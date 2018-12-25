/*
 * -------------------------------------------------------------------
 * MPLAB 16-Bit Device Blocks for Simulink v3.38.
 *
 *   Product Page:  http://www.microchip.com/SimulinkBlocks
 *           Forum: http://www.microchip.com/forums/f192.aspx
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: HOLA_LED_main.c
 *
 * Code generated for Simulink model 'HOLA_LED'.
 *
 * Model version                  : 1.29
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Thu Dec 20 11:31:34 2018
 */

#define MCHP_isMainFile
#include "HOLA_LED.h"
#include "HOLA_LED_private.h"

/* Microchip Global Variables */
/* Set Fuses Options */

#pragma config FNOSC = PRI
#pragma config POSCMD = HS, OSCIOFNC = ON, FCKSM = CSECMD
#pragma config FWDTEN = OFF
#pragma config JTAGEN = OFF

/* Scheduler */
void __attribute__((__interrupt__,__auto_psv__)) _T1Interrupt(void)
{
  {
    struct {
      unsigned int Flags0 : 1;
      unsigned int Flags1 : 1;
    } static volatile Overrun;

    struct {
      unsigned int Flags0 : 1;
      unsigned int Flags1 : 1;
    } static volatile event;

    static int_T taskCounter[2] = { 0, 0 };

    _T1IF = 0;                         /* Re-enable interrupt */

    /* Check subrate overrun, set rates that need to run this time step*/
    if (taskCounter[1] == 0) {         /* task dropped on overload */
      event.Flags1 = 1U;
    }

    /* Update task internal counters */
    taskCounter[1]++;
    if (taskCounter[1] == 100) {
      taskCounter[1]= 0;
    }

    /* Step the model for base rate */
    /* Start profiling task 0 */
    HOLA_LED_step0();

    /* Get model outputs here */

    /* Stop profiling task 0 */
    if (_T1IF ) {
      return;                          /* Will re-enter into the interrupt */
    }

    /* Re-Enable Interrupt. IPL value is 2 at this point */
    _IPL0 = 1;                         /* Re-Enable Scheduler re-entrant interrupt. Lower IPL from 2 to 1 */
    _IPL1 = 0;

    /* Step the model for any subrate */
    /* Handle Task 1 */
    if (Overrun.Flags1) {
      return;                          /* Priority to higher rate steps interrupted */
    }

    if (event.Flags1) {
      Overrun.Flags1 = 1;
      do {
        /* Start profiling task 1 */
        event.Flags1 = 0U;
        HOLA_LED_step1();

        /* Get model outputs here */
        ;                              /* Execute task tid 1 */

        /* Stop profiling task 1 */
      } while (event.Flags1);

      Overrun.Flags1 = 0U;
    }

    /* Disable Interrupt. IPL value is 1 at this point */
    _IPL1 = 1;                         /* Disable Scheduler Interrupts. Rise IPL from 1 to 2 */
    _IPL0 = 0;
  }
}

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
  AD1PCFGL = 0x02;

  /* Configure Remappables Pins */
  RPINR18 = 0x0A;
  RPOR5 = 0x0300;

  /* Configure Digitals I/O directions */
  TRISA = 0xFFFD;
  TRISB = 0xF7FF;

  /* Finish clock switching procedure */
  while (OSCCONbits.COSC != 3) ;       /* Wait for Oscillator Stabilisation */
  while (OSCCONbits.LOCK != 1) ;       /* Wait for PLL Stabilisation */

  /* Initialize model */
  HOLA_LED_initialize();

  /* Configure Timers */
  /* --- TIMER 1 --- This timer is enabled at end of configuration functions. */
  T1CON = 0;                           /* Stop Timer 1 and resets control register */
  _T1IP = 2;                           /* Set timer Interrupt Priority */
  _T1IF = 0;                           /* Reset pending Interrupt */
  _T1IE = 1;                           /* Enable Timer Interrupt. */
  PR1 = 0x9C3F;                        /* Period */

  /* Enable Time-step */
  TMR1 = 0x9C3E;
  T1CONbits.TON = 1;                   /* Start timer 1. Timer 1 is the source trigger for the model Time-step */

  /* Main Loop */
  for (;;) ;
}                                      /* end of main() */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
