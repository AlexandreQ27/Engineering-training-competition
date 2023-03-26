//
// Created by xs on 22-6-24.
//

#include "multi_input.h"

int main(int argc, char** argv)
{
    ros::init(argc, argv, "multi_input_node");
    ros::param::set("rate", 20);
    ros::param::get("rate", rate);
    ros::NodeHandle nh;
    ros::Rate loop(rate);
    multi_input multiInput(nh);

    while(ros::ok())
    {
        while(true)
        {
            bool result = multiInput.Init();
            if(result)
            {
                break;
            }
            loop.sleep();
            ros::spinOnce();
        }
        printf("初始化成功\n");
        if(If_continue())
        {
            print_input_tips();
        }
        else
        {
            ros::Time time_temp = ros::Time::now();
            printf("程序结束，请切换至LAND模式!\n");
            while(ros::Time::now() - time_temp < ros::Duration(3.0))
            {
                loop.sleep();
                ros::spinOnce();
            }
            return 0;
        }
        printf("等待切换到OFFBOARD模式并解锁~~~\n");
        while(!multiInput.Ok_for_fly())
        {
            loop.sleep();
            ros::spinOnce();
        }
        geometry_msgs::Pose tar_pose;
        for(int i = 1; i <= fly_nums && i <= 100; i++)
        {
            tar_pose.position.x = fly_points[i][0];
            tar_pose.position.y = fly_points[i][1];
            tar_pose.position.z = fly_points[i][2];
            while(!multiInput.Fly_to(tar_pose)) // 到达返回true
            {
                loop.sleep();
                ros::spinOnce();
            }
        }
        printf("此次飞行任务结束\n");
    }
    return 0;
}

void print_input_tips()
{
    printf("请输入需要飞行的航点数:");
    cin >> fly_nums;
    if(fly_nums <= 0)
    {
        printf("输入的数量有误，请重新输入");
        cin >> fly_nums;
    }
    for(int i = 1; i <= fly_nums; i++)
    {
        printf("请输入第%d个航点:", i);
        cin >> fly_points[i][0] >> fly_points[i][1] >> fly_points[i][2];
    }
}

bool If_continue()
{
    char flag;
    printf("是否需要进行飞行程序[y/n]:");
    cin >> flag;
    if(flag == 'y' || flag == 'Y')
    {
        return true;
    }
    else
    {
        return false;
    }
}
