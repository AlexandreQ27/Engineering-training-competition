;; Auto-generated. Do not edit!


(when (boundp 'offb_msgs::SwarmCommand)
  (if (not (find-package "OFFB_MSGS"))
    (make-package "OFFB_MSGS"))
  (shadow 'SwarmCommand (find-package "OFFB_MSGS")))
(unless (find-package "OFFB_MSGS::SWARMCOMMAND")
  (make-package "OFFB_MSGS::SWARMCOMMAND"))

(in-package "ROS")
;;//! \htmlinclude SwarmCommand.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(intern "*IDLE*" (find-package "OFFB_MSGS::SWARMCOMMAND"))
(shadow '*IDLE* (find-package "OFFB_MSGS::SWARMCOMMAND"))
(defconstant offb_msgs::SwarmCommand::*IDLE* 0)
(intern "*TAKEOFF*" (find-package "OFFB_MSGS::SWARMCOMMAND"))
(shadow '*TAKEOFF* (find-package "OFFB_MSGS::SWARMCOMMAND"))
(defconstant offb_msgs::SwarmCommand::*TAKEOFF* 1)
(intern "*HOLD*" (find-package "OFFB_MSGS::SWARMCOMMAND"))
(shadow '*HOLD* (find-package "OFFB_MSGS::SWARMCOMMAND"))
(defconstant offb_msgs::SwarmCommand::*HOLD* 2)
(intern "*LAND*" (find-package "OFFB_MSGS::SWARMCOMMAND"))
(shadow '*LAND* (find-package "OFFB_MSGS::SWARMCOMMAND"))
(defconstant offb_msgs::SwarmCommand::*LAND* 3)
(intern "*DISARM*" (find-package "OFFB_MSGS::SWARMCOMMAND"))
(shadow '*DISARM* (find-package "OFFB_MSGS::SWARMCOMMAND"))
(defconstant offb_msgs::SwarmCommand::*DISARM* 4)
(intern "*POSITION_CONTROL*" (find-package "OFFB_MSGS::SWARMCOMMAND"))
(shadow '*POSITION_CONTROL* (find-package "OFFB_MSGS::SWARMCOMMAND"))
(defconstant offb_msgs::SwarmCommand::*POSITION_CONTROL* 5)
(intern "*VELOCITY_CONTROL*" (find-package "OFFB_MSGS::SWARMCOMMAND"))
(shadow '*VELOCITY_CONTROL* (find-package "OFFB_MSGS::SWARMCOMMAND"))
(defconstant offb_msgs::SwarmCommand::*VELOCITY_CONTROL* 6)
(intern "*ACCEL_CONTROL*" (find-package "OFFB_MSGS::SWARMCOMMAND"))
(shadow '*ACCEL_CONTROL* (find-package "OFFB_MSGS::SWARMCOMMAND"))
(defconstant offb_msgs::SwarmCommand::*ACCEL_CONTROL* 7)
(intern "*MOVE*" (find-package "OFFB_MSGS::SWARMCOMMAND"))
(shadow '*MOVE* (find-package "OFFB_MSGS::SWARMCOMMAND"))
(defconstant offb_msgs::SwarmCommand::*MOVE* 8)
(intern "*USER_MODE1*" (find-package "OFFB_MSGS::SWARMCOMMAND"))
(shadow '*USER_MODE1* (find-package "OFFB_MSGS::SWARMCOMMAND"))
(defconstant offb_msgs::SwarmCommand::*USER_MODE1* 9)
(intern "*ONE_COLUMN*" (find-package "OFFB_MSGS::SWARMCOMMAND"))
(shadow '*ONE_COLUMN* (find-package "OFFB_MSGS::SWARMCOMMAND"))
(defconstant offb_msgs::SwarmCommand::*ONE_COLUMN* 0)
(intern "*TRIANGLE*" (find-package "OFFB_MSGS::SWARMCOMMAND"))
(shadow '*TRIANGLE* (find-package "OFFB_MSGS::SWARMCOMMAND"))
(defconstant offb_msgs::SwarmCommand::*TRIANGLE* 1)
(intern "*SQUARE*" (find-package "OFFB_MSGS::SWARMCOMMAND"))
(shadow '*SQUARE* (find-package "OFFB_MSGS::SWARMCOMMAND"))
(defconstant offb_msgs::SwarmCommand::*SQUARE* 2)
(intern "*CIRCULAR*" (find-package "OFFB_MSGS::SWARMCOMMAND"))
(shadow '*CIRCULAR* (find-package "OFFB_MSGS::SWARMCOMMAND"))
(defconstant offb_msgs::SwarmCommand::*CIRCULAR* 3)
(intern "*XYZ_POS*" (find-package "OFFB_MSGS::SWARMCOMMAND"))
(shadow '*XYZ_POS* (find-package "OFFB_MSGS::SWARMCOMMAND"))
(defconstant offb_msgs::SwarmCommand::*XYZ_POS* 0)
(intern "*XY_POS_Z_VEL*" (find-package "OFFB_MSGS::SWARMCOMMAND"))
(shadow '*XY_POS_Z_VEL* (find-package "OFFB_MSGS::SWARMCOMMAND"))
(defconstant offb_msgs::SwarmCommand::*XY_POS_Z_VEL* 1)
(intern "*XY_VEL_Z_POS*" (find-package "OFFB_MSGS::SWARMCOMMAND"))
(shadow '*XY_VEL_Z_POS* (find-package "OFFB_MSGS::SWARMCOMMAND"))
(defconstant offb_msgs::SwarmCommand::*XY_VEL_Z_POS* 2)
(intern "*XYZ_VEL*" (find-package "OFFB_MSGS::SWARMCOMMAND"))
(shadow '*XYZ_VEL* (find-package "OFFB_MSGS::SWARMCOMMAND"))
(defconstant offb_msgs::SwarmCommand::*XYZ_VEL* 3)
(intern "*XYZ_ACC*" (find-package "OFFB_MSGS::SWARMCOMMAND"))
(shadow '*XYZ_ACC* (find-package "OFFB_MSGS::SWARMCOMMAND"))
(defconstant offb_msgs::SwarmCommand::*XYZ_ACC* 4)
(intern "*TRAJECTORY*" (find-package "OFFB_MSGS::SWARMCOMMAND"))
(shadow '*TRAJECTORY* (find-package "OFFB_MSGS::SWARMCOMMAND"))
(defconstant offb_msgs::SwarmCommand::*TRAJECTORY* 5)
(defclass offb_msgs::SwarmCommand
  :super ros::object
  :slots (_header _Command_ID _source _Mode _swarm_shape _Move_mode _swarm_size _position_ref _velocity_ref _yaw_ref ))

(defmethod offb_msgs::SwarmCommand
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:Command_ID __Command_ID) 0)
    ((:source __source) "")
    ((:Mode __Mode) 0)
    ((:swarm_shape __swarm_shape) 0)
    ((:Move_mode __Move_mode) 0)
    ((:swarm_size __swarm_size) 0.0)
    ((:position_ref __position_ref) (make-array 3 :initial-element 0.0 :element-type :float))
    ((:velocity_ref __velocity_ref) (make-array 3 :initial-element 0.0 :element-type :float))
    ((:yaw_ref __yaw_ref) 0.0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _Command_ID (round __Command_ID))
   (setq _source (string __source))
   (setq _Mode (round __Mode))
   (setq _swarm_shape (round __swarm_shape))
   (setq _Move_mode (round __Move_mode))
   (setq _swarm_size (float __swarm_size))
   (setq _position_ref __position_ref)
   (setq _velocity_ref __velocity_ref)
   (setq _yaw_ref (float __yaw_ref))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:Command_ID
   (&optional __Command_ID)
   (if __Command_ID (setq _Command_ID __Command_ID)) _Command_ID)
  (:source
   (&optional __source)
   (if __source (setq _source __source)) _source)
  (:Mode
   (&optional __Mode)
   (if __Mode (setq _Mode __Mode)) _Mode)
  (:swarm_shape
   (&optional __swarm_shape)
   (if __swarm_shape (setq _swarm_shape __swarm_shape)) _swarm_shape)
  (:Move_mode
   (&optional __Move_mode)
   (if __Move_mode (setq _Move_mode __Move_mode)) _Move_mode)
  (:swarm_size
   (&optional __swarm_size)
   (if __swarm_size (setq _swarm_size __swarm_size)) _swarm_size)
  (:position_ref
   (&optional __position_ref)
   (if __position_ref (setq _position_ref __position_ref)) _position_ref)
  (:velocity_ref
   (&optional __velocity_ref)
   (if __velocity_ref (setq _velocity_ref __velocity_ref)) _velocity_ref)
  (:yaw_ref
   (&optional __yaw_ref)
   (if __yaw_ref (setq _yaw_ref __yaw_ref)) _yaw_ref)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; uint32 _Command_ID
    4
    ;; string _source
    4 (length _source)
    ;; uint8 _Mode
    1
    ;; uint8 _swarm_shape
    1
    ;; uint8 _Move_mode
    1
    ;; float32 _swarm_size
    4
    ;; float32[3] _position_ref
    (* 4    3)
    ;; float32[3] _velocity_ref
    (* 4    3)
    ;; float32 _yaw_ref
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; uint32 _Command_ID
       (write-long _Command_ID s)
     ;; string _source
       (write-long (length _source) s) (princ _source s)
     ;; uint8 _Mode
       (write-byte _Mode s)
     ;; uint8 _swarm_shape
       (write-byte _swarm_shape s)
     ;; uint8 _Move_mode
       (write-byte _Move_mode s)
     ;; float32 _swarm_size
       (sys::poke _swarm_size (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32[3] _position_ref
     (dotimes (i 3)
       (sys::poke (elt _position_ref i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;; float32[3] _velocity_ref
     (dotimes (i 3)
       (sys::poke (elt _velocity_ref i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;; float32 _yaw_ref
       (sys::poke _yaw_ref (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; uint32 _Command_ID
     (setq _Command_ID (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; string _source
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _source (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; uint8 _Mode
     (setq _Mode (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _swarm_shape
     (setq _swarm_shape (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _Move_mode
     (setq _Move_mode (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; float32 _swarm_size
     (setq _swarm_size (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32[3] _position_ref
   (dotimes (i (length _position_ref))
     (setf (elt _position_ref i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     )
   ;; float32[3] _velocity_ref
   (dotimes (i (length _velocity_ref))
     (setf (elt _velocity_ref i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     )
   ;; float32 _yaw_ref
     (setq _yaw_ref (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get offb_msgs::SwarmCommand :md5sum-) "f0e68f41f7d26607969a5fba3d80e691")
(setf (get offb_msgs::SwarmCommand :datatype-) "offb_msgs/SwarmCommand")
(setf (get offb_msgs::SwarmCommand :definition-)
      "std_msgs/Header header

## 控制命令的编号 防止接收到错误命令， 编号应该逐次递加
uint32 Command_ID

## 消息来源
string source

## 控制命令的模式 
uint8 Mode
# enum Mode 控制模式枚举
uint8 Idle=0
uint8 Takeoff=1
uint8 Hold=2
uint8 Land=3
uint8 Disarm=4
uint8 Position_Control=5
uint8 Velocity_Control=6
uint8 Accel_Control=7
uint8 Move=8
uint8 User_Mode1=9

## 控制参考量 
uint8 swarm_shape

uint8 One_column=0
uint8 Triangle=1
uint8 Square=2
uint8 Circular=3

## 默认为 XYZ位置追踪模式 （sub_mode = 0）； 速度追踪启用时，控制器不考虑位置参考量及位置状态反馈
uint8 Move_mode

uint8 XYZ_POS      = 0  ##0b00
uint8 XY_POS_Z_VEL = 1  ##0b01
uint8 XY_VEL_Z_POS = 2  ##0b10
uint8 XYZ_VEL = 3       ##0b11
uint8 XYZ_ACC = 4
uint8 TRAJECTORY   = 5 


float32 swarm_size

float32[3] position_ref          ## [m]
float32[3] velocity_ref          ## [m]
float32 yaw_ref                  ## [rad]


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

")



(provide :offb_msgs/SwarmCommand "f0e68f41f7d26607969a5fba3d80e691")


