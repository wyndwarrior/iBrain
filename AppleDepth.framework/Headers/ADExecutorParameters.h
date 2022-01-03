// Headers generated with ktool v0.19.0
// https://github.com/kritantadev/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 15.0.0 | SDK: 15.0.0


#ifndef ADEXECUTORPARAMETERS_H
#define ADEXECUTORPARAMETERS_H

@class NSObject, NSString;


#import "AppleDepthLogger.h"
#import "ADTimeProfiler.h"

@interface ADExecutorParameters : NSObject

@property (copy, nonatomic) NSString *intermediatesOutputPath; // ivar: _intermediatesOutputPath
@property (retain, nonatomic) AppleDepthLogger *logger; // ivar: _logger
@property (nonatomic) BOOL powerMeasureMode; // ivar: _powerMeasureMode
@property (nonatomic) NSInteger stepsToSkip; // ivar: _stepsToSkip
@property (retain, nonatomic) ADTimeProfiler *timeProfiler; // ivar: _timeProfiler


-(BOOL)powerMeasureMode;
-(id)init;


@end


#endif