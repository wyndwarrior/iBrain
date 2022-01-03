// Headers generated with ktool v0.19.0
// https://github.com/kritantadev/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 15.0.0 | SDK: 15.0.0


#ifndef ADMONOCULAREXECUTORPARAMETERS_H
#define ADMONOCULAREXECUTORPARAMETERS_H



#import "ADExecutorParameters.h"
#import "ADMonocularPipelineParameters.h"

@interface ADMonocularExecutorParameters : ADExecutorParameters

@property (readonly, retain, nonatomic) ADMonocularPipelineParameters *pipelineParameters; // ivar: _pipelineParameters


-(id)initForPipeline:(id)arg0 ;


@end


#endif