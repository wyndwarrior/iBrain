// Headers generated with ktool v0.19.0
// https://github.com/kritantadev/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 15.0.0 | SDK: 15.0.0


#ifndef ADFILELOGGERHANDLER_H
#define ADFILELOGGERHANDLER_H

@class NSString;


#import "AppleDepthLoggerHandler.h"

@interface ADFileLoggerHandler : AppleDepthLoggerHandler {
    NSString *_logFolder;
    NSString *_loggerName;
}




-(NSInteger)setLogFolder:(id)arg0 ;
-(id)getFullPath:(char *)arg0 timestamp:(CGFloat)arg1 extension:(char *)arg2 ;
-(id)init;
-(id)initWithName:(id)arg0 ;
-(id)name;
-(void)logCalibration:(id)arg0 name:(char *)arg1 timestamp:(CGFloat)arg2 ;
-(void)logDictionary:(id)arg0 name:(char *)arg1 timestamp:(CGFloat)arg2 ;
-(void)logMatrix4x3:(struct ? )arg0 name:(char *)arg1 timestamp:(CGFloat)arg2 ;
-(void)logMatrix4x4:(struct ? )arg0 name:(char *)arg1 timestamp:(CGFloat)arg2 ;
-(void)logPixelBuffer:(struct __CVBuffer *)arg0 name:(char *)arg1 timestamp:(CGFloat)arg2 ;
-(void)logPointCloud:(id)arg0 name:(char *)arg1 timestamp:(CGFloat)arg2 ;
-(void)logRawBuffer:(*void)arg0 size:(NSUInteger)arg1 name:(char *)arg2 timestamp:(CGFloat)arg3 ;
-(void)logString:(id)arg0 name:(char *)arg1 timestamp:(CGFloat)arg2 ;


@end


#endif