/*
 * interrupt.c
 *
 * Created: 28/08/2022 02:35:54 م
 *  Author: THE HAG
 */ 
#include "interrupt.h"
void EXT_INT_0_INIT(void)
{
	SET_BIT(SREG,7);        //_TO_ENABLE_THE_GLOBAL_INT_
	CLR_BIT(MCUCR,0);       // to make interrupt with FALLING edge
	SET_BIT(MCUCR,1);       
	SET_BIT(GICR,6);        //_TO_ENABLE_INT_0_
}