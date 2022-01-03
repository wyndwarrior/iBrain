// Headers generated with ktool v0.19.0
// https://github.com/kritantadev/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 15.0.0 | SDK: 15.0.0


#ifndef ADMONOCULARV2EXECUTOR_H
#define ADMONOCULARV2EXECUTOR_H

// Failed to load a method with 'NoneType' object is not subscriptable



#import "ADExecutor.h"
#import "ADMonocularV2Pipeline.h"
#import "ADMonocularV2ExecutorParameters.h"

@interface ADMonocularV2Executor : ADExecutor {
    BOOL _isPrepared;
    ADMonocularV2Pipeline *_pipeline;
    *__CVBuffer _itmCroppedScaledColor;
    *__CVBuffer _itmRotatedColor;
    *__CVBuffer _itmPreProcessedColor;
    *__CVBuffer _itmPrevDisparity;
    *__CVBuffer _itmUnprocessedOutputDisparity;
}


@property (copy, nonatomic) ADMonocularV2ExecutorParameters *executorParameters; // ivar: _executorParameters
@property (readonly, nonatomic) *__CVBuffer prevDisparity;


-(NSInteger)allocateIntermediateBuffers;
-(NSInteger)numberOfExecutionSteps;
-(NSInteger)prepareForEngineType:(NSUInteger)arg0 inputColorROI:(struct CGRect )arg1 ;
-(id)getIntermediates;
-(id)initWithInputPrioritization:(NSInteger)arg0 ;
-(void)dealloc;
-(void)deallocateEspressoBuffers;


@end


#endif