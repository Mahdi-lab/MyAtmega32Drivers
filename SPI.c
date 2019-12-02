/***************************************************************
*                                                              *
* Module: SPI DRIVER                                           *
*                                                              *
* File Name: spi.c                                             *
*                                                              *
* Description: SPI Driver source file for AVR microcontroller  *
*                                                              *
* Author: Mahdi Gamal                                          *
*                                                              *
* Date:7/1/2019                                                *
*                                                              *
****************************************************************/

#include "spi.h"


/***************************************************************
*                     Functions Definitions                    *
****************************************************************/

void SPI_masterr_Init(void)
{
  /**********************************************************
   *                 Master Mode Setup                        *
   *                                                          *
   * at SPI Control Register enable SPI by set ->> "SPE" bit. *
   *  at SPI Control Register enable SCK Frequency by using   *
   * bits (SPI2X, SPR1, SPR0) as described in datasheet,      *
   * set just "SPR0" bit to enable F/16 SCK Frequency.        * 
   *  enable SPI by set "SPE" bit                             *
   ************************************************************/
   SPCR=(1<<MSTR) | (1<<SPR0) | (1<<SPE);

  /***********************************************************
   *                 Master Pins Configuration               *
   *                                                         *
   *  enable Master Output  Slave Input "MOSI" bit as output *
   *  enable Master Input  SlaveOutput  "MISO" bit as input  *
   *  enable Shift  Clock   "SCK" bit as output              *
   *  enable Slave Select "SS" bit as output                 *
   **********************************************************/
   DDRB |= (1<<MOSI) | (1<<SCK) | (1<<SS);
   DDRB &= (~(1<<MISO);
   
 }


void SPI_slave_Init(void)
{
  /************************************************************
   *                 Slave Mode Setup                         *
   *                                                          *
   * at SPI Control Register enable SPI by set ->> "SPE" bit. *
   * at SPI Control Register enable Clock Polarity "CPOl" bit * 
   * enable Clock Phaset "CPHA" bit as described in Datasheet *
   ************************************************************/
   SPCR= (1<<SPE);
  /***********************************************************
   *                 Slave Pins Configuration                *
   *                                                         *
   *  enable Master Output  Slave Input "MOSI" bit as input  *
   *  enable Master Input  SlaveOutput  "MISO" bit as output *
   *  enable Shift  Clock   "SCK" bit as input               *
   *  enable Slave Select "SS" bit as input                  *
   ***********************************************************/
   DDRB &= (~(1<<MOSI)) | (~(1<<SCK)) | (~(1<<SS));
   DDRB |= (1<<MISO);
 }

void SPI_sendByte(const uint8 data) 
{
  while(BIT_IS_CLEAR(SPSR,SPIF)){} 
   /***************************************************************
    * making polling by checking if SPDR is empty when it's empty *
    * there is an ability to add data to it, the flag will be = 1 *
    * till data is transferred, then automatically return to 0    *
    ***************************************************************/
    SPDR = data; //send data by SPI
}


 void SPI_send_String(const uint8 *Str)
{
       
	uint8 i = 0;
	while(Str[i] != '\0')
	{
		SPI_sendByte(Str[i]);
		i++;
	}
}


void SPI_receive_String(char *Str)
{
	unsigned char i = 0;
	Str[i] = SPI_recieveByte();
	while(Str[i] != '#')
	{
		i++;
		Str[i] = SPI_recieveByte();
	}
	Str[i] = '\0';
}
/***************************************************
 *                     THE END                     *
 ***************************************************/
