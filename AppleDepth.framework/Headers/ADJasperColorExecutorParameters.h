// Headers generated with ktool v0.19.0
// https://github.com/kritantadev/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 15.0.0 | SDK: 15.0.0


#ifndef ADJASPERCOLOREXECUTORPARAMETERS_H
#define ADJASPERCOLOREXECUTORPARAMETERS_H



#import "ADExecutorParameters.h"
#import "ADJasperColorPipelineParameters.h"

@interface ADJasperColorExecutorParameters : ADExecutorParameters

@property (nonatomic) BOOL doComputeNormals; // ivar: _doComputeNormals
@property (nonatomic) BOOL doTemporalConsistency; // ivar: _doTemporalConsistency
@property (readonly, retain, nonatomic) ADJasperColorPipelineParameters *pipelineParameters; // ivar: _pipelineParameters
@property (nonatomic) NSUInteger temporalConsistencyMethod; // ivar: _temporalConsistencyMethod
@property (nonatomic) BOOL useAlphaMapForTemporalConsistency; // ivar: _useAlphaMapForTemporalConsistency


-(BOOL)doComputeNormals;
-(BOOL)doTemporalConsistency;
-(BOOL)useAlphaMapForTemporalConsistency;
-(id)initForPipeline:(id)arg0 ;


@end


#endif