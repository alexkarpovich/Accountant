import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQml.Models 2.1

Item {
    id: accountList
    height: 80
    anchors.left: parent.left
    anchors.right: parent.right

    property var accountModel: appService.getAccountList()

    GridView {
      id: root
      height: parent.height
      anchors.left: parent.left
      anchors.right: parent.right
      cellWidth: 80; cellHeight: 80

      displaced: Transition {
          NumberAnimation { properties: "x,y"; easing.type: Easing.OutQuad }
      }

      model: DelegateModel {
          id: visualModel
          model: accountModel
          delegate: MouseArea {
              id: delegateRoot

              property int visualIndex: DelegateModel.itemsIndex

              width: 80; height: 80
              drag.target: icon

              AccountItem {
                id: icon
              }

              DropArea {
                  anchors { fill: parent; margins: 15 }

                  onEntered: visualModel.items.move(drag.source.visualIndex, delegateRoot.visualIndex)
              }
          }
      }
    }
}
