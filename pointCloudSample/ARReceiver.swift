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
    var pointcloud: ARPointCloud?
    var lastARImage: ARImageData?
    var lastUWImage: ARImageData?
}

var imageSensorSettingsForUltraWide3: ARImageSensorSettings?
// Configure and run an AR session to provide the app with depth-related AR data.
final class ARReceiver: NSObject, ARSessionDelegate {
    var arData = ARData()
    var arSession = ARSession()
    var lastFrame: Any? = nil
    var done: Bool = false
    
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
//        config.imageSensorSettingsForUltraWide.videoFormat.setValue(CGSize(width: 1920, height: 1440), forKey:   "_imageResolution")
        if #available(iOS 14.5, *) {
            var videoFormats: [ARConfiguration.VideoFormat] = ARConfiguration.VideoFormat.supportedVideoFormats(forDevicePosition: config.imageSensorSettingsForUltraWide.videoFormat.captureDevicePosition.rawValue, deviceType: config.imageSensorSettingsForUltraWide.videoFormat.captureDeviceType) as! [ARConfiguration.VideoFormat]
            config.imageSensorSettingsForUltraWide.videoFormat = videoFormats[0]
            print(1, config.imageSensorSettingsForUltraWide.videoFormat ,videoFormats[0])
            
            imageSensorSettingsForUltraWide3 =  ARImageSensorSettings(videoFormat: videoFormats[0])
            
            print(imageSensorSettingsForUltraWide3)
            
            if !done {
                // Accessor
                method_exchangeImplementations(
                    class_getInstanceMethod(type(of:config), #selector(getter: config.imageSensorSettingsForUltraWide))!,
                    class_getInstanceMethod(type(of:self), #selector(self.imageSensorSettingsForUltraWide2))!
                )
                done = true
            }
            
//            let ivar = class_getInstanceVariable(type(of: config), "imageSensorSettingsForUltraWide")!
//            object_setIvar(config, ivar, UnsafeMutableRawPointer(&videoFormats[0]))
//            print(2,)
            print(2, config.imageSensorSettingsForUltraWide)
            
        } else {
            // Fallback on earlier versions
        }
        print(3, config.imageSensorSettingsForUltraWide)
        print(ARWorldTrackingConfiguration.supportedVideoFormats)
        config.frameSemantics = [.sceneDepth, .smoothedSceneDepth]
        arSession.run(config)
    }
    
    @objc func imageSensorSettingsForUltraWide2() -> ARImageSensorSettings{
        return imageSensorSettingsForUltraWide3!
    }
    
    func pause() {
        arSession.pause()
    }
  
    // Send required data from `ARFrame` to the delegate class via the `onNewARData` callback.
    func session(_ session: ARSession, didUpdate frame: ARFrame) {
        
//        if !done && arSession.availableSensors.count > 0{
//            for sensor in (arSession.availableSensors as NSArray) {
//                if let parent_sensor = sensor as? ARParentImageSensor{
//                    for sensor2 in (parent_sensor.sensors as NSArray) {
//                        if let arsensor = sensor2 as? ARImageSensor{
//                            if arsensor.captureFramesPerSecond == 10{
//                                print(arsensor.captureFramesPerSecond, arsensor.mutableSettings.videoFormat)
//                            }
//
//                        }
//                    }
//                }
//            }
//            done = true
//        }
            
        
        if(frame.sceneDepth != nil) && (frame.smoothedSceneDepth != nil) {
            arData.depthImage = frame.sceneDepth?.depthMap
            arData.depthSmoothImage = frame.smoothedSceneDepth?.depthMap
            arData.confidenceImage = frame.sceneDepth?.confidenceMap
            arData.confidenceSmoothImage = frame.smoothedSceneDepth?.confidenceMap
            arData.colorImage = frame.capturedImage
            arData.cameraIntrinsics = frame.camera.intrinsics
            arData.cameraResolution = frame.camera.imageResolution
            arData.pointcloud = frame.capturedPointCloudData
            delegate?.onNewARData(arData: arData)
            
            
            if let testFrame: ARFrameContext = self.lastFrame as? ARFrameContext{
                if let imageData = testFrame.imageData, let UWimage = imageData.latestUltraWideImage{
                    arData.lastARImage = imageData
                    arData.lastUWImage = UWimage
                }
            }
            
            self.lastFrame = arSession.value(forKey: "_nextFrameContext")
        }
    }
}
