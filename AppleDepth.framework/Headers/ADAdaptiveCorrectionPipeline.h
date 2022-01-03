// Headers generated with ktool v0.19.0
// https://github.com/kritantadev/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 15.0.0 | SDK: 15.0.0


#ifndef ADADAPTIVECORRECTIONPIPELINE_H
#define ADADAPTIVECORRECTIONPIPELINE_H

@class NSObject;


#import "ADAdaptiveCorrectionPipelineParameters.h"

@interface ADAdaptiveCorrectionPipeline : NSObject {
    AdaptiveCorrectionConfig _config;
    *AdaptiveCorrection _adc;
    ADAdaptiveCorrectionPipelineParameters *_pipelineParameters;
}


@property (readonly) int maxNumPoints; // ivar: _maxNumPoints


-(NSInteger)fullCorrectionWithCameraCalibrationTele:(id)arg0 cameraCalibrationWide:(id)arg1 xyPointsTele:(*CGFloat)arg2 xyPointsWide:(*CGFloat)arg3 numPoints:(int)arg4 ;
-(NSInteger)fullCorrectionWithPointsTele:(*CGFloat)arg0 xyPointsWide:(*CGFloat)arg1 numPoints:(int)arg2 calModel:(id)arg3 ;
-(NSInteger)fullTemporalCorrectionWithCameraCalibrationTele:(id)arg0 cameraCalibrationWide:(id)arg1 xyPointsTele:(*CGFloat)arg2 xyPointsWide:(*CGFloat)arg3 numPoints:(int)arg4 ;
-(id)initWithMaxNumPoints:(int)arg0 ;
-(id)initWithMaxNumPoints:(int)arg0 andParameters:(id)arg1 ;
-(struct AdaptiveCorrectionConfig )getConfigFromPipelineParams;
-(struct AdaptiveCorrectionStatus )getStatus;
+(CGFloat)meanFundamentalEpipolarErrorForCalModel:(struct CalModel *)arg0 xyPointsTele:(*CGFloat)arg1 xyPointsWide:(*CGFloat)arg2 numPoints:(int)arg3 ;
+(NSInteger)approximateCorrectionWithPointsTele:(*CGFloat)arg0 xyPointsWide:(*CGFloat)arg1 numPoints:(int)arg2 calModel:(id)arg3 ;
+(NSInteger)computeVerticalBaselineTransform:(struct ? )arg0 extrinsicRefToAuxPrime:(struct ? *)arg1 rotationRefToRefPrime:(struct ? *)arg2 rotationAuxToAuxPrime:(struct ? *)arg3 ;
+(NSInteger)rotateCalModel:(struct CalModel *)arg0 extrinsicRefToAuxRotated:(struct ? )arg1 rotationRef:(struct ? )arg2 rotationAux:(struct ? )arg3 calRotated:(struct CalModel *)arg4 ;
+(NSInteger)rotateDistortionModel:(struct DistortionModel *)arg0 rotation:(struct ? )arg1 distRotated:(struct DistortionModel *)arg2 ;
+(NSInteger)transformPointsWithMatrix:(*CGFloat)arg0 numPoints:(int)arg1 transformMatrix:(struct ? )arg2 xyPointsTransformed:(*CGFloat)arg3 ;
+(struct CalModel )convertToInternalCalModel:(id)arg0 ;
+(void)convertCameraCalibrationTele:(id)arg0 cameraCalibrationWide:(id)arg1 toDistortionModelTele:(struct DistortionModel *)arg2 toDistortionModelWide:(struct DistortionModel *)arg3 toCalModel:(struct CalModel *)arg4 ;
+(void)convertExtrinsics:(struct ? )arg0 toInternalFormat:(CGFloat)arg1 ;
+(void)convertInternalExtrinsics:(CGFloat)arg0 toMatrix:(struct ? *)arg1 ;
+(void)fillDistortionModel:(struct DistortionModel *)arg0 andUpdateCalModel:(struct CalModel *)arg1 forCamera:(int)arg2 fromCalib:(id)arg3 ;
+(void)updateADCalModel:(id)arg0 fromInternalCalModel:(struct CalModel *)arg1 ;
+(void)updateADCameraCalib:(id)arg0 fromDistortionModel:(struct DistortionModel *)arg1 andCalModel:(struct CalModel *)arg2 forCamera:(int)arg3 ;
+(void)updateCameraCalibrationTele:(id)arg0 cameraCalibrationWide:(id)arg1 withDistortionModelTele:(struct DistortionModel *)arg2 withDistortionModelWide:(struct DistortionModel *)arg3 withCalModel:(struct CalModel *)arg4 ;


@end


#endif