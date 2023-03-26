;; Auto-generated. Do not edit!


(when (boundp 'offb_msgs::ServoNum)
  (if (not (find-package "OFFB_MSGS"))
    (make-package "OFFB_MSGS"))
  (shadow 'ServoNum (find-package "OFFB_MSGS")))
(unless (find-package "OFFB_MSGS::SERVONUM")
  (make-package "OFFB_MSGS::SERVONUM"))

(in-package "ROS")
;;//! \htmlinclude ServoNum.msg.html


(defclass offb_msgs::ServoNum
  :super ros::object
  :slots (_num ))

(defmethod offb_msgs::ServoNum
  (:init
   (&key
    ((:num __num) 0)
    )
   (send-super :init)
   (setq _num (round __num))
   self)
  (:num
   (&optional __num)
   (if __num (setq _num __num)) _num)
  (:serialization-length
   ()
   (+
    ;; uint16 _num
    2
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint16 _num
       (write-word _num s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint16 _num
     (setq _num (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;;
   self)
  )

(setf (get offb_msgs::ServoNum :md5sum-) "0285aea93c08847f409c58db5e8d9137")
(setf (get offb_msgs::ServoNum :datatype-) "offb_msgs/ServoNum")
(setf (get offb_msgs::ServoNum :definition-)
      "uint16 num

")



(provide :offb_msgs/ServoNum "0285aea93c08847f409c58db5e8d9137")


