/****************************************************************************
** Meta object code from reading C++ file 'labelquerydialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../labelquerydialog.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'labelquerydialog.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSlabelQuerydialogENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSlabelQuerydialogENDCLASS = QtMocHelpers::stringData(
    "labelQuerydialog",
    "finishSelectingLabel",
    "",
    "newLabelEnlists",
    "refuseSaving",
    "on_acceptAndAddBtn_clicked",
    "on_rejectAndTryAgainBtn_clicked",
    "on_ensureTheLabelRes_clicked",
    "on_removeLabelButton_clicked",
    "closeEvent",
    "QCloseEvent*",
    "events",
    "on_btn_importLabels_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSlabelQuerydialogENDCLASS_t {
    uint offsetsAndSizes[26];
    char stringdata0[17];
    char stringdata1[21];
    char stringdata2[1];
    char stringdata3[16];
    char stringdata4[13];
    char stringdata5[27];
    char stringdata6[32];
    char stringdata7[29];
    char stringdata8[29];
    char stringdata9[11];
    char stringdata10[13];
    char stringdata11[7];
    char stringdata12[28];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSlabelQuerydialogENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSlabelQuerydialogENDCLASS_t qt_meta_stringdata_CLASSlabelQuerydialogENDCLASS = {
    {
        QT_MOC_LITERAL(0, 16),  // "labelQuerydialog"
        QT_MOC_LITERAL(17, 20),  // "finishSelectingLabel"
        QT_MOC_LITERAL(38, 0),  // ""
        QT_MOC_LITERAL(39, 15),  // "newLabelEnlists"
        QT_MOC_LITERAL(55, 12),  // "refuseSaving"
        QT_MOC_LITERAL(68, 26),  // "on_acceptAndAddBtn_clicked"
        QT_MOC_LITERAL(95, 31),  // "on_rejectAndTryAgainBtn_clicked"
        QT_MOC_LITERAL(127, 28),  // "on_ensureTheLabelRes_clicked"
        QT_MOC_LITERAL(156, 28),  // "on_removeLabelButton_clicked"
        QT_MOC_LITERAL(185, 10),  // "closeEvent"
        QT_MOC_LITERAL(196, 12),  // "QCloseEvent*"
        QT_MOC_LITERAL(209, 6),  // "events"
        QT_MOC_LITERAL(216, 27)   // "on_btn_importLabels_clicked"
    },
    "labelQuerydialog",
    "finishSelectingLabel",
    "",
    "newLabelEnlists",
    "refuseSaving",
    "on_acceptAndAddBtn_clicked",
    "on_rejectAndTryAgainBtn_clicked",
    "on_ensureTheLabelRes_clicked",
    "on_removeLabelButton_clicked",
    "closeEvent",
    "QCloseEvent*",
    "events",
    "on_btn_importLabels_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSlabelQuerydialogENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   68,    2, 0x06,    1 /* Public */,
       3,    0,   69,    2, 0x06,    2 /* Public */,
       4,    0,   70,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    0,   71,    2, 0x08,    4 /* Private */,
       6,    0,   72,    2, 0x08,    5 /* Private */,
       7,    0,   73,    2, 0x08,    6 /* Private */,
       8,    0,   74,    2, 0x08,    7 /* Private */,
       9,    1,   75,    2, 0x08,    8 /* Private */,
      12,    0,   78,    2, 0x08,   10 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject labelQuerydialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSlabelQuerydialogENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSlabelQuerydialogENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSlabelQuerydialogENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<labelQuerydialog, std::true_type>,
        // method 'finishSelectingLabel'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'newLabelEnlists'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'refuseSaving'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_acceptAndAddBtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_rejectAndTryAgainBtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_ensureTheLabelRes_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_removeLabelButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'closeEvent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QCloseEvent *, std::false_type>,
        // method 'on_btn_importLabels_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void labelQuerydialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<labelQuerydialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->finishSelectingLabel(); break;
        case 1: _t->newLabelEnlists(); break;
        case 2: _t->refuseSaving(); break;
        case 3: _t->on_acceptAndAddBtn_clicked(); break;
        case 4: _t->on_rejectAndTryAgainBtn_clicked(); break;
        case 5: _t->on_ensureTheLabelRes_clicked(); break;
        case 6: _t->on_removeLabelButton_clicked(); break;
        case 7: _t->closeEvent((*reinterpret_cast< std::add_pointer_t<QCloseEvent*>>(_a[1]))); break;
        case 8: _t->on_btn_importLabels_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (labelQuerydialog::*)();
            if (_t _q_method = &labelQuerydialog::finishSelectingLabel; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (labelQuerydialog::*)();
            if (_t _q_method = &labelQuerydialog::newLabelEnlists; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (labelQuerydialog::*)();
            if (_t _q_method = &labelQuerydialog::refuseSaving; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *labelQuerydialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *labelQuerydialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSlabelQuerydialogENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int labelQuerydialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void labelQuerydialog::finishSelectingLabel()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void labelQuerydialog::newLabelEnlists()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void labelQuerydialog::refuseSaving()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
