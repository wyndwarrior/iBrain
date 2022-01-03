// Headers generated with ktool v0.19.0
// https://github.com/kritantadev/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 15.0.0 | SDK: 15.0.0


#ifndef ADMUTABLEJASPERPOINTCLOUD_H
#define ADMUTABLEJASPERPOINTCLOUD_H



#import "ADJasperPointCloud.h"

@interface ADMutableJasperPointCloud : ADJasperPointCloud

@property (readonly) int capacity;
@property (readonly) char * mutableBankIds;
@property (readonly) *CGPoint mutableCameraPixels;
@property (readonly) *float mutableConfidences;
@property (readonly) char * mutableEchoIds;
@property (readonly) *float mutableEuclideanDistances;
@property (readonly) *unsigned int mutableFlags;
@property (readonly) *float mutableIntensities;
@property (readonly) *float mutableSignalToNoiseRatios;
@property (readonly) char * mutableSpotIds;
@property (readonly) *CGPoint mutableUndistortedCameraPixels;


-(*id)mutablePoints;
-(id)initWithCapacity:(int)arg0 ;
-(id)initWithCapacity:(int)arg0 storage:(struct __CVBuffer *)arg1 ;
-(void)appendPointsFrom:(id)arg0 ;
-(void)appendPointsFrom:(id)arg0 range:(struct _NSRange )arg1 ;
-(void)applyPerformanceOverrides;
-(void)blacken;
-(void)replacePointsInRange:(struct _NSRange )arg0 withPointsFrom:(id)arg1 range:(struct _NSRange )arg2 ;
-(void)resize:(int)arg0 ;


@end


#endif