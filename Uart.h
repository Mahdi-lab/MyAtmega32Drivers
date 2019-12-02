/***************************************************************************
*                                                                          *
* Module: UART DRIVER                                                      *
*                                                                          *
* File Name: uart.h                                                        *
*                                                                          *
* Description: header file for UART Driver 'Atmega16' Microcontroller      *
*                                                                          *
* Author: Mahdi Gamal                                                 *
*                                                                          *
* Date: 27/1/2019                                                          *
*                                                                          *
****************************************************************************/

#ifndefine UART_H_
#define UART_H_

#include "micro_config.h"
#include "std_types.h"
#include "common_macros.h

/******************************************************************
*                        Preprocessor Macros                      *
*******************************************************************/

/* UART Driver Baud Rate */
#define UART_BAUDRATE 9600


/*******************************************************************
*                         Functions Prototypes                     *
********************************************************************

/* UART Initialization Function */
void UART_init(void);

/* Sending Byte using UART Function */
void UART_sendByte(const uint data);

/* Sending String using UART Function */
void UART_sendString(const uint *str);

/* Receiving Byte using UART Function */
void UART_receiveByte(void);


/* Function responsible for receiving a String using UART Protocol */
void UART_receiveString(const uint8 *str);

/* End of UART_H_ */
#endif



