// Headers generated with ktool v0.19.0
// https://github.com/kritantadev/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 15.0.0 | SDK: 15.0.0


#ifndef ADJASPERCOLORSTILLSPIPELINE_H
#define ADJASPERCOLORSTILLSPIPELINE_H

// Failed to load an ivar with string index out of range

@class NSObject;


#import "ADNetworkProvider.h"
#import "ADEspressoStillImageInferenceDescriptor.h"
#import "ADEspressoJasperToColorTransformCorrectionBackendInfrerenceDescriptor.h"
#import "ADEspressoJasperToColorTransformCorrectionFrontendInfrerenceDescriptor.h"
#import "ADImageDescriptor.h"
#import "ADJasperColorStillsPipelineParameters.h"

@interface ADJasperColorStillsPipeline : NSObject {
    ADNetworkProvider *_networkProvider;
    ADNetworkProvider *_correctionBackendNetworkProvider;
    ADNetworkProvider *_correctionFrontendNetworkProvider;
    ADEspressoStillImageInferenceDescriptor *_inferenceDesc;
    ADEspressoJasperToColorTransformCorrectionBackendInfrerenceDescriptor *_correctionBackendInferenceDesc;
    ADEspressoJasperToColorTransformCorrectionFrontendInfrerenceDescriptor *_correctionFrontendInferenceDesc;
    ADImageDescriptor *_processedDepthDesc;
    BOOL _isDisparity;
    float _scaledEFL;
    float _STDThreshold;
}


@property (copy, nonatomic) ADJasperColorStillsPipelineParameters *pipelineParameters; // ivar: _pipelineParameters


-(NSInteger)postProcessDepth:(struct __CVBuffer *)arg0 depthOutput:(struct __CVBuffer *)arg1 depthUnits:(NSUInteger)arg2 ;
-(NSInteger)postProcessJasperToColorCorrectionWithAngles:(*float)arg0 errors:(*float)arg1 originalTransform:(struct ? )arg2 correctedTransform:(struct ? *)arg3 colorCameraCalibration:(id)arg4 colorImageScale:(float)arg5 transformCorrectionResults:(*id)arg6 ;
-(NSInteger)postProcessJasperToColorTransformCorrection:(id)arg0 originalTransform:(struct ? )arg1 correctedTransform:(struct ? *)arg2 ;
-(NSInteger)postProcessWithDepth:(struct __CVBuffer *)arg0 depthOutput:(struct __CVBuffer *)arg1 ;
-(NSInteger)processJasperToColorCorrectionIntermediateResultWithBackendEspressoFeaturesOutput:(*float)arg0 frontendEspressoFeaturesInput:(*float)arg1 featuresDimensions:(id)arg2 ;
-(NSInteger)projectJasperPoints:(id)arg0 cropTo:(struct CGRect )arg1 rotateBy:(NSInteger)arg2 projectedPointsBuffer:(struct __CVBuffer *)arg3 ;
-(NSInteger)projectJasperPointsForJasperToColorTransformCorrection:(id)arg0 cropTo:(struct CGRect )arg1 rotateBy:(NSInteger)arg2 projectedPointsBuffer:(struct __CVBuffer *)arg3 ;
-(id)correctionBackendInferenceDescriptor;
-(id)correctionFrontendInferenceDescriptor;
-(id)inferenceDescriptor;
-(id)init;
-(id)initWithParameters:(id)arg0 ;
-(id)processedDepthOutputDescriptor;


@end


#endif