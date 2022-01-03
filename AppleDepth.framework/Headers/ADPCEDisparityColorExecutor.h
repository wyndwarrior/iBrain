// Headers generated with ktool v0.19.0
// https://github.com/kritantadev/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 15.0.0 | SDK: 15.0.0


#ifndef ADPCEDISPARITYCOLOREXECUTOR_H
#define ADPCEDISPARITYCOLOREXECUTOR_H

// Failed to load a method with 'NoneType' object is not subscriptable
// Failed to load a method with 'NoneType' object is not subscriptable

@protocol MTLDevice, MTLCommandQueue;


#import "ADExecutor.h"
#import "ADPCEDisparityColorPipeline.h"
#import "ADPCEDisparityColorExecutorParameters.h"

@interface ADPCEDisparityColorExecutor : ADExecutor {
    BOOL _isPrepared;
    ADPCEDisparityColorPipeline *_pipeline;
    id<MTLDevice> *_metalDevice;
    id<MTLCommandQueue> *_cmdQueue;
    *__CVBuffer _preprocessorInputMetalHelper;
    *__CVBuffer _preprocessorOutputMetalHelper;
    *__CVBuffer _itmCroppedScaledColor;
    *__CVBuffer _itmRotatedColor;
    *__CVBuffer _itmPreProcessedColor;
    *__CVBuffer _itmCroppedScaledDisparity;
    *__CVBuffer _itmRotatedDisparity;
    *__CVBuffer _itmProcessedUnfilteredDisparity;
    *__CVBuffer _itmPreProcessedDisparity;
    *__CVBuffer _itmPrevDisparity;
    BOOL _prevDisparityIsZeros;
    *__CVBuffer _itmUnprocessedOutputDisparity;
}


@property (copy, nonatomic) ADPCEDisparityColorExecutorParameters *executorParameters; // ivar: _executorParameters
@property (readonly, nonatomic) *__CVBuffer prevDisparity;


-(NSInteger)allocateIntermediateBuffers;
-(NSInteger)numberOfExecutionSteps;
-(NSInteger)preProcessDisparity:(struct __CVBuffer *)arg0 normalizationMultiplier:(float)arg1 normalizationOffset:(float)arg2 output:(struct __CVBuffer *)arg3 ;
-(NSInteger)prepareForEngineType:(NSUInteger)arg0 inputColorROI:(struct CGRect )arg1 ;
-(id)getIntermediates;
-(id)init;
-(id)initForInputSource:(NSUInteger)arg0 ;
-(void)dealloc;
-(void)deallocateEspressoBuffers;


@end


#endif