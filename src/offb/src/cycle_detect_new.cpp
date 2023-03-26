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

offb::Circle circle;
ros::Publisher circle_pub;
ros::Subscriber position_sub;
//double desire_z;//���˻���һֱ������߶ȷ���
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

void process_image(const sensor_msgs::ImageConstPtr& msg) {
    
    cv_bridge::CvImageConstPtr ptr;
    ptr = cv_bridge::toCvShare(msg, sensor_msgs::image_encodings::BGR8);

    // ģ���㷨Ԥ����, ȥ���������
    cv::Mat change = ptr->image;
    auto filtered = cv::Mat();
    cv::bilateralFilter(change, filtered, 3, 1024, 1024);
    //cv::imshow("filtered", filtered);

    // Canny ��Ե���
    auto edge_detected = cv::Mat();
    cv::Canny(filtered, edge_detected, 24, 144);
    //cv::imshow("edge_detected", edge_detected);

    // ��-������, �ںϱ�Ե������������
    auto closed = cv::Mat();
    cv::morphologyEx(edge_detected, closed, cv::MORPH_CLOSE,
        cv::getStructuringElement(cv::MORPH_RECT, cv::Size(9, 9)));
    auto close_opened = cv::Mat();
    cv::morphologyEx(closed, close_opened, cv::MORPH_OPEN,
        cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3)));
    //cv::imshow("close_opened", close_opened);

    // ��ȡ������Բ�α�Ե
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(close_opened, contours, CV_RETR_LIST, CV_CHAIN_APPROX_NONE);
    cv::Mat contour_image(close_opened.size(), CV_8UC3, cv::Scalar(0, 0, 0));
    cv::Point min_radius_center;
    double min_radius = 8192;
    for (size_t idx = 0; idx < contours.size(); idx++) {
        // ����Բ��, ��� S = pi * r^2, �ܳ� C = 2 * pi * r.
        // ��ͨ��������ֵ���Բ���ʵ�ֵ pi = C^2 / (4 * S), ������ʵֵ���Ƚ�,
        // ����ɸѡ��Բ�α�Ե.
        auto area = cv::contourArea(contours[idx]);
        auto circumference = cv::arcLength(contours[idx], true);
        if (area > 512 &&
            fabs(circumference * circumference / (4 * area) - M_PI) < 0.4) {
            cv::drawContours(contour_image, contours, idx, cv::Scalar(255, 255, 255));
            // r = 2 * S / C
            auto radius = 2 * area / circumference;
            if (radius < min_radius) {
                cv::Moments M = cv::moments(contours[idx]);
                min_radius_center = { M.m10 / M.m00, M.m01 / M.m00 };
                min_radius = radius;
            }
        }
    }
    // �����ư뾶��С��Բ������
    if (min_radius < 8192)
        cv::circle(contour_image, min_radius_center, 2, cv::Scalar(255, 255, 255),
            2);
    //cv::imshow("contour_image", contour_image);

    // �ں�����Բ�α�Ե
    auto contour_image_closed = cv::Mat();
    cv::morphologyEx(contour_image, contour_image_closed, cv::MORPH_CLOSE,
        cv::getStructuringElement(cv::MORPH_RECT, cv::Size(7, 7)));
    //cv::imshow("contour_image_closed", contour_image_closed);
    cv::circle(change, min_radius_center, 4, cv::Scalar(192, 16, 192), 4);
    int error_x = 480 - min_radius_center.x;
    int error_y = 270 - min_radius_center.y;
    //double a = error_y * sensor_x * 1.0 / (x_size * fx);//xƫ��
    //double b = error_x * sensor_y * 1.0 / (y_size * fy);//yƫ��
    double a = error_y * sensor_x * pos_drone[2] / (x_size * fx);//xƫ��
    double b = error_x * sensor_y * pos_drone[2]/ (y_size * fy);//yƫ��
    circle.circle_x = a;
    circle.circle_y = b;
    if((min_radius_center.x!=0)&&(min_radius_center.y!=0)){
        circle_pub.publish(circle);
    	ROS_INFO("The change is x:%0.2f y:%0.2f", circle.circle_x, circle.circle_y);
    }
    //cv::imshow("csi_camera", change);
    //cv::waitKey(10);
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "cycle_detect_new_node");
    ros::NodeHandle n;
    //n.getParam("node_flyput_node/desire_z", desire_z);
    circle_pub = n.advertise<offb::Circle>("/circle_center",10);
    position_sub = n.subscribe<geometry_msgs::PoseStamped>("/mavros/local_position/pose", 10, pos_cb);
    ros::Subscriber sub = n.subscribe("/camera/rgb/image_raw", 1, process_image);
    ros::Rate loop_rate(1);
    ros::spin();
    cv::destroyAllWindows();
}
