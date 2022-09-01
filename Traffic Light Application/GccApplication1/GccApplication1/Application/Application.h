/*
 * Application.h
 *
 * Created: 31/08/2022 06:00:55 م
 *  Author: THE HAG
 */ 


#ifndef APPLICATION_H_
#define APPLICATION_H_
#include "../MCAL/DIO DRIVERS/dio.h"
#include "../UTIL/Types.h"
#include "../HAL/LED DRIVER/LED.h"
#include "../HAL/Button Driver/Button.h"
#include "../MCAL/Interrupt Drivers/interrupt.h"
#include "../MCAL/Timer Drivers/timer.h"
#include "avr/interrupt.h"
#include <avr/wdt.h> /*watch dog timer to reset the micro controller*/
#define Cars_Port PORT_A
#define P_Port PORT_B
#define Car_G_Pin 0
#define Car_Y_Pin 1
#define Car_R_Pin 2
#define P_G_Pin 0
#define P_Y_Pin 1
#define P_R_Pin 2

void yellowblink(uint8_t pin,uint8_t port);
void NormalMode();
void yellowsblink(uint8_t pin,uint8_t port,uint8_t pin2,uint8_t port2);
void PedestrianMode();
void All_OFF();
void Appinit(void);
void AppLoop(void);



#endif /* APPLICATION_H_ */