// Headers generated with ktool v0.19.0
// https://github.com/kritantadev/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 15.0.0 | SDK: 15.0.0


#ifndef ADEXECUTOR_H
#define ADEXECUTOR_H

@class NSObject, NSString;


#import "ADEspressoWrapper.h"

@interface ADExecutor : NSObject {
    CGRect _inputRoi;
    NSUInteger _layout;
    unsigned int _inputOrientation;
    NSUInteger _engineType;
    ADEspressoWrapper *_espressoRunner;
    NSUInteger _rotationPreference;
    NSInteger _rotationConstant;
}


@property (readonly, copy, nonatomic) NSString *networkVersionString;


-(NSInteger)convertIntrinsicsFrom:(struct __CVBuffer *)arg0 cropBy:(struct CGRect )arg1 to:(struct __CVBuffer *)arg2 ;
-(NSInteger)numberOfExecutionSteps;
-(NSInteger)prepareForEngineType:(NSUInteger)arg0 roi:(struct CGRect )arg1 descriptorForROI:(id)arg2 exifOrientation:(unsigned int)arg3 rotationPreference:(NSUInteger)arg4 inferenceDescriptor:(id)arg5 ;
-(NSInteger)solveRotationPreference:(NSUInteger)arg0 ;
-(id)getIntermediateWithName:(id)arg0 ;
-(id)getIntermediates;
-(id)init;


@end


#endif