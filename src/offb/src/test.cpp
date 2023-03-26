#include <ros/ros.h>
#include <serial/serial.h>
#include <iostream>
#include <std_msgs/UInt8.h>
using namespace std;
//无符号单字节整型数据,这里代表的是投放的顺序，5没有意义；1，2，3代表1号、2号、3号投放；4代表打开所有舵机；5没有意义，初始化为5；
//uint8_t是C++的数据格式，定义为 typedef unsigned char uint8_t;
uint8_t throw_n = 5; 
//6代表还原所有舵机
uint8_t back = 6; 

//这里serial_port::serial_message是自己定义的msg，代表投放的顺序
void SerialCallback(const std_msgs::UInt8 &msg)  //msg的数据只有一个uint8_t A
{
	throw_n = msg.data;
    if(throw_n > 48)
    {
        throw_n -= 48;
    }
    if(throw_n > 3)
    {
        throw_n = 6;
    }
        //cout有默认的输出数据格式，这里使用了强制类型转换,将其转换为int型
	cout << (int)throw_n << "号投放" << endl;
}
int main(int argc, char** argv)
{
    ros::init(argc, argv, "serial_port");
    //创建句柄（虽然后面没用到这个句柄，但如果不创建，运行时进程会出错）
    ros::NodeHandle n;
    //创建一个serial类，实例化为sp
    serial::Serial sp;
    //创建一个订阅者，订阅的话题类型为 /landing_quadrotor_node/throw_message ，数据缓存区为10个字节，回调函数为 SerialCallback
    ros::Subscriber sub = n.subscribe("/servo",1, &SerialCallback);
  

    //创建timeout
    serial::Timeout to = serial::Timeout::simpleTimeout(100);
    //设置要打开的串口名称
    std::string throw_serial_port;
    int Baudrate;
    //将串口名称定义为throw_serial_port,可以通过launch文件进行更改，默认为/ttyUSB0
    n.param<std::string>("test_node/throw_serial_port",throw_serial_port,"/dev/ttyUSB0");

    //将波特率参数定义为Baudrate，可以通过launch文件进行更改,默认为9600
    n.param<int>("test_node/Baudrate",Baudrate,9600); 

    sp.setPort(throw_serial_port);
    //设置串口通信的波特率
    sp.setBaudrate(Baudrate);
    //串口设置timeout
    sp.setTimeout(to);
 
    try
    {
        //打开串口
        sp.open();
    }
    catch(serial::IOException& e)
    {
        ROS_ERROR_STREAM("Unable to open port.");
        return -1;
    }
    
    //判断串口是否打开成功
    if(sp.isOpen())
    {
	//这里将串口名称和波特率打印出来，在ROS中将launch文件可以修改的参数引出是很好的习惯，因为可以看到是否更改成功，在debug时有很大的作用
        cout << "throw_serial_port:" << throw_serial_port << endl;
	    cout << "Baudrate:" << Baudrate << endl;
    }
    else
    {
        return -1;
    }

    //这里的意思是两个loop_rate.sleep()之间的时间为0.1s，即为10hz
    ros::Rate loop_rate(10); 
    int flag = 0;
    ros::Time last = ros::Time::now();
    int i = 0;
    while(ros::ok())
    {
        switch (throw_n)
        {
        case 1:
            sp.write(&throw_n, 1);
            throw_n = 5;
            break;
        case 2:
            sp.write(&throw_n, 1);
            throw_n = 5;
            break;
        case 3:
            sp.write(&throw_n, 1);
            throw_n = 5;
            break;
        case 6:
            sp.write(&throw_n, 1);
            throw_n = 5;
            break;
        default:
            throw_n = 5;
            break;
        }
        loop_rate.sleep();
        ros::spinOnce();
    }
    
    sp.write(&back,1);
    //当节点关闭，关闭串口
    sp.close();
 
    return 0;
}
