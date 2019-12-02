/******************************************
 *                                        *
 * Module: Keypad                         *
 *                                        *
 * File Name: kypad.h                     *
 *                                        *
 * Description: Keypad driver header file *
 *                                        *
 * Author: Mahdi Gamal                    *
 *                                        *
 ******************************************

#ifndef KEYPAD_H_
#define KEYPAD_H_

/*the file includes  microcontroller standard libraries for AVR configuration*/
#include "micro_config.h"

/*the file includes the standard needed data types for AVR controller*/
#include "std_types.h"

/*the file includes a common macros that is used for Bit and Register operation of a controller*/
#include "common_macros.h"

/*********************************************************
 *                  Preprocessor Macros                  *                   *
 *********************************************************/

/* a Keypad configurations for number of rows and columns */
#define N_col 4
#define N_row 4

/* Microcontroller Port Configurations for Keypad */
#define KEYPAD_PORT_DIR DDRA
#define KEYPAD_PORT_IN  PINA
#define KEYPAD_PORT_DATA  PORTA

/*********************************************
*            Functions Prototype             *
*********************************************/

/* getting pressed key function */
uint8 Key_Pad_getPressedKEY(void);

#endif  /* end of KEYPAD_H_ */
