// Headers generated with ktool v0.19.0
// https://github.com/kritantadev/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 15.0.0 | SDK: 15.0.0


#ifndef ADJASPERPOINTCLOUD_H
#define ADJASPERPOINTCLOUD_H

@class NSObject;



@interface ADJasperPointCloud : NSObject {
    JasperPointCloud _pc;
    *__CVBuffer _dataBuffer;
}


@property (readonly) char * bankIds;
@property (readonly) *CGPoint cameraPixels;
@property (readonly) *float confidences;
@property (readonly) char * echoIds;
@property (readonly) *float euclideanDistances;
@property (readonly) *unsigned int flags;
@property (readonly) *float intensities;
@property (readonly) int length;
@property (readonly) *float signalToNoiseRatios;
@property (readonly) char * spotIds;
@property (readonly) *CGPoint undistortedCameraPixels;


-(*id)points;
-(BOOL)pointCloudToCSV:(id)arg0 atomically:(BOOL)arg1 ;
-(BOOL)pointCloudToImageFile:(id)arg0 uti:(id)arg1 atomically:(BOOL)arg2 ;
-(BOOL)pointCloudToJSPP:(id)arg0 atomically:(BOOL)arg1 ;
-(BOOL)reset;
-(BOOL)writeToFile:(id)arg0 atomically:(BOOL)arg1 ;
-(NSInteger)projectJasperPointsCroppedBy:(struct CGRect )arg0 rotatedBy:(NSInteger)arg1 andScaledInto:(struct __CVBuffer *)arg2 ;
-(NSInteger)projectJasperPointsFilteredBy:(id)arg0 croppedBy:(struct CGRect )arg1 rotatedBy:(NSInteger)arg2 andScaledInto:(struct __CVBuffer *)arg3 ;
-(NSInteger)projectJasperPointsFilteredBy:(id)arg0 croppedBy:(struct CGRect )arg1 rotatedBy:(NSInteger)arg2 andScaledMergingWith:(struct __CVBuffer *)arg3 ;
-(id)debugQuickLookObject;
-(id)dictionaryRepresentation;
-(id)imageRepresentationForUTI:(id)arg0 ;
-(id)initByMergingPointClouds:(id)arg0 ;
-(id)initWithDataBuffer:(struct __CVBuffer *)arg0 ;
-(id)initWithDictionaryRepresentation:(id)arg0 ;
-(id)initWithLength:(int)arg0 ;
-(id)initWithLength:(int)arg0 storage:(struct __CVBuffer *)arg1 ;
-(id)initWithPointCloud:(id)arg0 ;
-(id)jpegRepresentation;
-(id)mutableCopy;
-(id)pngRepresentation;
-(id)pointCloudByApplyingFilter:(id)arg0 ;
-(id)pointCloudByChangingPointOfViewByTransform:(struct ? )arg0 to:(id)arg1 ;
-(id)pointCloudByChangingPointOfViewFrom:(id)arg0 to:(id)arg1 ;
-(int)size;
-(struct CGImage *)cgImageRepresentation;
-(struct __CVBuffer *)dataBuffer;
-(void)dealloc;
+(BOOL)prepareDataBuffer:(struct __CVBuffer *)arg0 forLength:(int)arg1 ;
+(NSInteger)getKeyForName:(id)arg0 ;
+(NSUInteger)requiredStorageBytesForLength:(int)arg0 ;
+(id)JasperCSVAttributeNamesCannonicalOrder;
+(id)makeWithDataBuffer:(struct __CVBuffer *)arg0 ;
+(id)pointCloudByMergingPointClouds:(id)arg0 ;
+(id)pointCloudByMergingPointClouds:(id)arg0 applyingTransforms:(struct ? *)arg1 projectingToCamera:(id)arg2 ;
+(id)pointCloudFromCSV:(id)arg0 ;
+(id)pointCloudFromFile:(id)arg0 ;
+(id)pointCloudFromJSPP:(id)arg0 ;
+(unsigned int)pixelFormat;
+(void)resetPerformanceOverrides;
+(void)setPerformanceOverrides:(id)arg0 ;


@end


#endif