// Headers generated with ktool v0.19.0
// https://github.com/kritantadev/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 15.0.0 | SDK: 15.0.0


#ifndef ADDYNAMICPOLYNOMIALSLENSDISTORTIONMODEL_H
#define ADDYNAMICPOLYNOMIALSLENSDISTORTIONMODEL_H



#import "ADPolynomialsLensDistortionModel.h"

@interface ADDynamicPolynomialsLensDistortionModel : ADPolynomialsLensDistortionModel {
    ADDistortionPolynomials _polynomialsBase;
    ADDistortionPolynomials _polynomialsDynamic;
}


@property (nonatomic) *ADDistortionPolynomials distortionPolynomialsBase;
@property (nonatomic) *ADDistortionPolynomials distortionPolynomialsDynamic;
@property (nonatomic) float dynamicFactor; // ivar: _dynamicFactor


-(id)copyWithZone:(struct _NSZone *)arg0 ;
-(id)initWithDistortionCenter:(struct CGPoint )arg0 dynFactor:(float)arg1 polynomialsBase:(struct ADDistortionPolynomials *)arg2 polynomialsDynamic:(struct ADDistortionPolynomials *)arg3 ;
-(void)setDistortionPolynomials:(struct ADDistortionPolynomials *)arg0 ;
-(void)updatePolynomials;


@end


#endif