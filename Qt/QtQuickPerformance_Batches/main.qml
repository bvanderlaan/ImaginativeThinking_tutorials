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

ApplicationWindow {
    id: root
    title: qsTr("Qt Quick Performance: Batches")
    width: 640
    height: 480
    menuBar: menuBar
    visible: true
    property bool clipElements: false

    MenuBar {
        id: menuBar

        Menu {
            title: qsTr("File")

            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
    }
    Button {
        anchors.top: parent.top
        anchors.topMargin: 20
        anchors.horizontalCenter: parent.horizontalCenter
        text: root.clipElements ? "Disable Clipping" : "Enable Clipping"
        onClicked: {
            root.clipElements = !root.clipElements
        }
    }
    Row {
        spacing: 100
        anchors.centerIn: parent
        width: childrenRect.width
        height: childrenRect.height

        Rectangle {
            width: childrenRect.width
            height: childrenRect.height
            color: "transparent"
            border.width: 2
            border.color: "red"

            ListView {
                id: listOne
                delegate: itemOneDelegate
                model: theModel
                width: 100
                height: childrenRect.height
            }
        }
        Rectangle {
            width: childrenRect.width
            height: childrenRect.height
            color: "transparent"
            border.width: 2
            border.color: "blue"

            ListView {
                id: listTwo
                delegate: itemTwoDelegate
                model: theModel
                width: 100
                height: childrenRect.height
            }
        }
    }
    ListModel{
        id: theModel

        ListElement { display : "A" }
        ListElement { display : "B" }
        ListElement { display : "C" }
        ListElement { display : "D" }
        ListElement { display : "E" }
        ListElement { display : "F" }
    }
    Component {
        id: itemOneDelegate

        Item {
            anchors.left: parent.left
            anchors.right: parent.right
            height: childrenRect.height + 10

            Text {
                text: clip ? display + " (clipped)" : display
                color: "red"
                anchors.horizontalCenter: parent.horizontalCenter
                clip: root.clipElements
            }
        }
    }
    Component {
        id: itemTwoDelegate

        Item {
            anchors.left: parent.left
            anchors.right: parent.right
            height: childrenRect.height + 10

            Text {
                text: clip ? display + " (clipped)" : display
                color: "blue"
                anchors.horizontalCenter: parent.horizontalCenter
                clip: root.clipElements
            }
        }
    }
}
