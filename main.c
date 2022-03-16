/*
 * GccApplication6.c
 *
 * Created: 12-Mar-22 12:26:09 PM
 * Author : lenovo
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "STD_TYPES.h"
#include "UTILS.h"
#include "DIO_Interface.h"
#include "EXINTERRUPT_Interface.h"

int main(void)
{
	EXI_TriggerEdge(EX_INT0,FALLING_EDGE);
	EXI_Enable(EX_INT0);
	EXI_TriggerEdge(EX_INT1,FALLING_EDGE);
	EXI_Enable(EX_INT1);
	sei(); // enable global interrupt
	//led
	DIO_SetPinDirection(PORT_A,PIN0,OUTPUT);
	//switch
	DIO_SetPinDirection(PORT_D,PIN2,INPUT);
	DIO_SetPinDirection(PORT_D,PIN3,INPUT);
	DIO_SetPinValue(PORT_D,PIN2,HIGH);
	DIO_SetPinValue(PORT_D,PIN3,HIGH);
    while (1) 
    {
		
		
    }
	
}
ISR(INT0_vect)
{
	DIO_SetPinValue(PORT_A,PIN0,HIGH);
}
ISR(INT1_vect)
{
	DIO_SetPinValue(PORT_A,PIN0,LOW);
}
