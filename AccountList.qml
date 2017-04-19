import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQml.Models 2.1

Item {
    id: accountList
    anchors.left: parent.left
    anchors.right: parent.right

    GridView {
      id: root
      height: 80
      anchors.left: parent.left
      anchors.right: parent.right
      cellWidth: 80; cellHeight: 80

      displaced: Transition {
          NumberAnimation { properties: "x,y"; easing.type: Easing.OutQuad }
      }

      model: DelegateModel {
          id: visualModel
          model: ListModel {
              id: colorModel
              ListElement { color: "blue" }
              ListElement { color: "green" }
              ListElement { color: "red" }
              ListElement { color: "yellow" }
              ListElement { color: "yellow" }
              ListElement { color: "yellow" }
              ListElement { color: "yellow" }
              ListElement { color: "yellow" }
              ListElement { color: "yellow" }
              ListElement { color: "yellow" }
              ListElement { color: "yellow" }
              ListElement { color: "yellow" }

          }
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
