/****************************************************************************
** Meta object code from reading C++ file 'qqlogin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../ui/qqlogin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qqlogin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QQLogin_t {
    QByteArrayData data[9];
    char stringdata0[82];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QQLogin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QQLogin_t qt_meta_stringdata_QQLogin = {
    {
QT_MOC_LITERAL(0, 0, 7), // "QQLogin"
QT_MOC_LITERAL(1, 8, 9), // "SendTcpRQ"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 11), // "const char*"
QT_MOC_LITERAL(4, 31, 9), // "SendUdpRQ"
QT_MOC_LITERAL(5, 41, 9), // "turnPage2"
QT_MOC_LITERAL(6, 51, 16), // "rememberpassword"
QT_MOC_LITERAL(7, 68, 5), // "login"
QT_MOC_LITERAL(8, 74, 7) // "MyClose"

    },
    "QQLogin\0SendTcpRQ\0\0const char*\0SendUdpRQ\0"
    "turnPage2\0rememberpassword\0login\0"
    "MyClose"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QQLogin[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   44,    2, 0x06 /* Public */,
       4,    3,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   56,    2, 0x0a /* Public */,
       6,    0,   57,    2, 0x0a /* Public */,
       7,    0,   58,    2, 0x0a /* Public */,
       8,    0,   59,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    2,    2,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int, QMetaType::Int,    2,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QQLogin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QQLogin *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SendTcpRQ((*reinterpret_cast< const char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->SendUdpRQ((*reinterpret_cast< const char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 2: _t->turnPage2(); break;
        case 3: _t->rememberpassword(); break;
        case 4: _t->login(); break;
        case 5: _t->MyClose(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QQLogin::*)(const char * , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QQLogin::SendTcpRQ)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QQLogin::*)(const char * , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QQLogin::SendUdpRQ)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QQLogin::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_QQLogin.data,
    qt_meta_data_QQLogin,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QQLogin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QQLogin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QQLogin.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int QQLogin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void QQLogin::SendTcpRQ(const char * _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QQLogin::SendUdpRQ(const char * _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
