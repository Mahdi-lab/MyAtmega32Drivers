/***********************************************
 *                                             *
 * Module: KEYPAD                              *
 *                                             *
 * File Name: keypad.c                         *
 *                                             *
 * Description: Keypad driver source code file *
 *                                             *
 * Author: Mahdi Gamal                         *
 *                                             *
 ***********************************************

 /* include Keypad header file */
  #include "keypad.h"

 /**************************************
  *     Private Functions Prototypes   *
  **************************************
/* if number of column of keypad = 3 (4 x 3 "keypad" ) 
  the function " keypad_4x3_AdjustKeyNumber" will be processed" */
 #if(N_col == 3)
 static uint8 keypad_4x3_AdjustKeyNumbe(uint8 button_number);

/* if number of column of keypad = 4 (4 x 4 "keypad" ) 
  the function " keypad_4x4_AdjustKeyNumber" will be processed" */
  #elif*N_col == 4)
  static uint8 keypad_4x4_AdjustKeyNumbe(uint8 button_number);

#endif
/*************************************************/

/**********************************************
 *            Functions Definitions           *
 **********************************************/

 uint8 Key_Pad_getPressedKEY(void)
{
 uint8 col,row;
  while(1)
   {
     for(col=0;col<N_col;col++){

      KEYPAD_PORT_DIR = (0b00010000<<col);
     
   
      KEYPAD_PORT_OUR = (~(0b00010000<<col));

       for(row=0;row<N_row;row++)
          { 
            if(BIT_IS_CLEAR(KEYPAD_PORT_IN,row))
               { 
                 #if (N_col == 3)
                      return keypad_4x3_AdjustKeyNumber(uint8 button_number);
                  #elif (N_col == 4)         
                          return keypad_4x4_AdjustKeyNumber(uint8 button_number);
                    #endif
           }
          }
         } 
       }
}

/* if number of column of keypad = 3 (4 x 3 "keypad" ) 
  the function " keypad_4x3_AdjustKeyNumber" will be processed" */
#if (N_col == 3)
static uint8 keypad_4x3_AdjustKeyNumber(uint8 button_number)
{
   switch(button_number)
    {
      case 10: return '*'; /* ASCII Code of =   */
               break;
      case 11: return '0';
               break;
      case 12: return '#'; /* ASCII Code of     */
               break;
      default: return (button_number); 
    }
}

/* if number of column of keypad = 4 (4 x 4 "keypad" ) 
  the function " keypad_4x4_AdjustKeyNumber" will be processed" */
#elif (N_col == 4)
static uint8 Keypad_4x4_AdjustKeyNumber(uint8 button_number)
{
 switch(button_number)
  {
     case 1: return 7;
             break;
     case 2: return 8;
             break;
     case 3: return 9;
             break;
     case 4: return '%'; /* ASCII Code of '%' */
             break;
     case 5: return 4;
             break;
     case 6: return 5;
             break;
     case 7: return 6;
             break;
     case 8: return '*';  /* ASCII Code of '*' */
             break;
     case 9: return 1;
             break;
     case 10: return 2;
             break;
     case 11: return 3;
             break;
     case 12: return '-';  /* ASCII Code of '-' */
              break;
     case 13: return 13;   /* ASCII Code for "Enter" */
              break;
     case 14: return 0;
              break;
     case 15: return '=';  /* ASCII Code of '=' */
              break;
     case 16: return '+';  /* ASCII Code of '+' */
              break;
     default: return(button_number);
   }
}

/*End of functions macro conditions */
#endif