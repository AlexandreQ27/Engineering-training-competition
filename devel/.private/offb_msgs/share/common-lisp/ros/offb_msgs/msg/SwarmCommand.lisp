; Auto-generated. Do not edit!


(cl:in-package offb_msgs-msg)


;//! \htmlinclude SwarmCommand.msg.html

(cl:defclass <SwarmCommand> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (Command_ID
    :reader Command_ID
    :initarg :Command_ID
    :type cl:integer
    :initform 0)
   (source
    :reader source
    :initarg :source
    :type cl:string
    :initform "")
   (Mode
    :reader Mode
    :initarg :Mode
    :type cl:fixnum
    :initform 0)
   (swarm_shape
    :reader swarm_shape
    :initarg :swarm_shape
    :type cl:fixnum
    :initform 0)
   (Move_mode
    :reader Move_mode
    :initarg :Move_mode
    :type cl:fixnum
    :initform 0)
   (swarm_size
    :reader swarm_size
    :initarg :swarm_size
    :type cl:float
    :initform 0.0)
   (position_ref
    :reader position_ref
    :initarg :position_ref
    :type (cl:vector cl:float)
   :initform (cl:make-array 3 :element-type 'cl:float :initial-element 0.0))
   (velocity_ref
    :reader velocity_ref
    :initarg :velocity_ref
    :type (cl:vector cl:float)
   :initform (cl:make-array 3 :element-type 'cl:float :initial-element 0.0))
   (yaw_ref
    :reader yaw_ref
    :initarg :yaw_ref
    :type cl:float
    :initform 0.0))
)

(cl:defclass SwarmCommand (<SwarmCommand>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SwarmCommand>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SwarmCommand)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name offb_msgs-msg:<SwarmCommand> is deprecated: use offb_msgs-msg:SwarmCommand instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <SwarmCommand>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader offb_msgs-msg:header-val is deprecated.  Use offb_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'Command_ID-val :lambda-list '(m))
(cl:defmethod Command_ID-val ((m <SwarmCommand>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader offb_msgs-msg:Command_ID-val is deprecated.  Use offb_msgs-msg:Command_ID instead.")
  (Command_ID m))

(cl:ensure-generic-function 'source-val :lambda-list '(m))
(cl:defmethod source-val ((m <SwarmCommand>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader offb_msgs-msg:source-val is deprecated.  Use offb_msgs-msg:source instead.")
  (source m))

(cl:ensure-generic-function 'Mode-val :lambda-list '(m))
(cl:defmethod Mode-val ((m <SwarmCommand>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader offb_msgs-msg:Mode-val is deprecated.  Use offb_msgs-msg:Mode instead.")
  (Mode m))

(cl:ensure-generic-function 'swarm_shape-val :lambda-list '(m))
(cl:defmethod swarm_shape-val ((m <SwarmCommand>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader offb_msgs-msg:swarm_shape-val is deprecated.  Use offb_msgs-msg:swarm_shape instead.")
  (swarm_shape m))

(cl:ensure-generic-function 'Move_mode-val :lambda-list '(m))
(cl:defmethod Move_mode-val ((m <SwarmCommand>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader offb_msgs-msg:Move_mode-val is deprecated.  Use offb_msgs-msg:Move_mode instead.")
  (Move_mode m))

(cl:ensure-generic-function 'swarm_size-val :lambda-list '(m))
(cl:defmethod swarm_size-val ((m <SwarmCommand>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader offb_msgs-msg:swarm_size-val is deprecated.  Use offb_msgs-msg:swarm_size instead.")
  (swarm_size m))

(cl:ensure-generic-function 'position_ref-val :lambda-list '(m))
(cl:defmethod position_ref-val ((m <SwarmCommand>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader offb_msgs-msg:position_ref-val is deprecated.  Use offb_msgs-msg:position_ref instead.")
  (position_ref m))

(cl:ensure-generic-function 'velocity_ref-val :lambda-list '(m))
(cl:defmethod velocity_ref-val ((m <SwarmCommand>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader offb_msgs-msg:velocity_ref-val is deprecated.  Use offb_msgs-msg:velocity_ref instead.")
  (velocity_ref m))

(cl:ensure-generic-function 'yaw_ref-val :lambda-list '(m))
(cl:defmethod yaw_ref-val ((m <SwarmCommand>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader offb_msgs-msg:yaw_ref-val is deprecated.  Use offb_msgs-msg:yaw_ref instead.")
  (yaw_ref m))
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql '<SwarmCommand>)))
    "Constants for message type '<SwarmCommand>"
  '((:IDLE . 0)
    (:TAKEOFF . 1)
    (:HOLD . 2)
    (:LAND . 3)
    (:DISARM . 4)
    (:POSITION_CONTROL . 5)
    (:VELOCITY_CONTROL . 6)
    (:ACCEL_CONTROL . 7)
    (:MOVE . 8)
    (:USER_MODE1 . 9)
    (:ONE_COLUMN . 0)
    (:TRIANGLE . 1)
    (:SQUARE . 2)
    (:CIRCULAR . 3)
    (:XYZ_POS . 0)
    (:XY_POS_Z_VEL . 1)
    (:XY_VEL_Z_POS . 2)
    (:XYZ_VEL . 3)
    (:XYZ_ACC . 4)
    (:TRAJECTORY . 5))
)
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql 'SwarmCommand)))
    "Constants for message type 'SwarmCommand"
  '((:IDLE . 0)
    (:TAKEOFF . 1)
    (:HOLD . 2)
    (:LAND . 3)
    (:DISARM . 4)
    (:POSITION_CONTROL . 5)
    (:VELOCITY_CONTROL . 6)
    (:ACCEL_CONTROL . 7)
    (:MOVE . 8)
    (:USER_MODE1 . 9)
    (:ONE_COLUMN . 0)
    (:TRIANGLE . 1)
    (:SQUARE . 2)
    (:CIRCULAR . 3)
    (:XYZ_POS . 0)
    (:XY_POS_Z_VEL . 1)
    (:XY_VEL_Z_POS . 2)
    (:XYZ_VEL . 3)
    (:XYZ_ACC . 4)
    (:TRAJECTORY . 5))
)
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SwarmCommand>) ostream)
  "Serializes a message object of type '<SwarmCommand>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'Command_ID)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'Command_ID)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'Command_ID)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'Command_ID)) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'source))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'source))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'Mode)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'swarm_shape)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'Move_mode)) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'swarm_size))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'position_ref))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'velocity_ref))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'yaw_ref))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SwarmCommand>) istream)
  "Deserializes a message object of type '<SwarmCommand>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'Command_ID)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'Command_ID)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'Command_ID)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'Command_ID)) (cl:read-byte istream))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'source) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'source) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'Mode)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'swarm_shape)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'Move_mode)) (cl:read-byte istream))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'swarm_size) (roslisp-utils:decode-single-float-bits bits)))
  (cl:setf (cl:slot-value msg 'position_ref) (cl:make-array 3))
  (cl:let ((vals (cl:slot-value msg 'position_ref)))
    (cl:dotimes (i 3)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits)))))
  (cl:setf (cl:slot-value msg 'velocity_ref) (cl:make-array 3))
  (cl:let ((vals (cl:slot-value msg 'velocity_ref)))
    (cl:dotimes (i 3)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits)))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'yaw_ref) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SwarmCommand>)))
  "Returns string type for a message object of type '<SwarmCommand>"
  "offb_msgs/SwarmCommand")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SwarmCommand)))
  "Returns string type for a message object of type 'SwarmCommand"
  "offb_msgs/SwarmCommand")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SwarmCommand>)))
  "Returns md5sum for a message object of type '<SwarmCommand>"
  "f0e68f41f7d26607969a5fba3d80e691")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SwarmCommand)))
  "Returns md5sum for a message object of type 'SwarmCommand"
  "f0e68f41f7d26607969a5fba3d80e691")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SwarmCommand>)))
  "Returns full string definition for message of type '<SwarmCommand>"
  (cl:format cl:nil "std_msgs/Header header~%~%## 控制命令的编号 防止接收到错误命令， 编号应该逐次递加~%uint32 Command_ID~%~%## 消息来源~%string source~%~%## 控制命令的模式 ~%uint8 Mode~%# enum Mode 控制模式枚举~%uint8 Idle=0~%uint8 Takeoff=1~%uint8 Hold=2~%uint8 Land=3~%uint8 Disarm=4~%uint8 Position_Control=5~%uint8 Velocity_Control=6~%uint8 Accel_Control=7~%uint8 Move=8~%uint8 User_Mode1=9~%~%## 控制参考量 ~%uint8 swarm_shape~%~%uint8 One_column=0~%uint8 Triangle=1~%uint8 Square=2~%uint8 Circular=3~%~%## 默认为 XYZ位置追踪模式 （sub_mode = 0）； 速度追踪启用时，控制器不考虑位置参考量及位置状态反馈~%uint8 Move_mode~%~%uint8 XYZ_POS      = 0  ##0b00~%uint8 XY_POS_Z_VEL = 1  ##0b01~%uint8 XY_VEL_Z_POS = 2  ##0b10~%uint8 XYZ_VEL = 3       ##0b11~%uint8 XYZ_ACC = 4~%uint8 TRAJECTORY   = 5 ~%~%~%float32 swarm_size~%~%float32[3] position_ref          ## [m]~%float32[3] velocity_ref          ## [m]~%float32 yaw_ref                  ## [rad]~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SwarmCommand)))
  "Returns full string definition for message of type 'SwarmCommand"
  (cl:format cl:nil "std_msgs/Header header~%~%## 控制命令的编号 防止接收到错误命令， 编号应该逐次递加~%uint32 Command_ID~%~%## 消息来源~%string source~%~%## 控制命令的模式 ~%uint8 Mode~%# enum Mode 控制模式枚举~%uint8 Idle=0~%uint8 Takeoff=1~%uint8 Hold=2~%uint8 Land=3~%uint8 Disarm=4~%uint8 Position_Control=5~%uint8 Velocity_Control=6~%uint8 Accel_Control=7~%uint8 Move=8~%uint8 User_Mode1=9~%~%## 控制参考量 ~%uint8 swarm_shape~%~%uint8 One_column=0~%uint8 Triangle=1~%uint8 Square=2~%uint8 Circular=3~%~%## 默认为 XYZ位置追踪模式 （sub_mode = 0）； 速度追踪启用时，控制器不考虑位置参考量及位置状态反馈~%uint8 Move_mode~%~%uint8 XYZ_POS      = 0  ##0b00~%uint8 XY_POS_Z_VEL = 1  ##0b01~%uint8 XY_VEL_Z_POS = 2  ##0b10~%uint8 XYZ_VEL = 3       ##0b11~%uint8 XYZ_ACC = 4~%uint8 TRAJECTORY   = 5 ~%~%~%float32 swarm_size~%~%float32[3] position_ref          ## [m]~%float32[3] velocity_ref          ## [m]~%float32 yaw_ref                  ## [rad]~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SwarmCommand>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4
     4 (cl:length (cl:slot-value msg 'source))
     1
     1
     1
     4
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'position_ref) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'velocity_ref) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SwarmCommand>))
  "Converts a ROS message object to a list"
  (cl:list 'SwarmCommand
    (cl:cons ':header (header msg))
    (cl:cons ':Command_ID (Command_ID msg))
    (cl:cons ':source (source msg))
    (cl:cons ':Mode (Mode msg))
    (cl:cons ':swarm_shape (swarm_shape msg))
    (cl:cons ':Move_mode (Move_mode msg))
    (cl:cons ':swarm_size (swarm_size msg))
    (cl:cons ':position_ref (position_ref msg))
    (cl:cons ':velocity_ref (velocity_ref msg))
    (cl:cons ':yaw_ref (yaw_ref msg))
))
