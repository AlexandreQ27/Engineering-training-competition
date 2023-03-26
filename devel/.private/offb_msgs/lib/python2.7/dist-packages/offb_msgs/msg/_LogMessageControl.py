# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from offb_msgs/LogMessageControl.msg. Do not edit."""
import codecs
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import geometry_msgs.msg
import offb_msgs.msg
import std_msgs.msg

class LogMessageControl(genpy.Message):
  _md5sum = "5781c2d06de4d7c7a326052cb8307187"
  _type = "offb_msgs/LogMessageControl"
  _has_header = True  # flag to mark the presence of a Header object
  _full_text = """std_msgs/Header header

## 用于控制模块的log消息，可自行增加需要记录的话题
float32 time             ## [s]

## 0代表px4_sender,1代表px4_pos_controller(姿态控制)
int32 control_type

DroneState Drone_State

ControlCommand Control_Command

ControlOutput Control_Output

AttitudeReference Attitude_Reference

geometry_msgs/PoseStamped ref_pose




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

================================================================================
MSG: geometry_msgs/PoseStamped
# A Pose with reference coordinate frame and timestamp
Header header
Pose pose

================================================================================
MSG: geometry_msgs/Pose
# A representation of pose in free space, composed of position and orientation. 
Point position
Quaternion orientation

================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z
"""
  __slots__ = ['header','time','control_type','Drone_State','Control_Command','Control_Output','Attitude_Reference','ref_pose']
  _slot_types = ['std_msgs/Header','float32','int32','offb_msgs/DroneState','offb_msgs/ControlCommand','offb_msgs/ControlOutput','offb_msgs/AttitudeReference','geometry_msgs/PoseStamped']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       header,time,control_type,Drone_State,Control_Command,Control_Output,Attitude_Reference,ref_pose

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(LogMessageControl, self).__init__(*args, **kwds)
      # message fields cannot be None, assign default values for those that are
      if self.header is None:
        self.header = std_msgs.msg.Header()
      if self.time is None:
        self.time = 0.
      if self.control_type is None:
        self.control_type = 0
      if self.Drone_State is None:
        self.Drone_State = offb_msgs.msg.DroneState()
      if self.Control_Command is None:
        self.Control_Command = offb_msgs.msg.ControlCommand()
      if self.Control_Output is None:
        self.Control_Output = offb_msgs.msg.ControlOutput()
      if self.Attitude_Reference is None:
        self.Attitude_Reference = offb_msgs.msg.AttitudeReference()
      if self.ref_pose is None:
        self.ref_pose = geometry_msgs.msg.PoseStamped()
    else:
      self.header = std_msgs.msg.Header()
      self.time = 0.
      self.control_type = 0
      self.Drone_State = offb_msgs.msg.DroneState()
      self.Control_Command = offb_msgs.msg.ControlCommand()
      self.Control_Output = offb_msgs.msg.ControlOutput()
      self.Attitude_Reference = offb_msgs.msg.AttitudeReference()
      self.ref_pose = geometry_msgs.msg.PoseStamped()

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_get_struct_3I().pack(_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs))
      _x = self.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
      _x = self
      buff.write(_get_struct_fi3I().pack(_x.time, _x.control_type, _x.Drone_State.header.seq, _x.Drone_State.header.stamp.secs, _x.Drone_State.header.stamp.nsecs))
      _x = self.Drone_State.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
      _x = self
      buff.write(_get_struct_3B().pack(_x.Drone_State.connected, _x.Drone_State.armed, _x.Drone_State.landed))
      _x = self.Drone_State.mode
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
      _x = self.Drone_State.time_from_start
      buff.write(_get_struct_f().pack(_x))
      buff.write(_get_struct_3f().pack(*self.Drone_State.position))
      _x = self.Drone_State.rel_alt
      buff.write(_get_struct_f().pack(_x))
      buff.write(_get_struct_3f().pack(*self.Drone_State.velocity))
      buff.write(_get_struct_3f().pack(*self.Drone_State.attitude))
      _x = self
      buff.write(_get_struct_4d().pack(_x.Drone_State.attitude_q.x, _x.Drone_State.attitude_q.y, _x.Drone_State.attitude_q.z, _x.Drone_State.attitude_q.w))
      buff.write(_get_struct_3f().pack(*self.Drone_State.attitude_rate))
      _x = self
      buff.write(_get_struct_3I().pack(_x.Control_Command.header.seq, _x.Control_Command.header.stamp.secs, _x.Control_Command.header.stamp.nsecs))
      _x = self.Control_Command.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
      _x = self.Control_Command.Command_ID
      buff.write(_get_struct_I().pack(_x))
      _x = self.Control_Command.source
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
      _x = self
      buff.write(_get_struct_B3I().pack(_x.Control_Command.Mode, _x.Control_Command.Reference_State.header.seq, _x.Control_Command.Reference_State.header.stamp.secs, _x.Control_Command.Reference_State.header.stamp.nsecs))
      _x = self.Control_Command.Reference_State.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
      _x = self
      buff.write(_get_struct_2Bf().pack(_x.Control_Command.Reference_State.Move_mode, _x.Control_Command.Reference_State.Move_frame, _x.Control_Command.Reference_State.time_from_start))
      buff.write(_get_struct_3f().pack(*self.Control_Command.Reference_State.position_ref))
      buff.write(_get_struct_3f().pack(*self.Control_Command.Reference_State.velocity_ref))
      buff.write(_get_struct_3f().pack(*self.Control_Command.Reference_State.acceleration_ref))
      _x = self
      buff.write(_get_struct_B2f3I().pack(_x.Control_Command.Reference_State.Yaw_Rate_Mode, _x.Control_Command.Reference_State.yaw_ref, _x.Control_Command.Reference_State.yaw_rate_ref, _x.Control_Output.header.seq, _x.Control_Output.header.stamp.secs, _x.Control_Output.header.stamp.nsecs))
      _x = self.Control_Output.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
      buff.write(_get_struct_3f().pack(*self.Control_Output.Thrust))
      buff.write(_get_struct_3f().pack(*self.Control_Output.Throttle))
      buff.write(_get_struct_3f().pack(*self.Control_Output.u_l))
      buff.write(_get_struct_3f().pack(*self.Control_Output.u_d))
      buff.write(_get_struct_3f().pack(*self.Control_Output.NE))
      _x = self
      buff.write(_get_struct_3I().pack(_x.Attitude_Reference.header.seq, _x.Attitude_Reference.header.stamp.secs, _x.Attitude_Reference.header.stamp.nsecs))
      _x = self.Attitude_Reference.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
      buff.write(_get_struct_3f().pack(*self.Attitude_Reference.throttle_sp))
      _x = self.Attitude_Reference.desired_throttle
      buff.write(_get_struct_f().pack(_x))
      buff.write(_get_struct_3f().pack(*self.Attitude_Reference.desired_attitude))
      _x = self
      buff.write(_get_struct_4d3I().pack(_x.Attitude_Reference.desired_att_q.x, _x.Attitude_Reference.desired_att_q.y, _x.Attitude_Reference.desired_att_q.z, _x.Attitude_Reference.desired_att_q.w, _x.ref_pose.header.seq, _x.ref_pose.header.stamp.secs, _x.ref_pose.header.stamp.nsecs))
      _x = self.ref_pose.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
      _x = self
      buff.write(_get_struct_7d().pack(_x.ref_pose.pose.position.x, _x.ref_pose.pose.position.y, _x.ref_pose.pose.position.z, _x.ref_pose.pose.orientation.x, _x.ref_pose.pose.orientation.y, _x.ref_pose.pose.orientation.z, _x.ref_pose.pose.orientation.w))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    if python3:
      codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      if self.header is None:
        self.header = std_msgs.msg.Header()
      if self.Drone_State is None:
        self.Drone_State = offb_msgs.msg.DroneState()
      if self.Control_Command is None:
        self.Control_Command = offb_msgs.msg.ControlCommand()
      if self.Control_Output is None:
        self.Control_Output = offb_msgs.msg.ControlOutput()
      if self.Attitude_Reference is None:
        self.Attitude_Reference = offb_msgs.msg.AttitudeReference()
      if self.ref_pose is None:
        self.ref_pose = geometry_msgs.msg.PoseStamped()
      end = 0
      _x = self
      start = end
      end += 12
      (_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs,) = _get_struct_3I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.header.frame_id = str[start:end].decode('utf-8', 'rosmsg')
      else:
        self.header.frame_id = str[start:end]
      _x = self
      start = end
      end += 20
      (_x.time, _x.control_type, _x.Drone_State.header.seq, _x.Drone_State.header.stamp.secs, _x.Drone_State.header.stamp.nsecs,) = _get_struct_fi3I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.Drone_State.header.frame_id = str[start:end].decode('utf-8', 'rosmsg')
      else:
        self.Drone_State.header.frame_id = str[start:end]
      _x = self
      start = end
      end += 3
      (_x.Drone_State.connected, _x.Drone_State.armed, _x.Drone_State.landed,) = _get_struct_3B().unpack(str[start:end])
      self.Drone_State.connected = bool(self.Drone_State.connected)
      self.Drone_State.armed = bool(self.Drone_State.armed)
      self.Drone_State.landed = bool(self.Drone_State.landed)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.Drone_State.mode = str[start:end].decode('utf-8', 'rosmsg')
      else:
        self.Drone_State.mode = str[start:end]
      start = end
      end += 4
      (self.Drone_State.time_from_start,) = _get_struct_f().unpack(str[start:end])
      start = end
      end += 12
      self.Drone_State.position = _get_struct_3f().unpack(str[start:end])
      start = end
      end += 4
      (self.Drone_State.rel_alt,) = _get_struct_f().unpack(str[start:end])
      start = end
      end += 12
      self.Drone_State.velocity = _get_struct_3f().unpack(str[start:end])
      start = end
      end += 12
      self.Drone_State.attitude = _get_struct_3f().unpack(str[start:end])
      _x = self
      start = end
      end += 32
      (_x.Drone_State.attitude_q.x, _x.Drone_State.attitude_q.y, _x.Drone_State.attitude_q.z, _x.Drone_State.attitude_q.w,) = _get_struct_4d().unpack(str[start:end])
      start = end
      end += 12
      self.Drone_State.attitude_rate = _get_struct_3f().unpack(str[start:end])
      _x = self
      start = end
      end += 12
      (_x.Control_Command.header.seq, _x.Control_Command.header.stamp.secs, _x.Control_Command.header.stamp.nsecs,) = _get_struct_3I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.Control_Command.header.frame_id = str[start:end].decode('utf-8', 'rosmsg')
      else:
        self.Control_Command.header.frame_id = str[start:end]
      start = end
      end += 4
      (self.Control_Command.Command_ID,) = _get_struct_I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.Control_Command.source = str[start:end].decode('utf-8', 'rosmsg')
      else:
        self.Control_Command.source = str[start:end]
      _x = self
      start = end
      end += 13
      (_x.Control_Command.Mode, _x.Control_Command.Reference_State.header.seq, _x.Control_Command.Reference_State.header.stamp.secs, _x.Control_Command.Reference_State.header.stamp.nsecs,) = _get_struct_B3I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.Control_Command.Reference_State.header.frame_id = str[start:end].decode('utf-8', 'rosmsg')
      else:
        self.Control_Command.Reference_State.header.frame_id = str[start:end]
      _x = self
      start = end
      end += 6
      (_x.Control_Command.Reference_State.Move_mode, _x.Control_Command.Reference_State.Move_frame, _x.Control_Command.Reference_State.time_from_start,) = _get_struct_2Bf().unpack(str[start:end])
      start = end
      end += 12
      self.Control_Command.Reference_State.position_ref = _get_struct_3f().unpack(str[start:end])
      start = end
      end += 12
      self.Control_Command.Reference_State.velocity_ref = _get_struct_3f().unpack(str[start:end])
      start = end
      end += 12
      self.Control_Command.Reference_State.acceleration_ref = _get_struct_3f().unpack(str[start:end])
      _x = self
      start = end
      end += 21
      (_x.Control_Command.Reference_State.Yaw_Rate_Mode, _x.Control_Command.Reference_State.yaw_ref, _x.Control_Command.Reference_State.yaw_rate_ref, _x.Control_Output.header.seq, _x.Control_Output.header.stamp.secs, _x.Control_Output.header.stamp.nsecs,) = _get_struct_B2f3I().unpack(str[start:end])
      self.Control_Command.Reference_State.Yaw_Rate_Mode = bool(self.Control_Command.Reference_State.Yaw_Rate_Mode)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.Control_Output.header.frame_id = str[start:end].decode('utf-8', 'rosmsg')
      else:
        self.Control_Output.header.frame_id = str[start:end]
      start = end
      end += 12
      self.Control_Output.Thrust = _get_struct_3f().unpack(str[start:end])
      start = end
      end += 12
      self.Control_Output.Throttle = _get_struct_3f().unpack(str[start:end])
      start = end
      end += 12
      self.Control_Output.u_l = _get_struct_3f().unpack(str[start:end])
      start = end
      end += 12
      self.Control_Output.u_d = _get_struct_3f().unpack(str[start:end])
      start = end
      end += 12
      self.Control_Output.NE = _get_struct_3f().unpack(str[start:end])
      _x = self
      start = end
      end += 12
      (_x.Attitude_Reference.header.seq, _x.Attitude_Reference.header.stamp.secs, _x.Attitude_Reference.header.stamp.nsecs,) = _get_struct_3I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.Attitude_Reference.header.frame_id = str[start:end].decode('utf-8', 'rosmsg')
      else:
        self.Attitude_Reference.header.frame_id = str[start:end]
      start = end
      end += 12
      self.Attitude_Reference.throttle_sp = _get_struct_3f().unpack(str[start:end])
      start = end
      end += 4
      (self.Attitude_Reference.desired_throttle,) = _get_struct_f().unpack(str[start:end])
      start = end
      end += 12
      self.Attitude_Reference.desired_attitude = _get_struct_3f().unpack(str[start:end])
      _x = self
      start = end
      end += 44
      (_x.Attitude_Reference.desired_att_q.x, _x.Attitude_Reference.desired_att_q.y, _x.Attitude_Reference.desired_att_q.z, _x.Attitude_Reference.desired_att_q.w, _x.ref_pose.header.seq, _x.ref_pose.header.stamp.secs, _x.ref_pose.header.stamp.nsecs,) = _get_struct_4d3I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.ref_pose.header.frame_id = str[start:end].decode('utf-8', 'rosmsg')
      else:
        self.ref_pose.header.frame_id = str[start:end]
      _x = self
      start = end
      end += 56
      (_x.ref_pose.pose.position.x, _x.ref_pose.pose.position.y, _x.ref_pose.pose.position.z, _x.ref_pose.pose.orientation.x, _x.ref_pose.pose.orientation.y, _x.ref_pose.pose.orientation.z, _x.ref_pose.pose.orientation.w,) = _get_struct_7d().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_get_struct_3I().pack(_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs))
      _x = self.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
      _x = self
      buff.write(_get_struct_fi3I().pack(_x.time, _x.control_type, _x.Drone_State.header.seq, _x.Drone_State.header.stamp.secs, _x.Drone_State.header.stamp.nsecs))
      _x = self.Drone_State.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
      _x = self
      buff.write(_get_struct_3B().pack(_x.Drone_State.connected, _x.Drone_State.armed, _x.Drone_State.landed))
      _x = self.Drone_State.mode
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
      _x = self.Drone_State.time_from_start
      buff.write(_get_struct_f().pack(_x))
      buff.write(self.Drone_State.position.tostring())
      _x = self.Drone_State.rel_alt
      buff.write(_get_struct_f().pack(_x))
      buff.write(self.Drone_State.velocity.tostring())
      buff.write(self.Drone_State.attitude.tostring())
      _x = self
      buff.write(_get_struct_4d().pack(_x.Drone_State.attitude_q.x, _x.Drone_State.attitude_q.y, _x.Drone_State.attitude_q.z, _x.Drone_State.attitude_q.w))
      buff.write(self.Drone_State.attitude_rate.tostring())
      _x = self
      buff.write(_get_struct_3I().pack(_x.Control_Command.header.seq, _x.Control_Command.header.stamp.secs, _x.Control_Command.header.stamp.nsecs))
      _x = self.Control_Command.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
      _x = self.Control_Command.Command_ID
      buff.write(_get_struct_I().pack(_x))
      _x = self.Control_Command.source
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
      _x = self
      buff.write(_get_struct_B3I().pack(_x.Control_Command.Mode, _x.Control_Command.Reference_State.header.seq, _x.Control_Command.Reference_State.header.stamp.secs, _x.Control_Command.Reference_State.header.stamp.nsecs))
      _x = self.Control_Command.Reference_State.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
      _x = self
      buff.write(_get_struct_2Bf().pack(_x.Control_Command.Reference_State.Move_mode, _x.Control_Command.Reference_State.Move_frame, _x.Control_Command.Reference_State.time_from_start))
      buff.write(self.Control_Command.Reference_State.position_ref.tostring())
      buff.write(self.Control_Command.Reference_State.velocity_ref.tostring())
      buff.write(self.Control_Command.Reference_State.acceleration_ref.tostring())
      _x = self
      buff.write(_get_struct_B2f3I().pack(_x.Control_Command.Reference_State.Yaw_Rate_Mode, _x.Control_Command.Reference_State.yaw_ref, _x.Control_Command.Reference_State.yaw_rate_ref, _x.Control_Output.header.seq, _x.Control_Output.header.stamp.secs, _x.Control_Output.header.stamp.nsecs))
      _x = self.Control_Output.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
      buff.write(self.Control_Output.Thrust.tostring())
      buff.write(self.Control_Output.Throttle.tostring())
      buff.write(self.Control_Output.u_l.tostring())
      buff.write(self.Control_Output.u_d.tostring())
      buff.write(self.Control_Output.NE.tostring())
      _x = self
      buff.write(_get_struct_3I().pack(_x.Attitude_Reference.header.seq, _x.Attitude_Reference.header.stamp.secs, _x.Attitude_Reference.header.stamp.nsecs))
      _x = self.Attitude_Reference.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
      buff.write(self.Attitude_Reference.throttle_sp.tostring())
      _x = self.Attitude_Reference.desired_throttle
      buff.write(_get_struct_f().pack(_x))
      buff.write(self.Attitude_Reference.desired_attitude.tostring())
      _x = self
      buff.write(_get_struct_4d3I().pack(_x.Attitude_Reference.desired_att_q.x, _x.Attitude_Reference.desired_att_q.y, _x.Attitude_Reference.desired_att_q.z, _x.Attitude_Reference.desired_att_q.w, _x.ref_pose.header.seq, _x.ref_pose.header.stamp.secs, _x.ref_pose.header.stamp.nsecs))
      _x = self.ref_pose.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
      _x = self
      buff.write(_get_struct_7d().pack(_x.ref_pose.pose.position.x, _x.ref_pose.pose.position.y, _x.ref_pose.pose.position.z, _x.ref_pose.pose.orientation.x, _x.ref_pose.pose.orientation.y, _x.ref_pose.pose.orientation.z, _x.ref_pose.pose.orientation.w))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    if python3:
      codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      if self.header is None:
        self.header = std_msgs.msg.Header()
      if self.Drone_State is None:
        self.Drone_State = offb_msgs.msg.DroneState()
      if self.Control_Command is None:
        self.Control_Command = offb_msgs.msg.ControlCommand()
      if self.Control_Output is None:
        self.Control_Output = offb_msgs.msg.ControlOutput()
      if self.Attitude_Reference is None:
        self.Attitude_Reference = offb_msgs.msg.AttitudeReference()
      if self.ref_pose is None:
        self.ref_pose = geometry_msgs.msg.PoseStamped()
      end = 0
      _x = self
      start = end
      end += 12
      (_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs,) = _get_struct_3I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.header.frame_id = str[start:end].decode('utf-8', 'rosmsg')
      else:
        self.header.frame_id = str[start:end]
      _x = self
      start = end
      end += 20
      (_x.time, _x.control_type, _x.Drone_State.header.seq, _x.Drone_State.header.stamp.secs, _x.Drone_State.header.stamp.nsecs,) = _get_struct_fi3I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.Drone_State.header.frame_id = str[start:end].decode('utf-8', 'rosmsg')
      else:
        self.Drone_State.header.frame_id = str[start:end]
      _x = self
      start = end
      end += 3
      (_x.Drone_State.connected, _x.Drone_State.armed, _x.Drone_State.landed,) = _get_struct_3B().unpack(str[start:end])
      self.Drone_State.connected = bool(self.Drone_State.connected)
      self.Drone_State.armed = bool(self.Drone_State.armed)
      self.Drone_State.landed = bool(self.Drone_State.landed)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.Drone_State.mode = str[start:end].decode('utf-8', 'rosmsg')
      else:
        self.Drone_State.mode = str[start:end]
      start = end
      end += 4
      (self.Drone_State.time_from_start,) = _get_struct_f().unpack(str[start:end])
      start = end
      end += 12
      self.Drone_State.position = numpy.frombuffer(str[start:end], dtype=numpy.float32, count=3)
      start = end
      end += 4
      (self.Drone_State.rel_alt,) = _get_struct_f().unpack(str[start:end])
      start = end
      end += 12
      self.Drone_State.velocity = numpy.frombuffer(str[start:end], dtype=numpy.float32, count=3)
      start = end
      end += 12
      self.Drone_State.attitude = numpy.frombuffer(str[start:end], dtype=numpy.float32, count=3)
      _x = self
      start = end
      end += 32
      (_x.Drone_State.attitude_q.x, _x.Drone_State.attitude_q.y, _x.Drone_State.attitude_q.z, _x.Drone_State.attitude_q.w,) = _get_struct_4d().unpack(str[start:end])
      start = end
      end += 12
      self.Drone_State.attitude_rate = numpy.frombuffer(str[start:end], dtype=numpy.float32, count=3)
      _x = self
      start = end
      end += 12
      (_x.Control_Command.header.seq, _x.Control_Command.header.stamp.secs, _x.Control_Command.header.stamp.nsecs,) = _get_struct_3I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.Control_Command.header.frame_id = str[start:end].decode('utf-8', 'rosmsg')
      else:
        self.Control_Command.header.frame_id = str[start:end]
      start = end
      end += 4
      (self.Control_Command.Command_ID,) = _get_struct_I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.Control_Command.source = str[start:end].decode('utf-8', 'rosmsg')
      else:
        self.Control_Command.source = str[start:end]
      _x = self
      start = end
      end += 13
      (_x.Control_Command.Mode, _x.Control_Command.Reference_State.header.seq, _x.Control_Command.Reference_State.header.stamp.secs, _x.Control_Command.Reference_State.header.stamp.nsecs,) = _get_struct_B3I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.Control_Command.Reference_State.header.frame_id = str[start:end].decode('utf-8', 'rosmsg')
      else:
        self.Control_Command.Reference_State.header.frame_id = str[start:end]
      _x = self
      start = end
      end += 6
      (_x.Control_Command.Reference_State.Move_mode, _x.Control_Command.Reference_State.Move_frame, _x.Control_Command.Reference_State.time_from_start,) = _get_struct_2Bf().unpack(str[start:end])
      start = end
      end += 12
      self.Control_Command.Reference_State.position_ref = numpy.frombuffer(str[start:end], dtype=numpy.float32, count=3)
      start = end
      end += 12
      self.Control_Command.Reference_State.velocity_ref = numpy.frombuffer(str[start:end], dtype=numpy.float32, count=3)
      start = end
      end += 12
      self.Control_Command.Reference_State.acceleration_ref = numpy.frombuffer(str[start:end], dtype=numpy.float32, count=3)
      _x = self
      start = end
      end += 21
      (_x.Control_Command.Reference_State.Yaw_Rate_Mode, _x.Control_Command.Reference_State.yaw_ref, _x.Control_Command.Reference_State.yaw_rate_ref, _x.Control_Output.header.seq, _x.Control_Output.header.stamp.secs, _x.Control_Output.header.stamp.nsecs,) = _get_struct_B2f3I().unpack(str[start:end])
      self.Control_Command.Reference_State.Yaw_Rate_Mode = bool(self.Control_Command.Reference_State.Yaw_Rate_Mode)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.Control_Output.header.frame_id = str[start:end].decode('utf-8', 'rosmsg')
      else:
        self.Control_Output.header.frame_id = str[start:end]
      start = end
      end += 12
      self.Control_Output.Thrust = numpy.frombuffer(str[start:end], dtype=numpy.float32, count=3)
      start = end
      end += 12
      self.Control_Output.Throttle = numpy.frombuffer(str[start:end], dtype=numpy.float32, count=3)
      start = end
      end += 12
      self.Control_Output.u_l = numpy.frombuffer(str[start:end], dtype=numpy.float32, count=3)
      start = end
      end += 12
      self.Control_Output.u_d = numpy.frombuffer(str[start:end], dtype=numpy.float32, count=3)
      start = end
      end += 12
      self.Control_Output.NE = numpy.frombuffer(str[start:end], dtype=numpy.float32, count=3)
      _x = self
      start = end
      end += 12
      (_x.Attitude_Reference.header.seq, _x.Attitude_Reference.header.stamp.secs, _x.Attitude_Reference.header.stamp.nsecs,) = _get_struct_3I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.Attitude_Reference.header.frame_id = str[start:end].decode('utf-8', 'rosmsg')
      else:
        self.Attitude_Reference.header.frame_id = str[start:end]
      start = end
      end += 12
      self.Attitude_Reference.throttle_sp = numpy.frombuffer(str[start:end], dtype=numpy.float32, count=3)
      start = end
      end += 4
      (self.Attitude_Reference.desired_throttle,) = _get_struct_f().unpack(str[start:end])
      start = end
      end += 12
      self.Attitude_Reference.desired_attitude = numpy.frombuffer(str[start:end], dtype=numpy.float32, count=3)
      _x = self
      start = end
      end += 44
      (_x.Attitude_Reference.desired_att_q.x, _x.Attitude_Reference.desired_att_q.y, _x.Attitude_Reference.desired_att_q.z, _x.Attitude_Reference.desired_att_q.w, _x.ref_pose.header.seq, _x.ref_pose.header.stamp.secs, _x.ref_pose.header.stamp.nsecs,) = _get_struct_4d3I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.ref_pose.header.frame_id = str[start:end].decode('utf-8', 'rosmsg')
      else:
        self.ref_pose.header.frame_id = str[start:end]
      _x = self
      start = end
      end += 56
      (_x.ref_pose.pose.position.x, _x.ref_pose.pose.position.y, _x.ref_pose.pose.position.z, _x.ref_pose.pose.orientation.x, _x.ref_pose.pose.orientation.y, _x.ref_pose.pose.orientation.z, _x.ref_pose.pose.orientation.w,) = _get_struct_7d().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_2Bf = None
def _get_struct_2Bf():
    global _struct_2Bf
    if _struct_2Bf is None:
        _struct_2Bf = struct.Struct("<2Bf")
    return _struct_2Bf
_struct_3B = None
def _get_struct_3B():
    global _struct_3B
    if _struct_3B is None:
        _struct_3B = struct.Struct("<3B")
    return _struct_3B
_struct_3I = None
def _get_struct_3I():
    global _struct_3I
    if _struct_3I is None:
        _struct_3I = struct.Struct("<3I")
    return _struct_3I
_struct_3f = None
def _get_struct_3f():
    global _struct_3f
    if _struct_3f is None:
        _struct_3f = struct.Struct("<3f")
    return _struct_3f
_struct_4d = None
def _get_struct_4d():
    global _struct_4d
    if _struct_4d is None:
        _struct_4d = struct.Struct("<4d")
    return _struct_4d
_struct_4d3I = None
def _get_struct_4d3I():
    global _struct_4d3I
    if _struct_4d3I is None:
        _struct_4d3I = struct.Struct("<4d3I")
    return _struct_4d3I
_struct_7d = None
def _get_struct_7d():
    global _struct_7d
    if _struct_7d is None:
        _struct_7d = struct.Struct("<7d")
    return _struct_7d
_struct_B2f3I = None
def _get_struct_B2f3I():
    global _struct_B2f3I
    if _struct_B2f3I is None:
        _struct_B2f3I = struct.Struct("<B2f3I")
    return _struct_B2f3I
_struct_B3I = None
def _get_struct_B3I():
    global _struct_B3I
    if _struct_B3I is None:
        _struct_B3I = struct.Struct("<B3I")
    return _struct_B3I
_struct_f = None
def _get_struct_f():
    global _struct_f
    if _struct_f is None:
        _struct_f = struct.Struct("<f")
    return _struct_f
_struct_fi3I = None
def _get_struct_fi3I():
    global _struct_fi3I
    if _struct_fi3I is None:
        _struct_fi3I = struct.Struct("<fi3I")
    return _struct_fi3I