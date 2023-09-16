/*
 * EXTI.c
 *
 * Created: 8/28/2023 8:20:12 PM
 *  Author: Ahmed
 */

//===========================================================================
//=========================includes==========================================
//===========================================================================
#include <avr/io.h>
#include <avr/interrupt.h>
#include "EXTI.h"
#include "bit_prosess.h"
#include "DIO.h"
#include <util/delay.h>

void MCAL_EXTI_1_ENABLE(uint8_t state)
{
	//enable  the globle interrput 
	SET_BIT(SREG,7);
	//chose interrput state
	switch(state)
	{
		case low_level_of_INT1: CLR_BIT(MCUCR,2); CLR_BIT(MCUCR,3); break;
		case Any_logical_change_on_INT1: CLR_BIT(MCUCR,3); SET_BIT(MCUCR,2); break;
		case falling_edge_of_INT1: SET_BIT(MCUCR,3); CLR_BIT(MCUCR,2); break;
		case rising_edge_of_INT1: SET_BIT(MCUCR,2); SET_BIT(MCUCR,3); break;
	}
	//enable the interrput in EXTI peripherals
	SET_BIT(GICR,7);
	//pin configure
		     MCAL_DIO_PIN_PULL_UP(DIO_PORTD,PD3);
		     MCAL_DIO_PIN_Dir(DIO_PORTD,PD3,DIO_pin_INT);
	
}
void MCAL_EXTI_0_ENABLE(uint8_t state)
{
//enable  the globe interrput
SET_BIT(SREG,7);
//chose interrput state
switch(state)
{
	case low_level_of_INT0: CLR_BIT(MCUCR,2); CLR_BIT(MCUCR,3); break;
	case Any_logical_change_on_INT0: CLR_BIT(MCUCR,3); SET_BIT(MCUCR,2); break;
	case falling_edge_of_INT0: SET_BIT(MCUCR,3); CLR_BIT(MCUCR,2); break;
	case rising_edge_of_INT0: SET_BIT(MCUCR,2); SET_BIT(MCUCR,3); break;
}
//enable the interrput in EXTI peripherals
SET_BIT(GICR,6);

   //pin configuer
	     MCAL_DIO_PIN_PULL_UP(DIO_PORTD,PD2);
	     MCAL_DIO_PIN_Dir(DIO_PORTD,PD2,DIO_pin_INT);	
}
void MCAL_EXTI_2_ENABLE(uint8_t state)
{
	//enable  the globle interrput
	SET_BIT(SREG,7);
	//chose interrput state
	
	switch(state)
	{
		case falling_edge_of_INT2: CLR_BIT(MCUCSR,6); break;
		case rising_edge_of_INT2: SET_BIT(MCUCSR,6); break;

	}
	//enable the interrput in EXTI peripherals
	SET_BIT(GICR,5);	
	//pin configuer
			  MCAL_DIO_PIN_PULL_UP(DIO_PORTB,PD2);
			  MCAL_DIO_PIN_Dir(DIO_PORTB,PD2,DIO_pin_INT);
			  
}


//ISR
ISR(INT0_vect)
{     MCAL_DIO_PIN_PULL_UP(DIO_PORTD,PD2);
	 MCAL_DIO_PIN_val(DIO_PORTD,PD6,DIO_pin_LOW);
	 
}

ISR(INT2_vect)
{


}
ISR(INT1_vect)
{	MCAL_DIO_PORT_Dir(DIO_PORTA ,DIO_PORT_INT);
	MCAL_DIO_PORT_Dir(DIO_PORTB ,DIO_PORT_INT);
	MCAL_DIO_PORT_Dir(DIO_PORTC ,DIO_PORT_INT);
	MCAL_DIO_PORT_Dir(DIO_PORTD ,DIO_PORT_INT);
 
}

