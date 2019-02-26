#include "Prueba_ADC.h"
#include "Prueba_ADC_private.h"

/* UART Config - Interrupt: <Root>/UART Configuration */

/* Declare UART1 Tx Circular Buffer Structure */
MCHP_UART1_TxStr MCHP_UART1_Tx;
MCHP_UART1_RxStr MCHP_UART1_Rx;
void __attribute__((__interrupt__,__shadow__,__no_auto_psv__)) _U1TXInterrupt
  (void)
{
  register uint_T LocalHead;
  LocalHead = MCHP_UART1_Tx.head;      /* Head is a volatile variable. Use local variable to speed-up execution */
  while ((0U == U1STAbits.UTXBF) && (MCHP_UART1_Tx.tail != LocalHead) )/* while UxTXREG buffer is not full */
  {
    U1TXREG = MCHP_UART1_Tx.buffer[LocalHead];
    LocalHead = (LocalHead + 1) & (Tx_BUFF_SIZE_Uart1-1);
  }

  MCHP_UART1_Tx.head = LocalHead;      /* Push back volatile variable */
  _U1TXIF = 0;                         /*  */
}

void __attribute__((__interrupt__,__no_auto_psv__)) _U1RXInterrupt(void)
{
  uint_T Tmp;
  Tmp = ~(MCHP_UART1_Rx.tail - MCHP_UART1_Rx.head);/* head - tail - 1 */
  Tmp &= (Rx_BUFF_SIZE_Uart1-1);       /* Tmp =  (head - tail - 1) modulo buffersize Rx_BUFF_SIZE_Uart1)	<==> Rx_BUFF_SIZE_Uart1 - (head - tail) - 1*/
  _U1RXIF = 0;                         /*  */
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

  if (U1STAbits.OERR == 1)
    U1STAbits.OERR = 0;                /* Buffer Overflow cleared */
}
