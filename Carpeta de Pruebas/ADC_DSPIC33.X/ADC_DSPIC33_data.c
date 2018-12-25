/*
 * -------------------------------------------------------------------
 * MPLAB 16-Bit Device Blocks for Simulink v3.38.
 *
 *   Product Page:  http://www.microchip.com/SimulinkBlocks
 *           Forum: http://www.microchip.com/forums/f192.aspx
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: ADC_DSPIC33_data.c
 *
 * Code generated for Simulink model 'ADC_DSPIC33'.
 *
 * Model version                  : 1.202
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Sun Nov 18 19:15:44 2018
 */

#include "ADC_DSPIC33.h"
#include "ADC_DSPIC33_private.h"

/* Invariant block signals (auto storage) */
const ConstB_ADC_DSPIC33_T ADC_DSPIC33_ConstB = {
  2U
  ,                                    /* '<Root>/Data Type Conversion9' */
  1U
  ,                                    /* '<Root>/Data Type Conversion5' */
  4U
  /* '<Root>/Data Type Conversion11' */
};

/* Constant parameters (auto storage) */
const ConstP_ADC_DSPIC33_T ADC_DSPIC33_ConstP = {
  /* Computed Parameter: FIR10_Coefficients
   * Referenced by: '<Root>/FIR10'
   */
  { 0.0569319092F, 0.0646082237F, 0.0710563F, 0.0759315863F, 0.0789686069F,
    0.08F, 0.0789686069F, 0.0759315863F, 0.0710563F, 0.0646082237F,
    0.0569319092F },

  /* Computed Parameter: FIR25_Coefficients
   * Referenced by: '<Root>/FIR25'
   */
  { 2.93238E-18F, 0.00653490052F, 0.0139865214F, 0.0221406184F, 0.0307385363F,
    0.0394880399F, 0.048076272F, 0.0561841615F, 0.0635015517F, 0.0697421879F,
    0.074657768F, 0.0780502707F, 0.079781875F, 0.079781875F, 0.0780502707F,
    0.074657768F, 0.0697421879F, 0.0635015517F, 0.0561841615F, 0.048076272F,
    0.0394880399F, 0.0307385363F, 0.0221406184F, 0.0139865214F, 0.00653490052F,
    2.93238E-18F },

  /* Pooled Parameter (Expression: [-0.01423297720420574 -0.015817959399409564 -0.016528271678139684 -0.016208243927688132 -0.014739975184467713 -0.012051521623166995 -0.0081230763316393183 -0.0029907383172590989 0.0032524116635554981 0.010458071899141172 0.01842731038110863 0.026917825484855638 0.03565356953724233 0.044336295104620511 0.05265847282390991 0.060316947197958951 0.067026647996413058 0.072533662871220136 0.076627002551852536 0.079148452405864642 0.080000000000000002 0.079148452405864642 0.076627002551852536 0.072533662871220136 0.067026647996413058 0.060316947197958951 0.05265847282390991 0.044336295104620511 0.03565356953724233 0.026917825484855638 0.01842731038110863 0.010458071899141172 0.0032524116635554981 -0.0029907383172590989 -0.0081230763316393183 -0.012051521623166995 -0.014739975184467713 -0.016208243927688132 -0.016528271678139684 -0.015817959399409564 -0.01423297720420574])
   * Referenced by:
   *   '<Root>/FIR1'
   *   '<Root>/FIR40'
   */
  { -0.0142329773F, -0.0158179589F, -0.0165282711F, -0.0162082445F,
    -0.0147399753F, -0.0120515218F, -0.00812307652F, -0.00299073826F,
    0.00325241173F, 0.0104580717F, 0.0184273105F, 0.0269178264F, 0.0356535688F,
    0.0443362966F, 0.0526584722F, 0.0603169464F, 0.0670266449F, 0.0725336596F,
    0.076627F, 0.079148449F, 0.08F, 0.079148449F, 0.076627F, 0.0725336596F,
    0.0670266449F, 0.0603169464F, 0.0526584722F, 0.0443362966F, 0.0356535688F,
    0.0269178264F, 0.0184273105F, 0.0104580717F, 0.00325241173F, -0.00299073826F,
    -0.00812307652F, -0.0120515218F, -0.0147399753F, -0.0162082445F,
    -0.0165282711F, -0.0158179589F, -0.0142329773F }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
