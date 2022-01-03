// Headers generated with ktool v0.19.0
// https://github.com/kritantadev/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 15.0.0 | SDK: 15.0.0


#ifndef ADUTILS_H
#define ADUTILS_H

@class NSObject;



@interface ADUtils : NSObject



+(NSInteger)ADReturnFromOSStatus:(int)arg0 ;
+(NSInteger)convertToLevelsConfidence:(struct __CVBuffer *)arg0 confidenceOutput:(struct __CVBuffer *)arg1 confidenceLowThreshold:(float)arg2 confidenceHighThreshold:(float)arg3 inverseThresholds:(BOOL)arg4 zeroEdgesThick:(int)arg5 ;
+(NSInteger)copyModifyNormalsPixelBuffer:(struct __CVBuffer *)arg0 output:(struct __CVBuffer *)arg1 normalsRotation:(NSInteger)arg2 ;
+(NSInteger)filterInvalidsFromFloatImage:(struct __CVBuffer *)arg0 minValue:(float)arg1 maxValue:(float)arg2 ;
+(NSInteger)filterInvalidsFromFloatImage:(struct __CVBuffer *)arg0 minValue:(float)arg1 maxValue:(float)arg2 clampToMinMax:(BOOL)arg3 ;
+(NSInteger)fuseCurrentDepth:(struct __CVBuffer *)arg0 previousDepth:(struct __CVBuffer *)arg1 intoOutputDepth:(struct __CVBuffer *)arg2 currentConfidence:(struct __CVBuffer *)arg3 previousConfidence:(struct __CVBuffer *)arg4 intoOutputConfidence:(struct __CVBuffer *)arg5 currentNormals:(struct __CVBuffer *)arg6 previousNormals:(struct __CVBuffer *)arg7 intoOutputNormals:(struct __CVBuffer *)arg8 usingAlpha:(struct __CVBuffer *)arg9 defaultAlpha:(float)arg10 depthUnits:(NSUInteger)arg11 confidenceUnits:(NSUInteger)arg12 ;
+(NSInteger)fuseCurrentDepthAndConfidenceMaps:(struct __CVBuffer *)arg0 previousDepth:(struct __CVBuffer *)arg1 currentConfidence:(struct __CVBuffer *)arg2 previousConfidence:(struct __CVBuffer *)arg3 outputDepth:(struct __CVBuffer *)arg4 outputConfidence:(struct __CVBuffer *)arg5 defaultAlpha:(float)arg6 depthMaxDiff:(float)arg7 ;
+(NSInteger)fuseCurrentMap:(struct __CVBuffer *)arg0 previousMap:(struct __CVBuffer *)arg1 intoOutputMap:(struct __CVBuffer *)arg2 usingAlpha:(struct __CVBuffer *)arg3 defaultAlpha:(float)arg4 diffThreshold:(float)arg5 ;
+(NSInteger)postProcessConfidence:(struct __CVBuffer *)arg0 confidenceOutput:(struct __CVBuffer *)arg1 rawConfidenceUnits:(NSUInteger)arg2 outConfidenceUnits:(NSUInteger)arg3 outDepthUnits:(NSUInteger)arg4 confidenceLowThreshold:(float)arg5 confidenceHighThreshold:(float)arg6 ;
+(NSInteger)postProcessDepth:(struct __CVBuffer *)arg0 depthOutput:(struct __CVBuffer *)arg1 depthUnitsType:(NSUInteger)arg2 inverse:(BOOL)arg3 ;
+(NSInteger)postProcessNormals:(struct __CVBuffer *)arg0 normalsOutput:(struct __CVBuffer *)arg1 normalsRotation:(NSInteger)arg2 ;
+(NSInteger)postProcessWithDepth:(struct __CVBuffer *)arg0 confidence:(struct __CVBuffer *)arg1 normals:(struct __CVBuffer *)arg2 depthOutput:(struct __CVBuffer *)arg3 confidenceOutput:(struct __CVBuffer *)arg4 normalsOutput:(struct __CVBuffer *)arg5 normalsRotation:(NSInteger)arg6 depthUnitsType:(NSUInteger)arg7 inverse:(BOOL)arg8 rawConfidenceUnits:(NSUInteger)arg9 outConfidenceUnits:(NSUInteger)arg10 confidenceLowThreshold:(float)arg11 confidenceHighThreshold:(float)arg12 ;
+(NSInteger)projectPointCloud:(id)arg0 croppedBy:(struct CGRect )arg1 rotatedBy:(NSInteger)arg2 scaledInto:(struct __CVBuffer *)arg3 ;
+(NSInteger)projectPointCloud:(id)arg0 filteredBy:(id)arg1 croppedBy:(struct CGRect )arg2 rotatedBy:(NSInteger)arg3 scaledInto:(struct __CVBuffer *)arg4 ;
+(NSInteger)projectPointCloud:(id)arg0 filteredBy:(id)arg1 croppedBy:(struct CGRect )arg2 rotatedBy:(NSInteger)arg3 scaledMergingWith:(struct __CVBuffer *)arg4 ;
+(NSInteger)warpAndFuseWithCurrDepth:(struct __CVBuffer *)arg0 prevDepth:(struct __CVBuffer *)arg1 currNormals:(struct __CVBuffer *)arg2 prevNormals:(struct __CVBuffer *)arg3 opticalFlow:(struct __CVBuffer *)arg4 alphaMap:(struct __CVBuffer *)arg5 depthUnitsType:(NSUInteger)arg6 defaultAlpha:(float)arg7 depthOutput:(struct __CVBuffer *)arg8 normalsOutput:(struct __CVBuffer *)arg9 ;
+(NSInteger)warpMap:(struct __CVBuffer *)arg0 toOutput:(struct __CVBuffer *)arg1 usingOpticalFlow:(struct __CVBuffer *)arg2 ;
+(NSInteger)warpPreviousDepth:(struct __CVBuffer *)arg0 intoCurrentDepth:(struct __CVBuffer *)arg1 previousConfidence:(struct __CVBuffer *)arg2 intoCurrentConfidence:(struct __CVBuffer *)arg3 previousNormals:(struct __CVBuffer *)arg4 intoCurrentNormals:(struct __CVBuffer *)arg5 usingOpticalFlow:(struct __CVBuffer *)arg6 ;
+(id)calcRotationAngle;
+(struct ? )addAnglesToRotation:(struct ? )arg0 angles;
+(struct ? )calcRotationMatrix;
+(void)convertRGBAFloat:(struct __CVBuffer *)arg0 toPlanar:(struct __CVBuffer *)arg1 ;


@end


#endif