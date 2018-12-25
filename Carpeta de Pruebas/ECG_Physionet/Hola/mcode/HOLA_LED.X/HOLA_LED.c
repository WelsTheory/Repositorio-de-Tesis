/*
 * -------------------------------------------------------------------
 * MPLAB 16-Bit Device Blocks for Simulink v3.38.
 *
 *   Product Page:  http://www.microchip.com/SimulinkBlocks
 *           Forum: http://www.microchip.com/forums/f192.aspx
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: HOLA_LED.c
 *
 * Code generated for Simulink model 'HOLA_LED'.
 *
 * Model version                  : 1.41
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Thu Dec 20 16:57:12 2018
 */

#include "HOLA_LED.h"
#include "HOLA_LED_private.h"

/* Block signals and states (auto storage) */
DW_HOLA_LED_T HOLA_LED_DW;

/* Model step function */
void HOLA_LED_step(void)
{
  /* local block i/o variables */
  boolean_T rtb_Compare;
  real32_T tmp;

  /* MCHP_ADC Block for ADC 1: <Root>/ADC/Output */
  HOLA_LED_DW.ADC = ADC1BuffChannelA[0];

  /* Switch: '<Root>/Switch4' incorporates:
   *  DataStoreRead: '<Root>/Data Store Read'
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   *  S-Function (MCHP_Digital_Input): '<Root>/Digital Input'
   */
  if (PORTBbits.RB15) {
    tmp = HOLA_LED_DW.ADC;
  } else {
    tmp = HOLA_LED_DW.A;
  }

  /* End of Switch: '<Root>/Switch4' */

  /* DataTypeConversion: '<Root>/Data Type Conversion4' incorporates:
   *  ArithShift: '<Root>/Shift Arithmetic1'
   */
  tmp = (real32_T)floor((real32_T)ldexp(tmp, -4));
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 256.0F);
  }

  HOLA_LED_DW.DataTypeConversion4 = (uint8_T)(tmp < 0.0F ? (int16_T)(uint8_T)
    -(int8_T)(uint8_T)-tmp : (int16_T)(uint8_T)tmp);

  /* End of DataTypeConversion: '<Root>/Data Type Conversion4' */
  /* MCHP_UART_Tx Block for UARTRef 1: <Root>/UART Tx1/Outputs */
  {
    uint_T Tmp;
    Tmp = ~(MCHP_UART1_Tx.tail - MCHP_UART1_Tx.head);
    Tmp = Tmp & (Tx_BUFF_SIZE_Uart1 - 1);/* Modulo Buffer Size */

    {
      register uint_T LocalTail = MCHP_UART1_Tx.tail;/* Tail is a volatile variable. Use local variable to speed-up execution */
      MCHP_UART1_Tx.buffer[LocalTail] = HOLA_LED_DW.DataTypeConversion4;
      MCHP_UART1_Tx.tail = (LocalTail + 1) & (Tx_BUFF_SIZE_Uart1 - 1);
    }

    {
      register uint_T LocalHead;
      _U1TXIE = 0;                     /* Disable Interrupt portecting against possible concurrent access */
      _U1TXIF = 0;                     /* Clear Interrupt Flag */
      LocalHead = MCHP_UART1_Tx.head;  /* Head is a volatile variable. Use local variable to speed-up execution */
      while ((0U == U1STAbits.UTXBF) && (MCHP_UART1_Tx.tail != LocalHead) )/* while UxTXREG buffer is not full */
      {
        U1TXREG = MCHP_UART1_Tx.buffer[LocalHead];
        LocalHead = (LocalHead + 1) & (Tx_BUFF_SIZE_Uart1-1);
      }

      MCHP_UART1_Tx.head = LocalHead;  /* Push back volatile variable */
      if (MCHP_UART1_Tx.tail != LocalHead)/* If remaining values to send present in the circular buffer */
      {
        _U1TXIE = 1;                   /* Enable Interrupt */
      }
    }
  }

  /* MCHP_UART_Rx Block for UARTRef 1: <Root>/UART Rx/Outputs */
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
      HOLA_LED_DW.U1Rx = (uint8_T) MCHP_UART1_Rx.buffer[MCHP_UART1_Rx.head];/* Use only the 8 low bytes or RxReg */
      MCHP_UART1_Rx.head = (MCHP_UART1_Rx.head+1) & (Rx_BUFF_SIZE_Uart1-1);
      U1LastValue = HOLA_LED_DW.U1Rx;
    } else {
      HOLA_LED_DW.U1Rx = U1LastValue;
      if (U1STAbits.OERR )
        U1STAbits.OERR = 0;            /* Clear UART Rx Overload Error */
    }
  }

  /* DataStoreWrite: '<Root>/Data Store Write' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion8'
   */
  HOLA_LED_DW.A = HOLA_LED_DW.U1Rx;

  /* RelationalOperator: '<S1>/Compare' incorporates:
   *  Constant: '<S1>/Constant'
   *  S-Function (sfix_bitop): '<Root>/Bitwise Operator2'
   */
  rtb_Compare = ((HOLA_LED_DW.U1Rx & 1) == 1);

  /* S-Function (MCHP_Digital_Output_Write): '<S2>/Digital Output Write' */
  LATAbits.LATA1 = rtb_Compare;
}

/* Model initialize function */
void HOLA_LED_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* states (dwork) */
  (void) memset((void *)&HOLA_LED_DW, 0,
                sizeof(DW_HOLA_LED_T));

  /* S-Function "Microchip MASTER" initialization Block: <Root>/Microchip Master */

  /* MCHP_ADC Block for ADC 1: <Root>/ADC/Initialize */
  AD1CHS0 = 0x00;
  AD1CON3 = 0x1A;
  AD1CON2 = 0x00;
  AD1CON1 = 0x8444;
  _AD1IP = 2;                          /*Interrupt Priority : 2*/
  _AD1IF = 0;
  _AD1IE = 1;                          /* Enable ADC Interrupt */

  /* MCHP_UART_Config Block for UART 1: <Root>/UART Configuration/Initialize */
  U1BRG = 0x56;                        /* Baud rate: 115200 (-0.22%) */
  U1MODE = 0x8008;
  U1STA = 0x84C0;

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
