// Headers generated with ktool v0.19.0
// https://github.com/kritantadev/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 15.0.0 | SDK: 15.0.0


#ifndef ADESPRESSOSTEREOINFERENCEDESCRIPTOR_H
#define ADESPRESSOSTEREOINFERENCEDESCRIPTOR_H



#import "ADEspressoInferenceDescriptor.h"
#import "ADEspressoImageDescriptor.h"

@interface ADEspressoStereoInferenceDescriptor : ADEspressoInferenceDescriptor

@property (readonly, nonatomic) ADEspressoImageDescriptor *auxiliaryInput; // ivar: _auxiliaryInput
@property (readonly, nonatomic) ADEspressoImageDescriptor *auxiliaryNoiseSigmaInput; // ivar: _auxiliaryNoiseSigmaInput
@property (readonly, nonatomic) ADEspressoImageDescriptor *disparityOutput; // ivar: _disparityOutput
@property (readonly, nonatomic) ADEspressoImageDescriptor *referenceInput; // ivar: _referenceInput
@property (readonly, nonatomic) ADEspressoImageDescriptor *referenceNoiseSigmaInput; // ivar: _referenceNoiseSigmaInput


-(id)initWithNetworkProvider:(id)arg0 inputColorFormat:(unsigned int)arg1 outputDisparityFormat:(unsigned int)arg2 ;


@end


#endif