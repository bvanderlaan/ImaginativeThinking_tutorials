import QtQuick 2.4
import QtQuick.Controls 1.4
import QtQuick.Window 2.2
import ca.imaginativethinking.tutorials.models 1.0

ApplicationWindow {
    title: qsTr("Qt Quick: TreeView")
    width: 640
    height: 480
    visible: true
    menuBar: MenuBar {
        Menu {
            title: qsTr("&File")

            MenuItem {
                text: qsTr("E&xit")
                onTriggered: Qt.quit();
            }
        }
    }

    MyTreeModel {
        id: theModel
    }
    TreeView {
        anchors.fill: parent
        model: theModel
        itemDelegate: Rectangle {
                   color: ( styleData.row % 2 == 0 ) ? "white" : "lightblue"
                   height: 20

                   Text {
                       anchors.verticalCenter: parent.verticalCenter
                       text: styleData.value === undefined ? "" : styleData.value // The branches don't have a description_role so styleData.value will be undefined
                   }
               }

        TableViewColumn {
            role: "name_role"
            title: "Name"
        }
        TableViewColumn {
            role: "description_role"
            title: "Description"
        }
    }
}
