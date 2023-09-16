/*
 * stepper_motor.c
 *
 * Created: 8/28/2023 6:48:15 PM
 *  Author: Ahmed
 */ 

	#include "DIO.h"
	#include "stepper_motor.h"
	#include "bit_prosess.h"
	
void stepper_morot_init(uint8_t  port ,uint8_t pin1 , uint8_t pin2 ,uint8_t pin3 ,uint8_t pin4 )
{
MCAL_DIO_PIN_Dir(port ,pin1,DIO_pin_OUT);
MCAL_DIO_PIN_Dir(port ,pin2,DIO_pin_OUT);
MCAL_DIO_PIN_Dir(port ,pin3,DIO_pin_OUT);
MCAL_DIO_PIN_Dir(port ,pin4,DIO_pin_OUT);	
}
void stepper_morot_deinit(uint8_t  port ,uint8_t pin1 , uint8_t pin2 ,uint8_t pin3 ,uint8_t pin4 )
{
	MCAL_DIO_PIN_Dir(port ,pin1,DIO_pin_INT);
	MCAL_DIO_PIN_Dir(port ,pin2,DIO_pin_INT);
	MCAL_DIO_PIN_Dir(port ,pin3,DIO_pin_INT);
	MCAL_DIO_PIN_Dir(port ,pin4,DIO_pin_INT);
}
void stepper_morot_CW(uint8_t  port , uint8_t angle, uint8_t pin1 , uint8_t pin2 ,uint8_t pin3 ,uint8_t pin4 )
{ 
	
	uint8_t itration =(angle/motor_step)/4 ;
	for(int i=0 ;i<=itration;i++)
	{
		//STEP1
		MCAL_DIO_PIN_val(port,pin1,DIO_pin_HIGH);
		MCAL_DIO_PIN_val(port,pin2,DIO_pin_LOW);
		MCAL_DIO_PIN_val(port,pin3,DIO_pin_LOW);
		MCAL_DIO_PIN_val(port,pin4,DIO_pin_LOW);
		_delay_ms(50);
       //STEP2
       MCAL_DIO_PIN_val(port,pin1,DIO_pin_LOW);
       MCAL_DIO_PIN_val(port,pin2,DIO_pin_HIGH);
       MCAL_DIO_PIN_val(port,pin3,DIO_pin_LOW);
		MCAL_DIO_PIN_val(port,pin4,DIO_pin_LOW);
	  _delay_ms(50);
				
		//STEP3
	  MCAL_DIO_PIN_val(port,pin1,DIO_pin_LOW);
	  MCAL_DIO_PIN_val(port,pin2,DIO_pin_LOW);
	  MCAL_DIO_PIN_val(port,pin3,DIO_pin_HIGH);
	  MCAL_DIO_PIN_val(port,pin4,DIO_pin_LOW);
	_delay_ms(50);
						
	//STEP4
		MCAL_DIO_PIN_val(port,pin1,DIO_pin_LOW);
	    MCAL_DIO_PIN_val(port,pin2,DIO_pin_LOW);
        MCAL_DIO_PIN_val(port,pin3,DIO_pin_LOW);
       MCAL_DIO_PIN_val(port,pin4,DIO_pin_HIGH);
		_delay_ms(50);
								
		
	}
	
}
void stepper_morot_CCW(uint8_t  port ,  uint8_t angle, uint8_t pin1 , uint8_t pin2 ,uint8_t pin3 ,uint8_t pin4 )
{
	uint8_t itration =(angle/motor_step)/4 ;
	for(int i=0 ;i<=itration;i++)
	{
		//STEP1
		MCAL_DIO_PIN_val(port,pin1,DIO_pin_LOW);
		MCAL_DIO_PIN_val(port,pin2,DIO_pin_LOW);
		MCAL_DIO_PIN_val(port,pin3,DIO_pin_LOW);
		MCAL_DIO_PIN_val(port,pin4,DIO_pin_HIGH);
		_delay_ms(50);
		//STEP2
	     MCAL_DIO_PIN_val(port,pin1,DIO_pin_LOW);
	     MCAL_DIO_PIN_val(port,pin2,DIO_pin_LOW);
	     MCAL_DIO_PIN_val(port,pin3,DIO_pin_HIGH);
	     MCAL_DIO_PIN_val(port,pin4,DIO_pin_LOW);
	    _delay_ms(50);
		
		//STEP3
       MCAL_DIO_PIN_val(port,pin1,DIO_pin_LOW);
       MCAL_DIO_PIN_val(port,pin2,DIO_pin_HIGH);
       MCAL_DIO_PIN_val(port,pin3,DIO_pin_LOW);
       MCAL_DIO_PIN_val(port,pin4,DIO_pin_LOW);
       _delay_ms(50);
		
		//STEP4
		MCAL_DIO_PIN_val(port,pin1,DIO_pin_HIGH);
		MCAL_DIO_PIN_val(port,pin2,DIO_pin_LOW);
		MCAL_DIO_PIN_val(port,pin3,DIO_pin_LOW);
		MCAL_DIO_PIN_val(port,pin4,DIO_pin_LOW);
		_delay_ms(50);
		
	}
}

