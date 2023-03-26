#!/usr/bin/env python
import cv2 as cv
import rospy
import sensor_msgs.msg
from cv_bridge import CvBridge

rospy.init_node("cam_node")
video = cv.VideoCapture(0)
cv.namedWindow('frame', cv.WINDOW_AUTOSIZE)

img_pub = rospy.Publisher('/camera/rgb/image_raw', sensor_msgs.msg.Image, queue_size=10)
bridge = CvBridge()
while video.isOpened():
    ret, frame = video.read()
    if   cv.waitKey(1) == ord('q'):
        break
    #cv.imshow('frame', frame)
    ros_image = bridge.cv2_to_imgmsg(frame, "bgr8")
    img_pub.publish(ros_image)
