// Headers generated with ktool v0.19.0
// https://github.com/kritantadev/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 15.0.0 | SDK: 15.0.0


#ifndef ADADAPTIVECORRECTIONDUALCAMERACALIBRATIONMODEL_H
#define ADADAPTIVECORRECTIONDUALCAMERACALIBRATIONMODEL_H

@class NSObject;



@interface ADAdaptiveCorrectionDualCameraCalibrationModel : NSObject

@property (nonatomic) float focalLengthPixAux; // ivar: _focalLengthPixAux
@property (nonatomic) float focalLengthPixRef; // ivar: _focalLengthPixRef
@property (nonatomic) CGPoint opticalCenterAux; // ivar: _opticalCenterAux
@property (nonatomic) CGPoint opticalCenterRef; // ivar: _opticalCenterRef
@property (nonatomic) ? refToAuxExtrinsic; // ivar: _refToAuxExtrinsic


-(NSInteger)computeStereoRectificationHomographiesMappingRectTeleToTele:(struct ? *)arg0 rectTeleToWide:(struct ? *)arg1 teleToRectTele:(struct ? *)arg2 ;


@end


#endif