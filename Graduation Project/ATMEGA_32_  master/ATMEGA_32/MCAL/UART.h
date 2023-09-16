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
#define frame_size 8    //(5,6,7,8,9)

//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
//APIS
//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
void UART_INIT (void);

void UART_SEND_char(uint8_t data);
uint8_t UART_RESIVED (void);

void UART_SendString( char* str) ;
void UART_ReceiveString(char* buffer);

uint8_t UART_RESIVED_Perodic_ckeck(uint8_t* buffer);
uint8_t UART_send_Perodic_ckeck(uint8_t buffer);

void UART_send_noblock(uint8_t buffer);
void UART_resived_noblock(uint8_t buffer);
void UART_ASYCH_SEND_STRING(uint8_t *str);

void RX_interrput_enable();
void RX_interrput_disable();
void TX_interrput_enable();
void TX_interrput_disable();





#endif /* UART_H_ */