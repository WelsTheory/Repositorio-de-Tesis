/*
 * -------------------------------------------------------------------
 * MPLAB 16-Bit Device Blocks for Simulink v3.38.
 *
 *   Product Page:  http://www.microchip.com/SimulinkBlocks
 *           Forum: http://www.microchip.com/forums/f192.aspx
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: DSPIC33FJ_FIR_main.c
 *
 * Code generated for Simulink model 'DSPIC33FJ_FIR'.
 *
 * Model version                  : 1.77
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Sun Dec 09 18:39:59 2018
 */

#define MCHP_isMainFile
#include "DSPIC33FJ_FIR.h"
#include "DSPIC33FJ_FIR_private.h"

volatile uint_T ContinueTimeStep __attribute__ ((near)) = 0;/* Microchip Global Variable for single rate scheduler */

/* Microchip Global Variables */
/* Set Fuses Options */
#pragma config FNOSC = PRI
#pragma config POSCMD = HS, OSCIOFNC = ON, FCKSM = CSDCMD
#pragma config FWDTEN = OFF
#pragma config JTAGEN = OFF

/* Scheduler */
void __attribute__((__interrupt__,__auto_psv__)) _T1Interrupt(void)
{
  {
    extern volatile uint_T ContinueTimeStep __attribute__ ((near)) ;
    __asm__ volatile ( "BSET.b %[MyVar], #0" : [MyVar] "+m" (ContinueTimeStep) )
      ;                                /* Atomic bit-set: ContinueTimeStep |= 1 */
    _T1IF = 0;                         /* Re-enable interrupt */
  }
}

/* Solver mode : SingleTasking */
int main()
{
  /* Initialize model */
  /* Configure Pins as Analog or Digital */
  AD1PCFGL = 0x00;

  /* Configure Remappables Pins */
  RPINR18 = 0x09;
  RPOR5 = 0x03;

  /* Configure Digitals I/O directions */
  TRISA = 0xFFFB;
  TRISB = 0xFBFF;

  /* Initialize model */
  DSPIC33FJ_FIR_initialize();

  /* Configure Timers */
  /* --- TIMER 1 --- This timer is enabled at end of configuration functions. */
  T1CON = 0;                           /* Stop Timer 1 and resets control register */
  _T1IP = 2;                           /* Set timer Interrupt Priority */
  _T1IF = 0;                           /* Reset pending Interrupt */
  _T1IE = 1;                           /* Enable Timer Interrupt. */
  PR1 = 0x1387;                        /* Period */

  /* Enable Time-step */
  TMR1 = 0x1386;
  T1CONbits.TON = 1;                   /* Start timer 1. Timer 1 is the source trigger for the model Time-step */

  /* Main Loop */
  for (;;) {
    while (!ContinueTimeStep) ;

    /* Disable Scheduler Interrupt */
    _IPL0 = 1;                         /* Disable Scheduler Interrupts. Rise IPL from 0 to 1 */
    __asm__ volatile ("BCLR.b %[MyVar], #0" : [MyVar] "+m" (ContinueTimeStep) );/* Atomic bit-clear of ContinueTimeStep bit 1 */

    /* Call model Scheduler */
    /* Step the model for base rate */
    /* Start profiling task 0 */
    DSPIC33FJ_FIR_step();

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
