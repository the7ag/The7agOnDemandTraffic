/*
 * Application.c
 *
 * Created: 31/08/2022 06:01:08 م
 *  Author: THE HAG
 */ 
#include "Application.h"
uint8_t R_FLAG=0;
uint8_t Y_FLAG=0;
uint8_t G_FLAG=0;
void Appinit(void){
		EXT_INT_0_INIT(); /*init ext int0*/
		LED_init(Car_G_Pin,Cars_Port); /*Led init*/
		LED_init(Car_Y_Pin,Cars_Port);
		LED_init(Car_R_Pin,Cars_Port);
		LED_init(P_G_Pin,P_Port);
		LED_init(P_Y_Pin,P_Port);
		LED_init(P_R_Pin,P_Port);
		Timer_init(); /* timer init*/
} /*sets all the leds off*/
void All_OFF(){
	Turn_OFF(Car_G_Pin,Cars_Port);
	Turn_OFF(Car_Y_Pin,Cars_Port);
	Turn_OFF(Car_R_Pin,Cars_Port);
	Turn_OFF(P_G_Pin,P_Port);
	Turn_OFF(P_Y_Pin,P_Port);
	Turn_OFF(P_R_Pin,P_Port);
}  /*makes the yellow led blink for 5 seconds*/
void yellowblink(uint8_t pin,uint8_t port){
	for (int i=0;i<5;i++)
	{
		LED_Blink(pin,port);
	}
} /*makes both the yellow leds blinks in the same 5 seconds*/
void yellowsblink(uint8_t pin,uint8_t port,uint8_t pin2,uint8_t port2){
	for (int i=0;i<5;i++)
	{
		LEDs_Blink(pin,port,pin2,port2);
	}
}
/*What keeps happning with no button is pressed*/
void NormalMode(){
	All_OFF(); /*turn all the leds off*/
	Turn_ON(P_R_Pin,P_Port);/*turn on the pedestrian Red led*/
	Turn_ON(Car_G_Pin,Cars_Port); /*turn on the cars green led and mark that it's green*/
	G_FLAG=1;
	Delay_IN_SEC(5); /*wait for 5 seconds*/
	Y_FLAG=1; /*mark that the yellow led is on*/
	yellowblink(Car_Y_Pin,Cars_Port); /*make the yellow blink while the green is on*/
	Turn_OFF(Car_G_Pin,Cars_Port); /*turn off yellow*/
	G_FLAG=0; /*mark that the yellow led is off and the green*/
	Y_FLAG=0;
	Turn_OFF(Car_Y_Pin,Cars_Port); /*turn off the yellow leds from blinking*/
	Turn_ON(Car_R_Pin,Cars_Port); /*turn on the red led and mark that it's currently red*/
	R_FLAG=1;
	Delay_IN_SEC(5); /*wait 5 seconds*/
	Turn_OFF(Car_R_Pin,Cars_Port); /*turn off the Red led and mark that's currently yellow*/
	R_FLAG=0;
	Y_FLAG=1;
	yellowblink(Car_Y_Pin,Cars_Port); /*make the yellow blink for 5 seconds and then the loop resetes*/
	Y_FLAG=0;
}
/*if the button is pressed*/
void PedestrianMode(){
	/*change based on current state*/
	if (R_FLAG==1) /*currently the red flag is on*/
	{
		R_FLAG=0; /*stops all the flags to prevent from double click*/
		Y_FLAG=0;
		G_FLAG=0;
		All_OFF(); /*turn off all the leds*/
		Turn_ON(P_G_Pin,P_Port); /*turn on the padestrians green and cars red*/
		Turn_ON(Car_R_Pin,Cars_Port);
		Delay_IN_SEC(5);  /*delay 5 seconds*/
		Turn_OFF(Car_R_Pin,Cars_Port); /*turning the leds off*/
		yellowsblink(Car_Y_Pin,Cars_Port,P_Y_Pin,P_Port); /*making both led blink before changing back*/
		wdt_enable(WDTO_15MS);	/* Resetting the uC to restart the NormalMode after 15 ms*/

	}/*if the current state is yellow or green*/
	else if (Y_FLAG==1||G_FLAG==1)
	{
		R_FLAG=0;
		Y_FLAG=0;
		G_FLAG=0; /*to prevent double click*/
		Turn_OFF(P_R_Pin,P_Port); /*turn of the pedstrian red led*/
		yellowsblink(Car_Y_Pin,Cars_Port,P_Y_Pin,P_Port); /*both yellow leds blink*/
		All_OFF(); /*turn off all the leds*/
		Turn_ON(Car_R_Pin,Cars_Port);/*turn on the cars red led*/
		Turn_ON(P_G_Pin,P_Port);/*turn on the pedestrians yellow led*/
		Delay_IN_SEC(5); /*wait for 5 seconds*/
		Turn_OFF(Car_R_Pin,Cars_Port); /*turn off the cars red led*/
		yellowsblink(Car_Y_Pin,Cars_Port,P_Y_Pin,P_Port); /*blink for 5 seconds*/
		wdt_enable(WDTO_15MS);/* Resetting the uC to restart the NormalMode after 15 ms*/
	}
	
}
void AppLoop(void){
	 while (1)
	 {
		 NormalMode();
	 }
}
ISR(INT0_vect)
{
	PedestrianMode();
}