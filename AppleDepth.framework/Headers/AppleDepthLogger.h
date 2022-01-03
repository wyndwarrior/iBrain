// Headers generated with ktool v0.19.0
// https://github.com/kritantadev/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 15.0.0 | SDK: 15.0.0


#ifndef APPLEDEPTHLOGGER_H
#define APPLEDEPTHLOGGER_H

@class NSObject, NSMutableArray, NSSet;



@interface AppleDepthLogger : NSObject {
    int _activeHandlersCounter;
    NSMutableArray *_handlers;
    NSSet *_enabledLoggerOverrideSet;
}


@property (nonatomic) NSUInteger loggingPriority; // ivar: _loggingPriority


-(NSInteger)addHandler:(id)arg0 ;
-(NSInteger)setHostName:(id)arg0 ;
-(NSInteger)setLogFolder:(id)arg0 ;
-(id)init;
-(id)initWithHandlers:(id)arg0 ;
-(id)visualLoggerPrefices;
-(void)applyConfigurationToNewHandler:(id)arg0 ;
-(void)disable:(id)arg0 ;
-(void)disableAll;
-(void)disableFileLogging;
-(void)disableVisualLogging;
-(void)enable:(id)arg0 ;
-(void)enableAll;
-(void)enableFileLogging;
-(void)enableVisualLogging;
-(void)logCalibration:(id)arg0 name:(char *)arg1 priority:(NSUInteger)arg2 ;
-(void)logCalibration:(id)arg0 name:(char *)arg1 priority:(NSUInteger)arg2 timestamp:(CGFloat)arg3 ;
-(void)logDictionary:(id)arg0 name:(char *)arg1 priority:(NSUInteger)arg2 ;
-(void)logDictionary:(id)arg0 name:(char *)arg1 priority:(NSUInteger)arg2 timestamp:(CGFloat)arg3 ;
-(void)logMatrix4x3:(struct ? )arg0 name:(char *)arg1 priority:(NSUInteger)arg2 ;
-(void)logMatrix4x3:(struct ? )arg0 name:(char *)arg1 priority:(NSUInteger)arg2 timestamp:(CGFloat)arg3 ;
-(void)logMatrix4x4:(struct ? )arg0 name:(char *)arg1 priority:(NSUInteger)arg2 ;
-(void)logMatrix4x4:(struct ? )arg0 name:(char *)arg1 priority:(NSUInteger)arg2 timestamp:(CGFloat)arg3 ;
-(void)logPixelBuffer:(struct __CVBuffer *)arg0 name:(char *)arg1 priority:(NSUInteger)arg2 ;
-(void)logPixelBuffer:(struct __CVBuffer *)arg0 name:(char *)arg1 priority:(NSUInteger)arg2 timestamp:(CGFloat)arg3 ;
-(void)logPointCloud:(id)arg0 name:(char *)arg1 priority:(NSUInteger)arg2 ;
-(void)logPointCloud:(id)arg0 name:(char *)arg1 priority:(NSUInteger)arg2 timestamp:(CGFloat)arg3 ;
-(void)logRawBuffer:(*void)arg0 size:(NSUInteger)arg1 name:(char *)arg2 priority:(NSUInteger)arg3 ;
-(void)logRawBuffer:(*void)arg0 size:(NSUInteger)arg1 name:(char *)arg2 priority:(NSUInteger)arg3 timestamp:(CGFloat)arg4 ;
-(void)logString:(id)arg0 name:(char *)arg1 priority:(NSUInteger)arg2 ;
-(void)logString:(id)arg0 name:(char *)arg1 priority:(NSUInteger)arg2 timestamp:(CGFloat)arg3 ;
-(void)observeValueForKeyPath:(id)arg0 ofObject:(id)arg1 change:(id)arg2 context:(*void)arg3 ;
-(void)toggleByClass:(Class)arg0 enable:(BOOL)arg1 ;
-(void)toggleHandler:(id)arg0 enable:(BOOL)arg1 ;
+(id)defaultLoggerWithName:(id)arg0 ;


@end


#endif