/*
 * _7segment.h
 *
 * Created: 8/21/2023 2:00:33 PM
 *  Author: Ahmed
 */ 
#define segment_port            PORTB
#define segment_DDR             DDRB

#define segment_port_enable     PORTC
#define segment_DDR_enable      DDRC

#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>
static unsigned char segment_number[ ]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
#ifndef  seven_SEGMENT_H_
#define  seven_SEGMENT_H_
//======================================================================================
//==============================APIS====================================================
//======================================================================================
void seven_segment_number( uint8_t number); // number from 0<<<<<<<<<<<<9
void two_seven_segment(uint8_t number);    // number from 0<<<<<<<<<<<<99
void three_seven_segment(uint16_t number);// number from 0<<<<<<<<<<<<999


#endif /*  seven_SEGMENT_H_*/