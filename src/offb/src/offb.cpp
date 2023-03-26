/**
 * @file offb_node.cpp
 * @brief Offboard control example node, written with MAVROS version 0.19.x, PX4 Pro Flight
 * Stack and tested in Gazebo SITL
 */
#include "offboard_control.h"

using namespace std;
double fly_point[100][3];    //存储无人机预定航点
double desire_vz = 0;  //预期降落速度
double yawl_desire;
Eigen::Vector3d fly_start;

mavros_msgs::State current_state;     //定义current_state结构体用来接受发布的消息
void state_cb(const mavros_msgs::State::ConstPtr& msg){
    current_state = *msg;
}                             //回调函数，传递状态的地址，利用取地址函数将函数值传递

Eigen::Vector3d pos_drone;        //定义三元组来存储无人机的当前位置（x,y,z）
Eigen::Vector3d next_point;                  
void pos_cb(const geometry_msgs::PoseStamped::ConstPtr &msg)   
{
    Eigen::Vector3d pos_drone_fcu_enu(msg->pose.position.x,msg->pose.position.y,msg->pose.position.z);

    pos_drone = pos_drone_fcu_enu;
}

int not_arrive(double x, double y, double z)     //判断无人机是否到达目标点
{
    double x_mis = abs(pos_drone[0] - x);
    double y_mis = abs(pos_drone[1] - y);
    double z_mis = abs(pos_drone[2] - z);
    if(x_mis <= 0.1 && y_mis <= 0.1 && z_mis <= 0.1){
        return 0;
    }
    else{
        return 1;
    }
}

void add_target(int i){                      //根据当前向飞控发送的位置信息，以及下一个航点的信息来改变下一个时刻向飞控发送的位置信息
    // x方向的下一位置改变
    double change = 0.04;
    if(abs(next_point[0] - fly_point[i][0]) > 0.3){
        if(next_point[0] > fly_point[i][0]){
            next_point[0] -= change;
        }
        else{
            next_point[0] += change;
        }
    }else{
        next_point[0] = fly_point[i][0];
    }
    //y方向的下一位置改变
    if(abs(next_point[1] - fly_point[i][1])){
        if(next_point[1] > fly_point[i][1]){
            next_point[1] -= change;
        }else{
            next_point[1] += change;
        }
    }else{
        next_point[1] = fly_point[i][1];
    }
    //z方向的下一位置改变
     if(abs(next_point[2] - fly_point[i][2]) > 0.3){
        if(next_point[2] > fly_point[i][2]){
            next_point[2] -= change;
        }
        else{
            next_point[2] += change;
        }
    }else{
        next_point[2] = fly_point[i][2];
    }
}

void landing_vel()
{
    // scanf("%lf", &desire_vz);
    OffboardControl OffboardControl_;
    ros::Rate rate(10.0);
    Eigen::Vector3d desire_vel;
    desire_vel[0] = 0;
    desire_vel[1] = 0;
    desire_vel[2] = desire_vz;
    while(ros::ok()){
        OffboardControl_.send_velxyz_setpoint(desire_vel, yawl_desire);
        ros::spinOnce();
        rate.sleep();
        if(current_state.armed == false){
            return;
        }
    }
}

void set_point(int i, ros::Publisher local_pos_pub){               
    geometry_msgs::PoseStamped pose_2;
     ros::Rate rate(10.0);
    // if(!current_state.armed){
    //     local_pos_pub.publish(pose_2);
    //     return;
    // }
    ROS_INFO("flying!!");
    while(ros::ok && not_arrive(fly_point[i][0],fly_point[i][1] ,fly_point[i][2])){
        add_target(i);
        pose_2.pose.position.x = next_point[0];
        pose_2.pose.position.y = next_point[1];
        pose_2.pose.position.z = next_point[2];
        local_pos_pub.publish(pose_2);
        ros::spinOnce();
        rate.sleep();
    }
    ROS_INFO("arrived!!!");
    return;
} 

int main(int argc, char **argv)
{
    
    ros::init(argc, argv, "offb_node");                   //自定义节点，offb_node
    // ros::NodeHandle nh("iris_0");                        //定义iris_0空间下的句柄，这样订阅，发布的消息华话题前都会加上，/iris_0                    
    ros::NodeHandle nh;      
    
    ros::Subscriber state_sub = nh.subscribe<mavros_msgs::State>     //定义订阅者，订阅无人机的状态，比如当前状态，是否解锁
            ("mavros/state", 10, state_cb);
    ros::Subscriber position_sub = nh.subscribe<geometry_msgs::PoseStamped>     //定义订阅者，订阅无人机当前的位置
            ("mavros/local_position/pose", 10, pos_cb);
    ros::Publisher local_pos_pub = nh.advertise<geometry_msgs::PoseStamped>     //定义发布者，发布对无人机的位置控制
            ("mavros/setpoint_position/local", 10);
    ros::ServiceClient arming_client = nh.serviceClient<mavros_msgs::CommandBool>     //定义服务，用来解锁无人机
            ("mavros/cmd/arming");
    ros::ServiceClient set_mode_client = nh.serviceClient<mavros_msgs::SetMode>       //定义服务，用来改变无人机的模式
            ("mavros/set_mode");

    //定义位置信息发布的频率，大于2Hz即可
    ros::Rate rate(10.0);

    //等待无人机连接 
    while(ros::ok() && !current_state.connected){
        ros::spinOnce();
        rate.sleep();
    }                    

    int num, i;             //输入并存储航点
    // cout <<"请输入期望降落速度以及偏航角" << endl;
    // scanf("%lf", &desire_vz);
    // scanf("%lf", &yawl_desire);
    cout << "请输入起飞点的目标" << endl;
    scanf("%lf", &fly_start[0]);
    scanf("%lf", &fly_start[1]);
    scanf("%lf", &fly_start[2]);
    printf("请输入目标点的个数：");
    scanf("%d", &num);
    for(i = 0; i < num; i++){
        printf("请输入第%d个航点：", i+1);
        scanf("%lf", &fly_point[i][0]);
        scanf("%lf", &fly_point[i][1]);
        scanf("%lf", &fly_point[i][2]);
    }

    next_point = fly_start;
    geometry_msgs::PoseStamped pose;          //定义发布的位置信息
    pose.pose.position.x = fly_start[0];
    pose.pose.position.y = fly_start[1];
    pose.pose.position.z = fly_start[2];

    //在无人机启动前向飞控发布一些点，不然飞控会拒绝进入OFFBOARD
    for(int i = 20; ros::ok() && i > 0; --i){
        local_pos_pub.publish(pose);
        ros::spinOnce();
        rate.sleep();
    }

    mavros_msgs::SetMode offb_set_mode;     //定义改变模式的变量
    offb_set_mode.request.custom_mode = "OFFBOARD";

    mavros_msgs::CommandBool arm_cmd;     //定义解锁飞机的变量
    arm_cmd.request.value = true;

    int count = 0, flag = 1;
    ros::Time last_request = ros::Time::now();      //记录飞机的当前时间
    while(ros::ok()){
        //如果当前不是OFFBOARD模式，并且持续了2s，执行内层if
        // if( current_state.mode != "OFFBOARD" &&(ros::Time::now() - last_request > ros::Duration(2.0))){      
        //     //改变当前模式为OFFBOARD
        //     if( set_mode_client.call(offb_set_mode) && offb_set_mode.response.mode_sent){
        //         ROS_INFO("Offboard enabled");
        //     }
        //     last_request = ros::Time::now();   //更新当前的last_request时间
        // } else {
        //     //如果在转化模式后，飞机未解锁并且持续了2s，执行内层if
        //     if( !current_state.armed &&(ros::Time::now() - last_request > ros::Duration(2.0))){
        //         //解锁飞机，flag = 1用来跳出while循环
        //         if( arming_client.call(arm_cmd) && arm_cmd.response.success){
        //             ROS_INFO("Vehicle armed");
        //             flag = 1;
        //         }
        //         last_request = ros::Time::now();
        //     }
        // }
        if(current_state.mode == "OFFBOARD" && current_state.armed)
        {
            break;
        }
        if(flag)
        {
            ROS_INFO("Waiting for armed and OFFBOARD mode.......");
            flag = 0;
        }
        local_pos_pub.publish(pose);   //循环中需要一直向飞控发送坐标点信息，不然就会退出OFFBOARD模式，飞机失控
        ros::spinOnce();
        rate.sleep();
    }
    for(i = 0; i < num ; i++){    //根据存储的航点，一个个飞行
        if(ros::ok){
            set_point(i, local_pos_pub);
            landing_vel();
        }
        else{
            break;
        }
    }
    // landing_vel();    //执行降落程序
    offb_set_mode.request.custom_mode = "AUTO.LAND";     //更改飞行模式为手动
    arm_cmd.request.value = false;      //对飞机上锁
    flag = 0;
    // while(ros::ok){
        //这一段同理上面的
        if( current_state.mode != "AUTO.LAND" ){
            if(set_mode_client.call(offb_set_mode) && 
            offb_set_mode.response.mode_sent){
                ROS_INFO("land enabled");
            }
            last_request = ros::Time::now();
        } 
        // else {
        //     if( !current_state.armed && (ros::Time::now() - last_request > ros::Duration(2.0)) ){
        //         if( arming_client.call(arm_cmd) && arm_cmd.response.success){
        //             ROS_INFO("Vehicle disarmed");
        //         }
        //         flag = 1;
        //     }
    // }
    //     if(flag){
    //         break;
    //     }
    // }
    return 0;
}
