/*
 * -------------------------------------------------------------------
 * MPLAB 16-Bit Device Blocks for Simulink v3.38.
 *
 *   Product Page:  http://www.microchip.com/SimulinkBlocks
 *           Forum: http://www.microchip.com/forums/f192.aspx
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: Tesis_Simulink.c
 *
 * Code generated for Simulink model 'Tesis_Simulink'.
 *
 * Model version                  : 1.69
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Mon Feb 18 04:35:22 2019
 */

#include "Tesis_Simulink.h"
#include "Tesis_Simulink_private.h"

/* Block signals and states (auto storage) */
DW_Tesis_Simulink_T Tesis_Simulink_DW;

/* Model step function */
void Tesis_Simulink_step(void)
{
  /* local block i/o variables */
  boolean_T rtb_Compare;
  int32_T i;
  int32_T j;
  boolean_T rtb_Compare_m;
  real32_T rtb_DataTypeConversion7;
  real32_T rtb_Filter_PB40_5orden;
  real32_T rtb_Filter_PA05_5orden;
  real32_T rtb_Filter_PA05_10orden;
  real32_T rtb_Filter_0540_30orden;

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
      Tesis_Simulink_DW.U1Rx = (uint8_T) MCHP_UART1_Rx.buffer[MCHP_UART1_Rx.head];/* Use only the 8 low bytes or RxReg */
      MCHP_UART1_Rx.head = (MCHP_UART1_Rx.head+1) & (Rx_BUFF_SIZE_Uart1-1);
      U1LastValue = Tesis_Simulink_DW.U1Rx;
    } else {
      Tesis_Simulink_DW.U1Rx = U1LastValue;
      if (U1STAbits.OERR )
        U1STAbits.OERR = 0;            /* Clear UART Rx Overload Error */
    }
  }

  /* RelationalOperator: '<S1>/Compare' incorporates:
   *  Constant: '<S1>/Constant'
   *  S-Function (sfix_bitop): '<Root>/Bitwise Operator2'
   */
  rtb_Compare = ((Tesis_Simulink_DW.U1Rx & 1) == 1);

  /* S-Function (MCHP_Digital_Output_Write): '<S4>/Digital Output Write' */
  LATAbits.LATA1 = rtb_Compare;

  /* MCHP_ADC Block for ADC 1: <Root>/ADC/Output */
  Tesis_Simulink_DW.ADC = ADC1BuffChannelA[0];

  /* DataTypeConversion: '<Root>/Data Type Conversion2' */
  Tesis_Simulink_DW.DataTypeConversion2 = Tesis_Simulink_DW.ADC;

  /* DiscreteFir: '<Root>/Filter_PB40_5orden' */
  /* Consume delay line and beginning of input samples */
  for (i = 1L; i - 1L < 1L; i++) {
    rtb_Filter_PB40_5orden = 0.0F;
    for (j = 0L; j < i; j++) {
      rtb_Filter_PB40_5orden += Tesis_Simulink_DW.DataTypeConversion2 *
        Tesis_Simulink_ConstP.Filter_PB40_5orden_Coefficients[j];
    }

    for (j = 0L; j < 6L - i; j++) {
      rtb_Filter_PB40_5orden +=
        Tesis_Simulink_ConstP.Filter_PB40_5orden_Coefficients[i + j] *
        Tesis_Simulink_DW.Filter_PB40_5orden_states[j];
    }
  }

  /* Update delay line for next frame */
  for (i = 3L; (int16_T)i >= 0; i = (int16_T)i - 1) {
    Tesis_Simulink_DW.Filter_PB40_5orden_states[(int32_T)(1 + (int16_T)i)] =
      Tesis_Simulink_DW.Filter_PB40_5orden_states[i];
  }

  for (i = 1L; i - 1L < 1L; i++) {
    Tesis_Simulink_DW.Filter_PB40_5orden_states[1L - i] =
      Tesis_Simulink_DW.DataTypeConversion2;
  }

  /* End of DiscreteFir: '<Root>/Filter_PB40_5orden' */

  /* DataTypeConversion: '<Root>/Data Type Conversion7' incorporates:
   *  Constant: '<S3>/Constant'
   *  Product: '<Root>/Divide2'
   *  RelationalOperator: '<S3>/Compare'
   *  S-Function (sfix_bitop): '<Root>/Bitwise Operator1'
   */
  rtb_DataTypeConversion7 = ((Tesis_Simulink_DW.U1Rx & 4) >> 2 == 1);

  /* RelationalOperator: '<S2>/Compare' incorporates:
   *  Constant: '<S2>/Constant'
   *  Product: '<Root>/Divide1'
   *  S-Function (sfix_bitop): '<Root>/Bitwise Operator'
   */
  rtb_Compare_m = ((Tesis_Simulink_DW.U1Rx & 2) >> 1 == 1);

  /* DiscreteFir: '<Root>/Filter_PA05_5orden' */
  /* Consume delay line and beginning of input samples */
  for (i = 1L; i - 1L < 1L; i++) {
    rtb_Filter_PA05_5orden = 0.0F;
    for (j = 0L; j < i; j++) {
      rtb_Filter_PA05_5orden += Tesis_Simulink_DW.DataTypeConversion2 *
        Tesis_Simulink_ConstP.Filter_PA05_5orden_Coefficients[j];
    }

    for (j = 0L; j < 6L - i; j++) {
      rtb_Filter_PA05_5orden +=
        Tesis_Simulink_ConstP.Filter_PA05_5orden_Coefficients[i + j] *
        Tesis_Simulink_DW.Filter_PA05_5orden_states[j];
    }
  }

  /* Update delay line for next frame */
  for (i = 3L; (int16_T)i >= 0; i = (int16_T)i - 1) {
    Tesis_Simulink_DW.Filter_PA05_5orden_states[(int32_T)(1 + (int16_T)i)] =
      Tesis_Simulink_DW.Filter_PA05_5orden_states[i];
  }

  for (i = 1L; i - 1L < 1L; i++) {
    Tesis_Simulink_DW.Filter_PA05_5orden_states[1L - i] =
      Tesis_Simulink_DW.DataTypeConversion2;
  }

  /* End of DiscreteFir: '<Root>/Filter_PA05_5orden' */

  /* DiscreteFir: '<Root>/Filter_PA05_10orden' */
  /* Consume delay line and beginning of input samples */
  for (i = 1L; i - 1L < 1L; i++) {
    rtb_Filter_PA05_10orden = 0.0F;
    for (j = 0L; j < i; j++) {
      rtb_Filter_PA05_10orden += Tesis_Simulink_DW.DataTypeConversion2 *
        Tesis_Simulink_ConstP.Filter_PA05_10orden_Coefficients[j];
    }

    for (j = 0L; j < 11L - i; j++) {
      rtb_Filter_PA05_10orden +=
        Tesis_Simulink_ConstP.Filter_PA05_10orden_Coefficients[i + j] *
        Tesis_Simulink_DW.Filter_PA05_10orden_states[j];
    }
  }

  /* Update delay line for next frame */
  for (i = 8L; (int16_T)i >= 0; i = (int16_T)i - 1) {
    Tesis_Simulink_DW.Filter_PA05_10orden_states[(int32_T)(1 + (int16_T)i)] =
      Tesis_Simulink_DW.Filter_PA05_10orden_states[i];
  }

  for (i = 1L; i - 1L < 1L; i++) {
    Tesis_Simulink_DW.Filter_PA05_10orden_states[1L - i] =
      Tesis_Simulink_DW.DataTypeConversion2;
  }

  /* End of DiscreteFir: '<Root>/Filter_PA05_10orden' */

  /* DiscreteFir: '<Root>/Filter_0540_30orden' */
  /* Consume delay line and beginning of input samples */
  for (i = 1L; i - 1L < 1L; i++) {
    rtb_Filter_0540_30orden = 0.0F;
    for (j = 0L; j < i; j++) {
      rtb_Filter_0540_30orden += Tesis_Simulink_DW.DataTypeConversion2 *
        Tesis_Simulink_ConstP.Filter_0540_30orden_Coefficients[j];
    }

    for (j = 0L; j < 31L - i; j++) {
      rtb_Filter_0540_30orden +=
        Tesis_Simulink_ConstP.Filter_0540_30orden_Coefficients[i + j] *
        Tesis_Simulink_DW.Filter_0540_30orden_states[j];
    }
  }

  /* Update delay line for next frame */
  for (i = 28L; (int16_T)i >= 0; i = (int16_T)i - 1) {
    Tesis_Simulink_DW.Filter_0540_30orden_states[(int32_T)(1 + (int16_T)i)] =
      Tesis_Simulink_DW.Filter_0540_30orden_states[i];
  }

  for (i = 1L; i - 1L < 1L; i++) {
    Tesis_Simulink_DW.Filter_0540_30orden_states[1L - i] =
      Tesis_Simulink_DW.DataTypeConversion2;
  }

  /* End of DiscreteFir: '<Root>/Filter_0540_30orden' */

  /* Switch: '<Root>/Switch7' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion6'
   *  Switch: '<Root>/Switch1'
   *  Switch: '<Root>/Switch6'
   */
  if (rtb_Compare) {
    /* Switch: '<Root>/Switch5' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion6'
     *  Switch: '<Root>/Switch3'
     */
    if (rtb_Compare_m) {
      /* Switch: '<Root>/Switch4' */
      if (rtb_DataTypeConversion7 != 0.0F) {
        rtb_DataTypeConversion7 = rtb_Filter_PB40_5orden;
      } else {
        rtb_DataTypeConversion7 = Tesis_Simulink_DW.DataTypeConversion2;
      }
    } else if (rtb_DataTypeConversion7 != 0.0F) {
      /* Switch: '<Root>/Switch3' incorporates:
       *  Switch: '<Root>/Switch4'
       */
      rtb_DataTypeConversion7 = Tesis_Simulink_DW.DataTypeConversion2;
    } else {
      /* Switch: '<Root>/Switch4' incorporates:
       *  Switch: '<Root>/Switch3'
       */
      rtb_DataTypeConversion7 = rtb_Filter_PA05_5orden;
    }
  } else if (rtb_Compare_m) {
    /* Switch: '<Root>/Switch2' incorporates:
     *  Switch: '<Root>/Switch1'
     */
    if (rtb_DataTypeConversion7 != 0.0F) {
      /* Switch: '<Root>/Switch4' incorporates:
       *  Switch: '<Root>/Switch5'
       */
      rtb_DataTypeConversion7 = rtb_Filter_PA05_10orden;
    } else {
      /* Switch: '<Root>/Switch4' incorporates:
       *  Switch: '<Root>/Switch5'
       */
      rtb_DataTypeConversion7 = Tesis_Simulink_DW.DataTypeConversion2;
    }

    /* End of Switch: '<Root>/Switch2' */
  } else if (rtb_DataTypeConversion7 != 0.0F) {
    /* Switch: '<Root>/Switch6' incorporates:
     *  Switch: '<Root>/Switch1'
     *  Switch: '<Root>/Switch4'
     *  Switch: '<Root>/Switch5'
     */
    rtb_DataTypeConversion7 = rtb_Filter_0540_30orden;
  } else {
    /* Switch: '<Root>/Switch4' incorporates:
     *  Switch: '<Root>/Switch1'
     *  Switch: '<Root>/Switch5'
     *  Switch: '<Root>/Switch6'
     */
    rtb_DataTypeConversion7 = Tesis_Simulink_DW.DataTypeConversion2;
  }

  /* End of Switch: '<Root>/Switch7' */

  /* ArithShift: '<Root>/Shift Arithmetic1' */
  rtb_DataTypeConversion7 = (real32_T)ldexp(rtb_DataTypeConversion7, -4);

  /* DataTypeConversion: '<Root>/Data Type Conversion4' */
  rtb_DataTypeConversion7 = (real32_T)floor(rtb_DataTypeConversion7);
  if (rtIsNaNF(rtb_DataTypeConversion7) || rtIsInfF(rtb_DataTypeConversion7)) {
    rtb_DataTypeConversion7 = 0.0F;
  } else {
    rtb_DataTypeConversion7 = (real32_T)fmod(rtb_DataTypeConversion7, 256.0F);
  }

  Tesis_Simulink_DW.DataTypeConversion4 = (uint8_T)(rtb_DataTypeConversion7 <
    0.0F ? (int16_T)(uint8_T)-(int8_T)(uint8_T)-rtb_DataTypeConversion7 :
    (int16_T)(uint8_T)rtb_DataTypeConversion7);

  /* End of DataTypeConversion: '<Root>/Data Type Conversion4' */
  /* MCHP_UART_Tx Block for UARTRef 1: <Root>/UART Tx/Outputs */
  {
    uint_T Tmp;
    Tmp = ~(MCHP_UART1_Tx.tail - MCHP_UART1_Tx.head);
    Tmp = Tmp & (Tx_BUFF_SIZE_Uart1 - 1);/* Modulo Buffer Size */

    {
      register uint_T LocalTail = MCHP_UART1_Tx.tail;/* Tail is a volatile variable. Use local variable to speed-up execution */
      MCHP_UART1_Tx.buffer[LocalTail] = Tesis_Simulink_DW.DataTypeConversion4;
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
void Tesis_Simulink_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* states (dwork) */
  (void) memset((void *)&Tesis_Simulink_DW, 0,
                sizeof(DW_Tesis_Simulink_T));

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
    for (i = 0; i < 5; i++) {
      /* InitializeConditions for DiscreteFir: '<Root>/Filter_PB40_5orden' */
      Tesis_Simulink_DW.Filter_PB40_5orden_states[i] = 0.0F;

      /* InitializeConditions for DiscreteFir: '<Root>/Filter_PA05_5orden' */
      Tesis_Simulink_DW.Filter_PA05_5orden_states[i] = 0.0F;
    }

    /* InitializeConditions for DiscreteFir: '<Root>/Filter_PA05_10orden' */
    for (i = 0; i < 10; i++) {
      Tesis_Simulink_DW.Filter_PA05_10orden_states[i] = 0.0F;
    }

    /* End of InitializeConditions for DiscreteFir: '<Root>/Filter_PA05_10orden' */

    /* InitializeConditions for DiscreteFir: '<Root>/Filter_0540_30orden' */
    memset(&Tesis_Simulink_DW.Filter_0540_30orden_states[0L], (int16_T)0.0F, 30U
           * sizeof(real32_T));
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
