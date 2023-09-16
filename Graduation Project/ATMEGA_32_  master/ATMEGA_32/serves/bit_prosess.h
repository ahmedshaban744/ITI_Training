/*
 * bit_prosess.h
 *
 * Created: 8/16/2023 6:16:05 PM
 *  Author: Ahmed shaban
 */ 


#ifndef BIT_PROSESS_H_
#define BIT_PROSESS_H_


#define SET_BIT(REG,PIN) (REG |=(1 << PIN))
#define CLR_BIT(REG,PIN) (REG &= ~(1<<PIN))
#define TOG_BIT(REG,PIN) (REG ^= (1<<PIN))
#define GET_BIT(REG,PIN) ((REG>>PIN) & 0x1)
#define ROT_L(REG,PIN)   ((REG<<PIN) | (REG>>(8-PIN)))
#define ROT_R(REG,PIN)   ((REG>>PIN) | (REG<<(8-PIN)))


#endif /* BIT_PROSESS_H_ */