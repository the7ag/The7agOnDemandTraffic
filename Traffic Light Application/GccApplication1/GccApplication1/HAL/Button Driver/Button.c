/*
 * Button.c
 *
 * Created: 25/08/2022 11:03:41 م
 *  Author: THE HAG
 */ 
#include "Button.h"
void Button_init(uint8_t ButtonPort,uint8_t ButtonPin){
	DIO_init(ButtonPort,ButtonPin,IN);
}
void Button_read(uint8_t ButtonPort,uint8_t ButtonPin,uint8_t *value){
	DIO_read(ButtonPort,ButtonPin,value);
}
