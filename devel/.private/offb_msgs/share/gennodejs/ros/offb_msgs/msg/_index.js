
"use strict";

let LogMessagePlanning = require('./LogMessagePlanning.js');
let LogMessageDetection = require('./LogMessageDetection.js');
let ArucoInfo = require('./ArucoInfo.js');
let ServoNum = require('./ServoNum.js');
let Formation = require('./Formation.js');
let BoundingBox = require('./BoundingBox.js');
let MultiArucoInfo = require('./MultiArucoInfo.js');
let DetectionInfo = require('./DetectionInfo.js');
let SwarmCommand = require('./SwarmCommand.js');
let AttitudeReference = require('./AttitudeReference.js');
let MultiDetectionInfo = require('./MultiDetectionInfo.js');
let ControlCommand = require('./ControlCommand.js');
let LogMessage = require('./LogMessage.js');
let DroneState = require('./DroneState.js');
let ControlOutput = require('./ControlOutput.js');
let Message = require('./Message.js');
let PositionReference = require('./PositionReference.js');
let LogMessageControl = require('./LogMessageControl.js');
let IndoorSearch = require('./IndoorSearch.js');
let BoundingBoxes = require('./BoundingBoxes.js');

module.exports = {
  LogMessagePlanning: LogMessagePlanning,
  LogMessageDetection: LogMessageDetection,
  ArucoInfo: ArucoInfo,
  ServoNum: ServoNum,
  Formation: Formation,
  BoundingBox: BoundingBox,
  MultiArucoInfo: MultiArucoInfo,
  DetectionInfo: DetectionInfo,
  SwarmCommand: SwarmCommand,
  AttitudeReference: AttitudeReference,
  MultiDetectionInfo: MultiDetectionInfo,
  ControlCommand: ControlCommand,
  LogMessage: LogMessage,
  DroneState: DroneState,
  ControlOutput: ControlOutput,
  Message: Message,
  PositionReference: PositionReference,
  LogMessageControl: LogMessageControl,
  IndoorSearch: IndoorSearch,
  BoundingBoxes: BoundingBoxes,
};
