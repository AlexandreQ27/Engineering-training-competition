#!/usr/bin/python
# -*- coding: UTF-8 -*-
"""
This program is demonstration for face and object detection using haar-like features.
The program finds faces in a camera image or video stream and displays a red box around them.

Original C implementation by:  ?
Python implementation by: Roman Stanchak, James Bowman
Updated: Copyright (c) 2016, Tal Regev.
"""
import sys
import os
#from optparse import OptionParser #选项处理模块
import rospy
from sensor_msgs.msg import Image
from offb.msg import Circle #自定义圆心坐标信息
from cv_bridge import CvBridge, CvBridgeError
import cv2
import numpy as np
import time

fx =4.476#通过相机标定求得的焦距fx
fy =5.96#通过相机标定求得的焦距fy
x_size =960#x方向像素
y_size =540#y方向像素
sensor_x =3.2#传感器宽度
sensor_y =2.4#传感器高度

if __name__ == '__main__':
    bridge = CvBridge()
    def len2(x1,y1,x2,y2):
        return (int(x1)-int(x2))*(int(x1)-int(x2))+(int(y1)-int(y2))*(int(y1)-int(y2))

    def detect_and_draw(imgmsg):
        try:
            imag = bridge.imgmsg_to_cv2(imgmsg, "bgr8")
        except CvBridgeError as e:
            print e
    	imag1 = imag.copy()
    	gray = cv2.cvtColor(imag, cv2.COLOR_BGR2GRAY)
    	circles = cv2.HoughCircles(gray, cv2.HOUGH_GRADIENT, 1, 100, param1=100, param2=100, minRadius=2 ,maxRadius=800)
	if circles is not None:
    	    x0 = int(circles[0][0][0])
    	    y0 = int(circles[0][0][1])
    	    r0 = 0
        #cv2.circle(img, center, radius, color[, thickness[, lineType[, shift]]])
        #thickness：圆形轮廓的粗细（如果为正）。负厚度表示要绘制实心圆。lineType： 圆边界的类型。shift：中心坐标和半径值中的小数位数。
    	    cv2.circle(imag1, (x0, y0), 2, (169, 30, 150),2,-1)
    	# 标定同心圆圆心的位置
            cv2.imshow('result', imag1)
        #圆心消息设定
            error_x=480-x0
            error_y=270-y0
            a=error_y*sensor_x*1.0/(x_size*fx)#x偏差
            b=error_x*sensor_y*1.0/(y_size*fy)#y偏差
	    x_change = a
            y_change = b
            circle_msg = Circle()
            circle_msg.circle_x = x_change
            circle_msg.circle_y = y_change
            cycle_pub.publish(circle_msg)
            rospy.loginfo("Publish circle x: %0.2f,y:%0.2f",circle_msg.circle_x,circle_msg.circle_y)
	    cv2.waitKey(10)
            rate.sleep()

    rospy.init_node('cycle_node')
    rospy.loginfo("Starting new_target node")
    rate = rospy.Rate(10)#设置循环频率为每秒十次
    cycle_pub = rospy.Publisher("/circle_center", Circle, queue_size=10) #缓冲队列为10
    rospy.Subscriber("/camera/rgb/image_raw", Image, detect_and_draw) 
    rospy.spin()
