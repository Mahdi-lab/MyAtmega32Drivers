/****************************************************************************
*                                                                           *
* Moduld: I2C(TWI) Driver                                                   *                                                                                                                *
*                                                                           *
* File Name: i2c.h                                                          *
*                                                                           *
* Description: I2C Driver header file for atmega16 microcontroller          *
*                                                                           *
* Author: Mahdi Gamal                                                       *
*                                                                           *
*****************************************************************************/

#ifndef I2C_H_
#define I2C_H_

#include "micro_config.h"
#include "std_types.h"
#include "common_macros.h"

/****************************************************************************
*                          Preprocessor Macros                              *
*****************************************************************************

/* I2C Bits Status in TWSR(Two Wire Interface Status Register) */

#define TW_START         0x08 // start has been sent
#define TW_REP_START     0x10 // repeated start
#define TW_MT_SLA_W_ACK  0x18 // Master transmit ( slave address + Write request ) to slave + Ack received from slave.
#define TW_MT_SLA_R_ACK  0x40 // Master transmit ( slave address + Read request ) to slave + Ack received from slave.
#define TW_MT_DATA_ACK   0x28 // Master transmit data and ACK has been received from Slave.
#define TW_MR_DATA_ACK   0x50 // Master received data and send ACK to slave.
#define TW_MR_DATA_NACK  0x58 // Master received data but doesn't send ACK to slave.


/******************************************************************
*                       Functions Prototypes                      *
*******************************************************************/


/* TWI initialization function */
void TWI_init(void);

/* send start bit */
void TWI_start(void);

/* send stop bit */
void TWI_stop(void);

void TWI_write(uint8 data);

/* read with send acknowledgment */
uint8 TWI_readWithACK(void);

* read without send acknowledgment */
uint8 TWI_readWithNACK(void);

uint8 TWI_getStatus(void);


/* End of I2C_H_ */
#endif
























