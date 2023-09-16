/*
 * DC_Motor.h
 *
 * Created: 8/24/2023 12:51:49 PM
 *  Author: Ahmed
 */ 
#include "DIO.h"
#include "bit_prosess.h"
#include <util/delay.h>



#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

void HALL_DC_MOTOR_forword(uint8_t potr ,uint8_t pin_1, uint8_t pin_2);
void HALL_DC_MOTOR_backword(uint8_t potr ,uint8_t pin_1, uint8_t pin_2);
void HALL_DC_MOTOR_stop(uint8_t potr ,uint8_t pin_1, uint8_t pin_2);


#endif /* DC_MOTOR_H_ */