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
 * Model version                  : 1.143
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Sun Jul 07 20:59:31 2019
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
  real32_T numAccum;
  real32_T denAccum;
  int32_T i;
  int32_T j;
  boolean_T rtb_Compare_m;
  real32_T rtb_DataTypeConversion7;
  real32_T rtb_Filtro_40Hz_Orden_20;
  real32_T rtb_Filtro_05Hz_Orden_2;
  real32_T rtb_Filtro_40Hz_Orden_5;
  real32_T rtb_Filtro_40Hz_Orden_15;
  real32_T rtb_Filtro_40Hz_Orden_30;

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

  /* RelationalOperator: '<S6>/Compare' incorporates:
   *  Constant: '<S6>/Constant'
   *  S-Function (sfix_bitop): '<S3>/Bitwise Operator2'
   */
  rtb_Compare = ((Tesis_Simulink_DW.U1Rx & 1) == 1);

  /* S-Function (MCHP_Digital_Output_Write): '<S1>/Digital Output Write' */
  LATAbits.LATA1 = rtb_Compare;

  /* MCHP_ADC Block for ADC 1: <Root>/ADC/Output */
  Tesis_Simulink_DW.ADC = ADC1BuffChannelA[0];

  /* DataTypeConversion: '<Root>/Data Type Conversion2' */
  Tesis_Simulink_DW.DataTypeConversion2 = Tesis_Simulink_DW.ADC;

  /* S-Function (sdspbiquad): '<S2>/Filtro_40Hz_Orden_5but' */
  denAccum = (0.0151201887F * Tesis_Simulink_DW.DataTypeConversion2 -
              -1.86462557F *
              Tesis_Simulink_DW.Filtro_40Hz_Orden_5but_FILT_STATES[0L]) -
    0.925106287F * Tesis_Simulink_DW.Filtro_40Hz_Orden_5but_FILT_STATES[1L];
  numAccum = (2.0F * Tesis_Simulink_DW.Filtro_40Hz_Orden_5but_FILT_STATES[0L] +
              denAccum) + Tesis_Simulink_DW.Filtro_40Hz_Orden_5but_FILT_STATES
    [1L];
  Tesis_Simulink_DW.Filtro_40Hz_Orden_5but_FILT_STATES[1L] =
    Tesis_Simulink_DW.Filtro_40Hz_Orden_5but_FILT_STATES[0L];
  Tesis_Simulink_DW.Filtro_40Hz_Orden_5but_FILT_STATES[0L] = denAccum;
  denAccum = (0.0141148167F * numAccum - -1.74064279F *
              Tesis_Simulink_DW.Filtro_40Hz_Orden_5but_FILT_STATES[2L]) -
    0.797102034F * Tesis_Simulink_DW.Filtro_40Hz_Orden_5but_FILT_STATES[3L];
  numAccum = (2.0F * Tesis_Simulink_DW.Filtro_40Hz_Orden_5but_FILT_STATES[2L] +
              denAccum) + Tesis_Simulink_DW.Filtro_40Hz_Orden_5but_FILT_STATES
    [3L];
  Tesis_Simulink_DW.Filtro_40Hz_Orden_5but_FILT_STATES[3L] =
    Tesis_Simulink_DW.Filtro_40Hz_Orden_5but_FILT_STATES[2L];
  Tesis_Simulink_DW.Filtro_40Hz_Orden_5but_FILT_STATES[2L] = denAccum;
  denAccum = (0.0133592F * numAccum - -1.64746F *
              Tesis_Simulink_DW.Filtro_40Hz_Orden_5but_FILT_STATES[4L]) -
    0.7008968F * Tesis_Simulink_DW.Filtro_40Hz_Orden_5but_FILT_STATES[5L];
  numAccum = (2.0F * Tesis_Simulink_DW.Filtro_40Hz_Orden_5but_FILT_STATES[4L] +
              denAccum) + Tesis_Simulink_DW.Filtro_40Hz_Orden_5but_FILT_STATES
    [5L];
  Tesis_Simulink_DW.Filtro_40Hz_Orden_5but_FILT_STATES[5L] =
    Tesis_Simulink_DW.Filtro_40Hz_Orden_5but_FILT_STATES[4L];
  Tesis_Simulink_DW.Filtro_40Hz_Orden_5but_FILT_STATES[4L] = denAccum;
  denAccum = (0.0128590548F * numAccum - -1.58578193F *
              Tesis_Simulink_DW.Filtro_40Hz_Orden_5but_FILT_STATES[6L]) -
    0.637218118F * Tesis_Simulink_DW.Filtro_40Hz_Orden_5but_FILT_STATES[7L];
  numAccum = (2.0F * Tesis_Simulink_DW.Filtro_40Hz_Orden_5but_FILT_STATES[6L] +
              denAccum) + Tesis_Simulink_DW.Filtro_40Hz_Orden_5but_FILT_STATES
    [7L];
  Tesis_Simulink_DW.Filtro_40Hz_Orden_5but_FILT_STATES[7L] =
    Tesis_Simulink_DW.Filtro_40Hz_Orden_5but_FILT_STATES[6L];
  Tesis_Simulink_DW.Filtro_40Hz_Orden_5but_FILT_STATES[6L] = denAccum;
  denAccum = (0.0126108425F * numAccum - -1.55517232F *
              Tesis_Simulink_DW.Filtro_40Hz_Orden_5but_FILT_STATES[8L]) -
    0.605615675F * Tesis_Simulink_DW.Filtro_40Hz_Orden_5but_FILT_STATES[9L];
  Tesis_Simulink_DW.Filtro_40Hz_Orden_5but = (2.0F *
    Tesis_Simulink_DW.Filtro_40Hz_Orden_5but_FILT_STATES[8L] + denAccum) +
    Tesis_Simulink_DW.Filtro_40Hz_Orden_5but_FILT_STATES[9L];
  Tesis_Simulink_DW.Filtro_40Hz_Orden_5but_FILT_STATES[9L] =
    Tesis_Simulink_DW.Filtro_40Hz_Orden_5but_FILT_STATES[8L];
  Tesis_Simulink_DW.Filtro_40Hz_Orden_5but_FILT_STATES[8L] = denAccum;

  /* DataTypeConversion: '<S3>/Data Type Conversion7' incorporates:
   *  Constant: '<S8>/Constant'
   *  Product: '<S3>/Divide2'
   *  RelationalOperator: '<S8>/Compare'
   *  S-Function (sfix_bitop): '<S3>/Bitwise Operator1'
   */
  rtb_DataTypeConversion7 = ((Tesis_Simulink_DW.U1Rx & 4) >> 2 == 1);

  /* DiscreteFir: '<S2>/Filtro_40Hz_Orden_20' */
  /* Consume delay line and beginning of input samples */
  for (i = 1L; i - 1L < 1L; i++) {
    rtb_Filtro_40Hz_Orden_20 = 0.0F;
    for (j = 0L; j < i; j++) {
      rtb_Filtro_40Hz_Orden_20 += Tesis_Simulink_DW.DataTypeConversion2 *
        Tesis_Simulink_ConstP.Filtro_40Hz_Orden_20_Coefficients[j];
    }

    for (j = 0L; j < 21L - i; j++) {
      rtb_Filtro_40Hz_Orden_20 +=
        Tesis_Simulink_ConstP.Filtro_40Hz_Orden_20_Coefficients[i + j] *
        Tesis_Simulink_DW.Filtro_40Hz_Orden_20_states[j];
    }
  }

  /* Update delay line for next frame */
  for (i = 18L; (int16_T)i >= 0; i = (int16_T)i - 1) {
    Tesis_Simulink_DW.Filtro_40Hz_Orden_20_states[(int32_T)(1 + (int16_T)i)] =
      Tesis_Simulink_DW.Filtro_40Hz_Orden_20_states[i];
  }

  for (i = 1L; i - 1L < 1L; i++) {
    Tesis_Simulink_DW.Filtro_40Hz_Orden_20_states[1L - i] =
      Tesis_Simulink_DW.DataTypeConversion2;
  }

  /* End of DiscreteFir: '<S2>/Filtro_40Hz_Orden_20' */

  /* RelationalOperator: '<S7>/Compare' incorporates:
   *  Constant: '<S7>/Constant'
   *  Product: '<S3>/Divide1'
   *  S-Function (sfix_bitop): '<S3>/Bitwise Operator'
   */
  rtb_Compare_m = ((Tesis_Simulink_DW.U1Rx & 2) >> 1 == 1);

  /* DiscreteFir: '<S2>/Filtro_05Hz_Orden_2' */
  /* Consume delay line and beginning of input samples */
  for (i = 1L; i - 1L < 1L; i++) {
    rtb_Filtro_05Hz_Orden_2 = 0.0F;
    for (j = 0L; j < i; j++) {
      rtb_Filtro_05Hz_Orden_2 += Tesis_Simulink_DW.DataTypeConversion2 *
        Tesis_Simulink_ConstP.Filtro_05Hz_Orden_2_Coefficients[j];
    }

    for (j = 0L; j < 11L - i; j++) {
      rtb_Filtro_05Hz_Orden_2 +=
        Tesis_Simulink_ConstP.Filtro_05Hz_Orden_2_Coefficients[i + j] *
        Tesis_Simulink_DW.Filtro_05Hz_Orden_2_states[j];
    }
  }

  /* Update delay line for next frame */
  for (i = 8L; (int16_T)i >= 0; i = (int16_T)i - 1) {
    Tesis_Simulink_DW.Filtro_05Hz_Orden_2_states[(int32_T)(1 + (int16_T)i)] =
      Tesis_Simulink_DW.Filtro_05Hz_Orden_2_states[i];
  }

  for (i = 1L; i - 1L < 1L; i++) {
    Tesis_Simulink_DW.Filtro_05Hz_Orden_2_states[1L - i] =
      Tesis_Simulink_DW.DataTypeConversion2;
  }

  /* End of DiscreteFir: '<S2>/Filtro_05Hz_Orden_2' */

  /* DiscreteFir: '<S2>/Filtro_40Hz_Orden_5' */
  /* Consume delay line and beginning of input samples */
  for (i = 1L; i - 1L < 1L; i++) {
    rtb_Filtro_40Hz_Orden_5 = 0.0F;
    for (j = 0L; j < i; j++) {
      rtb_Filtro_40Hz_Orden_5 += Tesis_Simulink_DW.DataTypeConversion2 *
        Tesis_Simulink_ConstP.Filtro_40Hz_Orden_5_Coefficients[j];
    }

    for (j = 0L; j < 6L - i; j++) {
      rtb_Filtro_40Hz_Orden_5 +=
        Tesis_Simulink_ConstP.Filtro_40Hz_Orden_5_Coefficients[i + j] *
        Tesis_Simulink_DW.Filtro_40Hz_Orden_5_states[j];
    }
  }

  /* Update delay line for next frame */
  for (i = 3L; (int16_T)i >= 0; i = (int16_T)i - 1) {
    Tesis_Simulink_DW.Filtro_40Hz_Orden_5_states[(int32_T)(1 + (int16_T)i)] =
      Tesis_Simulink_DW.Filtro_40Hz_Orden_5_states[i];
  }

  for (i = 1L; i - 1L < 1L; i++) {
    Tesis_Simulink_DW.Filtro_40Hz_Orden_5_states[1L - i] =
      Tesis_Simulink_DW.DataTypeConversion2;
  }

  /* End of DiscreteFir: '<S2>/Filtro_40Hz_Orden_5' */

  /* S-Function (sdspbiquad): '<S2>/Filtro_40Hz_Orden_20but' */
  denAccum = (0.015407783F * Tesis_Simulink_DW.DataTypeConversion2 -
              -1.90009177F *
              Tesis_Simulink_DW.Filtro_40Hz_Orden_20but_FILT_STATES[0L]) -
    0.96172291F * Tesis_Simulink_DW.Filtro_40Hz_Orden_20but_FILT_STATES[1L];
  numAccum = (2.0F * Tesis_Simulink_DW.Filtro_40Hz_Orden_20but_FILT_STATES[0L] +
              denAccum) + Tesis_Simulink_DW.Filtro_40Hz_Orden_20but_FILT_STATES
    [1L];
  Tesis_Simulink_DW.Filtro_40Hz_Orden_20but_FILT_STATES[1L] =
    Tesis_Simulink_DW.Filtro_40Hz_Orden_20but_FILT_STATES[0L];
  Tesis_Simulink_DW.Filtro_40Hz_Orden_20but_FILT_STATES[0L] = denAccum;
  denAccum = (0.0148464981F * numAccum - -1.83087397F *
              Tesis_Simulink_DW.Filtro_40Hz_Orden_20but_FILT_STATES[2L]) -
    0.89026F * Tesis_Simulink_DW.Filtro_40Hz_Orden_20but_FILT_STATES[3L];
  numAccum = (2.0F * Tesis_Simulink_DW.Filtro_40Hz_Orden_20but_FILT_STATES[2L] +
              denAccum) + Tesis_Simulink_DW.Filtro_40Hz_Orden_20but_FILT_STATES
    [3L];
  Tesis_Simulink_DW.Filtro_40Hz_Orden_20but_FILT_STATES[3L] =
    Tesis_Simulink_DW.Filtro_40Hz_Orden_20but_FILT_STATES[2L];
  Tesis_Simulink_DW.Filtro_40Hz_Orden_20but_FILT_STATES[2L] = denAccum;
  denAccum = (0.0143433679F * numAccum - -1.76882792F *
              Tesis_Simulink_DW.Filtro_40Hz_Orden_20but_FILT_STATES[4L]) -
    0.82620132F * Tesis_Simulink_DW.Filtro_40Hz_Orden_20but_FILT_STATES[5L];
  numAccum = (2.0F * Tesis_Simulink_DW.Filtro_40Hz_Orden_20but_FILT_STATES[4L] +
              denAccum) + Tesis_Simulink_DW.Filtro_40Hz_Orden_20but_FILT_STATES
    [5L];
  Tesis_Simulink_DW.Filtro_40Hz_Orden_20but_FILT_STATES[5L] =
    Tesis_Simulink_DW.Filtro_40Hz_Orden_20but_FILT_STATES[4L];
  Tesis_Simulink_DW.Filtro_40Hz_Orden_20but_FILT_STATES[4L] = denAccum;
  denAccum = (0.0139019927F * numAccum - -1.71439731F *
              Tesis_Simulink_DW.Filtro_40Hz_Orden_20but_FILT_STATES[6L]) -
    0.770005345F * Tesis_Simulink_DW.Filtro_40Hz_Orden_20but_FILT_STATES[7L];
  numAccum = (2.0F * Tesis_Simulink_DW.Filtro_40Hz_Orden_20but_FILT_STATES[6L] +
              denAccum) + Tesis_Simulink_DW.Filtro_40Hz_Orden_20but_FILT_STATES
    [7L];
  Tesis_Simulink_DW.Filtro_40Hz_Orden_20but_FILT_STATES[7L] =
    Tesis_Simulink_DW.Filtro_40Hz_Orden_20but_FILT_STATES[6L];
  Tesis_Simulink_DW.Filtro_40Hz_Orden_20but_FILT_STATES[6L] = denAccum;
  denAccum = (0.0135241225F * numAccum - -1.66779828F *
              Tesis_Simulink_DW.Filtro_40Hz_Orden_20but_FILT_STATES[8L]) -
    0.721894801F * Tesis_Simulink_DW.Filtro_40Hz_Orden_20but_FILT_STATES[9L];
  numAccum = (2.0F * Tesis_Simulink_DW.Filtro_40Hz_Orden_20but_FILT_STATES[8L] +
              denAccum) + Tesis_Simulink_DW.Filtro_40Hz_Orden_20but_FILT_STATES
    [9L];
  Tesis_Simulink_DW.Filtro_40Hz_Orden_20but_FILT_STATES[9L] =
    Tesis_Simulink_DW.Filtro_40Hz_Orden_20but_FILT_STATES[8L];
  Tesis_Simulink_DW.Filtro_40Hz_Orden_20but_FILT_STATES[8L] = denAccum;
  denAccum = (0.0132102845F * numAccum - -1.62909567F *
              Tesis_Simulink_DW.Filtro_40Hz_Orden_20but_FILT_STATES[10L]) -
    0.68193686F * Tesis_Simulink_DW.Filtro_40Hz_Orden_20but_FILT_STATES[11L];
  numAccum = (2.0F * Tesis_Simulink_DW.Filtro_40Hz_Orden_20but_FILT_STATES[10L]
              + denAccum) +
    Tesis_Simulink_DW.Filtro_40Hz_Orden_20but_FILT_STATES[11L];
  Tesis_Simulink_DW.Filtro_40Hz_Orden_20but_FILT_STATES[11L] =
    Tesis_Simulink_DW.Filtro_40Hz_Orden_20but_FILT_STATES[10L];
  Tesis_Simulink_DW.Filtro_40Hz_Orden_20but_FILT_STATES[10L] = denAccum;
  denAccum = (0.0129602822F * numAccum - -1.59826541F *
              Tesis_Simulink_DW.Filtro_40Hz_Orden_20but_FILT_STATES[12L]) -
    0.65010649F * Tesis_Simulink_DW.Filtro_40Hz_Orden_20but_FILT_STATES[13L];
  numAccum = (2.0F * Tesis_Simulink_DW.Filtro_40Hz_Orden_20but_FILT_STATES[12L]
              + denAccum) +
    Tesis_Simulink_DW.Filtro_40Hz_Orden_20but_FILT_STATES[13L];
  Tesis_Simulink_DW.Filtro_40Hz_Orden_20but_FILT_STATES[13L] =
    Tesis_Simulink_DW.Filtro_40Hz_Orden_20but_FILT_STATES[12L];
  Tesis_Simulink_DW.Filtro_40Hz_Orden_20but_FILT_STATES[12L] = denAccum;
  denAccum = (0.0127735706F * numAccum - -1.57524F *
              Tesis_Simulink_DW.Filtro_40Hz_Orden_20but_FILT_STATES[14L]) -
    0.62633425F * Tesis_Simulink_DW.Filtro_40Hz_Orden_20but_FILT_STATES[15L];
  numAccum = (2.0F * Tesis_Simulink_DW.Filtro_40Hz_Orden_20but_FILT_STATES[14L]
              + denAccum) +
    Tesis_Simulink_DW.Filtro_40Hz_Orden_20but_FILT_STATES[15L];
  Tesis_Simulink_DW.Filtro_40Hz_Orden_20but_FILT_STATES[15L] =
    Tesis_Simulink_DW.Filtro_40Hz_Orden_20but_FILT_STATES[14L];
  Tesis_Simulink_DW.Filtro_40Hz_Orden_20but_FILT_STATES[14L] = denAccum;
  denAccum = (0.0126495287F * numAccum - -1.55994308F *
              Tesis_Simulink_DW.Filtro_40Hz_Orden_20but_FILT_STATES[16L]) -
    0.610541224F * Tesis_Simulink_DW.Filtro_40Hz_Orden_20but_FILT_STATES[17L];
  numAccum = (2.0F * Tesis_Simulink_DW.Filtro_40Hz_Orden_20but_FILT_STATES[16L]
              + denAccum) +
    Tesis_Simulink_DW.Filtro_40Hz_Orden_20but_FILT_STATES[17L];
  Tesis_Simulink_DW.Filtro_40Hz_Orden_20but_FILT_STATES[17L] =
    Tesis_Simulink_DW.Filtro_40Hz_Orden_20but_FILT_STATES[16L];
  Tesis_Simulink_DW.Filtro_40Hz_Orden_20but_FILT_STATES[16L] = denAccum;
  denAccum = (0.0125876488F * numAccum - -1.55231202F *
              Tesis_Simulink_DW.Filtro_40Hz_Orden_20but_FILT_STATES[18L]) -
    0.602662623F * Tesis_Simulink_DW.Filtro_40Hz_Orden_20but_FILT_STATES[19L];
  Tesis_Simulink_DW.Filtro_40Hz_Orden_20but = (2.0F *
    Tesis_Simulink_DW.Filtro_40Hz_Orden_20but_FILT_STATES[18L] + denAccum) +
    Tesis_Simulink_DW.Filtro_40Hz_Orden_20but_FILT_STATES[19L];
  Tesis_Simulink_DW.Filtro_40Hz_Orden_20but_FILT_STATES[19L] =
    Tesis_Simulink_DW.Filtro_40Hz_Orden_20but_FILT_STATES[18L];
  Tesis_Simulink_DW.Filtro_40Hz_Orden_20but_FILT_STATES[18L] = denAccum;

  /* DiscreteFir: '<S2>/Filtro_40Hz_Orden_15' */
  /* Consume delay line and beginning of input samples */
  for (i = 1L; i - 1L < 1L; i++) {
    rtb_Filtro_40Hz_Orden_15 = 0.0F;
    for (j = 0L; j < i; j++) {
      rtb_Filtro_40Hz_Orden_15 += Tesis_Simulink_DW.DataTypeConversion2 *
        Tesis_Simulink_ConstP.Filtro_40Hz_Orden_15_Coefficients[j];
    }

    for (j = 0L; j < 16L - i; j++) {
      rtb_Filtro_40Hz_Orden_15 +=
        Tesis_Simulink_ConstP.Filtro_40Hz_Orden_15_Coefficients[i + j] *
        Tesis_Simulink_DW.Filtro_40Hz_Orden_15_states[j];
    }
  }

  /* Update delay line for next frame */
  for (i = 13L; (int16_T)i >= 0; i = (int16_T)i - 1) {
    Tesis_Simulink_DW.Filtro_40Hz_Orden_15_states[(int32_T)(1 + (int16_T)i)] =
      Tesis_Simulink_DW.Filtro_40Hz_Orden_15_states[i];
  }

  for (i = 1L; i - 1L < 1L; i++) {
    Tesis_Simulink_DW.Filtro_40Hz_Orden_15_states[1L - i] =
      Tesis_Simulink_DW.DataTypeConversion2;
  }

  /* End of DiscreteFir: '<S2>/Filtro_40Hz_Orden_15' */

  /* DiscreteFir: '<S2>/Filtro_40Hz_Orden_30' */
  /* Consume delay line and beginning of input samples */
  for (i = 1L; i - 1L < 1L; i++) {
    rtb_Filtro_40Hz_Orden_30 = 0.0F;
    for (j = 0L; j < i; j++) {
      rtb_Filtro_40Hz_Orden_30 += Tesis_Simulink_DW.DataTypeConversion2 *
        Tesis_Simulink_ConstP.Filtro_40Hz_Orden_30_Coefficients[j];
    }

    for (j = 0L; j < 31L - i; j++) {
      rtb_Filtro_40Hz_Orden_30 +=
        Tesis_Simulink_ConstP.Filtro_40Hz_Orden_30_Coefficients[i + j] *
        Tesis_Simulink_DW.Filtro_40Hz_Orden_30_states[j];
    }
  }

  /* Update delay line for next frame */
  for (i = 28L; (int16_T)i >= 0; i = (int16_T)i - 1) {
    Tesis_Simulink_DW.Filtro_40Hz_Orden_30_states[(int32_T)(1 + (int16_T)i)] =
      Tesis_Simulink_DW.Filtro_40Hz_Orden_30_states[i];
  }

  for (i = 1L; i - 1L < 1L; i++) {
    Tesis_Simulink_DW.Filtro_40Hz_Orden_30_states[1L - i] =
      Tesis_Simulink_DW.DataTypeConversion2;
  }

  /* End of DiscreteFir: '<S2>/Filtro_40Hz_Orden_30' */

  /* Switch: '<S4>/Switch7' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion6'
   *  Switch: '<S4>/Switch1'
   *  Switch: '<S4>/Switch6'
   */
  if (rtb_Compare) {
    /* Switch: '<S4>/Switch5' incorporates:
     *  DataTypeConversion: '<S3>/Data Type Conversion6'
     *  Switch: '<S4>/Switch3'
     */
    if (rtb_Compare_m) {
      /* Switch: '<S4>/Switch4' */
      if (rtb_DataTypeConversion7 != 0.0F) {
        rtb_DataTypeConversion7 = Tesis_Simulink_DW.Filtro_40Hz_Orden_5but;
      } else {
        rtb_DataTypeConversion7 = rtb_Filtro_40Hz_Orden_20;
      }
    } else if (rtb_DataTypeConversion7 != 0.0F) {
      /* Switch: '<S4>/Switch3' incorporates:
       *  Switch: '<S4>/Switch4'
       */
      rtb_DataTypeConversion7 = rtb_Filtro_05Hz_Orden_2;
    } else {
      /* Switch: '<S4>/Switch4' incorporates:
       *  Switch: '<S4>/Switch3'
       */
      rtb_DataTypeConversion7 = rtb_Filtro_40Hz_Orden_5;
    }
  } else if (rtb_Compare_m) {
    /* Switch: '<S4>/Switch2' incorporates:
     *  Switch: '<S4>/Switch1'
     */
    if (rtb_DataTypeConversion7 != 0.0F) {
      /* Switch: '<S4>/Switch4' incorporates:
       *  Switch: '<S4>/Switch5'
       */
      rtb_DataTypeConversion7 = Tesis_Simulink_DW.Filtro_40Hz_Orden_20but;
    } else {
      /* Switch: '<S4>/Switch4' incorporates:
       *  Switch: '<S4>/Switch5'
       */
      rtb_DataTypeConversion7 = rtb_Filtro_40Hz_Orden_15;
    }

    /* End of Switch: '<S4>/Switch2' */
  } else if (rtb_DataTypeConversion7 != 0.0F) {
    /* Switch: '<S4>/Switch6' incorporates:
     *  Switch: '<S4>/Switch1'
     *  Switch: '<S4>/Switch4'
     *  Switch: '<S4>/Switch5'
     */
    rtb_DataTypeConversion7 = rtb_Filtro_40Hz_Orden_30;
  } else {
    /* Switch: '<S4>/Switch4' incorporates:
     *  Switch: '<S4>/Switch1'
     *  Switch: '<S4>/Switch5'
     *  Switch: '<S4>/Switch6'
     */
    rtb_DataTypeConversion7 = Tesis_Simulink_DW.DataTypeConversion2;
  }

  /* End of Switch: '<S4>/Switch7' */

  /* ArithShift: '<S5>/Shift Arithmetic2' */
  rtb_DataTypeConversion7 = (real32_T)ldexp(rtb_DataTypeConversion7, -4);

  /* DataTypeConversion: '<S5>/Data Type Conversion1' */
  denAccum = (real32_T)floor(rtb_DataTypeConversion7);
  if (rtIsNaNF(denAccum) || rtIsInfF(denAccum)) {
    denAccum = 0.0F;
  } else {
    denAccum = (real32_T)fmod(denAccum, 256.0F);
  }

  Tesis_Simulink_DW.DataTypeConversion1 = (uint8_T)(denAccum < 0.0F ? (int16_T)
    (uint8_T)-(int8_T)(uint8_T)-denAccum : (int16_T)(uint8_T)denAccum);

  /* End of DataTypeConversion: '<S5>/Data Type Conversion1' */
  /* MCHP_UART_Tx Block for UARTRef 1: <Root>/UART Tx/Outputs */
  {
    uint_T Tmp;
    Tmp = ~(MCHP_UART1_Tx.tail - MCHP_UART1_Tx.head);
    Tmp = Tmp & (Tx_BUFF_SIZE_Uart1 - 1);/* Modulo Buffer Size */

    {
      register uint_T LocalTail = MCHP_UART1_Tx.tail;/* Tail is a volatile variable. Use local variable to speed-up execution */
      MCHP_UART1_Tx.buffer[LocalTail] = Tesis_Simulink_DW.DataTypeConversion1;
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
  _U1TXIP = 4;                         /*  Tx Interrupt priority set to 4 */
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

    /* InitializeConditions for DiscreteFir: '<S2>/Filtro_40Hz_Orden_20' */
    memset(&Tesis_Simulink_DW.Filtro_40Hz_Orden_20_states[0L], (int16_T)0.0F,
           20U * sizeof(real32_T));

    /* InitializeConditions for DiscreteFir: '<S2>/Filtro_05Hz_Orden_2' */
    for (i = 0; i < 10; i++) {
      Tesis_Simulink_DW.Filtro_05Hz_Orden_2_states[i] = 0.0F;
    }

    /* End of InitializeConditions for DiscreteFir: '<S2>/Filtro_05Hz_Orden_2' */

    /* InitializeConditions for DiscreteFir: '<S2>/Filtro_40Hz_Orden_5' */
    for (i = 0; i < 5; i++) {
      Tesis_Simulink_DW.Filtro_40Hz_Orden_5_states[i] = 0.0F;
    }

    /* End of InitializeConditions for DiscreteFir: '<S2>/Filtro_40Hz_Orden_5' */

    /* InitializeConditions for DiscreteFir: '<S2>/Filtro_40Hz_Orden_15' */
    for (i = 0; i < 15; i++) {
      Tesis_Simulink_DW.Filtro_40Hz_Orden_15_states[i] = 0.0F;
    }

    /* End of InitializeConditions for DiscreteFir: '<S2>/Filtro_40Hz_Orden_15' */

    /* InitializeConditions for DiscreteFir: '<S2>/Filtro_40Hz_Orden_30' */
    memset(&Tesis_Simulink_DW.Filtro_40Hz_Orden_30_states[0L], (int16_T)0.0F,
           30U * sizeof(real32_T));
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
