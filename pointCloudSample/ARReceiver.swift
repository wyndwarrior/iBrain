/*
See LICENSE folder for this sample’s licensing information.

Abstract:
A utility class that receives processed depth information.
*/

import Foundation
import SwiftUI
import Combine
import ARKit

// Receive the newest AR data from an `ARReceiver`.
protocol ARDataReceiver: AnyObject {
    func onNewARData(arData: ARData)
}

//- Tag: ARData
// Store depth-related AR data.
final class ARData {
    var depthImage: CVPixelBuffer?
    var depthSmoothImage: CVPixelBuffer?
    var colorImage: CVPixelBuffer?
    var confidenceImage: CVPixelBuffer?
    var confidenceSmoothImage: CVPixelBuffer?
    var cameraIntrinsics = simd_float3x3()
    var cameraResolution = CGSize()
}

// Configure and run an AR session to provide the app with depth-related AR data.
final class ARReceiver: NSObject, ARSessionDelegate {
    var arData = ARData()
    var arSession = ARSession()
    weak var delegate: ARDataReceiver?
    
    // Configure and start the ARSession.
    override init() {
        super.init()
        arSession.delegate = self
        start()
    }
    
    // Configure the ARKit session.
    func start() {
        guard ARWorldTrackingConfiguration.supportsFrameSemantics([.sceneDepth, .smoothedSceneDepth]) else { return }
        // Enable both the `sceneDepth` and `smoothedSceneDepth` frame semantics.
        let config = ARWorldTrackingConfiguration()
        config.frameSemantics = [.sceneDepth, .smoothedSceneDepth]
        arSession.run(config)
    }
    
    
    func get_png(pxbuffer: CVPixelBuffer? ) -> String?{
        if let buffer = pxbuffer {
            let ciimage = CIImage(cvPixelBuffer: buffer)
            let context = CIContext(options: nil)
            guard let cameraImage = context.createCGImage(ciimage, from: ciimage.extent) else {return nil}
            let uiimage = UIImage(cgImage: cameraImage)
            let imageData = uiimage.pngData();
            return imageData?.base64EncodedString();
//            let pngImage = UIImage(data:imageData)!;
//            UIImageWriteToSavedPhotosAlbum(pngImage, self, #selector(image(_:didFinishSavingWithError:contextInfo:)), nil)
//            print(uiimage)
        }
        return nil;
    }

    @objc func image(_ image: UIImage, didFinishSavingWithError error: NSError?, contextInfo: UnsafeRawPointer) {
        if let error = error{
            print("error", error.localizedDescription)
        } else {
            print("saved")
        }
    }
    
    func convertDepthData(depthMap: CVPixelBuffer) -> [[Float32]] {
        let width = CVPixelBufferGetWidth(depthMap)
        let height = CVPixelBufferGetHeight(depthMap)
        var convertedDepthMap: [[Float32]] = Array(
            repeating: Array(repeating: 0, count: width),
            count: height
        )
        CVPixelBufferLockBaseAddress(depthMap, CVPixelBufferLockFlags(rawValue: 2))
        let floatBuffer = unsafeBitCast(
            CVPixelBufferGetBaseAddress(depthMap),
            to: UnsafeMutablePointer<Float32>.self
        )
        for row in 0 ..< height {
            for col in 0 ..< width {
                convertedDepthMap[row][col] = floatBuffer[width * row + col]
            }
        }
        CVPixelBufferUnlockBaseAddress(depthMap, CVPixelBufferLockFlags(rawValue: 2))
        return convertedDepthMap
    }
    
    func pause() {
        arSession.pause()
//        print(arData.colorImage, arData.depthImage, arData.cameraResolution, arData.cameraIntrinsics)

        
        if let depthImage = arData.depthImage{
            let jsonDict: [String : Any] = [
                "intrinsic_matrix" : (0 ..< 3).map{ x in
                    (0 ..< 3).map{ y in arData.cameraIntrinsics[x][y]}
                },
                "depth_data" : convertDepthData(depthMap: depthImage),
                "camera_image": get_png(pxbuffer: arData.colorImage),
                "confidence_image": get_png(pxbuffer: arData.confidenceImage)
            ]
            let jsonStringData = try! JSONSerialization.data(
                withJSONObject: jsonDict
            )
            print(jsonStringData)
            
            
            // create post request
            let url = URL(string: "https://dab7-40-142-34-149.ngrok.io/brain_api")!
            var request = URLRequest(url: url)
            request.httpMethod = "POST"
            request.addValue("application/json", forHTTPHeaderField: "Content-Type")

            // insert json data to the request
            request.httpBody = jsonStringData

            let task = URLSession.shared.dataTask(with: request) { data, response, error in
                guard let data = data, error == nil else {
                    print(error?.localizedDescription ?? "No data")
                    return
                }
                let responseJSON = try? JSONSerialization.jsonObject(with: data, options: [])
                if let responseJSON = responseJSON as? [String: Any] {
                    print(responseJSON)
                    if responseJSON.keys.contains("link"){
                        if let url = URL(string: responseJSON["link"] as! String) {
                            DispatchQueue.main.async {
                                UIApplication.shared.open(url)
                            }
                        }
                    } else if responseJSON.keys.contains("error"){
                        print(responseJSON["error"])
                    }
                }
            }

            task.resume()
            
        }
        
        
//        save_img(pxbuffer: arData.colorImage)
//        save_img(pxbuffer: arData.depthImage)
//        save_img(pxbuffer: arData.confidenceImage)
    }
  
    // Send required data from `ARFrame` to the delegate class via the `onNewARData` callback.
    func session(_ session: ARSession, didUpdate frame: ARFrame) {
        if(frame.sceneDepth != nil) && (frame.smoothedSceneDepth != nil) {
            arData.depthImage = frame.sceneDepth?.depthMap
            arData.depthSmoothImage = frame.smoothedSceneDepth?.depthMap
            arData.confidenceImage = frame.sceneDepth?.confidenceMap
            arData.confidenceSmoothImage = frame.smoothedSceneDepth?.confidenceMap
            arData.colorImage = frame.capturedImage
            arData.cameraIntrinsics = frame.camera.intrinsics
            arData.cameraResolution = frame.camera.imageResolution
            delegate?.onNewARData(arData: arData)
        }
    }
}
