/***************************************************************************
*                                                                          *
* Module: I2C(TWI) Driver                                                  *
*                                                                          *
* File Name: i2c.c                                                         *
*                                                                          *
* Description: Source file for I2C(TWI) AVR driver                         *
*                                                                          *
* Author: Mahdi Gamal                                                      *
*                                                                          *
* Date: 27/1/2019                                                          *
*                                                                          *
****************************************************************************/

#include "i2c.h"


/*TWI Initialization function*/
void TWI_init(void)
{
  /*******************************************************************
   * Bit rate register "TWBR" to setup division factor for bit rate, *
   * generator"frequency divider, for data transfer rate             *       
   *                                                                 *
   * Status register TWSR for the transaction status,bit 2:1,        *
   * is reserved, TWPS1:TWPS0 both = 0 for prescaler = 0,........... *
   *******************************************************************/
   TWBR = 0x02;  
   TWSR = 0x00;  

   /********************************************************************
    * set  address that is used if master controller become a  slave,  *
    *  at TWAR - TWI(Slave) Address Register bits 7:1                  *
    ********************************************************************/
    TWAR = 0x02; 
  
    /********************************************************************
     * Enable TWI(Two Wire Interface) , by set "TWEN" bit in TWCR       *
     *   (Two Wire Control Register)                                    *
     ********************************************************************/
     TWCR = (1<<TWEN);
}
  
/*TWI Start,the start of TWI indicated by send a start bit */
void TWI_start(void)
{
  
   /********************************************************************
    * 1.TWIN (Interrupt flag) must be cleared at each start of SPI W/R *
    * 2.TWEN (Enable), enable TWI, set TWEN                            *
    * 3.TWSTA (start), set it to start TWI                             *
    ********************************************************************/
    TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
    
    /*******************************************************
     * clearing TWIN flag starts the operation of the TWI, * 
     *indicate that start bit is Sent successfully         *
     *******************************************************/
    while(BIT_IS_CLEAR(TWCR,TWINT));


}


/*TWI Stop,the stop of TWI indicated by send a stop bit */
void TWI_stop(void)
{
    /********************************************************************
    * 1.TWIN (Interrupt flag) must be cleared at each start of TWI *
    * 2.TWEN (Enable), enable TWI, set TWEN                            *
    * 3.TWSTO(stop), set it to stop TWI                                *
    ********************************************************************/
    TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);
}

   
void TWI_write(uint8 data)
{
   /********************************************************************
    * 1.TWDR (TW Data Register), put data in TWDR                      *
    * 2.TWIN (Interrupt flag) must be cleared at each start of TWI     *
    * 3.TWEN (Enable), enable TWI, set TWEN                            *
    ********************************************************************/
    TWDR = data
    TWCR = (1 << TWINT) | (1 << TWEN);

    /*******************************************************
     *clearing TWIN flag starts the operation of the TWI,  * 
     *indicate thatstart bit is Sent successfully          *
     *******************************************************/
    while(BIT_IS_CLEAR(TWCR,TWINT));
}

   
/*TWI Read indicated with Acknowledgment function*/
uint8 TWI_readWithACK(void)
{
   /********************************************************************
    * 1.TWIN (Interrupt flag) must be cleared at each start of TWI     *
    * 2.TWEA (Enable ACK) must be set to enable ACK with R/W operations*
    * 3.TWEN (Enable), enable TWI, set TWEN                            *
    ********************************************************************/
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);

    /*******************************************************
     * clearing TWIN flag starts the operation of the TWI, * 
     * indicate that read operation is done successfully   *
     *******************************************************/

    while(BIT_IS_CLEAR(TWCR,TWINT));
    return TWDR;/* Read Data Register */
}


/*TWI Read indicated with negative Acknowledgment function*/ 
uint8 TWI_readWithNACK(void)
{
   /********************************************************************
    * 1.TWIN (Interrupt flag) must be cleared at each start of TWI     *
    * 2.TWEN (Enable), enable TWI, set TWEN                            *
    ********************************************************************/
    TWCR = (1 << TWINT) | (1 << TWEN);

     /*******************************************************
     * clearing TWIN flag starts the operation of the TWI, * 
     * indicate thatread operation is done successfully                 *
     *******************************************************/
    while(BIT_IS_CLEAR(TWCR,TWINT));
    /* Read Data */
    return TWDR;
}

/*get status of TWI function*/
uint8 TWI_getStatus(void)
{
    /* 8-bit variable to store status info /*
    uint8 status;
  
   /******************************************************
    * TWSR(TW Status Register), mask bits 3:7            *
    * Bits [3:7] – TWS: TWI Status,these five bits,      *   
    * reflect the status of the TWI logic                *
    * and the Two-wire Serial Bus.                       *
    * ****************************************************/
    
    status = TWSR & 0xF8;
    return status;
}



















