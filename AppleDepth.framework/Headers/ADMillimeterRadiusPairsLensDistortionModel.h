// Headers generated with ktool v0.19.0
// https://github.com/kritantadev/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 15.0.0 | SDK: 15.0.0


#ifndef ADMILLIMETERRADIUSPAIRSLENSDISTORTIONMODEL_H
#define ADMILLIMETERRADIUSPAIRSLENSDISTORTIONMODEL_H

@class NSObject, NSString, NSData;


#import "ADLensDistortionModel-Protocol.h"

@interface ADMillimeterRadiusPairsLensDistortionModel : NSObject <ADLensDistortionModel>



@property (readonly, copy) NSString *debugDescription;
@property (readonly, copy) NSString *description;
@property (retain, nonatomic) NSData *distortedRadii; // ivar: _distortedRadii
@property (nonatomic) CGPoint distortionCenter; // ivar: _distortionCenter
@property (readonly) NSUInteger hash;
@property (readonly) Class superclass;
@property (retain, nonatomic) NSData *undistortedRadii; // ivar: _undistortedRadii


-(id)copyWithZone:(struct _NSZone *)arg0 ;
-(id)dictionaryRepresentation:(BOOL)arg0 ;
-(id)initWithDictionary:(id)arg0 ;
-(id)initWithDistortionCenter:(struct CGPoint )arg0 distortedRadii:(id)arg1 undistortedRadii:(id)arg2 ;
-(void)adjustForImageRotation:(NSInteger)arg0 forDimensions:(struct CGSize )arg1 ;
-(void)applyDistortionModelToPixels:(NSUInteger)arg0 inPixels:(struct CGPoint *)arg1 intrinsicsMatrix:(struct ? )arg2 pixelSize:(CGFloat)arg3 distort:(BOOL)arg4 outPixels:(struct CGPoint *)arg5 ;
-(void)crop:(struct CGRect )arg0 fromDimensions:(struct CGSize )arg1 ;
-(void)distortPixels:(NSUInteger)arg0 undistortedPixels:(struct CGPoint *)arg1 withCameraCalibration:(id)arg2 outDistortedPixels:(struct CGPoint *)arg3 ;
-(void)scale:(float)arg0 ;
-(void)undistortPixels:(NSUInteger)arg0 distortedPixels:(struct CGPoint *)arg1 withCameraCalibration:(id)arg2 outUndistortedPixels:(struct CGPoint *)arg3 ;


@end


#endif