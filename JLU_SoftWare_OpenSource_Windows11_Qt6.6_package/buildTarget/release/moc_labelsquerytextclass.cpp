/****************************************************************************
** Meta object code from reading C++ file 'labelsquerytextclass.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../sourceCode/labelsquerytextclass.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'labelsquerytextclass.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSlabelsQueryTextClassENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSlabelsQueryTextClassENDCLASS = QtMocHelpers::stringData(
    "labelsQueryTextClass",
    "finishEditingLabels",
    ""
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSlabelsQueryTextClassENDCLASS_t {
    uint offsetsAndSizes[6];
    char stringdata0[21];
    char stringdata1[20];
    char stringdata2[1];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSlabelsQueryTextClassENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSlabelsQueryTextClassENDCLASS_t qt_meta_stringdata_CLASSlabelsQueryTextClassENDCLASS = {
    {
        QT_MOC_LITERAL(0, 20),  // "labelsQueryTextClass"
        QT_MOC_LITERAL(21, 19),  // "finishEditingLabels"
        QT_MOC_LITERAL(41, 0)   // ""
    },
    "labelsQueryTextClass",
    "finishEditingLabels",
    ""
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSlabelsQueryTextClassENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   20,    2, 0x06,    1 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject labelsQueryTextClass::staticMetaObject = { {
    QMetaObject::SuperData::link<smartLineEditClass::staticMetaObject>(),
    qt_meta_stringdata_CLASSlabelsQueryTextClassENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSlabelsQueryTextClassENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSlabelsQueryTextClassENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<labelsQueryTextClass, std::true_type>,
        // method 'finishEditingLabels'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void labelsQueryTextClass::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<labelsQueryTextClass *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->finishEditingLabels(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (labelsQueryTextClass::*)();
            if (_t _q_method = &labelsQueryTextClass::finishEditingLabels; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject *labelsQueryTextClass::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *labelsQueryTextClass::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSlabelsQueryTextClassENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return smartLineEditClass::qt_metacast(_clname);
}

int labelsQueryTextClass::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = smartLineEditClass::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void labelsQueryTextClass::finishEditingLabels()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
