/**
  ******************************************************************************
  * \file tardigrade_stress_tools.h
  ******************************************************************************
  * A collection of tools which implement and solve stress-strain relationships
  * in such a way to enable more rapid development of constitutive models which
  * have capabilities which may not be contained within a collection of
  * of constitutive models.
  ******************************************************************************
  */

#ifndef TARDIGRADE_STRESS_TOOLS_H
#define TARDIGRADE_STRESS_TOOLS_H

#define USE_EIGEN
#include<tardigrade_vector_tools.h>
#include<tardigrade_error_tools.h>
#include<tardigrade_constitutive_tools.h>
#include<linear_elasticity.h>

namespace tardigradeStressTools{

    typedef tardigradeConstitutiveTools::errorNode errorNode; //!< Redefinition for the error node
    typedef tardigradeConstitutiveTools::errorOut errorOut; //!< Redefinition for a pointer to the error node
    typedef tardigradeConstitutiveTools::floatType floatType; //!< Define the float values type.
    typedef tardigradeConstitutiveTools::floatVector floatVector; //!< Define a vector of floats
    typedef tardigradeConstitutiveTools::floatMatrix floatMatrix; //!< Define a matrix of floats

    errorOut calculateMeanStress( const floatVector &stress, floatType &meanStress );

    floatType calculateMeanStress( const floatVector &stress );

    errorOut calculateMeanStress( const floatMatrix &stress, floatType &meanStress );

    floatType calculateMeanStress( const floatMatrix &stress );

    errorOut calculateMeanStress( const floatVector &stress, floatType &meanStress, floatVector &jacobian );

    errorOut calculateDeviatoricStress( const floatVector &stress, floatVector &deviatoric );

    errorOut calculateDeviatoricStress( const floatVector &stress, floatVector &deviatoric, floatMatrix &jacobian );

    errorOut calculateDeviatoricStress( const floatVector &stress, floatVector &deviatoric, floatMatrix &jacobian );

    floatVector calculateDeviatoricStress( const floatVector &stress );

    floatVector calculateDeviatoricStress( const floatVector &stress, floatMatrix &jacobian );

    errorOut calculateVonMisesStress( const floatVector &stress, floatType &vonMises );

    floatType calculateVonMisesStress( const floatVector &stress );

    errorOut calculateVonMisesStress( const floatVector &stress, floatType &vonMises, floatVector &jacobian );

    errorOut druckerPragerSurface( const floatType &vonMises, const floatType &meanStress, const floatType &A, const floatType &B, floatType &dpYield );

    errorOut druckerPragerSurface( const floatType &vonMises, const floatType &meanStress, const floatVector &dpParam, floatType &dpYield );

    floatType druckerPragerSurface( const floatType &vonMises, const floatType &meanStress, const floatType &A, const floatType &B );

    floatType druckerPragerSurface( const floatType &vonMises, const floatType &meanStress, const floatVector &dpParam );

    errorOut druckerPragerSurface( const floatVector &stress, const floatType &A, const floatType &B, floatType &dpYield );

    errorOut druckerPragerSurface( const floatVector &stress, const floatVector &dpParam, floatType &dpYield );

    floatType druckerPragerSurface( const floatVector &stress, const floatType &A, const floatType &B );

    floatType druckerPragerSurface( const floatVector &stress, const floatVector &dpParam );

    errorOut druckerPragerSurface( const floatVector &stress, const floatType &A, const floatType &B, floatType &dpYield, floatVector &jacobian );

    errorOut druckerPragerSurface( const floatVector &stress, const floatVector &dpParam, floatType &dpYield, floatVector &jacobian );

    errorOut druckerPragerSurface( const floatVector &stress, const floatType &A, const floatType &B, floatType &dpYield, floatVector &jacobian, floatMatrix &djacobiandstress );

    errorOut druckerPragerSurface( const floatVector &stress, const floatVector &dpParam, floatType &dpYield, floatVector &jacobian, floatMatrix &djacobiandstress );

    errorOut druckerPragerSurface( const floatVector &stress, const floatType &A, const floatType &B, floatType &dpYield, floatVector &jacobian, floatVector &unitDirection );

    errorOut druckerPragerSurface( const floatVector &stress, const floatVector &dpParam, floatType &dpYield, floatVector &jacobian, floatVector &unitDirection );

    errorOut druckerPragerSurface( const floatVector &stress, const floatType &A, const floatType &B, floatType &dpYield, floatVector &jacobian, floatVector &unitDirection, floatMatrix &unitDirectionJacobian );

    errorOut druckerPragerSurface( const floatVector &stress, const floatVector &dpParam, floatType &dpYield, floatVector &jacobian, floatVector &unitDirection, floatMatrix &unitDirectionJacobian );

//    errorOut linearViscoelasticity( const floatType &currentTime, const floatType &currentStrain,
//                                   const floatType &previousTime, const floatType &previousStrain,
//                                   const floatType &currentRateModifier, const floatType &previousRateModifier,
//                                   const floatVector &previousStateVariables, const floatVector &materialParameters,
//                                   const floatType &alpha,
//                                   floatVector &stress, floatVector &currentStateVariables );
//
//    errorOut linearViscoelasticity( const floatType &currentTime, const floatType &currentStrain,
//                                   const floatType &previousTime, const floatType &previousStrain,
//                                   const floatType &currentRateModifier, const floatType &previousRateModifier,
//                                   const floatVector &previousStateVariables, const floatVector &materialParameters,
//                                   const floatType &alpha,
//                                   floatVector &stress, floatVector &currentStateVariables, floatMatrix &dstressdstrain,
//                                   floatVector &dstressdrateModifier );

    errorOut linearViscoelasticity( const floatType &currentTime, const floatVector &currentStrain,
                                   const floatType &previousTime, const floatVector &previousStrain,
                                   const floatType &currentRateModifier, const floatType &previousRateModifier,
                                   const floatVector &previousStateVariables, const floatVector &materialParameters,
                                   const floatType &alpha,
                                   floatVector &stress, floatVector &currentStateVariables );

    errorOut linearViscoelasticity( const floatType &currentTime, const floatVector &currentStrain,
                                   const floatType &previousTime, const floatVector &previousStrain,
                                   const floatType &currentRateModifier, const floatType &previousRateModifier,
                                   const floatVector &previousStateVariables, const floatVector &materialParameters,
                                   const floatType &alpha,
                                   floatVector &stress, floatVector &currentStateVariables,
                                   floatMatrix &dstressdstrain, floatVector &dstressdrateModifier );

    errorOut linearViscoelasticity( const floatType &currentTime, const floatVector &currentStrain,
                                   const floatType &previousTime, const floatVector &previousStrain,
                                   const floatType &currentRateModifier, const floatType &previousRateModifier,
                                   const floatVector &previousStateVariables, const floatVector &materialParameters,
                                   const floatType &alpha,
                                   floatVector &stress, floatVector &currentStateVariables,
                                   floatMatrix &dstressdstrain, floatVector &dstressdrateModifier,
                                   floatMatrix &dstressdPreviousStrain, floatVector &dstressdPreviousRateModifier,
                                   floatMatrix &dstressdPreviousStateVariables,
                                   floatMatrix &dStateVariablesdStrain, floatVector &dStateVariablesdRateModifier,
                                   floatMatrix &dStateVariablesdPreviousStrain, floatVector &dStateVariablesdPreviousRateModifier,
                                   floatMatrix &dStateVariablesdPreviousStateVariables );

    errorOut linearViscoelasticity( const floatType &currentTime, const floatVector &currentStrain,
                                   const floatType &previousTime, const floatVector &previousStrain,
                                   const floatType &currentRateModifier, const floatType &previousRateModifier,
                                   const floatVector &previousStateVariables, const floatVector &materialParameters,
                                   const floatType &alpha,
                                   floatVector &dStress, floatVector &stress, floatVector &currentStateVariables );

    errorOut linearViscoelasticity( const floatType &currentTime, const floatVector &currentStrain,
                                   const floatType &previousTime, const floatVector &previousStrain,
                                   const floatType &currentRateModifier, const floatType &previousRateModifier,
                                   const floatVector &previousStateVariables, const floatVector &materialParameters,
                                   const floatType &alpha,
                                   floatVector &dStress, floatVector &stress, floatVector &currentStateVariables,
                                   floatMatrix &dstressdstrain, floatVector &dstressdrateModifier );

    errorOut linearViscoelasticity( const floatType &currentTime, const floatVector &currentStrain,
                                   const floatType &previousTime, const floatVector &previousStrain,
                                   const floatType &currentRateModifier, const floatType &previousRateModifier,
                                   const floatVector &previousStateVariables, const floatVector &materialParameters,
                                   const floatType &alpha,
                                   floatVector &dStress, floatVector &stress, floatVector &currentStateVariables,
                                   floatMatrix &dstressdstrain, floatVector &dstressdrateModifier,
                                   floatMatrix &dstressdPreviousStrain, floatVector &dstressdPreviousRateModifier,
                                   floatMatrix &dstressdPreviousStateVariables,
                                   floatMatrix &dStateVariablesdStrain, floatVector &dStateVariablesdRateModifier,
                                   floatMatrix &dStateVariablesdPreviousStrain, floatVector &dStateVariablesdPreviousRateModifier,
                                   floatMatrix &dStateVariablesdPreviousStateVariables );

    errorOut volumetricNeoHookean( const floatType &jacobian, const floatType &bulkModulus,
                                  floatType &meanStress );

    errorOut volumetricNeoHookean( const floatType &jacobian, const floatType &bulkModulus,
                                  floatType &meanStress, floatType &dmeanStressdJ );

    errorOut volumetricNeoHookean( const floatVector &deformationGradient, const floatType &bulkModulus,
                                  floatType &meanStress );

    errorOut volumetricNeoHookean( const floatVector &deformationGradient, const floatType &bulkModulus,
                                  floatType &meanStress, floatType &dmeanStressdJ );

    errorOut peryznaModel( const floatType f, const floatType q, const floatType A, const floatType n, floatType &p );

    errorOut peryznaModel( const floatType f, const floatType q, const floatType A, const floatVector &parameters, floatType &p );

    errorOut peryznaModel( const floatType f, const floatType q, const floatType A, const floatType n, floatType &p,
                          floatType &dpdf, floatType &dpdq, floatType &dpdA );

    errorOut peryznaModel( const floatType f, const floatType q, const floatType A, const floatVector &parameters, floatType &p,
                          floatType &dpdf, floatType &dpdq, floatType &dpdA );

    errorOut linearHardening( const floatVector &stateVariables, const floatVector &linearModuli, const floatType &scalarShift,
                             floatType &value );

    errorOut linearHardening( const floatVector &stateVariables, const floatVector &linearModuli, const floatType &scalarShift,
                             floatType &value, floatVector &valueJacobian );

    errorOut computeJaumannStiffnessTensor( const floatVector &cauchyStress, const floatVector &currentDeformationGradient,
                                            const floatMatrix &dCauchydF, floatMatrix &C );
}

#endif
