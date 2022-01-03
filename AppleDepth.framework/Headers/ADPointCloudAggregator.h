// Headers generated with ktool v0.19.0
// https://github.com/kritantadev/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 15.0.0 | SDK: 15.0.0


#ifndef ADPOINTCLOUDAGGREGATOR_H
#define ADPOINTCLOUDAGGREGATOR_H

@class NSObject;


#import "ADAggregationParameters.h"
#import "ADCameraCalibration.h"
#import "ADJasperPointCloudFilterParameters.h"

@interface ADPointCloudAggregator : NSObject {
    *? _history;
    NSUInteger _historyIndex;
}


@property (readonly, retain, nonatomic) ADAggregationParameters *aggregationParameters; // ivar: _aggregationParameters
@property (retain) ADCameraCalibration *colorCameraCalibration; // ivar: _colorCameraCalibration
@property ? jasperToCameraTransform; // ivar: _jasperToCameraTransform
@property (retain, nonatomic) ADJasperPointCloudFilterParameters *pointCloudFilterParameters; // ivar: _pointCloudFilterParameters


-(NSInteger)aggregateAndProjectForTime:(CGFloat)arg0 worldToCameraTransform:(struct ? )arg1 cropTo:(struct CGRect )arg2 rotateBy:(NSInteger)arg3 projectedPointsBuffer:(struct __CVBuffer *)arg4 ;
-(NSInteger)aggregateAndProjectForTime:(CGFloat)arg0 worldToCameraTransform:(struct ? )arg1 filterParams:(id)arg2 cropTo:(struct CGRect )arg3 rotateBy:(NSInteger)arg4 projectedPointsBuffer:(struct __CVBuffer *)arg5 ;
-(NSInteger)clear;
-(NSInteger)pushPointCloud:(id)arg0 timestamp:(CGFloat)arg1 worldToCameraTransform:(struct ? )arg2 ;
-(id)aggregateForTime:(CGFloat)arg0 worldToCameraTransform:(struct ? )arg1 ;
-(id)initWithAggregationParameters:(id)arg0 ;
-(id)initWithAggregationParameters:(id)arg0 jasperToColorTransform:(struct ? )arg1 colorCamera:(id)arg2 ;
-(void)dealloc;
+(struct ? )transformMetersToMillimiters:(struct ? )arg0 ;


@end


#endif