/*
 * -------------------------------------------------------------------
 * MPLAB 16-Bit Device Blocks for Simulink v3.38.
 *
 *   Product Page:  http://www.microchip.com/SimulinkBlocks
 *           Forum: http://www.microchip.com/forums/f192.aspx
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: DSPIC33FJ_FIR.c
 *
 * Code generated for Simulink model 'DSPIC33FJ_FIR'.
 *
 * Model version                  : 1.77
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Sun Dec 09 18:39:59 2018
 */

#include "DSPIC33FJ_FIR.h"
#include "DSPIC33FJ_FIR_private.h"

/* Block signals and states (auto storage) */
DW_DSPIC33FJ_FIR_T DSPIC33FJ_FIR_DW;

/* Model step function */
void DSPIC33FJ_FIR_step(void)
{
  /* local block i/o variables */
  boolean_T rtb_DataTypeConversion8;

  /* MCHP_UART_Rx Block for UARTRef 1: <Root>/UART Rx1/Outputs */
  {
    static uint8_T U1LastValue ;
    if (0U != U1STAbits.URXDA) {       /* Flush internal UART buffer */
      uint_T Tmp;
      _U1RXIE = 0;                     /* Flush internal UART buffer, disable interrupt */
      Tmp = ~(MCHP_UART1_Rx.tail - MCHP_UART1_Rx.head);/* head - tail - 1 */
      Tmp &= (Rx_BUFF_SIZE_Uart1-1);   /* Tmp =  (head - tail - 1) modulo buffersize Rx_BUFF_SIZE_Uart1)	<==> Rx_BUFF_SIZE_Uart1 - (head - tail) - 1*/
      while (U1STAbits.URXDA == 1) {
        if (Tmp--) {
          MCHP_UART1_Rx.buffer[MCHP_UART1_Rx.tail] = (uint8_T) U1RXREG;
          MCHP_UART1_Rx.tail = (MCHP_UART1_Rx.tail+1) & (Rx_BUFF_SIZE_Uart1-1);
        } else {
          unsigned int a;
          do
            a = U1RXREG;
          while (U1STAbits.URXDA == 1);
          break;
        }
      }

      _U1RXIF = 0;                     /* Reset interrupt */
      _U1RXIE = 1;                     /* Re-enable interrupt */
    }

    if (MCHP_UART1_Rx.tail != MCHP_UART1_Rx.head) {
      DSPIC33FJ_FIR_DW.U1Rx = (uint8_T) MCHP_UART1_Rx.buffer[MCHP_UART1_Rx.head];/* Use only the 8 low bytes or RxReg */
      MCHP_UART1_Rx.head = (MCHP_UART1_Rx.head+1) & (Rx_BUFF_SIZE_Uart1-1);
      U1LastValue = DSPIC33FJ_FIR_DW.U1Rx;
    } else {
      DSPIC33FJ_FIR_DW.U1Rx = U1LastValue;
      if (U1STAbits.OERR )
        U1STAbits.OERR = 0;            /* Clear UART Rx Overload Error */
    }
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion8' incorporates:
   *  Constant: '<S1>/Constant'
   *  Product: '<Root>/Divide'
   *  RelationalOperator: '<S1>/Compare'
   *  S-Function (sfix_bitop): '<Root>/Bitwise Operator2'
   */
  rtb_DataTypeConversion8 = ((uint8_T)(DSPIC33FJ_FIR_ConstB.DataTypeConversion5 ==
    0U ? MAX_uint16_T : (uint16_T)(DSPIC33FJ_FIR_DW.U1Rx & ((uint8_T)1U)) /
    DSPIC33FJ_FIR_ConstB.DataTypeConversion5) == ((uint8_T)1U));

  /* S-Function (MCHP_Digital_Output_Write): '<S2>/Digital Output Write' */
  LATAbits.LATA2 = rtb_DataTypeConversion8;
}

/* Model initialize function */
void DSPIC33FJ_FIR_initialize(void)
{
  /* Registration code */

  /* states (dwork) */
  (void) memset((void *) &DSPIC33FJ_FIR_DW, 0,
                sizeof(DW_DSPIC33FJ_FIR_T));

  /* S-Function "Microchip MASTER" initialization Block: <Root>/Microchip Master */

  /* MCHP_UART_Config Block for UART 1: <Root>/UART Configuration/Initialize */
  U1BRG = 0x15;                        /* Baud rate: 57600 (-1.36%) */
  U1MODE = 0x8008;
  U1STA = 0x8400;

  /* Configure UART1 Tx Interruption */
  MCHP_UART1_Tx.head = 0;              /* Initialise Circular Buffers */
  MCHP_UART1_Tx.tail = 0;
  _U1TXIP = 5;                         /*  Tx Interrupt priority set to 5 */
  _U1TXIF = 0;                         /*  */
  _U1TXIE = 1;                         /* Enable Interrupt */

  /* Configure UART1 Rx Interruption */
  MCHP_UART1_Rx.head = 0;              /* Initialise Circular Buffers */
  MCHP_UART1_Rx.tail = 0;
  _U1RXIP = 7;                         /* Rx Interrupt priority set to 7 */
  _U1RXIF = 0;                         /*  */
  _U1RXIE = 1;                         /* Enable Interrupt */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
