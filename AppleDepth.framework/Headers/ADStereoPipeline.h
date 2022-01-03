// Headers generated with ktool v0.19.0
// https://github.com/kritantadev/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 15.0.0 | SDK: 15.0.0


#ifndef ADSTEREOPIPELINE_H
#define ADSTEREOPIPELINE_H

@class NSObject;


#import "ADNetworkProvider.h"
#import "ADEspressoStereoInferenceDescriptor.h"
#import "ADStereoPipelineParameters.h"

@interface ADStereoPipeline : NSObject {
    ADNetworkProvider *_networkProvider;
    ADEspressoStereoInferenceDescriptor *_inferenceDesc;
    NSInteger _prioritization;
}


@property (copy, nonatomic) ADStereoPipelineParameters *pipelineParameters; // ivar: _pipelineParameters
@property (readonly, nonatomic) BOOL shouldPreProcessColorInputs; // ivar: _shouldPreProcessColorInputs
@property (readonly, nonatomic) NSUInteger stereoImagesAlignment; // ivar: _stereoImagesAlignment


-(BOOL)shouldPreProcessColorInputs;
-(NSInteger)adjustForEngine:(NSUInteger)arg0 ;
-(NSInteger)preProcessColorInput:(struct __CVBuffer *)arg0 toBuffer:(struct __CVBuffer *)arg1 ;
-(id)inferenceDescriptor;
-(id)initWithInputAlignment:(NSUInteger)arg0 andPrioritization:(NSInteger)arg1 ;
-(id)initWithInputAlignment:(NSUInteger)arg0 prioritization:(NSInteger)arg1 andParameters:(id)arg2 ;


@end


#endif