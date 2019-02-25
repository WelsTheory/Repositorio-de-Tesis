/*
 * -------------------------------------------------------------------
 * MPLAB 16-Bit Device Blocks for Simulink v3.38.
 *
 *   Product Page:  http://www.microchip.com/SimulinkBlocks
 *           Forum: http://www.microchip.com/forums/f192.aspx
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: DSPIC33FJ_FIR.h
 *
 * Code generated for Simulink model 'DSPIC33FJ_FIR'.
 *
 * Model version                  : 1.77
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Sun Dec 09 18:39:59 2018
 */

#ifndef RTW_HEADER_DSPIC33FJ_FIR_h_
#define RTW_HEADER_DSPIC33FJ_FIR_h_
#include <string.h>
#include <stddef.h>
#ifndef DSPIC33FJ_FIR_COMMON_INCLUDES_
# define DSPIC33FJ_FIR_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* DSPIC33FJ_FIR_COMMON_INCLUDES_ */

#include "DSPIC33FJ_FIR_types.h"
#define FCY                            (5000000U)                /* Instruction Frequency FCY set at  5.0 MHz */

/* Include for pic 33F */
#include <p33Fxxxx.h>
#include <libpic30.h>                  /* For possible use with C function Call block (delay_ms or delay_us functions might be used by few peripherals) */
#include <libq.h>                      /* For possible use with C function Call block */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((void*) 0)
#endif

/* Declare UART1 Tx Circular Buffer Structure */
#define Tx_BUFF_SIZE_Uart1             (128)

typedef struct MCHP_UART1_TxStr{
  volatile uint8_T buffer[Tx_BUFF_SIZE_Uart1];/* Size Rx_BUFF_SIZE_Uart1 is 128 */
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
  uint8_T U1Rx;                        /* '<Root>/UART Rx1' */
} DW_DSPIC33FJ_FIR_T;

/* Invariant block signals (auto storage) */
typedef struct {
  const uint8_T DataTypeConversion5;   /* '<Root>/Data Type Conversion5' */
} ConstB_DSPIC33FJ_FIR_T;

/* Block signals and states (auto storage) */
extern DW_DSPIC33FJ_FIR_T DSPIC33FJ_FIR_DW;
extern const ConstB_DSPIC33FJ_FIR_T DSPIC33FJ_FIR_ConstB;/* constant block i/o */

/* Model entry point functions */
extern void DSPIC33FJ_FIR_initialize(void);
extern void DSPIC33FJ_FIR_step(void);

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
 * '<Root>' : 'DSPIC33FJ_FIR'
 * '<S1>'   : 'DSPIC33FJ_FIR/Compare To Constant'
 * '<S2>'   : 'DSPIC33FJ_FIR/Digital Output1'
 */
#endif                                 /* RTW_HEADER_DSPIC33FJ_FIR_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
