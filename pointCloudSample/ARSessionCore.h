
#import <Foundation/Foundation.h>
#import <ARKit/ARKit.h>
#import <CoreGraphics/CoreGraphics.h>

#ifndef ARSESSION_H
#define ARSESSION_H



@interface ADJasperPointCloud : NSObject {
}


@property (readonly) char * bankIds;
@property (readonly) CGPoint * cameraPixels;
@property (readonly) float * confidences;
@property (readonly) char * echoIds;
@property (readonly) float*  euclideanDistances;
@property (readonly) unsigned int * flags;
@property (readonly) float* intensities;
@property (readonly) int length;
@property (readonly) float * signalToNoiseRatios;
@property (readonly) char * spotIds;
@property (readonly) CGPoint * undistortedCameraPixels;
-(id)jpegRepresentation;
-(id)mutableCopy;
-(id)pngRepresentation;

@end

@interface ARFrame ()
@property (retain, nonatomic) ARPointCloud *capturedPointCloudData; 
@end

@interface ARPointCloud ()

 {
}
-(id)depthPointCloud;
@end


@interface ARImageData : NSObject

@property (retain, nonatomic) ARImageData *latestUltraWideImage;
@property (retain, nonatomic) ARPointCloud *pointCloud;
@property (retain, nonatomic) AVCameraCalibrationData *calibrationData;
@property (retain, nonatomic) NSMutableDictionary *extrinsicsMap;
@end


@interface ARFrameContext : NSObject

 {
}

@property (retain, nonatomic) ARImageData *imageData;

@end

@interface ARSession ()
{
}


@property (retain, nonatomic) NSArray *availableSensors;


@end

#endif
