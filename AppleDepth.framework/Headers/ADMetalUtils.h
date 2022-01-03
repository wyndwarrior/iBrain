// Headers generated with ktool v0.19.0
// https://github.com/kritantadev/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 15.0.0 | SDK: 15.0.0


#ifndef ADMETALUTILS_H
#define ADMETALUTILS_H

@class NSObject;



@interface ADMetalUtils : NSObject



+(NSUInteger)bytesPerPixelForTextureFormat:(NSUInteger)arg0 ;
+(NSUInteger)getMTLPixelFormat:(unsigned int)arg0 ;
+(id)bindIOSurfaceToMTL2DTexture:(struct __IOSurface *)arg0 pixelFormat:(NSUInteger)arg1 width:(NSUInteger)arg2 height:(NSUInteger)arg3 plane:(NSUInteger)arg4 metalDevice:(id)arg5 error:(*id)arg6 ;
+(id)bindPixelBufferToMTL2DTexture:(struct __CVBuffer *)arg0 metalDevice:(id)arg1 ;
+(id)bindPixelBufferToMTL2DTexture:(struct __CVBuffer *)arg0 pixelFormat:(NSUInteger)arg1 textureSize:(struct CGSize )arg2 plane:(NSUInteger)arg3 metalDevice:(id)arg4 error:(*id)arg5 ;
+(id)bindPixelBufferToMTL2DTexture:(struct __CVBuffer *)arg0 plane:(NSUInteger)arg1 metalDevice:(id)arg2 error:(*id)arg3 ;
+(id)textureForSize:(struct CGSize )arg0 pixelFormat:(unsigned int)arg1 metalDevice:(id)arg2 ;
+(void)dispatchCommandEncoder:(id)arg0 pipeline:(id)arg1 width:(unsigned int)arg2 height:(unsigned int)arg3 ;


@end


#endif