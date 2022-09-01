/*
 * register.h
 *
 * Created: 25/08/2022 08:50:43 م
 *  Author: THE HAG
 */ 


#ifndef REGISTER_H_
#define REGISTER_H_
#include "Types.h"
/************************************************************************/
/* port A                                                                     */
/************************************************************************/
#define PORTA *((volatile uint8_t*)0x3B)
#define  DDRA *((volatile uint8_t*)0x3A)
#define  PINA *((volatile uint8_t*)0x39)
// port B                                                                     
#define PORTB *((volatile uint8_t*)0x38)
#define  DDRB *((volatile uint8_t*)0x37)
#define  PINB *((volatile uint8_t*)0x36)
//port c
#define PORTC *((volatile uint8_t*)0x35)
#define  DDRC *((volatile uint8_t*)0x34)
#define  PINC *((volatile uint8_t*)0x33)
//port D
#define PORTD *((volatile uint8_t*)0x32)
#define  DDRD *((volatile uint8_t*)0x31)
#define  PIND *((volatile uint8_t*)0x30)
/************************************************************************/
/* Timer0 Reg                                                                     */
/************************************************************************/
#define TCCR0 *((volatile uint8_t*)0x53)
#define TCNT0 *((volatile uint8_t*)0x52)
#define TIFR *((volatile uint8_t*)0x58)
/************************************************************************/
/* Interrupt reg                                                                     */
/************************************************************************/
#define SREG        *((volatile uint8_t*)0x5F)
#define MCUCR       *((volatile uint8_t*)0x55)
#define GICR        *((volatile uint8_t*)0x5B)
#define GIFR        *((volatile uint8_t*)0x5A)

#endif /* REGISTER_H_ */