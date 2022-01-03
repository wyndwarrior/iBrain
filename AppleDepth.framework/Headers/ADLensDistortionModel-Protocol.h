// Headers generated with ktool v0.19.0
// https://github.com/kritantadev/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 15.0.0 | SDK: 15.0.0



@protocol ADLensDistortionModel


-(void)adjustForImageRotation:(NSInteger)arg0 forDimensions:(struct CGSize )arg1 ;
-(void)distortPixels:(NSUInteger)arg0 undistortedPixels:(struct CGPoint *)arg1 withCameraCalibration:(id)arg2 outDistortedPixels:(struct CGPoint *)arg3 ;
-(void)scale:(float)arg0 ;
-(void)undistortPixels:(NSUInteger)arg0 distortedPixels:(struct CGPoint *)arg1 withCameraCalibration:(id)arg2 outUndistortedPixels:(struct CGPoint *)arg3 ;

@optional
-(id)dictionaryRepresentation:(BOOL)arg0 ;
-(id)initWithDictionary:(id)arg0 ;
-(void)crop:(struct CGRect )arg0 ;
-(void)crop:(struct CGRect )arg0 fromDimensions:(struct CGSize )arg1 ;
@end

