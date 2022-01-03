// Headers generated with ktool v0.19.0
// https://github.com/kritantadev/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 15.0.0 | SDK: 15.0.0


#ifndef ADWARPERMESHLENSDISTORTIONMODEL_H
#define ADWARPERMESHLENSDISTORTIONMODEL_H

@class NSObject, NSString, NSData;


#import "ADLensDistortionModel-Protocol.h"

@interface ADWarperMeshLensDistortionModel : NSObject <ADLensDistortionModel>

 {
    ADWarperMesh _undistortMesh;
    ADWarperMesh _distortMesh;
}


@property (readonly, copy) NSString *debugDescription;
@property (readonly, copy) NSString *description;
@property (readonly) NSUInteger hash;
@property (readonly) NSInteger height;
@property (readonly) Class superclass;
@property (readonly) NSUInteger type;
@property (readonly, retain) NSData *warperMesh;
@property (readonly) NSInteger width;


-(id)copyWithZone:(struct _NSZone *)arg0 ;
-(id)dictionaryRepresentation:(BOOL)arg0 ;
-(id)initWithDictionary:(id)arg0 ;
-(id)initWithWarperMesh:(id)arg0 type:(NSUInteger)arg1 width:(NSInteger)arg2 height:(NSInteger)arg3 ;
-(void)adjustForImageRotation:(NSInteger)arg0 forDimensions:(struct CGSize )arg1 ;
-(void)crop:(struct CGRect )arg0 fromDimensions:(struct CGSize )arg1 ;
-(void)distortPixels:(NSUInteger)arg0 undistortedPixels:(struct CGPoint *)arg1 withCameraCalibration:(id)arg2 outDistortedPixels:(struct CGPoint *)arg3 ;
-(void)scale:(float)arg0 ;
-(void)undistortPixels:(NSUInteger)arg0 distortedPixels:(struct CGPoint *)arg1 withCameraCalibration:(id)arg2 outUndistortedPixels:(struct CGPoint *)arg3 ;


@end


#endif