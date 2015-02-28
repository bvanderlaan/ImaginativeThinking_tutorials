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
import ca.imaginativethinking.tutorial.proxymodels 1.0 // import my custom registered module @see main.cpp

ApplicationWindow {
    visible: true
    title: qsTr("QSortFilterProxyModel Sample 2")
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
                text: "In this example we have a single model with 12 entries and via a QSortFilterProxyModel we are filtering that data so that we can display a sub-set of the data in the view depending on which group the user selects"
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
                            MyProxyModel.filter =  FilterTypes.Details;
                            theListView.delegate = detailsDelegate
                        }
                    }
                }
                RadioButton {
                    id: displayGroup
                    exclusiveGroup: groupSelection
                    text: "Display Group"
                    onCheckedChanged: {
                        if ( checked ) {
                            MyProxyModel.filter = FilterTypes.Display;
                            theListView.delegate = displayDelegate
                        }
                    }
                }
                RadioButton {
                    id: evenGroup
                    exclusiveGroup: groupSelection
                    text: "Even Values Group"
                    onCheckedChanged: {
                        if ( checked ) {
                            MyProxyModel.filter = FilterTypes.EvenNumbers;
                            theListView.delegate = valueDelegate
                        }
                    }
                }
            }
            ListView {
                id: theListView
                anchors.left: parent.left
                anchors.right: parent.right
                height: root.rowHeight * 12
                model: MyProxyModel
                delegate: detailsDelegate
            }
        }
    }
}
