/*
 * EXTI.h
 *
 * Created: 8/28/2023 8:19:58 PM
 *  Author: Ahmed
 */ 


#ifndef EXTI_H_
#define EXTI_H_



//===========================================================================
//=========================APIS==============================================
//===========================================================================
//#define SREG  ((volatile uint8_t*)0x5F)
void MCAL_EXTI_1_ENABLE(uint8_t state);
void MCAL_EXTI_0_ENABLE(uint8_t state);
void MCAL_EXTI_2_ENABLE(uint8_t state);

//===========================================================================
//=========================macros==============================================
//===========================================================================

#define   low_level_of_INT1             0
#define   Any_logical_change_on_INT1    1
#define   falling_edge_of_INT1           2
#define   rising_edge_of_INT1            3

#define low_level_of_INT0                        0
#define Any_logical_change_on_INT0               1
#define falling_edge_of_INT0                     2
#define rising_edge_of_INT0                      3

#define falling_edge_of_INT2             0
#define rising_edge_of_INT2              1
 



#endif /* EXTI_H_ */