// Headers generated with ktool v0.19.0
// https://github.com/kritantadev/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 15.0.0 | SDK: 15.0.0


#ifndef ADMUTABLECAMERACALIBRATION_H
#define ADMUTABLECAMERACALIBRATION_H



#import "ADCameraCalibration.h"
#import "ADLensDistortionModel-Protocol.h"

@interface ADMutableCameraCalibration : ADCameraCalibration

@property (nonatomic) ? cameraToPlatformTransform;
@property (retain, nonatomic) id<ADLensDistortionModel> *distortionModel;
@property (nonatomic) ? intrinsicMatrix;
@property (nonatomic) float pixelSize;
@property (nonatomic) CGSize referenceDimensions;


-(BOOL)adjustForImageRotation:(NSInteger)arg0 ;
-(BOOL)scale:(struct CGSize )arg0 ;
-(void)centerCrop:(struct CGSize )arg0 ;
-(void)crop:(struct CGRect )arg0 ;


@end


#endif