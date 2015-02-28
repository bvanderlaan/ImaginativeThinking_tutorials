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
    title: qsTr("VisualDataModel Sample 2")
    width: 640
    height: 600
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

        VisualDataModel {
            id: detailsVisualDataModel
            delegate: detailsDelegate
            model: MyModel // This is a root context set in the main.cpp file.
            groups: [
                VisualDataGroup {
                    includeByDefault: false
                    name: "detailsField"
                }
            ]
            filterOnGroup: "detailsField"
            Component.onCompleted: {
                var rowCount = MyModel.count;
                items.remove(0,rowCount);
                for( var i = 0;i < rowCount;i++ )
                {
                    var entry = MyModel.get(i);
                    if(entry.role_details !== undefined) {
                        items.insert(entry, "detailsField");
                    }
                }
            }
        }
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
        VisualDataModel {
            id: displayVisualDataModel
            delegate: displayDelegate
            model: MyModel
            groups: [
                VisualDataGroup {
                    includeByDefault: false
                    name: "displayField"
                }
            ]
            filterOnGroup: "displayField"
            Component.onCompleted: {
                var rowCount = MyModel.count;
                items.remove(0,rowCount);
                for( var i = 0;i < rowCount;i++ )
                {
                    var entry = MyModel.get(i);
                    if(entry.role_display !== undefined){
                        items.insert(entry, "displayField");
                    }
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
        VisualDataModel {
            id: evenValueVisualDataModel
            delegate: valueDelegate
            model: MyModel
            groups: [
                VisualDataGroup {
                    includeByDefault: false
                    name: "evenNumbers"
                }
            ]
            filterOnGroup: "evenNumbers"
            Component.onCompleted: {
                var rowCount = MyModel.count;
                items.remove(0,rowCount);
                for( var i = 0;i < rowCount;i++ )
                {
                    if ( MyModel.isEven(i) ) {
                        items.insert(MyModel.get(i), "evenNumbers");
                    }
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
                text: "In this example we have a single model with 12 entries and via a Visual Data Group we are filtering that data so that we can display a sub-set of it in different ListViews"
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
                model: detailsVisualDataModel
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
                model: displayVisualDataModel
            }
            Item { width: 20; height: 20; }
            Text {
                text: "In this List View we are only showing the entries whose value are even."
            }
            ListView {
                id: evenValueListView
                anchors.left: parent.left
                anchors.right: parent.right
                height: root.rowHeight * 6
                model: evenValueVisualDataModel
            }
        }
    }
}
