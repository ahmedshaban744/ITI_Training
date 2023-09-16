/*
 * ATMEGA_32.c
 *
 * Created: 8/16/2023 3:42:38 PM
 * Author : Ahmed shaban
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>
#define F_CPU 8000000UL
#include "bit_prosess.h"
#include "DIO.h"
#include "SPI.h"
#include "UART.h"
#include "lcd.h"
#include "keypad.h"
#include "EXTI.h"
#define NULL ((void *)0)


  
  
  
//===================================================================================================
//=======================================MICROS======================================================
//===================================================================================================

#define MAX_PASSWORD_ATTEMPTS 3
#define PASSWORD_LENGTH       4

//===================================================================================================
//=======================================program======================================================
//===================================================================================================
char correctPassword[PASSWORD_LENGTH] = "1234";
bool checkPassword(char* enteredPassword) {
	for (int i = 0; i < PASSWORD_LENGTH; i++) {
		if (enteredPassword[i] != correctPassword[i]) {
			return false; // Password mismatch
		}
	}
	return true; // Password is correct
}

void displayMessage(char* message) {
	LCD_clear_screen();
	LCD_GOTO_XY(1, 0);
	LCD_WRITE_STRING(message);
	_delay_ms(2000);  // Display the message for 2 seconds
}

int main() {

    char enteredPassword[PASSWORD_LENGTH + 1];  // +1 for null-terminator
    uint8_t attempts = 0;

    LCD_INIT();
    keypad_init();

    while (1) {
        LCD_clear_screen();
        LCD_GOTO_XY(1, 0);
        LCD_WRITE_STRING("Enter PASSWORD..");

        for (uint8_t i = 0; i < PASSWORD_LENGTH; i++) {
            char key = 'N';
            while (key == 'N') {
                key = git_char();
            }
            enteredPassword[i] = key;
            LCD_GOTO_XY(2, i);
            LCD_WRITE_CHAR('*');
        }
        enteredPassword[PASSWORD_LENGTH] = '\0';  // Null-terminate the entered password

        if (checkPassword(enteredPassword)) {
            displayMessage("RIGH PASSWORD");
			MCAL_DIO_PIN_Dir(DIO_PORTD,PD7,DIO_pin_OUT);
			MCAL_DIO_PIN_val(DIO_PORTD,PD7,DIO_pin_HIGH);
            break;  // Correct password, exit the loop
        } else {
            attempts++;

            if (attempts >= MAX_PASSWORD_ATTEMPTS) {
                displayMessage("Too many try");
				{
				MCAL_DIO_PIN_Dir(DIO_PORTB,PB0,DIO_pin_OUT);
				MCAL_DIO_PIN_Dir(DIO_PORTD,PD6,DIO_pin_OUT);
				MCAL_DIO_PIN_val(DIO_PORTD,PD6,DIO_pin_HIGH);
				for(int i=0 ;i<30;i++)
				{	
			   MCAL_DIO_PIN_val(DIO_PORTB,PB0,DIO_pin_HIGH);
				_delay_ms(500);
				MCAL_DIO_PIN_val(DIO_PORTB,PB0,DIO_pin_LOW);
				_delay_ms(200);
				}
            
                attempts = 0;  
				}
            } else {
                displayMessage("wrong password  try again");
            }
        }
    }
	 //==============================================================================================================================================
	 //==============================================================SPI CONFIG======================================================================
	 //==============================================================================================================================================	
	 SPI_config SPI_config;
	 SPI_config.clock_rate=SPI_boud_rate_prescaler4;
	 SPI_config.Clock_phase=SPI_samling_on_last_edge;
	 SPI_config.Clock_Polarity=SPI_clock_high_idel;
	 SPI_config.data_order=SPI_DARA_ORDER_MSB;
	 SPI_config.SPI_MODE=SPI_MASTER;
	 SPI_config.interrupt_enable=SPI_interrupt_disable;
	 SPI_config.interrupt_callback=NULL;
	 MCAL_SPI_INIT(&SPI_config);
	 MCAL_SPI_DIO_SET_PINS(&SPI_config);
//==============================================================================================================================================
//==============================================================EXTI ============================================================================
//==============================================================================================================================================
	  MCAL_EXTI_0_ENABLE(low_level_of_INT0);
	  MCAL_EXTI_1_ENABLE(Any_logical_change_on_INT1);
//==============================================================================================================================================
//==============================================================UART INIT ======================================================================
//==============================================================================================================================================
	  UART_INIT();
	  uint8_t data1;	 	   	   
	LCD_clear_screen();
	LCD_GOTO_XY(1,0);
    LCD_WRITE_STRING("welcome to my        home");
	_delay_ms(10000);
	LCD_clear_screen();
    LCD_WRITE_STRING("Choose ROME TO      Control");
	_delay_ms(9000);
	LCD_clear_screen();	
 LCD_WRITE_STRING("1:ROME1  2:ROME2");
 LCD_GOTO_XY(2,0);
 LCD_WRITE_STRING("3:ROME3  4:ROME4");
 LCD_GOTO_XY(1,0);
    while (1) {
     //==============================================================================================================================================
     //==============================================================UART============================================================================
     //==============================================================================================================================================
     data1=UART_RESIVED();
     UART_SEND_char(data1);
	 switch(data1)
	 {
	case '1':
	case '2':	 
	case '3':
	case '4':
	    {
		 LCD_clear_screen();
		 LCD_WRITE_STRING("IN ROME ");
		 LCD_WRITE_CHAR(data1);
		 	  //==============================================================================================================================================
		 	  //==============================================================SPI ============================================================================
		 	  //==============================================================================================================================================
		  MCAL_SPI_SEND(&data1);
		 break ;
		 }

	 	case '0':
	 	case '5':
	 	case '6':
	 	case '7':
	    case '8':
		case '+':
		case '-':
		case '*':
		case '/':
		case '=':
		case '!':	
	{	
		 LCD_clear_screen();
		LCD_WRITE_STRING("that option not valid ");
		
	}

	}

   
	
	}
    }























 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

/*
uint8_t ch='a';
uint8_t m=0;
void callback(void)
{
	#ifdef SPI_in_slave
	if(GET_BIT(SPSR,SPIF))
	{
	MCAL_SPI_resive(&m);		
	LCD_WRITE_CHAR(m);
	}
	#endif
}
int main(void)
{ 
LCD_INIT();
SPI_config SPI_define;

SPI_define.data_order=SPI_DARA_ORDER_MSB;
SPI_define.interrupt_callback=callback;
SPI_define.double_speed=SPI_boud_rate_Double_speed_disable;

SPI_define.clock_rate=SPI_boud_rate_prescaler4;
SPI_define.Clock_phase=SPI_clock_high_idel;
SPI_define.Clock_phase=SPI_samling_on_last_edge;

#ifdef SPI_in_MASTER
SPI_define.SPI_MODE=SPI_MASTER;

#endif

#ifdef SPI_in_slave
SPI_define.SPI_MODE=SPI_SLAVE;
SPI_define.interrupt_enable=SPI_interrupt_enable;
SET_BIT(SREG,7);
#endif 
MCAL_SPI_INIT(&SPI_define);
MCAL_SPI_DIO_SET_PINS(&SPI_define);

while(1)
{ 
	#ifdef SPI_in_MASTER
 MCAL_DIO_PIN_val(DIO_PORTB,PB4,0);	
MCAL_SPI_SEND(&ch);
LCD_WRITE_CHAR(ch);
MCAL_DIO_PIN_val(DIO_PORTB,PB4,1);
_delay_ms(100);
#endif
#ifdef SPI_in_slave
	MCAL_SPI_resive(&m);
	LCD_WRITE_CHAR(m);
#endif
}

}
*/