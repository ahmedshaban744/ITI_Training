/*
 * ADC.h
 *
 * Created: 8/31/2023 12:51:13 AM
 *  Author: Ahmed shaban
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

#ifndef ADC_H_
#define ADC_H_

typedef struct
{
	uint8_t  refrence_volt;   //@ADC_refrence_volt
	uint8_t  result_state;    //@ADC_result_state
	//uint8_t  ADCX;           //@ADC_ADCX
	uint8_t Prescaler ;      //@ADC_Prescaler
	uint8_t interrput ;      //@ADC_interrput
	uint8_t  Auto_Trigger;   //@ADC_Auto_Trigger
	
	
}ADC_Confeg;
extern ADC_Confeg;
//===========================================================================
//=========================macros==============================================
//=============================================================================

//@ADC_refrence_volt
#define ADC_AREF_refrence                    (uint8_t)(0)
#define ADC_AVCC_refrence                    (uint8_t)((0b1<<6) & 0b11)
#define ADC_internal_two_and__half_refrence  (uint8_t)((0b11<<6) & 0b11)

//@ADC_result_state
#define left_Adjust                         (uint16_t)(1<<5)
#define right_Adjust                        (uint16_t)(0)
//@ADC_ADCX
#define ADC0                                0
#define ADC1                                1
#define ADC2                                2
#define ADC3                                3
#define ADC4                                4
#define ADC5                                5
#define ADC6                                6
#define ADC7                                7

//@ADC_Prescaler
#define ADC_2_Prescaler                    ( uint8_t)(0)
#define ADC_4_Prescaler                    (uint8_t) (2<<0 &0b111)
#define ADC_8_Prescaler                    (uint8_t) (3<<0 &0b111)
#define ADC_16_Prescaler                   (uint8_t) (4<<0 &0b111)
#define ADC_32_Prescaler                   (uint8_t) (5<<0 &0b111)
#define ADC_64_Prescaler                   (uint8_t) (6<<0 &0b111)
#define ADC_128_Prescaler                  (uint8_t) (7<<0 &0b111)

//@ADC_interrput
#define ADC_interrput_enable               ( uint8_t)(1<<3)
#define ADC_interrput_disable              ( uint8_t)(0)

//@ADC_Auto_Trigger
#define ADC_Auto_Trigger_enable               ( uint8_t)(1<<5)

#define ADC_Auto_Trigger_disable              ( uint8_t)(0)

//=============================================================================
//============================APIS=============================================
//=============================================================================
void MCAL_ADC_INIT(uint8_t ADCX, ADC_Confeg*ADC_define);
uint16_t MCAL_ADC_REED(uint8_t ADCX,ADC_Confeg*ADC_define);
#endif /* ADC_H_ */