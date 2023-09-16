/*
 * ADC.c
 *
 * Created: 8/31/2023 12:51:00 AM
 *  Author: Ahmed shaban
 */ 
#include "ADC.h"
//#define a   *(volatile uint8_t *)(0x26)
#define NULL ((void *)0)
ADC_Confeg * GL_ADC_configs [8] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
void MCAL_ADC_INIT(uint8_t ADCX, ADC_Confeg * ADC_define)
{
	//ADC enable
	//ADCSRA|=1<<7;
	switch(ADCX)
	{
	case ADC0 : ADMUX|=((0 <<0) &0x1F) ;GL_ADC_configs[0]=ADC_define; break;
    case ADC1 : ADMUX|=((1 <<0 )&0x1F) ;GL_ADC_configs[1]=ADC_define; break;
    case ADC2 : ADMUX|=((2 <<0 )&0x1F) ;GL_ADC_configs[2]=ADC_define; break;
    case ADC3 : ADMUX|=((3 <<0 )&0x1F) ;GL_ADC_configs[3]=ADC_define; break;
    case ADC4 : ADMUX|=((4<<0 )&0x1F) ;GL_ADC_configs[4]=ADC_define; break;
    case ADC5 : ADMUX|=((5 <<0 )&0x1F) ;GL_ADC_configs[5]=ADC_define; break;
    case ADC6 : ADMUX|=((6 <<0 )&0x1F) ;GL_ADC_configs[6]=ADC_define; break;
    case ADC7 : ADMUX|=((7 <<0 )&0x1F) ;GL_ADC_configs[7]=ADC_define; break;
	}
	//Reference volt
	ADMUX |= ADC_define->refrence_volt;

	//RESULT STATE
	ADMUX |=ADC_define->result_state;
	//Prescaler
	ADCSRA |=ADC_define->Prescaler;
	ADCSRA |=ADC_define->interrput;	
	//Auto_Trigger
	ADCSRA|=ADC_define->Auto_Trigger;
	   }
	
uint16_t MCAL_ADC_REED(uint8_t ADCX , ADC_Confeg*ADC_define)
{
		SET_BIT(ADCSRA,7);
	//start Conversion
	SET_BIT(ADCSRA,6);
 
	
	switch(ADCX)
	{
		case ADC0 :  GL_ADC_configs[0]=ADC_define; break;
		case ADC1 :  GL_ADC_configs[1]=ADC_define; break;
		case ADC2 :  GL_ADC_configs[2]=ADC_define; break;
		case ADC3 :  GL_ADC_configs[3]=ADC_define; break;
		case ADC4 :  GL_ADC_configs[4]=ADC_define; break;
		case ADC5 :  GL_ADC_configs[5]=ADC_define; break;
		case ADC6 :  GL_ADC_configs[6]=ADC_define; break;
		case ADC7 :  GL_ADC_configs[7]=ADC_define; break;
	}
		
		
		//polling to register ADCSRA bit 4 until finishing Conversion
		while(GET_BIT(ADCSRA,4)==0);
		// return the value
	if(ADC_define->result_state==left_Adjust)
		{
		uint16_t digital_val;
		digital_val|=ADCL<<6;
		digital_val|=ADCH<<8;
	//return digital_val;
	return ADC ;
		}
    else if(ADC_define->result_state==right_Adjust)
	{
	uint16_t digital_val;
	digital_val=ADCL;
	digital_val|=ADCH<<8;
	//return digital_val;	
	return ADC ;
	}
	
	}
	
