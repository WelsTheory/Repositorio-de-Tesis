/*
 * -------------------------------------------------------------------
 * MPLAB 16-Bit Device Blocks for Simulink v3.38.
 *
 *   Product Page:  http://www.microchip.com/SimulinkBlocks
 *           Forum: http://www.microchip.com/forums/f192.aspx
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: Programa_DSPIC.c
 *
 * Code generated for Simulink model 'Programa_DSPIC'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Thu Dec 20 15:43:44 2018
 */

#include "Programa_DSPIC.h"
#include "Programa_DSPIC_private.h"

/* Block signals and states (auto storage) */
DW_Programa_DSPIC_T Programa_DSPIC_DW;

/* Model step function */
void Programa_DSPIC_step(void)
{
  /* local block i/o variables */
  boolean_T rtb_Compare;
  boolean_T rtb_Compare_c;
  boolean_T rtb_Compare_d;
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
      Programa_DSPIC_DW.U1Rx = (uint8_T) MCHP_UART1_Rx.buffer[MCHP_UART1_Rx.head];/* Use only the 8 low bytes or RxReg */
      MCHP_UART1_Rx.head = (MCHP_UART1_Rx.head+1) & (Rx_BUFF_SIZE_Uart1-1);
      U1LastValue = Programa_DSPIC_DW.U1Rx;
    } else {
      Programa_DSPIC_DW.U1Rx = U1LastValue;
      if (U1STAbits.OERR )
        U1STAbits.OERR = 0;            /* Clear UART Rx Overload Error */
    }
  }

  /* DataStoreWrite: '<Root>/Data Store Write' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion3'
   */
  Programa_DSPIC_DW.A = Programa_DSPIC_DW.U1Rx;

  /* RelationalOperator: '<S2>/Compare' incorporates:
   *  Constant: '<S2>/Constant'
   *  Product: '<Root>/Divide1'
   *  S-Function (sfix_bitop): '<Root>/Bitwise Operator'
   */
  rtb_Compare = ((Programa_DSPIC_DW.U1Rx & 2) >> 1 == 1);

  /* S-Function (MCHP_Digital_Output_Write): '<S4>/Digital Output Write' */
  LATBbits.LATB1 = rtb_Compare;

  /* RelationalOperator: '<S1>/Compare' incorporates:
   *  Constant: '<S1>/Constant'
   *  S-Function (sfix_bitop): '<Root>/Bitwise Operator2'
   */
  rtb_Compare_c = ((Programa_DSPIC_DW.U1Rx & 1) == 1);

  /* S-Function (MCHP_Digital_Output_Write): '<S5>/Digital Output Write' */
  LATAbits.LATA1 = rtb_Compare_c;

  /* RelationalOperator: '<S3>/Compare' incorporates:
   *  Constant: '<S3>/Constant'
   *  Product: '<Root>/Divide2'
   *  S-Function (sfix_bitop): '<Root>/Bitwise Operator1'
   */
  rtb_Compare_d = ((Programa_DSPIC_DW.U1Rx & 4) >> 2 == 1);

  /* S-Function (MCHP_Digital_Output_Write): '<S6>/Digital Output Write' */
  LATBbits.LATB2 = rtb_Compare_d;

  /* MCHP_ADC Block for ADC 1: <Root>/ADC/Output */
  Programa_DSPIC_DW.ADC = ADC1BuffChannelA[0];

  /* Switch: '<Root>/Switch8' incorporates:
   *  DataStoreRead: '<Root>/Data Store Read'
   *  DataTypeConversion: '<Root>/Data Type Conversion1'
   *  S-Function (MCHP_Digital_Input): '<Root>/Digital Input'
   */
  if (PORTBbits.RB15) {
    Programa_DSPIC_DW.Switch8 = Programa_DSPIC_DW.ADC;
  } else {
    Programa_DSPIC_DW.Switch8 = Programa_DSPIC_DW.A;
  }

  /* End of Switch: '<Root>/Switch8' */

  /* DiscreteFir: '<Root>/FIR10' */
  /* Consume delay line and beginning of input samples */
  for (i = 1L; i - 1L < 1L; i++) {
    rtb_FIR10 = 0.0F;
    for (j = 0L; j < i; j++) {
      rtb_FIR10 += Programa_DSPIC_DW.Switch8 *
        Programa_DSPIC_ConstP.FIR10_Coefficients[j];
    }

    for (j = 0L; j < 11L - i; j++) {
      rtb_FIR10 += Programa_DSPIC_ConstP.FIR10_Coefficients[i + j] *
        Programa_DSPIC_DW.FIR10_states[j];
    }
  }

  /* Update delay line for next frame */
  for (i = 8L; (int16_T)i >= 0; i = (int16_T)i - 1) {
    Programa_DSPIC_DW.FIR10_states[(int32_T)(1 + (int16_T)i)] =
      Programa_DSPIC_DW.FIR10_states[i];
  }

  for (i = 1L; i - 1L < 1L; i++) {
    Programa_DSPIC_DW.FIR10_states[1L - i] = Programa_DSPIC_DW.Switch8;
  }

  /* End of DiscreteFir: '<Root>/FIR10' */

  /* DiscreteFir: '<Root>/FIR25' */
  /* Consume delay line and beginning of input samples */
  for (i = 1L; i - 1L < 1L; i++) {
    rtb_FIR25 = 0.0F;
    for (j = 0L; j < i; j++) {
      rtb_FIR25 += Programa_DSPIC_DW.Switch8 *
        Programa_DSPIC_ConstP.FIR25_Coefficients[j];
    }

    for (j = 0L; j < 26L - i; j++) {
      rtb_FIR25 += Programa_DSPIC_ConstP.FIR25_Coefficients[i + j] *
        Programa_DSPIC_DW.FIR25_states[j];
    }
  }

  /* Update delay line for next frame */
  for (i = 23L; (int16_T)i >= 0; i = (int16_T)i - 1) {
    Programa_DSPIC_DW.FIR25_states[(int32_T)(1 + (int16_T)i)] =
      Programa_DSPIC_DW.FIR25_states[i];
  }

  for (i = 1L; i - 1L < 1L; i++) {
    Programa_DSPIC_DW.FIR25_states[1L - i] = Programa_DSPIC_DW.Switch8;
  }

  /* End of DiscreteFir: '<Root>/FIR25' */

  /* DiscreteFir: '<Root>/FIR40' */
  /* Consume delay line and beginning of input samples */
  for (i = 1L; i - 1L < 1L; i++) {
    rtb_FIR40 = 0.0F;
    for (j = 0L; j < i; j++) {
      rtb_FIR40 += Programa_DSPIC_DW.Switch8 * Programa_DSPIC_ConstP.pooled2[j];
    }

    for (j = 0L; j < 41L - i; j++) {
      rtb_FIR40 += Programa_DSPIC_ConstP.pooled2[i + j] *
        Programa_DSPIC_DW.FIR40_states[j];
    }
  }

  /* Update delay line for next frame */
  for (i = 38L; (int16_T)i >= 0; i = (int16_T)i - 1) {
    Programa_DSPIC_DW.FIR40_states[(int32_T)(1 + (int16_T)i)] =
      Programa_DSPIC_DW.FIR40_states[i];
  }

  for (i = 1L; i - 1L < 1L; i++) {
    Programa_DSPIC_DW.FIR40_states[1L - i] = Programa_DSPIC_DW.Switch8;
  }

  /* End of DiscreteFir: '<Root>/FIR40' */

  /* DiscreteFir: '<Root>/FIR1' */
  /* Consume delay line and beginning of input samples */
  for (i = 1L; i - 1L < 1L; i++) {
    rtb_FIR1 = 0.0F;
    for (j = 0L; j < i; j++) {
      rtb_FIR1 += Programa_DSPIC_DW.Switch8 * Programa_DSPIC_ConstP.pooled2[j];
    }

    for (j = 0L; j < 41L - i; j++) {
      rtb_FIR1 += Programa_DSPIC_ConstP.pooled2[i + j] *
        Programa_DSPIC_DW.FIR1_states[j];
    }
  }

  /* Update delay line for next frame */
  for (i = 38L; (int16_T)i >= 0; i = (int16_T)i - 1) {
    Programa_DSPIC_DW.FIR1_states[(int32_T)(1 + (int16_T)i)] =
      Programa_DSPIC_DW.FIR1_states[i];
  }

  for (i = 1L; i - 1L < 1L; i++) {
    Programa_DSPIC_DW.FIR1_states[1L - i] = Programa_DSPIC_DW.Switch8;
  }

  /* End of DiscreteFir: '<Root>/FIR1' */

  /* Switch: '<Root>/Switch7' incorporates:
   *  Switch: '<Root>/Switch1'
   *  Switch: '<Root>/Switch6'
   */
  if (rtb_Compare_d) {
    /* Switch: '<Root>/Switch5' incorporates:
     *  Switch: '<Root>/Switch3'
     */
    if (rtb_Compare) {
      /* Switch: '<Root>/Switch4' */
      if (rtb_Compare_c) {
        rtb_FIR1 = Programa_DSPIC_DW.Switch8;
      } else {
        rtb_FIR1 = rtb_FIR10;
      }
    } else if (rtb_Compare_c) {
      /* Switch: '<Root>/Switch3' incorporates:
       *  Switch: '<Root>/Switch4'
       */
      rtb_FIR1 = Programa_DSPIC_DW.Switch8;
    } else {
      /* Switch: '<Root>/Switch4' incorporates:
       *  Switch: '<Root>/Switch3'
       */
      rtb_FIR1 = rtb_FIR25;
    }

    /* End of Switch: '<Root>/Switch5' */
  } else if (rtb_Compare) {
    /* Switch: '<Root>/Switch2' incorporates:
     *  Switch: '<Root>/Switch1'
     */
    if (rtb_Compare_c) {
      rtb_FIR1 = Programa_DSPIC_DW.Switch8;
    } else {
      rtb_FIR1 = rtb_FIR40;
    }

    /* End of Switch: '<Root>/Switch2' */
  } else {
    if (rtb_Compare_c) {
      /* Switch: '<Root>/Switch6' incorporates:
       *  Switch: '<Root>/Switch1'
       */
      rtb_FIR1 = Programa_DSPIC_DW.Switch8;
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

  Programa_DSPIC_DW.DataTypeConversion4 = (uint8_T)(rtb_FIR1 < 0.0F ? (int16_T)
    (uint8_T)-(int8_T)(uint8_T)-rtb_FIR1 : (int16_T)(uint8_T)rtb_FIR1);

  /* End of DataTypeConversion: '<Root>/Data Type Conversion4' */
  /* MCHP_UART_Tx Block for UARTRef 1: <Root>/UART Tx/Outputs */
  {
    uint_T Tmp;
    Tmp = ~(MCHP_UART1_Tx.tail - MCHP_UART1_Tx.head);
    Tmp = Tmp & (Tx_BUFF_SIZE_Uart1 - 1);/* Modulo Buffer Size */

    {
      register uint_T LocalTail = MCHP_UART1_Tx.tail;/* Tail is a volatile variable. Use local variable to speed-up execution */
      MCHP_UART1_Tx.buffer[LocalTail] = Programa_DSPIC_DW.DataTypeConversion4;
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
void Programa_DSPIC_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* states (dwork) */
  (void) memset((void *)&Programa_DSPIC_DW, 0,
                sizeof(DW_Programa_DSPIC_T));

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
      Programa_DSPIC_DW.FIR10_states[i] = 0.0F;
    }

    /* End of InitializeConditions for DiscreteFir: '<Root>/FIR10' */

    /* InitializeConditions for DiscreteFir: '<Root>/FIR25' */
    memset(&Programa_DSPIC_DW.FIR25_states[0L], (int16_T)0.0F, 25U * sizeof
           (real32_T));
    for (i = 0; i < 40; i++) {
      /* InitializeConditions for DiscreteFir: '<Root>/FIR40' */
      Programa_DSPIC_DW.FIR40_states[i] = 0.0F;

      /* InitializeConditions for DiscreteFir: '<Root>/FIR1' */
      Programa_DSPIC_DW.FIR1_states[i] = 0.0F;
    }
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
