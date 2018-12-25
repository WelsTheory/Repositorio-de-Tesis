/*
 * -------------------------------------------------------------------
 * MPLAB 16-Bit Device Blocks for Simulink v3.38.
 *
 *   Product Page:  http://www.microchip.com/SimulinkBlocks
 *           Forum: http://www.microchip.com/forums/f192.aspx
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: ADC_DSPIC33.c
 *
 * Code generated for Simulink model 'ADC_DSPIC33'.
 *
 * Model version                  : 1.202
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Sun Nov 18 19:15:44 2018
 */

#include "ADC_DSPIC33.h"
#include "ADC_DSPIC33_private.h"

/* Block signals and states (auto storage) */
DW_ADC_DSPIC33_T ADC_DSPIC33_DW;

/* Model step function */
void ADC_DSPIC33_step(void)
{
  /* local block i/o variables */
  boolean_T rtb_DataTypeConversion10;
  boolean_T rtb_DataTypeConversion8;
  boolean_T rtb_DataTypeConversion2;
  int32_T i;
  int32_T j;
  real32_T rtb_FIR10;
  real32_T rtb_FIR25;
  real32_T rtb_FIR40;
  real32_T rtb_FIR1;

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
      ADC_DSPIC33_DW.U1Rx = (uint8_T) MCHP_UART1_Rx.buffer[MCHP_UART1_Rx.head];/* Use only the 8 low bytes or RxReg */
      MCHP_UART1_Rx.head = (MCHP_UART1_Rx.head+1) & (Rx_BUFF_SIZE_Uart1-1);
      U1LastValue = ADC_DSPIC33_DW.U1Rx;
    } else {
      ADC_DSPIC33_DW.U1Rx = U1LastValue;
      if (U1STAbits.OERR )
        U1STAbits.OERR = 0;            /* Clear UART Rx Overload Error */
    }
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion10' incorporates:
   *  Constant: '<S2>/Constant'
   *  Product: '<Root>/Divide1'
   *  RelationalOperator: '<S2>/Compare'
   *  S-Function (sfix_bitop): '<Root>/Bitwise Operator'
   */
  rtb_DataTypeConversion10 = ((uint8_T)(ADC_DSPIC33_ConstB.DataTypeConversion9 ==
    0U ? MAX_uint16_T : (uint16_T)(ADC_DSPIC33_DW.U1Rx & ((uint8_T)2U)) /
    ADC_DSPIC33_ConstB.DataTypeConversion9) == ((uint8_T)1U));

  /* S-Function (MCHP_Digital_Output_Write): '<S4>/Digital Output Write' */
  LATBbits.LATB1 = rtb_DataTypeConversion10;

  /* DataTypeConversion: '<Root>/Data Type Conversion8' incorporates:
   *  Constant: '<S1>/Constant'
   *  Product: '<Root>/Divide'
   *  RelationalOperator: '<S1>/Compare'
   *  S-Function (sfix_bitop): '<Root>/Bitwise Operator2'
   */
  rtb_DataTypeConversion8 = ((uint8_T)(ADC_DSPIC33_ConstB.DataTypeConversion5 ==
    0U ? MAX_uint16_T : (uint16_T)(ADC_DSPIC33_DW.U1Rx & ((uint8_T)1U)) /
    ADC_DSPIC33_ConstB.DataTypeConversion5) == ((uint8_T)1U));

  /* S-Function (MCHP_Digital_Output_Write): '<S5>/Digital Output Write' */
  LATAbits.LATA1 = rtb_DataTypeConversion8;

  /* DataTypeConversion: '<Root>/Data Type Conversion2' incorporates:
   *  Constant: '<S3>/Constant'
   *  Product: '<Root>/Divide2'
   *  RelationalOperator: '<S3>/Compare'
   *  S-Function (sfix_bitop): '<Root>/Bitwise Operator1'
   */
  rtb_DataTypeConversion2 = ((uint8_T)(ADC_DSPIC33_ConstB.DataTypeConversion11 ==
    0U ? MAX_uint16_T : (uint16_T)(ADC_DSPIC33_DW.U1Rx & ((uint8_T)4U)) /
    ADC_DSPIC33_ConstB.DataTypeConversion11) == ((uint8_T)1U));

  /* S-Function (MCHP_Digital_Output_Write): '<S6>/Digital Output Write' */
  LATBbits.LATB2 = rtb_DataTypeConversion2;

  /* MCHP_ADC Block for ADC 1: <Root>/ADC/Output */
  ADC_DSPIC33_DW.ADC = ADC1BuffChannelA[0];

  /* DataTypeConversion: '<Root>/Data Type Conversion1' */
  ADC_DSPIC33_DW.DataTypeConversion1 = ADC_DSPIC33_DW.ADC;

  /* DiscreteFir: '<Root>/FIR10' */
  /* Consume delay line and beginning of input samples */
  for (i = 1L; i - 1L < 1L; i++) {
    rtb_FIR10 = 0.0F;
    for (j = 0L; j < i; j++) {
      rtb_FIR10 += ADC_DSPIC33_DW.DataTypeConversion1 *
        ADC_DSPIC33_ConstP.FIR10_Coefficients[j];
    }

    for (j = 0L; j < 11L - i; j++) {
      rtb_FIR10 = ADC_DSPIC33_ConstP.FIR10_Coefficients[i + j] *
        ADC_DSPIC33_DW.FIR10_states[j] + rtb_FIR10;
    }
  }

  /* Update delay line for next frame */
  for (i = 8L; (int16_T)i >= 0; i = (int16_T)i - 1) {
    ADC_DSPIC33_DW.FIR10_states[(int32_T)(1 + (int16_T)i)] =
      ADC_DSPIC33_DW.FIR10_states[i];
  }

  for (i = 1L; i - 1L < 1L; i++) {
    ADC_DSPIC33_DW.FIR10_states[1L - i] = ADC_DSPIC33_DW.DataTypeConversion1;
  }

  /* End of DiscreteFir: '<Root>/FIR10' */

  /* DiscreteFir: '<Root>/FIR25' */
  /* Consume delay line and beginning of input samples */
  for (i = 1L; i - 1L < 1L; i++) {
    rtb_FIR25 = 0.0F;
    for (j = 0L; j < i; j++) {
      rtb_FIR25 += ADC_DSPIC33_DW.DataTypeConversion1 *
        ADC_DSPIC33_ConstP.FIR25_Coefficients[j];
    }

    for (j = 0L; j < 26L - i; j++) {
      rtb_FIR25 = ADC_DSPIC33_ConstP.FIR25_Coefficients[i + j] *
        ADC_DSPIC33_DW.FIR25_states[j] + rtb_FIR25;
    }
  }

  /* Update delay line for next frame */
  for (i = 23L; (int16_T)i >= 0; i = (int16_T)i - 1) {
    ADC_DSPIC33_DW.FIR25_states[(int32_T)(1 + (int16_T)i)] =
      ADC_DSPIC33_DW.FIR25_states[i];
  }

  for (i = 1L; i - 1L < 1L; i++) {
    ADC_DSPIC33_DW.FIR25_states[1L - i] = ADC_DSPIC33_DW.DataTypeConversion1;
  }

  /* End of DiscreteFir: '<Root>/FIR25' */

  /* DiscreteFir: '<Root>/FIR40' */
  /* Consume delay line and beginning of input samples */
  for (i = 1L; i - 1L < 1L; i++) {
    rtb_FIR40 = 0.0F;
    for (j = 0L; j < i; j++) {
      rtb_FIR40 += ADC_DSPIC33_DW.DataTypeConversion1 *
        ADC_DSPIC33_ConstP.pooled2[j];
    }

    for (j = 0L; j < 41L - i; j++) {
      rtb_FIR40 = ADC_DSPIC33_ConstP.pooled2[i + j] *
        ADC_DSPIC33_DW.FIR40_states[j] + rtb_FIR40;
    }
  }

  /* Update delay line for next frame */
  for (i = 38L; (int16_T)i >= 0; i = (int16_T)i - 1) {
    ADC_DSPIC33_DW.FIR40_states[(int32_T)(1 + (int16_T)i)] =
      ADC_DSPIC33_DW.FIR40_states[i];
  }

  for (i = 1L; i - 1L < 1L; i++) {
    ADC_DSPIC33_DW.FIR40_states[1L - i] = ADC_DSPIC33_DW.DataTypeConversion1;
  }

  /* End of DiscreteFir: '<Root>/FIR40' */

  /* DiscreteFir: '<Root>/FIR1' */
  /* Consume delay line and beginning of input samples */
  for (i = 1L; i - 1L < 1L; i++) {
    rtb_FIR1 = 0.0F;
    for (j = 0L; j < i; j++) {
      rtb_FIR1 += ADC_DSPIC33_DW.DataTypeConversion1 *
        ADC_DSPIC33_ConstP.pooled2[j];
    }

    for (j = 0L; j < 41L - i; j++) {
      rtb_FIR1 = ADC_DSPIC33_ConstP.pooled2[i + j] *
        ADC_DSPIC33_DW.FIR1_states[j] + rtb_FIR1;
    }
  }

  /* Update delay line for next frame */
  for (i = 38L; (int16_T)i >= 0; i = (int16_T)i - 1) {
    ADC_DSPIC33_DW.FIR1_states[(int32_T)(1 + (int16_T)i)] =
      ADC_DSPIC33_DW.FIR1_states[i];
  }

  for (i = 1L; i - 1L < 1L; i++) {
    ADC_DSPIC33_DW.FIR1_states[1L - i] = ADC_DSPIC33_DW.DataTypeConversion1;
  }

  /* End of DiscreteFir: '<Root>/FIR1' */

  /* Switch: '<Root>/Switch7' incorporates:
   *  Switch: '<Root>/Switch1'
   *  Switch: '<Root>/Switch6'
   */
  if (rtb_DataTypeConversion2) {
    /* Switch: '<Root>/Switch5' incorporates:
     *  Switch: '<Root>/Switch3'
     */
    if (rtb_DataTypeConversion10) {
      /* Switch: '<Root>/Switch4' */
      if (rtb_DataTypeConversion8) {
        rtb_FIR1 = ADC_DSPIC33_DW.DataTypeConversion1;
      } else {
        rtb_FIR1 = rtb_FIR10;
      }
    } else if (rtb_DataTypeConversion8) {
      /* Switch: '<Root>/Switch3' incorporates:
       *  Switch: '<Root>/Switch4'
       */
      rtb_FIR1 = ADC_DSPIC33_DW.DataTypeConversion1;
    } else {
      /* Switch: '<Root>/Switch4' incorporates:
       *  Switch: '<Root>/Switch3'
       */
      rtb_FIR1 = rtb_FIR25;
    }

    /* End of Switch: '<Root>/Switch5' */
  } else if (rtb_DataTypeConversion10) {
    /* Switch: '<Root>/Switch2' incorporates:
     *  Switch: '<Root>/Switch1'
     */
    if (rtb_DataTypeConversion8) {
      rtb_FIR1 = ADC_DSPIC33_DW.DataTypeConversion1;
    } else {
      rtb_FIR1 = rtb_FIR40;
    }

    /* End of Switch: '<Root>/Switch2' */
  } else {
    if (rtb_DataTypeConversion8) {
      /* Switch: '<Root>/Switch6' incorporates:
       *  Switch: '<Root>/Switch1'
       */
      rtb_FIR1 = ADC_DSPIC33_DW.DataTypeConversion1;
    }
  }

  /* End of Switch: '<Root>/Switch7' */

  /* ArithShift: '<Root>/Shift Arithmetic1' */
  rtb_FIR1 = (real32_T)ldexp(rtb_FIR1, -4);

  /* DataTypeConversion: '<Root>/Data Type Conversion4' */
  rtb_FIR1 = (real32_T)floor(rtb_FIR1);
  if (rtIsNaNF(rtb_FIR1) || rtIsInfF(rtb_FIR1)) {
    rtb_FIR1 = 0.0F;
  } else {
    rtb_FIR1 = (real32_T)fmod(rtb_FIR1, 256.0F);
  }

  ADC_DSPIC33_DW.DataTypeConversion4 = (uint8_T)(rtb_FIR1 < 0.0F ? (int16_T)
    (uint8_T)-(int8_T)(uint8_T)-rtb_FIR1 : (int16_T)(uint8_T)rtb_FIR1);

  /* End of DataTypeConversion: '<Root>/Data Type Conversion4' */
  /* MCHP_UART_Tx Block for UARTRef 1: <Root>/UART Tx/Outputs */
  {
    uint_T Tmp;
    Tmp = ~(MCHP_UART1_Tx.tail - MCHP_UART1_Tx.head);
    Tmp = Tmp & (Tx_BUFF_SIZE_Uart1 - 1);/* Modulo Buffer Size */

    {
      register uint_T LocalTail = MCHP_UART1_Tx.tail;/* Tail is a volatile variable. Use local variable to speed-up execution */
      MCHP_UART1_Tx.buffer[LocalTail] = ADC_DSPIC33_DW.DataTypeConversion4;
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
void ADC_DSPIC33_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* states (dwork) */
  (void) memset((void *)&ADC_DSPIC33_DW, 0,
                sizeof(DW_ADC_DSPIC33_T));

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

  {
    int16_T i;

    /* InitializeConditions for DiscreteFir: '<Root>/FIR10' */
    for (i = 0; i < 10; i++) {
      ADC_DSPIC33_DW.FIR10_states[i] = 0.0F;
    }

    /* End of InitializeConditions for DiscreteFir: '<Root>/FIR10' */

    /* InitializeConditions for DiscreteFir: '<Root>/FIR25' */
    for (i = 0; i < 25; i++) {
      ADC_DSPIC33_DW.FIR25_states[i] = 0.0F;
    }

    for (i = 0; i < 40; i++) {
      /* InitializeConditions for DiscreteFir: '<Root>/FIR40' */
      ADC_DSPIC33_DW.FIR40_states[i] = 0.0F;

      /* InitializeConditions for DiscreteFir: '<Root>/FIR1' */
      ADC_DSPIC33_DW.FIR1_states[i] = 0.0F;
    }

    /* End of InitializeConditions for DiscreteFir: '<Root>/FIR25' */
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
