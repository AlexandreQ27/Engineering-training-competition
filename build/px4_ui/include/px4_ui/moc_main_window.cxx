/****************************************************************************
** Meta object code from reading C++ file 'main_window.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/px4_ui/include/px4_ui/main_window.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'main_window.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_px4_ui__MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x05,
      45,   19,   19,   19, 0x05,
      75,   72,   19,   19, 0x05,

 // slots: signature, parameters, type, tag, flags
     121,   19,   19,   19, 0x0a,
     154,  148,   19,   19, 0x0a,
     192,  186,   19,   19, 0x0a,
     238,   19,   19,   19, 0x0a,
     270,   19,   19,   19, 0x0a,
     294,   19,   19,   19, 0x0a,
     331,   19,   19,   19, 0x0a,
     358,   19,   19,   19, 0x0a,
     378,   72,   19,   19, 0x0a,
     408,   72,   19,   19, 0x0a,
     439,   72,   19,   19, 0x0a,
     470,   72,   19,   19, 0x0a,
     507,  504,   19,   19, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_px4_ui__MainWindow[] = {
    "px4_ui::MainWindow\0\0change_state_signal(int)\0"
    "change_arming_signal(char)\0,,\0"
    "control_send_pos_signal(double,double,double)\0"
    "on_actionAbout_triggered()\0check\0"
    "on_button_connect_clicked(bool)\0state\0"
    "on_checkbox_use_environment_stateChanged(int)\0"
    "on_button_mode_change_clicked()\0"
    "on_button_arm_clicked()\0"
    "on_button_control_send_pos_clicked()\0"
    "on_button_disarm_clicked()\0"
    "updateLoggingView()\0slot_state(QString,char,char)\0"
    "slot_pos(double,double,double)\0"
    "slot_vel(double,double,double)\0"
    "slot_target(double,double,double)\0im\0"
    "slot_show_frame(QImage)\0"
};

void px4_ui::MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->change_state_signal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->change_arming_signal((*reinterpret_cast< char(*)>(_a[1]))); break;
        case 2: _t->control_send_pos_signal((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 3: _t->on_actionAbout_triggered(); break;
        case 4: _t->on_button_connect_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->on_checkbox_use_environment_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_button_mode_change_clicked(); break;
        case 7: _t->on_button_arm_clicked(); break;
        case 8: _t->on_button_control_send_pos_clicked(); break;
        case 9: _t->on_button_disarm_clicked(); break;
        case 10: _t->updateLoggingView(); break;
        case 11: _t->slot_state((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< char(*)>(_a[2])),(*reinterpret_cast< char(*)>(_a[3]))); break;
        case 12: _t->slot_pos((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 13: _t->slot_vel((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 14: _t->slot_target((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 15: _t->slot_show_frame((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData px4_ui::MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject px4_ui::MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_px4_ui__MainWindow,
      qt_meta_data_px4_ui__MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &px4_ui::MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *px4_ui::MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *px4_ui::MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_px4_ui__MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int px4_ui::MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void px4_ui::MainWindow::change_state_signal(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void px4_ui::MainWindow::change_arming_signal(char _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void px4_ui::MainWindow::control_send_pos_signal(double _t1, double _t2, double _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
