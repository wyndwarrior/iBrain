// Headers generated with ktool v0.19.0
// https://github.com/kritantadev/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 15.0.0 | SDK: 15.0.0


#ifndef ADADAPTIVECORRECTIONPIPELINEPARAMETERS_H
#define ADADAPTIVECORRECTIONPIPELINEPARAMETERS_H

@class NSObject;



@interface ADAdaptiveCorrectionPipelineParameters : NSObject

@property (nonatomic) CGFloat epErrorLimitWidePix_FirstPass; // ivar: _epErrorLimitWidePix_FirstPass
@property (nonatomic) CGFloat epErrorLimitWidePix_SecondPass; // ivar: _epErrorLimitWidePix_SecondPass
@property (nonatomic) CGFloat errorVal_BetweenIntermediate_ExtremeMacro; // ivar: _errorVal_BetweenIntermediate_ExtremeMacro
@property (nonatomic) CGFloat errorVal_GreaterThanInf; // ivar: _errorVal_GreaterThanInf
@property (nonatomic) CGFloat errorVal_LessThanExtremeMacro; // ivar: _errorVal_LessThanExtremeMacro
@property (nonatomic) CGFloat extremeMacroDistMM; // ivar: _extremeMacroDistMM
@property (nonatomic) CGFloat intermediateMacroDistMM; // ivar: _intermediateMacroDistMM
@property (nonatomic) int minPointsForAdjustment; // ivar: _minPointsForAdjustment
@property (nonatomic) CGFloat rangeOCxT; // ivar: _rangeOCxT
@property (nonatomic) CGFloat rangeOCxW; // ivar: _rangeOCxW
@property (nonatomic) CGFloat rangeOCyW; // ivar: _rangeOCyW
@property (nonatomic) CGFloat rangePFL_T; // ivar: _rangePFL_T
@property (nonatomic) CGFloat rangePFL_W; // ivar: _rangePFL_W
@property (nonatomic) BOOL runAnalyticalPreconditioning; // ivar: _runAnalyticalPreconditioning
@property (nonatomic) CGFloat spgEpsilon; // ivar: _spgEpsilon
@property (nonatomic) float temporalFilteringStrength; // ivar: _temporalFilteringStrength


-(BOOL)runAnalyticalPreconditioning;


@end


#endif