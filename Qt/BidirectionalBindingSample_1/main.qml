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
    visible: true
    width: 640
    height: 480
    title: qsTr("Bi-Directonal Binding Sample 1")
    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
    }

    Column {
        spacing: 15
        anchors.fill: parent
        anchors.margins: 15

        Text {
            text: qsTr("This example shows how to setup bi-directonal binding")
            anchors.horizontalCenter: parent.horizontalCenter
            font.pointSize: 14
        }
        Row {
            anchors.left: parent.left
            anchors.right: parent.right
            spacing: 20

            Text {
                text: qsTr("This value is what is currently stored in the View Model:")
            }
            Text {
                text: MyModel.myValue
            }
        }
        Text {
            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr("This input field is bounded to the same value in the view model but only one way, from the ViewModel to the View. If you update it the ViewModel will not change.")
            width: parent.width * 0.9
            wrapMode: Text.WordWrap
        }
        Row {
            anchors.left: parent.left
            anchors.right: parent.right
            spacing: 20

            Text {
                text: qsTr("ViewModel -> View element:")
                width: parent.width / 2
                wrapMode: Text.WordWrap
            }
            Rectangle {
                width: childrenRect.width + 10
                height: childrenRect.height + 4
                border.width: 1
                border.color: "black"

                TextInput {
                    anchors.top: parent.top
                    anchors.topMargin: 2
                    anchors.left: parent.left
                    anchors.leftMargin: 3
                    text: MyModel.myValue
                }
            }
        }
        Text {
            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr("This input field is bounded to the same value in the view model but in both directions (Bi-Directional). If you update it the ViewModel's value will change and so will any UI elements bounded to it.")
            width: parent.width * 0.9
            wrapMode: Text.WordWrap
        }
        Row {
            anchors.left: parent.left
            anchors.right: parent.right
            spacing: 20

            Text {
                text: qsTr("View element <-> ViewModel:")
            }
            Rectangle {
                width: childrenRect.width + 10
                height: childrenRect.height + 4
                border.width: 1
                border.color: "black"

                TextInput {
                    id: biDirectional
                    anchors.left: parent.left
                    anchors.leftMargin: 3
                    anchors.top: parent.top
                    anchors.topMargin: 2
                    text: MyModel.myValue
                }
            }
            Binding {
                target: MyModel
                property: "myValue"
                value: biDirectional.text
            }
        }
        Text {
            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr("If you remove the if statement in MyModel.cpp's setValue() method so that ever time its called the valueChanged() signal is emitted you will get a binding loop warning on the text property of the biDirectional TextInput element above (only when you have actually changed the value in the text input) when you press the reset button.")
            width: parent.width * 0.9
            wrapMode: Text.WordWrap
        }
        Button {
            text: "Reset"
            onClicked:{
                MyModel.myValue = "Hello World"
            }

        }
    }
}
