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
    width: 640
    height: 180
    title: qsTr("qmlRegisterType Sample 1")

    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
    }

    SubMenuProxyModel {
        id: homeMenuModel
        Component.onCompleted: {
            homeMenuModel.setFilter( SubMenuTypes.SubMenuType_Home )
        }
    }
    SubMenuProxyModel {
        id: editMenuModel
        Component.onCompleted: {
            editMenuModel.setFilter( SubMenuTypes.SubMenuType_Edit )
        }
    }
    Column {
        id: theColumn
        spacing: 0
        anchors.fill: parent
        readonly property int menuHeight: 52;
        readonly property int menuWidth: 100;

        Row {
            spacing: 0
            height: parent.menuHeight
            anchors.left: parent.left
            anchors.right: parent.right

            Rectangle {
                color: homeRootMenuMouseArea.containsMouse ? "lightblue" : "black"
                border.color: "lightgrey"
                border.width: 1
                width: theColumn.menuWidth
                anchors.top: parent.top
                anchors.bottom: parent.bottom

                MouseArea {
                    id: homeRootMenuMouseArea
                    anchors.fill: parent
                    hoverEnabled: true // enables the homeRootMenuMouseArea.containtsMouse used above.
                }
                Text {
                    id: subMenuText
                    color: homeRootMenuMouseArea.containsMouse ? "darkblue" : "white"
                    anchors.centerIn: parent
                    text: "Home >"
                }
            }
            ListView {
                id: homeMenu
                orientation: ListView.Horizontal
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                width: childrenRect.width
                model: homeMenuModel
                delegate: subMenuDelegate
            }
        }
        Row {
            spacing: 0
            height: parent.menuHeight
            anchors.left: parent.left
            anchors.right: parent.right

            Rectangle {
                color: editRootMenuMouseArea.containsMouse ? "lightblue" : "black"
                border.color: "lightgrey"
                border.width: 1
                width: theColumn.menuWidth
                anchors.top: parent.top
                anchors.bottom: parent.bottom

                MouseArea {
                    id: editRootMenuMouseArea
                    anchors.fill: parent
                    hoverEnabled: true // enables the editRootMenuMouseArea.containtsMouse used above.
                }
                Text {
                    color: editRootMenuMouseArea.containsMouse ? "darkblue" : "white"
                    anchors.centerIn: parent
                    text: "Edit >"
                }
            }
            ListView {
                id: editMenu
                orientation: ListView.Horizontal
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                width: childrenRect.width
                model: editMenuModel
                delegate: subMenuDelegate
            }
        }
    }
    Component {
        id: subMenuDelegate

        Rectangle {
            color: theMouseArea.containsMouse ? "lightblue" : "black"
            border.color: "lightgrey"
            border.width: 1
            width: theColumn.menuWidth
            anchors.top: parent.top
            anchors.bottom: parent.bottom

            MouseArea {
                id: theMouseArea
                anchors.fill: parent
                hoverEnabled: true // enables the theMouseArea.containtsMouse used above.
            }
            Text {
                id: subMenuText
                color: theMouseArea.containsMouse ? "darkblue" : "white"
                anchors.centerIn: parent
                text: role_display
            }
        }
    }
}
