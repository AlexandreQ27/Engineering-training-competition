;; Auto-generated. Do not edit!


(when (boundp 'offb::Circle)
  (if (not (find-package "OFFB"))
    (make-package "OFFB"))
  (shadow 'Circle (find-package "OFFB")))
(unless (find-package "OFFB::CIRCLE")
  (make-package "OFFB::CIRCLE"))

(in-package "ROS")
;;//! \htmlinclude Circle.msg.html


(defclass offb::Circle
  :super ros::object
  :slots (_circle_x _circle_y ))

(defmethod offb::Circle
  (:init
   (&key
    ((:circle_x __circle_x) 0.0)
    ((:circle_y __circle_y) 0.0)
    )
   (send-super :init)
   (setq _circle_x (float __circle_x))
   (setq _circle_y (float __circle_y))
   self)
  (:circle_x
   (&optional __circle_x)
   (if __circle_x (setq _circle_x __circle_x)) _circle_x)
  (:circle_y
   (&optional __circle_y)
   (if __circle_y (setq _circle_y __circle_y)) _circle_y)
  (:serialization-length
   ()
   (+
    ;; float32 _circle_x
    4
    ;; float32 _circle_y
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _circle_x
       (sys::poke _circle_x (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _circle_y
       (sys::poke _circle_y (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _circle_x
     (setq _circle_x (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _circle_y
     (setq _circle_y (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get offb::Circle :md5sum-) "aab94b94318d02875f549111ac08c6be")
(setf (get offb::Circle :datatype-) "offb/Circle")
(setf (get offb::Circle :definition-)
      "float32 circle_x 
float32 circle_y
")



(provide :offb/Circle "aab94b94318d02875f549111ac08c6be")


