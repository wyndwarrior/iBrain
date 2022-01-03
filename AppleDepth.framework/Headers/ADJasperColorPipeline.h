// Headers generated with ktool v0.19.0
// https://github.com/kritantadev/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 15.0.0 | SDK: 15.0.0


#ifndef ADJASPERCOLORPIPELINE_H
#define ADJASPERCOLORPIPELINE_H

@class NSObject;


#import "ADNetworkProvider.h"
#import "ADEspressoJasperColorInferenceDescriptor.h"
#import "ADImageDescriptor.h"
#import "ADReprojection.h"
#import "ADJasperColorPipelineParameters.h"

@interface ADJasperColorPipeline : NSObject {
    NSInteger _prioritization;
    ADNetworkProvider *_networkProvider;
    ADEspressoJasperColorInferenceDescriptor *_inferenceDesc;
    ADImageDescriptor *_processedDepthDesc;
    ADImageDescriptor *_processedConfDesc;
    ADImageDescriptor *_processedNormalsDesc;
    BOOL _isDenseDepthInverse;
    ADReprojection *_depthReprojector;
}


@property (copy, nonatomic) ADJasperColorPipelineParameters *pipelineParameters; // ivar: _pipelineParameters


-(NSInteger)fuseCurrentDepth:(struct __CVBuffer *)arg0 previousDepth:(struct __CVBuffer *)arg1 intoOutputDepth:(struct __CVBuffer *)arg2 currentConfidence:(struct __CVBuffer *)arg3 previousConfidence:(struct __CVBuffer *)arg4 intoOutputConfidence:(struct __CVBuffer *)arg5 currentNormals:(struct __CVBuffer *)arg6 previousNormals:(struct __CVBuffer *)arg7 intoOutputNormals:(struct __CVBuffer *)arg8 usingAlpha:(struct __CVBuffer *)arg9 ;
-(NSInteger)postProcessConfidence:(struct __CVBuffer *)arg0 confidenceOutput:(struct __CVBuffer *)arg1 confidenceUnits:(NSUInteger)arg2 ;
-(NSInteger)postProcessConfidence:(struct __CVBuffer *)arg0 confidenceOutput:(struct __CVBuffer *)arg1 confidenceUnits:(NSUInteger)arg2 depthUnits:(NSUInteger)arg3 ;
-(NSInteger)postProcessDepth:(struct __CVBuffer *)arg0 depthOutput:(struct __CVBuffer *)arg1 depthUnits:(NSUInteger)arg2 ;
-(NSInteger)postProcessWithDepth:(struct __CVBuffer *)arg0 confidence:(struct __CVBuffer *)arg1 depthOutput:(struct __CVBuffer *)arg2 confidenceOutput:(struct __CVBuffer *)arg3 ;
-(NSInteger)postProcessWithDepth:(struct __CVBuffer *)arg0 confidence:(struct __CVBuffer *)arg1 normals:(struct __CVBuffer *)arg2 depthOutput:(struct __CVBuffer *)arg3 confidenceOutput:(struct __CVBuffer *)arg4 normalsOutput:(struct __CVBuffer *)arg5 normalsRequiredRotation:(NSInteger)arg6 ;
-(NSInteger)projectJasperPoints:(id)arg0 cropTo:(struct CGRect )arg1 rotateBy:(NSInteger)arg2 projectedPointsBuffer:(struct __CVBuffer *)arg3 ;
-(NSInteger)warpAndFuseWithCurrDepth:(struct __CVBuffer *)arg0 prevDepth:(struct __CVBuffer *)arg1 currNormals:(struct __CVBuffer *)arg2 prevNormals:(struct __CVBuffer *)arg3 opticalFlow:(struct __CVBuffer *)arg4 alphaMap:(struct __CVBuffer *)arg5 depthOutput:(struct __CVBuffer *)arg6 normalsOutput:(struct __CVBuffer *)arg7 ;
-(NSInteger)warpAndFuseWithCurrDepth:(struct __CVBuffer *)arg0 prevDepth:(struct __CVBuffer *)arg1 opticalFlow:(struct __CVBuffer *)arg2 alphaMap:(struct __CVBuffer *)arg3 depthOutput:(struct __CVBuffer *)arg4 ;
-(NSInteger)warpPreviousDepth:(struct __CVBuffer *)arg0 intoCurrentDepth:(struct __CVBuffer *)arg1 previousConfidence:(struct __CVBuffer *)arg2 intoCurrentConfidence:(struct __CVBuffer *)arg3 previousNormals:(struct __CVBuffer *)arg4 intoCurrentNormals:(struct __CVBuffer *)arg5 usingOpticalFlow:(struct __CVBuffer *)arg6 ;
-(NSInteger)warpPreviousDepth:(struct __CVBuffer *)arg0 intoCurrentDepth:(struct __CVBuffer *)arg1 previousConfidence:(struct __CVBuffer *)arg2 intoCurrentConfidence:(struct __CVBuffer *)arg3 previousNormals:(struct __CVBuffer *)arg4 intoCurrentNormals:(struct __CVBuffer *)arg5 usingPoseDelta:(struct ? )arg6 previousCalibration:(id)arg7 currentCalibration:(id)arg8 ;
-(id)LKTTexturesDescriptor;
-(id)inferenceDescriptor;
-(id)initWithInputPrioritization:(NSInteger)arg0 ;
-(id)initWithInputPrioritization:(NSInteger)arg0 andParameters:(id)arg1 ;
-(id)processedConfidenceOutputDescriptor;
-(id)processedDepthOutputDescriptor;
-(id)processedNormalsOutputDescriptor;


@end


#endif