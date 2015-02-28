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
import "red" as Red
import "blue" as Blue

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Naming Conflict Sample 1")
    menuBar: menuBar

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
    Column {
        anchors.fill: parent
        anchors.margins: 20
        spacing: 40

        Text {
            text: "In this example we have three button controls all with the exact same name 'Button'. " +
                  "The issue being is that they are not the same control and are in fact three different " +
                  "controls with conflicting names. How do we resolve QML component naming conflicts?" +
                  "\n\r\n\rQML like C# allows you to alias the module/namespace that your using. " +
                  "When we import the directory 'blue' it gets put into the global namespace by default " +
                  "with all the other components. To qulaify it with an alias we can use the 'as' keyword. " +
                  "\n\r\n\r\tExample: import \"blue\" as Blue " +
                  "\n\r\n\rNow  we can use the blue button explicitly by declaring it like so: " +
                  "Blue.Button {...} "
            wrapMode: Text.WordWrap
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.margins: 20
        }
        Rectangle {
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.margins: 60
            height: 2
            color: "green"
        }
        Text {
            id: outputText
            anchors.horizontalCenter: parent.horizontalCenter
            text: "When you press a button this text will change"
        }
        Row {
            spacing: 40
            anchors.horizontalCenter: parent.horizontalCenter

            Button {
                id: qtQuickControlButton
                text: "QtQuick Control Button"
                onClicked: {
                    outputText.text = "The QtQuick Control Button was pressed."
                }
                height: redButton.height
            }
            Red.Button {
                id: redButton
                text: "Red Button"
                onClicked: {
                    outputText.text = "The Red Button was pressed."
                }
            }
            Blue.Button {
                id: blueButton
                text: "Blue Button"
                onClicked: {
                    outputText.text = "The Blue Button was pressed."
                }
            }
        }
    }
}
