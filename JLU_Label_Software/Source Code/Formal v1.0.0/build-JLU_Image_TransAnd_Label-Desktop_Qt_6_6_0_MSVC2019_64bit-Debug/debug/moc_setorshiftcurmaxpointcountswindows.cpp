/****************************************************************************
** Meta object code from reading C++ file 'setorshiftcurmaxpointcountswindows.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../JLU_Image_TransAnd_Label/setorshiftcurmaxpointcountswindows.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'setorshiftcurmaxpointcountswindows.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSsetOrShiftCurMaxPointCountsWindowsENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSsetOrShiftCurMaxPointCountsWindowsENDCLASS = QtMocHelpers::stringData(
    "setOrShiftCurMaxPointCountsWindows",
    "finishSelectAndReadyReturn",
    "",
    "on_ensureSelectAndCheckIfLegal_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSsetOrShiftCurMaxPointCountsWindowsENDCLASS_t {
    uint offsetsAndSizes[8];
    char stringdata0[35];
    char stringdata1[27];
    char stringdata2[1];
    char stringdata3[39];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSsetOrShiftCurMaxPointCountsWindowsENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSsetOrShiftCurMaxPointCountsWindowsENDCLASS_t qt_meta_stringdata_CLASSsetOrShiftCurMaxPointCountsWindowsENDCLASS = {
    {
        QT_MOC_LITERAL(0, 34),  // "setOrShiftCurMaxPointCountsWi..."
        QT_MOC_LITERAL(35, 26),  // "finishSelectAndReadyReturn"
        QT_MOC_LITERAL(62, 0),  // ""
        QT_MOC_LITERAL(63, 38)   // "on_ensureSelectAndCheckIfLega..."
    },
    "setOrShiftCurMaxPointCountsWindows",
    "finishSelectAndReadyReturn",
    "",
    "on_ensureSelectAndCheckIfLegal_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSsetOrShiftCurMaxPointCountsWindowsENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   26,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   27,    2, 0x08,    2 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject setOrShiftCurMaxPointCountsWindows::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSsetOrShiftCurMaxPointCountsWindowsENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSsetOrShiftCurMaxPointCountsWindowsENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSsetOrShiftCurMaxPointCountsWindowsENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<setOrShiftCurMaxPointCountsWindows, std::true_type>,
        // method 'finishSelectAndReadyReturn'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_ensureSelectAndCheckIfLegal_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void setOrShiftCurMaxPointCountsWindows::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<setOrShiftCurMaxPointCountsWindows *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->finishSelectAndReadyReturn(); break;
        case 1: _t->on_ensureSelectAndCheckIfLegal_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (setOrShiftCurMaxPointCountsWindows::*)();
            if (_t _q_method = &setOrShiftCurMaxPointCountsWindows::finishSelectAndReadyReturn; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject *setOrShiftCurMaxPointCountsWindows::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *setOrShiftCurMaxPointCountsWindows::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSsetOrShiftCurMaxPointCountsWindowsENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int setOrShiftCurMaxPointCountsWindows::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void setOrShiftCurMaxPointCountsWindows::finishSelectAndReadyReturn()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
