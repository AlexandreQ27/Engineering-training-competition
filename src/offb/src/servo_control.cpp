#include <ros/ros.h>
#include <std_msgs/UInt8.h>
#include "offboard_control.h"

using namespace std;

int main(int argc, char** argv)
{
    uint8_t num;
    ros::init(argc, argv, "servo_control");
    ros::NodeHandle nh;
    OffboardControl Offb_;
    while(ros::ok())
    {
        switch (num)
        {
        case 0:
            cout << ">>>>>>>>>>>>>>>>>>>-------<<<<<<<<<<<<<<<<<<<<" << endl;
            cout << "input the num: 1 for servo_1, 2 for servo_2, 3 for servo_3, 6 for all servo" << endl;
            cin >> num ;
        case 1:
            Offb_.send_serial_num(num);
            cout << "成功发送指令" << endl;
            num = 0;
            break;
        case 2:
            Offb_.send_serial_num(num);
            cout << "成功发送指令" << endl;
            num = 0;
            break;
        case 3:
            Offb_.send_serial_num(num);
            cout << "成功发送指令" << endl;
            num = 0;
            break;
        case 6:
            Offb_.send_serial_num(num);
            cout << "成功发送指令" << endl;
            num = 0;
            break;
        default:
            num = 0;
            break;
        }
    }
    return 0;
}
