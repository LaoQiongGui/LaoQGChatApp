import QtQuick
import QtQuick.Controls
import QtQuick.Controls.Material
import QtQuick.Layouts

Rectangle {
    required property string title

    width: 160
    height: 60
    border.color: "black"
    border.width: 3
    radius: 10
    color: "transparent"

    RowLayout {
        spacing: 0
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter

        Text {
            id: titleArea
            text: qsTr(title)
            font.pixelSize: 18
            width: 100
        }

        Button {
            id: deleteSessionBtn
            background: Rectangle {
                width: 40
                height: 40
                radius: 5
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                color: {
                    if (parent.hovered || parent.pressed) {
                        return Qt.rgba(1, 1, 1, 0.6)
                    } else {
                        return "transparent"
                    }
                }
            }
            icon.source: "qrc:/icons/cancel.svg"
        }
    }
}
