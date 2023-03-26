/**
 * @file /include/px4_ui/main_window.hpp
 *
 * @brief Qt based gui for px4_ui.
 *
 * @date November 2010
 **/
#ifndef px4_ui_MAIN_WINDOW_H
#define px4_ui_MAIN_WINDOW_H

/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtGui/QMainWindow>
#include "ui_main_window.h"
#include "qnode.hpp"

/*****************************************************************************
** Namespace
*****************************************************************************/

namespace px4_ui {

/*****************************************************************************
** Interface [MainWindow]
*****************************************************************************/
/**
 * @brief Qt central, all operations relating to the view part here.
 */
class MainWindow : public QMainWindow {
Q_OBJECT


  std::string mode_string[6] = {"OFFBOARD", "AUTO.LOITER", "AUTO.LAND"};

public:
	MainWindow(int argc, char** argv, QWidget *parent = 0);
	~MainWindow();

	void ReadSettings(); // Load up qt program settings at startup
	void WriteSettings(); // Save qt program settings when closing

	void closeEvent(QCloseEvent *event); // Overloaded function
	void showNoMasterMessage();

public Q_SLOTS:
	/******************************************
	** Auto-connections (connectSlotsByName())
	*******************************************/
	void on_actionAbout_triggered();
	void on_button_connect_clicked(bool check );
	void on_checkbox_use_environment_stateChanged(int state);
  void on_button_mode_change_clicked();
  void on_button_arm_clicked();
  void on_button_control_send_pos_clicked();
  void on_button_disarm_clicked();
    /******************************************
    ** Manual connections
    *******************************************/
    void updateLoggingView(); // no idea why this can't connect automatically
    void slot_state(QString, char, char);
    void slot_pos(double, double, double);
    void slot_vel(double, double, double);
    void slot_target(double, double, double);
    void slot_show_frame(QImage im);

Q_SIGNALS:
    void change_state_signal(int);
    void change_arming_signal(char);
    void control_send_pos_signal(double, double, double);



private:
	Ui::MainWindowDesign ui;
	QNode qnode;
};

}  // namespace px4_ui

#endif // px4_ui_MAIN_WINDOW_H
