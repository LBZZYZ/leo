/****************************************************************************
** Meta object code from reading C++ file 'Mediator.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../ui/Mediator/Mediator.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Mediator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Mediator_t {
    QByteArrayData data[15];
    char stringdata0[165];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Mediator_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Mediator_t qt_meta_stringdata_Mediator = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Mediator"
QT_MOC_LITERAL(1, 9, 9), // "DealUdpRQ"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 11), // "const char*"
QT_MOC_LITERAL(4, 32, 9), // "DealTcpRQ"
QT_MOC_LITERAL(5, 42, 14), // "initchatwidget"
QT_MOC_LITERAL(6, 57, 15), // "DealSendMsgSlot"
QT_MOC_LITERAL(7, 73, 5), // "char*"
QT_MOC_LITERAL(8, 79, 13), // "GetFriendList"
QT_MOC_LITERAL(9, 93, 14), // "DealRegisterRS"
QT_MOC_LITERAL(10, 108, 11), // "DealLoginRS"
QT_MOC_LITERAL(11, 120, 14), // "IsAdduiExisted"
QT_MOC_LITERAL(12, 135, 14), // "DealFriendList"
QT_MOC_LITERAL(13, 150, 9), // "pszBuffer"
QT_MOC_LITERAL(14, 160, 4) // "nLen"

    },
    "Mediator\0DealUdpRQ\0\0const char*\0"
    "DealTcpRQ\0initchatwidget\0DealSendMsgSlot\0"
    "char*\0GetFriendList\0DealRegisterRS\0"
    "DealLoginRS\0IsAdduiExisted\0DealFriendList\0"
    "pszBuffer\0nLen"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Mediator[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    3,   59,    2, 0x0a /* Public */,
       4,    2,   66,    2, 0x0a /* Public */,
       5,    1,   71,    2, 0x0a /* Public */,
       6,    2,   74,    2, 0x0a /* Public */,
       8,    0,   79,    2, 0x0a /* Public */,
       9,    1,   80,    2, 0x0a /* Public */,
      10,    1,   83,    2, 0x0a /* Public */,
      11,    1,   86,    2, 0x0a /* Public */,
      12,    2,   89,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int, QMetaType::Int,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 7, QMetaType::Int,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, 0x80000000 | 7, QMetaType::Int,   13,   14,

       0        // eod
};

void Mediator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Mediator *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->DealUdpRQ((*reinterpret_cast< const char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->DealTcpRQ((*reinterpret_cast< const char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->initchatwidget((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->DealSendMsgSlot((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->GetFriendList(); break;
        case 5: _t->DealRegisterRS((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->DealLoginRS((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->IsAdduiExisted((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->DealFriendList((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Mediator::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Mediator.data,
    qt_meta_data_Mediator,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Mediator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Mediator::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Mediator.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Mediator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
