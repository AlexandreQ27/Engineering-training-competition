//
// Created by xs on 22-6-24.
//

#ifndef SRC_MULTI_INPUT_H
#define SRC_MULTI_INPUT_H
#include <ros/ros.h>
#include <iostream>
#include "state_from_mavros.h"
#include <mavros_msgs/CommandBool.h>
#include <mavros_msgs/SetMode.h>
#include <mavros_msgs/PositionTarget.h>
#include <geometry_msgs/PoseStamped.h>
#include <mavros_msgs/State.h>
#include <geometry_msgs/Pose.h>
#include <Eigen/Dense>


typedef enum mode_type
{
    OFFBOARD,
    LAND,
    HOVER
}mode_type;

const double tolerance = 0.2;

class multi_input
{
public:
    multi_input(ros::NodeHandle &nh);
    ~multi_input();
    bool Arming(bool type);
    bool Set_Mode(mode_type mode);
    bool Init();
    bool Fly_to(const geometry_msgs::Pose &point);
    bool Ok_for_fly();
    void inline Pub_pose(const geometry_msgs::Pose &point)
    {
        pos_pub.publish(point);
    }


private:
    ros::NodeHandle nh;
    ros::ServiceClient arming_client;
    ros::ServiceClient set_mode_client;

    ros::Subscriber state_sub;
    ros::Subscriber pos_sub;

    ros::Publisher pos_pub;
    ros::Publisher raw_pub;

    mavros_msgs::State Drone_state;
    geometry_msgs::PoseStamped Drone_pose;

    void state_cb(const mavros_msgs::State::ConstPtr &msg);
    void pos_cb(const geometry_msgs::PoseStamped::ConstPtr &msg);
};

multi_input::multi_input(ros::NodeHandle &nh) {
    this->nh = nh;
    arming_client = this->nh.serviceClient<mavros_msgs::CommandBool>("/mavros/cmd/arming", 1);
    set_mode_client = this->nh.serviceClient<mavros_msgs::SetMode>("/mavros/set_mode", 1);
    state_sub = this->nh.subscribe<mavros_msgs::State>("/mavros/state", 10, &multi_input::state_cb, this);
    pos_sub = this->nh.subscribe <geometry_msgs::PoseStamped> ("/mavros/local_position/pose", 10, &multi_input::pos_cb, this);
    pos_pub = this->nh.advertise<geometry_msgs::Pose>("/mavros/point_from_keyboard", 10);
    raw_pub = this->nh.advertise<mavros_msgs::PositionTarget>("/mavros/setpoint_raw/local", 10);
}

multi_input::~multi_input() {
    printf("multi_input class ended\n");
}

void multi_input::state_cb(const mavros_msgs::State_<allocator<void>>::ConstPtr &msg) {
    Drone_state = *msg;
}

void multi_input::pos_cb(const geometry_msgs::PoseStamped::ConstPtr &msg) {
    Drone_pose = *msg;
}

bool multi_input::Arming(bool type) {
    mavros_msgs::CommandBool arming;
    arming.request.value = type;
    return arming_client.call(arming);
}

bool multi_input::Set_Mode(mode_type mode) {
    mavros_msgs::SetMode setmode;
    switch(mode)
    {
        case mode_type::OFFBOARD:
            setmode.request.custom_mode = "OFFBOARD";
            break;
        case mode_type::LAND:
            setmode.request.custom_mode = "LAND";
            break;
        case mode_type::HOVER:
            setmode.request.custom_mode = "AUTO.LIOTER";
            break;
        default:
            printf("get wrong mode\n");
            return false;
    }
    bool result = set_mode_client.call(setmode);
    return result;
}

bool multi_input::Init() {
    if(!Drone_state.connected)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool multi_input::Fly_to(const geometry_msgs::Pose &point) {
    static int flag = 0;
    if(flag == 0)
    {
        pos_pub.publish(point);
        printf("正在前往点 %lf %lf %lf\n", point.position.x, point.position.y, point.position.z);
        flag = 1;
        return false;
    }
    double pos_x, pos_y, pos_z;
    double x, y, z;
    pos_x =  Drone_pose.pose.position.x;
    pos_y = Drone_pose.pose.position.y;
    pos_z = Drone_pose.pose.position.z;
    x = point.position.x;
    y = point.position.y;
    z = point.position.z;
    if(abs(pos_x - x) < tolerance && abs(pos_y - y) < tolerance && abs(pos_z - z) < tolerance)
    {
        flag = 0;
        printf("到达点 %lf %lf %lf\n", point.position.x, point.position.y, point.position.z);
        return true;
    }
    else
    {
        return false;
    }
}

bool multi_input::Ok_for_fly() {
    if(Drone_state.armed == true && Drone_state.mode == "OFFBOARD")
    {
        return true;
    }
    else
    {
        return false;
    }
}

double rate;
int fly_nums;
double fly_points[100][3];

void print_input_tips();
void start_mission();
bool If_continue();
#endif //SRC_MULTI_INPUT_H
