/*
 * Copyright 2014 ImaginativeThinking
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
import QtQuick 2.2
import QtQuick.Controls 1.1
import QtQuick.Window 2.0

ApplicationWindow {
    title: qsTr("QSortFilterProxyModel Sample 1")
    width: 640
    height: 850
    visible: true
    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
    }

    Item {
        id: root
        anchors.fill: parent
        readonly property int rowHeight: 25

        Component {
            id: detailsDelegate

            Rectangle {
                anchors.left: parent.left
                anchors.right: parent.right
                height: root.rowHeight
                color: "yellow"
                border.color: "black"

                Text {
                    text: role_details
                    anchors.centerIn: parent
                }
            }
        }
        Component{
            id: displayDelegate

            Rectangle {
                anchors.left: parent.left
                anchors.right: parent.right
                height: root.rowHeight
                color: "green"
                border.color: "black"

                Text {
                    text: role_display
                    anchors.centerIn: parent
                }
            }
        }
        Component{
            id: valueDelegate

            Rectangle {
                anchors.left: parent.left
                anchors.right: parent.right
                height: root.rowHeight
                color: "lightblue"
                border.color: "black"

                Text {
                    text: role_value
                    anchors.centerIn: parent
                }
            }
        }
        Column{
            id: theColumn
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.margins: 10
            height: childrenRect.height
            spacing: 0

            Text {
                anchors.horizontalCenter: parent.horizontalCenter
                width: 600
                wrapMode: Text.WordWrap
                text: "In this example we have a single model with 12 entries and via a QSortFilterProxyModel we are filtering that data so that we can display a sub-set of it in different ListViews"
            }
            Item { width: 20; height: 20; }
            Text {
                text: "In this List View we are only showing the entries that have a details role."
            }
            ListView {
                id: detailsListView
                anchors.left: parent.left
                anchors.right: parent.right
                height: root.rowHeight * 5
                model: DetailsRoleModel
                delegate: detailsDelegate
            }
            Item { width: 20; height: 20; }
            Text {
                text: "In this List View we are only showing the entries that have a display role."
            }
            ListView {
                id: displayListView
                anchors.left: parent.left
                anchors.right: parent.right
                height: root.rowHeight * 4
                model: DisplayRoleModel
                delegate: displayDelegate
            }
            Item { width: 20; height: 20; }
            Text {
                text: "In this List View we are only showing the entries whose value are even."
            }
            ListView {
                id: evenValueListView
                anchors.left: parent.left
                anchors.right: parent.right
                height: root.rowHeight * 7
                model: EvenEntriesModel
                delegate: valueDelegate
            }
            Item { width: 20; height: 20; }
            Text {
                text: "This is the same as above but uses a custom QSortFilterProxyModel."
            }
            ListView {
                id: evenValueListView2
                anchors.left: parent.left
                anchors.right: parent.right
                height: root.rowHeight * 7
                model: MyEvenEntriesModel
                delegate: valueDelegate
            }
            Text {
                text: "Clicking press me will change the value of 2 to 88 and the value of 4 to 99. When 4 turns into 99 it will no longer satisfy the filter and be removed from the even numbers list."
                width: parent.width
                wrapMode: Text.WordWrap
            }
            Button {
                anchors.left: parent.left
                anchors.right: parent.right
                text: "Press Me"
                onClicked: {
                    MyModel.doWork()
                }
            }
        }
    }
}
