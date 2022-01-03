// Headers generated with ktool v0.19.0
// https://github.com/kritantadev/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 15.0.0 | SDK: 15.0.0


#ifndef ADPCEDISPARITYCOLORPIPELINE_H
#define ADPCEDISPARITYCOLORPIPELINE_H

@class NSObject;
@protocol MTLDevice;


#import "ADNetworkProvider.h"
#import "ADEspressoPCEDisparityColorInferenceDescriptor.h"
#import "ADPCEDisparityColorPipelineParameters.h"

@interface ADPCEDisparityColorPipeline : NSObject {
    ADNetworkProvider *_networkProvider;
    ADEspressoPCEDisparityColorInferenceDescriptor *_inferenceDesc;
    id<MTLDevice> *_metalDevice;
    id<MTLComputePipelineState>" _preprocessPipelineForRawPCE;
    id<MTLComputePipelineState>" _preprocessPipelineForFloatPCE;
}


@property (copy, nonatomic) ADPCEDisparityColorPipelineParameters *pipelineParameters; // ivar: _pipelineParameters


-(NSInteger)adjustForEngine:(NSUInteger)arg0 ;
-(NSInteger)encodeDisparityPreprocessingToCommandBuffer:(id)arg0 input:(id)arg1 normalizationMultiplier:(float)arg2 normalizationOffset:(float)arg3 invalidValue:(unsigned short)arg4 rotation:(NSInteger)arg5 output:(id)arg6 ;
-(NSInteger)postProcessDisparity:(struct __CVBuffer *)arg0 output:(struct __CVBuffer *)arg1 ;
-(NSInteger)rebuildMetalPreprocessingKernels;
-(id)inferenceDescriptor;
-(id)init;
-(id)initForInputSource:(NSUInteger)arg0 ;
-(id)initForInputSource:(NSUInteger)arg0 metalDevice:(id)arg1 ;
-(id)initWithParameters:(id)arg0 ;
-(id)initWithParameters:(id)arg0 inputSource:(NSUInteger)arg1 ;
-(id)initWithParameters:(id)arg0 inputSource:(NSUInteger)arg1 metalDevice:(id)arg2 ;


@end


#endif