#! /usr/bin/python3
import cv2 as cv
import os
import numpy as np
# ros库的调用
import rospy
from std_msgs.msg import String
from geometry_msgs.msg import Pose
from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError
# paddle的库，网络结构
import torch
from PIL import Image
from matplotlib import pyplot as plt
from numpy.random import choice
from torchvision import datasets, transforms

device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')
model = torch.load('model_params/LeNet5.pth', map_location=device)  # 加载模型
model = model.to(device)
model.eval()  # 把模型转为test模式


def nothing(x):
    pass


def single_predict(img):
    """
    单张图片检测
    :param img_path:图片路径
    :return:label
    """
    img_show = img.copy()
    trans = transforms.Compose(
        [
            transforms.Resize((32, 32)),
            transforms.ToTensor(),
            transforms.Normalize((0.1307,), (0.3081,))
        ])
    img = cv.cvtColor(img, cv.COLOR_BGR2GRAY)  # 图片转为灰度图
    ret, img = cv.threshold(img, 110, 255, cv.THRESH_BINARY)
    img = img / 255  # opencv读取的灰度图片是0-255，映射到0-1之间
    img = 1 - img  # 反相
    img = Image.fromarray(img)  # 这里ndarray_image为原来的numpy数组类型的输入

    img = trans(img)
    img = img.to(device)
    img = img.unsqueeze(0)  # [1，1，28，28]
    with torch.no_grad():
        _, probs = model(img)
    return f'{torch.argmax(probs)}'

class Detector:

    def __init__(self):
        self.detect_type = None
        self.pict = None
        self.flag = 0
        self.model = None
        self.QRdetector = cv.QRCodeDetector()

    def detect(self, detect_type, pict):
        index = -1
        assert detect_type in ['h_mark', 'number', 'QRcode'], "错误的检测参数{0}".format(detect_type)
        self.detect_type = detect_type
        self.pict = pict
        res = self._pre_process()
        if detect_type == 'h_mark':
            _pict = pict.copy()
            _pict = cv.medianBlur(_pict, 5)
            _pict = cv.cvtColor(_pict, cv.COLOR_RGB2GRAY)
            # para_thresh = cv.getTrackbarPos('para_thresh', 'contour_circle')
            ret, _pict = cv.threshold(_pict, 75, 255, cv.THRESH_BINARY)
            contours, hierarchy = cv.findContours(_pict, cv.RETR_TREE, cv.CHAIN_APPROX_SIMPLE)
            if len(contours) > 50:
                num = 50
            else:
                num = len(contours)
            # 排除掉比较小的轮廓
            filtered_contours = []
            contours_radius = []
            circle_center = []
            for i in range(num):
                area = cv.contourArea(contours[i])
                if area < 2000:
                    continue
                else:
                    (x,y),radius = cv.minEnclosingCircle(contours[i])
                    center = (int(x),int(y))
                    radius = int(radius)
                    cv.circle(_pict, center, radius,(0,255,0),4)
                    if area / (3.1415 * radius *radius) > 0.8:
                        filtered_contours.append(contours[i])
                        contours_radius.append(radius)
                        circle_center.append(center)
            if len(filtered_contours) == 2:
                _pict = pict[circle_center[0][1] - contours_radius[0] : circle_center[0][1] + contours_radius[0],
                                circle_center[0][0] - contours_radius[0] : circle_center[0][0] + contours_radius[0]]
                return _pict, circle_center[0]
            else:
                return _pict, None

        elif detect_type == 'number':
            # 用于调试，寻找比较好的阈值参数
            # canny_threshold1 = cv.getTrackbarPos('canny_threshold1', 'result_frame')
            # canny_threshold2 = cv.getTrackbarPos('canny_threshold2', 'result_frame')
            after = cv.cvtColor(pict, cv.COLOR_RGB2GRAY)
            after = cv.medianBlur(after, 5)
            ret_threshold, after = cv.threshold(after, 110, 255, cv.THRESH_BINARY)
            # edges = cv.Canny(after, canny_1, canny_2)

            contours, hierarchy = cv.findContours(after, cv.RETR_TREE, cv.CHAIN_APPROX_SIMPLE)
            if len(contours) > 50:
                num = 50
            else:
                num = len(contours)

            filtered_contours = []
            for i in range(num):
                area = cv.contourArea(contours[i])
                if area < 2500:
                    continue
                elif area > 500 * 500:
                    continue
                else:
                    x, y, w, h = cv.boundingRect(contours[i])
                    # 排除掉不太像矩形的轮廓
                    if area / (w * h) < 0.9:
                        filtered_contours.append(contours[i])
                        
            max_index = 0
            max_area = 0
            for i in range(len(filtered_contours)):
                x, y, w, h = cv.boundingRect(filtered_contours[i])
                if w * h > max_area:
                    max_area = w * h
                    max_index = i
                cv.rectangle(after, (x, y), (x + w, y + h), (64, 64, 64), 2)
            if len(filtered_contours) > 0:
                x, y, w, h = cv.boundingRect(filtered_contours[max_index])
                new_y_min = y - 0.5 * h
                new_y_max = y + 1.5 * h
                new_x_min = x - 0.2 * w
                new_x_max = x + 1.2 * w
                # if new_y_min < 0:
                #     new_y_min = 0
                # if new_y_min > 700:
                #     new_y_min = 0
                # if new_y_max > 720:
                #     new_y_max = 700

                # if new_x_max > 1280:
                #     new_x_max = 1200
                # if new_x_min < 0:
                #     new_x_min = 0
                # if new_x_min > 1000:
                #     new_x_min = 1000

                cutted = np.zeros((int(new_y_max - new_y_min), int (new_x_max- new_x_min), 3), np.uint8)
                cutted[int(0.5 * h) : int(1.5 * h), int(0.2 * w): int(1.2 * w)] = pict[y : y + h, x: x + w]
                index = single_predict(cutted)
                return cutted, index
            else:
                return None, -1

        # 调用opencv自带的QRdetector库
        elif detect_type == 'QRcode':
            val, pts, st_code = self.QRdetector.detectAndDecode(pict)  # 识别二维码
            if pts is None:
                result = ''
            else:
                if val == 'left':
                    result = 'left'
                elif val == 'right':
                    result = 'right'
                else:
                    result = ''
            return result

    def _pre_process(self):
        pre_processed = None
        if self.detect_type == 'QRcode':
            pre_processed = self.pict
        elif self.detect_type == 'number':
            pre_processed = self.pict
        elif self.detect_type == 'h_mark':
            pre_processed = cv.medianBlur(self.pict, 5)
            pre_processed = cv.cvtColor(pre_processed, cv.COLOR_RGB2GRAY)

        return pre_processed

    def _pub_result(self):
        pass


number_pub = rospy.Publisher('/number_info', String, queue_size=5)
QRcode_pub = rospy.Publisher('/QR_info', String, queue_size=5)
H_Mark_pub = rospy.Publisher('/H_info', Pose, queue_size=5)

detector = Detector()
bridge = CvBridge()
number_info = String()
QR_info = String()
H_info = Pose()
count = 0


def image_callback(image_data):
    global count
    count = count + 1
    if count % 400 == 0:
        print('working···')
    if count % 10 != 0:
        return
    frame = bridge.imgmsg_to_cv2(image_data, "bgr8")
    if cv.waitKey(1):
        cv.imshow("img", frame)
    result_frame, index = detector.detect('number', frame)
    QR_result = detector.detect('QRcode', frame)
    _, center = detector.detect('h_mark', frame)
    if index != -1:
        number_info.data = str(index)
        number_pub.publish(number_info)
    if QR_result != '':
        QR_info.data = QR_result
        QRcode_pub.publish(QR_info)
    if H_info != None:
        H_info.position.y = center[0] / 720
        H_info.position.x = center[1] / 1280
        H_Mark_pub.publish(H_info)


if __name__ == '__main__':
    try:
        #  初始化ROS节点以及发布者
        rospy.init_node('Detect', anonymous=True)
        img_sub = rospy.Subscriber("/iris_0/camera/image_raw", Image, image_callback, queue_size=10)
        rospy.spin()
    except RuntimeError:
        pass
