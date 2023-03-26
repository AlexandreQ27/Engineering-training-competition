#include "offboard_control.h"
#include <state_from_mavros.h>

Eigen::Vector2f x_boarder;  //设置电子围栏
Eigen::Vector2f y_boarder;
Eigen::Vector2f z_boarder;
{
    x_boarder[0] = 2;
    x_boarder[1] = 2;
    y_boarder[0] = 2;
    y_boarder[1] = 2;
    z_boarder[0] = 0;
    z_boarder[1] = 3;
}
Eigen::Vector3d start_fly;     //设置起飞点
{
    start_fly[0] = 0;
    start_fly[1] = 0;
    start_fly[2] = 0.5;
}
Eigen::Vector3d pos;
{
    pos[0] = start_fly[0];
    pos[1] = start_fly[1];
    pos[2] = start_fly[2];
}
Eigen::Vector3d vel;
{
    vel[0] = 0;
    vel[1] = 0;
    vel[2] = 2;
}
ros::Rate rate(20.0);
int main(int argc, char **argv)
{
    ros::init(argc, argv, "fly_node");
    ros::NodeHandle nh;
    OffboardControl OffbCtrl; //建立类的对象，来实例化方法
    state_from_mavros state_mavros;
    ros::ServiceClient set_mode_client = nh.serviceClient<mavros_msgs::SetMode>("/mavros/set_mode");
    ros::ServiceClient arming_client = nh.serviceClient<mavros_msgs::CommandBool>("/mavros/cmd/arming");
    mavros_msgs::SetMode mode_cmd;
    mavros_msgs::CommandBool arm_cmd;
    arm_cmd.request.value = true;
    while(ros::ok() && state_mavros._DroneState.connected)
    {
        ros::spinOnce();
        rate.sleep();
    }
    ROS_INFO("")
    while(1)
    {
        OffbCtrl.send_body_velxyz_setpoint(vel, 0);
    }
    while()
}