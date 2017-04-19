import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQml.Models 2.1

  GridView {
      id: root
      width: 320; height: 480
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
              ListElement { color: "orange" }
              ListElement { color: "purple" }
              ListElement { color: "cyan" }
              ListElement { color: "magenta" }
              ListElement { color: "chartreuse" }
              ListElement { color: "aquamarine" }
              ListElement { color: "indigo" }
              ListElement { color: "black" }
              ListElement { color: "lightsteelblue" }
              ListElement { color: "violet" }
              ListElement { color: "grey" }
              ListElement { color: "springgreen" }
              ListElement { color: "salmon" }
              ListElement { color: "blanchedalmond" }
              ListElement { color: "forestgreen" }
              ListElement { color: "pink" }
              ListElement { color: "navy" }
              ListElement { color: "goldenrod" }
              ListElement { color: "crimson" }
              ListElement { color: "teal" }
          }
          delegate: MouseArea {
              id: delegateRoot

              property int visualIndex: DelegateModel.itemsIndex

              width: 80; height: 80
              drag.target: icon

              Rectangle {
                  id: icon
                  width: 72; height: 72
                  anchors {
                      horizontalCenter: parent.horizontalCenter;
                      verticalCenter: parent.verticalCenter
                  }
                  color: model.color
                  radius: 3

                  Drag.active: delegateRoot.drag.active
                  Drag.source: delegateRoot
                  Drag.hotSpot.x: 36
                  Drag.hotSpot.y: 36

                  states: [
                      State {
                          when: icon.Drag.active
                          ParentChange {
                              target: icon
                              parent: root
                          }

                          AnchorChanges {
                              target: icon;
                              anchors.horizontalCenter: undefined;
                              anchors.verticalCenter: undefined
                          }
                      }
                  ]
              }

              DropArea {
                  anchors { fill: parent; margins: 15 }

                  onEntered: visualModel.items.move(drag.source.visualIndex, delegateRoot.visualIndex)
              }
          }
      }
  }

