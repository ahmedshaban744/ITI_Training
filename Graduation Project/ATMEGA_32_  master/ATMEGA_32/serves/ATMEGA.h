/*
 * memory_map.h
 *
 * Created: 8/16/2023 3:45:56 PM
 *  Author: Ahmed shaban
 */ 


#ifndef MEMORY_MAP_H_
#define MEMORY_MAP_H_
//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
//Includes
//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
#include "stdio.h"
#include "stdint.h"

//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
//Peripheral register:
//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
//UART register

#define UDR      (( volatile UDR_typedef*)0x2C)
#define UCSRA    (( volatile UCSRA_typedef*)0x2B)
#define UCSRB    (( volatile UCSRB_typedef*)0x2A)
#define UCSRC    (( volatile UCSRC_typedef*)0x40)
#define UBRRL    ((volatile UBRRL_typedef*)0x39)
#define UBRRH    ((volatile UBRRH_typedef*)0x40)

//DIO
//POTRA
#define PINA    ((volatile uint8_t*)0x39)
#define DDRA    ((volatile uint8_t*)0x3A)
#define PORTA   ((volatile uint8_t*)0x3B)

//POTRB 
#define PINB    ((volatile uint8_t*)0x36)
#define DDRB    ((volatile uint8_t*)0x37)
#define PORTB   ((volatile uint8_t*)0x38)

//POTRC
#define PINC    ((volatile uint8_t*)0x33)
#define DDRC    ((volatile uint8_t*)0x34)
#define PORTC   ((volatile uint8_t*)0x35)

//POTRD
#define PIND   ((volatile uint8_t*)0x30)
#define DDRD   ((volatile uint8_t*)0x31)
#define PORTD  ((volatile uint8_t*)0x32)
#define  SREG   ((volatile uint8_t*)0x5F)

//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
// Registers PINS
//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
//UART
typedef struct
{
	volatile uint8_t DATA:8;
}UDR_typedef;

typedef struct
{
	volatile uint8_t MPCM: 1;
	volatile uint8_t U2X : 1;
	volatile uint8_t PE  : 1;
	volatile uint8_t DOR : 1;
	volatile uint8_t FE  : 1;
	volatile uint8_t UDRE: 1;
	volatile uint8_t TXC : 1;
	volatile uint8_t RXC : 1;
	
}UCSRA_typedef;

typedef struct
{
	volatile uint8_t TXB8: 1;
	volatile uint8_t RXB8: 1;
	volatile uint8_t UCSZ2:1;
	volatile uint8_t TXEN: 1;
	volatile uint8_t RXEN: 1;
	volatile uint8_t UDRIE:1;
	volatile uint8_t TXCIE:1;
	volatile uint8_t RXCIE:1;
	
}UCSRB_typedef;
typedef struct
{
	volatile uint8_t UCPOL:1;
	volatile uint8_t UCSZ0:1;
	volatile uint8_t UCSZ1:1;
	volatile uint8_t USBS:1;
	volatile uint8_t UPM0:1;
	volatile uint8_t UPM1:1;
	volatile uint8_t UMSEL:1;
	volatile uint8_t URSEL:1;
	
}UCSRC_typedef;



typedef struct
{
	volatile uint8_t UBRR:8;

	
}UBRRL_typedef;

typedef struct
{
	volatile uint8_t UBRR:4;
	volatile uint8_t RESERVED:3;
	volatile uint8_t URSEL:1;

	
}UBRRH_typedef;










#endif /* MEMORY_MAP_H_ */