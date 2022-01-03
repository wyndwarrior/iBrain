/*
See LICENSE folder for this sample’s licensing information.

Abstract:
A parent view class that displays the sample app's other views.
*/

import Foundation
import SwiftUI
import MetalKit
import ARKit
import FLEX

// Add a title to a view that enlarges the view to full screen on tap.
struct Texture<T: View>: ViewModifier {
    let height: CGFloat
    let width: CGFloat
    let title: String
    let view: T
    func body(content: Content) -> some View {
        VStack {
            Text(title).foregroundColor(Color.red)
            // To display the same view in the navigation, reference the view
            // directly versus using the view's `content` property.
            NavigationLink(destination: view.aspectRatio(CGSize(width: width, height: height), contentMode: .fill)) {
                view.frame(maxWidth: width, maxHeight: height, alignment: .center)
                    .aspectRatio(CGSize(width: width, height: height), contentMode: .fill)
            }
        }
    }
}

extension View {
    // Apply `zoomOnTapModifier` with a `self` reference to show the same view
    // on tap.
    func zoomOnTapModifier(height: CGFloat, width: CGFloat, title: String) -> some View {
        modifier(Texture(height: height, width: width, title: title, view: self))
    }
}
extension Image {
    init(_ texture: MTLTexture, ciContext: CIContext, scale: CGFloat, orientation: Image.Orientation, label: Text) {
        let ciimage = CIImage(mtlTexture: texture)!
        let cgimage = ciContext.createCGImage(ciimage, from: ciimage.extent)
        self.init(cgimage!, scale: 1.0, orientation: .leftMirrored, label: label)
    }
}

//- Tag: MetalDepthView
struct MetalDepthView: View {
    
    // Set the default sizes for the texture views.
    let sizeH: CGFloat = 256
    let sizeW: CGFloat = 192
    
    // Manage the AR session and AR data processing.
    //- Tag: ARProvider
    @ObservedObject var arProvider: ARProvider = ARProvider()!
    let ciContext: CIContext = CIContext()

    // Save the user's confidence selection.
    @State private var selectedConfidence = 2
    // Set the depth view's state data.i
    @State var isShowSmoothDepth = false
    @State var isArPaused = false
    @State private var scaleMovement: Float = 1.5
    
    var confLevels = ["low", "med", "high"]
 
    var body: some View {
        if !ARWorldTrackingConfiguration.supportsFrameSemantics([.sceneDepth, .smoothedSceneDepth]) {
            Text("Unsupported Device: This app requires the LiDAR Scanner to access the scene's depth.")
        } else {
            NavigationView {
                GeometryReader { geometry in
                    ScrollView(.vertical) {
                        ScrollView(.horizontal) {
                            HStack() {
                                MetalTextureViewDepth(mtkView: MTKView(), content: arProvider.depthContent, confSelection: $selectedConfidence).rotationEffect(.degrees(-90))
                                    .zoomOnTapModifier(height: sizeH, width: sizeW, title: "Depth").frame(width: sizeH, height: sizeW)
                                MetalTextureViewConfidence(mtkView: MTKView(), content: arProvider.confidenceContent).rotationEffect(.degrees(-90))
                                    .zoomOnTapModifier(height: sizeH, width: sizeW, title: "Confidence").frame(width: sizeH, height: sizeW)
                                MetalPointCloud(mtkView: MTKView(), arData: arProvider, confSelection: $selectedConfidence, scaleMovement: $scaleMovement)
                                    .zoomOnTapModifier(height: sizeW, width: sizeH, title: "")
                                
                            }
                        }
                        HStack {
                            Text("Confidence Select:")
                            Picker(selection: $selectedConfidence, label: Text("Confidence Select")) {
                                ForEach(0..<confLevels.count) { index in
                                    Text(self.confLevels[index]).tag(index)
                                }

                            }.pickerStyle(SegmentedPickerStyle())
                        }.padding(.horizontal)
                        HStack {
                            if arProvider.uploading{
                                Text(String(format:"Uploading %.2f%%, this may take some time..." , arProvider.progress*100))
                            }
                            Spacer()
                            Button(action: {
                                FLEXManager.shared.showExplorer()
                            }){
                                Text("Flex")
                                
                            }
                            Button(action: {
                                arProvider.capture()
                            }) {
                                HStack{
                                    Image(systemName: isArPaused ? "record.circle" : "record.circle").resizable().frame(width: 60, height: 60)
                                    Text("Capture")
                                }
                            }.disabled(arProvider.uploading)
                        }.padding(.horizontal)
                        
                        Spacer()
                    }
                }
            }.navigationViewStyle(StackNavigationViewStyle())
            
        }
    }
}
struct MtkView_Previews: PreviewProvider {
    static var previews: some View {
        Group {
            MetalDepthView().previewDevice("iPad Pro (12.9-inch) (4th generation)")
            MetalDepthView().previewDevice("iPhone 11 Pro")
        }
    }
}
