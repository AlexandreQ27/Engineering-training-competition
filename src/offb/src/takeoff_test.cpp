#include <ros/ros.h>
#include "state_from_mavros.h"
#include "offboard_control.h"


int main(int argc, char** argv)
{
    ros::init(argc, argv, "takeoff");
    ros::NodeHandle nh;
    OffboardControl Offb_;
    state_from_mavros state_now;
    Eigen::Vector4d push;
    double desire_push;
    ros::param::get("~desire_push", desire_push);
    for(int i = 0; i < 4; i++)
    {
        push[i] = desire_push;
    }    
    ros::Rate rate(20.0);
    while(ros::ok())
    {
        if(state_now._DroneState.armed && state_now._DroneState.mode == "OFFBOARD")
        {
        Offb_.send_actuator_setpoint(push);            
        }
        ros::spinOnce();
        rate.sleep();
    }
    return 0;
}