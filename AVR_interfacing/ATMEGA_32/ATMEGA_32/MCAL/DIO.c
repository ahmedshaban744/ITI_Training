/*
 * DIO.c
 *
 * Created: 8/22/2023 2:36:49 PM
 *  Author: Ahmed shaban
 */ 
#include "DIO.h"
void MCAL_DIO_PORT_Dir(uint8_t port_num,uint8_t dir)
{
	switch(port_num)
	{
	case DIO_PORTA : DDRA=dir; break;
    case DIO_PORTB : DDRB=dir; break;
    case DIO_PORTC : DDRC=dir; break;
	case DIO_PORTD : DDRD=dir; break;
		
	}
}
void MCAL_DIO_PORT_val(uint8_t port_num,uint8_t val)
{	switch(port_num)
	{
		case DIO_PORTA : PORTA=val; break;
		case DIO_PORTB : PORTB=val; break;
		case DIO_PORTC : PORTC=val; break;
		case DIO_PORTD : PORTD=val; break;
		
	}
	
}
void MCAL_DIO_PIN_Dir(uint8_t port_num, uint8_t pin_num, uint8_t dir)
{
switch(dir)
{
case DIO_pin_OUT:
     switch(port_num)
	 {
		 case DIO_PORTA: SET_BIT(DDRA ,pin_num); break;
         case DIO_PORTB: SET_BIT(DDRB ,pin_num); break;
         case DIO_PORTC: SET_BIT(DDRC ,pin_num); break;
         case DIO_PORTD: SET_BIT(DDRD ,pin_num); break;	 
	 }
	 break;
case DIO_pin_INT:
     switch(port_num)
     {
	     case DIO_PORTA: CLR_BIT(DDRA ,pin_num); break;
	     case DIO_PORTB: CLR_BIT(DDRB ,pin_num); break;
	     case DIO_PORTC: CLR_BIT(DDRC ,pin_num); break;
	     case DIO_PORTD: CLR_BIT(DDRD ,pin_num); break;     
     }
	 break;
}
}
void MCAL_DIO_PIN_val(uint8_t port_num, uint8_t pin_num, uint8_t val)
{
switch(val)
{
	case DIO_pin_HIGH :
	switch(port_num)
	{
		case DIO_PORTA: SET_BIT(PORTA ,pin_num); break;
		case DIO_PORTB: SET_BIT(PORTB ,pin_num); break;
		case DIO_PORTC: SET_BIT(PORTC ,pin_num); break;
		case DIO_PORTD: SET_BIT(PORTD ,pin_num); break;
	}
	break;
	case DIO_pin_LOW:	
	switch(port_num)
	{
		case DIO_PORTA: CLR_BIT(PORTA ,pin_num); break;
		case DIO_PORTB: CLR_BIT(PORTB ,pin_num); break;
		case DIO_PORTC: CLR_BIT(PORTC ,pin_num); break;
		case DIO_PORTD: CLR_BIT(PORTD ,pin_num); break;
	
	}
	break;
}
}
void MCAL_DIO_PIN_toggle(uint8_t port_num, uint8_t pin_num)
{
switch(port_num)
{
	case DIO_PORTA : TOG_BIT(PORTA,pin_num); break;
	case DIO_PORTB : TOG_BIT(PORTB,pin_num); break;
	case DIO_PORTC : TOG_BIT(PORTC,pin_num); break;
	case DIO_PORTD : TOG_BIT(PORTD,pin_num); break;
	
}
}
uint8_t MCAL_DIO_Read_pin(uint8_t port_num, uint8_t pin_num)
{
switch(port_num)
{
	case DIO_PORTA :return GET_BIT(PORTA,pin_num); break;
	case DIO_PORTB : return GET_BIT(PORTB,pin_num); break;
	case DIO_PORTC : return GET_BIT(PORTC,pin_num); break;
	case DIO_PORTD : return GET_BIT(PORTD,pin_num); break;
	
}
}
void MCAL_DIO_PIN_PULL_UP(uint8_t port_num , uint8_t pin_num)
{
		switch(port_num)
		{
		case DIO_PORTA: SET_BIT(PORTA ,pin_num); break;
		case DIO_PORTB: SET_BIT(PORTB ,pin_num); break;
		case DIO_PORTC: SET_BIT(PORTC ,pin_num); break;
		case DIO_PORTD: SET_BIT(PORTD ,pin_num); break;
			
		}
	
}
