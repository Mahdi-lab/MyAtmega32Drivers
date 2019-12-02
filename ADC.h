/****************************************
 *                                      *
 * Module: ADC                          *
 *                                      *
 * File Name: ADC.h                     *
 *                                      *
 * Description: ADC driver header file  *
 *                                      *
 * Author: Mahdi Gamal                  *
 *                                      *
 ****************************************

#ifndef ADC_H_
#define ADC_H_

/*the file includes  microcontroller standard libraries for AVR configuration*/
#include "micro_config.h"

/*the file includes the standard needed data types for AVR controller*/
#include "std_types.h"

/*the file includes a common macros that is used for Bit and Register operation of a controller*/
#include "common_macros.h"

/******************************************
 *           Preprocessor Macros          *
 ******************************************/
external volatile uint16 g_adcResult

/**************************************
 *        Functions Prototypes        *
 **************************************/

/* ADC Initialization Function */
void ADC_init(void);

void ADC_readChannel(uint8 channel_num);

#endif  /* ADC_H_ */