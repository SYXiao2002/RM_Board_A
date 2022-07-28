#include "user_pid.h"

fp32 ShootMotor1PID[3] = {ShootMOTOR1_SPEED_PID_KP, ShootMOTOR1_SPEED_PID_KI, ShootMOTOR1_SPEED_PID_KD};
pid_type_def ShootMotor1;

fp32 ShootMotor2PID[3] = {ShootMOTOR2_SPEED_PID_KP, ShootMOTOR2_SPEED_PID_KI, ShootMOTOR2_SPEED_PID_KD};
pid_type_def ShootMotor2;

fp32 PushMotorPID[3] = {PushMotor_SPEED_PID_KP, PushMotor_SPEED_PID_KI, PushMotor_SPEED_PID_KD};
pid_type_def PushMotor;


void user_pid_Init(void){
	PID_init(&ShootMotor1, PID_POSITION, ShootMotor1PID, ShootMOTOR1_SPEED_PID_MAX_OUT, ShootMOTOR1_SPEED_PID_MAX_IOUT);
	PID_init(&ShootMotor2, PID_POSITION, ShootMotor2PID, ShootMOTOR2_SPEED_PID_MAX_OUT, ShootMOTOR2_SPEED_PID_MAX_IOUT);
	PID_init(&PushMotor, PID_POSITION, PushMotorPID, PushMotor_SPEED_PID_MAX_OUT, PushMotor_SPEED_PID_MAX_IOUT);
}


void user_pid_Calc(void){
	PID_calc(&ShootMotor1, get_chassis_motor_measure_point(0)->speed_rpm, 0);
	PID_calc(&ShootMotor2, get_chassis_motor_measure_point(1)->speed_rpm, 0);
	PID_calc(&PushMotor, get_pushing_motor_measure_point()->speed_rpm, 4000);
}

void shoot(void){
    user_pid_Calc();
    CAN_cmd_chassis(ShootMotor1.out,
                    ShootMotor2.out,
                    PushMotor.out);
}

