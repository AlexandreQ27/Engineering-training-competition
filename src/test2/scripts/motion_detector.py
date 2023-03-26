#!/usr/bin/env python
# -*- coding: utf-8 -*-
import rospy
import cv2
import numpy as np
from sensor_msgs.msg import Image, RegionOfInterest
from cv_bridge import CvBridge, CvBridgeError
import time
class motionDetector:
    def __init__(self):
        rospy.on_shutdown(self.cleanup);
 
        # 创建cv_bridge
        self.bridge = CvBridge()
        self.image_pub = rospy.Publisher("cv_bridge_image", Image, queue_size=1)
 
        # 设置参数：最小区域、阈值
        self.minArea   = rospy.get_param("~minArea",   500)
        self.threshold = rospy.get_param("~threshold", 25)
 
        self.firstFrame = None
        self.text = "Unoccupied"
 
        # 初始化订阅rgb格式图像数据的订阅者，此处图像topic的话题名可以在launch文件中重映射
        self.image_sub = rospy.Subscriber("input_rgb_image", Image, self.image_callback, queue_size=1)
    # 定义函数，求两点之间的距离的平方
    def len2(x1,y1,x2,y2):
        return (int(x1)-int(x2))*(int(x1)-int(x2))+(int(y1)-int(y2))*(int(y1)-int(y2))
    def image_callback(self, data):
        # 使用cv_bridge将ROS的图像数据转换成OpenCV的图像格式
        try:
            cv_image = self.bridge.imgmsg_to_cv2(data, "bgr8")     
            imag = np.array(cv_image, dtype=np.uint8)
        except CvBridgeError, e:
            print e
    	num = 20  # 定义数组大小
    	all = np.zeros([num,3],dtype=np.uint32)
    	# 创建一个二维数组用来存储检测到的圆的数据（最多存储num组数据)
    	imag1 = imag.copy()
    	blur = cv2.medianBlur(imag, 5)
    	gray = cv2.cvtColor(blur, cv2.COLOR_BGR2GRAY)
    	circles = cv2.HoughCircles(gray, cv2.HOUGH_GRADIENT, 1, 100, param1=100, param2=100, minRadius=2
                          , maxRadius=800)

    	x0 = int(circles[0][0][0])
    	y0 = int(circles[0][0][1])
    	r0 = 0
    	all[0][0] = x0
    	all[0][1] = y0
    	cv2.circle(imag1, (x0, y0), 2, (0, 0, 255), 2, -1)
    	# 标定同心圆圆心的位置
    	step1 = 20
    	step2 = 15
    	# 设置内外矩形的步进速度
    	thres = 50
    	# 设置检测阈值
    	blank = np.ones_like(gray)
    	blank = blank * 255
    	# 创建一个白色的面板用来承载裁剪后的图像
    	height, width, _ = imag.shape
    	r1 = r0 + step1
    	r2 = r0 + step2
    	i = 1
        while x0-r1>0 and x0+r1<width and y0-r1>0 and y0+r1<height:
            one = np.ones_like(gray)
            zero = np.zeros_like(gray)
            # print('r1:',r1,' r2:',r2)
            one[x0 - r1:x0 + r1,y0 - r1:y0 + r1] = 0
            one[x0 - r2 + step2:x0 + r2 - step2,y0 - r2 + step2:y0 + r2 - step2] = 1
            zero[x0 - r1:x0 + r1,y0 - r1:y0 + r1] = 1
            zero[x0 - r2 + step2:x0 + r2 - step2,y0 - r2 + step2:y0 + r2 - step2] = 0
            pic = one * blank + zero * gray
            cv2.imshow('pic',pic)
            circles = cv2.HoughCircles(pic, cv2.HOUGH_GRADIENT, 1, 100, param1=150, param2=100, minRadius=2, maxRadius=800)
            if circles is not None:
                for circle in circles[0]:
                    x = int(circle[0])
                    y = int(circle[1])
                    rr = int(circle[2])
                    if len2(x,y,x0,y0) < thres :
                        all[i][0] = x
                        all[i][1] = y
                        all[i][2] = rr
                        i += 1
            r1 = r1 + step1
            r2 = r2 + step2
         # 对储存有检测圆的数据的二维数组进行筛选，标记检测到的重复圆数据
        for i in range(1,num):
    	    if all[i][2] != 0:
        	for j in range(i+1,num):
            	    if abs(int(all[j][2])-int(all[i][2]))<8:
                	if len2(all[i][0],all[i][1],all[0][0],all[0][1]) <= len2(all[j][0],all[j][1],all[0][0],all[0][1]):
                            all[j][2] = 0
                        else:
                            all[i][2] = 0
        # 画圆
        for circle in all:
            if circle[2] != 0:
                x = circle[0]
                y = circle[1]
                rr = circle[2]
                cv2.circle(imag1, (x, y), rr, (0, 0, 255), 2, 1)
        cv2.imshow('result', imag1)
        self.text = "Occupied"
 
        # 在输出画面上打当前状态和时间戳信息
        cv2.putText(frame, "Status: {}".format(self.text), (10, 20),
        cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 0, 255), 2)
 
        # 将识别后的图像转换成ROS消息并发布
        self.image_pub.publish(self.bridge.cv2_to_imgmsg(frame, "bgr8"))
 
    def cleanup(self):
        print "Shutting down vision node."
        cv2.destroyAllWindows()
 
if __name__ == '__main__':
    try:
        # 初始化ros节点
        rospy.init_node("motion_detector")
        rospy.loginfo("motion_detector node is started...")
        rospy.loginfo("Please subscribe the ROS image.")
        motionDetector()
        rospy.spin()
    except KeyboardInterrupt:
        print "Shutting down motion detector node."
        cv2.destroyAllWindows()
