/****************************************************************************
** Meta object code from reading C++ file 'AgencyTCP.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../net/AgencyTCP.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AgencyTCP.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CTCPAgency_t {
    QByteArrayData data[10];
    char stringdata0[120];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CTCPAgency_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CTCPAgency_t qt_meta_stringdata_CTCPAgency = {
    {
QT_MOC_LITERAL(0, 0, 10), // "CTCPAgency"
QT_MOC_LITERAL(1, 11, 13), // "LoginRSSignal"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 13), // "SerchRsSiganl"
QT_MOC_LITERAL(4, 40, 20), // "STRU_SEARCH_USER_RS*"
QT_MOC_LITERAL(5, 61, 16), // "DeletefrRSsignal"
QT_MOC_LITERAL(6, 78, 20), // "DealFriendListSignal"
QT_MOC_LITERAL(7, 99, 5), // "char*"
QT_MOC_LITERAL(8, 105, 9), // "pszBuffer"
QT_MOC_LITERAL(9, 115, 4) // "nLen"

    },
    "CTCPAgency\0LoginRSSignal\0\0SerchRsSiganl\0"
    "STRU_SEARCH_USER_RS*\0DeletefrRSsignal\0"
    "DealFriendListSignal\0char*\0pszBuffer\0"
    "nLen"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CTCPAgency[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       3,    1,   37,    2, 0x06 /* Public */,
       5,    1,   40,    2, 0x06 /* Public */,
       6,    2,   43,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, 0x80000000 | 7, QMetaType::Int,    8,    9,

       0        // eod
};

void CTCPAgency::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CTCPAgency *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->LoginRSSignal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->SerchRsSiganl((*reinterpret_cast< STRU_SEARCH_USER_RS*(*)>(_a[1]))); break;
        case 2: _t->DeletefrRSsignal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->DealFriendListSignal((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CTCPAgency::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CTCPAgency::LoginRSSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CTCPAgency::*)(STRU_SEARCH_USER_RS * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CTCPAgency::SerchRsSiganl)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CTCPAgency::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CTCPAgency::DeletefrRSsignal)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (CTCPAgency::*)(char * , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CTCPAgency::DealFriendListSignal)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CTCPAgency::staticMetaObject = { {
    QMetaObject::SuperData::link<Agency::staticMetaObject>(),
    qt_meta_stringdata_CTCPAgency.data,
    qt_meta_data_CTCPAgency,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CTCPAgency::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CTCPAgency::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CTCPAgency.stringdata0))
        return static_cast<void*>(this);
    return Agency::qt_metacast(_clname);
}

int CTCPAgency::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Agency::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void CTCPAgency::LoginRSSignal(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CTCPAgency::SerchRsSiganl(STRU_SEARCH_USER_RS * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CTCPAgency::DeletefrRSsignal(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CTCPAgency::DealFriendListSignal(char * _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
