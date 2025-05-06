#ifndef AUDIO_STREAMER_H
#define AUDIO_STREAMER_H

#include "player.h"
#include <gst/gst.h>

class AudioStreamer : public Player
{
    Q_OBJECT

public:
    explicit AudioStreamer(QObject *parent = nullptr);
    ~AudioStreamer();

public slots:
    void play(const QString &source) override;
    void pause() override;
    void stop() override;
    void setVolume(int volume) override;
    void seek(int position) override;

protected:
    void initGStreamer() override;
    void cleanup() override;

private:
    GstBus *m_bus;
    guint    m_busWatchId;

    static gboolean busCallback(GstBus *bus, GstMessage *msg, gpointer userData);
};

#endif // AUDIOSTREAMER_H