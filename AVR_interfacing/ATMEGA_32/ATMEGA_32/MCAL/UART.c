/*
 * UART.c
 *
 * Created: 8/16/2023 3:46:50 PM
 *  Author: Ahmed shaban
 */ 
#include "UART.h"
#include <avr/io.h>
void UART_INIT (void)
{/*
	UBRRL=51;
	CLR_BIT(UCSRA,U2X);
	SET_BIT(UCSRC,UCSZ0);
	SET_BIT(UCSRB,TXEN);
	SET_BIT(UCSRB,RXEN);
	
	*/
	
	
	

//init boud rate
CLR_BIT(UCSRA,U2X);
UBRRL=51;
	
//init tx and rx
SET_BIT(UCSRB,RXEN)	;
SET_BIT(UCSRB,TXEN);

//init fram

    //parity bit	

	#ifdef  Even_Parity
	CLR_BIT(UCSRC,UPM0);
	SET_BIT( UCSRC,UPM1);
 #endif
    #ifdef Odd_Parity
	SET_BIT(UCSRC,UPM0);
	SET_BIT(UCSRC,UPM1);		
    #endif
	
	
//stop bit
   #ifdef  one_stop_bit
   CLR_BIT(UCSRC,USBS);
    #endif
 #ifdef two_stop_bit
 SET_BIT(UCSRC,USBS);  
 #endif
//Data  size
switch(frame_size)
{
	case 5:

	CLR_BIT(UCSRC,UCSZ0);
	CLR_BIT(UCSRC,UCSZ1);
	CLR_BIT(UCSRB,UCSZ2);

	break;


   case 6:

		SET_BIT(UCSRC,UCSZ0);
		CLR_BIT(UCSRC,UCSZ1);
		CLR_BIT(UCSRB,UCSZ2);

	break;


   case 7:

			CLR_BIT(UCSRC,UCSZ0);
			SET_BIT(UCSRC,UCSZ1);
			CLR_BIT(UCSRB,UCSZ2);

	break;


   case 8:

				SET_BIT(UCSRC,UCSZ0);
				SET_BIT(UCSRC,UCSZ1);
				CLR_BIT(UCSRB,UCSZ2);

	break;

   case 9:

	      SET_BIT(UCSRC,UCSZ0);
	      SET_BIT(UCSRC,UCSZ1);
	      SET_BIT(UCSRB,UCSZ2);

	break;


default:

		      SET_BIT(UCSRC,UCSZ0);
		      SET_BIT(UCSRC,UCSZ1);
		      CLR_BIT(UCSRB,UCSZ2);



}	

	
}
void UART_SEND_char(uint8_t data)
{
//check if the buffer is empety or not
while(! GET_BIT(UCSRA,UDRE));
UDR=data;
	
}

uint8_t UART_RESIVED (void)
{
while(! GET_BIT(UCSRA,RXC));

return UDR;
	
}
void UART_SendString(const char* str) {
	while (*str != '\0') {
		UART_SEND_char(*str);
		str++;
	}
}


void UART_ReceiveString(char* buffer, uint8_t max_length) {
	uint8_t count = 0;
	char received_char;
	
	do {
		received_char = UART_RESIVED();
		UART_SEND_char(received_char); 
		if (received_char != '\r') 
		{ 
			buffer[count] = received_char;
			count++;
		}
	} 
	while (received_char != '\n' && count < max_length - 1);
	
	buffer[count] = '\0'; // Null-terminate the string
}