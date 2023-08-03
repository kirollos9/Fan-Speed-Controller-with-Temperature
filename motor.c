/*
 * motor.c
 *
 *  Created on: Oct 14, 2021
 *      Author: kirollos Gerges
 */
#include "common_macros.h"
#include "motor.h"
#include "gpio.h"
#include "std_types.h"
#include "avr/io.h"
#include "pwm.h"

void DcMotor_Init(void)
{
GPIO_setupPinDirection(PORTB_ID, PIN0_ID, PIN_OUTPUT);
GPIO_setupPinDirection(PORTB_ID, PIN1_ID, PIN_OUTPUT);
GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_LOW);
GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_LOW);

}
void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{
PORTB=((PORTB & 0xFC)| state);
PWM_Timer0_Start(speed);
}



