/*
 * -------------------------------------------------------------------
 * MPLAB 16-Bit Device Blocks for Simulink v3.38.
 *
 *   Product Page:  http://www.microchip.com/SimulinkBlocks
 *           Forum: http://www.microchip.com/forums/f192.aspx
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: Prueba_ADC.c
 *
 * Code generated for Simulink model 'Prueba_ADC'.
 *
 * Model version                  : 1.43
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Mon Feb 18 00:49:58 2019
 */

#include "Prueba_ADC.h"
#include "Prueba_ADC_private.h"

/* Block signals and states (auto storage) */
DW_Prueba_ADC_T Prueba_ADC_DW;

/* Model step function */
void Prueba_ADC_step(void)
{
  /* local block i/o variables */
  boolean_T rtb_Compare;
  int32_T i;
  int32_T j;
  real32_T rtb_DataTypeConversion7;
  real32_T rtb_Filter_0540_HP_1;
  real32_T rtb_Filter_40_HP_50;

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
      Prueba_ADC_DW.U1Rx = (uint8_T) MCHP_UART1_Rx.buffer[MCHP_UART1_Rx.head];/* Use only the 8 low bytes or RxReg */
      MCHP_UART1_Rx.head = (MCHP_UART1_Rx.head+1) & (Rx_BUFF_SIZE_Uart1-1);
      U1LastValue = Prueba_ADC_DW.U1Rx;
    } else {
      Prueba_ADC_DW.U1Rx = U1LastValue;
      if (U1STAbits.OERR )
        U1STAbits.OERR = 0;            /* Clear UART Rx Overload Error */
    }
  }

  /* RelationalOperator: '<S1>/Compare' incorporates:
   *  Constant: '<S1>/Constant'
   *  S-Function (sfix_bitop): '<Root>/Bitwise Operator2'
   */
  rtb_Compare = ((Prueba_ADC_DW.U1Rx & 1) == 1);

  /* S-Function (MCHP_Digital_Output_Write): '<S3>/Digital Output Write' */
  LATAbits.LATA1 = rtb_Compare;

  /* MCHP_ADC Block for ADC 1: <Root>/ADC1/Output */
  Prueba_ADC_DW.ADC1 = ADC1BuffChannelA[0];

  /* DataTypeConversion: '<Root>/Data Type Conversion3' */
  Prueba_ADC_DW.DataTypeConversion3 = Prueba_ADC_DW.ADC1;

  /* DiscreteFir: '<Root>/Filter_0540_HP_1' */
  /* Consume delay line and beginning of input samples */
  for (i = 1L; i - 1L < 1L; i++) {
    rtb_Filter_0540_HP_1 = 0.0F;
    for (j = 0L; j < i; j++) {
      rtb_Filter_0540_HP_1 += Prueba_ADC_DW.DataTypeConversion3 *
        Prueba_ADC_ConstP.Filter_0540_HP_1_Coefficients[j];
    }

    for (j = 0L; j < 51L - i; j++) {
      rtb_Filter_0540_HP_1 += Prueba_ADC_ConstP.Filter_0540_HP_1_Coefficients[i
        + j] * Prueba_ADC_DW.Filter_0540_HP_1_states[j];
    }
  }

  /* Update delay line for next frame */
  for (i = 48L; (int16_T)i >= 0; i = (int16_T)i - 1) {
    Prueba_ADC_DW.Filter_0540_HP_1_states[(int32_T)(1 + (int16_T)i)] =
      Prueba_ADC_DW.Filter_0540_HP_1_states[i];
  }

  for (i = 1L; i - 1L < 1L; i++) {
    Prueba_ADC_DW.Filter_0540_HP_1_states[1L - i] =
      Prueba_ADC_DW.DataTypeConversion3;
  }

  /* End of DiscreteFir: '<Root>/Filter_0540_HP_1' */

  /* DataTypeConversion: '<Root>/Data Type Conversion7' incorporates:
   *  Constant: '<S2>/Constant'
   *  Product: '<Root>/Divide1'
   *  RelationalOperator: '<S2>/Compare'
   *  S-Function (sfix_bitop): '<Root>/Bitwise Operator'
   */
  rtb_DataTypeConversion7 = ((Prueba_ADC_DW.U1Rx & 2) >> 1 == 1);

  /* DiscreteFir: '<Root>/Filter_40_HP_50' */
  /* Consume delay line and beginning of input samples */
  for (i = 1L; i - 1L < 1L; i++) {
    rtb_Filter_40_HP_50 = 0.0F;
    for (j = 0L; j < i; j++) {
      rtb_Filter_40_HP_50 += Prueba_ADC_DW.DataTypeConversion3 *
        Prueba_ADC_ConstP.Filter_40_HP_50_Coefficients[j];
    }

    for (j = 0L; j < 51L - i; j++) {
      rtb_Filter_40_HP_50 += Prueba_ADC_ConstP.Filter_40_HP_50_Coefficients[i +
        j] * Prueba_ADC_DW.Filter_40_HP_50_states[j];
    }
  }

  /* Update delay line for next frame */
  for (i = 48L; (int16_T)i >= 0; i = (int16_T)i - 1) {
    Prueba_ADC_DW.Filter_40_HP_50_states[(int32_T)(1 + (int16_T)i)] =
      Prueba_ADC_DW.Filter_40_HP_50_states[i];
  }

  for (i = 1L; i - 1L < 1L; i++) {
    Prueba_ADC_DW.Filter_40_HP_50_states[1L - i] =
      Prueba_ADC_DW.DataTypeConversion3;
  }

  /* End of DiscreteFir: '<Root>/Filter_40_HP_50' */

  /* Switch: '<Root>/Switch7' incorporates:
   *  Switch: '<Root>/Switch1'
   */
  if (rtb_Compare) {
    /* Switch: '<Root>/Switch5' */
    if (rtb_DataTypeConversion7 != 0.0F) {
      rtb_DataTypeConversion7 = rtb_Filter_0540_HP_1;
    } else {
      rtb_DataTypeConversion7 = Prueba_ADC_DW.DataTypeConversion3;
    }
  } else if (rtb_DataTypeConversion7 != 0.0F) {
    /* Switch: '<Root>/Switch1' incorporates:
     *  Switch: '<Root>/Switch5'
     */
    rtb_DataTypeConversion7 = Prueba_ADC_DW.DataTypeConversion3;
  } else {
    /* Switch: '<Root>/Switch5' incorporates:
     *  Switch: '<Root>/Switch1'
     */
    rtb_DataTypeConversion7 = rtb_Filter_40_HP_50;
  }

  /* End of Switch: '<Root>/Switch7' */

  /* ArithShift: '<Root>/Shift Arithmetic1' */
  rtb_DataTypeConversion7 = (real32_T)ldexp(rtb_DataTypeConversion7, -4);

  /* DataTypeConversion: '<Root>/Data Type Conversion5' */
  rtb_DataTypeConversion7 = (real32_T)floor(rtb_DataTypeConversion7);
  if (rtIsNaNF(rtb_DataTypeConversion7) || rtIsInfF(rtb_DataTypeConversion7)) {
    rtb_DataTypeConversion7 = 0.0F;
  } else {
    rtb_DataTypeConversion7 = (real32_T)fmod(rtb_DataTypeConversion7, 256.0F);
  }

  Prueba_ADC_DW.DataTypeConversion5 = (uint8_T)(rtb_DataTypeConversion7 < 0.0F ?
    (int16_T)(uint8_T)-(int8_T)(uint8_T)-rtb_DataTypeConversion7 : (int16_T)
    (uint8_T)rtb_DataTypeConversion7);

  /* End of DataTypeConversion: '<Root>/Data Type Conversion5' */
  /* MCHP_UART_Tx Block for UARTRef 1: <Root>/UART Tx/Outputs */
  {
    uint_T Tmp;
    Tmp = ~(MCHP_UART1_Tx.tail - MCHP_UART1_Tx.head);
    Tmp = Tmp & (Tx_BUFF_SIZE_Uart1 - 1);/* Modulo Buffer Size */

    {
      register uint_T LocalTail = MCHP_UART1_Tx.tail;/* Tail is a volatile variable. Use local variable to speed-up execution */
      MCHP_UART1_Tx.buffer[LocalTail] = Prueba_ADC_DW.DataTypeConversion5;
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
void Prueba_ADC_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* states (dwork) */
  (void) memset((void *)&Prueba_ADC_DW, 0,
                sizeof(DW_Prueba_ADC_T));

  /* S-Function "Microchip MASTER" initialization Block: <Root>/Microchip Master */

  /* MCHP_ADC Block for ADC 1: <Root>/ADC1/Initialize */
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
    for (i = 0; i < 50; i++) {
      /* InitializeConditions for DiscreteFir: '<Root>/Filter_0540_HP_1' */
      Prueba_ADC_DW.Filter_0540_HP_1_states[i] = 0.0F;

      /* InitializeConditions for DiscreteFir: '<Root>/Filter_40_HP_50' */
      Prueba_ADC_DW.Filter_40_HP_50_states[i] = 0.0F;
    }
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
