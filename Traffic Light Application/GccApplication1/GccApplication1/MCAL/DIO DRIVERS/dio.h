/*
 * dio.h
 *
 * Created: 25/08/2022 09:10:26 م
 *  Author: THE HAG
 */ 


#ifndef DIO_H_
#define DIO_H_
/*including the library's*/
#include "../../UTIL/Types.h"
#include "../../UTIL/register.h"
#include "../../UTIL/BMath.h"
/*Defining the ports*/
#define PORT_A 'A' 
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'
//Defining the direction of data
#define IN 0
#define OUT 1
//Defining the states
#define HIGH 1
#define LOW 0
/*Function prototypes for pins */
void DIO_init(uint8_t portNumber, uint8_t pinNumber,uint8_t direction);
void DIO_write(uint8_t portNumber, uint8_t pinNumber,uint8_t data);
void DIO_toggle(uint8_t portNumber, uint8_t pinNumber);
void DIO_read(uint8_t portNumber, uint8_t pinNumber,uint8_t *value);


#endif /* DIO_H_ */