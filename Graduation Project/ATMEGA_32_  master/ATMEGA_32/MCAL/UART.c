/*
 * UART.c
 *
 * Created: 8/16/2023 3:46:50 PM
 *  Author: Ahmed shaban
 */ 
#include "UART.h"
#include <avr/io.h>
static char flag_send=1;
static char* TX_Str;
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

void UART_SendString( char* str) 
{
	for(int i=0 ;i<str[i] ;i++)
	{
		UART_SEND_char(str[i]);
	}
	UART_SEND_char('\r');
}


void UART_ReceiveString(char* buffer)
{
	char i=0;
buffer	[i]=UART_RESIVED();
while(buffer[i]!= '\r')
{
	i++;
	buffer[i]=UART_RESIVED();	
	
}
buffer[i]= '\0';		
}


uint8_t UART_RESIVED_Perodic_ckeck(uint8_t* buffer)
{
	if(GET_BIT(UCSRA,RXC))
	{
    buffer=	UDR ;
	return 1;
	}
	return 0;
}



uint8_t UART_send_Perodic_ckeck(uint8_t buffer)
{
	if(GET_BIT(UCSRA,TXC))
	{
		UDR=buffer ;
	  UART_SEND_char(UDR);	
	  return 1;
	}
	return 0;
}


void UART_send_noblock(uint8_t buffer)
{
	UDR = buffer;
}


void UART_resived_noblock(uint8_t buffer)
{
	buffer = UDR;
}

void RX_interrput_enable()
{
	SET_BIT(UCSRB,RXCIE);
	SET_BIT(SREG,7);
}
void RX_interrput_disable()
{
	CLR_BIT(UCSRB,RXCIE);
	SET_BIT(SREG,7);
}
void TX_interrput_enable()
{
	SET_BIT(UCSRB,TXCIE);
	SET_BIT(SREG,7);
}
void TX_interrput_disable()
{
	CLR_BIT(UCSRB,TXCIE);
	SET_BIT(SREG,7);
}
void UART_ASYCH_SEND_STRING(uint8_t *str)
{
	if(flag_send==1)
	{
		TX_interrput_enable();
		UART_send_noblock(str[0]);
		TX_Str=str;
		flag_send=0 ;
	}
	
}
ISR(USART_TXC_vect)
{
	static uint8_t i=1;
	if(TX_Str[i]!=0)
	{
		UART_send_noblock(TX_Str[i]);
		i++;
   }
else
{
	i=1;
	flag_send=1;
}
}