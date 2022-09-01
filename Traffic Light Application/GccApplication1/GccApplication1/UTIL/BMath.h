/*
 * BMath.h
 *
 * Created: 28/08/2022 07:01:01 م
 *  Author: THE HAG
 */ 


#ifndef BMATH_H_
#define BMATH_H_
//bitwise math using function as macros
#define SET_BIT(REG,BIT)       (REG = REG  | (1 << BIT)) /*setting 1 in the reg*/
#define CLR_BIT(REG,BIT)       (REG = REG   & (~(1 << BIT))) /* setting 0 in the reg*/
#define TOG_BIT(REG,BIT)       (REG =  REG ^ (1 << BIT)) /* toggling the bit*/

#endif /* BMATH_H_ */