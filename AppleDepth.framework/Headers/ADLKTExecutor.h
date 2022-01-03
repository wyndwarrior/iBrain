// Headers generated with ktool v0.19.0
// https://github.com/kritantadev/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 15.0.0 | SDK: 15.0.0


#ifndef ADLKTEXECUTOR_H
#define ADLKTEXECUTOR_H

// Failed to load a method with 'NoneType' object is not subscriptable

@class NSObject;
@protocol MTLDevice, MTLCommandQueue;


#import "ADLKTOpticalFlow.h"

@interface ADLKTExecutor : NSObject {
    id<MTLDevice> *_device;
    ADLKTOpticalFlow *_lkt;
    BOOL _isFirstTime;
    CGSize _inputSize;
    id<MTLCommandQueue> *_commandQueue;
    unsigned int _currentFrameIndex;
    NSMutableArray" _pyramids;
    NSMutableArray" _features;
    NSMutableArray" _derivitives;
}




-(NSInteger)executeWithFrame:(struct __CVBuffer *)arg0 intoOpticalFlowBuffer:(struct __CVBuffer *)arg1 ;
-(id)initWithDescriptor:(id)arg0 forLayout:(NSUInteger)arg1 ;
-(id)initWithSize:(struct CGSize )arg0 ;
-(struct __CVBuffer *)createPixelBufferForOpticalFlow;


@end


#endif