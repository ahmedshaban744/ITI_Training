/*
 * ATMEGA_32.c
 *
 * Created: 8/16/2023 3:42:38 PM
 * Author : Ahmed shaban
 */ 

#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 8000000UL
#include "bit_prosess.h"
#include "DIO.h"
#include "lcd.h"
#include "keypad.h"
#include "EXTI.h"
#include "stepper_motor.h"
#include "ADC.h"
#include "LM35.h"


int main(void)
{ 
	 HALL_LM35_INIT();
	 LCD_INIT();	   
while(1)
{
LCD_clear_screen();
uint32_t data ;
data=HALL_LM35_REED();

display_int_number(data);

_delay_ms(500);
LCD_clear_screen();
}	

}
