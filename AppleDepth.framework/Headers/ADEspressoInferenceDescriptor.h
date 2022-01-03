// Headers generated with ktool v0.19.0
// https://github.com/kritantadev/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 15.0.0 | SDK: 15.0.0


#ifndef ADESPRESSOINFERENCEDESCRIPTOR_H
#define ADESPRESSOINFERENCEDESCRIPTOR_H

@class NSObject, NSDictionary, NSURL;



@interface ADEspressoInferenceDescriptor : NSObject {
    NSDictionary *_layoutNames;
}


@property (readonly, nonatomic) NSURL *networkURL; // ivar: _networkURL


-(id)configurationNameForLayout:(NSUInteger)arg0 ;
-(id)initWithUrl:(id)arg0 layoutNames:(id)arg1 ;


@end


#endif