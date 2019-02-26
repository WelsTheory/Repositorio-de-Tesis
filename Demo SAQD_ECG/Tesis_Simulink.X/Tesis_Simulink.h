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
 * Model version                  : 1.69
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Mon Feb 18 04:35:22 2019
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
  real_T A;                            /* '<Root>/Data Store Memory' */
  real32_T Filter_PB40_5orden_states[5];/* '<Root>/Filter_PB40_5orden' */
  real32_T Filter_PA05_5orden_states[5];/* '<Root>/Filter_PA05_5orden' */
  real32_T Filter_PA05_10orden_states[10];/* '<Root>/Filter_PA05_10orden' */
  real32_T Filter_0540_30orden_states[30];/* '<Root>/Filter_0540_30orden' */
  real32_T DataTypeConversion2;        /* '<Root>/Data Type Conversion2' */
  uint16_T ADC;                        /* '<Root>/ADC' */
  uint8_T U1Rx;                        /* '<Root>/UART Rx' */
  uint8_T DataTypeConversion4;         /* '<Root>/Data Type Conversion4' */
} DW_Tesis_Simulink_T;

/* Constant parameters (auto storage) */
typedef struct {
  /* Computed Parameter: Filter_PB40_5orden_Coefficients
   * Referenced by: '<Root>/Filter_PB40_5orden'
   */
  real32_T Filter_PB40_5orden_Coefficients[6];

  /* Computed Parameter: Filter_PA05_5orden_Coefficients
   * Referenced by: '<Root>/Filter_PA05_5orden'
   */
  real32_T Filter_PA05_5orden_Coefficients[6];

  /* Computed Parameter: Filter_PA05_10orden_Coefficients
   * Referenced by: '<Root>/Filter_PA05_10orden'
   */
  real32_T Filter_PA05_10orden_Coefficients[11];

  /* Computed Parameter: Filter_0540_30orden_Coefficients
   * Referenced by: '<Root>/Filter_0540_30orden'
   */
  real32_T Filter_0540_30orden_Coefficients[31];
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
 * '<S4>'   : 'Tesis_Simulink/LED'
 */
#endif                                 /* RTW_HEADER_Tesis_Simulink_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
