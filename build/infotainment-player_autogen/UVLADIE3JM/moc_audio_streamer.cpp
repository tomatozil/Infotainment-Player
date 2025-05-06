/****************************************************************************
** Meta object code from reading C++ file 'audio_streamer.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/audio_streamer.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'audio_streamer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.0. It"
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
struct qt_meta_tag_ZN13AudioStreamerE_t {};
} // unnamed namespace

template <> constexpr inline auto AudioStreamer::qt_create_metaobjectdata<qt_meta_tag_ZN13AudioStreamerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "AudioStreamer",
        "play",
        "",
        "source",
        "PlayerMode",
        "mode",
        "pause",
        "stop",
        "setVolume",
        "volume",
        "seek",
        "position"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'play'
        QtMocHelpers::SlotData<void(const QString &, PlayerMode)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 }, { 0x80000000 | 4, 5 },
        }}),
        // Slot 'pause'
        QtMocHelpers::SlotData<void()>(6, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'stop'
        QtMocHelpers::SlotData<void()>(7, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'setVolume'
        QtMocHelpers::SlotData<void(int)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 9 },
        }}),
        // Slot 'seek'
        QtMocHelpers::SlotData<void(int)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 11 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<AudioStreamer, qt_meta_tag_ZN13AudioStreamerE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject AudioStreamer::staticMetaObject = { {
    QMetaObject::SuperData::link<Player::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13AudioStreamerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13AudioStreamerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN13AudioStreamerE_t>.metaTypes,
    nullptr
} };

void AudioStreamer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<AudioStreamer *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->play((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<PlayerMode>>(_a[2]))); break;
        case 1: _t->pause(); break;
        case 2: _t->stop(); break;
        case 3: _t->setVolume((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->seek((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *AudioStreamer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AudioStreamer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13AudioStreamerE_t>.strings))
        return static_cast<void*>(this);
    return Player::qt_metacast(_clname);
}

int AudioStreamer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Player::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
