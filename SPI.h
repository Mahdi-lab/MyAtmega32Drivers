/************************************************************************
*                                                                       *
* Module: SPI Driver                                                    *
*                                                                       *
* File Name: spi.h                                                      *
*                                                                       *
* Description: SPI Driver header file for AVR controller                *
*                                                                       *
* Author: Mahdi Gamal                                                   *
*                                                                       *
* Date: 27/1/2019                                                       *
*                                                                       *
*************************************************************************/

#ifndef SPI_H_
#define SPI_H_

#include "micro_config.h"
#include "std_types.h"
#include "common_macros.h"

/***********************************************************************
*                    Functions Prototypes                              *
************************************************************************/

/* SPI Driver "Master" Initialization */
void init_Master(void);

/* SPI Driver "Slave" Initialization */
void init_Slave(void);

/* SPI Driver send byte function */
void SPI_sendByte(const uint8 data);

/* SPI Driver send String function */
void SPI_sendString(const uint8 *str);

/ SPI receive byte function */
void SPI_receiveByte(void);

/ SPI receive String function */
void SPI_reveiveString(char *str);


/* End of SPI_H_ */
#endif