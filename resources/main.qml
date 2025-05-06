import QtQuick
import QtQuick.Controls
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtMultimedia 5.15
import Infotainment 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: "Infotainment Player"

    Column {
        id: controls
        spacing: 10
        anchors.centerIn: parent

        Rectangle {
            id: audioDisplay
            width: parent.width
            height: parent.height * 0.5
            color: "lightgray"

            Text {
                anchors.centerIn: parent
                text: "Audio Player"
            }
        }

        TextField {
            id: sourceInput
            placeholderText: "Enter media source URL"
            width: parent.width * 0.8
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Row {
            spacing: 10
            anchors.horizontalCenter: parent.horizontalCenter

            Button {
                text: "Play"
                onClicked: {
                    audioPlayer.play(sourceInput.text);
                }
            }

            Button {
                text: "Pause"
                onClicked: {
                    audioPlayer.pause();
                }
            }

            Button {
                text: "Stop"
                onClicked: {
                    audioPlayer.stop();
                }
            }
        }

        Slider {
            id: volumeSlider
            width: parent.width * 0.8
            anchors.horizontalCenter: parent.horizontalCenter
            from: 0
            to: 100
            value: 50
            onValueChanged: {
                audioPlayer.setVolume(value);
            }
        }

        Slider {
            id: seekSlider
            width: parent.width * 0.8
            anchors.horizontalCenter: parent.horizontalCenter
            from: 0
            to: 100
            value: 0
            onValueChanged: {
                audioPlayer.seek(value);
            }
        }
    }

    AudioStreamer {
        id: audioPlayer
    }

    property string playerType: "AudioStreamer"
}
