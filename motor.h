/*
 * motor.h
 *
 *  Created on: Oct 14, 2021
 *      Author: kirollos gerges
 */

#ifndef MOTOR_H_
#define MOTOR_H_
#include "std_types.h"
typedef enum{
	Stop,Cw,A_Cw
}DcMotor_State;
void DcMotor_Init(void);
void DcMotor_Rotate(DcMotor_State state,uint8 speed);



#endif /* MOTOR_H_ */
