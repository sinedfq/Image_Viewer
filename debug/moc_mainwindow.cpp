/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../untitled1/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[21];
    char stringdata0[419];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 25), // "on_addPhotoButton_clicked"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 14), // "onTimerTimeout"
QT_MOC_LITERAL(4, 53, 28), // "on_deletePhotoButton_clicked"
QT_MOC_LITERAL(5, 82, 31), // "on_createDatabaseButton_clicked"
QT_MOC_LITERAL(6, 114, 29), // "on_openDatabaseButton_clicked"
QT_MOC_LITERAL(7, 144, 26), // "on_nextPhotoButton_clicked"
QT_MOC_LITERAL(8, 171, 26), // "on_prevPhotoButton_clicked"
QT_MOC_LITERAL(9, 198, 24), // "on_listWidgetItemClicked"
QT_MOC_LITERAL(10, 223, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(11, 240, 4), // "item"
QT_MOC_LITERAL(12, 245, 26), // "onDeleteAlbumButtonClicked"
QT_MOC_LITERAL(13, 272, 20), // "sortDatabaseByDateUP"
QT_MOC_LITERAL(14, 293, 22), // "sortDatabaseByDateDown"
QT_MOC_LITERAL(15, 316, 24), // "handleContextMenuAction1"
QT_MOC_LITERAL(16, 341, 24), // "handleContextMenuAction2"
QT_MOC_LITERAL(17, 366, 15), // "mousePressEvent"
QT_MOC_LITERAL(18, 382, 12), // "QMouseEvent*"
QT_MOC_LITERAL(19, 395, 5), // "event"
QT_MOC_LITERAL(20, 401, 17) // "openImageInViewer"

    },
    "MainWindow\0on_addPhotoButton_clicked\0"
    "\0onTimerTimeout\0on_deletePhotoButton_clicked\0"
    "on_createDatabaseButton_clicked\0"
    "on_openDatabaseButton_clicked\0"
    "on_nextPhotoButton_clicked\0"
    "on_prevPhotoButton_clicked\0"
    "on_listWidgetItemClicked\0QListWidgetItem*\0"
    "item\0onDeleteAlbumButtonClicked\0"
    "sortDatabaseByDateUP\0sortDatabaseByDateDown\0"
    "handleContextMenuAction1\0"
    "handleContextMenuAction2\0mousePressEvent\0"
    "QMouseEvent*\0event\0openImageInViewer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x08 /* Private */,
       3,    0,   90,    2, 0x08 /* Private */,
       4,    0,   91,    2, 0x08 /* Private */,
       5,    0,   92,    2, 0x08 /* Private */,
       6,    0,   93,    2, 0x08 /* Private */,
       7,    0,   94,    2, 0x08 /* Private */,
       8,    0,   95,    2, 0x08 /* Private */,
       9,    1,   96,    2, 0x08 /* Private */,
      12,    0,   99,    2, 0x08 /* Private */,
      13,    0,  100,    2, 0x08 /* Private */,
      14,    0,  101,    2, 0x08 /* Private */,
      15,    0,  102,    2, 0x08 /* Private */,
      16,    0,  103,    2, 0x08 /* Private */,
      17,    1,  104,    2, 0x08 /* Private */,
      20,    0,  107,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_addPhotoButton_clicked(); break;
        case 1: _t->onTimerTimeout(); break;
        case 2: _t->on_deletePhotoButton_clicked(); break;
        case 3: _t->on_createDatabaseButton_clicked(); break;
        case 4: _t->on_openDatabaseButton_clicked(); break;
        case 5: _t->on_nextPhotoButton_clicked(); break;
        case 6: _t->on_prevPhotoButton_clicked(); break;
        case 7: _t->on_listWidgetItemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 8: _t->onDeleteAlbumButtonClicked(); break;
        case 9: _t->sortDatabaseByDateUP(); break;
        case 10: _t->sortDatabaseByDateDown(); break;
        case 11: _t->handleContextMenuAction1(); break;
        case 12: _t->handleContextMenuAction2(); break;
        case 13: _t->mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 14: _t->openImageInViewer(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
