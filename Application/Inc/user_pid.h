#ifndef USER_PID_H
#define USER_PID_H

#include "stm32f4xx_hal.h"
#include "struct_typedef.h"
#include "pid.h"
#include "CAN_receive.h"


//PID   for the left RM_3I508_Motor
#define ShootMOTOR1_SPEED_PID_KP 30.0f
#define ShootMOTOR1_SPEED_PID_KI 0.001f
#define ShootMOTOR1_SPEED_PID_KD 0.8f
#define ShootMOTOR1_SPEED_PID_MAX_OUT 16000.0f
#define ShootMOTOR1_SPEED_PID_MAX_IOUT 2000.0f

//PID   for the right RM_3508_Motor
#define ShootMOTOR2_SPEED_PID_KP 30.0f
#define ShootMOTOR2_SPEED_PID_KI 0.001f
#define ShootMOTOR2_SPEED_PID_KD 0.8f
#define ShootMOTOR2_SPEED_PID_MAX_OUT 16000.0f
#define ShootMOTOR2_SPEED_PID_MAX_IOUT 2000.0f

//PID   for the pushing RM_2006_Motor
#define PushMotor_GYRO_ABSOLUTE_PID_KP 15.0f
#define PushMotor_GYRO_ABSOLUTE_PID_KI 0.0f
#define PushMotor_GYRO_ABSOLUTE_PID_KD -0.7f
#define PushMotor_GYRO_ABSOLUTE_PID_MAX_OUT 10.0f
#define PushMotor_GYRO_ABSOLUTE_PID_MAX_IOUT 0.0f
#define PushMotor_SPEED_PID_KP 15.0f
#define PushMotor_SPEED_PID_KI 0.001f
#define PushMotor_SPEED_PID_KD 0.09f
#define PushMotor_SPEED_PID_MAX_OUT 2000.0f
#define PushMotor_SPEED_PID_MAX_IOUT 10.0f



void user_pid_Init(void);
void user_pid_Calc(void);
void shoot(void);

#endif
