/*
 * -------------------------------------------------------------------
 * MPLAB 16-Bit Device Blocks for Simulink v3.38.
 *
 *   Product Page:  http://www.microchip.com/SimulinkBlocks
 *           Forum: http://www.microchip.com/forums/f192.aspx
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: hola_dspic.h
 *
 * Code generated for Simulink model 'hola_dspic'.
 *
 * Model version                  : 1.124
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Sun Nov 11 19:55:10 2018
 */

#ifndef RTW_HEADER_hola_dspic_h_
#define RTW_HEADER_hola_dspic_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef hola_dspic_COMMON_INCLUDES_
# define hola_dspic_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* hola_dspic_COMMON_INCLUDES_ */

#include "hola_dspic_types.h"
#define FCY                            (40000000U)               /* Instruction Frequency FCY set at  40.0 MHz */

/* Include for pic 33F */
#include <p33Fxxxx.h>
#include <libpic30.h>                  /* For possible use with C function Call block (delay_ms or delay_us functions might be used by few peripherals) */
#include <libq.h>                      /* For possible use with C function Call block */
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */

/* Declare UART1 Tx Circular Buffer Structure */
#define Tx_BUFF_SIZE_Uart1             (512)

typedef struct MCHP_UART1_TxStr{
  volatile uint8_T buffer[Tx_BUFF_SIZE_Uart1];/* Size Rx_BUFF_SIZE_Uart1 is 512 */
  volatile uint_T tail;                /* tail is the index for the next value to be read from the Circular buffer */
  volatile uint_T head;                /* head is the index for the next value to be written into the Circular buffer */
} MCHP_UART1_TxStr;

/* Declare UART1 Rx Circular Buffer Structure */
#define Rx_BUFF_SIZE_Uart1             (8)

typedef struct MCHP_UART1_RxStr{
  volatile uint8_T buffer[Rx_BUFF_SIZE_Uart1];/* Size Rx_BUFF_SIZE_Uart1 is 8 */
  volatile uint_T tail;                /* tail is the index for the next value to be written into the Circular buffer */
  uint_T head;                         /* head is the index for the next value to be read from the Circular buffer */
} MCHP_UART1_RxStr;

/* To read the UART1 Rx Circular with a custom code: read the next value: buffer[head], then increment head index by 1 modulo Rx_BUFF_SIZE_Uart1 (=8).
   code example:
   if (U1STAbits.URXDA != 0)
   if (MCHP_UART1_Rx.tail != MCHP_UART1_Rx.head)	{  		// is buffer not empty ?
   output = (uint8_T) MCHP_UART1_Rx.buffer[MCHP_UART1_Rx.head ++];     // Read one char
   MCHP_UART1_Rx.head &= (Rx_BUFF_SIZE_Uart1-1); 	// modulo : use a simple bitewise "and" operator as <Rx_BUFF_SIZE_Uart1> is a power of 2
   }
 */

/* Block signals and states (auto storage) for system '<Root>' */
typedef struct {
  real32_T FIR100_states[100];         /* '<Root>/FIR100' */
  uint16_T ADC;                        /* '<Root>/ADC' */
  uint8_T U1Rx;                        /* '<Root>/UART Rx' */
  uint8_T DataTypeConversion;          /* '<Root>/Data Type Conversion' */
  uint8_T DataTypeConversion1;         /* '<Root>/Data Type Conversion1' */
} DW_hola_dspic_T;

/* Constant parameters (auto storage) */
typedef struct {
  /* Computed Parameter: FIR100_Coefficients
   * Referenced by: '<Root>/FIR100'
   */
  real32_T FIR100_Coefficients[101];
} ConstP_hola_dspic_T;

/* Block signals and states (auto storage) */
extern DW_hola_dspic_T hola_dspic_DW;

/* Constant parameters (auto storage) */
extern const ConstP_hola_dspic_T hola_dspic_ConstP;

/* Model entry point functions */
extern void hola_dspic_initialize(void);
extern void hola_dspic_step(void);

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
 * '<Root>' : 'hola_dspic'
 * '<S1>'   : 'hola_dspic/Digital Output1'
 */
#endif                                 /* RTW_HEADER_hola_dspic_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
