/****************************************************************************
** Meta object code from reading C++ file 'player.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/player.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'player.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN6PlayerE_t {};
} // unnamed namespace

template <> constexpr inline auto Player::qt_create_metaobjectdata<qt_meta_tag_ZN6PlayerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "Player",
        "playingChanged",
        "",
        "sourceChanged",
        "modeChanged",
        "errorOccurred",
        "message",
        "play",
        "source",
        "PlayerMode",
        "mode",
        "pause",
        "stop",
        "setVolume",
        "volume",
        "seek",
        "position",
        "initGStreamer",
        "cleanup",
        "isPlaying",
        "currentSource",
        "currentMode",
        "AudioMode",
        "VideoMode"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'playingChanged'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'sourceChanged'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'modeChanged'
        QtMocHelpers::SignalData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'errorOccurred'
        QtMocHelpers::SignalData<void(const QString &)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 6 },
        }}),
        // Slot 'play'
        QtMocHelpers::SlotData<void(const QString &, PlayerMode)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 8 }, { 0x80000000 | 9, 10 },
        }}),
        // Slot 'pause'
        QtMocHelpers::SlotData<void()>(11, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'stop'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'setVolume'
        QtMocHelpers::SlotData<void(int)>(13, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 14 },
        }}),
        // Slot 'seek'
        QtMocHelpers::SlotData<void(int)>(15, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 16 },
        }}),
        // Slot 'initGStreamer'
        QtMocHelpers::SlotData<void()>(17, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'cleanup'
        QtMocHelpers::SlotData<void()>(18, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'isPlaying'
        QtMocHelpers::PropertyData<bool>(19, QMetaType::Bool, QMC::DefaultPropertyFlags, 0),
        // property 'currentSource'
        QtMocHelpers::PropertyData<QString>(20, QMetaType::QString, QMC::DefaultPropertyFlags, 1),
        // property 'currentMode'
        QtMocHelpers::PropertyData<QString>(21, QMetaType::QString, QMC::DefaultPropertyFlags, 2),
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'PlayerMode'
        QtMocHelpers::EnumData<PlayerMode>(9, 9, QMC::EnumFlags{}).add({
            {   22, PlayerMode::AudioMode },
            {   23, PlayerMode::VideoMode },
        }),
    };
    return QtMocHelpers::metaObjectData<Player, qt_meta_tag_ZN6PlayerE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject Player::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN6PlayerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN6PlayerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN6PlayerE_t>.metaTypes,
    nullptr
} };

void Player::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<Player *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->playingChanged(); break;
        case 1: _t->sourceChanged(); break;
        case 2: _t->modeChanged(); break;
        case 3: _t->errorOccurred((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->play((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<PlayerMode>>(_a[2]))); break;
        case 5: _t->pause(); break;
        case 6: _t->stop(); break;
        case 7: _t->setVolume((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->seek((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 9: _t->initGStreamer(); break;
        case 10: _t->cleanup(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (Player::*)()>(_a, &Player::playingChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (Player::*)()>(_a, &Player::sourceChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (Player::*)()>(_a, &Player::modeChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (Player::*)(const QString & )>(_a, &Player::errorOccurred, 3))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<bool*>(_v) = _t->isPlaying(); break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->currentSource(); break;
        case 2: *reinterpret_cast<QString*>(_v) = _t->currentMode(); break;
        default: break;
        }
    }
}

const QMetaObject *Player::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Player::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN6PlayerE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Player::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void Player::playingChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Player::sourceChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Player::modeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Player::errorOccurred(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}
QT_WARNING_POP
