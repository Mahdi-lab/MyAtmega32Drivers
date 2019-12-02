/*******************************************
 *                                         *
 * Module: ADC                             *
 *                                         *
 * File Name: ADC.c                        *
 *                                         *
 * Description: ADC driver source file     *
 *                                         *
 * Author: Mahdi Gamal                     *
 *                                         *
 *******************************************/

#include"adc.h"


/*****************************************
 *       Global External Variables       *
 *****************************************/
volatile  uint16 adcResult = 0;
/**********************************
 *        ISR Definition          *
 **********************************/
ISR(ADC_vect)
{
	/* Read ADC Data after conversion complete */
	g_adcResult = ADC;


/***************************************
 *          Functions Definitions      *
 ***************************************/

void ADC_init(void)
{
  /* at ADMUX register register choose reference voltage
        and choose ADC channel
   1.Choose Reference Voltage
 REFS1,REFS0=00 Both equal 0 means connect to external reference voltage
       at ADC RefVoltage PIN "AREF"
      MUX4:MUX0=0  channel 0  2.Choose channel*/ 
    ADMUX = 0;
 /* 3.Enable/Disable ADC Interrupt"if ADC interrupt will be used, I-bit you should enable it 
    4.choose ADCclock----->> */
  ADCSRA |=(1<<ADEN) | (1<<ADIE) | (1<<ADPS1) | (1<<ADPS0);
}

   void ADC_readChannel(uint8 channel_num)
{
	channel_num &= 0x07; /* channel number must be from 0 --> 7 */
	ADMUX &= 0xE0; /* clear first 5 bits in the ADMUX (channel number MUX4:0 bits) before set the required channel */
	ADMUX = ADMUX | channel_num; /* choose the correct channel by setting the channel number in MUX4:0 bits */
	SET_BIT(ADCSRA,ADSC); /* start conversion write '1' to ADSC */
}

                 

 



















       