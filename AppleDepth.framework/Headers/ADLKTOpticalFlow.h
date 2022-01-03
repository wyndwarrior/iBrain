// Headers generated with ktool v0.19.0
// https://github.com/kritantadev/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 15.0.0 | SDK: 15.0.0


#ifndef ADLKTOPTICALFLOW_H
#define ADLKTOPTICALFLOW_H

// Failed to load an ivar with 'NoneType' object is not subscriptable

@class NSObject;
@protocol MTLDevice;



@interface ADLKTOpticalFlow : NSObject {
    int _resX;
    int _resY;
    NSUInteger _nscales;
    unsigned int _nwarpings;
    BOOL _useNonLocalRegularization;
    int _nlreg_radius;
    int _nlreg_padding;
    float _nlreg_sigma_l;
    float _nlreg_sigma_c;
    float _nlreg_sigma_w;
    id<MTLDevice> *_device;
    CGSize _pyramid_size;
    NSUInteger _maxThreadExecutionWidth;
    id<MTLComputePipelineState>" _computePipelines;
    id<MTLTexture>"] _uv_tex;
    id<MTLTexture>"] _uv_u32_alias_tex;
    id<MTLBuffer>" _Adiagb_buf;
    id<MTLBuffer>" _Ixy_buf;
    *__CVBuffer _w_pxbuf;
    id<MTLTexture>" _w_tex;
}




-(BOOL)_createImagePyramidWithCommandBuffer:(id)arg0 inOutPyramidsArray:(id)arg1 error:(*id)arg2 ;
-(BOOL)_createImagePyramidWithCommandBuffer:(id)arg0 in_BGRATex:(id)arg1 outPyramidsArray:(id)arg2 error:(*id)arg3 ;
-(BOOL)_setupBufferAndReturnErrorWithDevice:(id)arg0 error:(*id)arg1 ;
-(NSInteger)encodeOpticalFlowSolverToCommandBuffer:(id)arg0 currentFeaturesArray:(id)arg1 currentDerivitiveArray:(id)arg2 previousFeaturesArray:(id)arg3 previousDerivitiveArray:(id)arg4 currentPyramidsArray:(id)arg5 outShiftMap:(id)arg6 ;
-(NSInteger)encodePyramidFeaturesToCommandBuffer:(id)arg0 colorTexture:(id)arg1 outPyramidsArray:(id)arg2 outFeaturesArray:(id)arg3 outDerivitiveArray:(id)arg4 ;
-(id)initWithDevice:(id)arg0 inputSize:(struct CGSize )arg1 config:(struct ? )arg2 ;
-(id)initWithDevice:(id)arg0 inputSize:(struct CGSize )arg1 scales:(NSUInteger)arg2 ;
-(int)_computeFeaturesDerivativesWithCommandBuffer:(id)arg0 in_tex:(id)arg1 out_tex:(id)arg2 ;
-(int)_computeFeaturesWithCommandBuffer:(id)arg0 in_tex:(id)arg1 out_tex:(id)arg2 ;
-(int)_doSolverWithCommandBuffer:(id)arg0 currentFeatures:(id)arg1 currentDerivitive:(id)arg2 previousFeatures:(id)arg3 previousDerivitive:(id)arg4 scale:(int)arg5 coeff:(id)arg6 in_uv_tex:(id)arg7 out_uv_tex:(id)arg8 out_w_tex;
-(int)_downscale2XWithCommandBuffer:(id)arg0 in_tex:(id)arg1 out_tex:(id)arg2 scaling_factor;
-(void)_doNLRegularizationWithCommandBuffer:(id)arg0 in_uv_tex:(id)arg1 join_tex:(id)arg2 w_tex:(id)arg3 out_uv_tex:(id)arg4 ;
-(void)_setupPipelines;
-(void)_zeroFlowWithCommandBuffer:(id)arg0 uv_tex:(id)arg1 ;
-(void)dealloc;
-(void)setPyramidSizes;
+(struct ? )defaultConfig;
+(struct CGSize )getNextPyramidLevelSize:(struct CGSize )arg0 ;
+(unsigned int)MaxScales;


@end


#endif