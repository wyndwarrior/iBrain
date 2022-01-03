// Headers generated with ktool v0.19.0
// https://github.com/kritantadev/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 15.0.0 | SDK: 15.0.0


#ifndef ADJASPERCOLOREXECUTOR_H
#define ADJASPERCOLOREXECUTOR_H

// Failed to load a method with 'NoneType' object is not subscriptable
// Failed to load a method with 'NoneType' object is not subscriptable
// Failed to load a method with 'NoneType' object is not subscriptable
// Failed to load a method with 'NoneType' object is not subscriptable



#import "ADExecutor.h"
#import "ADJasperColorPipeline.h"
#import "ADLKTExecutor.h"
#import "ADCameraCalibration.h"
#import "ADJasperColorExecutorParameters.h"

@interface ADJasperColorExecutor : ADExecutor {
    ADJasperColorPipeline *_pipeline;
    ADLKTExecutor *_lktExecutor;
    *__CVBuffer _itmCroppedScaledColor;
    *__CVBuffer _itmRotatedColor;
    *__CVBuffer _itmPreProcessedColor;
    *__CVBuffer _itmPreProcessedJasper;
    *__CVBuffer _itmUnprocessedDepth;
    *__CVBuffer _itmPostProcessedDepth;
    *__CVBuffer _itmUnprocessedConf;
    *__CVBuffer _itmPostProcessedConf;
    *__CVBuffer _itmUnprocessedNormals;
    *__CVBuffer _itmPostProcessedNormals;
    *__CVBuffer _itmUnprocessedAlpha;
    *__CVBuffer _itmWarpedPrevDepth;
    *__CVBuffer _itmWarpedPrevConf;
    *__CVBuffer _itmOpticalFlow;
    *__CVBuffer _itmPrevProcessedFusedDepth;
    *__CVBuffer _itmCurrProcessedFusedDepth;
    *__CVBuffer _itmPrevProcessedFusedConf;
    *__CVBuffer _itmCurrProcessedFusedConf;
    *__CVBuffer _itmPrevProcessedFusedNormals;
    *__CVBuffer _itmCurrProcessedFusedNormals;
    BOOL _firstTimeExecution;
    BOOL _opticalFlowEnabled;
    ? _prevPose;
    ADCameraCalibration *_prevCamCalib;
}


@property (retain, nonatomic) ADJasperColorExecutorParameters *executorParameters; // ivar: _executorParameters


-(NSInteger)allocateIntermediateBuffers;
-(NSInteger)numberOfExecutionSteps;
-(NSInteger)prepareForEngineType:(NSUInteger)arg0 roi:(struct CGRect )arg1 exifOrientation:(unsigned int)arg2 ;
-(NSInteger)prepareForEngineType:(NSUInteger)arg0 roi:(struct CGRect )arg1 exifOrientation:(unsigned int)arg2 rotationPreference:(NSUInteger)arg3 ;
-(NSInteger)prepareForEngineType:(NSUInteger)arg0 roi:(struct CGRect )arg1 exifOrientation:(unsigned int)arg2 useTemporalConsistency:(BOOL)arg3 ;
-(NSInteger)prepareForEngineType:(NSUInteger)arg0 roi:(struct CGRect )arg1 exifOrientation:(unsigned int)arg2 useTemporalConsistency:(BOOL)arg3 rotationPreference:(NSUInteger)arg4 ;
-(id)getIntermediates;
-(id)initWithInputPrioritization:(NSInteger)arg0 ;
-(void)dealloc;
-(void)deallocateEspressoBuffers;


@end


#endif