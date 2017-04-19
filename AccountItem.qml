import QtQuick 2.0

Item {
    width: 72
    height: 72
    anchors {
        horizontalCenter: parent.horizontalCenter;
        verticalCenter: parent.verticalCenter
    }

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

    Rectangle {
        id: rectId
        width: 54
        height: 54
        anchors.horizontalCenter: parent.horizontalCenter
        color: model.color
        radius: 27
    }

    Text {
        anchors {
            top: rectId.bottom
            horizontalCenter: parent.horizontalCenter
            leftMargin: 5
            rightMargin: 5
        }
        text: model.color
        font.pointSize: 9
    }
}
