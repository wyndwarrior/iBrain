// Headers generated with ktool v0.19.0
// https://github.com/kritantadev/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 15.0.0 | SDK: 15.0.0


#ifndef ADPCEDISPARITYCOLOREXECUTORPARAMETERS_H
#define ADPCEDISPARITYCOLOREXECUTORPARAMETERS_H



#import "ADExecutorParameters.h"
#import "ADPCEDisparityColorPipelineParameters.h"

@interface ADPCEDisparityColorExecutorParameters : ADExecutorParameters

@property (nonatomic) unsigned short disparityInvalidValue; // ivar: _disparityInvalidValue
@property (nonatomic) BOOL disparityPreprocessingActive; // ivar: _disparityPreprocessingActive
@property (nonatomic) NSInteger disparityRotation; // ivar: _disparityRotation
@property (readonly, retain, nonatomic) ADPCEDisparityColorPipelineParameters *pipelineParameters; // ivar: _pipelineParameters
@property (nonatomic) BOOL temporalConsistencyActive; // ivar: _temporalConsistencyActive


-(BOOL)disparityPreprocessingActive;
-(BOOL)temporalConsistencyActive;
-(id)initForPipeline:(id)arg0 inputSource:(NSUInteger)arg1 ;


@end


#endif