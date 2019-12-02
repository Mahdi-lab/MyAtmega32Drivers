/*******************************************************************
*                                                                  *
* Module: UART Driver                                              *
*                                                                  *
* File Name: uart.c                                                *
*                                                                  *
* Description: UART Driver Source file for AVR microcontroller    *
*                                                                  *
* Author: Mahdi Gamal Mahdi                                        *
*                                                                  *
* Date: 20/1/2019                                                  *
*                                                                  *
********************************************************************/

/* UART Driver header file */
#include "uart.h"

/********************************************************
* Operation mode = Asynchronous Double Speed Mode       *
*   UART double speed, at UCSRA set it "U2X = 1"        *
*********************************************************/
#define BAUD_PRESCALE (((F_CPU/(UART_BAUDRATE * 8UL))) -1)


/**************************************************************************
*                           Functions Definitions                         *
***************************************************************************/

/* UART Initialization Function */
void UART_init(void)
{
  /*********************************************************
   * at UCSRA (UART Control & Status Register A)           *
   * for UART double speed set U2X=1                       *
   *********************************************************/
     UCSRA = (1<<U2X);

  
  /*************************************************************
   * at UCSRB (UART Control & Status Register B)               *
   *  set RXEN (Receiver Enable) = 1                           *
   *  set TXEN (Receiver Enable) = 1                           *
   *  disable RXCIE (Receiver Complete Interrupt Enable) = 0   *
   *  disable TXCIE (Receiver Complete Interrupt Enable) = 0   * 
   *  disable UDRIE (UART Data Register Empty Interrupt) = 0   *
   *  disable UCSZ2 ( UART Character Size),                    *
   *  for 8-bit data mode                                      *
   *************************************************************/
    UCSRB = (1<<RXEN) | (1<<TXEN);

   /*************************************************************
    * at UCSRC (UART Control & Status Register C)               *
    * URSEL   = 1 The URSEL must be one when writing the UCSRC  *
    * UMSEL   = 0 Asynchronous Operation                        *
    * UPM1:0  = 00 Disable parity bit                           *
    * USBS    = 0 One stop bit                                  *
    * UCSZ1:0 = 11 For 8-bit data mode                          *
    * UCPOL   = 0 Used with the Synchronous operation only      *
    *************************************************************/
    UCSRC = (1<<URSEL) |(1<<UCSZ0) | (1<<UCSZ1 );
   
    /************************************************************
     * to set the BAUD_RATE, UBRRH & UBRRL must be used as each *
     * of them is 8-bit                                         *
     ************************************************************/
        UBRRH = BAUD_PRESCALE>>8;
	UBRRL = BAUD_PRESCALE;
}
  /* Function responsible for sending a byte using UART Protocol */
void UART_sendByte(const uint8 data)
{
   UDR = data;
  /********************************************************************
   * UDRE flag is set when the Tx buffer (UDR) is empty and ready for *
   *transmitting a new byte so wait until this flag is set to one     *
   ********************************************************************/
   while(BIT_IS_CLAER(UCSRA<UDRE)) 
   {
    }
}

/* Function responsible for sending a String using UART Protocol */
void UART_sendString(const uint8 *str)
 {
   uint8 i = 0; 
   while(*str != '\0')
   {
    UART_sendByte(str[i]);
     i++;
   }

}


   /* Function responsible for receiving a byte using UART Protocol */
void UART_receiveByte(void)
{
   /********************************************************************
   * UDRE flag is set when the Rx buffer (UDR) is empty and ready for  *
   *receiving a new byte so wait until this flag is set to one         *
   *********************************************************************/
   while(BIT_IS_CLAER(UCSRA<UDRE))
       {
        }
     return UDR;
 }


/* Function responsible for receiving a String using UART Protocol */
void UART_receiveString(const uint8 *str)

   uint8 i = 0;
   str[i] = UART_receiveByte(); 
   while(*str != '#')
   {
     i++;
    UART_receiveByte(str[i]);
   }
  str[i] = '\0';

}
   



















