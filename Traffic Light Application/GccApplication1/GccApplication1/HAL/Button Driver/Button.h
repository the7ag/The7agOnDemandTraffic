/*
 * Button.h
 *
 * Created: 25/08/2022 11:03:51 م
 *  Author: THE HAG
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_
#include "../../MCAL/DIO DRIVERS/dio.h"
void Button_init(uint8_t ButtonPort,uint8_t ButtonPin);
void Button_read(uint8_t ButtonPort,uint8_t ButtonPin,uint8_t *value);


#endif /* BUTTON_H_ */