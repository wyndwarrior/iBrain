// Headers generated with ktool v0.19.0
// https://github.com/kritantadev/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 15.0.0 | SDK: 15.0.0


#ifndef ADDEVICECONFIGURATION_H
#define ADDEVICECONFIGURATION_H

@class NSObject, NSUserDefaults, NSMutableDictionary;



@interface ADDeviceConfiguration : NSObject {
    NSUserDefaults *_globalUserDefaults;
    NSUserDefaults *_appleDepthUserDefaults;
    NSMutableDictionary *_currentDefaults;
}




-(BOOL)createPropertyForKey:(id)arg0 ;
-(id)init;
-(void)dealloc;
-(void)observeValueForKeyPath:(id)arg0 ofObject:(id)arg1 change:(id)arg2 context:(*void)arg3 ;
-(void)updateValue:(id)arg0 forKey:(id)arg1 ;
+(BOOL)boolForKey:(id)arg0 ;
+(CGFloat)doubleForKey:(id)arg0 ;
+(NSInteger)integerForKey:(id)arg0 ;
+(float)floatForKey:(id)arg0 ;
+(id)getDefaultConfiguration;
+(id)listForKey:(id)arg0 ;
+(id)numberForKey:(id)arg0 ;
+(id)sharedConfiguration;
+(id)stringForKey:(id)arg0 ;


@end


#endif