/****************************************************************************
** Meta object code from reading C++ file 'multimediax.h'
**
** Created: Tue 4. Sep 17:42:22 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../multimediax.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'multimediax.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MultimediaX[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x0a,
      25,   12,   12,   12, 0x0a,
      36,   12,   12,   12, 0x0a,
      47,   12,   12,   12, 0x0a,
      60,   12,   12,   12, 0x08,
      77,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MultimediaX[] = {
    "MultimediaX\0\0openMusic()\0playFile()\0"
    "stopFile()\0openImages()\0openTestWindow()\0"
    "copyToVariaple()\0"
};

const QMetaObject MultimediaX::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MultimediaX,
      qt_meta_data_MultimediaX, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MultimediaX::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MultimediaX::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MultimediaX::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MultimediaX))
        return static_cast<void*>(const_cast< MultimediaX*>(this));
    return QWidget::qt_metacast(_clname);
}

int MultimediaX::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: openMusic(); break;
        case 1: playFile(); break;
        case 2: stopFile(); break;
        case 3: openImages(); break;
        case 4: openTestWindow(); break;
        case 5: copyToVariaple(); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
