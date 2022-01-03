// Headers generated with ktool v0.19.0
// https://github.com/kritantadev/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 15.0.0 | SDK: 15.0.0


#ifndef ADMONOCULARV2EXECUTORPARAMETERS_H
#define ADMONOCULARV2EXECUTORPARAMETERS_H



#import "ADExecutorParameters.h"
#import "ADMonocularV2PipelineParameters.h"

@interface ADMonocularV2ExecutorParameters : ADExecutorParameters

@property (readonly, retain, nonatomic) ADMonocularV2PipelineParameters *pipelineParameters; // ivar: _pipelineParameters


-(id)initForPipeline:(id)arg0 ;


@end


#endif