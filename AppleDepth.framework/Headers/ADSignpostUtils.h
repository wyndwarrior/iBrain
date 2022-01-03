// Headers generated with ktool v0.19.0
// https://github.com/kritantadev/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 15.0.0 | SDK: 15.0.0


#ifndef ADSIGNPOSTUTILS_H
#define ADSIGNPOSTUTILS_H

@class NSObject;



@interface ADSignpostUtils : NSObject



+(void)markEndFrame:(BOOL)arg0 name:(id)arg1 mappingId:(NSUInteger)arg2 ;
+(void)markEndMeasurement;
+(void)markStartFrame:(id)arg0 mappingId:(NSUInteger)arg1 ;
+(void)markStartMeasurement;


@end


#endif