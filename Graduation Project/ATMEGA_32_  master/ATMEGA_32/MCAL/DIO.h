/*
 * IncFile1.h
 *
 * Created: 8/22/2023 2:36:58 PM
 *  Author: Ahmed
 */ 


#ifndef INCFILE1_H_
#define INCFILE1_H_
#include <stdint.h>
#include <avr/io.h>
#include "bit_prosess.h"
//==========================================================================
//=============================macros=========================================
//==========================================================================
#define  DIO_PORTA  0
#define  DIO_PORTB  1
#define  DIO_PORTC  2
#define  DIO_PORTD  3

#define DIO_PORT_OUT     0xff
#define DIO_PORT_INT     0x00

#define DIO_port_LOW     0x00
#define DIO_port_HIGH    0xff


#define DIO_pin_OUT     1
#define DIO_pin_INT     0

#define DIO_pin_LOW     0
#define DIO_pin_HIGH    1

//PORTA
#define PA0         0
#define PA1         1
#define PA2         2
#define PA3         3
#define PA4         4
#define PA5         5
#define PA6         6
#define PA7         7
//PORTB
#define PB0         0
#define PB1         1
#define PB2         2
#define PB3         3
#define PB4         4
#define PB5         5
#define PB6         6
#define PB7         7
//PORTC
#define PC0         0
#define PC1         1
#define PC2         2
#define PC3         3
#define PC4         4
#define PC5         5
#define PC6         6
#define PC7         7
//PORTD
#define PD0         0
#define PD1         1
#define PD2         2
#define PD3         3
#define PD4         4
#define PD5         5
#define PD6         6
#define PD7         7


//==========================================================================
//=============================APIS=========================================
//==========================================================================
void MCAL_DIO_PORT_Dir(uint8_t port_num , uint8_t dir);
void MCAL_DIO_PIN_Dir(uint8_t port_num , uint8_t pin_num, uint8_t dir);
void MCAL_DIO_PORT_val(uint8_t port_num , uint8_t val);
void MCAL_DIO_PIN_val(uint8_t port_num , uint8_t pin_num, uint8_t val);
void MCAL_DIO_PIN_toggle(uint8_t port_num , uint8_t pin_num);
void MCAL_DIO_PIN_PULL_UP(uint8_t port_num , uint8_t pin_num);
uint8_t MCAL_DIO_Read_pin(uint8_t port_num , uint8_t pin_num);


#endif /* INCFILE1_H_ */