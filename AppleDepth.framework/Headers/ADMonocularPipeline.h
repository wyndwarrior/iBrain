// Headers generated with ktool v0.19.0
// https://github.com/kritantadev/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 15.0.0 | SDK: 15.0.0


#ifndef ADMONOCULARPIPELINE_H
#define ADMONOCULARPIPELINE_H

@class NSObject;


#import "ADNetworkProvider.h"
#import "ADEspressoMonocularInferenceDescriptor.h"
#import "ADImageDescriptor.h"
#import "ADMonocularPipelineParameters.h"

@interface ADMonocularPipeline : NSObject {
    NSInteger _prioritization;
    ADNetworkProvider *_networkProvider;
    ADEspressoMonocularInferenceDescriptor *_inferenceDesc;
    ADImageDescriptor *_processedDepthDesc;
    BOOL _isDenseDepthInverse;
}


@property (copy, nonatomic) ADMonocularPipelineParameters *pipelineParameters; // ivar: _pipelineParameters


-(NSInteger)postProcessWithDepth:(struct __CVBuffer *)arg0 depthOutput:(struct __CVBuffer *)arg1 ;
-(id)inferenceDescriptor;
-(id)initWithInputPrioritization:(NSInteger)arg0 ;
-(id)initWithInputPrioritization:(NSInteger)arg0 andParameters:(id)arg1 ;
-(id)processedDepthOutputDescriptor;


@end


#endif