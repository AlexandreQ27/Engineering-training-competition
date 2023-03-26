//
// Created by xs on 22-6-23.
//

#ifndef SRC_TEST_MODE_H
#define SRC_TEST_MODE_H
#include <ros/ros.h>
#include <mavros_msgs/SetMode.h>
#include <mavros_msgs/CommandBool.h>
#include <mavros_msgs/PositionTarget.h>
#include <geometry_msgs/PoseStamped.h>
#include "offb_msgs/ControlCommand.h"

//enum fly_mode
//{
//    Idle,    // 怠速模式，无人机切换到OFFBOARD模式，但是并不解锁
//    Takeoff, //起飞模式，无人机解锁，在OFFBOARD模式下，发送起飞点坐标，无人机起飞
//    Hover,   // 悬停模式，无人机保持OFFBOARD模式，向无人机发送自身坐标点
//    Move,    // 移动模式，无人机接受用户输入的目标点信息
//    Land,    // 降落模式，无人机直接切换到LAND模式，在降落后上锁
//    Disarm,  // 对无人机进行上锁
//};

// 定义一些订阅者
ros::Subscriber command_sub;
ros::Subscriber state_sub;

ros::ServiceClient set_mode_client;
ros::ServiceClient arming_client;
ros::Publisher pos_pub;
ros::Publisher vel_pub;
ros::Publisher pos_raw_pub;

// 订阅者对应的回调函数

offb_msgs::ControlCommand command_now;

void command_cb(const offb_msgs::ControlCommand::ConstPtr& msg);

#endif //SRC_TEST_MODE_H
