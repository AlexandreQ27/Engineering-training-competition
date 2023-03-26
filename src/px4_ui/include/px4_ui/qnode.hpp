/**
 * @file /include/px4_ui/qnode.hpp
 *
 * @brief Communications central!
 *
 * @date February 2011
 **/
/*****************************************************************************
** Ifdefs
*****************************************************************************/

#ifndef px4_ui_QNODE_HPP_
#define px4_ui_QNODE_HPP_

/*****************************************************************************
** Includes
*****************************************************************************/

// To workaround boost/qt4 problems that won't be bugfixed. Refer to
//    https://bugreports.qt.io/browse/QTBUG-22829
#ifndef Q_MOC_RUN
#include <ros/ros.h>
#include <mavros_msgs/State.h>
#include <mavros_msgs/SetMode.h>
#include <mavros_msgs/CommandBool.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/TwistStamped.h>
#include <mavros_msgs/PositionTarget.h>
#include <sensor_msgs/Image.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#endif
#include <string>
#include <QThread>
#include <QStringListModel>
#include "config.h"


/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace px4_ui {

/*****************************************************************************
** Class
*****************************************************************************/

class QNode : public QThread {
    Q_OBJECT
public:
	QNode(int argc, char** argv );
	virtual ~QNode();
	bool init();
	bool init(const std::string &master_url, const std::string &host_url);
	void run();

	/*********************
	** Logging
	**********************/
	enum LogLevel {
	         Debug,
	         Info,
	         Warn,
	         Error,
	         Fatal
	 };



  QImage Mat2QImage(cv::Mat const& src);
	QStringListModel* loggingModel() { return &logging_model; }
	void log( const LogLevel &level, const std::string &msg);
  void state_callback(const mavros_msgs::State &msg);
  void pos_callback(const geometry_msgs::PoseStamped &msg);
  void vel_callback(const geometry_msgs::TwistStamped &msg);
  void target_callback(const mavros_msgs::PositionTarget &msg);
  void img_callback(const sensor_msgs::ImageConstPtr &msg);
  void topic_name_init(ros::NodeHandle &n);


Q_SIGNALS:
	void loggingUpdated();
    void rosShutdown();
    void state_signal(QString, char, char);
    void pos_signal(double, double, double);
    void vel_signal(double, double, double);
    void target_signal(double, double, double);
    void img_signal(QImage);

public Q_SLOTS:
    void slot_change_mode(int);
    void slot_change_arming(char);
    void slot_control_send_pos(double, double ,double);

private:
	int init_argc;
	char** init_argv;
  std::string pos_topic_name, vel_topic_name, state_topic_name, target_topic_name, img_topic_name;
  std::string ros_namespace;
	ros::Publisher chatter_publisher;
  ros::Publisher pos_pub;

  ros::Subscriber pos_sub;
  ros::Subscriber vel_sub;
  ros::Subscriber state_sub;
  ros::Subscriber target_sub;
  image_transport::Subscriber img_sub;


  ros::ServiceClient change_mode_serv;
  ros::ServiceClient change_arming_serv;
    QStringListModel logging_model;
};

}  // namespace px4_ui

#endif /* px4_ui_QNODE_HPP_ */
