// Headers generated with ktool v0.19.0
// https://github.com/kritantadev/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 15.0.0 | SDK: 15.0.0


#ifndef ADREPROJECTION_H
#define ADREPROJECTION_H

@class NSObject;



@interface ADReprojection : NSObject {
    *CGPoint _intermediateUndistortedCameraPixels;
    ? _points;
    *float _inOutDepth;
    *CGPoint _srcCameraPixels;
    *CGPoint _dstCameraPixels;
    *int _warpMaskX;
    *int _warpMaskY;
    *float _warpMaskZHelper;
    BOOL _singlePassOptimizationUsed;
    *__CVBuffer _warpMap;
}


@property (readonly, nonatomic) NSUInteger capacity; // ivar: _capacity
@property (nonatomic) BOOL fullPassReprojectionAllowed; // ivar: _fullPassReprojectionAllowed
@property (readonly, nonatomic) NSUInteger length; // ivar: _length
@property (nonatomic) BOOL singlePassReprojectionAllowed; // ivar: _singlePassReprojectionAllowed
@property (nonatomic) NSUInteger streakingInfill; // ivar: _streakingInfill


-(BOOL)fullPassReprojectionAllowed;
-(BOOL)isCalibrationUndistorted:(id)arg0 ;
-(BOOL)singlePassReprojectionAllowed;
-(BOOL)updateCapacity:(NSUInteger)arg0 ;
-(NSInteger)updateWarpMapWithDepth:(struct __CVBuffer *)arg0 srcDepthUnits:(NSUInteger)arg1 dstDepthUnits:(NSUInteger)arg2 srcCalibration:(id)arg3 dstCalibration:(id)arg4 poseTransform:(struct ? )arg5 warpedDepth:(struct __CVBuffer *)arg6 ;
-(NSInteger)updateWarpMapWithDepth:(struct __CVBuffer *)arg0 srcDepthUnits:(NSUInteger)arg1 dstDepthUnits:(NSUInteger)arg2 srcCalibration:(id)arg3 dstCalibration:(id)arg4 sourceToDestinationTransform:(struct ? )arg5 warpedDepth:(struct __CVBuffer *)arg6 ;
-(NSInteger)updateWarpWithWarpedDepthBuffer:(struct __CVBuffer *)arg0 depthUnits:(NSUInteger)arg1 dimensions:(struct CGSize )arg2 validPixels:(NSUInteger)arg3 ;
-(NSInteger)warpImage:(struct __CVBuffer *)arg0 intoImage:(struct __CVBuffer *)arg1 ;
-(id)init;
-(id)initWithCapacity:(NSUInteger)arg0 ;
-(id)initWithCapacity:(NSUInteger)arg0 streakingInfill:(NSUInteger)arg1 ;
-(id)initWithStreakingInfill:(NSUInteger)arg0 ;
-(int)vectorizeCameraPixels:(struct __CVBuffer *)arg0 depthUnits:(NSUInteger)arg1 ;
-(void)calculateWarpedPixelsFromSrcCalibration:(id)arg0 dstCalibration:(id)arg1 sourceToDestinationTransform:(struct ? *)arg2 validPixels:(NSUInteger)arg3 ;
-(void)dealloc;
-(void)deallocateBuffers;


@end


#endif