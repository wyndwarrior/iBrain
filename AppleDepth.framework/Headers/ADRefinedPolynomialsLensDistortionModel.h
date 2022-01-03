// Headers generated with ktool v0.19.0
// https://github.com/kritantadev/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 15.0.0 | SDK: 15.0.0


#ifndef ADREFINEDPOLYNOMIALSLENSDISTORTIONMODEL_H
#define ADREFINEDPOLYNOMIALSLENSDISTORTIONMODEL_H



#import "ADDynamicPolynomialsLensDistortionModel.h"

@interface ADRefinedPolynomialsLensDistortionModel : ADDynamicPolynomialsLensDistortionModel

@property (nonatomic) float focalLength; // ivar: _focalLength
@property (nonatomic) float pixelSize; // ivar: _pixelSize


-(id)copyWithZone:(struct _NSZone *)arg0 ;
-(id)initWithDistortionCenter:(struct CGPoint )arg0 pixelSize:(float)arg1 focalLength:(float)arg2 polynomialsBase:(struct ADDistortionPolynomials *)arg3 polynomialsDynamic:(struct ADDistortionPolynomials *)arg4 ;
-(void)distortPixels:(NSUInteger)arg0 undistortedPixels:(struct CGPoint *)arg1 withCameraCalibration:(id)arg2 outDistortedPixels:(struct CGPoint *)arg3 ;
-(void)setDynamicFactor:(float)arg0 ;
-(void)undistortPixels:(NSUInteger)arg0 distortedPixels:(struct CGPoint *)arg1 withCameraCalibration:(id)arg2 outUndistortedPixels:(struct CGPoint *)arg3 ;
-(void)updateDynamicFactor;


@end


#endif