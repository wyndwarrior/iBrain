
#import <Foundation/Foundation.h>
#import <ARKit/ARKit.h>
#import <CoreGraphics/CoreGraphics.h>

#ifndef ARSESSION_H
#define ARSESSION_H



@interface ARVideoFormat ()

 {
}


+(id)supportedVideoFormatsForDevicePosition:(NSInteger)arg0 deviceType:(id)arg1 ;
+(id)supportedVideoFormatsForDevicePosition:(NSInteger)arg0 deviceType:(id)arg1 frameRate:(CGFloat)arg2 ;
+(id)supportedVideoFormatsForDevicePosition:(NSInteger)arg0 deviceType:(id)arg1 videoBinned:(BOOL)arg2 ;
+(id)supportedVideoFormatsForDevicePosition:(NSInteger)arg0 deviceType:(id)arg1 videoBinned:(BOOL)arg2 frameRate:(CGFloat)arg3 ;


@end


@interface ARImageSensorSettings : NSObject <NSCopying>



@property (nonatomic) BOOL autoFocusEnabled; // ivar: _autoFocusEnabled
@property (nonatomic) BOOL backFacingCameraGeometricDistortionCorrectionEnabled; // ivar: _backFacingCameraGeometricDistortionCorrectionEnabled
@property (nonatomic) BOOL calibrationDataOutputEnabled; // ivar: _calibrationDataOutputEnabled
@property (nonatomic) BOOL dropsInitialFramesOutsideExposureTargetOffsetThreshold; // ivar: _dropsInitialFramesOutsideExposureTargetOffsetThreshold
@property (nonatomic) BOOL enabled; // ivar: _enabled
@property (nonatomic) float maxGainOverride; // ivar: _maxGainOverride
@property (nonatomic) NSUInteger maximumNumberOfInitialFramesDropped; // ivar: _maximumNumberOfInitialFramesDropped
@property (nonatomic) NSUInteger maximumNumberOfTrackedFaces; // ivar: _maximumNumberOfTrackedFaces
@property (copy, nonatomic) NSString *metaData; // ivar: _metaData
@property (nonatomic) BOOL mirrorVideoOutput; // ivar: _mirrorVideoOutput
@property (nonatomic) float negativeExposureTargetOffsetThreshold; // ivar: _negativeExposureTargetOffsetThreshold
@property (nonatomic) float positiveExposureTargetOffsetThreshold; // ivar: _positiveExposureTargetOffsetThreshold
@property (retain, nonatomic) ARVideoFormat *videoFormat; // ivar: _videoFormat
@property (nonatomic) BOOL visionDataOutputEnabled; // ivar: _visionDataOutputEnabled
@property (retain, nonatomic) NSDictionary *visionDataOutputParameters; // ivar: _visionDataOutputParameters

-(id)initWithVideoFormat:(id)arg0;

@end

@interface ARImageSensor : NSObject

 {
}


@property NSInteger captureFramesPerSecond; // ivar: _captureFramesPerSecond
@property (readonly, nonatomic) ARImageSensorSettings *mutableSettings;

@end

@interface ARParentImageSensor : NSObject

 {
}

@property (retain, nonatomic) NSMutableArray *sensors;

@end



@interface ARWorldTrackingConfiguration ()

@property (copy, nonatomic) ARImageSensorSettings *imageSensorSettingsForUltraWide;


@end

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
@property (nonatomic) CGFloat timestamp;
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
@property (nonatomic) CVBufferRef* pixelBuffer;
@property (nonatomic) CGFloat timestamp;
@property (nonatomic) CGSize imageResolution;
@end

CVPixelBufferRef CastToCVPixelBuffer(void* p)
{
    return (CVPixelBufferRef)p;
}

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
