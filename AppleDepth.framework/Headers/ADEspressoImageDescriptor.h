// Headers generated with ktool v0.19.0
// https://github.com/kritantadev/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 15.0.0 | SDK: 15.0.0


#ifndef ADESPRESSOIMAGEDESCRIPTOR_H
#define ADESPRESSOIMAGEDESCRIPTOR_H

@class NSObject, NSString;


#import "ADImageDescriptor.h"

@interface ADEspressoImageDescriptor : NSObject

@property (readonly, nonatomic) ADImageDescriptor *imageDescriptor; // ivar: _imageDescriptor
@property (readonly, nonatomic) BOOL isInput; // ivar: _isInput
@property (readonly, nonatomic) NSString *name; // ivar: _name


-(BOOL)isInput;
+(id)descriptorWithName:(id)arg0 imageDescriptor:(id)arg1 isInput:(BOOL)arg2 ;


@end


#endif