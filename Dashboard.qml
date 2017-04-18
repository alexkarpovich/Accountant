import QtQuick 2.0
import QtQuick.Controls 2.0

Item {    
    anchors.fill: parent

    Rectangle {
        id: accounts
        height: 50
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        color: '#bbbbbb'
    }

    Rectangle {
        anchors.top: accounts.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
    }
}
