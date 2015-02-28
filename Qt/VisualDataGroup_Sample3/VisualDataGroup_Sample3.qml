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
    title: qsTr("VisualDataModel Sample 3")
    width: 640
    height: 600
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

        ListModel {
            id: myModel
            ListElement { role_display: "One"; role_value: 0; }
            ListElement { role_display: "One"; role_value: 2; }
            ListElement { role_display: "One"; role_value: 3; }
            ListElement { role_display: "One"; role_value: 4; }
            ListElement { role_details: "Two"; role_value: 5; }
            ListElement { role_details: "Three"; role_value: 6; }
            ListElement { role_details: "Four"; role_value: 7; }
            ListElement { role_details: "Five"; role_value: 8; }
            ListElement { role_details: "Six"; role_value: 9; }
            ListElement { role_keyID: "Seven"; role_value: 10; }
            ListElement { role_keyID: "Eight"; role_value: 11; }
            ListElement { role_keyID: "hello"; role_value: 12; }
        }
        VisualDataModel {
            id: theVisualDataModel
            delegate: detailsDelegate
            model: myModel
            groups: [
                VisualDataGroup {
                    includeByDefault: false
                    name: "displayField"
                },
                VisualDataGroup {
                    includeByDefault: false
                    name: "detailsField"
                },
                VisualDataGroup {
                    includeByDefault: false
                    name: "evenNumbers"
                }
            ]
            filterOnGroup: "detailsField"
            Component.onCompleted: {
                var rowCount = myModel.count;
                items.remove(0,rowCount);
                for( var i = 0;i < rowCount;i++ )
                {
                    var entry = myModel.get(i);
                    if(entry.role_display !== undefined) {
                        items.insert(entry, "displayField");
                    }

                    if(entry.role_details !== undefined) {
                        items.insert(entry, "detailsField");
                    }

                    if( ( entry.role_value % 2 ) === 0 ){
                        items.insert(entry, "evenNumbers");
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
            spacing: 20

            Text {
                anchors.horizontalCenter: parent.horizontalCenter
                width: 600
                wrapMode: Text.WordWrap
                text: "In this example we have a single model with 12 entries and via a Visual Data Group we are filtering that data so that we can display a sub-set of the data in the view depending on which group the user selects"
            }
            Row {
                anchors.left: parent.left
                anchors.right: parent.right

                ExclusiveGroup {
                    id: groupSelection
                }
                RadioButton {
                    id: detailsGroup
                    exclusiveGroup: groupSelection
                    text: "Details Group"
                    checked:  true
                    onCheckedChanged: {
                        if ( checked ) {
                            theVisualDataModel.delegate = detailsDelegate
                            theVisualDataModel.filterOnGroup =  "detailsField";
                        }
                    }
                }
                RadioButton {
                    id: displayGroup
                    exclusiveGroup: groupSelection
                    text: "Display Group"
                    onCheckedChanged: {
                        if ( checked ) {
                            theVisualDataModel.delegate = displayDelegate
                            theVisualDataModel.filterOnGroup =  "displayField";
                        }
                    }
                }
                RadioButton {
                    id: evenGroup
                    exclusiveGroup: groupSelection
                    text: "Even Values Group"
                    onCheckedChanged: {
                        if ( checked ) {
                            theVisualDataModel.delegate = valueDelegate
                            theVisualDataModel.filterOnGroup =  "evenNumbers";
                        }
                    }
                }
            }
            ListView {
                id: theListView
                anchors.left: parent.left
                anchors.right: parent.right
                height: root.rowHeight * 12
                model: theVisualDataModel
            }
        }
    }
}
