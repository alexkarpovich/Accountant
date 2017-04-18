import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

ApplicationWindow {
    id: appWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("Accountant")

    property bool isLoggedIn: appService.isLoggedIn()

    Connections {
            target: appService

            onUserAdded: {
                isLoggedIn = true
            }
        }

    header: ToolBar {
        visible: isLoggedIn
        RowLayout {
            anchors.fill: parent
            ToolButton {
                text: qsTr("‹")
                onClicked: stack.pop()
            }
            Label {
                text: "Title"
                elide: Label.ElideRight
                horizontalAlignment: Qt.AlignHCenter
                verticalAlignment: Qt.AlignVCenter
                Layout.fillWidth: true
            }
            ToolButton {
                text: qsTr("⋮")
                onClicked: menu.open()
            }
        }
    }

    Loader {
        id: stateLoader
        anchors.fill: parent
        source: isLoggedIn ? "LoggedIn.qml" : "Start.qml"
    }
}
