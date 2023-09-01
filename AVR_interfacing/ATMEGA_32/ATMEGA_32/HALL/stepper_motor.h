/*
 * stepper_motor.h
 *
 * Created: 8/28/2023 6:48:52 PM
 *  Author: Ahmed
 */ 


#ifndef STEPPER_MOTOR_H_
#define STEPPER_MOTOR_H_
#define  motor_step   1
#include <util/delay.h>
#include "DIO.h"
void stepper_morot_init(uint8_t  port ,uint8_t pin1 , uint8_t pin2 ,uint8_t pin3 ,uint8_t pin4 );
void stepper_morot_deinit(uint8_t  port ,uint8_t pin1 , uint8_t pin2 ,uint8_t pin3 ,uint8_t pin4 );
void stepper_morot_CW(uint8_t  port , uint8_t angle, uint8_t pin1 , uint8_t pin2 ,uint8_t pin3 ,uint8_t pin4 );
void stepper_morot_CCW(uint8_t  port ,  uint8_t angle, uint8_t pin1 , uint8_t pin2 ,uint8_t pin3 ,uint8_t pin4 );



#endif /* STEPPER_MOTOR_H_ */