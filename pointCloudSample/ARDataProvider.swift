/*
See LICENSE folder for this sample’s licensing information.

Abstract:
A utility class that provides processed depth information.
*/

import Foundation
import SwiftUI
import Combine
import ARKit
import Accelerate
import MetalPerformanceShaders
import FLEX

// Wrap the `MTLTexture` protocol to reference outputs from ARKit.
final class MetalTextureContent {
    var texture: MTLTexture?
}

// Enable `CVPixelBuffer` to output an `MTLTexture`.
extension CVPixelBuffer {
    
    func texture(withFormat pixelFormat: MTLPixelFormat, planeIndex: Int, addToCache cache: CVMetalTextureCache) -> MTLTexture? {
        
        let width = CVPixelBufferGetWidthOfPlane(self, planeIndex)
        let height = CVPixelBufferGetHeightOfPlane(self, planeIndex)
        
        var cvtexture: CVMetalTexture?
        _ = CVMetalTextureCacheCreateTextureFromImage(nil, cache, self, nil, pixelFormat, width, height, planeIndex, &cvtexture)
        let texture = CVMetalTextureGetTexture(cvtexture!)
        
        return texture
        
    }
    
}

// Collect AR data using a lower-level receiver. This class converts AR data
// to a Metal texture, optionally upscaling depth data using a guided filter,
// and implements `ARDataReceiver` to respond to `onNewARData` events.
final class ARProvider: ARDataReceiver, ObservableObject {
    private var observation: NSKeyValueObservation?
    // Set the destination resolution for the upscaled algorithm.
    let upscaledWidth = 960
    let upscaledHeight = 760

    // Set the original depth size.
    let origDepthWidth = 256
    let origDepthHeight = 192

    // Set the original color size.
    let origColorWidth = 1920
    let origColorHeight = 1440
    
    // Set the guided filter constants.
    let guidedFilterEpsilon: Float = 0.004
    let guidedFilterKernelDiameter = 5
    
    let arReceiver = ARReceiver()
    @Published var lastArData: ARData?
    @Published var uploading: Bool = false
    @Published var progress: Double = 0.0
    
    let depthContent = MetalTextureContent()
    let confidenceContent = MetalTextureContent()
    let colorYContent = MetalTextureContent()
    let colorCbCrContent = MetalTextureContent()
    let upscaledCoef = MetalTextureContent()
    let downscaledRGB = MetalTextureContent()
    let upscaledConfidence = MetalTextureContent()
    
    let coefTexture: MTLTexture
    let destDepthTexture: MTLTexture
    let destConfTexture: MTLTexture
    let colorRGBTexture: MTLTexture
    let colorRGBTextureDownscaled: MTLTexture
    let colorRGBTextureDownscaledLowRes: MTLTexture
    
    // Enable or disable depth upsampling.
    public var isToUpsampleDepth: Bool = false {
        didSet {
            processLastArData()
        }
    }
    
    // Enable or disable smoothed-depth upsampling.
    public var isUseSmoothedDepthForUpsampling: Bool = false {
        didSet {
            processLastArData()
        }
    }
    var textureCache: CVMetalTextureCache?
    let metalDevice: MTLDevice
    let guidedFilter: MPSImageGuidedFilter?
    let mpsScaleFilter: MPSImageBilinearScale?
    let commandQueue: MTLCommandQueue
    let pipelineStateCompute: MTLComputePipelineState?
    
    // Create an empty texture.
    static func createTexture(metalDevice: MTLDevice, width: Int, height: Int, usage: MTLTextureUsage, pixelFormat: MTLPixelFormat) -> MTLTexture {
        let descriptor: MTLTextureDescriptor = MTLTextureDescriptor()
        descriptor.pixelFormat = pixelFormat
        descriptor.width = width
        descriptor.height = height
        descriptor.usage = usage
        let resTexture = metalDevice.makeTexture(descriptor: descriptor)
        return resTexture!
    }
    
    // Start or resume the stream from ARKit.
    func start() {
        arReceiver.start()
    }
    
    // Pause the stream from ARKit.
    func pause() {
        arReceiver.pause()
    }
    
    
    func get_png(pxbuffer: CVPixelBuffer? ) -> Data?{
        if let buffer = pxbuffer {
            let ciimage = CIImage(cvPixelBuffer: buffer)
            let context = CIContext(options: nil)
            print("image extent", ciimage.extent)
            guard let cameraImage = context.createCGImage(ciimage, from: ciimage.extent) else {return nil}
            let uiimage = UIImage(cgImage: cameraImage)
            let imageData = uiimage.pngData();
            return imageData;
        }
        return nil;
    }
    
    func save_png(pxbuffer: CVPixelBuffer? ){
        if let png_data = get_png(pxbuffer: pxbuffer) {
            let pngImage = UIImage(data:png_data)!;
            UIImageWriteToSavedPhotosAlbum(pngImage, nil, nil, nil)
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
    
    func json_lidar(lidar: ARPointCloud) -> [String: Any]?{
        if let depthPointCloud: ADJasperPointCloud = lidar.depthPointCloud() as? ADJasperPointCloud{
            let lidar_json: [String : Any] = [
                "lidar_point_cloud": lidar.points.map{ [$0.x, $0.y, $0.z]},
                "lidar_confidence": (0 ..< depthPointCloud.length).map{ x in
                    depthPointCloud.confidences[Int(x)]
                },
                "lidar_px": (0 ..< depthPointCloud.length).map{ x in
                    [depthPointCloud.undistortedCameraPixels[Int(x)].x,
                    depthPointCloud.undistortedCameraPixels[Int(x)].y]
                },
            ]
            return lidar_json
        }
        return nil;
    }
    
    func json_arimage(arimage: ARImageData) -> [String: Any]? {
        if let pointer = CastToCVPixelBuffer(arimage.pixelBuffer){
            print(arimage.imageResolution)
            let png_data = get_png(pxbuffer: pointer.takeUnretainedValue() as? CVPixelBuffer)
            let pngImage = UIImage(data:png_data!)!;
            UIImageWriteToSavedPhotosAlbum(pngImage, nil, nil, nil)
            var json : [String: Any] = [
                "image": png_data?.base64EncodedString(),
                "intrinsic_matrix" : (0 ..< 3).map{ x in
                    (0 ..< 3).map{ y in arimage.calibrationData.intrinsicMatrix[y][x]}
                },
                "extrinsic_matrix" : (0 ..< 3).map{ x in
                    (0 ..< 4).map{ y in arimage.calibrationData.extrinsicMatrix[y][x]}
                },
                "ref_size" : [arimage.calibrationData.intrinsicMatrixReferenceDimensions.height,
                              arimage.calibrationData.intrinsicMatrixReferenceDimensions.width]
            ]
            if let pointCloud = arimage.pointCloud{
                json["lidar"] = json_lidar(lidar: pointCloud)
            }
            print(arimage.calibrationData)
            return json
        }
        return nil
    }
    
    func capture() {
        self.pause()

        if let arData = lastArData, let depthImage = arData.depthImage, let pointCloud = arData.pointcloud{
            var jsonDict: [String : Any] = [
                "intrinsic_matrix" : (0 ..< 3).map{ x in
                    (0 ..< 3).map{ y in arData.cameraIntrinsics[x][y]}
                },
                "lidar": json_lidar(lidar: pointCloud),
                "depth_data" : convertDepthData(depthMap: depthImage),
                "camera_image": get_png(pxbuffer: arData.colorImage)?.base64EncodedString(),
                "confidence_image": get_png(pxbuffer: arData.confidenceImage)?.base64EncodedString()
            ]
            
            if let arimage = arData.lastARImage, let uwimage = arData.lastUWImage{
                jsonDict["arimage"] = json_arimage(arimage: arimage)
                jsonDict["uwimage"] = json_arimage(arimage: uwimage)
            }
            
            let jsonStringData = try! JSONSerialization.data(
                withJSONObject: jsonDict
            )
            print(jsonStringData)
            save_png(pxbuffer: depthImage)
            save_png(pxbuffer: arData.colorImage)
            
            
            // create post request
            let url = URL(string: "https://covariant-ibrain.ngrok.io/brain_api")!
            var request = URLRequest(url: url)
            request.httpMethod = "POST"
            request.addValue("application/json", forHTTPHeaderField: "Content-Type")

            // insert json data to the request
            request.httpBody = jsonStringData
            uploading = true

            let task = URLSession.shared.dataTask(with: request) { data, response, error in
                DispatchQueue.main.async {
                    self.uploading = false
                }
                guard let data = data, error == nil else {
                    DispatchQueue.main.async {
                        let alertVC = UIAlertController(title: "Error", message: error?.localizedDescription ?? "No data", preferredStyle: .alert)
                        let okAction = UIAlertAction(title: "OK", style: .default) { (action: UIAlertAction) in
                        }
                        alertVC.addAction(okAction)
                        
                        let viewController = UIApplication.shared.windows.first!.rootViewController!
                        viewController.present(alertVC, animated: true, completion: nil)
                    }
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
            
            observation = task.progress.observe(\.fractionCompleted) { progress, _ in
                DispatchQueue.main.async {
                    self.progress = progress.fractionCompleted
                }
            }

            task.resume()
            
        }
        
        self.start()
//        self.pause()

    }
    
    // Initialize the MPS filters, metal pipeline, and Metal textures.
    init?() {
        do {
            metalDevice = EnvironmentVariables.shared.metalDevice
            CVMetalTextureCacheCreate(nil, nil, metalDevice, nil, &textureCache)
            guidedFilter = MPSImageGuidedFilter(device: metalDevice, kernelDiameter: guidedFilterKernelDiameter)
            guidedFilter?.epsilon = guidedFilterEpsilon
            mpsScaleFilter = MPSImageBilinearScale(device: metalDevice)
            commandQueue = EnvironmentVariables.shared.metalCommandQueue
            let lib = EnvironmentVariables.shared.metalLibrary
            let convertYUV2RGBFunc = lib.makeFunction(name: "convertYCbCrToRGBA")
            pipelineStateCompute = try metalDevice.makeComputePipelineState(function: convertYUV2RGBFunc!)
            // Initialize the working textures.
            coefTexture = ARProvider.createTexture(metalDevice: metalDevice, width: origDepthWidth, height: origDepthHeight,
                                                   usage: [.shaderRead, .shaderWrite], pixelFormat: .rgba32Float)
            destDepthTexture = ARProvider.createTexture(metalDevice: metalDevice, width: upscaledWidth, height: upscaledHeight,
                                                        usage: [.shaderRead, .shaderWrite], pixelFormat: .r32Float)
            destConfTexture = ARProvider.createTexture(metalDevice: metalDevice, width: upscaledWidth, height: upscaledHeight,
                                                       usage: [.shaderRead, .shaderWrite], pixelFormat: .r8Unorm)
            colorRGBTexture = ARProvider.createTexture(metalDevice: metalDevice, width: origColorWidth, height: origColorHeight,
                                                       usage: [.shaderRead, .shaderWrite], pixelFormat: .rgba32Float)
            colorRGBTextureDownscaled = ARProvider.createTexture(metalDevice: metalDevice, width: upscaledWidth, height: upscaledHeight,
                                                                 usage: [.shaderRead, .shaderWrite], pixelFormat: .rgba32Float)
            colorRGBTextureDownscaledLowRes = ARProvider.createTexture(metalDevice: metalDevice, width: origDepthWidth, height: origDepthHeight,
                                                                       usage: [.shaderRead, .shaderWrite], pixelFormat: .rgba32Float)
            upscaledCoef.texture = coefTexture
            upscaledConfidence.texture = destConfTexture
            downscaledRGB.texture = colorRGBTextureDownscaled
            
            // Set the delegate for ARKit callbacks.
            arReceiver.delegate = self
            
        } catch {
            print("Unexpected error: \(error).")
            return nil
        }
    }
    
    // Save a reference to the current AR data and process it.
    func onNewARData(arData: ARData) {
        lastArData = arData
        processLastArData()
    }
    
    // Copy the AR data to Metal textures and, if the user enables the UI, upscale the depth using a guided filter.
    func processLastArData() {
        colorYContent.texture = lastArData?.colorImage?.texture(withFormat: .r8Unorm, planeIndex: 0, addToCache: textureCache!)!
        colorCbCrContent.texture = lastArData?.colorImage?.texture(withFormat: .rg8Unorm, planeIndex: 1, addToCache: textureCache!)!
        if isUseSmoothedDepthForUpsampling {
            depthContent.texture = lastArData?.depthSmoothImage?.texture(withFormat: .r32Float, planeIndex: 0, addToCache: textureCache!)!
            confidenceContent.texture = lastArData?.confidenceSmoothImage?.texture(withFormat: .r8Unorm, planeIndex: 0, addToCache: textureCache!)!
        } else {
            depthContent.texture = lastArData?.depthImage?.texture(withFormat: .r32Float, planeIndex: 0, addToCache: textureCache!)!
            confidenceContent.texture = lastArData?.confidenceImage?.texture(withFormat: .r8Unorm, planeIndex: 0, addToCache: textureCache!)!
        }
        if isToUpsampleDepth {
            guard let cmdBuffer = commandQueue.makeCommandBuffer() else { return }
            guard let computeEncoder = cmdBuffer.makeComputeCommandEncoder() else { return }
            // Convert YUV to RGB because the guided filter needs RGB format.
            computeEncoder.setComputePipelineState(pipelineStateCompute!)
            computeEncoder.setTexture(colorYContent.texture, index: 0)
            computeEncoder.setTexture(colorCbCrContent.texture, index: 1)
            computeEncoder.setTexture(colorRGBTexture, index: 2)
            let threadgroupSize = MTLSizeMake(pipelineStateCompute!.threadExecutionWidth,
                                              pipelineStateCompute!.maxTotalThreadsPerThreadgroup / pipelineStateCompute!.threadExecutionWidth, 1)
            let threadgroupCount = MTLSize(width: Int(ceil(Float(colorRGBTexture.width) / Float(threadgroupSize.width))),
                                           height: Int(ceil(Float(colorRGBTexture.height) / Float(threadgroupSize.height))),
                                           depth: 1)
            computeEncoder.dispatchThreadgroups(threadgroupCount, threadsPerThreadgroup: threadgroupSize)
            computeEncoder.endEncoding()
            
            // Downscale the RGB data. Pass in the target resoultion.
            mpsScaleFilter?.encode(commandBuffer: cmdBuffer, sourceTexture: colorRGBTexture,
                                   destinationTexture: colorRGBTextureDownscaled)
            // Match the input depth resolution.
            mpsScaleFilter?.encode(commandBuffer: cmdBuffer, sourceTexture: colorRGBTexture,
                                   destinationTexture: colorRGBTextureDownscaledLowRes)
            
            // Upscale the confidence data. Pass in the target resolution.
            mpsScaleFilter?.encode(commandBuffer: cmdBuffer, sourceTexture: confidenceContent.texture!,
                                   destinationTexture: destConfTexture)
            
            // Encode the guided filter.
            guidedFilter?.encodeRegression(to: cmdBuffer, sourceTexture: depthContent.texture!,
                                           guidanceTexture: colorRGBTextureDownscaledLowRes, weightsTexture: nil,
                                           destinationCoefficientsTexture: coefTexture)
            
            // Optionally, process `coefTexture` here.
            
            guidedFilter?.encodeReconstruction(to: cmdBuffer, guidanceTexture: colorRGBTextureDownscaled,
                                               coefficientsTexture: coefTexture, destinationTexture: destDepthTexture)
            cmdBuffer.commit()
            
            // Override the original depth texture with the upscaled version.
            depthContent.texture = destDepthTexture
        }
    }
}

