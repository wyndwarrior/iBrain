// Headers generated with ktool v0.19.0
// https://github.com/kritantadev/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 15.0.0 | SDK: 15.0.0


#ifndef ADESPRESSORUNNER_H
#define ADESPRESSORUNNER_H

// Failed to load a method with 'NoneType' object is not subscriptable

@class NSObject;



@interface ADEspressoRunner : NSObject {
    *void _ctx;
    *void _plan;
    ? _net;
    int _engineType;
    int _storageType;
    unordered_map<std::string, PixelBufferSharedPtr, std::hash<std::string>, std::equal_to<std::string>, std::allocator<std::pair<const std::string, PixelBufferSharedPtr>>> _pixelBuffersToBindAsVImage;
    unordered_map<std::string, PixelBufferSharedPtr, std::hash<std::string>, std::equal_to<std::string>, std::allocator<std::pair<const std::string, PixelBufferSharedPtr>>> _pixelBuffersToBindDirect;
    unordered_map<std::string, PixelBufferSharedPtr, std::hash<std::string>, std::equal_to<std::string>, std::allocator<std::pair<const std::string, PixelBufferSharedPtr>>> _pixelBuffersToBindIndirect;
    unordered_map<std::string, PixelBufferSharedPtr, std::hash<std::string>, std::equal_to<std::string>, std::allocator<std::pair<const std::string, PixelBufferSharedPtr>>> _pixelBuffersToBindAsEspressoBufferInput;
    unordered_map<std::string, PixelBufferSharedPtr, std::hash<std::string>, std::equal_to<std::string>, std::allocator<std::pair<const std::string, PixelBufferSharedPtr>>> _pixelBuffersToBindAsEspressoBufferOutput;
    BOOL _CPUBindWA;
}




-(BOOL)isCVPixelBufferBindingSupportedForFormat:(unsigned int)arg0 ;
-(BOOL)isDirectBindingSupportedForFormat:(unsigned int)arg0 ;
-(BOOL)isVImageBindingSupportedForFormat:(unsigned int)arg0 ;
-(NSInteger)execute;
-(NSInteger)registerPixelBuffer:(struct __CVBuffer *)arg0 forDescriptor:(id)arg1 ;
-(id)initWithPath:(id)arg0 forEngine:(NSUInteger)arg1 configurationName:(id)arg2 ;
-(id)networkVersionString;
-(id)registerDescriptor:(id)arg0 ;
-(int)bindPixelBufferAsVImage:(struct __CVBuffer *)arg0 toBlob:(char *)arg1 ;
-(struct __CVBuffer *)createAndRegisterPixelBufferForDescriptor:(id)arg0 ;
-(void)dealloc;
-(void)unlockAllVImageBindBuffers;


@end


#endif