#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "player.h"
#include "audio_streamer.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    // Player는 추상 타입이므로
    qmlRegisterUncreatableType<Player>(
        "Infotainment", 1, 0, "Player",
        QStringLiteral("Player is abstract")
    );

    // 구현체만 등록
    qmlRegisterType<AudioStreamer>(
        "Infotainment", 1, 0, "AudioStreamer"
    );

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
