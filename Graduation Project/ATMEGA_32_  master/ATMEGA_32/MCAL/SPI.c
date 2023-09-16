/*
 * SPI.c
 *
 * Created: 9/11/2023 10:44:41 PM
 *  Author: Ahmed Shaban
 */
#include "SPI.h"
SPI_config *GP[1]={NULL};
void MCAL_SPI_INIT(SPI_config *SPI_define)
{

	GP[1]=SPI_define;
    SPCR|=SPI_define->interrupt_enable;
    SPCR|=SPI_define->data_order;
    SPCR|=SPI_define->SPI_MODE;
    SPCR|=SPI_define->Clock_Polarity;
    SPCR|=SPI_define->Clock_phase;
	SPCR|=SPI_define->clock_rate;
	SPSR|=SPI_define->double_speed;
	 //SPI ENABLE
	 	SPCR|=1<< SPE;
	
} 
void MCAL_SPI_SEND(uint8_t *buffer)
{ 
		
		SPDR=*buffer;
	while(!((SPSR>>SPIF)&1));

	
}
void MCAL_SPI_resive(uint8_t *buffer )
{	
		
		while(!((SPSR>>SPIF)&1));
		*buffer=SPDR;
	
}
void MCAL_SPI_send_resive(uint8_t *buffer)
{
	
		while(!((SPSR>>SPIF)&1));
		SPDR=*buffer;
	   while(!((SPSR>>SPIF)&1));
    	*buffer=SPDR;
	
}
void MCAL_SPI_DIO_SET_PINS(SPI_config *SPI_define)
{
	
		if(SPI_define->SPI_MODE==SPI_MASTER)
		{
			//SPI_SS -> PB4
			MCAL_DIO_PIN_Dir(DIO_PORTB,PB4,DIO_pin_OUT);
			//SPI_MOSI -> PB5
			MCAL_DIO_PIN_Dir(DIO_PORTB,PB5,DIO_pin_OUT);
			//SPI_MISO -> PB6
			MCAL_DIO_PIN_Dir(DIO_PORTB,PB6,DIO_pin_INT);
			//SPI_SCK -> PB7
			MCAL_DIO_PIN_Dir(DIO_PORTB,PB7,DIO_pin_OUT);
			
		}
		else if(SPI_define->SPI_MODE==SPI_SLAVE)
		{
			//SPI_SS -> PB4
			MCAL_DIO_PIN_Dir(DIO_PORTB,PB4,DIO_pin_INT);
			//SPI_MOSI -> PB5
			MCAL_DIO_PIN_Dir(DIO_PORTB,PB5,DIO_pin_INT);
			//SPI_MISO -> PB6
			MCAL_DIO_PIN_Dir(DIO_PORTB,PB6,DIO_pin_OUT);
			//SPI_SCK -> PB7
			MCAL_DIO_PIN_Dir(DIO_PORTB,PB7,DIO_pin_INT);
			
			
		}
	
}
//ISR

void SPI_STC (void)
{
GP[1]->interrupt_callback();
	
}