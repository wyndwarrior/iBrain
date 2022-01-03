// Headers generated with ktool v0.19.0
// https://github.com/kritantadev/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 15.0.0 | SDK: 15.0.0


#ifndef ADJASPERCOLORPIPELINEPARAMETERS_H
#define ADJASPERCOLORPIPELINEPARAMETERS_H



#import "ADPipelineParameters.h"
#import "ADAggregationParameters.h"
#import "ADJasperPointCloudFilterParameters.h"

@interface ADJasperColorPipelineParameters : ADPipelineParameters

@property (retain, nonatomic) ADAggregationParameters *aggregationParameters; // ivar: _aggregationParameters
@property (nonatomic) float confidenceBucketingHighThreshold; // ivar: _confidenceBucketingHighThreshold
@property (nonatomic) float confidenceBucketingLowThreshold; // ivar: _confidenceBucketingLowThreshold
@property (nonatomic) NSUInteger confidenceUnits; // ivar: _confidenceUnits
@property (nonatomic) float defaultAlphaForDepthWarping; // ivar: _defaultAlphaForDepthWarping
@property (retain, nonatomic) ADJasperPointCloudFilterParameters *pointCloudFilter; // ivar: _pointCloudFilter


-(id)init;


@end


#endif