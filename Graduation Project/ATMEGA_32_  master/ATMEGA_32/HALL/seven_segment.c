/*
 * _7_segment.c
 *
 * Created: 8/21/2023 2:00:05 PM
 *  Author: Ahmed
 */ 

#include "sev_segment.h"
void seven_segment_number( uint8_t number)
{
	 segment_DDR=0b01111111;
	 
for(int i=0 ; i <=number; i++)
{
	segment_port=segment_number[i];
	_delay_ms(500);
}

}


void two_seven_segment(uint8_t number)
{
	 segment_DDR =0b01111111;
	 segment_DDR_enable=0b11;;
	for(int i=0 ; i <=number; i++)
	{
	 segment_port_enable=0b01;
	segment_port=(segment_number[i%10]) ;
	_delay_ms(500);
	
    segment_port_enable=0b10;
    segment_port=(segment_number[i/10]) ;
    _delay_ms(500);
		
	}
}
	
	

	void three_seven_segment(uint16_t number)
	{
		segment_DDR =0b01111111;
		segment_DDR_enable=0b0111;
		for(int i=0 ; i <=number; i++)
		{
			segment_port_enable=0b0001;
			segment_port=(segment_number[i%10]) ;  //union number
			_delay_ms(500);

			segment_port_enable=0b0010;
			segment_port=(segment_number[(i/10)]) ; //tens number
			_delay_ms(500);
			
        	segment_port_enable=0b0100;
         	segment_port=(segment_number[(i/100)]) ; //Hundreds number
           	_delay_ms(500);
           					
			
		}
	}
