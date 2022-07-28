/**
  ****************************(C) COPYRIGHT 2019 DJI****************************
  * @file       can_receive.c/h
  * @brief      there is CAN interrupt function  to receive motor data,
  *             and CAN send function to send motor current to control motor.
  *             这里是CAN中断接收函数，接收电机数据,CAN发送函数发送电机电流控制电机.
  * @note
  * @history
  *  Version    Date            Author          Modification
  *  V1.0.0     Dec-26-2018     RM              1. done
  *
  @verbatim
  ==============================================================================
  ==============================================================================
  @endverbatim
  ****************************(C) COPYRIGHT 2019 DJI****************************
  */

#ifndef CAN_RECEIVE_H
#define CAN_RECEIVE_H

#include "struct_typedef.h"

#define CHASSIS_CAN hcan1

/* CAN send and receive ID */
typedef enum
{
    CAN_FIRST_TAG = 0x200,
    CAN_SECOND_TAG = 0x1FF,

    CAN_3508_LEFT_ID = 0x201,
    CAN_3508_RIGHT_ID = 0x202,
    CAN_2006_PUSHING_ID = 0x203,

} can_msg_id_e;


/*robomaster motor data structure*/
typedef struct
{
    uint16_t ecd;
    int16_t speed_rpm;
    int16_t given_current;
    uint8_t temperate;
    int16_t last_ecd;
} motor_measure_t;



/**
  * @brief          发送电机控制电流(0x201,0x202,0x203)
  * @param[in]      motor_left: (0x201) 3508电机控制电流, 范围 [-16384,16384]
  * @param[in]      motor_right: (0x202) 3508电机控制电流, 范围 [-16384,16384]
  * @param[in]      pushing: (0x203) 2006电机控制电流, 范围  [-10000,10000]
  * @retval         none
  */
extern void CAN_cmd_chassis(int16_t motor_left, int16_t motor_right, int16_t pushing);


/**
  * @brief          返回拨弹电机 2006电机数据指针
  * @param[in]      none
  * @retval         电机数据指针
  */
extern const motor_measure_t *get_pushing_motor_measure_point(void);

/**
  * @brief          返回底盘电机 3508电机数据指针
  * @param[in]      i: 电机编号,范围[0,1]
  * @retval         电机数据指针
  */
extern const motor_measure_t *get_chassis_motor_measure_point(uint8_t i);


#endif