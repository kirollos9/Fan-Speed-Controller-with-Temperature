/*
 * timer0.h
 *
 *  Created on: Oct 31, 2021
 *      Author: Kirollos Gerges Sobhy
 */

#ifndef TIMER0_H_
#define TIMER0_H_
#include "std_types.h"
typedef enum
{
	NORMAL,CTC
}mode;
typedef enum
{
	NOCLOCK,NOPRESCALER,CLK_8,CLK_64,CLK_256,CLK_1024
} prescaler;
typedef struct{
	uint8 ocr;
	prescaler Prescaler;
	mode Mode;

}timer0config;
void Timer0_init(const timer0config * Ptr);
void SetCallBack(void(*a_ptr)(void));
void Timer0_deinit(void);

#endif /* TIMER0_H_ */
