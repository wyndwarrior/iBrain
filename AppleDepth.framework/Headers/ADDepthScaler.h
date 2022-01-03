// Headers generated with ktool v0.19.0
// https://github.com/kritantadev/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 15.0.0 | SDK: 15.0.0


#ifndef ADDEPTHSCALER_H
#define ADDEPTHSCALER_H

@class NSObject;



@interface ADDepthScaler : NSObject

@property (readonly, nonatomic) float interpThreshold; // ivar: _interpThreshold
@property (readonly, nonatomic) float noDepthOutputValue; // ivar: _noDepthOutputValue


-(NSInteger)scaleDepthBuffer:(struct __CVBuffer *)arg0 withCropRect:(struct CGRect )arg1 toBuffer:(struct __CVBuffer *)arg2 ;
-(NSInteger)scaleDepthBuffer:(struct __CVBuffer *)arg0 withZoomFactor:(float)arg1 toBuffer:(struct __CVBuffer *)arg2 ;
+(id)defaultScaler;
+(id)scalerWithInterpThreshold:(float)arg0 andNoDepthOutputValue:(float)arg1 ;


@end


#endif