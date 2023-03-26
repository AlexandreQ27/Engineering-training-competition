/********************************************************************************
** Form generated from reading UI file 'main_window.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_WINDOW_H
#define UI_MAIN_WINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDockWidget>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFormLayout>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowDesign
{
public:
    QAction *action_Quit;
    QAction *action_Preferences;
    QAction *actionAbout;
    QAction *actionAbout_Qt;
    QWidget *centralwidget;
    QHBoxLayout *hboxLayout;
    QTabWidget *tab_manager;
    QWidget *tab;
    QFrame *frame_2;
    QFrame *frame_3;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_2;
    QLabel *label_7;
    QLineEdit *line_pos_x;
    QLabel *label_8;
    QLineEdit *line_pos_y;
    QLabel *label_9;
    QLineEdit *line_pos_z;
    QLabel *label_19;
    QFrame *frame_4;
    QWidget *formLayoutWidget_3;
    QFormLayout *formLayout_3;
    QLabel *label_10;
    QLineEdit *line_connected;
    QLabel *label_11;
    QLineEdit *line_armed;
    QLabel *label_12;
    QLineEdit *line_mode;
    QLabel *label_20;
    QFrame *frame_5;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_4;
    QLineEdit *line_vel_x;
    QLabel *label_5;
    QLineEdit *line_vel_y;
    QLabel *label_6;
    QLineEdit *line_vel_z;
    QLabel *label_18;
    QTextEdit *text_target_info;
    QLabel *label_21;
    QFrame *frame_31;
    QLabel *label_13;
    QWidget *formLayoutWidget_4;
    QFormLayout *formLayout_4;
    QLabel *label_14;
    QLabel *label_15;
    QDoubleSpinBox *spinbox_pos_x;
    QDoubleSpinBox *spinbox_pos_y;
    QDoubleSpinBox *spinbox_pos_z;
    QLabel *label_16;
    QPushButton *button_control_send_pos;
    QFrame *frame_41;
    QPushButton *button_arm;
    QComboBox *combox_mode_change;
    QPushButton *button_mode_change;
    QLabel *label_17;
    QPushButton *button_disarm;
    QWidget *tab_status;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_12;
    QGridLayout *gridLayout_3;
    QListView *view_logging;
    QMenuBar *menubar;
    QMenu *menu_File;
    QStatusBar *statusbar;
    QDockWidget *dock_status;
    QWidget *dockWidgetContents_2;
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *line_edit_master;
    QLabel *label_2;
    QLineEdit *line_edit_host;
    QLabel *label_3;
    QLineEdit *line_edit_topic;
    QCheckBox *checkbox_use_environment;
    QCheckBox *checkbox_remember_settings;
    QSpacerItem *horizontalSpacer;
    QPushButton *button_connect;
    QSpacerItem *verticalSpacer_3;
    QPushButton *quit_button;
    QDockWidget *dockWidget_2;
    QWidget *dockWidgetContents_3;
    QLabel *label_frame;

    void setupUi(QMainWindow *MainWindowDesign)
    {
        if (MainWindowDesign->objectName().isEmpty())
            MainWindowDesign->setObjectName(QString::fromUtf8("MainWindowDesign"));
        MainWindowDesign->resize(1318, 807);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindowDesign->setWindowIcon(icon);
        MainWindowDesign->setLocale(QLocale(QLocale::English, QLocale::Australia));
        action_Quit = new QAction(MainWindowDesign);
        action_Quit->setObjectName(QString::fromUtf8("action_Quit"));
        action_Quit->setShortcutContext(Qt::ApplicationShortcut);
        action_Preferences = new QAction(MainWindowDesign);
        action_Preferences->setObjectName(QString::fromUtf8("action_Preferences"));
        actionAbout = new QAction(MainWindowDesign);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionAbout_Qt = new QAction(MainWindowDesign);
        actionAbout_Qt->setObjectName(QString::fromUtf8("actionAbout_Qt"));
        centralwidget = new QWidget(MainWindowDesign);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        hboxLayout = new QHBoxLayout(centralwidget);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        tab_manager = new QTabWidget(centralwidget);
        tab_manager->setObjectName(QString::fromUtf8("tab_manager"));
        tab_manager->setMinimumSize(QSize(100, 0));
        tab_manager->setLocale(QLocale(QLocale::English, QLocale::Australia));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        frame_2 = new QFrame(tab);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(10, 10, 631, 411));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        frame_3 = new QFrame(frame_2);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(360, 220, 261, 181));
        frame_3->setFrameShape(QFrame::StyledPanel);
        formLayoutWidget_2 = new QWidget(frame_3);
        formLayoutWidget_2->setObjectName(QString::fromUtf8("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(10, 30, 241, 151));
        formLayout_2 = new QFormLayout(formLayoutWidget_2);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout_2->setRowWrapPolicy(QFormLayout::DontWrapRows);
        formLayout_2->setLabelAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        formLayout_2->setFormAlignment(Qt::AlignCenter);
        formLayout_2->setHorizontalSpacing(6);
        formLayout_2->setVerticalSpacing(26);
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(formLayoutWidget_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_7);

        line_pos_x = new QLineEdit(formLayoutWidget_2);
        line_pos_x->setObjectName(QString::fromUtf8("line_pos_x"));
        line_pos_x->setAlignment(Qt::AlignCenter);
        line_pos_x->setReadOnly(true);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, line_pos_x);

        label_8 = new QLabel(formLayoutWidget_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setAlignment(Qt::AlignCenter);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_8);

        line_pos_y = new QLineEdit(formLayoutWidget_2);
        line_pos_y->setObjectName(QString::fromUtf8("line_pos_y"));
        line_pos_y->setAlignment(Qt::AlignCenter);
        line_pos_y->setReadOnly(true);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, line_pos_y);

        label_9 = new QLabel(formLayoutWidget_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_9);

        line_pos_z = new QLineEdit(formLayoutWidget_2);
        line_pos_z->setObjectName(QString::fromUtf8("line_pos_z"));
        line_pos_z->setAlignment(Qt::AlignCenter);
        line_pos_z->setReadOnly(true);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, line_pos_z);

        label_19 = new QLabel(frame_3);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(10, 0, 71, 21));
        label_19->setAutoFillBackground(true);
        label_19->setAlignment(Qt::AlignCenter);
        frame_4 = new QFrame(frame_2);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setGeometry(QRect(10, 20, 261, 181));
        frame_4->setFrameShape(QFrame::StyledPanel);
        formLayoutWidget_3 = new QWidget(frame_4);
        formLayoutWidget_3->setObjectName(QString::fromUtf8("formLayoutWidget_3"));
        formLayoutWidget_3->setGeometry(QRect(10, 30, 241, 151));
        formLayout_3 = new QFormLayout(formLayoutWidget_3);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        formLayout_3->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout_3->setRowWrapPolicy(QFormLayout::DontWrapRows);
        formLayout_3->setLabelAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        formLayout_3->setFormAlignment(Qt::AlignCenter);
        formLayout_3->setHorizontalSpacing(6);
        formLayout_3->setVerticalSpacing(26);
        formLayout_3->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(formLayoutWidget_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_10);

        line_connected = new QLineEdit(formLayoutWidget_3);
        line_connected->setObjectName(QString::fromUtf8("line_connected"));
        line_connected->setAlignment(Qt::AlignCenter);
        line_connected->setReadOnly(true);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, line_connected);

        label_11 = new QLabel(formLayoutWidget_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setAlignment(Qt::AlignCenter);

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_11);

        line_armed = new QLineEdit(formLayoutWidget_3);
        line_armed->setObjectName(QString::fromUtf8("line_armed"));
        line_armed->setAlignment(Qt::AlignCenter);
        line_armed->setReadOnly(true);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, line_armed);

        label_12 = new QLabel(formLayoutWidget_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, label_12);

        line_mode = new QLineEdit(formLayoutWidget_3);
        line_mode->setObjectName(QString::fromUtf8("line_mode"));
        line_mode->setAlignment(Qt::AlignCenter);
        line_mode->setReadOnly(true);

        formLayout_3->setWidget(2, QFormLayout::FieldRole, line_mode);

        label_20 = new QLabel(frame_4);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(10, 0, 81, 21));
        label_20->setAutoFillBackground(true);
        label_20->setAlignment(Qt::AlignCenter);
        frame_5 = new QFrame(frame_2);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setGeometry(QRect(10, 230, 261, 171));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        formLayoutWidget = new QWidget(frame_5);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 20, 241, 151));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setRowWrapPolicy(QFormLayout::DontWrapRows);
        formLayout->setLabelAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        formLayout->setFormAlignment(Qt::AlignCenter);
        formLayout->setHorizontalSpacing(6);
        formLayout->setVerticalSpacing(26);
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_4);

        line_vel_x = new QLineEdit(formLayoutWidget);
        line_vel_x->setObjectName(QString::fromUtf8("line_vel_x"));
        line_vel_x->setAlignment(Qt::AlignCenter);
        line_vel_x->setReadOnly(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, line_vel_x);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_5);

        line_vel_y = new QLineEdit(formLayoutWidget);
        line_vel_y->setObjectName(QString::fromUtf8("line_vel_y"));
        line_vel_y->setAlignment(Qt::AlignCenter);
        line_vel_y->setReadOnly(true);

        formLayout->setWidget(1, QFormLayout::FieldRole, line_vel_y);

        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_6);

        line_vel_z = new QLineEdit(formLayoutWidget);
        line_vel_z->setObjectName(QString::fromUtf8("line_vel_z"));
        line_vel_z->setAlignment(Qt::AlignCenter);
        line_vel_z->setReadOnly(true);

        formLayout->setWidget(2, QFormLayout::FieldRole, line_vel_z);

        label_18 = new QLabel(frame_5);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(10, -4, 71, 21));
        label_18->setAutoFillBackground(true);
        label_18->setAlignment(Qt::AlignCenter);
        text_target_info = new QTextEdit(frame_2);
        text_target_info->setObjectName(QString::fromUtf8("text_target_info"));
        text_target_info->setGeometry(QRect(360, 30, 251, 171));
        QFont font;
        font.setFamily(QString::fromUtf8("Umpush"));
        font.setPointSize(14);
        text_target_info->setFont(font);
        text_target_info->setReadOnly(true);
        label_21 = new QLabel(frame_2);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(370, 10, 81, 17));
        label_21->setAutoFillBackground(true);
        frame_31 = new QFrame(tab);
        frame_31->setObjectName(QString::fromUtf8("frame_31"));
        frame_31->setGeometry(QRect(370, 430, 271, 211));
        frame_31->setFrameShape(QFrame::StyledPanel);
        frame_31->setFrameShadow(QFrame::Raised);
        label_13 = new QLabel(frame_31);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(10, -4, 71, 21));
        label_13->setAutoFillBackground(true);
        label_13->setAlignment(Qt::AlignCenter);
        formLayoutWidget_4 = new QWidget(frame_31);
        formLayoutWidget_4->setObjectName(QString::fromUtf8("formLayoutWidget_4"));
        formLayoutWidget_4->setGeometry(QRect(10, 30, 241, 121));
        formLayout_4 = new QFormLayout(formLayoutWidget_4);
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        formLayout_4->setHorizontalSpacing(7);
        formLayout_4->setVerticalSpacing(15);
        formLayout_4->setContentsMargins(0, 0, 0, 0);
        label_14 = new QLabel(formLayoutWidget_4);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, label_14);

        label_15 = new QLabel(formLayoutWidget_4);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        formLayout_4->setWidget(1, QFormLayout::LabelRole, label_15);

        spinbox_pos_x = new QDoubleSpinBox(formLayoutWidget_4);
        spinbox_pos_x->setObjectName(QString::fromUtf8("spinbox_pos_x"));
        spinbox_pos_x->setAlignment(Qt::AlignCenter);
        spinbox_pos_x->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinbox_pos_x->setMinimum(-99);

        formLayout_4->setWidget(0, QFormLayout::FieldRole, spinbox_pos_x);

        spinbox_pos_y = new QDoubleSpinBox(formLayoutWidget_4);
        spinbox_pos_y->setObjectName(QString::fromUtf8("spinbox_pos_y"));
        spinbox_pos_y->setAlignment(Qt::AlignCenter);
        spinbox_pos_y->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinbox_pos_y->setMinimum(-99);

        formLayout_4->setWidget(1, QFormLayout::FieldRole, spinbox_pos_y);

        spinbox_pos_z = new QDoubleSpinBox(formLayoutWidget_4);
        spinbox_pos_z->setObjectName(QString::fromUtf8("spinbox_pos_z"));
        spinbox_pos_z->setAlignment(Qt::AlignCenter);
        spinbox_pos_z->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinbox_pos_z->setMinimum(-99);

        formLayout_4->setWidget(2, QFormLayout::FieldRole, spinbox_pos_z);

        label_16 = new QLabel(formLayoutWidget_4);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        formLayout_4->setWidget(2, QFormLayout::LabelRole, label_16);

        button_control_send_pos = new QPushButton(frame_31);
        button_control_send_pos->setObjectName(QString::fromUtf8("button_control_send_pos"));
        button_control_send_pos->setGeometry(QRect(10, 160, 241, 31));
        frame_41 = new QFrame(tab);
        frame_41->setObjectName(QString::fromUtf8("frame_41"));
        frame_41->setGeometry(QRect(20, 440, 301, 201));
        frame_41->setFrameShape(QFrame::StyledPanel);
        frame_41->setFrameShadow(QFrame::Raised);
        button_arm = new QPushButton(frame_41);
        button_arm->setObjectName(QString::fromUtf8("button_arm"));
        button_arm->setGeometry(QRect(20, 110, 111, 51));
        combox_mode_change = new QComboBox(frame_41);
        combox_mode_change->setObjectName(QString::fromUtf8("combox_mode_change"));
        combox_mode_change->setGeometry(QRect(20, 40, 131, 41));
        button_mode_change = new QPushButton(frame_41);
        button_mode_change->setObjectName(QString::fromUtf8("button_mode_change"));
        button_mode_change->setGeometry(QRect(180, 40, 111, 41));
        label_17 = new QLabel(frame_41);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(20, -3, 101, 20));
        label_17->setAutoFillBackground(true);
        button_disarm = new QPushButton(frame_41);
        button_disarm->setObjectName(QString::fromUtf8("button_disarm"));
        button_disarm->setGeometry(QRect(180, 110, 111, 51));
        tab_manager->addTab(tab, QString());
        tab_status = new QWidget();
        tab_status->setObjectName(QString::fromUtf8("tab_status"));
        verticalLayout_2 = new QVBoxLayout(tab_status);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox_12 = new QGroupBox(tab_status);
        groupBox_12->setObjectName(QString::fromUtf8("groupBox_12"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_12->sizePolicy().hasHeightForWidth());
        groupBox_12->setSizePolicy(sizePolicy);
        gridLayout_3 = new QGridLayout(groupBox_12);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        view_logging = new QListView(groupBox_12);
        view_logging->setObjectName(QString::fromUtf8("view_logging"));

        gridLayout_3->addWidget(view_logging, 0, 0, 1, 1);


        verticalLayout_2->addWidget(groupBox_12);

        tab_manager->addTab(tab_status, QString());

        hboxLayout->addWidget(tab_manager);

        MainWindowDesign->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindowDesign);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1318, 28));
        menu_File = new QMenu(menubar);
        menu_File->setObjectName(QString::fromUtf8("menu_File"));
        MainWindowDesign->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindowDesign);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindowDesign->setStatusBar(statusbar);
        dock_status = new QDockWidget(MainWindowDesign);
        dock_status->setObjectName(QString::fromUtf8("dock_status"));
        dock_status->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(dock_status->sizePolicy().hasHeightForWidth());
        dock_status->setSizePolicy(sizePolicy1);
        dock_status->setMinimumSize(QSize(337, 389));
        dock_status->setFloating(false);
        dock_status->setFeatures(QDockWidget::AllDockWidgetFeatures);
        dock_status->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QString::fromUtf8("dockWidgetContents_2"));
        verticalLayout = new QVBoxLayout(dockWidgetContents_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame = new QFrame(dockWidgetContents_2);
        frame->setObjectName(QString::fromUtf8("frame"));
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupBox = new QGroupBox(frame);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFrameShape(QFrame::StyledPanel);
        label->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        line_edit_master = new QLineEdit(groupBox);
        line_edit_master->setObjectName(QString::fromUtf8("line_edit_master"));

        gridLayout->addWidget(line_edit_master, 1, 0, 1, 2);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFrameShape(QFrame::StyledPanel);
        label_2->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        line_edit_host = new QLineEdit(groupBox);
        line_edit_host->setObjectName(QString::fromUtf8("line_edit_host"));

        gridLayout->addWidget(line_edit_host, 3, 0, 1, 2);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFrameShape(QFrame::StyledPanel);
        label_3->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        line_edit_topic = new QLineEdit(groupBox);
        line_edit_topic->setObjectName(QString::fromUtf8("line_edit_topic"));
        line_edit_topic->setEnabled(false);

        gridLayout->addWidget(line_edit_topic, 5, 0, 1, 2);

        checkbox_use_environment = new QCheckBox(groupBox);
        checkbox_use_environment->setObjectName(QString::fromUtf8("checkbox_use_environment"));
        checkbox_use_environment->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(checkbox_use_environment, 6, 0, 1, 2);

        checkbox_remember_settings = new QCheckBox(groupBox);
        checkbox_remember_settings->setObjectName(QString::fromUtf8("checkbox_remember_settings"));
        checkbox_remember_settings->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(checkbox_remember_settings, 7, 0, 1, 2);

        horizontalSpacer = new QSpacerItem(170, 21, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 8, 0, 1, 1);

        button_connect = new QPushButton(groupBox);
        button_connect->setObjectName(QString::fromUtf8("button_connect"));
        button_connect->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(button_connect->sizePolicy().hasHeightForWidth());
        button_connect->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(button_connect, 8, 1, 1, 1);


        verticalLayout_3->addWidget(groupBox);

        verticalSpacer_3 = new QSpacerItem(20, 233, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);


        verticalLayout->addWidget(frame);

        quit_button = new QPushButton(dockWidgetContents_2);
        quit_button->setObjectName(QString::fromUtf8("quit_button"));
        sizePolicy2.setHeightForWidth(quit_button->sizePolicy().hasHeightForWidth());
        quit_button->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(quit_button);

        dock_status->setWidget(dockWidgetContents_2);
        MainWindowDesign->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dock_status);
        dockWidget_2 = new QDockWidget(MainWindowDesign);
        dockWidget_2->setObjectName(QString::fromUtf8("dockWidget_2"));
        dockWidgetContents_3 = new QWidget();
        dockWidgetContents_3->setObjectName(QString::fromUtf8("dockWidgetContents_3"));
        label_frame = new QLabel(dockWidgetContents_3);
        label_frame->setObjectName(QString::fromUtf8("label_frame"));
        label_frame->setGeometry(QRect(10, 0, 301, 291));
        dockWidget_2->setWidget(dockWidgetContents_3);
        MainWindowDesign->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget_2);

        menubar->addAction(menu_File->menuAction());
        menu_File->addAction(action_Preferences);
        menu_File->addSeparator();
        menu_File->addAction(actionAbout);
        menu_File->addAction(actionAbout_Qt);
        menu_File->addSeparator();
        menu_File->addAction(action_Quit);

        retranslateUi(MainWindowDesign);
        QObject::connect(action_Quit, SIGNAL(triggered()), MainWindowDesign, SLOT(close()));
        QObject::connect(quit_button, SIGNAL(clicked()), MainWindowDesign, SLOT(close()));

        tab_manager->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindowDesign);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowDesign)
    {
        MainWindowDesign->setWindowTitle(QApplication::translate("MainWindowDesign", "QRosApp", 0, QApplication::UnicodeUTF8));
        action_Quit->setText(QApplication::translate("MainWindowDesign", "&Quit", 0, QApplication::UnicodeUTF8));
        action_Quit->setShortcut(QApplication::translate("MainWindowDesign", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        action_Preferences->setText(QApplication::translate("MainWindowDesign", "&Preferences", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindowDesign", "&About", 0, QApplication::UnicodeUTF8));
        actionAbout_Qt->setText(QApplication::translate("MainWindowDesign", "About &Qt", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindowDesign", "pos_x", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindowDesign", "pos_y", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindowDesign", "pos_z", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("MainWindowDesign", "pos_info", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindowDesign", "connected", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindowDesign", "armed", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindowDesign", "mode", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("MainWindowDesign", "state_info", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindowDesign", "vel_x", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindowDesign", "vel_y", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindowDesign", "vel_z", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("MainWindowDesign", "vel_info", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("MainWindowDesign", "target_info", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("MainWindowDesign", "send pos", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("MainWindowDesign", "pos_x_send", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("MainWindowDesign", "pos_y_send", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("MainWindowDesign", "pos_z_send", 0, QApplication::UnicodeUTF8));
        button_control_send_pos->setText(QApplication::translate("MainWindowDesign", "Send", 0, QApplication::UnicodeUTF8));
        button_arm->setText(QApplication::translate("MainWindowDesign", "arm", 0, QApplication::UnicodeUTF8));
        combox_mode_change->clear();
        combox_mode_change->insertItems(0, QStringList()
         << QApplication::translate("MainWindowDesign", "OFFBOARD", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindowDesign", "AUTO.LOITER", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindowDesign", "AUTO.LAND", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindowDesign", "RETURN", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindowDesign", "AUTO.TAKEOFF", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindowDesign", "MANUAL", 0, QApplication::UnicodeUTF8)
        );
        button_mode_change->setText(QApplication::translate("MainWindowDesign", "change", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("MainWindowDesign", "mode change", 0, QApplication::UnicodeUTF8));
        button_disarm->setText(QApplication::translate("MainWindowDesign", "disarm", 0, QApplication::UnicodeUTF8));
        tab_manager->setTabText(tab_manager->indexOf(tab), QApplication::translate("MainWindowDesign", "info", 0, QApplication::UnicodeUTF8));
        groupBox_12->setTitle(QApplication::translate("MainWindowDesign", "Logging", 0, QApplication::UnicodeUTF8));
        tab_manager->setTabText(tab_manager->indexOf(tab_status), QApplication::translate("MainWindowDesign", "Ros Communications", 0, QApplication::UnicodeUTF8));
        menu_File->setTitle(QApplication::translate("MainWindowDesign", "&App", 0, QApplication::UnicodeUTF8));
        dock_status->setWindowTitle(QApplication::translate("MainWindowDesign", "Command Panel", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindowDesign", "Ros Master", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindowDesign", "Ros Master Url", 0, QApplication::UnicodeUTF8));
        line_edit_master->setText(QApplication::translate("MainWindowDesign", "http://192.168.1.2:11311/", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindowDesign", "Ros IP", 0, QApplication::UnicodeUTF8));
        line_edit_host->setText(QApplication::translate("MainWindowDesign", "192.168.1.67", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindowDesign", "Ros Hostname", 0, QApplication::UnicodeUTF8));
        line_edit_topic->setText(QApplication::translate("MainWindowDesign", "unused", 0, QApplication::UnicodeUTF8));
        checkbox_use_environment->setText(QApplication::translate("MainWindowDesign", "Use environment variables", 0, QApplication::UnicodeUTF8));
        checkbox_remember_settings->setText(QApplication::translate("MainWindowDesign", "Remember settings on startup", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        button_connect->setToolTip(QApplication::translate("MainWindowDesign", "Set the target to the current joint trajectory state.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        button_connect->setStatusTip(QApplication::translate("MainWindowDesign", "Clear all waypoints and set the target to the current joint trajectory state.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        button_connect->setText(QApplication::translate("MainWindowDesign", "Connect", 0, QApplication::UnicodeUTF8));
        quit_button->setText(QApplication::translate("MainWindowDesign", "Quit", 0, QApplication::UnicodeUTF8));
        label_frame->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindowDesign: public Ui_MainWindowDesign {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
