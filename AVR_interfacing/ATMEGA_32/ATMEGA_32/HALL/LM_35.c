/*
 * LM_35.c
 *
 * Created: 8/31/2023 2:20:28 PM
 *  Author: Ahmed
 */ 
#include "LM35.h"

void HALL_LM35_INIT()
{     ADC_Confeg  ADC_define;
	
	ADC_define.Auto_Trigger= ADC_Auto_Trigger_enable;
	ADC_define.result_state= right_Adjust;
	ADC_define.Prescaler= ADC_64_Prescaler;
	ADC_define.refrence_volt= ADC_AVCC_refrence;
	ADC_define.interrput=ADC_interrput_disable;
	MCAL_ADC_INIT(ADC0,& ADC_define);
	
}
uint16_t HALL_LM35_REED()
{
        ADC_Confeg  ADC_define;
		
		ADC_define.Auto_Trigger= ADC_Auto_Trigger_enable;
		ADC_define.result_state= right_Adjust;
		ADC_define.Prescaler= ADC_64_Prescaler;
		ADC_define.refrence_volt= ADC_AVCC_refrence;
		SET_BIT(ADMUX,6);
		ADC_define.interrput=ADC_interrput_disable;
		
        uint16_t steps= MCAL_ADC_REED( ADC0, &ADC_define);
		uint16_t analogVoltage = (steps * 5000.0) /1024 ;
		uint16_t temp = analogVoltage /10;
		return temp;
}