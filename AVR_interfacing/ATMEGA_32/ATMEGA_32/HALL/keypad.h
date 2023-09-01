/*
 * keypad.h
 *
 * Created: 7/29/2023 7:12:34 PM
 *  Author:  Ahmed Shaban
 */ 
#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#ifndef KEYPAD_H_
#define KEYPAD_H_
//PORTD register
#define keypad_port PORTD
#define keypad_data_direcation DDRD
#define keypad_pin PIND

#define R0 0
#define R1 1
#define R2 2
#define R3 3

#define C0 4
#define C1 5
#define C2 6
#define C3 7

void keypad_init();
char git_char();
uint8_t git_number();
#endif /* KEYPAD_H_ */