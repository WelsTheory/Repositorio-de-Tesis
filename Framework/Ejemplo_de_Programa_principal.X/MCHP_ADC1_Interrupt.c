#include "Ejemplo_de_Programa_principal.h"
#include "Ejemplo_de_Programa_principal_private.h"

/* ADC - Interrupt: <Root>/ADC */
volatile uint16_T ADC1BuffChannelA[1];
void __attribute__((__interrupt__,__auto_psv__)) _T3Interrupt(void)
{
  AD1CON1 = 0x84E4;                    /* Force bits 4-7 for automatic sampling */
  _T3IF = 0;                           /* Disable Interrupt */
}

void __attribute__((__interrupt__,__auto_psv__)) _ADC1Interrupt(void)
{
  ADC1BuffChannelA[0] = ADC1BUF0;      /* Copy value from ADC buffer  */
  AD1CON1 &= 0x7FFF;                   /* Must cancel current sampling */

  {
    extern volatile uint_T ContinueTimeStep __attribute__ ((near)) ;
    __asm__ volatile ( "BSET.b %[MyVar], #0" : [MyVar] "+m" (ContinueTimeStep) )
      ;                                /* Atomic bit-set: ContinueTimeStep |= 1 */
    _AD1IF = 0;                        /* Re-enable interrupt */
  }
}
