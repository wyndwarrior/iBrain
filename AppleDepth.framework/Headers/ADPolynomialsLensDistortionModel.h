// Headers generated with ktool v0.19.0
// https://github.com/kritantadev/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 15.0.0 | SDK: 15.0.0


#ifndef ADPOLYNOMIALSLENSDISTORTIONMODEL_H
#define ADPOLYNOMIALSLENSDISTORTIONMODEL_H

@class NSObject, NSString;


#import "ADLensDistortionModel-Protocol.h"

@interface ADPolynomialsLensDistortionModel : NSObject <ADLensDistortionModel>

 {
    ADDistortionPolynomials _polynomials;
}


@property (readonly, copy) NSString *debugDescription;
@property (readonly, copy) NSString *description;
@property (nonatomic) CGPoint distortionCenter; // ivar: _distortionCenter
@property (nonatomic) *ADDistortionPolynomials distortionPolynomials;
@property (readonly) NSUInteger hash;
@property (readonly) Class superclass;


-(CGFloat)getMaxDistortedRadius:(struct CGSize )arg0 ;
-(id)copyWithZone:(struct _NSZone *)arg0 ;
-(id)dictionaryRepresentation:(BOOL)arg0 ;
-(id)initWithDictionary:(id)arg0 ;
-(id)initWithDistortionCenter:(struct CGPoint )arg0 andPloynomials:(struct ADDistortionPolynomials *)arg1 ;
-(id)initWithDistortionCenter:(struct CGPoint )arg0 andPolynomials:(struct ADDistortionPolynomials *)arg1 ;
-(void)adjustForImageRotation:(NSInteger)arg0 forDimensions:(struct CGSize )arg1 ;
-(void)crop:(struct CGRect )arg0 fromDimensions:(struct CGSize )arg1 ;
-(void)distortPixels:(NSUInteger)arg0 undistortedPixels:(struct CGPoint *)arg1 withCameraCalibration:(id)arg2 outDistortedPixels:(struct CGPoint *)arg3 ;
-(void)distortPixels:(NSUInteger)arg0 undistortedPixels:(struct CGPoint *)arg1 withPixelSize:(CGFloat)arg2 referenceDimensions:(struct CGSize )arg3 outDistortedPixels:(struct CGPoint *)arg4 ;
-(void)scale:(float)arg0 ;
-(void)undistortPixels:(NSUInteger)arg0 distortedPixels:(struct CGPoint *)arg1 withCameraCalibration:(id)arg2 outUndistortedPixels:(struct CGPoint *)arg3 ;
-(void)undistortPixels:(NSUInteger)arg0 distortedPixels:(struct CGPoint *)arg1 withPixelSize:(CGFloat)arg2 referenceDimensions:(struct CGSize )arg3 outUndistortedPixels:(struct CGPoint *)arg4 ;


@end


#endif