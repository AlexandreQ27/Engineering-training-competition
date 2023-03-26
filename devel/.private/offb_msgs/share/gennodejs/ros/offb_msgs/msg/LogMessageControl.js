// Auto-generated. Do not edit!

// (in-package offb_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let DroneState = require('./DroneState.js');
let ControlCommand = require('./ControlCommand.js');
let ControlOutput = require('./ControlOutput.js');
let AttitudeReference = require('./AttitudeReference.js');
let geometry_msgs = _finder('geometry_msgs');
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class LogMessageControl {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.time = null;
      this.control_type = null;
      this.Drone_State = null;
      this.Control_Command = null;
      this.Control_Output = null;
      this.Attitude_Reference = null;
      this.ref_pose = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('time')) {
        this.time = initObj.time
      }
      else {
        this.time = 0.0;
      }
      if (initObj.hasOwnProperty('control_type')) {
        this.control_type = initObj.control_type
      }
      else {
        this.control_type = 0;
      }
      if (initObj.hasOwnProperty('Drone_State')) {
        this.Drone_State = initObj.Drone_State
      }
      else {
        this.Drone_State = new DroneState();
      }
      if (initObj.hasOwnProperty('Control_Command')) {
        this.Control_Command = initObj.Control_Command
      }
      else {
        this.Control_Command = new ControlCommand();
      }
      if (initObj.hasOwnProperty('Control_Output')) {
        this.Control_Output = initObj.Control_Output
      }
      else {
        this.Control_Output = new ControlOutput();
      }
      if (initObj.hasOwnProperty('Attitude_Reference')) {
        this.Attitude_Reference = initObj.Attitude_Reference
      }
      else {
        this.Attitude_Reference = new AttitudeReference();
      }
      if (initObj.hasOwnProperty('ref_pose')) {
        this.ref_pose = initObj.ref_pose
      }
      else {
        this.ref_pose = new geometry_msgs.msg.PoseStamped();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type LogMessageControl
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [time]
    bufferOffset = _serializer.float32(obj.time, buffer, bufferOffset);
    // Serialize message field [control_type]
    bufferOffset = _serializer.int32(obj.control_type, buffer, bufferOffset);
    // Serialize message field [Drone_State]
    bufferOffset = DroneState.serialize(obj.Drone_State, buffer, bufferOffset);
    // Serialize message field [Control_Command]
    bufferOffset = ControlCommand.serialize(obj.Control_Command, buffer, bufferOffset);
    // Serialize message field [Control_Output]
    bufferOffset = ControlOutput.serialize(obj.Control_Output, buffer, bufferOffset);
    // Serialize message field [Attitude_Reference]
    bufferOffset = AttitudeReference.serialize(obj.Attitude_Reference, buffer, bufferOffset);
    // Serialize message field [ref_pose]
    bufferOffset = geometry_msgs.msg.PoseStamped.serialize(obj.ref_pose, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type LogMessageControl
    let len;
    let data = new LogMessageControl(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [time]
    data.time = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [control_type]
    data.control_type = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [Drone_State]
    data.Drone_State = DroneState.deserialize(buffer, bufferOffset);
    // Deserialize message field [Control_Command]
    data.Control_Command = ControlCommand.deserialize(buffer, bufferOffset);
    // Deserialize message field [Control_Output]
    data.Control_Output = ControlOutput.deserialize(buffer, bufferOffset);
    // Deserialize message field [Attitude_Reference]
    data.Attitude_Reference = AttitudeReference.deserialize(buffer, bufferOffset);
    // Deserialize message field [ref_pose]
    data.ref_pose = geometry_msgs.msg.PoseStamped.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    length += DroneState.getMessageSize(object.Drone_State);
    length += ControlCommand.getMessageSize(object.Control_Command);
    length += ControlOutput.getMessageSize(object.Control_Output);
    length += AttitudeReference.getMessageSize(object.Attitude_Reference);
    length += geometry_msgs.msg.PoseStamped.getMessageSize(object.ref_pose);
    return length + 8;
  }

  static datatype() {
    // Returns string type for a message object
    return 'offb_msgs/LogMessageControl';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '5781c2d06de4d7c7a326052cb8307187';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    std_msgs/Header header
    
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
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new LogMessageControl(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.time !== undefined) {
      resolved.time = msg.time;
    }
    else {
      resolved.time = 0.0
    }

    if (msg.control_type !== undefined) {
      resolved.control_type = msg.control_type;
    }
    else {
      resolved.control_type = 0
    }

    if (msg.Drone_State !== undefined) {
      resolved.Drone_State = DroneState.Resolve(msg.Drone_State)
    }
    else {
      resolved.Drone_State = new DroneState()
    }

    if (msg.Control_Command !== undefined) {
      resolved.Control_Command = ControlCommand.Resolve(msg.Control_Command)
    }
    else {
      resolved.Control_Command = new ControlCommand()
    }

    if (msg.Control_Output !== undefined) {
      resolved.Control_Output = ControlOutput.Resolve(msg.Control_Output)
    }
    else {
      resolved.Control_Output = new ControlOutput()
    }

    if (msg.Attitude_Reference !== undefined) {
      resolved.Attitude_Reference = AttitudeReference.Resolve(msg.Attitude_Reference)
    }
    else {
      resolved.Attitude_Reference = new AttitudeReference()
    }

    if (msg.ref_pose !== undefined) {
      resolved.ref_pose = geometry_msgs.msg.PoseStamped.Resolve(msg.ref_pose)
    }
    else {
      resolved.ref_pose = new geometry_msgs.msg.PoseStamped()
    }

    return resolved;
    }
};

module.exports = LogMessageControl;
