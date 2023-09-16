/*
 * lcd.h
 *
 * Created: 7/29/2023 5:06:43 PM
 *  Author: Ahmed shaban
 */ 


#ifndef LCD_H_
#define LCD_H_
//#define F_CPU 1000000UL
#include<avr/io.h>
#include<util/delay.h>
#include "DIO.h"
#include <stdbool.h>

#define F_CPU 1000000UL
#define LCD_PORT             PORTA      
#define DataDir_LCD_PORT     DDRA

#define LCD_CTRL            PORTB         
#define DataDir_LCD_CTRL    DDRB 

#define RS_SWITCH 3   //SELECT REGISTER ( 1 FOR DATA | 0 FOR COMMAND)
#define RW_SWITCH 2  //read _ write register ( 1for reed | 0 for write)
#define EN_SWITCH 1  // enable  to start
#define  shift 4
#define EIGHT_BIT_MODE
//#define FOUR_BIT_MODE

 // the command that can be handle 
#define LCD_FUNCTION_8BIT_2LINES   					(0x38)
#define LCD_FUNCTION_4BIT_2LINES   					(0x28)
#define LCD_MOVE_DISP_RIGHT       					(0x1C)
#define LCD_MOVE_DISP_LEFT   						(0x18)
#define LCD_MOVE_CURSOR_RIGHT   					(0x14)
#define LCD_MOVE_CURSOR_LEFT 	  					(0x10)
#define LCD_DISP_OFF   								(0x08)
#define LCD_DISP_ON_CURSOR   						(0x0E)
#define LCD_DISP_ON_CURSOR_BLINK   					(0x0F)
#define LCD_DISP_ON_BLINK   						(0x0D)
#define LCD_DISP_ON   								(0x0C)
#define LCD_ENTRY_DEC   							(0x04)
#define LCD_ENTRY_DEC_SHIFT   						(0x05)
#define LCD_ENTRY_INC_   							(0x06)
#define LCD_ENTRY_INC_SHIFT   						(0x07)
#define LCD_BEGIN_AT_FIRST_ROW						(0x80)
#define LCD_BEGIN_AT_SECOND_ROW						(0xC0)
#define LCD_CLEAR_SCREEN							(0x01)
#define LCD_ENTRY_MODE								(0x06)

//funcation that use

void LCD_INIT();
void LCD_WRITE_COMMAND(unsigned char command);
void LCD_WRITE_CHAR(unsigned char character);
void LCD_WRITE_STRING(char* string);
void LCD_check_lcd_isbusy();
void LCD_lcd_kick(void);
void LCD_clear_screen();
void LCD_GOTO_XY(unsigned char line, unsigned char position);
void display_int_number(uint32_t number);
void display_float_number(float number,uint8_t decimal_places);





#endif /* LCD_H_ */