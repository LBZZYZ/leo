/****************************************************************************
** Meta object code from reading C++ file 'AddFriendWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../ui/AddFirendsWindow/AddFriendWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AddFriendWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UiSearchResultItem_t {
    QByteArrayData data[1];
    char stringdata0[19];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UiSearchResultItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UiSearchResultItem_t qt_meta_stringdata_UiSearchResultItem = {
    {
QT_MOC_LITERAL(0, 0, 18) // "UiSearchResultItem"

    },
    "UiSearchResultItem"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UiSearchResultItem[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void UiSearchResultItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject UiSearchResultItem::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_UiSearchResultItem.data,
    qt_meta_data_UiSearchResultItem,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *UiSearchResultItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UiSearchResultItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UiSearchResultItem.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int UiSearchResultItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_AddFriendWindow_t {
    QByteArrayData data[11];
    char stringdata0[187];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AddFriendWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AddFriendWindow_t qt_meta_stringdata_AddFriendWindow = {
    {
QT_MOC_LITERAL(0, 0, 15), // "AddFriendWindow"
QT_MOC_LITERAL(1, 16, 26), // "SearchFriendsRequestSignal"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 11), // "const char*"
QT_MOC_LITERAL(4, 56, 15), // "AddMsgToMsgList"
QT_MOC_LITERAL(5, 72, 22), // "AddFriendRequestSignal"
QT_MOC_LITERAL(6, 95, 28), // "OnSearchFriendsButtonPressed"
QT_MOC_LITERAL(7, 124, 24), // "OnAddFriendButtonPressed"
QT_MOC_LITERAL(8, 149, 27), // "OnRecvSearchFriendsResponse"
QT_MOC_LITERAL(9, 177, 4), // "data"
QT_MOC_LITERAL(10, 182, 4) // "size"

    },
    "AddFriendWindow\0SearchFriendsRequestSignal\0"
    "\0const char*\0AddMsgToMsgList\0"
    "AddFriendRequestSignal\0"
    "OnSearchFriendsButtonPressed\0"
    "OnAddFriendButtonPressed\0"
    "OnRecvSearchFriendsResponse\0data\0size"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AddFriendWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   44,    2, 0x06 /* Public */,
       4,    3,   49,    2, 0x06 /* Public */,
       5,    0,   56,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   57,    2, 0x0a /* Public */,
       7,    0,   58,    2, 0x0a /* Public */,
       8,    2,   59,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::LongLong, 0x80000000 | 3, QMetaType::Int,    2,    2,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    9,   10,

       0        // eod
};

void AddFriendWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AddFriendWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SearchFriendsRequestSignal((*reinterpret_cast< const char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->AddMsgToMsgList((*reinterpret_cast< long long(*)>(_a[1])),(*reinterpret_cast< const char*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 2: _t->AddFriendRequestSignal(); break;
        case 3: _t->OnSearchFriendsButtonPressed(); break;
        case 4: _t->OnAddFriendButtonPressed(); break;
        case 5: _t->OnRecvSearchFriendsResponse((*reinterpret_cast< const char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AddFriendWindow::*)(const char * , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AddFriendWindow::SearchFriendsRequestSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AddFriendWindow::*)(long long , const char * , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AddFriendWindow::AddMsgToMsgList)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (AddFriendWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AddFriendWindow::AddFriendRequestSignal)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AddFriendWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_AddFriendWindow.data,
    qt_meta_data_AddFriendWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AddFriendWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AddFriendWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AddFriendWindow.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int AddFriendWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void AddFriendWindow::SearchFriendsRequestSignal(const char * _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AddFriendWindow::AddMsgToMsgList(long long _t1, const char * _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void AddFriendWindow::AddFriendRequestSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
