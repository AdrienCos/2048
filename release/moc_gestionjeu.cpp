/****************************************************************************
** Meta object code from reading C++ file 'gestionjeu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../gestionjeu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gestionjeu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GestionJeu_t {
    QByteArrayData data[17];
    char stringdata0[149];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GestionJeu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GestionJeu_t qt_meta_stringdata_GestionJeu = {
    {
QT_MOC_LITERAL(0, 0, 10), // "GestionJeu"
QT_MOC_LITERAL(1, 11, 13), // "statesChanged"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 9), // "finPartie"
QT_MOC_LITERAL(4, 36, 5), // "arret"
QT_MOC_LITERAL(5, 42, 7), // "newGame"
QT_MOC_LITERAL(6, 50, 6), // "nb_lig"
QT_MOC_LITERAL(7, 57, 6), // "nb_col"
QT_MOC_LITERAL(8, 64, 7), // "newCell"
QT_MOC_LITERAL(9, 72, 10), // "deplGauche"
QT_MOC_LITERAL(10, 83, 10), // "deplDroite"
QT_MOC_LITERAL(11, 94, 8), // "deplHaut"
QT_MOC_LITERAL(12, 103, 7), // "deplBas"
QT_MOC_LITERAL(13, 111, 6), // "states"
QT_MOC_LITERAL(14, 118, 14), // "QList<QString>"
QT_MOC_LITERAL(15, 133, 8), // "resultat"
QT_MOC_LITERAL(16, 142, 6) // "resume"

    },
    "GestionJeu\0statesChanged\0\0finPartie\0"
    "arret\0newGame\0nb_lig\0nb_col\0newCell\0"
    "deplGauche\0deplDroite\0deplHaut\0deplBas\0"
    "states\0QList<QString>\0resultat\0resume"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GestionJeu[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       3,   72, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,
       4,    0,   61,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       5,    2,   62,    2, 0x02 /* Public */,
       8,    0,   67,    2, 0x02 /* Public */,
       9,    0,   68,    2, 0x02 /* Public */,
      10,    0,   69,    2, 0x02 /* Public */,
      11,    0,   70,    2, 0x02 /* Public */,
      12,    0,   71,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
      13, 0x80000000 | 14, 0x00495009,
      15, QMetaType::QString, 0x00495001,
      16, QMetaType::Bool, 0x00495001,

 // properties: notify_signal_id
       0,
       1,
       2,

       0        // eod
};

void GestionJeu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GestionJeu *_t = static_cast<GestionJeu *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->statesChanged(); break;
        case 1: _t->finPartie(); break;
        case 2: _t->arret(); break;
        case 3: _t->newGame((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->newCell(); break;
        case 5: _t->deplGauche(); break;
        case 6: _t->deplDroite(); break;
        case 7: _t->deplHaut(); break;
        case 8: _t->deplBas(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GestionJeu::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GestionJeu::statesChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (GestionJeu::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GestionJeu::finPartie)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (GestionJeu::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GestionJeu::arret)) {
                *result = 2;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QString> >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        GestionJeu *_t = static_cast<GestionJeu *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QList<QString>*>(_v) = _t->readStates(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->verifFinPartie(); break;
        case 2: *reinterpret_cast< bool*>(_v) = _t->arretJeu(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject GestionJeu::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_GestionJeu.data,
      qt_meta_data_GestionJeu,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GestionJeu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GestionJeu::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GestionJeu.stringdata0))
        return static_cast<void*>(const_cast< GestionJeu*>(this));
    return QObject::qt_metacast(_clname);
}

int GestionJeu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void GestionJeu::statesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void GestionJeu::finPartie()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void GestionJeu::arret()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
