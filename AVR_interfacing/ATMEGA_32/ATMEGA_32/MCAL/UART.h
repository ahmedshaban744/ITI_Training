/*
 * UART.h
 *
 * Created: 8/16/2023 3:47:09 PM
 *  Author: Ahmed shaban
 */ 


#ifndef UART_H_
#define UART_H_

//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
//Includes
//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
//#include "ATMEGA.h"
#include "bit_prosess.h"
#include "stdint.h"

//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
// MACROS
//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-

   
#define Even_Parity       //(chose Even_Parity or Odd_Parity)
#define two_stop_bit     //(chose one_stop_bit or two_stop_bit)
#define frame_size 5   //(5,6,7,8,9)

//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
//APIS
//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
void UART_INIT (void);
void UART_SEND_char(uint8_t data);
void UART_SendString(const char* str) ;
uint8_t UART_RESIVED (void);
void UART_ReceiveString(char* buffer, uint8_t max_length);


#endif /* UART_H_ */