/****************************************************************************
** Meta object code from reading C++ file 'qdownloader.h'
**
** Created: Wed Mar 14 11:25:49 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "qdownloader.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qdownloader.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QDownloader[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   13,   12,   12, 0x08,
      49,   12,   12,   12, 0x08,
      76,   12,   12,   12, 0x08,
      90,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QDownloader[] = {
    "QDownloader\0\0,\0onDownloadProgress(qint64,qint64)\0"
    "onFinished(QNetworkReply*)\0onReadyRead()\0"
    "onReplyFinished()\0"
};

const QMetaObject QDownloader::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QDownloader,
      qt_meta_data_QDownloader, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QDownloader::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QDownloader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QDownloader::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QDownloader))
        return static_cast<void*>(const_cast< QDownloader*>(this));
    return QObject::qt_metacast(_clname);
}

int QDownloader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: onDownloadProgress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 1: onFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 2: onReadyRead(); break;
        case 3: onReplyFinished(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
