/****************************************************************************
** Meta object code from reading C++ file 'imdb.h'
**
** Created: Wed Mar 14 11:25:49 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "imdb.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imdb.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_IMDB[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,    6,    5,    5, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_IMDB[] = {
    "IMDB\0\0reply\0successResponse(QNetworkReply*)\0"
};

const QMetaObject IMDB::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_IMDB,
      qt_meta_data_IMDB, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &IMDB::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *IMDB::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *IMDB::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_IMDB))
        return static_cast<void*>(const_cast< IMDB*>(this));
    return QObject::qt_metacast(_clname);
}

int IMDB::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: successResponse((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
