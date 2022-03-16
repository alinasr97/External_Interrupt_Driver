/*
 * EXINTERRUPT_Register.h
 *
 * Created: 16-Mar-22 4:14:44 PM
 *  Author: lenovo
 */ 


#ifndef EXINTERRUPT_REGISTER_H_
#define EXINTERRUPT_REGISTER_H_

#include <avr/io.h>


/*External Interrupt*/
#define MCUCSR   (*(volatile unsigned char*)0x54)
#define ISC2 6

#define MCUCR   (*(volatile unsigned char*)0x55)
#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3

#define GICR   (*(volatile unsigned char*)0x5B)
#define INT1 7
#define INT0 6
#define INT2 5

#define GIFR   (*(volatile unsigned char*)0x5A)
#define INTF1 7
#define INTF0 6
#define INTF2 5

/* Interrupt vectors */
/* External Interrupt Request 0 */
#define INT0_vect                      __vector_1
/* External Interrupt Request 1 */
#define INT1_vect                      __vector_2
/* External Interrupt Request 2 */
#define INT2_vect                      __vector_3
/* Timer/Counter2 Compare match */
#define TIMER2_COMP_vect               __vector_4
/* Timer/Counter2 Overflow */
#define TIMER2_OVF_vect                __vector_5
/* Timer/Counter1 Capture Event */
#define TIMER1_ICU_vect                __vector_6
/* Timer/Counter1 Compare match A */
#define TIMER1_OCA_vect                __vector_7
/* Timer/Counter1 Compare match B */
#define TIMER1_OCB_vect                __vector_8
/* Timer/Counter1 Overflow */
#define TIMER1_OVF_vect                __vector_9
/* Timer/Counter0 Compare match */
#define TIMER0_OC_vect                 __vector_10
/* Timer/Counter0 Overflow */
#define TIMER0_OVF_vect                __vector_11
/* Serial Transfer Complete */
#define SPI_STC_vect                   __vector_12
/* USART RX Complete */
#define UART_RX_vect                   __vector_13
/* USART Data Register Empty */
#define UART_UDRE_vect                 __vector_14
/* USART TX Complete */
#define UART_TX_vect                   __vector_15
/* ADC Conversion Complete */
#define ADC_vect                       __vector_16
/* EEPROM Ready*/
#define EE_RDY_vect                    __vector_17
/* Analog Comparator */
#define ANA_COMP_vect                  __vector_18
/* 2-wire serial Interface */
#define TWI_vect                       __vector_19
/* Store program memory ready */
#define SPM_RDY_vect                   __vector_20

#define BAD_vect  __vector_default

/* Interrupt Functions */

#define sei()  __asm__ __volatile__ ("sei" ::) // enable global interrupt
#define cli()  __asm__ __volatile__ ("cli" ::) // disable global interrupt
#define reti()  __asm__ __volatile__ ("reti" ::)
#define ret()  __asm__ __volatile__ ("ret" ::)

#define ISR_NOBLOCK     __attribute__((interrupt))
#define ISR_NAKED       __attribute__((naked))


#define ISR(vector,...)             \
void vector (void) __attribute__ ((signal))__VA_ARGS__ ;\
void vector (void)

#endif /* EXINTERRUPT_REGISTER_H_ */