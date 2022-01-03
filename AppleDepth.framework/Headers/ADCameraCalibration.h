// Headers generated with ktool v0.19.0
// https://github.com/kritantadev/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 15.0.0 | SDK: 15.0.0


#ifndef ADCAMERACALIBRATION_H
#define ADCAMERACALIBRATION_H

@class NSObject;


#import "NSCopying-Protocol.h"
#import "NSMutableCopying-Protocol.h"
#import "ADLensDistortionModel-Protocol.h"

@interface ADCameraCalibration : NSObject <NSCopying, NSMutableCopying>



@property (readonly, nonatomic) ? cameraToPlatformTransform; // ivar: _cameraToPlatformTransform
@property (readonly, nonatomic) id<ADLensDistortionModel> *distortionModel; // ivar: _distortionModel
@property (readonly, nonatomic) ? intrinsicMatrix; // ivar: _intrinsicMatrix
@property (readonly, nonatomic) float pixelSize; // ivar: _pixelSize
@property (readonly, nonatomic) CGSize referenceDimensions; // ivar: _referenceDimensions


-(BOOL)writeToFile:(id)arg0 atomically:(BOOL)arg1 ;
-(id)copyWithZone:(struct _NSZone *)arg0 ;
-(id)createDictionaryRepresentationWithHumanReadable:(BOOL)arg0 ;
-(id)dictionaryRepresentation;
-(id)initWithDictionary:(id)arg0 ;
-(id)initWithFile:(id)arg0 ;
-(id)initWithIntrinsics:(struct ? )arg0 cameraToPlatformTransform:(struct ? )arg1 pixelSize:(CGFloat)arg2 forReferenceDimensions:(struct CGSize )arg3 withDistortionModel:(id)arg4 ;
-(id)mutableCopyWithZone:(struct _NSZone *)arg0 ;
-(struct ? )getTransformationTo:(id)arg0 ;
-(void)backProject:(NSUInteger)arg0 undistortedPixels:(struct CGPoint *)arg1 withR:(*float)arg2 outPoints;
-(void)backProject:(NSUInteger)arg0 undistortedPixels:(struct CGPoint *)arg1 withZ:(*float)arg2 outPoints;
-(void)distort:(NSUInteger)arg0 undistortedPixels:(struct CGPoint *)arg1 outDistorted:(struct CGPoint *)arg2 ;
-(void)project:(NSUInteger)arg0 points:(struct CGPoint **)arg1 outUndistortedPixels;
-(void)project:(NSUInteger)arg0 points:(struct CGPoint **)arg1 outUndistortedPixels:(*float)arg2 outR;
-(void)transform:(NSUInteger)arg0 points:(*id)arg1 toCameraoutPoints;
-(void)undistort:(NSUInteger)arg0 distortedPixels:(struct CGPoint *)arg1 outUndistorted:(struct CGPoint *)arg2 ;
+(struct ? )createIntrinsicsMatrixWithEFL:(float)arg0 principalPointX:(float)arg1 principalPointY:(float)arg2 ;
+(void)transform:(NSUInteger)arg0 points:(struct ? *)arg1 withoutPoints;


@end


#endif