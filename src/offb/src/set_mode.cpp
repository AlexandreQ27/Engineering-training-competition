/***************************************************************************************************************************
* set_mode.cpp
*
* Author: Qyp
*
* Update Time: 2019.3.16
*
* Introduction:  Change mode
***************************************************************************************************************************/

//头文件
#include <ros/ros.h>


#include <iostream>

//话题头文件
#include <mavros_msgs/CommandBool.h>
#include <mavros_msgs/SetMode.h>
#include <mavros_msgs/State.h>


using namespace std;
mavros_msgs::State current_state;                       //无人机当前状态[包含上锁状态 模式] (从飞控中读取)
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>回调函数<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void state_cb(const mavros_msgs::State::ConstPtr& msg)
{
    current_state = *msg;
}


//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>主 函 数<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
int main(int argc, char **argv)
{
    ros::init(argc, argv, "set_mode");
    ros::NodeHandle nh("~");

    // 【订阅】无人机当前状态 - 来自飞控
    //  本话题来自飞控(通过/plugins/sys_status.cpp)
    ros::Subscriber state_sub = nh.subscribe<mavros_msgs::State>("/mavros/state", 10, state_cb);

    // 【服务】修改系统模式
    ros::ServiceClient set_mode_client = nh.serviceClient<mavros_msgs::SetMode>("/mavros/set_mode");

    ros::ServiceClient arming_client = nh.serviceClient<mavros_msgs::CommandBool>("/mavros/cmd/arming");

    mavros_msgs::SetMode mode_cmd;

    mavros_msgs::CommandBool arm_cmd;
    arm_cmd.request.value = true;

    ros::Rate rate(10.0);

    int Num_StateMachine = 0;
    int flag_1;

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>主  循  环<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
    while(ros::ok())
    {
        switch (Num_StateMachine)
        {
            // input
            case 0:
                cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>--------<<<<<<<<<<<<<<<<<<<<<<<<<<< "<< endl;
                cout << "Input the mode:  0 for Arm,1 for TAKEOFF, 2 for OFFBOARD,3 for LAND, 4 for POSCTL,5 for MISSION, 6 for LOITER, 7 for disarm "<<endl;
                cin >> flag_1;

                //1000 降落 也可以指向其他任务
                if (flag_1 == 0)
                {
                    Num_StateMachine = 1;
                    break;
                }
                else if (flag_1 == 1)
                {
                    Num_StateMachine = 2;
                    break;
                }
                else if(flag_1 == 2)
                {
                    Num_StateMachine = 3;
                }//惯性系移动
                else if(flag_1 == 3)
                {
                    Num_StateMachine = 4;
                }
                else if(flag_1 == 4)
                {
                    Num_StateMachine = 5;
                }
                else if(flag_1 == 5)
                {
                    Num_StateMachine = 6;
                }
                else if(flag_1 == 6)
                {
                    Num_StateMachine = 7;
                }
                else if(flag_1 == 7)
                {
                    Num_StateMachine = 8;
                }

                break;

        //Arm
        case 1:
           if(!current_state.armed)
            {
                arm_cmd.request.value = true;
                arming_client.call(arm_cmd);

                cout << "Arming..." <<endl;

            }else
            {
                Num_StateMachine = 0;
                cout << "Arm Susscess!!!" <<endl;
            }
            break;

        //TAKEOFF
        case 2:
            if(current_state.mode != "AUTO.TAKEOFF")
            {
                mode_cmd.request.custom_mode = "AUTO.TAKEOFF";
                set_mode_client.call(mode_cmd);
                cout << "Setting to TAKEOFF Mode..." <<endl;

            }else
            {
                Num_StateMachine = 0;
                cout << "Set to AUTO.TAKEOFF Mode Susscess!!!" <<endl;
            }
            break;

        //OFFBOARD
        case 3:
            if(current_state.mode != "OFFBOARD")
            {
                mode_cmd.request.custom_mode = "OFFBOARD";
                set_mode_client.call(mode_cmd);
                cout << "Setting to OFFBOARD Mode..." <<endl;

            }else
            {
                Num_StateMachine = 0;
                cout << "Set to OFFBOARD Mode Susscess!!!" <<endl;
            }
            break;

        //LAND
        case 4:
            if(current_state.mode != "AUTO.LAND")
            {
                mode_cmd.request.custom_mode = "AUTO.LAND";
                set_mode_client.call(mode_cmd);
                cout << "Setting to LAND Mode..." <<endl;

            }else
            {
                Num_StateMachine = 0;
                cout << "Set to LAND Mode Susscess!!!" <<endl;
            }
            break;

        //POSCTL
        case 5:
            if(current_state.mode != "POSCTL")
            {
                mode_cmd.request.custom_mode = "POSCTL";
                set_mode_client.call(mode_cmd);
                cout << "Setting to POSCTL Mode..." <<endl;

            }else
            {
                Num_StateMachine = 0;
                cout << "Set to POSCTL Mode Susscess!!!" <<endl;
            }
            break;

        //MISSION
        case 6:
            if(current_state.mode != "AUTO.MISSION")
            {
                mode_cmd.request.custom_mode = "AUTO.MISSION";
                set_mode_client.call(mode_cmd);
                cout << "Setting to MISSION Mode..." <<endl;

            }else
            {
                Num_StateMachine = 0;
                cout << "Set to RTL MISSION Susscess!!!" <<endl;
            }
            break;

        case 7:
            if(current_state.mode != "AUTO.LOITER")
            {
                mode_cmd.request.custom_mode = "AUTO.LOITER";
                set_mode_client.call(mode_cmd);
                cout << "Setting to AUTO.LOITER Mode..." <<endl;

            }else
            {
                Num_StateMachine = 0;
                cout << "Set to AUTO.LOITER Mode Susscess!!!" <<endl;
            }
            break;
        
        case 8:
            if(current_state.armed)
            {
                 arm_cmd.request.value = false;
                arming_client.call(arm_cmd);
                cout << "Disarm...." <<endl;

            }else
            {
                Num_StateMachine = 0;
                cout << "Disarm Susscess!!!" <<endl;
            }
            break;
        }

        //执行回调函数
        ros::spinOnce();
        //周期休眠
        rate.sleep();
    }

    return 0;

}
