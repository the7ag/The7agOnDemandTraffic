/*
 * dio.c
 *
 * Created: 25/08/2022 09:10:03 م
 *  Author: THE HAG
 */ 
#include "dio.h"
/*Dio init 
input DDR pin is LOW
output DDR pin is HIGH*/
void DIO_init(uint8_t portNumber, uint8_t pinNumber,uint8_t direction){
	switch(portNumber){
		case PORT_A:
		if (direction==OUT)
		{
			SET_BIT(DDRA,pinNumber);
		} 
		else if(direction==IN)	
		{
			CLR_BIT(DDRA,pinNumber);
		}
		else{
			
		}
		break;
		case PORT_B:
		if (direction==OUT)
		{
			SET_BIT(DDRB,pinNumber);
		}
		else if(direction==IN)
		{
			CLR_BIT(DDRB,pinNumber);
		}else{
			
		}
		break;
		case PORT_C:
			if (direction==OUT)
			{
			SET_BIT(DDRC,pinNumber);
			}
			else if(direction==IN)
			{
			CLR_BIT(DDRC,pinNumber);
			}else{
				
			}
		break;
		case PORT_D:
			if (direction==OUT)
			{
			SET_BIT(DDRD,pinNumber);
			}
			else if(direction==IN)
			{
			CLR_BIT(DDRD,pinNumber);
			}else{
				
			}
		 break;
	}
}
/*DIO Write on the pin High Or Low
to make it High set the port to high
to make it low set the port to low	*/
void DIO_write(uint8_t portNumber, uint8_t pinNumber,uint8_t data){
	switch(portNumber){
		case PORT_A:
		if (data==HIGH)
		{
			SET_BIT(PORTA,pinNumber);
		}
		else if(data==LOW)
		{
			CLR_BIT(PORTA,pinNumber);
		}
		else{
			
		}
		break;
		case PORT_B:
		if (data==HIGH)
		{
			SET_BIT(PORTB,pinNumber);
		}
		else if(data==LOW)
		{
			CLR_BIT(PORTB,pinNumber);
			}else{
			
		}
		break;
		case PORT_C:
		if (data==HIGH)
		{
			SET_BIT(PORTC,pinNumber);
		}
		else if(data==LOW)
		{
			CLR_BIT(PORTC,pinNumber);
			}else{
			
		}
		break;
		case PORT_D:
		if (data==HIGH)
		{
			SET_BIT(PORTD,pinNumber);
		}
		else if(data==LOW)
		{
			CLR_BIT(PORTD,pinNumber);
			}else{
			
		}
		break;
	}

}
/*it changes the state of the pin from 0 to 1 or 1 to 0*/
void DIO_toggle(uint8_t portNumber, uint8_t pinNumber){
	switch(portNumber){
		case PORT_A:	
		TOG_BIT(PORTA,pinNumber);
		break;
		case PORT_B:
		TOG_BIT(PORTB,pinNumber);
		break;
		case PORT_C:
		TOG_BIT(PORTC,pinNumber);
		break;
		case PORT_D:
		TOG_BIT(PORTC,pinNumber);
		break;
	}
}
/*it reads the value stored on that pin*/
void DIO_read(uint8_t portNumber, uint8_t pinNumber,uint8_t *value){
	switch(portNumber){
		case PORT_A:
		*value=(PINA &(1<<pinNumber))>>pinNumber;
		break;
		case PORT_B:
		*value=(PINB &(1<<pinNumber))>>pinNumber;
		break;
		case PORT_C:
		*value=(PINC &(1<<pinNumber))>>pinNumber;
		break;
		case PORT_D:
		*value=(PIND &(1<<pinNumber))>>pinNumber;
		break;
	}
}