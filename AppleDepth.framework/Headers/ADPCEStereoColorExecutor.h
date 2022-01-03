// Headers generated with ktool v0.19.0
// https://github.com/kritantadev/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 15.0.0 | SDK: 15.0.0


#ifndef ADPCESTEREOCOLOREXECUTOR_H
#define ADPCESTEREOCOLOREXECUTOR_H



#import "ADPCEDisparityColorExecutor.h"
#import "ADPCEStereoColorExecutorParameters.h"

@interface ADPCEStereoColorExecutor : ADPCEDisparityColorExecutor

@property (copy, nonatomic) ADPCEStereoColorExecutorParameters *executorParameters;


-(id)initForInputSource:(NSUInteger)arg0 ;


@end


#endif