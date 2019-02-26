/*
 * -------------------------------------------------------------------
 * MPLAB 16-Bit Device Blocks for Simulink v3.38.
 *
 *   Product Page:  http://www.microchip.com/SimulinkBlocks
 *           Forum: http://www.microchip.com/forums/f192.aspx
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: Ejemplo_de_Programa_principal.c
 *
 * Code generated for Simulink model 'Ejemplo_de_Programa_principal'.
 *
 * Model version                  : 1.89
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Feb 26 06:30:36 2019
 */

#include "Ejemplo_de_Programa_principal.h"
#include "Ejemplo_de_Programa_principal_private.h"

/* Block signals and states (auto storage) */
DW_Ejemplo_de_Programa_principal_T Ejemplo_de_Programa_principal_DW;

/* Model step function */
void Ejemplo_de_Programa_principal_step(void)
{
  /* local block i/o variables */
  uint16_T rtb_DataTypeConversion4;
  boolean_T rtb_Compare;
  int32_T i;
  int32_T j;
  boolean_T rtb_Compare_m;
  real32_T rtb_DataTypeConversion7;
  real32_T rtb_Filter;
  real32_T rtb_Filter1;
  real32_T rtb_Filter2;
  real32_T rtb_Filter3;
  real32_T rtb_Filter4;
  real32_T rtb_Filter5;
  real32_T rtb_Filter6;

  /* MCHP_ADC Block for ADC 1: <Root>/ADC/Output */
  Ejemplo_de_Programa_principal_DW.ADC = ADC1BuffChannelA[0];

  /* DataTypeConversion: '<Root>/Data Type Conversion2' */
  Ejemplo_de_Programa_principal_DW.DataTypeConversion2 =
    Ejemplo_de_Programa_principal_DW.ADC;

  /* DiscreteFir: '<S3>/Filter' */
  /* Consume delay line and beginning of input samples */
  for (i = 1L; i - 1L < 1L; i++) {
    rtb_Filter = 0.0F;
    for (j = 0L; j < i; j++) {
      rtb_Filter += Ejemplo_de_Programa_principal_DW.DataTypeConversion2 * 0.5F;
    }

    for (j = 0L; j < 2L - i; j++) {
      rtb_Filter += Ejemplo_de_Programa_principal_DW.Filter_states * 0.5F;
    }
  }

  /* Update delay line for next frame */
  i = 0L;
  while ((int16_T)i < 1) {
    Ejemplo_de_Programa_principal_DW.Filter_states =
      Ejemplo_de_Programa_principal_DW.DataTypeConversion2;
    i = 1L;
  }

  /* End of DiscreteFir: '<S3>/Filter' */

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
      Ejemplo_de_Programa_principal_DW.U1Rx = (uint8_T)
        MCHP_UART1_Rx.buffer[MCHP_UART1_Rx.head];/* Use only the 8 low bytes or RxReg */
      MCHP_UART1_Rx.head = (MCHP_UART1_Rx.head+1) & (Rx_BUFF_SIZE_Uart1-1);
      U1LastValue = Ejemplo_de_Programa_principal_DW.U1Rx;
    } else {
      Ejemplo_de_Programa_principal_DW.U1Rx = U1LastValue;
      if (U1STAbits.OERR )
        U1STAbits.OERR = 0;            /* Clear UART Rx Overload Error */
    }
  }

  /* DataTypeConversion: '<S5>/Data Type Conversion7' incorporates:
   *  Constant: '<S10>/Constant'
   *  Product: '<S5>/Divide2'
   *  RelationalOperator: '<S10>/Compare'
   *  S-Function (sfix_bitop): '<S5>/Bitwise Operator1'
   */
  rtb_DataTypeConversion7 = ((Ejemplo_de_Programa_principal_DW.U1Rx & 4) >> 2 ==
    1);

  /* DiscreteFir: '<S3>/Filter1' */
  /* Consume delay line and beginning of input samples */
  while (i - 1L < 1L) {
    rtb_Filter1 = 0.0F;
    for (j = 0L; j < i; j++) {
      rtb_Filter1 += Ejemplo_de_Programa_principal_DW.DataTypeConversion2 * 0.5F;
    }

    for (j = 0L; j < 2L - i; j++) {
      rtb_Filter1 += Ejemplo_de_Programa_principal_DW.Filter1_states * 0.5F;
    }

    i++;
  }

  /* Update delay line for next frame */
  i = 0L;
  while ((int16_T)i < 1) {
    Ejemplo_de_Programa_principal_DW.Filter1_states =
      Ejemplo_de_Programa_principal_DW.DataTypeConversion2;
    i = 1L;
  }

  /* End of DiscreteFir: '<S3>/Filter1' */

  /* RelationalOperator: '<S9>/Compare' incorporates:
   *  Constant: '<S9>/Constant'
   *  Product: '<S5>/Divide1'
   *  S-Function (sfix_bitop): '<S5>/Bitwise Operator'
   */
  rtb_Compare_m = ((Ejemplo_de_Programa_principal_DW.U1Rx & 2) >> 1 == 1);

  /* DiscreteFir: '<S3>/Filter2' */
  /* Consume delay line and beginning of input samples */
  while (i - 1L < 1L) {
    rtb_Filter2 = 0.0F;
    for (j = 0L; j < i; j++) {
      rtb_Filter2 += Ejemplo_de_Programa_principal_DW.DataTypeConversion2 * 0.5F;
    }

    for (j = 0L; j < 2L - i; j++) {
      rtb_Filter2 += Ejemplo_de_Programa_principal_DW.Filter2_states * 0.5F;
    }

    i++;
  }

  /* Update delay line for next frame */
  i = 0L;
  while ((int16_T)i < 1) {
    Ejemplo_de_Programa_principal_DW.Filter2_states =
      Ejemplo_de_Programa_principal_DW.DataTypeConversion2;
    i = 1L;
  }

  /* End of DiscreteFir: '<S3>/Filter2' */

  /* DiscreteFir: '<S3>/Filter3' */
  /* Consume delay line and beginning of input samples */
  while (i - 1L < 1L) {
    rtb_Filter3 = 0.0F;
    for (j = 0L; j < i; j++) {
      rtb_Filter3 += Ejemplo_de_Programa_principal_DW.DataTypeConversion2 * 0.5F;
    }

    for (j = 0L; j < 2L - i; j++) {
      rtb_Filter3 += Ejemplo_de_Programa_principal_DW.Filter3_states * 0.5F;
    }

    i++;
  }

  /* Update delay line for next frame */
  i = 0L;
  while ((int16_T)i < 1) {
    Ejemplo_de_Programa_principal_DW.Filter3_states =
      Ejemplo_de_Programa_principal_DW.DataTypeConversion2;
    i = 1L;
  }

  /* End of DiscreteFir: '<S3>/Filter3' */

  /* RelationalOperator: '<S8>/Compare' incorporates:
   *  Constant: '<S8>/Constant'
   *  S-Function (sfix_bitop): '<S5>/Bitwise Operator2'
   */
  rtb_Compare = ((Ejemplo_de_Programa_principal_DW.U1Rx & 1) == 1);

  /* DiscreteFir: '<S3>/Filter4' */
  /* Consume delay line and beginning of input samples */
  while (i - 1L < 1L) {
    rtb_Filter4 = 0.0F;
    for (j = 0L; j < i; j++) {
      rtb_Filter4 += Ejemplo_de_Programa_principal_DW.DataTypeConversion2 * 0.5F;
    }

    for (j = 0L; j < 2L - i; j++) {
      rtb_Filter4 += Ejemplo_de_Programa_principal_DW.Filter4_states * 0.5F;
    }

    i++;
  }

  /* Update delay line for next frame */
  i = 0L;
  while ((int16_T)i < 1) {
    Ejemplo_de_Programa_principal_DW.Filter4_states =
      Ejemplo_de_Programa_principal_DW.DataTypeConversion2;
    i = 1L;
  }

  /* End of DiscreteFir: '<S3>/Filter4' */

  /* DiscreteFir: '<S3>/Filter5' */
  /* Consume delay line and beginning of input samples */
  while (i - 1L < 1L) {
    rtb_Filter5 = 0.0F;
    for (j = 0L; j < i; j++) {
      rtb_Filter5 += Ejemplo_de_Programa_principal_DW.DataTypeConversion2 * 0.5F;
    }

    for (j = 0L; j < 2L - i; j++) {
      rtb_Filter5 += Ejemplo_de_Programa_principal_DW.Filter5_states * 0.5F;
    }

    i++;
  }

  /* Update delay line for next frame */
  i = 0L;
  while ((int16_T)i < 1) {
    Ejemplo_de_Programa_principal_DW.Filter5_states =
      Ejemplo_de_Programa_principal_DW.DataTypeConversion2;
    i = 1L;
  }

  /* End of DiscreteFir: '<S3>/Filter5' */

  /* DiscreteFir: '<S3>/Filter6' */
  /* Consume delay line and beginning of input samples */
  while (i - 1L < 1L) {
    rtb_Filter6 = 0.0F;
    for (j = 0L; j < i; j++) {
      rtb_Filter6 += Ejemplo_de_Programa_principal_DW.DataTypeConversion2 * 0.5F;
    }

    for (j = 0L; j < 2L - i; j++) {
      rtb_Filter6 += Ejemplo_de_Programa_principal_DW.Filter6_states * 0.5F;
    }

    i++;
  }

  /* Update delay line for next frame */
  i = 0L;
  while ((int16_T)i < 1) {
    Ejemplo_de_Programa_principal_DW.Filter6_states =
      Ejemplo_de_Programa_principal_DW.DataTypeConversion2;
    i = 1L;
  }

  /* End of DiscreteFir: '<S3>/Filter6' */

  /* Switch: '<S6>/Switch7' incorporates:
   *  DataTypeConversion: '<S5>/Data Type Conversion6'
   *  Switch: '<S6>/Switch1'
   *  Switch: '<S6>/Switch6'
   */
  if (rtb_Compare) {
    /* Switch: '<S6>/Switch5' incorporates:
     *  DataTypeConversion: '<S5>/Data Type Conversion6'
     *  Switch: '<S6>/Switch3'
     */
    if (rtb_Compare_m) {
      /* Switch: '<S6>/Switch4' */
      if (rtb_DataTypeConversion7 != 0.0F) {
        rtb_DataTypeConversion7 = rtb_Filter;
      } else {
        rtb_DataTypeConversion7 = rtb_Filter1;
      }
    } else if (rtb_DataTypeConversion7 != 0.0F) {
      /* Switch: '<S6>/Switch3' incorporates:
       *  Switch: '<S6>/Switch4'
       */
      rtb_DataTypeConversion7 = rtb_Filter2;
    } else {
      /* Switch: '<S6>/Switch4' incorporates:
       *  Switch: '<S6>/Switch3'
       */
      rtb_DataTypeConversion7 = rtb_Filter3;
    }
  } else if (rtb_Compare_m) {
    /* Switch: '<S6>/Switch2' incorporates:
     *  Switch: '<S6>/Switch1'
     */
    if (rtb_DataTypeConversion7 != 0.0F) {
      /* Switch: '<S6>/Switch4' incorporates:
       *  Switch: '<S6>/Switch5'
       */
      rtb_DataTypeConversion7 = rtb_Filter4;
    } else {
      /* Switch: '<S6>/Switch4' incorporates:
       *  Switch: '<S6>/Switch5'
       */
      rtb_DataTypeConversion7 = rtb_Filter5;
    }

    /* End of Switch: '<S6>/Switch2' */
  } else if (rtb_DataTypeConversion7 != 0.0F) {
    /* Switch: '<S6>/Switch6' incorporates:
     *  Switch: '<S6>/Switch1'
     *  Switch: '<S6>/Switch4'
     *  Switch: '<S6>/Switch5'
     */
    rtb_DataTypeConversion7 = rtb_Filter6;
  } else {
    /* Switch: '<S6>/Switch4' incorporates:
     *  Switch: '<S6>/Switch1'
     *  Switch: '<S6>/Switch5'
     *  Switch: '<S6>/Switch6'
     */
    rtb_DataTypeConversion7 =
      Ejemplo_de_Programa_principal_DW.DataTypeConversion2;
  }

  /* End of Switch: '<S6>/Switch7' */

  /* DataStoreWrite: '<S7>/Data Store Write' */
  Ejemplo_de_Programa_principal_DW.A = rtb_DataTypeConversion7;

  /* ArithShift: '<S7>/Shift Arithmetic2' */
  rtb_DataTypeConversion7 = (real32_T)ldexp(rtb_DataTypeConversion7, -4);

  /* DataTypeConversion: '<S7>/Data Type Conversion1' */
  rtb_DataTypeConversion7 = (real32_T)floor(rtb_DataTypeConversion7);
  if (rtIsNaNF(rtb_DataTypeConversion7) || rtIsInfF(rtb_DataTypeConversion7)) {
    rtb_DataTypeConversion7 = 0.0F;
  } else {
    rtb_DataTypeConversion7 = (real32_T)fmod(rtb_DataTypeConversion7, 256.0F);
  }

  Ejemplo_de_Programa_principal_DW.DataTypeConversion1 = (uint8_T)
    (rtb_DataTypeConversion7 < 0.0F ? (int16_T)(uint8_T)-(int8_T)(uint8_T)
     -rtb_DataTypeConversion7 : (int16_T)(uint8_T)rtb_DataTypeConversion7);

  /* End of DataTypeConversion: '<S7>/Data Type Conversion1' */

  /* S-Function (MCHP_Digital_Output_Write): '<S2>/Digital Output Write' */
  LATAbits.LATA1 = rtb_Compare;

  /* MCHP_UART_Tx Block for UARTRef 1: <Root>/UART Tx/Outputs */
  {
    uint_T Tmp;
    Tmp = ~(MCHP_UART1_Tx.tail - MCHP_UART1_Tx.head);
    Tmp = Tmp & (Tx_BUFF_SIZE_Uart1 - 1);/* Modulo Buffer Size */

    {
      register uint_T LocalTail = MCHP_UART1_Tx.tail;/* Tail is a volatile variable. Use local variable to speed-up execution */
      MCHP_UART1_Tx.buffer[LocalTail] =
        Ejemplo_de_Programa_principal_DW.DataTypeConversion1;
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

  /* DataTypeConversion: '<S1>/Data Type Conversion4' incorporates:
   *  ArithShift: '<S1>/Shift Arithmetic1'
   *  DataStoreRead: '<S1>/Data Store Read'
   */
  rtb_DataTypeConversion7 = (real32_T)floor((real32_T)ldexp
    (Ejemplo_de_Programa_principal_DW.A, -5));
  if (rtIsNaNF(rtb_DataTypeConversion7) || rtIsInfF(rtb_DataTypeConversion7)) {
    rtb_DataTypeConversion7 = 0.0F;
  } else {
    rtb_DataTypeConversion7 = (real32_T)fmod(rtb_DataTypeConversion7, 65536.0F);
  }

  rtb_DataTypeConversion4 = rtb_DataTypeConversion7 < 0.0F ? (uint16_T)-(int16_T)
    (uint16_T)-rtb_DataTypeConversion7 : (uint16_T)rtb_DataTypeConversion7;

  /* End of DataTypeConversion: '<S1>/Data Type Conversion4' */

  /* S-Function (MCHP_Digital_Output_Write): '<S4>/Digital Output Write' */
  {
    uint16_T register WritePortB = LATB;
    LATB = WritePortB ^ (127 & (WritePortB ^ rtb_DataTypeConversion4));/* Update only required pins */
  }
}

/* Model initialize function */
void Ejemplo_de_Programa_principal_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* states (dwork) */
  (void) memset((void *)&Ejemplo_de_Programa_principal_DW, 0,
                sizeof(DW_Ejemplo_de_Programa_principal_T));

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

  /* InitializeConditions for DiscreteFir: '<S3>/Filter' */
  Ejemplo_de_Programa_principal_DW.Filter_states = 0.0F;

  /* InitializeConditions for DiscreteFir: '<S3>/Filter1' */
  Ejemplo_de_Programa_principal_DW.Filter1_states = 0.0F;

  /* InitializeConditions for DiscreteFir: '<S3>/Filter2' */
  Ejemplo_de_Programa_principal_DW.Filter2_states = 0.0F;

  /* InitializeConditions for DiscreteFir: '<S3>/Filter3' */
  Ejemplo_de_Programa_principal_DW.Filter3_states = 0.0F;

  /* InitializeConditions for DiscreteFir: '<S3>/Filter4' */
  Ejemplo_de_Programa_principal_DW.Filter4_states = 0.0F;

  /* InitializeConditions for DiscreteFir: '<S3>/Filter5' */
  Ejemplo_de_Programa_principal_DW.Filter5_states = 0.0F;

  /* InitializeConditions for DiscreteFir: '<S3>/Filter6' */
  Ejemplo_de_Programa_principal_DW.Filter6_states = 0.0F;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
