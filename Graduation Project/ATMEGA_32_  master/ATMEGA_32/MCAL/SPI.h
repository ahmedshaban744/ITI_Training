/*
 * SPI.h
 *
 * Created: 9/11/2023 10:44:32 PM
 *  Author: Ahmed shaban
 */ 
#ifndef SPI_H_
#define SPI_H_
//=========================================================================================
//===================================include===============================================
//=========================================================================================
#include<avr/io.h>
#include "bit_prosess.h"
#include "DIO.h"
#define NULL ((void *)0)
//=========================================================================================
//===================================configration strutuer=================================
//=========================================================================================
typedef struct
{
	uint8_t SPI_MODE; //set in @SPI MODE
	uint8_t data_order; //set in @SPI data order
	uint8_t interrupt_enable; //set in @SPI interrupt_enable
	uint8_t  Clock_Polarity; //set in @SPI Clock_Polarity
	uint8_t  Clock_phase;   //set in @SPI Clock_phase
	uint8_t  clock_rate;   //set in @SPI clock_rate
	uint8_t double_speed;  //set in @SPI double_speed
	void (*interrupt_callback)(void);
	
}SPI_config;
enum polling{SPI_POLL_enable,SPI_POLL_disable};

//=========================================================================================
//===================================MACROS==================================================
//=========================================================================================
//set in @SPI MODE 
#define  SPI_MASTER (uint8_t)(1<<4) //register SPCR
#define  SPI_SLAVE  (uint8_t)(0)   //register SPCR
//=========================================================================================

//@SPI data order
#define  SPI_DARA_ORDER_MSB   (uint8_t)(0)    //register SPCR
#define  SPI_DARA_ORDER_LSB   (uint8_t)(1<<5) //register SPCR
//=========================================================================================

//set in @SPI interrupt_enable
#define  SPI_interrupt_enable    (uint8_t)(1<<7) //register SPCR
#define  SPI_interrupt_disable   (uint8_t)(0)   //register SPCR
//=========================================================================================

//set in @SPI Clock_Polarity
 #define  SPI_clock_high_idel    (uint8_t)(1<<3) //register SPCR
 #define  SPI_clock_low_idel    (uint8_t)(0)     //register SPCR
//=========================================================================================

//set in @SPI Clock_phase
 #define  SPI_samling_on_first_edge    (uint8_t)(0)           //register SPCR
 #define  SPI_samling_on_last_edge       (uint8_t)(1<<2)     //register SPCR
 //=========================================================================================

//@SPI clock_rate
#define  SPI_boud_rate_prescaler4     (uint8_t)(0b00U<<1) //register SPCR
#define  SPI_boud_rate_prescaler16    (uint8_t)(0b01U<<1) //register SPCR
#define  SPI_boud_rate_prescaler64    (uint8_t)(0b10U<<1) //register SPCR
#define  SPI_boud_rate_prescaler128   (uint8_t)(0b11U<<1) //register SPCR
#define  SPI_boud_rate_Double_speed_enable  (uint8_t)(1<<0)     //register SPSR
#define  SPI_boud_rate_Double_speed_disable  (uint8_t)(0)     //register SPSR
//=========================================================================================
//@SPI double_speed
#define  SPI_boud_rate_Double_speed  (uint8_t)(1<<0)     //register SPSR
//=========================================================================================
//===================================APIS==================================================
//=========================================================================================
void MCAL_SPI_INIT(SPI_config *SPI_define);
void MCAL_SPI_SEND(uint8_t *buffer);
void MCAL_SPI_resive(uint8_t *buffer);
void MCAL_SPI_send_resive(uint8_t *buffer);
void MCAL_SPI_DIO_SET_PINS(SPI_config *SPI_define);



#endif /* SPI_H_ */