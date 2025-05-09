#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <gst/gst.h>

class Player : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool isPlaying READ isPlaying NOTIFY playingChanged)
    Q_PROPERTY(QString currentSource READ currentSource NOTIFY sourceChanged)
    Q_PROPERTY(QString currentMode READ currentMode NOTIFY modeChanged)

public:
    enum PlayerMode {
        AudioMode,
        VideoMode
    };
    Q_ENUM(PlayerMode)

    explicit Player(QObject *parent = nullptr);
    virtual ~Player();

    bool isPlaying() const { return m_isPlaying; }
    QString currentSource() const { return m_currentSource; }
    QString currentMode() const { return m_currentMode; }

signals:
    void playingChanged();
    void sourceChanged();
    void modeChanged();
    void errorOccurred(const QString &message);

protected:
    bool m_isPlaying;
    QString m_currentSource;
    QString m_currentMode;
    GstElement *m_pipeline;

public slots:
    virtual void play(const QString &source) = 0;
    virtual void pause() = 0;
    virtual void stop() = 0;
    virtual void setVolume(int volume) = 0;
    virtual void seek(int position) = 0;

    virtual void initGStreamer() = 0;
    virtual void cleanup() = 0;
};

#endif // PLAYER_H