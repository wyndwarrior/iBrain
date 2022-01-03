// Headers generated with ktool v0.19.0
// https://github.com/kritantadev/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 15.0.0 | SDK: 15.0.0


#ifndef ADESPRESSOSTILLIMAGEINFERENCEDESCRIPTOR_H
#define ADESPRESSOSTILLIMAGEINFERENCEDESCRIPTOR_H



#import "ADEspressoInferenceDescriptor.h"
#import "ADEspressoImageDescriptor.h"

@interface ADEspressoStillImageInferenceDescriptor : ADEspressoInferenceDescriptor

@property (readonly, nonatomic) ADEspressoImageDescriptor *colorInput; // ivar: _colorInput
@property (readonly, nonatomic) ADEspressoImageDescriptor *depthOutput; // ivar: _depthOutput
@property (readonly, nonatomic) ADEspressoImageDescriptor *jasperInput; // ivar: _jasperInput


-(id)initWithNetworkProvider:(id)arg0 ;


@end


#endif