/**
 * @file /src/main_window.cpp
 *
 * @brief Implementation for the qt gui.
 *
 * @date February 2011
 **/
/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtGui>
#include <QMessageBox>
#include <iostream>
#include "../include/px4_ui/main_window.hpp"

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace px4_ui {

using namespace Qt;

/*****************************************************************************
** Implementation [MainWindow]
*****************************************************************************/

MainWindow::MainWindow(int argc, char** argv, QWidget *parent)
	: QMainWindow(parent)
	, qnode(argc,argv)
{
	ui.setupUi(this); // Calling this incidentally connects all ui's triggers to on_...() callbacks in this class.
    QObject::connect(ui.actionAbout_Qt, SIGNAL(triggered(bool)), qApp, SLOT(aboutQt())); // qApp is a global variable for the application

    ReadSettings();
	setWindowIcon(QIcon(":/images/icon.png"));
	ui.tab_manager->setCurrentIndex(0); // ensure the first tab is showing - qt-designer should have this already hardwired, but often loses it (settings?).
    QObject::connect(&qnode, SIGNAL(rosShutdown()), this, SLOT(close()));

    ui.dock_status->show();

	/*********************
	** Logging
	**********************/
	ui.view_logging->setModel(qnode.loggingModel());
    QObject::connect(&qnode, SIGNAL(loggingUpdated()), this, SLOT(updateLoggingView()));


    QObject::connect(&qnode, SIGNAL(state_signal(QString, char, char)), this, SLOT(slot_state(QString ,char, char)));
    QObject::connect(&qnode, SIGNAL(pos_signal(double, double, double)), this, SLOT(slot_pos(double, double, double)));
    QObject::connect(&qnode, SIGNAL(vel_signal(double, double, double)), this, SLOT(slot_vel(double, double, double)));
    QObject::connect(&qnode, SIGNAL(target_signal(double, double, double)), this, SLOT(slot_target(double, double, double)));
    QObject::connect(&qnode, SIGNAL(img_signal(QImage)), this, SLOT(slot_show_frame(QImage)));

    QObject::connect(this, SIGNAL(change_state_signal(int)), &qnode, SLOT(slot_change_mode(int)));
    QObject::connect(this, SIGNAL(change_arming_signal(char)), &qnode, SLOT(slot_change_arming(char)));
    QObject::connect(this, SIGNAL(control_send_pos_signal(double, double, double)),
                     &qnode, SLOT(slot_control_send_pos(double, double, double)));
    /*********************
    ** Auto Start
    **********************/
    if ( ui.checkbox_remember_settings->isChecked() ) {
        on_button_connect_clicked(true);
    }
}

MainWindow::~MainWindow() {}

/*****************************************************************************
** Implementation [Slots]
*****************************************************************************/

void MainWindow::showNoMasterMessage() {
	QMessageBox msgBox;
	msgBox.setText("Couldn't find the ros master.");
	msgBox.exec();
    close();
}

/*
 * These triggers whenever the button is clicked, regardless of whether it
 * is already checked or not.
 */

void MainWindow::on_button_connect_clicked(bool check ) {
	if ( ui.checkbox_use_environment->isChecked() ) {
		if ( !qnode.init() ) {
			showNoMasterMessage();
		} else {
			ui.button_connect->setEnabled(false);
		}
	} else {
		if ( ! qnode.init(ui.line_edit_master->text().toStdString(),
				   ui.line_edit_host->text().toStdString()) ) {
			showNoMasterMessage();
		} else {
			ui.button_connect->setEnabled(false);
			ui.line_edit_master->setReadOnly(true);
			ui.line_edit_host->setReadOnly(true);
			ui.line_edit_topic->setReadOnly(true);
		}
	}
}


void MainWindow::on_checkbox_use_environment_stateChanged(int state) {
	bool enabled;
	if ( state == 0 ) {
		enabled = true;
	} else {
		enabled = false;
	}
	ui.line_edit_master->setEnabled(enabled);
	ui.line_edit_host->setEnabled(enabled);
	//ui.line_edit_topic->setEnabled(enabled);
}

/*****************************************************************************
** Implemenation [Slots][manually connected]
*****************************************************************************/

/**
 * This function is signalled by the underlying model. When the model changes,
 * this will drop the cursor down to the last line in the QListview to ensure
 * the user can always see the latest log message.
 */
void MainWindow::updateLoggingView() {
        ui.view_logging->scrollToBottom();
}

/*****************************************************************************
** Implementation [Menu]
*****************************************************************************/

void MainWindow::on_actionAbout_triggered() {
    QMessageBox::about(this, tr("About ..."),tr("<h2>PACKAGE_NAME Test Program 0.10</h2><p>Copyright Yujin Robot</p><p>This package needs an about description.</p>"));
}

/*****************************************************************************
** Implementation [Configuration]
*****************************************************************************/

void MainWindow::ReadSettings() {
    QSettings settings("Qt-Ros Package", "px4_ui");
    restoreGeometry(settings.value("geometry").toByteArray());
    restoreState(settings.value("windowState").toByteArray());
    QString master_url = settings.value("master_url",QString("http://192.168.1.2:11311/")).toString();
    QString host_url = settings.value("host_url", QString("192.168.1.3")).toString();
    //QString topic_name = settings.value("topic_name", QString("/chatter")).toString();
    ui.line_edit_master->setText(master_url);
    ui.line_edit_host->setText(host_url);
    //ui.line_edit_topic->setText(topic_name);
    bool remember = settings.value("remember_settings", false).toBool();
    ui.checkbox_remember_settings->setChecked(remember);
    bool checked = settings.value("use_environment_variables", false).toBool();
    ui.checkbox_use_environment->setChecked(checked);
    if ( checked ) {
    	ui.line_edit_master->setEnabled(false);
    	ui.line_edit_host->setEnabled(false);
    	//ui.line_edit_topic->setEnabled(false);
    }
}

void MainWindow::WriteSettings() {
    QSettings settings("Qt-Ros Package", "px4_ui");
    settings.setValue("master_url",ui.line_edit_master->text());
    settings.setValue("host_url",ui.line_edit_host->text());
    //settings.setValue("topic_name",ui.line_edit_topic->text());
    settings.setValue("use_environment_variables",QVariant(ui.checkbox_use_environment->isChecked()));
    settings.setValue("geometry", saveGeometry());
    settings.setValue("windowState", saveState());
    settings.setValue("remember_settings",QVariant(ui.checkbox_remember_settings->isChecked()));

}

void MainWindow::closeEvent(QCloseEvent *event)
{
	WriteSettings();
	QMainWindow::closeEvent(event);
}

void MainWindow::slot_state(QString mode, char armed, char connected)
{
  ui.line_mode->setText(mode);
  if(armed == 0)
  {
    ui.line_armed->setText("false");
  }
  else {
    ui.line_armed->setText("true");
  }
  if(connected == 0)
  {
    ui.line_connected->setText("false");
  }
  else {
    ui.line_connected->setText("true");
  }
}

void MainWindow::slot_pos(double x, double y, double z)
{
  ui.line_pos_x->setText(QString::number(x, 'g', 2));
  ui.line_pos_y->setText(QString::number(y, 'g', 2));
  ui.line_pos_z->setText(QString::number(z, 'g', 2));
}

void MainWindow::slot_vel(double x, double y, double z)
{
  ui.line_vel_x->setText(QString::number(x, 'g', 2));
  ui.line_vel_y->setText(QString::number(y, 'g', 2));
  ui.line_vel_z->setText(QString::number(z, 'g', 2));
}

void MainWindow::slot_target(double px, double py, double pz)
{
  ui.text_target_info->clear();
  QString pos_x = "pos_x :" + QString::number(px);
  QString pos_y = "pos_y :" + QString::number(py);
  QString pos_z = "pos_z :" + QString::number(pz);
//  QString vel_x = "vel_x :" + QString::number(msg.position.x);
//  QString vel_y = "vel_y :" + QString::number(msg.position.x);
//  QString vel_z = "vel_z :" + QString::number(msg.position.x);
  ui.text_target_info->append(pos_x);
  ui.text_target_info->append(pos_y);
  ui.text_target_info->append(pos_z);
}

void MainWindow::slot_show_frame(QImage im)
{
  im = im.scaled(ui.label_frame->width(), ui.label_frame->height());
  ui.label_frame->setPixmap(QPixmap::fromImage(im));
}






}  // namespace px4_ui



void px4_ui::MainWindow::on_button_mode_change_clicked()
{
    Q_EMIT change_state_signal(ui.combox_mode_change->currentIndex());
}

void px4_ui::MainWindow::on_button_arm_clicked()
{
  char val = 1;
  Q_EMIT change_arming_signal(val);
}

void px4_ui::MainWindow::on_button_disarm_clicked()
{
  char val = 0;
  Q_EMIT change_arming_signal(val);
}


void px4_ui::MainWindow::on_button_control_send_pos_clicked()
{
  double x, y, z;
  x = ui.spinbox_pos_x->value();
  y = ui.spinbox_pos_y->value();
  z = ui.spinbox_pos_z->value();
  Q_EMIT control_send_pos_signal(x, y, z);
}



