/*
 * -------------------------------------------------------------------
 * MPLAB 16-Bit Device Blocks for Simulink v3.38.
 *
 *   Product Page:  http://www.microchip.com/SimulinkBlocks
 *           Forum: http://www.microchip.com/forums/f192.aspx
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: ADC_DSPIC33.h
 *
 * Code generated for Simulink model 'ADC_DSPIC33'.
 *
 * Model version                  : 1.216
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Dec 18 17:40:23 2018
 */

#ifndef RTW_HEADER_ADC_DSPIC33_h_
#define RTW_HEADER_ADC_DSPIC33_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef ADC_DSPIC33_COMMON_INCLUDES_
# define ADC_DSPIC33_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* ADC_DSPIC33_COMMON_INCLUDES_ */

#include "ADC_DSPIC33_types.h"
#define FCY                            (40000000U)               /* Instruction Frequency FCY set at  40.0 MHz */

/* Include for pic 33F */
#include <p33Fxxxx.h>
#include <libpic30.h>                  /* For possible use with C function Call block (delay_ms or delay_us functions might be used by few peripherals) */
#include <libq.h>                      /* For possible use with C function Call block */
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((void*) 0)
#endif

/* Declare UART1 Tx Circular Buffer Structure */
#define Tx_BUFF_SIZE_Uart1             (64)

typedef struct MCHP_UART1_TxStr{
  volatile uint8_T buffer[Tx_BUFF_SIZE_Uart1];/* Size Rx_BUFF_SIZE_Uart1 is 64 */
  volatile uint_T tail;                /* tail is the index for the next value to be read from the Circular buffer */
  volatile uint_T head;                /* head is the index for the next value to be written into the Circular buffer */
} MCHP_UART1_TxStr;

/* Declare UART1 Rx Circular Buffer Structure */
#define Rx_BUFF_SIZE_Uart1             (1024)

typedef struct MCHP_UART1_RxStr{
  volatile uint8_T buffer[Rx_BUFF_SIZE_Uart1];/* Size Rx_BUFF_SIZE_Uart1 is 1024 */
  volatile uint_T tail;                /* tail is the index for the next value to be written into the Circular buffer */
  uint_T head;                         /* head is the index for the next value to be read from the Circular buffer */
} MCHP_UART1_RxStr;

/* To read the UART1 Rx Circular with a custom code: read the next value: buffer[head], then increment head index by 1 modulo Rx_BUFF_SIZE_Uart1 (=1024).
   code example:
   if (U1STAbits.URXDA != 0)
   if (MCHP_UART1_Rx.tail != MCHP_UART1_Rx.head)	{  		// is buffer not empty ?
   output = (uint8_T) MCHP_UART1_Rx.buffer[MCHP_UART1_Rx.head ++];     // Read one char
   MCHP_UART1_Rx.head &= (Rx_BUFF_SIZE_Uart1-1); 	// modulo : use a simple bitewise "and" operator as <Rx_BUFF_SIZE_Uart1> is a power of 2
   }
 */

/* Block signals and states (auto storage) for system '<Root>' */
typedef struct {
  real32_T FIR10_states[10];           /* '<Root>/FIR10' */
  real32_T FIR25_states[25];           /* '<Root>/FIR25' */
  real32_T FIR40_states[40];           /* '<Root>/FIR40' */
  real32_T FIR1_states[40];            /* '<Root>/FIR1' */
  real32_T DataTypeConversion1;        /* '<Root>/Data Type Conversion1' */
  real32_T A;                          /* '<Root>/Data Store Memory' */
  uint16_T ADC;                        /* '<Root>/ADC' */
  uint8_T U1Rx;                        /* '<Root>/UART Rx1' */
  uint8_T DataTypeConversion4;         /* '<Root>/Data Type Conversion4' */
} DW_ADC_DSPIC33_T;

/* Invariant block signals (auto storage) */
typedef struct {
  const uint8_T DataTypeConversion9;   /* '<Root>/Data Type Conversion9' */
  const uint8_T DataTypeConversion5;   /* '<Root>/Data Type Conversion5' */
  const uint8_T DataTypeConversion11;  /* '<Root>/Data Type Conversion11' */
} ConstB_ADC_DSPIC33_T;

/* Constant parameters (auto storage) */
typedef struct {
  /* Computed Parameter: FIR10_Coefficients
   * Referenced by: '<Root>/FIR10'
   */
  real32_T FIR10_Coefficients[11];

  /* Computed Parameter: FIR25_Coefficients
   * Referenced by: '<Root>/FIR25'
   */
  real32_T FIR25_Coefficients[26];

  /* Pooled Parameter (Expression: [-0.01423297720420574 -0.015817959399409564 -0.016528271678139684 -0.016208243927688132 -0.014739975184467713 -0.012051521623166995 -0.0081230763316393183 -0.0029907383172590989 0.0032524116635554981 0.010458071899141172 0.01842731038110863 0.026917825484855638 0.03565356953724233 0.044336295104620511 0.05265847282390991 0.060316947197958951 0.067026647996413058 0.072533662871220136 0.076627002551852536 0.079148452405864642 0.080000000000000002 0.079148452405864642 0.076627002551852536 0.072533662871220136 0.067026647996413058 0.060316947197958951 0.05265847282390991 0.044336295104620511 0.03565356953724233 0.026917825484855638 0.01842731038110863 0.010458071899141172 0.0032524116635554981 -0.0029907383172590989 -0.0081230763316393183 -0.012051521623166995 -0.014739975184467713 -0.016208243927688132 -0.016528271678139684 -0.015817959399409564 -0.01423297720420574])
   * Referenced by:
   *   '<Root>/FIR1'
   *   '<Root>/FIR40'
   */
  real32_T pooled2[41];
} ConstP_ADC_DSPIC33_T;

/* Block signals and states (auto storage) */
extern DW_ADC_DSPIC33_T ADC_DSPIC33_DW;
extern const ConstB_ADC_DSPIC33_T ADC_DSPIC33_ConstB;/* constant block i/o */

/* Constant parameters (auto storage) */
extern const ConstP_ADC_DSPIC33_T ADC_DSPIC33_ConstP;

/* Model entry point functions */
extern void ADC_DSPIC33_initialize(void);
extern void ADC_DSPIC33_step(void);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'ADC_DSPIC33'
 * '<S1>'   : 'ADC_DSPIC33/Compare To Constant'
 * '<S2>'   : 'ADC_DSPIC33/Compare To Constant1'
 * '<S3>'   : 'ADC_DSPIC33/Compare To Constant2'
 * '<S4>'   : 'ADC_DSPIC33/Digital Output'
 * '<S5>'   : 'ADC_DSPIC33/Digital Output1'
 * '<S6>'   : 'ADC_DSPIC33/Digital Output2'
 */
#endif                                 /* RTW_HEADER_ADC_DSPIC33_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
