import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls.Styles 1.4

Item {    
    id: start
    anchors.fill: parent

    Rectangle {
        id: paneForm
        height: 200
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter

        TextField {
            id: username
            horizontalAlignment: Text.AlignHCenter
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            placeholderText: qsTr("Введите имя пользователя")

            background: Rectangle {
                border.color: "#333"
                border.width: 0
            }
        }

        Text {
            id: usernameLabel
            anchors.bottom: username.top
            anchors.bottomMargin: 10
            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr("Имя пользователя:")
        }


        Button {
            id: startBtn
            anchors.top: username.bottom
            anchors.topMargin: 20
            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr("НАЧАТЬ")

            onClicked: {
                appService.addUser(username.text)
            }
        }
    }
}
