// Headers generated with ktool v0.19.0
// https://github.com/kritantadev/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 15.0.0 | SDK: 15.0.0


#ifndef ADPCEDISPARITYCOLORPIPELINEPARAMETERS_H
#define ADPCEDISPARITYCOLORPIPELINEPARAMETERS_H



#import "ADPipelineParameters.h"

@interface ADPCEDisparityColorPipelineParameters : ADPipelineParameters

@property (nonatomic) float maxDisparity; // ivar: _maxDisparity
@property (nonatomic) float minDisparity; // ivar: _minDisparity
@property (nonatomic) float pceBias; // ivar: _pceBias


-(id)init;


@end


#endif