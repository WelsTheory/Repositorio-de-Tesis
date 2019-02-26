/*
 * -------------------------------------------------------------------
 * MPLAB 16-Bit Device Blocks for Simulink v3.38.
 *
 *   Product Page:  http://www.microchip.com/SimulinkBlocks
 *           Forum: http://www.microchip.com/forums/f192.aspx
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: Ejemplo_de_Programa_principal.h
 *
 * Code generated for Simulink model 'Ejemplo_de_Programa_principal'.
 *
 * Model version                  : 1.89
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Feb 26 06:30:36 2019
 */

#ifndef RTW_HEADER_Ejemplo_de_Programa_principal_h_
#define RTW_HEADER_Ejemplo_de_Programa_principal_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef Ejemplo_de_Programa_principal_COMMON_INCLUDES_
# define Ejemplo_de_Programa_principal_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Ejemplo_de_Programa_principal_COMMON_INCLUDES_ */

#include "Ejemplo_de_Programa_principal_types.h"
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
  real32_T DataTypeConversion2;        /* '<Root>/Data Type Conversion2' */
  real32_T Filter_states;              /* '<S3>/Filter' */
  real32_T Filter1_states;             /* '<S3>/Filter1' */
  real32_T Filter2_states;             /* '<S3>/Filter2' */
  real32_T Filter3_states;             /* '<S3>/Filter3' */
  real32_T Filter4_states;             /* '<S3>/Filter4' */
  real32_T Filter5_states;             /* '<S3>/Filter5' */
  real32_T Filter6_states;             /* '<S3>/Filter6' */
  real32_T A;                          /* '<Root>/Data Store Memory' */
  uint16_T ADC;                        /* '<Root>/ADC' */
  uint8_T U1Rx;                        /* '<Root>/UART Rx' */
  uint8_T DataTypeConversion1;         /* '<S7>/Data Type Conversion1' */
} DW_Ejemplo_de_Programa_principal_T;

/* Block signals and states (auto storage) */
extern DW_Ejemplo_de_Programa_principal_T Ejemplo_de_Programa_principal_DW;

/* Model entry point functions */
extern void Ejemplo_de_Programa_principal_initialize(void);
extern void Ejemplo_de_Programa_principal_step(void);

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
 * '<Root>' : 'Ejemplo_de_Programa_principal'
 * '<S1>'   : 'Ejemplo_de_Programa_principal/DAC'
 * '<S2>'   : 'Ejemplo_de_Programa_principal/LED'
 * '<S3>'   : 'Ejemplo_de_Programa_principal/Programable'
 * '<S4>'   : 'Ejemplo_de_Programa_principal/R2R'
 * '<S5>'   : 'Ejemplo_de_Programa_principal/Recepción de Datos'
 * '<S6>'   : 'Ejemplo_de_Programa_principal/Selección de Filtro'
 * '<S7>'   : 'Ejemplo_de_Programa_principal/Transmisión de datos'
 * '<S8>'   : 'Ejemplo_de_Programa_principal/Recepción de Datos/Compare To Constant'
 * '<S9>'   : 'Ejemplo_de_Programa_principal/Recepción de Datos/Compare To Constant1'
 * '<S10>'  : 'Ejemplo_de_Programa_principal/Recepción de Datos/Compare To Constant2'
 */
#endif                                 /* RTW_HEADER_Ejemplo_de_Programa_principal_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
