;; Auto-generated. Do not edit!


(when (boundp 'offb_msgs::MultiDetectionInfo)
  (if (not (find-package "OFFB_MSGS"))
    (make-package "OFFB_MSGS"))
  (shadow 'MultiDetectionInfo (find-package "OFFB_MSGS")))
(unless (find-package "OFFB_MSGS::MULTIDETECTIONINFO")
  (make-package "OFFB_MSGS::MULTIDETECTIONINFO"))

(in-package "ROS")
;;//! \htmlinclude MultiDetectionInfo.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass offb_msgs::MultiDetectionInfo
  :super ros::object
  :slots (_header _num_objs _detection_infos ))

(defmethod offb_msgs::MultiDetectionInfo
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:num_objs __num_objs) 0)
    ((:detection_infos __detection_infos) (let (r) (dotimes (i 0) (push (instance offb_msgs::DetectionInfo :init) r)) r))
    )
   (send-super :init)
   (setq _header __header)
   (setq _num_objs (round __num_objs))
   (setq _detection_infos __detection_infos)
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:num_objs
   (&optional __num_objs)
   (if __num_objs (setq _num_objs __num_objs)) _num_objs)
  (:detection_infos
   (&rest __detection_infos)
   (if (keywordp (car __detection_infos))
       (send* _detection_infos __detection_infos)
     (progn
       (if __detection_infos (setq _detection_infos (car __detection_infos)))
       _detection_infos)))
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; int32 _num_objs
    4
    ;; offb_msgs/DetectionInfo[] _detection_infos
    (apply #'+ (send-all _detection_infos :serialization-length)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; int32 _num_objs
       (write-long _num_objs s)
     ;; offb_msgs/DetectionInfo[] _detection_infos
     (write-long (length _detection_infos) s)
     (dolist (elem _detection_infos)
       (send elem :serialize s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; int32 _num_objs
     (setq _num_objs (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; offb_msgs/DetectionInfo[] _detection_infos
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _detection_infos (let (r) (dotimes (i n) (push (instance offb_msgs::DetectionInfo :init) r)) r))
     (dolist (elem- _detection_infos)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;;
   self)
  )

(setf (get offb_msgs::MultiDetectionInfo :md5sum-) "bc6aead57058b498c6b06cb8ab93293c")
(setf (get offb_msgs::MultiDetectionInfo :datatype-) "offb_msgs/MultiDetectionInfo")
(setf (get offb_msgs::MultiDetectionInfo :definition-)
      "Header header

## 检测到的目标数量
int32 num_objs

## 每个目标的检测结果
DetectionInfo[] detection_infos

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
string frame_id

================================================================================
MSG: offb_msgs/DetectionInfo
std_msgs/Header header

## 目标类别名称
string object_name

## 是否检测到目标
bool detected

## 0表示相机坐标系, 1表示机体坐标系, 2表示惯性坐标系
int32 frame

## 目标位置[相机系下：右方x为正，下方y为正，前方z为正]
float32[3] position

## 目标姿态-欧拉角-(z,y,x)
float32[3] attitude

## 目标姿态-四元数-(qx,qy,qz,qw)
float32[4] attitude_q

## 视线角度[相机系下：右方x角度为正，下方y角度为正]
float32[2] sight_angle

## 偏航角误差
float32 yaw_error

## 类别
int32 category


")



(provide :offb_msgs/MultiDetectionInfo "bc6aead57058b498c6b06cb8ab93293c")


