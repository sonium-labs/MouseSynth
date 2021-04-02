/*------------------------------------------------------------------------------
  usart.c --
------------------------------------------------------------------------------*/

/********************************DEPENDENCIES**********************************/

#include <avr/io.h>
#include "usart.h"

/*****************************END OF DEPENDENCIES******************************/

/***********************************MACROS*************************************/

/* At 2 MHz SYSclk, 5 BSEL, -6 BSCALE corresponds to 115200 bps */
#define BSEL     (1047)
#define BSCALE   (-6)

/********************************END OF MACROS*********************************/

/*****************************FUNCTION DEFINITIONS*****************************/

char usartd0_in_char(void)
{
  /* intentionally left blank */
}

void usartd0_in_string(char * buf)
{
  /* intentionally left blank */
}

void usartd0_init(void)
{
  /* Configure relevant TxD and RxD pins. */
	PORTD.OUTSET = PIN3_bm;
	PORTD.DIRSET = PIN3_bm;
	PORTD.DIRCLR = PIN2_bm;

  /* Configure baud rate. */
	USARTD0.BAUDCTRLA = (uint8_t)BSEL;
	USARTD0.BAUDCTRLB = (uint8_t)((BSCALE << 4)|(BSEL >> 8));

  /* Configure remainder of serial protocol. */
  /* (In this example, a protocol with 8 data bits, no parity, and
   *  one stop bit is chosen.) */
	USARTD0.CTRLC =	(USART_CMODE_ASYNCHRONOUS_gc |
					 USART_PMODE_DISABLED_gc  	 |
					 USART_CHSIZE_8BIT_gc)       &
					~USART_SBMODE_bm;

  /* Enable receiver and/or transmitter systems. */
	USARTD0.CTRLB = USART_RXEN_bm | USART_TXEN_bm;

  /* Enable interrupt (optional). */
	 USARTD0.CTRLA = USART_RXCINTLVL_MED_gc; 
}

void usartd0_out_char(char c)
{
	while(!(USARTD0.STATUS & USART_DREIF_bm));
	USARTD0.DATA = c;
}

void usartd0_out_string(const char * str)
{
	/*output an 8-bit long string*/
	usartd0_out_char(*(str++));
}

/***************************END OF FUNCTION DEFINITIONS************************/