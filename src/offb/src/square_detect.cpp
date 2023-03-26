#include "ros/ros.h"
#include "sensor_msgs/image_encodings.h"
#include <cv_bridge/cv_bridge.h>
#include <opencv2/opencv.hpp>
#include <image_transport/image_transport.h> 
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include "offb/Circle.h"
#include <geometry_msgs/TwistStamped.h>
#include <std_msgs/UInt16.h>
#include "offboard_control.h"
using namespace cv;

ros::Publisher square_pub;
ros::Subscriber position_sub;
offb::Circle square;

double fx = 4.476;//ͨ������궨��õĽ���fx
double fy = 5.96;//ͨ������궨��õĽ���fy
double x_size = 960;//x��������
double y_size = 540;//y��������
double sensor_x = 3.2;//���������
double sensor_y = 2.4;//�������߶�
Eigen::Vector3d pos_drone;
void pos_cb(const geometry_msgs::PoseStamped::ConstPtr &msg)
        {
            pos_drone[0] = msg->pose.position.x;
            pos_drone[1] = msg->pose.position.y;
            pos_drone[2] = msg->pose.position.z;
        }


void process_square(const sensor_msgs::ImageConstPtr& msg) {

    cv::Point center;
    cv_bridge::CvImageConstPtr ptr;
    ptr = cv_bridge::toCvShare(msg, sensor_msgs::image_encodings::BGR8);
		
    cv::Mat change = ptr->image;;
    auto filtered = cv::Mat();
    cv::bilateralFilter(change, filtered, 3, 1024, 1024);
    //cv::imshow("filtered", filtered);

    // Canny ��Ե���
    auto edge_detected = cv::Mat();
    cv::Canny(filtered, edge_detected, 24, 144);

    // ��-������, �ںϱ�Ե������������
    //�գ������ͣ��ٸ�ʴ������ڵ�
    //�����ȸ�ʴ�������ͣ���������
    auto closed = cv::Mat();
    cv::morphologyEx(edge_detected, closed, cv::MORPH_CLOSE,
    cv::getStructuringElement(cv::MORPH_RECT, cv::Size(7, 7)));
    auto close_opened = cv::Mat();
    cv::morphologyEx(closed, close_opened, cv::MORPH_OPEN,
    cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3)));
    //cv::imshow("close_opened", close_opened);
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(close_opened, contours, CV_RETR_LIST, CV_CHAIN_APPROX_NONE);
    cv::Mat contour_image(close_opened.size(), CV_8UC3, cv::Scalar(0, 0, 0));
    for (size_t idx = 0; idx < contours.size(); idx++) {
        auto area = cv::contourArea(contours[idx]);
        auto circumference = cv::arcLength(contours[idx], true);
	//�������������ܳ��������ϵȷ������
        if (area > 1024 && fabs(circumference * circumference /area - 16) < 2) {
            cv::drawContours(contour_image, contours, idx, cv::Scalar(255, 255, 255));
	    //���ͼ��ľ�
	    cv::Moments M = cv::moments(contours[idx]);
	    //���ͼ�������
            center = { M.m10 / M.m00, M.m01 / M.m00 };
	    circle(contour_image, center, 2, cv::Scalar(255, 255, 255),2);
            //cv::circle(change, min_radius_center, 4, cv::Scalar(192, 16, 192), 4);
	    //cv::imshow("contour_image", contour_image);
        }
    }
    int error_x = 480 - center.x;
    int error_y = 270 - center.y;
    double a = error_y * sensor_x * pos_drone[2] / (x_size * fx);//xƫ��
    double b = error_x * sensor_y * pos_drone[2]/ (y_size * fy);//yƫ��
    square.circle_x = a;
    square.circle_y = b;
    if((center.x!=0)&&(center.y!=0)){
    	square_pub.publish(square);
    	ROS_INFO("The square change is x:%0.2f y:%0.2f", square.circle_x, square.circle_y);
    }
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "square_detect_node");
    ros::NodeHandle n;
    square_pub = n.advertise<offb::Circle>("/square_center",10);
    position_sub = n.subscribe<geometry_msgs::PoseStamped>("/mavros/local_position/pose", 10, pos_cb);
    ros::Subscriber sub = n.subscribe("/camera/rgb/image_raw", 1, process_square);
    ros::Rate loop_rate(1);
    ros::spin();
    cv::destroyAllWindows();
}
