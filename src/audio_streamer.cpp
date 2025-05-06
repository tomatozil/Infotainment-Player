#include "audio_streamer.h"

AudioStreamer::AudioStreamer(QObject *parent) : Player(parent) {
    m_bus = nullptr;
    m_busWatchId = 0;
}

AudioStreamer::~AudioStreamer() {
    cleanup();
}

void AudioStreamer::initGStreamer() {
    m_pipeline = gst_element_factory_make("playbin", "player");
    if (!m_pipeline) {
        emit errorOccurred("Failed to create playbin");
        return;
    }

    m_bus = gst_element_get_bus(m_pipeline);
    m_busWatchId = gst_bus_add_watch(m_bus, busCallback, this);
}

void AudioStreamer::cleanup() {
    if (m_busWatchId) {
        gst_bus_remove_watch(m_bus);
        m_busWatchId = 0;
    }
    if (m_bus) {
        gst_object_unref(m_bus);
        m_bus = nullptr;
    }
}

gboolean AudioStreamer::busCallback(GstBus *bus, GstMessage *msg, gpointer userData) {
    AudioStreamer *streamer = static_cast<AudioStreamer*>(userData);
    switch (GST_MESSAGE_TYPE(msg)) {
        case GST_MESSAGE_STATE_CHANGED: {
            // 파이프라인 자신(pipeline)에서만 상태변경 추적
            if (GST_MESSAGE_SRC(msg) == GST_OBJECT(streamer->m_pipeline)) {
                GstState oldS, newS;
                gst_message_parse_state_changed(msg, &oldS, &newS, nullptr);
                bool playing = (newS == GST_STATE_PLAYING);
                streamer->m_isPlaying = playing;
                emit streamer->playingChanged();
            }
            break;
        }
        case GST_MESSAGE_ERROR: {
            GError *error;
            gchar *debug_info;
            gst_message_parse_error(msg, &error, &debug_info);
            streamer->errorOccurred(QString::fromUtf8(error->message));
            g_error_free(error);
            g_free(debug_info);
            break;
        }
        case GST_MESSAGE_EOS:
            streamer->stop();
            break;
        
        default:
            break;
    }
    return TRUE;
}

void AudioStreamer::play(const QString &source) {
    if (!m_pipeline) {
        initGStreamer();
    }

    g_object_set(G_OBJECT(m_pipeline), "uri", qPrintable(source), nullptr);
    gst_element_set_state(m_pipeline, GST_STATE_PLAYING);
}

void AudioStreamer::pause() {
    gst_element_set_state(m_pipeline, GST_STATE_PAUSED);
}

void AudioStreamer::stop() {
    gst_element_set_state(m_pipeline, GST_STATE_NULL);
}

void AudioStreamer::setVolume(int volume) {
    g_object_set(G_OBJECT(m_pipeline), "volume", volume, nullptr);
}

void AudioStreamer::seek(int position) {
    if (GST_IS_ELEMENT(m_pipeline)) {
        gst_element_seek_simple(m_pipeline, GST_FORMAT_TIME, GST_SEEK_FLAG_FLUSH, GST_SECOND * position);
    }
}