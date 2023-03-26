; Auto-generated. Do not edit!


(cl:in-package offb_msgs-msg)


;//! \htmlinclude ServoNum.msg.html

(cl:defclass <ServoNum> (roslisp-msg-protocol:ros-message)
  ((num
    :reader num
    :initarg :num
    :type cl:fixnum
    :initform 0))
)

(cl:defclass ServoNum (<ServoNum>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ServoNum>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ServoNum)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name offb_msgs-msg:<ServoNum> is deprecated: use offb_msgs-msg:ServoNum instead.")))

(cl:ensure-generic-function 'num-val :lambda-list '(m))
(cl:defmethod num-val ((m <ServoNum>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader offb_msgs-msg:num-val is deprecated.  Use offb_msgs-msg:num instead.")
  (num m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ServoNum>) ostream)
  "Serializes a message object of type '<ServoNum>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'num)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'num)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ServoNum>) istream)
  "Deserializes a message object of type '<ServoNum>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'num)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'num)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ServoNum>)))
  "Returns string type for a message object of type '<ServoNum>"
  "offb_msgs/ServoNum")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ServoNum)))
  "Returns string type for a message object of type 'ServoNum"
  "offb_msgs/ServoNum")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ServoNum>)))
  "Returns md5sum for a message object of type '<ServoNum>"
  "0285aea93c08847f409c58db5e8d9137")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ServoNum)))
  "Returns md5sum for a message object of type 'ServoNum"
  "0285aea93c08847f409c58db5e8d9137")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ServoNum>)))
  "Returns full string definition for message of type '<ServoNum>"
  (cl:format cl:nil "uint16 num~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ServoNum)))
  "Returns full string definition for message of type 'ServoNum"
  (cl:format cl:nil "uint16 num~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ServoNum>))
  (cl:+ 0
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ServoNum>))
  "Converts a ROS message object to a list"
  (cl:list 'ServoNum
    (cl:cons ':num (num msg))
))
