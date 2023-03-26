/**
 * @file /src/qnode.cpp
 *
 * @brief Ros communication central!
 *
 * @date February 2011
 **/

/*****************************************************************************
** Includes
*****************************************************************************/

#ifndef Q_MOC_RUN
#include <ros/ros.h>
#include "../include/px4_ui/qnode.hpp"
#include <ros/network.h>
#endif

#include <string>
#include <std_msgs/String.h>
#include <sstream>


/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace px4_ui {

/*****************************************************************************
** Implementation
*****************************************************************************/

QNode::QNode(int argc, char** argv ) :
	init_argc(argc),
	init_argv(argv)
	{}

QNode::~QNode() {
    if(ros::isStarted()) {
      ros::shutdown(); // explicitly needed since we use ros::start();
      ros::waitForShutdown();
    }
	wait();
}

bool QNode::init() {
	ros::init(init_argc,init_argv,"px4_ui");
	if ( ! ros::master::check() ) {
		return false;
	}
	ros::start(); // explicitly needed since our nodehandle is going out of scope.
	ros::NodeHandle n;
  image_transport::ImageTransport it(n);
	// Add your ros communications here.
  topic_name_init(n);
  pos_pub = n.advertise <geometry_msgs::Pose> ("mavros/setpoint_from_station/pose", 100);

  pos_sub = n.subscribe("mavros/local_position/pose", 100, &QNode::pos_callback, this);
  vel_sub = n.subscribe("mavros/local_position/velocity_local", 100, &QNode::vel_callback, this);
  target_sub = n.subscribe("mavros/setpoint_raw/local", 100, &QNode::target_callback, this);
  state_sub = n.subscribe("/mavros/state", 100, &QNode::state_callback, this);
  img_sub = it.subscribe(ros_namespace + img_topic_name, 100, &QNode::img_callback, this);
  change_mode_serv = n.serviceClient<mavros_msgs::SetMode>("/mavros/set_mode");
  change_arming_serv = n.serviceClient<mavros_msgs::CommandBool>("mavros/cmd/arming");
	start();
	return true;
}

bool QNode::init(const std::string &master_url, const std::string &host_url) {
	std::map<std::string,std::string> remappings;
	remappings["__master"] = master_url;
	remappings["__hostname"] = host_url;
	ros::init(remappings,"px4_ui");
	if ( ! ros::master::check() ) {
		return false;
	}
	ros::start(); // explicitly needed since our nodehandle is going out of scope.
	ros::NodeHandle n;
	// Add your ros communications here.
  pos_pub = n.advertise <geometry_msgs::Pose> ("mavros/setpoint_from_station/pose", 100);

  pos_sub = n.subscribe("/mavros/local_position/pose", 100, &QNode::pos_callback, this);
  state_sub = n.subscribe("/mavros/state", 100, &QNode::state_callback, this);
  change_mode_serv = n.serviceClient<mavros_msgs::SetMode>("/mavros/set_mode");
  change_arming_serv = n.serviceClient<mavros_msgs::CommandBool>("mavros/cmd/arming");
	start();
	return true;
}

void QNode::run() {
  ros::Rate loop_rate(20);
	while ( ros::ok() ) {

		ros::spinOnce();
		loop_rate.sleep();

	}
	std::cout << "Ros shutdown, proceeding to close the gui." << std::endl;
	Q_EMIT rosShutdown(); // used to signal the gui for a shutdown (useful to roslaunch)
}


void QNode::log( const LogLevel &level, const std::string &msg) {
	logging_model.insertRows(logging_model.rowCount(),1);
	std::stringstream logging_model_msg;
	switch ( level ) {
		case(Debug) : {
				ROS_DEBUG_STREAM(msg);
				logging_model_msg << "[DEBUG] [" << ros::Time::now() << "]: " << msg;
				break;
		}
		case(Info) : {
				ROS_INFO_STREAM(msg);
				logging_model_msg << "[INFO] [" << ros::Time::now() << "]: " << msg;
				break;
		}
		case(Warn) : {
				ROS_WARN_STREAM(msg);
				logging_model_msg << "[INFO] [" << ros::Time::now() << "]: " << msg;
				break;
		}
		case(Error) : {
				ROS_ERROR_STREAM(msg);
				logging_model_msg << "[ERROR] [" << ros::Time::now() << "]: " << msg;
				break;
		}
		case(Fatal) : {
				ROS_FATAL_STREAM(msg);
				logging_model_msg << "[FATAL] [" << ros::Time::now() << "]: " << msg;
				break;
		}
	}
	QVariant new_row(QString(logging_model_msg.str().c_str()));
	logging_model.setData(logging_model.index(logging_model.rowCount()-1),new_row);
	Q_EMIT loggingUpdated(); // used to readjust the scrollbar
}

void QNode::state_callback(const mavros_msgs::State &msg)
{
  std::string mode_ = msg.mode;
  Q_EMIT state_signal(QString::fromStdString(mode_), msg.armed, msg.connected);
}

void QNode::pos_callback(const geometry_msgs::PoseStamped &msg)
{
  double pos_x, pos_y, pos_z;
  pos_x = msg.pose.position.x;
  pos_y = msg.pose.position.y;
  pos_z = msg.pose.position.z;

  Q_EMIT pos_signal(pos_x, pos_y, pos_z);
}

void QNode::vel_callback(const geometry_msgs::TwistStamped &msg)
{
  double vel_x, vel_y, vel_z;
  vel_x = msg.twist.linear.x;
  vel_y = msg.twist.linear.y;
  vel_z = msg.twist.linear.z;

  Q_EMIT vel_signal(vel_x, vel_y, vel_z);
}

void QNode::target_callback(const mavros_msgs::PositionTarget &msg)
{
  Q_EMIT target_signal(msg.position.x, msg.position.y, msg.position.z);
}

void QNode::slot_change_mode(int mode)
{
  if(mode >=0 && mode < 6)
  {
    mavros_msgs::SetMode set_mode;
    set_mode.request.custom_mode = mode_string[mode];
    change_mode_serv.call(set_mode);
    std::cout << "changed" << std::endl;
  }

}

void QNode::slot_change_arming(char val)
{
  mavros_msgs::CommandBool set_arming;
  if(val == 0)
  {
    set_arming.request.value = false;
    change_arming_serv.call(set_arming);
    std::cout << "disarmed" << std::endl;
  }
  else
  {
    set_arming.request.value = true;
    change_arming_serv.call(set_arming);
    std::cout << "hi";
  }
}

void QNode::slot_control_send_pos(double x, double y, double z)
{
  geometry_msgs::Pose Pose;
  Pose.position.x = x;
  Pose.position.y = y;
  Pose.position.z = z;
//  Pose.header.stamp = ros::Time::now();
  pos_pub.publish(Pose);
}

void QNode::topic_name_init(ros::NodeHandle &n)
{
  ros_namespace = "";
  img_topic_name = "/iris_0/camera/image_raw";
  pos_topic_name = "/mavros/local_position/pose";
  vel_topic_name = "mavros/local_position/velocity_local";
  state_topic_name = "/mavros/state";
}

void QNode::img_callback(const sensor_msgs::ImageConstPtr &msg)
{
  cv_bridge::CvImagePtr cv_ptr;
  cv_ptr=cv_bridge::toCvCopy(msg,msg->encoding);
  QImage im=Mat2QImage(cv_ptr->image);
  Q_EMIT img_signal(im);
//  log(Info, "received a image !");
}

QImage QNode::Mat2QImage(cv::Mat const& src)
{
  QImage dest(src.cols, src.rows, QImage::Format_ARGB32);

  const float scale = 255.0;

  if (src.depth() == CV_8U) {
    if (src.channels() == 1) {
      for (int i = 0; i < src.rows; ++i) {
        for (int j = 0; j < src.cols; ++j) {
          int level = src.at<quint8>(i, j);
          dest.setPixel(j, i, qRgb(level, level, level));
        }
      }
    } else if (src.channels() == 3) {
      for (int i = 0; i < src.rows; ++i) {
        for (int j = 0; j < src.cols; ++j) {
          cv::Vec3b bgr = src.at<cv::Vec3b>(i, j);
          dest.setPixel(j, i, qRgb(bgr[2], bgr[1], bgr[0]));
        }
      }
    }
  } else if (src.depth() == CV_32F) {
    if (src.channels() == 1) {
      for (int i = 0; i < src.rows; ++i) {
        for (int j = 0; j < src.cols; ++j) {
          int level = scale * src.at<float>(i, j);
          dest.setPixel(j, i, qRgb(level, level, level));
        }
      }
    } else if (src.channels() == 3) {
      for (int i = 0; i < src.rows; ++i) {
        for (int j = 0; j < src.cols; ++j) {
          cv::Vec3f bgr = scale * src.at<cv::Vec3f>(i, j);
          dest.setPixel(j, i, qRgb(bgr[2], bgr[1], bgr[0]));
        }
      }
    }
  }

  return dest;
}

}  // namespace px4_ui
