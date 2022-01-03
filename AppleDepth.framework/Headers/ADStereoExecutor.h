// Headers generated with ktool v0.19.0
// https://github.com/kritantadev/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 15.0.0 | SDK: 15.0.0


#ifndef ADSTEREOEXECUTOR_H
#define ADSTEREOEXECUTOR_H

// Failed to load a method with 'NoneType' object is not subscriptable



#import "ADExecutor.h"
#import "ADStereoExecutorParameters.h"
#import "ADStereoPipeline.h"

@interface ADStereoExecutor : ADExecutor {
    BOOL _isPrepared;
    CGRect _refColorROI;
    CGRect _auxColorROI;
    *__CVBuffer _refColor;
    *__CVBuffer _itmChunkyRefColor;
    *__CVBuffer _itmCroppedScaledRefColor;
    *__CVBuffer _itmRotatedRefColor;
    *__CVBuffer _auxColor;
    *__CVBuffer _itmChunkyAuxColor;
    *__CVBuffer _itmCroppedScaledAuxColor;
    *__CVBuffer _itmRotatedAuxColor;
    *__CVBuffer _disparity;
}


@property (copy, nonatomic) ADStereoExecutorParameters *executorParameters; // ivar: _executorParameters
@property (readonly, retain, nonatomic) ADStereoPipeline *pipeline; // ivar: _pipeline


-(NSInteger)allocateIntermediateBuffers;
-(NSInteger)numberOfExecutionSteps;
-(NSInteger)prepareForEngineType:(NSUInteger)arg0 ;
-(NSInteger)prepareWithBestEngine;
-(id)initWithInputAlignment:(NSUInteger)arg0 andPrioritization:(NSInteger)arg1 ;
-(void)dealloc;
-(void)deallocateEspressoBuffers;


@end


#endif