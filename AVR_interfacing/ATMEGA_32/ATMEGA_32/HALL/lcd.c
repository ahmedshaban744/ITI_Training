/*
 * lcd.c
 *
 * Created: 7/29/2023 5:07:15 PM
 *  Author: Ahmed shaban
 */


#include "lcd.h"

void LCD_GOTO_XY(unsigned char line, unsigned char position){
	if (line == 1)
	{
		if (position < 16 && position >= 0)
		{
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW+position);
		}
	}
	if (line == 2)
	{
		if (position < 16 && position >= 0)
		{
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_SECOND_ROW+position);
		}
	}
}

void LCD_INIT()
{
	_delay_ms(20);

	DataDir_LCD_CTRL |= (1<<EN_SWITCH | 1<<RS_SWITCH | 1<<RW_SWITCH); // DDRB   (enable the register , send data , read mode)
	LCD_CTRL &= ~ (1<<EN_SWITCH | 1<<RS_SWITCH | 1<<RW_SWITCH);      // PORTB   (disable the register  , send command , write mode)
	
	DataDir_LCD_PORT = 0xFF;
	_delay_ms(15);
	LCD_clear_screen(); 
	
	#ifdef EIGHT_BIT_MODE
	//LCD_check_lcd_isbusy();
	LCD_WRITE_COMMAND(LCD_FUNCTION_8BIT_2LINES);
	#endif
	#ifdef FOUR_BIT_MODE
	LCD_check_lcd_isbusy();
	LCD_WRITE_COMMAND(0x02);
	LCD_WRITE_COMMAND(LCD_FUNCTION_4BIT_2LINES);
    /* send for 4 bit initialization of LCD  */
	//LCD_WRITE_COMMAND(0x28);              /* 2 line, 5*7 matrix in 4-bit mode */
	//LCD_WRITE_COMMAND(0x0c);              /* Display on cursor off*/
	//LCD_WRITE_COMMAND(0x06);              /* Increment cursor (shift cursor to right)*/
	//LCD_WRITE_COMMAND(0x01);
	//LCD_WRITE_COMMAND(0x02);
	
	#endif
		LCD_WRITE_COMMAND(LCD_ENTRY_MODE);
		LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW);
		LCD_WRITE_COMMAND(LCD_DISP_ON_CURSOR_BLINK);
}
void LCD_clear_screen(){
	LCD_WRITE_COMMAND(LCD_CLEAR_SCREEN);
}

void LCD_lcd_kick(){
	LCD_CTRL |= (1 << EN_SWITCH);
	_delay_ms(50);
	LCD_CTRL &= ~(1 << EN_SWITCH);
}
void LCD_WRITE_COMMAND(unsigned char command){
	//LCD_check_lcd_isbusy();
	#ifdef EIGHT_BIT_MODE
	LCD_check_lcd_isbusy();
	LCD_PORT = command; // put the command  at port-A
	LCD_CTRL &= ~((1 << RS_SWITCH) | (1<<RW_SWITCH));  //  make portB select command and at read mode
	_delay_ms(1);
	LCD_lcd_kick();
	#endif
	
	
	
	#ifdef FOUR_BIT_MODE
	LCD_check_lcd_isbusy();
	LCD_PORT = (LCD_PORT & 0x0F) | (command & 0xF0);
	LCD_CTRL &= ~ ((1<<RW_SWITCH)|(1<<RS_SWITCH));
	_delay_ms(5);
	LCD_lcd_kick ();
	LCD_PORT = (LCD_PORT & 0x0F) | (command << 4);
	LCD_CTRL &= ~ ((1<<RW_SWITCH)|(1<<RS_SWITCH));
	_delay_ms(1);
	LCD_lcd_kick();
	#endif
}
void LCD_WRITE_CHAR(unsigned char character){
	#ifdef EIGHT_BIT_MODE
	LCD_check_lcd_isbusy();
	LCD_PORT = character;
	LCD_CTRL &= ~(1 << RW_SWITCH);
	LCD_CTRL |= (1 << RS_SWITCH);
	_delay_ms(1);
	LCD_lcd_kick();
	#endif
	#ifdef FOUR_BIT_MODE
	LCD_check_lcd_isbusy();
	LCD_PORT = (LCD_PORT & 0x0F) | (character & 0xF0);
	LCD_CTRL |= 1<<RS_SWITCH; //turn RS ON for Data mode.
	LCD_CTRL &= ~ (1<<RW_SWITCH);//turn RW off so you can write.
	_delay_ms(1);
	LCD_lcd_kick();
	LCD_PORT = (LCD_PORT & 0x0F) | (character << 4);
	LCD_CTRL |= 1<<RS_SWITCH; //turn RS ON for Data mode.
	LCD_CTRL &= ~ (1<<RW_SWITCH);//turn RW off so you can write.
	_delay_ms(1);
	LCD_lcd_kick ();
	#endif
}

void LCD_WRITE_STRING(char* string){
	int count = 0;
	while (*string > 0){
		count++;
		LCD_WRITE_CHAR(*string++);
		if (count == 16)
		{
			LCD_GOTO_XY(2,0);
		}
		else if (count == 32)
		{
			LCD_clear_screen();
			LCD_GOTO_XY(1,0);
			count = 0;
		}
	}
}
void LCD_check_lcd_isbusy(){
	DataDir_LCD_PORT &= ~(0xFF<<shift);
	LCD_CTRL |= (1 << RW_SWITCH);
	LCD_CTRL &= ~(1 << RS_SWITCH);
	LCD_lcd_kick();
	DataDir_LCD_PORT |= (0xFF<<4);
	LCD_CTRL &= ~(1 << RW_SWITCH);
	
}
void display_int_number(uint32_t number)
{ 

	uint32_t num = 0;
	if(number < 0)
	{
		LCD_WRITE_CHAR(' - ');
	    number = number*(-1);
	}
	 else if(number == 0)
	{
		LCD_WRITE_CHAR('0');
		
	}
	 char buffer[12];
	 int i=0;
	while(number)
	{
		
		 buffer[i++] = '0' + (number % 10);
		 number /= 10;
		//num *= 10;
		//num += number %10 ;
		//number /= 10;

	}

	while(i>0)
	{
		 LCD_WRITE_CHAR(buffer[--i]);
		//LCD_WRITE_CHAR((num %10) + '0');
		//num/=10;
	}
}

void display_float_number(float number, uint8_t decimal_places)
{
	if (number < 0)
	{
		LCD_WRITE_CHAR('-');
		number = -number;
	}

	// Extract the integer part
	int32_t int_part = (int32_t)number;

	// Display the integer part
	if (int_part == 0)
	{
		LCD_WRITE_CHAR('0');
	}
	else
	{
		char int_str[20]; // Adjust buffer size as needed
		int i = 0;
		while (int_part > 0)
		{
			int_str[i++] = '0' + (int_part % 10);
			int_part /= 10;
		}
		for (int j = i - 1; j >= 0; j--)
		{
			LCD_WRITE_CHAR(int_str[j]);
		}
	}

	// Check if we need to display a decimal point
	if (decimal_places > 0)
	{
		LCD_WRITE_CHAR('.');
	}

	// Extract and display the decimal part
	float decimal_part = number - (float)int_part;
	for (uint8_t dp = 0; dp < decimal_places; dp++)
	{
		decimal_part *=(int) 10;
		int digit = (int)decimal_part;
		LCD_WRITE_CHAR('0' + digit);
		decimal_part -= (float)digit;
	}

	// Handle the case where decimal places are 0 (e.g., "40.0")
	if (decimal_places == 0)
	{
		LCD_WRITE_CHAR('0');
	}
}
