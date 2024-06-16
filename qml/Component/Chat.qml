import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Dialogs
import QtQuick.Controls.Material

import Component

import "./Chat"

Item {
    property color lightBlue: "#d3e5ff"
    property color whiteColor: "#ffffff"
    property int currentSession: 0

    anchors.fill: parent

    ChatHandler {
        id: chatHandler
    }

    ColumnLayout {
        anchors.fill: parent

        // 会话标签区域
        RowLayout {
            id: chatTabArea
            Layout.alignment: Qt.AlignTop
            Layout.fillWidth: true
            Layout.preferredHeight: 60

            Repeater {
                model: chatHandler.chatSessions

                delegate: SessionTab {
                    required property variant modelData
                    title: modelData.title
                }
            }

            Button {
                id: newSessionBtn
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
                icon.source: "qrc:/icons/add_circle.svg"

                onClicked: {
                    chatHandler.newChatSession()
                }
            }
        }

        // 会话区域
        StackLayout {
            id: chatSessionArea
            currentIndex: currentSession

            Repeater {
                model: chatHandler.chatSessions

                delegate: SessionArea {
                    required property variant modelData
                    chatSession: modelData
                }
            }
        }

        // 提问区域
    }
}
