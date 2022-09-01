/*
 * LED.c
 *
 * Created: 25/08/2022 10:11:22 م
 *  Author: THE HAG
 */ 
#include "LED.h"
void LED_init(uint8_t pinNumber,uint8_t portNumber){
	DIO_init(portNumber,pinNumber,OUT);
}
void Turn_ON(uint8_t pinNumber,uint8_t portNumber){
	DIO_write(portNumber,pinNumber,HIGH);
}
void Turn_OFF(uint8_t pinNumber,uint8_t portNumber){
	DIO_write(portNumber,pinNumber,LOW);
}
void LED_TOGGLE(uint8_t pinNumber,uint8_t portNumber){
		DIO_toggle(portNumber,pinNumber);
}
void LED_Blink(uint8_t pinNumber,uint8_t portNumber){
	Turn_ON(pinNumber,portNumber);
	Delay_IN_MSEC(500);
	Turn_OFF(pinNumber,portNumber);
	Delay_IN_MSEC(500);

}
void LEDs_Blink(uint8_t pinNumber,uint8_t portNumber,uint8_t pinNumber2,uint8_t portNumber2){
		Turn_ON(pinNumber,portNumber);
		Turn_ON(pinNumber2,portNumber2);
		Delay_IN_MSEC(500);
		Turn_OFF(pinNumber,portNumber);
		Turn_OFF(pinNumber2,portNumber2);
		Delay_IN_MSEC(500);

}