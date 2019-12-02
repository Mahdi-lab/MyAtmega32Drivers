/**************************************************
 *                                                *
 * Module: LCD                                    *
 *                                                *
 * File Name: lcd.h                               *
 *                                                *
 * Description: LCD driver header file            *
 *                                                *
 * Author: Mahdi Gamal                            *
 *                                                *
 **************************************************/

#ifndef LCD_H_
#define LCD_H_  

/* including my standard data types file */
#include "std_types.h" 
    
/* include macros file */
#include "common_macros.h" 

/* include AVR configuration file */
#include "micro_config.h"  

/*******************************************************************
 *                  Preprocessor Macros                            *
 *******************************************************************/
 /* LCD mode configuration for data are 4bit mode and 8bit mode,
    for 4bit mode that mean D4 to D7 will be used for 4bit mode */
  #define BITS_DATA_MODE 4


/* the default DATA_MODE for LCD is 8bit mode, if it's defined
   as 4bit as it's mentioned at LCD characteristics in its datasheet
   that mean D4 to D7 "Higher 4 bits is used to transfer data */
#if(BITS_DATA_MODE == 4)
#define HIGHER_PORT_PINS
#endif

/* to use the LOWER_BITS_MODE it's possible to disable the higher
   4 data bits,so lower bits is in use " D0 to D3" */
#undef HIGHER_PORTS_PINS

/***************************************************************/
              /* LCD PINS,PORTS */
/* at the definitions below, i just defined the pins,
   and ports that i used in wire, that is not matter,
   you can define pins and ports that you want to use */

#define RS PB1 /* RS=1 "that mean a data will be sent,RS=0 for command */
#define RW PB2 /* RW=1 means Write mode, RW=0 means Read mode */
#define PORT_CONTROL PORTB
#define DIR_Control  DDRB
#define DATA_PORT PORTD
#define DATA_DIR DDRD


             /* LCD COMMANDS */
/* LCD commands are all mentioned at LCD datasheet */

#define CLEAR_LCD 0x01
#define 4PITS_MODE 0x02
#define TWO_LINE_4BITS_MODE 0x28
#define TWO_LINE_8BITS_MODE 0x38
#define TURN_ON_CURSOR 0x0E
#define TURN_OF_CURSOR 0x0C
#define CURSOR_LOCATION 0x80
/*************************************************************/

/********************************************
 *           Functions Prototypes           *
 ********************************************/
void LCD_init(void);
void LCD_clearScreen(void);
void LCD_gotoRowColumn(uint8 row,uint8 column);
void LCD_sendCommand(uint8 command);
void LCD_displayCharacter(uint8 data);
void LCD_displayString(const uint8 *data);
void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *Str);
void LCD_integerToString(int data);

#endif /*End of LCD_H_ */
