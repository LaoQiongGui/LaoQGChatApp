import QtQuick
import QtQuick.Controls
import QtQuick.Controls.Material
import QtQuick.Layouts

import Chat

Rectangle {
    property alias chatSession: sessionAreaHandler.chatSession

    SessionAreaHandler {
        id: sessionAreaHandler
    }
}
