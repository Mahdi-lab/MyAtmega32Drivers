/*******************************************
 *                                         *
 * Module:LCD                              *
 *                                         *
 * File Name: lcd.c                        *
 *                                         *
 * Description:LCD Driver source code      * 
 *                                         *
 * Author: Mahdi Gamal                     *
 *                                         *
 *******************************************/

 #include "lcd.h"

 /*****************************************
  *       Functions Definitions           *
  *****************************************
 /* first I have to initialize LCD "1.Module Initialization" */
 void LCD_init(void)
 {
   /* Initialize Enable(E) command/Data(RS) Read/Write(RW) as input PINS */
  DIR_Control |=(1<<E) | (1<<RS) | (1<<RW);
  
   /*****************************************************/
  #if(BITS_DATA_MODE == 4) /*if data mode = 4 */
     #ifdef HIGHER_4PITS_MODE /*if data mode = 4, then higher BITS mode is defined */
          DATA_DIR|=0xF0; /* configure D4:D7 as input PINS */
       #else /* if not defined */
          DATA_DIR|=0x0F; /* configure D0:D3 as input PINS */
        #endif
    
  LCD_sendCommand(4PITS_MODE); /* 4-BIT mode Initialization */
  LCD_sendCommand(TWO_LINE_4BITS_MODE); /* Enable writing using 2 lines in LCD */
  /********************************************************/
   #elif(BITS_DATA_MODE == 8)
         DATA_DIR |=0xFF;
  LCD_sendCommand(TWO_LINE_8BITS_MODE); /* Enable writing using 2 lines in LCD */
   #endif
   LCD_sendCommand(TURN_OF_CURSOR);
   LCD_sendCommand(CLEAR_LCD);
}

void LCD_displayCharacter(uint8 data)
{
	SET_BIT(PORT_CONTROL,RS); /* Data Mode RS=1 */
	CLEAR_BIT(PORT_CONTROL,RW); /* write data to LCD so RW=0 */
	_delay_ms(1); /* delay for processing Tas = 50ns */
	SET_BIT(PORT_CONTROL,E); /* Enable LCD E=1 */
	_delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */
#if (DATA_BITS_MODE == 4)
	/* out the highest 4 bits of the required data to the data bus D4 --> D7 */
#ifdef HIGHER_PORTS_PINS
	DATA_PORT = (LDATA_PORT & 0x0F) | (data & 0xF0);
#else
	LCD_DATA_PORT = (DATA_PORT & 0xF0) | ((data & 0xF0) >> 4);
#endif

	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	CLEAR_BIT(PORT_CONTROL,E); /* disable LCD E=0 */
	_delay_ms(1); /* delay for processing Th = 13ns */
	SET_BIT(PORT_CONTROL,E); /* Enable LCD E=1 */
	_delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */

	/* out the lowest 4 bits of the required data to the data bus D4 --> D7 */
#ifdef UPPER_PORT_PINS
	LCD_DATA_PORT = (LCD_DATA_PORT & 0x0F) | ((data & 0x0F) << 4);
#else
	LCD_DATA_PORT = (LCD_DATA_PORT & 0xF0) | (data & 0x0F);
#endif

	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	CLEAR_BIT(PORT_CONTROL,E); /* disable LCD E=0 */
	_delay_ms(1); /* delay for processing Th = 13ns */
#elif (BITS_DATA_MODE == 8)
	DATA_PORT = command; /* out the required command to the data bus D0 --> D7 */
	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	CLEAR_BIT(PORT_CONTROL,E); /* disable LCD E=0 */
	_delay_ms(1); /* delay for processing Th = 13ns */
#endif
}

void LCD_displayString(const uint8 *Str)
{
 uint8 i=0;
 while(Str[i] != '\0')
  {
    LCD_displayCharacter(Str[i]);
      i++;
  }
}


void LCD_goToRowColumn(uint8 row,uint col)
{
  
  uint8 Address;
   
  switch(row)
  {
   case 0:
         Address = col;
          break;
     
  case 1: 
         Address = 40+col;
         break;

 case 2: 
        Address = 50+col;
        break;
  }
    /* that is mentioned in datasheet, to write to
       a specific address you have first to make it
       set cursor locationusing the command 0b10000000 added to the address */
       LCD_sendCommand(Address | CURSOR_LOCATION); 
}
 
 void LCD_clearScreen(void)
{
	LCD_sendCommand(CLEAR_LCD); //clear display 
}
       
  
 