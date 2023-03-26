#include "offboard_control.h"
#include <geometry_msgs/TwistStamped.h>
#include <std_msgs/UInt16.h>
#include "offb/Circle.h"

double desire_z;  //无人机将一直以这个高度飞行
double desire_vz = 0.5; //无人机以这个速度起飞降落
int num_fly;     //无人机的航点个数
double change;
double fly_point[100][3];   //存储无人机的航点
/*double fx=4.476;//通过相机标定求得的焦距fx
double fy=5.96;//通过相机标定求得的焦距fy
double x_size=960;//x方向像素
double y_size=540;//y方向像素
double sensor_x=3.2;//传感器宽度
double sensor_y=2.4;//传感器高度 */
double x_change;
double y_change;
double x_square_change;
double y_square_change;
Eigen::Vector3d start_point, next_point, end_point;
Eigen::Vector3d start_vel, landing_vel, slow_vel;
Eigen::Vector3d pos_drone, vel_drone;

 void pos_cb(const geometry_msgs::PoseStamped::ConstPtr &msg)
        {
            pos_drone[0] = msg->pose.position.x;
            pos_drone[1] = msg->pose.position.y;
            pos_drone[2] = msg->pose.position.z;
        }
    
    void vel_cb(const geometry_msgs::TwistStamped::ConstPtr &msg)
        {
            vel_drone[0] = msg->twist.linear.x;
            vel_drone[1] = msg->twist.linear.y;
            vel_drone[2] = msg->twist.linear.z;
        }

mavros_msgs::State state_drone;
 void state_cb(const mavros_msgs::State::ConstPtr &msg)
        {
            state_drone.connected = msg->connected;
            state_drone.armed = msg->armed;
            state_drone.mode = msg->mode;
        }

offb::Circle center;
void circle_change(const offb::Circle::ConstPtr &msg)
        {
            //ROS_INFO("The change of circle center is x:%0.2f y:%0.2f", msg->circle_x, msg->circle_y);
	    center.circle_x = msg->circle_x;
            center.circle_y = msg->circle_y;
	    x_change = center.circle_x;
            y_change = center.circle_y;

        }

offb::Circle sqr;
void square_change(const offb::Circle::ConstPtr &msg_s)
        {
            //ROS_INFO("The change of square center is x:%0.2f y:%0.2f", msg->circle_x, msg->circle_y);
	    sqr.circle_x = msg_s->circle_x;
            sqr.circle_y = msg_s->circle_y;
	    x_square_change = sqr.circle_x;
            y_square_change = sqr.circle_y;

        }

void add_target(int i){                      //根据当前向飞控发送的位置信息，以及下一个航点的信息来改变下一个时刻向飞控发送的位置信息
    for(int j = 0; j < 3; j++)
    {
        if(abs(next_point[j] - fly_point[i + 1][j]) > 0.3){
            if(next_point[j] > fly_point[i + 1][j]){
                next_point[j] -= change;
            }
            else{
                next_point[j] += change;
            }
        }else{
            next_point[j] = fly_point[i + 1][j];
        }
    }
}

int not_arrived( int i )     //判断无人机是否到达目标点
{
    double x_mis = abs(pos_drone[0] - fly_point[i + 1][0]);
    double y_mis = abs(pos_drone[1] - fly_point[i + 1][1]);
    double z_mis = abs(pos_drone[2] - fly_point[i + 1][2]);
    if(x_mis <= 0.15 && y_mis <= 0.15 && z_mis <= 0.15){
        return 0;
    }
    else{ 
        return 1;
    }
}

void fly_high(int i, double desire_z )
{
    OffboardControl Offb_;
    ros::Rate rate(20.0);
    cout << "正在上升中" << endl;
    Eigen::Vector3d high_pos;
    high_pos[0] = pos_drone[0];
    high_pos[1] = pos_drone[1];
    high_pos[2] = 0.3;
    double current_z;
    if (i == 0)
    {
        current_z = 1.0;
    }
    else
    {
        current_z = desire_z;
    }
    while(abs(pos_drone[2] - current_z) > 0.05)
    {
        if(state_drone.armed)
        {
            Offb_.send_local_pos_setpoint(high_pos);
            if(high_pos[2] < current_z + 0.1)
            {
                high_pos[2] += change;
            }
        }
        else{
            cout << "无人机已上锁" << endl;
        }
        ros::spinOnce();
        rate.sleep();
    }
    cout << "已经到达期望高度" << endl;
}

void fly_to(int i)
{
    OffboardControl Offb_;
    ros::Rate rate(20.0);
    cout << "正在飞往下一个目标点" << endl;
    while(not_arrived(i))
    {
        add_target(i);
        Offb_.send_local_pos_setpoint(next_point);
        ros::spinOnce();
        rate.sleep();
    }
    cout << "已经到达目标点上方"  << endl;
}

void fly_stay(int i,double desire_z)
{
	Eigen::Vector3d high_pos;
	OffboardControl Offb_;
    ros::Rate rate(20.0);
	ros::Time last_request = ros::Time::now();
    double current_z;
    if (i == 0)
    {
        current_z = 1.0;
    }
    else
    {
        current_z = desire_z;
    }
    high_pos[0] = fly_point[i+1][0];
   	high_pos[1] = fly_point[i+1][1];
   	high_pos[2] = current_z;
   	cout << "已经到达期望高度,将保持3s" << endl;
	while(ros::Time::now() - last_request < ros::Duration(5.0))
        {
        ros::spinOnce();
        rate.sleep();
        ROS_INFO("The change of circle center is x:%0.2f y:%0.2f", x_change, y_change);//在纠偏过程中打印修正后的圆心数据
        Offb_.send_local_pos_setpoint(high_pos); 
	}
}
void fly_change(int i, double desire_z )//降低高度至desire_z/2
{
    OffboardControl Offb_;
    ros::Rate rate(20.0);
    cout << "正在下降中" << endl;
    Eigen::Vector3d high_pos;
    if(i==3)
    {
        fly_point[i+1][0]=fly_point[i+1][0]-x_square_change;
        fly_point[i+1][1]=fly_point[i+1][1]-y_square_change;
    }
    else
    {
        fly_point[i+1][0]=fly_point[i+1][0]-x_change;
        fly_point[i+1][1]=fly_point[i+1][1]-y_change;
    }
    double current_z;
    if (i == 0)
    {
        current_z = 1.0;
    }
    else
    {
        current_z = desire_z;
    }
    high_pos[0] = fly_point[i+1][0];
    high_pos[1] = fly_point[i+1][1];
    high_pos[2] = pos_drone[2];//？too large ,we can change it to the current height
    while(abs(pos_drone[2] - current_z /2) > 0.15)
    {
        if(state_drone.armed)
        {
            Offb_.send_local_pos_setpoint(high_pos);
            if(high_pos[2] > current_z /2 + 0.1)//0.05
            {
            	high_pos[2] -= change;
            }
        }
        else{
            cout << "无人机已上锁" << endl;
        }
        ros::spinOnce();
        rate.sleep();
    }
    cout << "已经到达改变的期望高度" << endl;
}

void fly_change_stay(int i,double desire_z)//下降一半高度再次检测---->0.5m高度的地方进行检测，是否能够检测到完整的圆，弧度
{
	Eigen::Vector3d high_pos;
	OffboardControl Offb_;
    ros::Rate rate(20.0);
	ros::Time last_request = ros::Time::now();
    high_pos[0] = fly_point[i+1][0];
    high_pos[1] = fly_point[i+1][1];
    high_pos[2] = pos_drone[2];
    cout << "已经到达改变的期望高度,将保持3s" << endl;
	while(ros::Time::now() - last_request < ros::Duration(5.0))
        {
        	ros::spinOnce();
        	rate.sleep();
		ROS_INFO("The change of circle center is x:%0.2f y:%0.2f", x_change, y_change);//在纠偏过程中打印修正后的圆心数据
        	Offb_.send_local_pos_setpoint(high_pos);        
	}
}

int is_ready(int i)//读取圆心坐标文件并进行误差分析
{
    OffboardControl Offb_;
    ros::Rate rate(20.0);
    double current_z;
    if (i == 0)
    {
        current_z = 1.0;
    }
    else
    {
        current_z = desire_z;
    }
    //根据获取的圆心坐标进行误差分析
    switch(i)
    {
	case 0:
    	fly_point[i+1][0]=fly_point[i+1][0]-x_change+0.04;
        fly_point[i+1][1]=fly_point[i+1][1]-y_change+0.02;
	break;
	case 1:
    	fly_point[i+1][0]=fly_point[i+1][0]-x_change-0.02;
        fly_point[i+1][1]=fly_point[i+1][1]-y_change-0.02;
	break;
	case 2:
    	fly_point[i+1][0]=fly_point[i+1][0]-x_change-0.02;
        fly_point[i+1][1]=fly_point[i+1][1]-y_change+0.04;
	break;
	default:
	ROS_INFO("The change of circle center is x:%0.2f y:%0.2f", x_square_change, y_square_change);    	
	fly_point[i+1][0]=fly_point[i+1][0]-x_square_change;
        fly_point[i+1][1]=fly_point[i+1][1]-y_square_change;
	break;
    }
    printf("%lf\n",fly_point[i+1][0]);
    printf("%lf\n",fly_point[i+1][1]);
    cout<<"误差分析结束"<<endl;
    //调整落地点（作用在landing函数内）
    end_point[0] = fly_point[i+1][0];
    end_point[1] = fly_point[i+1][1];
    end_point[2] = current_z/2;
    
}

void landing()
{
    OffboardControl Offb_;
    ros::Rate rate(20.0);
    Eigen::Vector3d land_pos = end_point;
    cout << "准备降落" << endl;
    while(abs(vel_drone[2]) >0.1 || pos_drone[2] > 0.1)
    {
        Offb_.send_local_pos_setpoint(land_pos);
        if(land_pos[2] > -0.5){
            land_pos[2] -= change;
        }
        else{
            land_pos[2] = -0.5;
        }
        ros::spinOnce();
        rate.sleep();
    }
    cout << "降落成功，怠速旋转"  <<  endl;
}

void unload(int i)
{
    Eigen::Vector3d land_pos;
    ros::Rate rate(20.0);
    while(pos_drone[2] > 0.2)
    {
        ros::spinOnce();
        rate.sleep();
    }
    land_pos[0] = pos_drone[0];
    land_pos[1] = pos_drone[1];
    land_pos[2] = -0.5;
    OffboardControl Offb_;
    ros::Time last_request = ros::Time::now();
    while(ros::Time::now() - last_request < ros::Duration(3.0))
    {
        ros::spinOnce();
        rate.sleep();
        Offb_.send_pos_setpoint(land_pos, 0);
    }
    Offb_.send_serial_num(i);
    last_request = ros::Time::now();
     while(ros::Time::now() - last_request < ros::Duration(2.0))
    {
        ros::spinOnce();
        rate.sleep();
        Offb_.send_pos_setpoint(land_pos, 0);
    }
    cout << "投放完毕" << endl;
}
int main(int argc, char** argv)
{
    ros::init(argc, argv, "node_flyput_node");
    ros::NodeHandle nh;
    ros::ServiceClient arming_client = nh.serviceClient<mavros_msgs::CommandBool>     //定义服务，用来解锁无人机
            ("mavros/cmd/arming");
    ros::ServiceClient set_mode_client = nh.serviceClient<mavros_msgs::SetMode>       //定义服务，用来改变无人机的模式
            ("mavros/set_mode");
    ros::Subscriber    position_sub = nh.subscribe<geometry_msgs::PoseStamped>
            ("/mavros/local_position/pose", 10, pos_cb);
    ros::Subscriber    velocity_sub = nh.subscribe<geometry_msgs::TwistStamped>
            ("/mavros/local_position/velocity_local", 10, vel_cb);
    ros::Subscriber    state_sub = nh.subscribe<mavros_msgs::State>
            ("/mavros/state", 10, state_cb);
    ros::Subscriber    center_sub = nh.subscribe<offb::Circle>
            ("/circle_center", 10, circle_change);
    ros::Subscriber    square_sub = nh.subscribe<offb::Circle>
            ("/square_center", 10, square_change);
    ros::Rate rate(20.0);
    mavros_msgs::SetMode offb_set_mode;     //定义改变模式的变量
    mavros_msgs::CommandBool arm_cmd;     //定义解锁飞机的变量
    offb_set_mode.request.custom_mode = "AUTO.LAND";     //更改飞行模式为手动
    arm_cmd.request.value = false;      //对飞机上锁
    OffboardControl Offb_;
    nh.getParam("node_flyput_node/desire_z", desire_z);
    nh.getParam("node_flyput_node/change", change);  
    //ros::param::get("~desire_z", desire_z);
    //ros::param::get("~change", change);
    while(!state_drone.connected)
    {
        ros::spinOnce();
        rate.sleep();
    }
    cout << "无人机的巡航高度是：" << desire_z << endl;
    num_fly = 4;
    fly_point[1][0] = 2.0;
    fly_point[1][1] = 0;
    fly_point[1][2] = 1.0;
    fly_point[2][0] = 0;
    fly_point[2][1] = -2.0;
    fly_point[2][2] = desire_z;
    fly_point[3][0] = 2.0;
    fly_point[3][1] = -2.0;
    fly_point[3][2] = desire_z;
    fly_point[4][0] = 0.0;
    fly_point[4][1] = -0.0;
    fly_point[4][2] = desire_z;
    fly_point[0][2] = 1.0;//刚改完点位
    fly_point[num_fly + 1][2] = desire_z;
    cout << "等待OFFBOARD模式以及解锁飞机" << endl;
    while(state_drone.mode != "OFFBOARD" || !state_drone.armed)
    {
        ros::spinOnce();
        rate.sleep();
    }
    for(int i = 0; i < num_fly ; i++)
    {
        start_point[0] = fly_point[i][0];
        start_point[1] = fly_point[i][1];
        start_point[2] = fly_point[i][2];
        end_point[0] = fly_point[i + 1][0];
        end_point[1] = fly_point[i + 1][1];
        end_point[2] = fly_point[i + 1][2];
        next_point[0] = start_point[0];
        next_point[1] = start_point[1];
        next_point[2] = start_point[2];
        fly_high(i, desire_z);
        fly_to(i);
        fly_stay(i,desire_z);
	fly_change(i,desire_z);
        fly_change_stay(i,desire_z);
        is_ready(i);
        landing();
        unload(i + 1);
        cout << "第" << i + 1 <<"个点的任务已经完成"  << endl;
    }
    cout << "所有任务点飞行结束" << endl;
    while(state_drone.mode != "AUTO.LAND"){
        offb_set_mode.request.custom_mode = "AUTO.LAND";
        set_mode_client.call(offb_set_mode);    
        ros::spinOnce();
        rate.sleep();
    }
    cout << "已经成功切换到AUTO.LAND模式" << endl;
    ros::Time land_time = ros::Time::now();
    while(state_drone.armed)
    {
        if(ros::Time::now() - land_time > ros::Duration(2.0)){
            arming_client.call(arm_cmd);
        }
        ros::spinOnce();
        rate.sleep();
    }
    cout << "无人机成功上锁" << endl;
    return 0;
}
