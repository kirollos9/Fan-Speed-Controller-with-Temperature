/*
 * timer0.c
 *
 *  Created on: Oct 31, 2021
 *      Author: Kirollos Gerges
 */
#include "timer0.h"
#include "common_macros.h"
#include <avr/interrupt.h>
#include <avr/io.h>
static volatile void (*g_callBackPtr)(void) = NULL_PTR;
ISR(TIMER0_OVF_vect)
{
	if(g_callBackPtr != NULL_PTR)
		{

			(*g_callBackPtr)();
		}
}
ISR(TIMER0_COMP_vect)
{
	if(g_callBackPtr != NULL_PTR)
		{
			(*g_callBackPtr)();
		}
}

void Timer0_init(const timer0config * ptr)
{
	SREG  |= (1<<7);
	TCNT0 = 0; //Set Timer initial value to 0
   if((ptr->Mode)==NORMAL)
   {
	   TIMSK |= (1<<TOIE0); /* Enable Timer0 Overflow Interrupt*/
	   TCCR0 = (1<<FOC0);
	   TCCR0 = (TCCR0&0xf8)|(ptr ->Prescaler);
   }
   else
   {
	   OCR0  =(ptr->ocr);
	   TIMSK |= (1<<OCIE0);
	   TCCR0 = (1<<FOC0) | (1<<WGM01);
	   TCCR0 = (TCCR0&0xf8)|(ptr ->Prescaler);
   }







}
void SetCallBack(void(*a_ptr)(void))
{
	g_callBackPtr= a_ptr;
}
void Timer0_deinit(void)
{
	TIFR |=TOV0;
	TCCR0=0;
}



