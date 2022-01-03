// Headers generated with ktool v0.19.0
// https://github.com/kritantadev/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 15.0.0 | SDK: 15.0.0


#ifndef ADLKTTEXTURESDESCRIPTOR_H
#define ADLKTTEXTURESDESCRIPTOR_H

@class NSObject, NSArray;


#import "ADImageDescriptor.h"

@interface ADLKTTexturesDescriptor : NSObject

@property (readonly, nonatomic) NSArray *derivitivesDescriptors; // ivar: _derivitivesDescriptors
@property (readonly, nonatomic) NSArray *featuresDescriptors; // ivar: _featuresDescriptors
@property (readonly, nonatomic) ADImageDescriptor *inputDescriptor; // ivar: _inputDescriptor
@property (readonly, nonatomic) ? opticalFlowConfig; // ivar: _opticalFlowConfig
@property (readonly, nonatomic) NSArray *pyramidsDescriptors; // ivar: _pyramidsDescriptors
@property (readonly, nonatomic) NSUInteger scales; // ivar: _scales
@property (readonly, nonatomic) ADImageDescriptor *shiftmapDescriptor; // ivar: _shiftmapDescriptor


-(id)initForSupportedSizes:(id)arg0 config:(struct ? )arg1 ;
-(struct CGSize )inputSizeForLayout:(NSUInteger)arg0 ;


@end


#endif