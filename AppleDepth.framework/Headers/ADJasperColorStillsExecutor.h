// Headers generated with ktool v0.19.0
// https://github.com/kritantadev/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 15.0.0 | SDK: 15.0.0


#ifndef ADJASPERCOLORSTILLSEXECUTOR_H
#define ADJASPERCOLORSTILLSEXECUTOR_H

// Failed to load a method with 'NoneType' object is not subscriptable

@class NSString;


#import "ADExecutor.h"
#import "ADJasperColorStillsPipeline.h"
#import "ADJasperPointCloud.h"
#import "ADEspressoWrapper.h"
#import "ADEspressoBufferHandle.h"
#import "ADJasperColorStillsExecutorParameters.h"

@interface ADJasperColorStillsExecutor : ADExecutor {
    BOOL _isPrepared;
    ADJasperColorStillsPipeline *_pipeline;
    NSString *_correctionLogString;
    *__CVBuffer _itmCroppedScaledColor;
    *__CVBuffer _itmRotatedColor;
    *__CVBuffer _itmPreProcessedColor;
    *__CVBuffer _itmPreProcessedJasper;
    *__CVBuffer _itmPreProcessedJasperForCorrection;
    ADJasperPointCloud *_aggregatedPointCloud;
    ADJasperPointCloud *_aggregatedPointCloudBeforeCorrection;
    *__CVBuffer _itmUnprocessedDepth;
    *__CVBuffer _itmUnscaledProcessedDepth;
    ADEspressoWrapper *_correctionBackendEspressoRunner;
    ADEspressoWrapper *_correctionFrontendEspressoRunner;
    ADEspressoBufferHandle *_sijFeaturesOutputBuffer;
    *float _sijFeaturesOutput;
    *float _sijFeaturesInput;
    *float _sijAnglesOutput;
    *float _sijErrorsOutput;
}


@property (copy, nonatomic) ADJasperColorStillsExecutorParameters *executorParameters; // ivar: _executorParameters


-(NSInteger)allocateIntermediateBuffers;
-(NSInteger)numberOfExecutionSteps;
-(NSInteger)prepareForEngineType:(NSUInteger)arg0 inputSize:(struct CGSize )arg1 ;
-(id)getIntermediates;
-(id)init;
-(void)dealloc;
-(void)deallocateEspressoBuffers;


@end


#endif