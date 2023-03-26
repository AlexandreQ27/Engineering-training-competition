#include "offboard_control.h"

Eigen::Vector3d vel_pos(0, 0, 0.1);
Eigen::Vector3d pos(0, 0, 0.5);
Eigen::Vector3d pos_drone;

mavros_msgs::State current_state;     //定义current_state结构体用来接受发布的消息
void state_cb(const mavros_msgs::State::ConstPtr& msg){
    current_state = *msg;
}        

void pos_cb(const geometry_msgs::PoseStamped::ConstPtr &msg)   
{
    Eigen::Vector3d pos_drone_fcu_enu(msg->pose.position.x,msg->pose.position.y,msg->pose.position.z);

    pos_drone = pos_drone_fcu_enu;
}
int main(int argc, char **argv)
{
    ros::init(argc, argv, "send_info");
    ros::NodeHandle nh;
    ros::Rate rate(20.0);
    ros::Time last_record = ros::Time::now();
     ros::Subscriber state_sub = nh.subscribe<mavros_msgs::State>     //定义订阅者，订阅无人机的状态，比如当前状态，是否解锁
            ("mavros/state", 10, state_cb);
    ros::Subscriber position_sub = nh.subscribe<geometry_msgs::PoseStamped>     //定义订阅者，订阅无人机当前的位置
            ("/mavros/local_position/pose", 10, pos_cb);
     OffboardControl Offb_;
    while(ros::ok() && !current_state.connected)
    {
        Offb_.send_velxyz_setpoint(vel_pos, 0);
        ros::spinOnce();
        rate.sleep();
    }
    while(ros::ok())
    {
        // Offb_.send_pos_setpoint(pos, 0);
        if(current_state.armed && (current_state.mode == "OFFBOARD"))
        {
            //
        }
        else{
            Offb_.send_velxyz_setpoint(vel_pos, 0);
        }
        if((ros::Time::now() - last_record) > ros::Duration(3.0))
        {
            ROS_INFO("working.......");
            last_record = ros::Time::now();
        }
        ros::spinOnce();
        rate.sleep();
    } 
}