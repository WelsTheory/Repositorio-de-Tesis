/*
 * -------------------------------------------------------------------
 * MPLAB 16-Bit Device Blocks for Simulink v3.38.
 *
 *   Product Page:  http://www.microchip.com/SimulinkBlocks
 *           Forum: http://www.microchip.com/forums/f192.aspx
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: Tesis_Simulink.h
 *
 * Code generated for Simulink model 'Tesis_Simulink'.
 *
 * Model version                  : 1.13
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Dec 25 20:13:03 2018
 */

#ifndef RTW_HEADER_Tesis_Simulink_h_
#define RTW_HEADER_Tesis_Simulink_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef Tesis_Simulink_COMMON_INCLUDES_
# define Tesis_Simulink_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Tesis_Simulink_COMMON_INCLUDES_ */

#include "Tesis_Simulink_types.h"
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
#define Tx_BUFF_SIZE_Uart1             (1024)

typedef struct MCHP_UART1_TxStr{
  volatile uint8_T buffer[Tx_BUFF_SIZE_Uart1];/* Size Rx_BUFF_SIZE_Uart1 is 1024 */
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
  real32_T FIR4_states[25];            /* '<Root>/FIR4' */
  real32_T FIR25_states[25];           /* '<Root>/FIR25' */
  real32_T FIR3_states[40];            /* '<Root>/FIR3' */
  real32_T FIR40_states[40];           /* '<Root>/FIR40' */
  real32_T FIR2_states[40];            /* '<Root>/FIR2' */
  real32_T FIR1_states[40];            /* '<Root>/FIR1' */
  real32_T DataTypeConversion2;        /* '<Root>/Data Type Conversion2' */
  real32_T A;                          /* '<Root>/Data Store Memory' */
  uint16_T ADC;                        /* '<Root>/ADC' */
  uint8_T U1Rx;                        /* '<Root>/UART Rx' */
  uint8_T DataTypeConversion4;         /* '<Root>/Data Type Conversion4' */
} DW_Tesis_Simulink_T;

/* Constant parameters (auto storage) */
typedef struct {
  /* Computed Parameter: FIR10_Coefficients
   * Referenced by: '<Root>/FIR10'
   */
  real32_T FIR10_Coefficients[11];

  /* Pooled Parameter (Expression: [2.9323800933922057e-18 0.0065349003912518319 0.013986521520040542 0.022140617857123224 0.030738535363382793 0.03948803959916064 0.048076271039389107 0.056184162411385824 0.063501554247964775 0.069742190535843199 0.074657770305471507 0.078050274193107061 0.079781875233049623 0.079781875233049623 0.078050274193107061 0.074657770305471507 0.069742190535843199 0.063501554247964775 0.056184162411385824 0.048076271039389107 0.03948803959916064 0.030738535363382793 0.022140617857123224 0.013986521520040542 0.0065349003912518319 2.9323800933922057e-18])
   * Referenced by:
   *   '<Root>/FIR25'
   *   '<Root>/FIR4'
   */
  real32_T pooled2[26];

  /* Pooled Parameter (Expression: [-0.01423297720420574 -0.015817959399409564 -0.016528271678139684 -0.016208243927688132 -0.014739975184467713 -0.012051521623166995 -0.0081230763316393183 -0.0029907383172590989 0.0032524116635554981 0.010458071899141172 0.01842731038110863 0.026917825484855638 0.03565356953724233 0.044336295104620511 0.05265847282390991 0.060316947197958951 0.067026647996413058 0.072533662871220136 0.076627002551852536 0.079148452405864642 0.080000000000000002 0.079148452405864642 0.076627002551852536 0.072533662871220136 0.067026647996413058 0.060316947197958951 0.05265847282390991 0.044336295104620511 0.03565356953724233 0.026917825484855638 0.01842731038110863 0.010458071899141172 0.0032524116635554981 -0.0029907383172590989 -0.0081230763316393183 -0.012051521623166995 -0.014739975184467713 -0.016208243927688132 -0.016528271678139684 -0.015817959399409564 -0.01423297720420574])
   * Referenced by:
   *   '<Root>/FIR1'
   *   '<Root>/FIR2'
   *   '<Root>/FIR3'
   *   '<Root>/FIR40'
   */
  real32_T pooled3[41];
} ConstP_Tesis_Simulink_T;

/* Block signals and states (auto storage) */
extern DW_Tesis_Simulink_T Tesis_Simulink_DW;

/* Constant parameters (auto storage) */
extern const ConstP_Tesis_Simulink_T Tesis_Simulink_ConstP;

/* Model entry point functions */
extern void Tesis_Simulink_initialize(void);
extern void Tesis_Simulink_step(void);

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
 * '<Root>' : 'Tesis_Simulink'
 * '<S1>'   : 'Tesis_Simulink/Compare To Constant'
 * '<S2>'   : 'Tesis_Simulink/Compare To Constant1'
 * '<S3>'   : 'Tesis_Simulink/Compare To Constant2'
 * '<S4>'   : 'Tesis_Simulink/Digital Output1'
 * '<S5>'   : 'Tesis_Simulink/Digital Output2'
 * '<S6>'   : 'Tesis_Simulink/Digital Output3'
 */
#endif                                 /* RTW_HEADER_Tesis_Simulink_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
