// Auto-generated. Do not edit!

// (in-package offb.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class Circle {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.circle_x = null;
      this.circle_y = null;
    }
    else {
      if (initObj.hasOwnProperty('circle_x')) {
        this.circle_x = initObj.circle_x
      }
      else {
        this.circle_x = 0.0;
      }
      if (initObj.hasOwnProperty('circle_y')) {
        this.circle_y = initObj.circle_y
      }
      else {
        this.circle_y = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type Circle
    // Serialize message field [circle_x]
    bufferOffset = _serializer.float32(obj.circle_x, buffer, bufferOffset);
    // Serialize message field [circle_y]
    bufferOffset = _serializer.float32(obj.circle_y, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Circle
    let len;
    let data = new Circle(null);
    // Deserialize message field [circle_x]
    data.circle_x = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [circle_y]
    data.circle_y = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 8;
  }

  static datatype() {
    // Returns string type for a message object
    return 'offb/Circle';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'aab94b94318d02875f549111ac08c6be';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float32 circle_x 
    float32 circle_y
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new Circle(null);
    if (msg.circle_x !== undefined) {
      resolved.circle_x = msg.circle_x;
    }
    else {
      resolved.circle_x = 0.0
    }

    if (msg.circle_y !== undefined) {
      resolved.circle_y = msg.circle_y;
    }
    else {
      resolved.circle_y = 0.0
    }

    return resolved;
    }
};

module.exports = Circle;
