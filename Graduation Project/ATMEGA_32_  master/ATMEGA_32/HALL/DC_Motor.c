/*
 * DC_Motor.c
 *
 * Created: 8/24/2023 12:52:46 PM
 *  Author: Ahmed shaban
 */ 
#include "DC_Motor.h"
/*
potr==  
  DIO_PORTA        for PORTA
  DIO_PORTB        for PORTB
  DIO_PORTC        for PORTC
  DIO_PORTD        for PORTD 

*/
void HALL_DC_MOTOR_forword(uint8_t potr ,uint8_t pin_1, uint8_t pin_2)
{
	
MCAL_DIO_PIN_Dir( potr,  pin_1,DIO_pin_OUT);
MCAL_DIO_PIN_Dir( potr,  pin_2,DIO_pin_OUT);

MCAL_DIO_PIN_val( potr,  pin_1 , DIO_pin_HIGH );
	_delay_ms(20);
MCAL_DIO_PIN_val( potr,  pin_2, DIO_pin_LOW );
	_delay_ms(20); 

}
void HALL_DC_MOTOR_backword(uint8_t potr ,uint8_t pin_1, uint8_t pin_2)
{
	
MCAL_DIO_PIN_Dir( potr,  pin_1,DIO_pin_OUT);
MCAL_DIO_PIN_Dir( potr,  pin_2,DIO_pin_OUT);

MCAL_DIO_PIN_val( potr,  pin_1 , DIO_pin_LOW );
//_delay_ms(20);
MCAL_DIO_PIN_val( potr,  pin_2 , DIO_pin_HIGH );
//_delay_ms(20);

}
void HALL_DC_MOTOR_stop(uint8_t potr ,uint8_t pin_1, uint8_t pin_2)
{
	
MCAL_DIO_PIN_Dir( potr,  pin_1,DIO_pin_OUT);
MCAL_DIO_PIN_Dir( potr,  pin_2,DIO_pin_OUT);

MCAL_DIO_PIN_val( potr,  pin_1 , DIO_pin_LOW );
//_delay_ms(20);
MCAL_DIO_PIN_val( potr,  pin_1 , DIO_pin_LOW );
//_delay_ms(20);	
	
	
	
}