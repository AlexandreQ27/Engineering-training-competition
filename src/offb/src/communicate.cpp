//
// Created by xs on 22-6-25.
//

#include "ros/ros.h"
#include "geometry_msgs/Pose.h"
#include "geometry_msgs/PoseStamped.h"

geometry_msgs::Pose pose;
geometry_msgs::PoseStamped poseStamped;

void listen_keyboard_cb(const geometry_msgs::Pose::ConstPtr &msg){
    pose = *msg;
    poseStamped.header.stamp = ros::Time::now();
    poseStamped.pose = pose;
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "communicate");
    ros::NodeHandle nh;
    ros::Rate rate(30);

    ros::Subscriber listen_keyboard = nh.subscribe<geometry_msgs::Pose>("/mavros/point_from_keyboard", 10, listen_keyboard_cb);
    ros::Publisher cmd_pos = nh.advertise<geometry_msgs::PoseStamped>("/mavros/setpoint_position/local", 10);

    printf("通信初始化成功\n");
    while(ros::ok())
    {
        cmd_pos.publish(poseStamped);
        rate.sleep();
        ros::spinOnce();
    }

    return 0;
}
