import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import QtQuick.Window 2.0
import QtGraphicalEffects 1.0

ApplicationWindow {
    id: appWindow
    title: qsTr("Accountant")
    visible: true
    width: 640
    height: 480

    property bool isLoggedIn: appService.isLoggedIn()

    Connections {
        target: appService

        onUserAdded: {
            isLoggedIn = true
        }
    }

    Loader {
        id: stateLoader
        anchors.fill: parent
        source: isLoggedIn ? "LoggedIn.qml" : "Start.qml"
    }

    Component.onCompleted: {
        setX(Screen.width / 2 - width / 2);
        setY(Screen.height / 2 - height / 2);
    }
}
