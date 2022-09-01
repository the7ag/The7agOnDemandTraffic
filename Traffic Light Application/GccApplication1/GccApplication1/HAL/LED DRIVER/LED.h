/*
 * LED.h
 *
 * Created: 25/08/2022 10:11:36 م
 *  Author: THE HAG
 */ 


#ifndef LED_H_
#define LED_H_
#include "../../MCAL/DIO DRIVERS/dio.h"
#include "../../MCAL/Timer Drivers/timer.h"
void LED_init(uint8_t pinNumber,uint8_t portNumber);
void Turn_ON(uint8_t pinNumber,uint8_t portNumber);
void Turn_OFF(uint8_t pinNumber,uint8_t portNumber);
void LED_TOGGLE(uint8_t pinNumber,uint8_t portNumber);
void LED_Blink(uint8_t pinNumber,uint8_t portNumber);
void LEDs_Blink(uint8_t pinNumber,uint8_t portNumber,uint8_t pinNumber2,uint8_t portNumber2);



#endif /* LED_H_ */