/*
 * EXINTERRUPT_Interface.h
 *
 * Created: 16-Mar-22 5:18:35 PM
 *  Author: lenovo
 */ 


#ifndef EXINTERRUPT_INTERFACE_H_
#define EXINTERRUPT_INTERFACE_H_

#include "STD_TYPES.h"
#include "UTILS.h"
#include "DIO_Interface.h"
#include "EXINTERRUPT_Register.h"

typedef enum{
	LOW_LEVEL=0,
	ANY_LOGIC_CHANGE,
	FALLING_EDGE,
	RISING_EDGE,
	}TriggerEdge_Type;
	
typedef enum{
	EX_INT0=0,
	EX_INT1,
	EX_INT2,
	}ExInterruptSource_Type; 

void EXI_Enable(ExInterruptSource_Type Interrupt);
void EXI_Disable(ExInterruptSource_Type Interrupt);
void EXI_TriggerEdge(ExInterruptSource_Type Interrupt , TriggerEdge_Type Edge);
void EXI_SetCallBack(ExInterruptSource_Type Interrupt , void(*LocalPtr)(void));



#endif /* EXINTERRUPT_INTERFACE_H_ */