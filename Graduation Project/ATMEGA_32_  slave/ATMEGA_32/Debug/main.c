/*
 * ATMEGA_32.c
 *
 * Created: 8/16/2023 3:42:38 PM
 * Author : Ahmed shaban
 */ 

#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 8000000UL
#include "bit_prosess.h"
#include "DIO.h"
#include "lcd.h"
#include "SPI.h"
#include "UART.h"
#define NULL ((void *)0)
#define  SPI_in_MASTER
#define  SPI_in_slave


uint8_t ch='a';

int main(void)
{ 
LCD_INIT();
SPI_config SPI_define;
SPI_define.Clock_phase=SPI_samling_on_last_edge;
SPI_define.Clock_Polarity=SPI_clock_high_idel;
SPI_define.clock_rate=SPI_boud_rate_prescaler4;
SPI_define.data_order=SPI_DARA_ORDER_MSB;
SPI_define.interrupt_callback=NULL;
SPI_define.double_speed=SPI_boud_rate_Double_speed_disable;
SPI_define.interrupt_enable=SPI_interrupt_disable;

#ifdef SPI_in_MASTER
SPI_define.SPI_MODE=SPI_MASTER;

#endif

#ifdef SPI_in_slave
SPI_define.SPI_MODE=SPI_SLAVE;
#endif 
MCAL_SPI_INIT(&SPI_define);



while(1)
{
	#ifdef SPI_in_MASTER
	LCD_WRITE_CHAR(ch);
	MCAL_SPI_send_resive(&ch);
	#endif
	#ifdef SPI_in_slave
		MCAL_SPI_send_resive(&ch);
	LCD_WRITE_CHAR(ch);
	#endif


}

}