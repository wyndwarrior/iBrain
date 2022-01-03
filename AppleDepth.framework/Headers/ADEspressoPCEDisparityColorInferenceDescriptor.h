// Headers generated with ktool v0.19.0
// https://github.com/kritantadev/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 15.0.0 | SDK: 15.0.0


#ifndef ADESPRESSOPCEDISPARITYCOLORINFERENCEDESCRIPTOR_H
#define ADESPRESSOPCEDISPARITYCOLORINFERENCEDESCRIPTOR_H



#import "ADEspressoInferenceDescriptor.h"
#import "ADEspressoImageDescriptor.h"

@interface ADEspressoPCEDisparityColorInferenceDescriptor : ADEspressoInferenceDescriptor

@property (readonly, nonatomic) ADEspressoImageDescriptor *colorInput; // ivar: _colorInput
@property (readonly, nonatomic) ADEspressoImageDescriptor *disparityInput; // ivar: _disparityInput
@property (readonly, nonatomic) ADEspressoImageDescriptor *disparityOutput; // ivar: _disparityOutput
@property (readonly, nonatomic) ADEspressoImageDescriptor *prevDisparityInput; // ivar: _prevDisparityInput


-(id)initWithNetworkProvider:(id)arg0 inputColorFormat:(unsigned int)arg1 disparityFormat:(unsigned int)arg2 ;


@end


#endif