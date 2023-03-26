; Auto-generated. Do not edit!


(cl:in-package offb_msgs-msg)


;//! \htmlinclude LogMessagePlanning.msg.html

(cl:defclass <LogMessagePlanning> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (time
    :reader time
    :initarg :time
    :type cl:float
    :initform 0.0)
   (Drone_State
    :reader Drone_State
    :initarg :Drone_State
    :type offb_msgs-msg:DroneState
    :initform (cl:make-instance 'offb_msgs-msg:DroneState))
   (Control_Command
    :reader Control_Command
    :initarg :Control_Command
    :type offb_msgs-msg:ControlCommand
    :initform (cl:make-instance 'offb_msgs-msg:ControlCommand))
   (Control_Output
    :reader Control_Output
    :initarg :Control_Output
    :type offb_msgs-msg:ControlOutput
    :initform (cl:make-instance 'offb_msgs-msg:ControlOutput))
   (Attitude_Reference
    :reader Attitude_Reference
    :initarg :Attitude_Reference
    :type offb_msgs-msg:AttitudeReference
    :initform (cl:make-instance 'offb_msgs-msg:AttitudeReference)))
)

(cl:defclass LogMessagePlanning (<LogMessagePlanning>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <LogMessagePlanning>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'LogMessagePlanning)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name offb_msgs-msg:<LogMessagePlanning> is deprecated: use offb_msgs-msg:LogMessagePlanning instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <LogMessagePlanning>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader offb_msgs-msg:header-val is deprecated.  Use offb_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'time-val :lambda-list '(m))
(cl:defmethod time-val ((m <LogMessagePlanning>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader offb_msgs-msg:time-val is deprecated.  Use offb_msgs-msg:time instead.")
  (time m))

(cl:ensure-generic-function 'Drone_State-val :lambda-list '(m))
(cl:defmethod Drone_State-val ((m <LogMessagePlanning>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader offb_msgs-msg:Drone_State-val is deprecated.  Use offb_msgs-msg:Drone_State instead.")
  (Drone_State m))

(cl:ensure-generic-function 'Control_Command-val :lambda-list '(m))
(cl:defmethod Control_Command-val ((m <LogMessagePlanning>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader offb_msgs-msg:Control_Command-val is deprecated.  Use offb_msgs-msg:Control_Command instead.")
  (Control_Command m))

(cl:ensure-generic-function 'Control_Output-val :lambda-list '(m))
(cl:defmethod Control_Output-val ((m <LogMessagePlanning>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader offb_msgs-msg:Control_Output-val is deprecated.  Use offb_msgs-msg:Control_Output instead.")
  (Control_Output m))

(cl:ensure-generic-function 'Attitude_Reference-val :lambda-list '(m))
(cl:defmethod Attitude_Reference-val ((m <LogMessagePlanning>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader offb_msgs-msg:Attitude_Reference-val is deprecated.  Use offb_msgs-msg:Attitude_Reference instead.")
  (Attitude_Reference m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <LogMessagePlanning>) ostream)
  "Serializes a message object of type '<LogMessagePlanning>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'time))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'Drone_State) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'Control_Command) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'Control_Output) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'Attitude_Reference) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <LogMessagePlanning>) istream)
  "Deserializes a message object of type '<LogMessagePlanning>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'time) (roslisp-utils:decode-single-float-bits bits)))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'Drone_State) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'Control_Command) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'Control_Output) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'Attitude_Reference) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<LogMessagePlanning>)))
  "Returns string type for a message object of type '<LogMessagePlanning>"
  "offb_msgs/LogMessagePlanning")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'LogMessagePlanning)))
  "Returns string type for a message object of type 'LogMessagePlanning"
  "offb_msgs/LogMessagePlanning")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<LogMessagePlanning>)))
  "Returns md5sum for a message object of type '<LogMessagePlanning>"
  "2d4ad0bb816c6f3427390d4683b646bf")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'LogMessagePlanning)))
  "Returns md5sum for a message object of type 'LogMessagePlanning"
  "2d4ad0bb816c6f3427390d4683b646bf")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<LogMessagePlanning>)))
  "Returns full string definition for message of type '<LogMessagePlanning>"
  (cl:format cl:nil "std_msgs/Header header~%~%## 用于控制模块的log消息，可自行增加需要记录的话题~%float32 time             ## [s]~%~%DroneState Drone_State~%~%ControlCommand Control_Command~%~%ControlOutput Control_Output~%~%AttitudeReference Attitude_Reference~%~%~%~%~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: offb_msgs/DroneState~%std_msgs/Header header~%~%## 机载电脑是否连接上飞控，true已连接，false则不是~%bool connected~%## 是否解锁，true为已解锁，false则不是~%bool armed~%## 是否降落，true为已降落，false则代表在空中~%bool landed~%## PX4飞控当前飞行模式~%string mode~%~%## 系统启动时间~%float32 time_from_start             ## [s]~%~%## 无人机状态量：位置、速度、姿态~%float32[3] position                 ## [m]~%float32  rel_alt                               ## [m] only for outdoor~%float32[3] velocity                 ## [m/s]~%float32[3] attitude                 ## [rad]~%geometry_msgs/Quaternion attitude_q ## 四元数~%float32[3] attitude_rate            ## [rad/s]~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%================================================================================~%MSG: offb_msgs/ControlCommand~%std_msgs/Header header~%~%## 控制命令的编号 防止接收到错误命令， 编号应该逐次递加~%uint32 Command_ID~%~%## 消息来源~%string source~%## 控制命令的模式 ~%uint8 Mode~%# enum Mode 控制模式枚举~%uint8 Idle=0~%uint8 Takeoff=1~%uint8 Hover=2~%uint8 Move=3~%uint8 LAND=4~%uint8 Disarm=5~%uint8 User_Mode1=6~%uint8 User_Mode2=7~%~%## 控制参考量 ~%## 位置参考量：位置、速度、加速度、加加速度、加加加速度~%## 角度参考量：偏航角、偏航角速度、偏航角加速度~%PositionReference Reference_State~%~%================================================================================~%MSG: offb_msgs/PositionReference~%std_msgs/Header header~%~%## 位置控制参考量~%~%## 默认为 XYZ位置追踪模式 （sub_mode = 0）； 速度追踪启用时，控制器不考虑位置参考量及位置状态反馈~%uint8 Move_mode~%~%uint8 XYZ_POS      = 0  ##0b00~%uint8 XY_POS_Z_VEL = 1  ##0b01~%uint8 XY_VEL_Z_POS = 2  ##0b10~%uint8 XYZ_VEL = 3       ##0b11~%uint8 XYZ_ACC = 4~%uint8 TRAJECTORY   = 5  ~%~%uint8 Move_frame~%# 默认情况下均为ENU_FRAME,注意轨迹追踪和XYZ_ACC一定是ENU_FRAME~%uint8 ENU_FRAME  = 0~%uint8 BODY_FRAME = 1~%uint8 MIX_FRAME = 2 ##2020.4.6 临时增加的模式，后期需要统一整合，该模式下，xy采用机体系控制，z采用enu系控制~%~%~%~%## 时刻： 用于轨迹追踪~%float32 time_from_start          ## [s]~%~%## 参考量：位置、速度、加速度、加加速度、加加加速度~%float32[3] position_ref          ## [m]~%float32[3] velocity_ref          ## [m/s]~%float32[3] acceleration_ref      ## [m/s^2]~%## float32[3] jerk_ref              ## [m/s^3]~%## float32[3] snap_ref              ## [m/s^4]~%~%## 角度参考量：偏航角、偏航角速度、偏航角加速度~%bool Yaw_Rate_Mode                      ## True 代表控制偏航角速率~%float32 yaw_ref                  ## [rad]~%float32 yaw_rate_ref             ## [rad/s] ~%## float32 yaw_acceleration_ref     ## [rad/s] ~%================================================================================~%MSG: offb_msgs/ControlOutput~%std_msgs/Header header~%~%## 位置控制器输出： 期望推力及期望油门~%float32[3] Thrust              ## [rad]  ~%float32[3] Throttle~%~%## NE控制器的中间变量~%float32[3] u_l                 ## [0-1] 惯性系下的油门量~%float32[3] u_d                 ## [rad]~%float32[3] NE                  ## [rad]~%================================================================================~%MSG: offb_msgs/AttitudeReference~%std_msgs/Header header~%~%## 位置控制器输出： 期望油门 + 期望角度~%float32[3] throttle_sp                 ## [0-1] 惯性系下的油门量~%float32 desired_throttle               ## [0-1] 机体系z轴~%float32[3] desired_attitude            ## [rad]~%geometry_msgs/Quaternion desired_att_q ## 四元数~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'LogMessagePlanning)))
  "Returns full string definition for message of type 'LogMessagePlanning"
  (cl:format cl:nil "std_msgs/Header header~%~%## 用于控制模块的log消息，可自行增加需要记录的话题~%float32 time             ## [s]~%~%DroneState Drone_State~%~%ControlCommand Control_Command~%~%ControlOutput Control_Output~%~%AttitudeReference Attitude_Reference~%~%~%~%~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: offb_msgs/DroneState~%std_msgs/Header header~%~%## 机载电脑是否连接上飞控，true已连接，false则不是~%bool connected~%## 是否解锁，true为已解锁，false则不是~%bool armed~%## 是否降落，true为已降落，false则代表在空中~%bool landed~%## PX4飞控当前飞行模式~%string mode~%~%## 系统启动时间~%float32 time_from_start             ## [s]~%~%## 无人机状态量：位置、速度、姿态~%float32[3] position                 ## [m]~%float32  rel_alt                               ## [m] only for outdoor~%float32[3] velocity                 ## [m/s]~%float32[3] attitude                 ## [rad]~%geometry_msgs/Quaternion attitude_q ## 四元数~%float32[3] attitude_rate            ## [rad/s]~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%================================================================================~%MSG: offb_msgs/ControlCommand~%std_msgs/Header header~%~%## 控制命令的编号 防止接收到错误命令， 编号应该逐次递加~%uint32 Command_ID~%~%## 消息来源~%string source~%## 控制命令的模式 ~%uint8 Mode~%# enum Mode 控制模式枚举~%uint8 Idle=0~%uint8 Takeoff=1~%uint8 Hover=2~%uint8 Move=3~%uint8 LAND=4~%uint8 Disarm=5~%uint8 User_Mode1=6~%uint8 User_Mode2=7~%~%## 控制参考量 ~%## 位置参考量：位置、速度、加速度、加加速度、加加加速度~%## 角度参考量：偏航角、偏航角速度、偏航角加速度~%PositionReference Reference_State~%~%================================================================================~%MSG: offb_msgs/PositionReference~%std_msgs/Header header~%~%## 位置控制参考量~%~%## 默认为 XYZ位置追踪模式 （sub_mode = 0）； 速度追踪启用时，控制器不考虑位置参考量及位置状态反馈~%uint8 Move_mode~%~%uint8 XYZ_POS      = 0  ##0b00~%uint8 XY_POS_Z_VEL = 1  ##0b01~%uint8 XY_VEL_Z_POS = 2  ##0b10~%uint8 XYZ_VEL = 3       ##0b11~%uint8 XYZ_ACC = 4~%uint8 TRAJECTORY   = 5  ~%~%uint8 Move_frame~%# 默认情况下均为ENU_FRAME,注意轨迹追踪和XYZ_ACC一定是ENU_FRAME~%uint8 ENU_FRAME  = 0~%uint8 BODY_FRAME = 1~%uint8 MIX_FRAME = 2 ##2020.4.6 临时增加的模式，后期需要统一整合，该模式下，xy采用机体系控制，z采用enu系控制~%~%~%~%## 时刻： 用于轨迹追踪~%float32 time_from_start          ## [s]~%~%## 参考量：位置、速度、加速度、加加速度、加加加速度~%float32[3] position_ref          ## [m]~%float32[3] velocity_ref          ## [m/s]~%float32[3] acceleration_ref      ## [m/s^2]~%## float32[3] jerk_ref              ## [m/s^3]~%## float32[3] snap_ref              ## [m/s^4]~%~%## 角度参考量：偏航角、偏航角速度、偏航角加速度~%bool Yaw_Rate_Mode                      ## True 代表控制偏航角速率~%float32 yaw_ref                  ## [rad]~%float32 yaw_rate_ref             ## [rad/s] ~%## float32 yaw_acceleration_ref     ## [rad/s] ~%================================================================================~%MSG: offb_msgs/ControlOutput~%std_msgs/Header header~%~%## 位置控制器输出： 期望推力及期望油门~%float32[3] Thrust              ## [rad]  ~%float32[3] Throttle~%~%## NE控制器的中间变量~%float32[3] u_l                 ## [0-1] 惯性系下的油门量~%float32[3] u_d                 ## [rad]~%float32[3] NE                  ## [rad]~%================================================================================~%MSG: offb_msgs/AttitudeReference~%std_msgs/Header header~%~%## 位置控制器输出： 期望油门 + 期望角度~%float32[3] throttle_sp                 ## [0-1] 惯性系下的油门量~%float32 desired_throttle               ## [0-1] 机体系z轴~%float32[3] desired_attitude            ## [rad]~%geometry_msgs/Quaternion desired_att_q ## 四元数~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <LogMessagePlanning>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'Drone_State))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'Control_Command))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'Control_Output))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'Attitude_Reference))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <LogMessagePlanning>))
  "Converts a ROS message object to a list"
  (cl:list 'LogMessagePlanning
    (cl:cons ':header (header msg))
    (cl:cons ':time (time msg))
    (cl:cons ':Drone_State (Drone_State msg))
    (cl:cons ':Control_Command (Control_Command msg))
    (cl:cons ':Control_Output (Control_Output msg))
    (cl:cons ':Attitude_Reference (Attitude_Reference msg))
))
