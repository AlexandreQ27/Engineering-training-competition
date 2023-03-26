//
// Created by xs on 22-6-23.
//
#include "test_mode.h"

void command_cb(const offb_msgs::ControlCommand::ConstPtr& msg) {
    command_now = *msg;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "test_mode_node");
    ros::Rate rate(20);
    ros::NodeHandle nh;

    command_sub = nh.subscribe("/command", 10, command_cb);
    set_mode_client = nh.serviceClient<mavros_msgs::SetMode>("/mavros/set_mode");
    arming_client = nh.serviceClient<mavros_msgs::CommandBool>("/mavros/cmd/arming");


    while(ros::ok())
    {
        switch(command_now.Command_ID)
        {
            case offb_msgs::ControlCommand::Idle:

        }
    }
}