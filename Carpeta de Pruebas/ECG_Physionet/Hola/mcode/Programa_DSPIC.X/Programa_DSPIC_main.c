/*
 * -------------------------------------------------------------------
 * MPLAB 16-Bit Device Blocks for Simulink v3.38.
 *
 *   Product Page:  http://www.microchip.com/SimulinkBlocks
 *           Forum: http://www.microchip.com/forums/f192.aspx
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: Programa_DSPIC_main.c
 *
 * Code generated for Simulink model 'Programa_DSPIC'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Thu Dec 20 15:43:44 2018
 */

#define MCHP_isMainFile
#include "Programa_DSPIC.h"
#include "Programa_DSPIC_private.h"

volatile uint_T ContinueTimeStep __attribute__ ((near)) = 0;/* Microchip Global Variable for single rate scheduler */

/* Microchip Global Variables */
/* Set Fuses Options */
#pragma config FNOSC = PRI, IESO = OFF
#pragma config POSCMD = HS, FCKSM = CSECMD
#pragma config FWDTEN = OFF
#pragma config FPWRT = PWR1
#pragma config JTAGEN = OFF

/* Solver mode : SingleTasking */
int main()
{
  /* Initialize model */
  /* Start Clock Switching */
  if ((OSCCONbits.COSC & 1) && !(OSCCONbits.COSC & 4))/* check not already in PLL mode (0?1) */
  {
    __builtin_write_OSCCONH(0);        /* Clock Switch to non PLL mode */
    __builtin_write_OSCCONL(0x01);     /* Start clock switching */
    __asm__ volatile("nop\n"
                     "nop");
    while (OSCCONbits.COSC != 0) ;
  }

  PLLFBD = 110.0;                      /* configure Oscillator PLL : PLLDIV */
  CLKDIV = 0x05;                       /* configure Oscillator PLL : FRCDIV ; PLLPOST ; PLLPRE */
  __builtin_write_OSCCONH(3);          /* Clock Switch to desired configuration */
  __builtin_write_OSCCONL(0x01);       /* Start clock switching */

  /* Configure Pins as Analog or Digital */
  AD1PCFGL = 0x1A;

  /* Configure Remappables Pins */
  RPINR18 = 0x0A;
  RPOR5 = 0x0300;

  /* Configure Digitals I/O directions */
  TRISA = 0xFFFD;
  TRISB = 0xF7F9;

  /* Finish clock switching procedure */
  while (OSCCONbits.COSC != 3) ;       /* Wait for Oscillator Stabilisation */
  while (OSCCONbits.LOCK != 1) ;       /* Wait for PLL Stabilisation */

  /* Initialize model */
  Programa_DSPIC_initialize();

  /* Configure Timers */
  /* --- TIMER 3 --- This timer is enabled at end of configuration functions. */
  T3CON = 0;                           /* Stop Timer 3 and resets control register */
  PR3 = 0x9C3F;                        /* Period */

  /* Enable Time-step */
  _T3IF = 0;                           /* Clear Timer 3 Interrupt flag */
  _T3IE = 1;                           /* Enable Timer 3 model Step Interrupt */
  TMR3 = 0x9C3E;
  T3CONbits.TON = 1;                   /* Start timer 3. Timer 3 is the source trigger for the model Time-step */

  /* Main Loop */
  for (;;) {
    while (!ContinueTimeStep) ;

    /* Disable Scheduler Interrupt */
    _IPL0 = 1;                         /* Disable Scheduler Interrupts. Rise IPL from 0 to 1 */
    __asm__ volatile ("BCLR.b %[MyVar], #0" : [MyVar] "+m" (ContinueTimeStep) );/* Atomic bit-clear of ContinueTimeStep bit 1 */

    /* Call model Scheduler */
    /* Step the model for base rate */
    /* Start profiling task 0 */
    Programa_DSPIC_step();

    /* Get model outputs here */

    /* Stop profiling task 0 */

    /* Re-Enable Scheduler Interrupt */
    _IPL0 = 0;                         /* Re-Enable Scheduler re-entrant interrupt. Lower IPL from 1 to 0 */
  }                                    /* End for(;;) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
