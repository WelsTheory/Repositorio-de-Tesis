/*
 * -------------------------------------------------------------------
 * MPLAB 16-Bit Device Blocks for Simulink v3.38.
 *
 *   Product Page:  http://www.microchip.com/SimulinkBlocks
 *           Forum: http://www.microchip.com/forums/f192.aspx
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: hola_dspic.c
 *
 * Code generated for Simulink model 'hola_dspic'.
 *
 * Model version                  : 1.124
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Sun Nov 11 19:55:10 2018
 */

#include "hola_dspic.h"
#include "hola_dspic_private.h"

/* Block signals and states (auto storage) */
DW_hola_dspic_T hola_dspic_DW;

/* Model step function */
void hola_dspic_step(void)
{
  /* local block i/o variables */
  boolean_T rtb_DataTypeConversion2;
  int16_T j;
  real32_T rtb_ShiftArithmetic1;
  uint32_T rtb_Product1;

  /* S-Function (MCHP_UART_Rx): '<Root>/UART Rx' */

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
      hola_dspic_DW.U1Rx = (uint8_T) MCHP_UART1_Rx.buffer[MCHP_UART1_Rx.head];/* Use only the 8 low bytes or RxReg */
      MCHP_UART1_Rx.head = (MCHP_UART1_Rx.head+1) & (Rx_BUFF_SIZE_Uart1-1);
      U1LastValue = hola_dspic_DW.U1Rx;
    } else {
      hola_dspic_DW.U1Rx = U1LastValue;
      if (U1STAbits.OERR )
        U1STAbits.OERR = 0;            /* Clear UART Rx Overload Error */
    }
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion2' incorporates:
   *  S-Function (sfix_bitop): '<Root>/Bitwise Operator'
   */
  rtb_DataTypeConversion2 = ((hola_dspic_DW.U1Rx & 1) != 0);

  /* S-Function (MCHP_Digital_Output_Write): '<S1>/Digital Output Write' */
  LATAbits.LATA1 = rtb_DataTypeConversion2;

  /* S-Function (MCHP_ADC): '<Root>/ADC' */
  /* MCHP_ADC Block for ADC 1: <Root>/ADC/Output */
  hola_dspic_DW.ADC = ADC1BuffChannelA[0];

  /* Product: '<Root>/Product' incorporates:
   *  S-Function (sfix_bitop): '<Root>/Bitwise Operator1'
   */
  rtb_Product1 = (uint32_T)(hola_dspic_DW.U1Rx & 9) * hola_dspic_DW.ADC;

  /* DiscreteFir: '<Root>/FIR100' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion3'
   */
  /* Consume delay line and beginning of input samples */
  rtb_ShiftArithmetic1 = 0.0F;
  j = 0;
  while (j < 1) {
    rtb_ShiftArithmetic1 += (real32_T)rtb_Product1 *
      hola_dspic_ConstP.FIR100_Coefficients[0L];
    j = 1;
  }

  for (j = 0; j < 100; j++) {
    rtb_ShiftArithmetic1 += hola_dspic_ConstP.FIR100_Coefficients[(int32_T)(1 +
      j)] * hola_dspic_DW.FIR100_states[(int32_T)j];
  }

  /* Update delay line for next frame */
  for (j = 98; j >= 0; j--) {
    hola_dspic_DW.FIR100_states[(int32_T)(1 + j)] = hola_dspic_DW.FIR100_states
      [(int32_T)j];
  }

  hola_dspic_DW.FIR100_states[0L] = (real32_T)rtb_Product1;

  /* End of DiscreteFir: '<Root>/FIR100' */

  /* ArithShift: '<Root>/Shift Arithmetic' */
  rtb_ShiftArithmetic1 = (real32_T)ldexp(rtb_ShiftArithmetic1, -4);

  /* DataTypeConversion: '<Root>/Data Type Conversion' */
  rtb_ShiftArithmetic1 = (real32_T)floor(rtb_ShiftArithmetic1);
  if (rtIsNaNF(rtb_ShiftArithmetic1) || rtIsInfF(rtb_ShiftArithmetic1)) {
    rtb_ShiftArithmetic1 = 0.0F;
  } else {
    rtb_ShiftArithmetic1 = (real32_T)fmod(rtb_ShiftArithmetic1, 256.0F);
  }

  hola_dspic_DW.DataTypeConversion = (uint8_T)(rtb_ShiftArithmetic1 < 0.0F ?
    (int16_T)(uint8_T)-(int8_T)(uint8_T)-rtb_ShiftArithmetic1 : (int16_T)
    (uint8_T)rtb_ShiftArithmetic1);

  /* End of DataTypeConversion: '<Root>/Data Type Conversion' */

  /* S-Function (MCHP_UART_Tx): '<Root>/UART Tx' */
  /* MCHP_UART_Tx Block for UARTRef 1: <Root>/UART Tx/Outputs */
  {
    uint_T Tmp;
    Tmp = ~(MCHP_UART1_Tx.tail - MCHP_UART1_Tx.head);
    Tmp = Tmp & (Tx_BUFF_SIZE_Uart1 - 1);/* Modulo Buffer Size */

    {
      register uint_T LocalTail = MCHP_UART1_Tx.tail;/* Tail is a volatile variable. Use local variable to speed-up execution */
      MCHP_UART1_Tx.buffer[LocalTail] = hola_dspic_DW.DataTypeConversion;
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

  /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
   *  ArithShift: '<Root>/Shift Arithmetic1'
   *  DataTypeConversion: '<Root>/Data Type Conversion4'
   *  Product: '<Root>/Product1'
   *  S-Function (sfix_bitop): '<Root>/Bitwise Operator2'
   */
  hola_dspic_DW.DataTypeConversion1 = (uint8_T)(int16_T)(real32_T)fmod((int16_T)
    (real32_T)floor((real32_T)ldexp((real32_T)((uint32_T)(hola_dspic_DW.U1Rx & 4)
    * hola_dspic_DW.ADC), -4)), 256.0F);

  /* S-Function (MCHP_UART_Tx): '<Root>/UART Tx1' */
  /* MCHP_UART_Tx Block for UARTRef 1: <Root>/UART Tx1/Outputs */
  {
    uint_T Tmp;
    Tmp = ~(MCHP_UART1_Tx.tail - MCHP_UART1_Tx.head);
    Tmp = Tmp & (Tx_BUFF_SIZE_Uart1 - 1);/* Modulo Buffer Size */

    {
      register uint_T LocalTail = MCHP_UART1_Tx.tail;/* Tail is a volatile variable. Use local variable to speed-up execution */
      MCHP_UART1_Tx.buffer[LocalTail] = hola_dspic_DW.DataTypeConversion1;
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
}

/* Model initialize function */
void hola_dspic_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* states (dwork) */
  (void) memset((void *)&hola_dspic_DW, 0,
                sizeof(DW_hola_dspic_T));

  /* Start for S-Function (MCHP_Master): '<Root>/Microchip Master' */

  /* S-Function "Microchip MASTER" initialization Block: <Root>/Microchip Master */

  /* Start for S-Function (MCHP_ADC): '<Root>/ADC' */

  /* MCHP_ADC Block for ADC 1: <Root>/ADC/Initialize */
  AD1CHS0 = 0x00;
  AD1CON3 = 0x1A;
  AD1CON2 = 0x00;
  AD1CON1 = 0x8444;
  _AD1IP = 2;                          /*Interrupt Priority : 2*/
  _AD1IF = 0;
  _AD1IE = 1;                          /* Enable ADC Interrupt */

  /* Start for S-Function (MCHP_UART_Config): '<Root>/UART Configuration' */

  /* MCHP_UART_Config Block for UART 1: <Root>/UART Configuration/Initialize */
  U1BRG = 0xAD;                        /* Baud rate: 57600 (-0.22%) */
  U1MODE = 0x8008;
  U1STA = 0x8400;

  /* Configure UART1 Tx Interruption */
  MCHP_UART1_Tx.head = 0;              /* Initialise Circular Buffers */
  MCHP_UART1_Tx.tail = 0;
  _U1TXIP = 4;                         /*  Tx Interrupt priority set to 4 */
  _U1TXIF = 0;                         /*  */
  _U1TXIE = 1;                         /* Enable Interrupt */

  /* Configure UART1 Rx Interruption */
  MCHP_UART1_Rx.head = 0;              /* Initialise Circular Buffers */
  MCHP_UART1_Rx.tail = 0;
  _U1RXIP = 7;                         /* Rx Interrupt priority set to 7 */
  _U1RXIF = 0;                         /*  */
  _U1RXIE = 1;                         /* Enable Interrupt */

  /* InitializeConditions for DiscreteFir: '<Root>/FIR100' */
  memset(&hola_dspic_DW.FIR100_states[0], 0, 100U * sizeof(real32_T));
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
