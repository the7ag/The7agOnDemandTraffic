/*
 * Timer.c
 *
 * Created: 28/08/2022 01:35:59 م
 *  Author: THE HAG
 */ 
#include "timer.h"
void Timer_init(){
	TCCR0 =0x00; //timer mode normal no prescalar
	TCNT0 =0x00; //set initial value 
}
void Delay_IN_SEC(int delay){
		double max_Delay =0.000256; /*max delay for 8 bit*/
		int OverFlow=ceil(delay/max_Delay); /*how many overflows nedded to reach this delay*/
		int OverFlowCounter=0;  /*to count to overflow */
		 	TCCR0 |=(1<<0); /* Timer0, normal mode, no pre-scalar */
		 	while(OverFlowCounter<OverFlow){
			 	while ( ( TIFR & (1<<0) ) == 0 ); /*wait untill an over flow happens*/
			 	TIFR |= (1<<0); /*Clear TOV0 flag*/
			 	OverFlowCounter++;/*increase the counter until it reaches the overflow amount*/
		 	}
		 	OverFlowCounter=0; /*reset the counter*/
		 	TCCR0 =0x00;		/*stop the timer*/
}
void Delay_IN_MSEC(int delay){
	double max_Delay =0.256; /*max delay for 8 bit in mSec*/
	int OverFlow=ceil(delay/max_Delay); /*how many overflows nedded to reach this delay*/
	int OverFlowCounter=0;  /*to count to overflow */
	TCCR0 |=(1<<0); /* Timer0, normal mode, no pre-scalar */
	while(OverFlowCounter<OverFlow){
		while ( ( TIFR & (1<<0) ) == 0 ); /*wait untill an over flow happens*/
		TIFR |= (1<<0); /*Clear TOV0 flag*/
		OverFlowCounter++;/*increase the counter until it reaches the overflow amount*/
	}
	OverFlowCounter=0; /*reset the counter*/
	TCCR0 =0x00;		/*stop the timer*/
}
