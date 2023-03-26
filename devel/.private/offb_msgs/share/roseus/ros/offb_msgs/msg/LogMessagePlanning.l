;; Auto-generated. Do not edit!


(when (boundp 'offb_msgs::LogMessagePlanning)
  (if (not (find-package "OFFB_MSGS"))
    (make-package "OFFB_MSGS"))
  (shadow 'LogMessagePlanning (find-package "OFFB_MSGS")))
(unless (find-package "OFFB_MSGS::LOGMESSAGEPLANNING")
  (make-package "OFFB_MSGS::LOGMESSAGEPLANNING"))

(in-package "ROS")
;;//! \htmlinclude LogMessagePlanning.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass offb_msgs::LogMessagePlanning
  :super ros::object
  :slots (_header _time _Drone_State _Control_Command _Control_Output _Attitude_Reference ))

(defmethod offb_msgs::LogMessagePlanning
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:time __time) 0.0)
    ((:Drone_State __Drone_State) (instance offb_msgs::DroneState :init))
    ((:Control_Command __Control_Command) (instance offb_msgs::ControlCommand :init))
    ((:Control_Output __Control_Output) (instance offb_msgs::ControlOutput :init))
    ((:Attitude_Reference __Attitude_Reference) (instance offb_msgs::AttitudeReference :init))
    )
   (send-super :init)
   (setq _header __header)
   (setq _time (float __time))
   (setq _Drone_State __Drone_State)
   (setq _Control_Command __Control_Command)
   (setq _Control_Output __Control_Output)
   (setq _Attitude_Reference __Attitude_Reference)
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:time
   (&optional __time)
   (if __time (setq _time __time)) _time)
  (:Drone_State
   (&rest __Drone_State)
   (if (keywordp (car __Drone_State))
       (send* _Drone_State __Drone_State)
     (progn
       (if __Drone_State (setq _Drone_State (car __Drone_State)))
       _Drone_State)))
  (:Control_Command
   (&rest __Control_Command)
   (if (keywordp (car __Control_Command))
       (send* _Control_Command __Control_Command)
     (progn
       (if __Control_Command (setq _Control_Command (car __Control_Command)))
       _Control_Command)))
  (:Control_Output
   (&rest __Control_Output)
   (if (keywordp (car __Control_Output))
       (send* _Control_Output __Control_Output)
     (progn
       (if __Control_Output (setq _Control_Output (car __Control_Output)))
       _Control_Output)))
  (:Attitude_Reference
   (&rest __Attitude_Reference)
   (if (keywordp (car __Attitude_Reference))
       (send* _Attitude_Reference __Attitude_Reference)
     (progn
       (if __Attitude_Reference (setq _Attitude_Reference (car __Attitude_Reference)))
       _Attitude_Reference)))
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; float32 _time
    4
    ;; offb_msgs/DroneState _Drone_State
    (send _Drone_State :serialization-length)
    ;; offb_msgs/ControlCommand _Control_Command
    (send _Control_Command :serialization-length)
    ;; offb_msgs/ControlOutput _Control_Output
    (send _Control_Output :serialization-length)
    ;; offb_msgs/AttitudeReference _Attitude_Reference
    (send _Attitude_Reference :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; float32 _time
       (sys::poke _time (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; offb_msgs/DroneState _Drone_State
       (send _Drone_State :serialize s)
     ;; offb_msgs/ControlCommand _Control_Command
       (send _Control_Command :serialize s)
     ;; offb_msgs/ControlOutput _Control_Output
       (send _Control_Output :serialize s)
     ;; offb_msgs/AttitudeReference _Attitude_Reference
       (send _Attitude_Reference :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; float32 _time
     (setq _time (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; offb_msgs/DroneState _Drone_State
     (send _Drone_State :deserialize buf ptr-) (incf ptr- (send _Drone_State :serialization-length))
   ;; offb_msgs/ControlCommand _Control_Command
     (send _Control_Command :deserialize buf ptr-) (incf ptr- (send _Control_Command :serialization-length))
   ;; offb_msgs/ControlOutput _Control_Output
     (send _Control_Output :deserialize buf ptr-) (incf ptr- (send _Control_Output :serialization-length))
   ;; offb_msgs/AttitudeReference _Attitude_Reference
     (send _Attitude_Reference :deserialize buf ptr-) (incf ptr- (send _Attitude_Reference :serialization-length))
   ;;
   self)
  )

(setf (get offb_msgs::LogMessagePlanning :md5sum-) "2d4ad0bb816c6f3427390d4683b646bf")
(setf (get offb_msgs::LogMessagePlanning :datatype-) "offb_msgs/LogMessagePlanning")
(setf (get offb_msgs::LogMessagePlanning :definition-)
      "std_msgs/Header header

## 用于控制模块的log消息，可自行增加需要记录的话题
float32 time             ## [s]

DroneState Drone_State

ControlCommand Control_Command

ControlOutput Control_Output

AttitudeReference Attitude_Reference






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
MSG: offb_msgs/DroneState
std_msgs/Header header

## 机载电脑是否连接上飞控，true已连接，false则不是
bool connected
## 是否解锁，true为已解锁，false则不是
bool armed
## 是否降落，true为已降落，false则代表在空中
bool landed
## PX4飞控当前飞行模式
string mode

## 系统启动时间
float32 time_from_start             ## [s]

## 无人机状态量：位置、速度、姿态
float32[3] position                 ## [m]
float32  rel_alt                               ## [m] only for outdoor
float32[3] velocity                 ## [m/s]
float32[3] attitude                 ## [rad]
geometry_msgs/Quaternion attitude_q ## 四元数
float32[3] attitude_rate            ## [rad/s]
================================================================================
MSG: geometry_msgs/Quaternion
# This represents an orientation in free space in quaternion form.

float64 x
float64 y
float64 z
float64 w

================================================================================
MSG: offb_msgs/ControlCommand
std_msgs/Header header

## 控制命令的编号 防止接收到错误命令， 编号应该逐次递加
uint32 Command_ID

## 消息来源
string source
## 控制命令的模式 
uint8 Mode
# enum Mode 控制模式枚举
uint8 Idle=0
uint8 Takeoff=1
uint8 Hover=2
uint8 Move=3
uint8 LAND=4
uint8 Disarm=5
uint8 User_Mode1=6
uint8 User_Mode2=7

## 控制参考量 
## 位置参考量：位置、速度、加速度、加加速度、加加加速度
## 角度参考量：偏航角、偏航角速度、偏航角加速度
PositionReference Reference_State

================================================================================
MSG: offb_msgs/PositionReference
std_msgs/Header header

## 位置控制参考量

## 默认为 XYZ位置追踪模式 （sub_mode = 0）； 速度追踪启用时，控制器不考虑位置参考量及位置状态反馈
uint8 Move_mode

uint8 XYZ_POS      = 0  ##0b00
uint8 XY_POS_Z_VEL = 1  ##0b01
uint8 XY_VEL_Z_POS = 2  ##0b10
uint8 XYZ_VEL = 3       ##0b11
uint8 XYZ_ACC = 4
uint8 TRAJECTORY   = 5  

uint8 Move_frame
# 默认情况下均为ENU_FRAME,注意轨迹追踪和XYZ_ACC一定是ENU_FRAME
uint8 ENU_FRAME  = 0
uint8 BODY_FRAME = 1
uint8 MIX_FRAME = 2 ##2020.4.6 临时增加的模式，后期需要统一整合，该模式下，xy采用机体系控制，z采用enu系控制



## 时刻： 用于轨迹追踪
float32 time_from_start          ## [s]

## 参考量：位置、速度、加速度、加加速度、加加加速度
float32[3] position_ref          ## [m]
float32[3] velocity_ref          ## [m/s]
float32[3] acceleration_ref      ## [m/s^2]
## float32[3] jerk_ref              ## [m/s^3]
## float32[3] snap_ref              ## [m/s^4]

## 角度参考量：偏航角、偏航角速度、偏航角加速度
bool Yaw_Rate_Mode                      ## True 代表控制偏航角速率
float32 yaw_ref                  ## [rad]
float32 yaw_rate_ref             ## [rad/s] 
## float32 yaw_acceleration_ref     ## [rad/s] 
================================================================================
MSG: offb_msgs/ControlOutput
std_msgs/Header header

## 位置控制器输出： 期望推力及期望油门
float32[3] Thrust              ## [rad]  
float32[3] Throttle

## NE控制器的中间变量
float32[3] u_l                 ## [0-1] 惯性系下的油门量
float32[3] u_d                 ## [rad]
float32[3] NE                  ## [rad]
================================================================================
MSG: offb_msgs/AttitudeReference
std_msgs/Header header

## 位置控制器输出： 期望油门 + 期望角度
float32[3] throttle_sp                 ## [0-1] 惯性系下的油门量
float32 desired_throttle               ## [0-1] 机体系z轴
float32[3] desired_attitude            ## [rad]
geometry_msgs/Quaternion desired_att_q ## 四元数

")



(provide :offb_msgs/LogMessagePlanning "2d4ad0bb816c6f3427390d4683b646bf")


