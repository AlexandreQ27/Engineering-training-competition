# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from offb_msgs/SwarmCommand.msg. Do not edit."""
import codecs
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import std_msgs.msg

class SwarmCommand(genpy.Message):
  _md5sum = "f0e68f41f7d26607969a5fba3d80e691"
  _type = "offb_msgs/SwarmCommand"
  _has_header = True  # flag to mark the presence of a Header object
  _full_text = """std_msgs/Header header

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
"""
  # Pseudo-constants
  Idle = 0
  Takeoff = 1
  Hold = 2
  Land = 3
  Disarm = 4
  Position_Control = 5
  Velocity_Control = 6
  Accel_Control = 7
  Move = 8
  User_Mode1 = 9
  One_column = 0
  Triangle = 1
  Square = 2
  Circular = 3
  XYZ_POS = 0
  XY_POS_Z_VEL = 1
  XY_VEL_Z_POS = 2
  XYZ_VEL = 3
  XYZ_ACC = 4
  TRAJECTORY = 5

  __slots__ = ['header','Command_ID','source','Mode','swarm_shape','Move_mode','swarm_size','position_ref','velocity_ref','yaw_ref']
  _slot_types = ['std_msgs/Header','uint32','string','uint8','uint8','uint8','float32','float32[3]','float32[3]','float32']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       header,Command_ID,source,Mode,swarm_shape,Move_mode,swarm_size,position_ref,velocity_ref,yaw_ref

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(SwarmCommand, self).__init__(*args, **kwds)
      # message fields cannot be None, assign default values for those that are
      if self.header is None:
        self.header = std_msgs.msg.Header()
      if self.Command_ID is None:
        self.Command_ID = 0
      if self.source is None:
        self.source = ''
      if self.Mode is None:
        self.Mode = 0
      if self.swarm_shape is None:
        self.swarm_shape = 0
      if self.Move_mode is None:
        self.Move_mode = 0
      if self.swarm_size is None:
        self.swarm_size = 0.
      if self.position_ref is None:
        self.position_ref = [0.] * 3
      if self.velocity_ref is None:
        self.velocity_ref = [0.] * 3
      if self.yaw_ref is None:
        self.yaw_ref = 0.
    else:
      self.header = std_msgs.msg.Header()
      self.Command_ID = 0
      self.source = ''
      self.Mode = 0
      self.swarm_shape = 0
      self.Move_mode = 0
      self.swarm_size = 0.
      self.position_ref = [0.] * 3
      self.velocity_ref = [0.] * 3
      self.yaw_ref = 0.

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
      _x = self.Command_ID
      buff.write(_get_struct_I().pack(_x))
      _x = self.source
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
      _x = self
      buff.write(_get_struct_3Bf().pack(_x.Mode, _x.swarm_shape, _x.Move_mode, _x.swarm_size))
      buff.write(_get_struct_3f().pack(*self.position_ref))
      buff.write(_get_struct_3f().pack(*self.velocity_ref))
      _x = self.yaw_ref
      buff.write(_get_struct_f().pack(_x))
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
      start = end
      end += 4
      (self.Command_ID,) = _get_struct_I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.source = str[start:end].decode('utf-8', 'rosmsg')
      else:
        self.source = str[start:end]
      _x = self
      start = end
      end += 7
      (_x.Mode, _x.swarm_shape, _x.Move_mode, _x.swarm_size,) = _get_struct_3Bf().unpack(str[start:end])
      start = end
      end += 12
      self.position_ref = _get_struct_3f().unpack(str[start:end])
      start = end
      end += 12
      self.velocity_ref = _get_struct_3f().unpack(str[start:end])
      start = end
      end += 4
      (self.yaw_ref,) = _get_struct_f().unpack(str[start:end])
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
      _x = self.Command_ID
      buff.write(_get_struct_I().pack(_x))
      _x = self.source
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
      _x = self
      buff.write(_get_struct_3Bf().pack(_x.Mode, _x.swarm_shape, _x.Move_mode, _x.swarm_size))
      buff.write(self.position_ref.tostring())
      buff.write(self.velocity_ref.tostring())
      _x = self.yaw_ref
      buff.write(_get_struct_f().pack(_x))
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
      start = end
      end += 4
      (self.Command_ID,) = _get_struct_I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.source = str[start:end].decode('utf-8', 'rosmsg')
      else:
        self.source = str[start:end]
      _x = self
      start = end
      end += 7
      (_x.Mode, _x.swarm_shape, _x.Move_mode, _x.swarm_size,) = _get_struct_3Bf().unpack(str[start:end])
      start = end
      end += 12
      self.position_ref = numpy.frombuffer(str[start:end], dtype=numpy.float32, count=3)
      start = end
      end += 12
      self.velocity_ref = numpy.frombuffer(str[start:end], dtype=numpy.float32, count=3)
      start = end
      end += 4
      (self.yaw_ref,) = _get_struct_f().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_3Bf = None
def _get_struct_3Bf():
    global _struct_3Bf
    if _struct_3Bf is None:
        _struct_3Bf = struct.Struct("<3Bf")
    return _struct_3Bf
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
_struct_f = None
def _get_struct_f():
    global _struct_f
    if _struct_f is None:
        _struct_f = struct.Struct("<f")
    return _struct_f