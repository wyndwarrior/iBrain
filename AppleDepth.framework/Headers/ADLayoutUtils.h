// Headers generated with ktool v0.19.0
// https://github.com/kritantadev/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 15.0.0 | SDK: 15.0.0


#ifndef ADLAYOUTUTILS_H
#define ADLAYOUTUTILS_H

@class NSObject;



@interface ADLayoutUtils : NSObject



+(BOOL)aspectRatio:(float)arg0 matchesAspectRatio:(float)arg1 ;
+(BOOL)isLandscape:(NSUInteger)arg0 ;
+(BOOL)isLandscapeSize:(struct CGSize )arg0 ;
+(NSUInteger)adjustLayout:(NSUInteger)arg0 sourceOrientation:(unsigned int)arg1 toRotationPreference:(NSUInteger)arg2 ;
+(NSUInteger)layoutForSize:(struct CGSize )arg0 ;
+(NSUInteger)transposeLayout:(NSUInteger)arg0 ;
+(float)aspectRatioForKnownLayout:(NSUInteger)arg0 ;


@end


#endif