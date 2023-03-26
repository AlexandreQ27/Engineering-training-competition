; Auto-generated. Do not edit!


(cl:in-package offb_msgs-msg)


;//! \htmlinclude Formation.msg.html

(cl:defclass <Formation> (roslisp-msg-protocol:ros-message)
  ((type
    :reader type
    :initarg :type
    :type cl:fixnum
    :initform 0))
)

(cl:defclass Formation (<Formation>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Formation>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Formation)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name offb_msgs-msg:<Formation> is deprecated: use offb_msgs-msg:Formation instead.")))

(cl:ensure-generic-function 'type-val :lambda-list '(m))
(cl:defmethod type-val ((m <Formation>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader offb_msgs-msg:type-val is deprecated.  Use offb_msgs-msg:type instead.")
  (type m))
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql '<Formation>)))
    "Constants for message type '<Formation>"
  '((:HORIZONTAL . 0)
    (:TRIANGEL . 1)
    (:DIAMOND . 2)
    (:DIAMOND_STAGE_1 . 3))
)
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql 'Formation)))
    "Constants for message type 'Formation"
  '((:HORIZONTAL . 0)
    (:TRIANGEL . 1)
    (:DIAMOND . 2)
    (:DIAMOND_STAGE_1 . 3))
)
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Formation>) ostream)
  "Serializes a message object of type '<Formation>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'type)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Formation>) istream)
  "Deserializes a message object of type '<Formation>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'type)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Formation>)))
  "Returns string type for a message object of type '<Formation>"
  "offb_msgs/Formation")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Formation)))
  "Returns string type for a message object of type 'Formation"
  "offb_msgs/Formation")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Formation>)))
  "Returns md5sum for a message object of type '<Formation>"
  "47f40aa4cf085460be9489e1f3e02ea5")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Formation)))
  "Returns md5sum for a message object of type 'Formation"
  "47f40aa4cf085460be9489e1f3e02ea5")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Formation>)))
  "Returns full string definition for message of type '<Formation>"
  (cl:format cl:nil "uint8 HORIZONTAL=0~%uint8 TRIANGEL=1~%uint8 DIAMOND=2~%uint8 DIAMOND_STAGE_1=3~%~%uint8 type~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Formation)))
  "Returns full string definition for message of type 'Formation"
  (cl:format cl:nil "uint8 HORIZONTAL=0~%uint8 TRIANGEL=1~%uint8 DIAMOND=2~%uint8 DIAMOND_STAGE_1=3~%~%uint8 type~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Formation>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Formation>))
  "Converts a ROS message object to a list"
  (cl:list 'Formation
    (cl:cons ':type (type msg))
))
