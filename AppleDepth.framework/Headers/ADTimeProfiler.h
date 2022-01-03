// Headers generated with ktool v0.19.0
// https://github.com/kritantadev/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 15.0.0 | SDK: 15.0.0


#ifndef ADTIMEPROFILER_H
#define ADTIMEPROFILER_H

@class NSObject, NSMutableArray;



@interface ADTimeProfiler : NSObject

@property (retain, nonatomic) NSMutableArray *logArray; // ivar: _logArray


-(NSUInteger)currentTime;
-(id)description;
-(id)init;
-(id)log;
-(id)stringLog;
-(id)valueDictForOperationName:(id)arg0 ;
-(void)printLog;
-(void)reset;
-(void)start:(id)arg0 ;
-(void)startForOperationWithName:(id)arg0 ;
-(void)stop:(id)arg0 ;
-(void)stopForOperationWithName:(id)arg0 ;


@end


#endif