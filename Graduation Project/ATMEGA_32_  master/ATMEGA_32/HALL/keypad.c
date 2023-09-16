/*
 * keypad.c
 *
 * Created: 7/29/2023 7:13:14 PM
 *  Author: Ahmed Shaban
 */ 
#include "keypad.h"
int keypad_row[]={R0,R1,R2,R3};
int keypad_colom[]={C0,C1,C2,C3};
keypad_init()
{    keypad_data_direcation &=~(1<<R0) |(1<<R1)|(1<<R2)|(1<<R3);
     keypad_data_direcation |=((1<<C0) |(1<<C1)|(1<<C2)|(1<<C3));
   
	keypad_port =0xff;
	
}
char git_char()
{
	for(int i=0 ;i<4;i++)
	{
		keypad_port |=((1<<C0) |(1<<C1)|(1<<C2)|(1<<C3));
		keypad_port &=~(1<<keypad_colom[i]);
		for(int j=0 ;j<4;j++)
		{
			if(!(keypad_pin & (1<<keypad_row[j])))
			{
				while(!(keypad_pin&(1<<keypad_row[j])));
				switch(i)
				{
					case(0):
					{
							if(j==0)     return '7';
							else if(j==1)return '4';
							else if(j==2)return '1';
							else if(j==3)return '!';
							break;
					}
					
						case(1):
					{
						     if(j==0)return '8';
							 else if(j==1)return '5';
							 else if(j==2)return '2';
							 else if(j==3)return '0';
							break;
							}
					case(2):
					{
							if(j==0)return '9';
					     	else if(j==1)return '6';
							else if(j==2)return '3';
							else if(j==3)return '=';
						 	break;
							}
					case(3):
							{
					     	if(j==0)return '/';
							else if(j==1)return '*';
							else if(j==2)return '-';
							else if(j==3)return '+';
							break;
					}
				}
			}
		
	    }
	
	 }
	return 'N';

}

