// Headers generated with ktool v0.19.0
// https://github.com/kritantadev/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 15.0.0 | SDK: 15.0.0


#ifndef ADMONOCULARV2PIPELINE_H
#define ADMONOCULARV2PIPELINE_H

@class NSObject;


#import "ADNetworkProvider.h"
#import "ADEspressoMonocularV2InferenceDescriptor.h"
#import "ADMonocularV2PipelineParameters.h"

@interface ADMonocularV2Pipeline : NSObject {
    ADNetworkProvider *_networkProvider;
    ADEspressoMonocularV2InferenceDescriptor *_inferenceDesc;
}


@property (copy, nonatomic) ADMonocularV2PipelineParameters *pipelineParameters; // ivar: _pipelineParameters


-(NSInteger)adjustForEngine:(NSUInteger)arg0 ;
-(NSInteger)postProcessDisparity:(struct __CVBuffer *)arg0 output:(struct __CVBuffer *)arg1 ;
-(id)inferenceDescriptor;
-(id)initWithInputPrioritization:(NSInteger)arg0 ;
-(id)initWithInputPrioritization:(NSInteger)arg0 andParameters:(id)arg1 ;


@end


#endif