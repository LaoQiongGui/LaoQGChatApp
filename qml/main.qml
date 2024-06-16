import QtQuick
import QtQuick.Controls
import QtQuick.Controls.Material
import QtQuick.Layouts

import "./Component"

Window {
    id: root
    width: 1280
    height: 720

    // Color Definitions
    property color lightBlue: "#d3e5ff"
    property color whiteColor: "#ffffff"
    property color tabBarColor: whiteColor
    property int currentTab: 0  // Track the currently selected tab

    Rectangle {
        anchors.fill: parent
        color: lightBlue

        ColumnLayout {
            anchors.fill: parent

            // 主区域
            Rectangle {
                Layout.fillWidth: true
                Layout.fillHeight: true
                color: lightBlue

                StackLayout {
                    id: stackLayout
                    anchors.fill: parent
                    currentIndex: currentTab

                    Loader {
                        source: "qrc:/Component/Chat.qml"
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                    }
                    Loader { source: "qrc:/Component/Account.qml" }
                }
            }

            // Tab区域
            Rectangle {
                Layout.fillWidth: true
                Layout.preferredHeight: 60
                Layout.alignment: Qt.AlignBottom
                color: lightBlue

                RowLayout {
                    id: tabBar
                    anchors.fill: parent
                    spacing: 0

                    // Chat Tab
                    TabButton {
                        id: chatTab
                        property int serial: 0
                        icon.source: "qrc:/icons/chat.svg"
                        Layout.preferredWidth: tabBar.width / tabBar.children.length
                        Layout.fillHeight: true
                        onClicked: currentTab = serial
                        checked: currentTab == serial
                    }

                    // Account Tab
                    TabButton {
                        id: accountTab
                        property int serial: 1
                        icon.source: "qrc:/icons/account.svg"
                        Layout.preferredWidth: tabBar.width / tabBar.children.length
                        Layout.fillHeight: true
                        onClicked: currentTab = serial
                        checked: currentTab == serial
                    }
                }
            }
        }
    }
}
