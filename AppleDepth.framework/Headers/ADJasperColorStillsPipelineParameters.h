// Headers generated with ktool v0.19.0
// https://github.com/kritantadev/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 15.0.0 | SDK: 15.0.0


#ifndef ADJASPERCOLORSTILLSPIPELINEPARAMETERS_H
#define ADJASPERCOLORSTILLSPIPELINEPARAMETERS_H



#import "ADPipelineParameters.h"
#import "ADJasperPointCloudFilterParameters.h"

@interface ADJasperColorStillsPipelineParameters : ADPipelineParameters

@property (retain, nonatomic) ADJasperPointCloudFilterParameters *pointCloudFilter; // ivar: _pointCloudFilter
@property (retain, nonatomic) ADJasperPointCloudFilterParameters *pointCloudFilterForTransformCorrection; // ivar: _pointCloudFilterForTransformCorrection


-(id)init;


@end


#endif