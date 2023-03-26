cmake_minimum_required(VERSION 2.8.3)
project(offb)

## Compile as C++11, supported in ROS Kinetic and newer
 add_compile_options(-std=c++11)
set(OpenCV_DIR /usr/share/OpenCV/) #新增
find_package(catkin REQUIRED COMPONENTS
  message_generation  
  roscpp
  geometry_msgs
  sensor_msgs
  mavros
  nav_msgs
  std_msgs
  std_srvs
  tf2_ros
  tf2_eigen
  mavros_msgs
  actionlib
  trajectory_msgs
  pluginlib
  offb_msgs
  serial
#以下为新增
  cv_bridge
  image_transport
  message_generation
  OpenCV
)
find_package(cmake_modules REQUIRED)
find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})
add_definitions(${EIGEN_DEFINITIONS})
#以下为新增
## Generate messages in the 'msg' folder
add_message_files(
   FILES 
   Circle.msg
#   Message1.msg
#   Message2.msg
 )

#以下为新增
## Generate added messages and services with any dependencies listed here
 generate_messages(
   DEPENDENCIES
#   geometry_msgs#   nav_msgs#   sensor_msgs
   std_msgs
#   trajectory_msgs
 )

catkin_package(
 INCLUDE_DIRS include
#  LIBRARIES vision_to_mavros
#  CATKIN_DEPENDS roscpp rospy tf
#  DEPENDS system_lib
)



###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}#新增
)

add_executable(offb_node src/offb.cpp)
target_link_libraries(offb_node ${catkin_LIBRARIES})

add_executable(node_flyput_node src/node_flyput.cpp)
target_link_libraries(node_flyput_node ${catkin_LIBRARIES})

add_executable(node_flyput_fixed_node src/node_flyput_fixed.cpp)
target_link_libraries(node_flyput_fixed_node ${catkin_LIBRARIES})

add_executable(cycle_detect_new_node src/cycle_detect_new.cpp)
target_link_libraries(cycle_detect_new_node ${catkin_LIBRARIES})

add_executable(showinfo_node src/showinfo.cpp)
add_dependencies(showinfo_node ${catkin_EXPORTED_TARGETS} offb_msgs_gencpp)
target_link_libraries(showinfo_node ${catkin_LIBRARIES})

add_executable(set_mode_node src/set_mode.cpp)
target_link_libraries(set_mode_node ${catkin_LIBRARIES})

add_executable(send_info_node src/send_info.cpp)
target_link_libraries(send_info_node ${catkin_LIBRARIES})

add_executable(com_node src/com.cpp)
target_link_libraries(com_node ${catkin_LIBRARIES})

add_executable(test_node src/test.cpp)
target_link_libraries(test_node ${catkin_LIBRARIES})

add_executable(servo_control_node src/servo_control.cpp)
target_link_libraries(servo_control_node ${catkin_LIBRARIES})

add_executable(communicate_node src/communicate.cpp)
target_link_libraries(communicate_node ${catkin_LIBRARIES})

add_executable(H_detect_node src/H_detect.cpp)
target_link_libraries(H_detect_node ${catkin_LIBRARIES})

add_executable(multi_input_node src/multi_input.cpp)
add_dependencies(showinfo_node ${catkin_EXPORTED_TARGETS} offb_msgs_gencpp)
target_link_libraries(multi_input_node ${catkin_LIBRARIES})

# add_executable(landing_quadrotor_node src/landing_quadrotor.cpp)
# target_link_libraries(landing_quadrotor_node ${catkin_LIBRARIES})

## Mark cpp header files for installation
install(DIRECTORY include/${PROJECT_NAME}/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
  FILES_MATCHING PATTERN "*.h"
)
## Mark executables and/or libraries for installation
 install(TARGETS
# offb_node
#  showinfo_node
#   set_mode_node
#   collision_avoidance_vfh_node
#   avoidance_car_vfh_node
#   collision_avoidance_matlabvfh_node
#   circular_node circular_car_node 
#   ros_nav_quadrotor_node 
#   mission_car_offboard_node
#   landing_quadrotor_node
#   tracking_quadrotor_node
#   tracking_down_kcf_quadrotor_node
#   tracking_ardupilot_node
#   auto_2d_nav_node
#   simulinkVFH_node
#   omplControlPx4_node
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(DIRECTORY
  launch
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)
