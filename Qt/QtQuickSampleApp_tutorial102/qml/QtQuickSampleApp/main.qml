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

/**
 * This is a sample application for educational purposes.
 * It is a simple calculator that handles addition and subtration.
 */
import QtQuick 2.0
import QtQuick.Layouts 1.0

Rectangle {
    width: 360
    height: 360
    color: "#6B95FF"

    Rectangle {
        id: exitButton
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.margins: 2
        opacity: 0.5
        border.color: "black"
        border.width: 2
        radius: 5
        width: exitButtonText.implicitWidth + (exitButtonText.anchors.margins * 2)
        height: exitButtonText.implicitHeight + (exitButtonText.anchors.margins*2)
        color:  exitButtonMouseArea.pressed ? Qt.darker(parent.color, 1.5) : "transparent"


        MouseArea {
            id:  exitButtonMouseArea
            anchors.fill: parent
            onClicked: {
                Qt.quit();
            }
        }
        Text {
            id: exitButtonText
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            anchors.margins: 4
            anchors.fill:parent
            font.family: myResult.font.family
            font.pointSize: 16
            text: "Close"
            color: "black"
        }
    }
    Column {
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: exitButton.bottom
        anchors.bottom: parent.bottom
        anchors.margins: 10
        spacing: 10

        Rectangle {
            id: myResultRect
            anchors.left: parent.left
            anchors.right: parent.right
            height: myResult.implicitHeight + 10
            border.color: "#663FFF"
            border.width: 5
            color: "transparent"
            clip: true

            Text {
                id: myResult
                anchors.right: parent.right
                anchors.rightMargin: 10
                anchors.verticalCenter: parent.verticalCenter
                color: "#663FFF"
                font.family: "Arial"
                font.pointSize: 14
                font.bold: true
                text: myCalculatorViewModel.myResult
            }
        }
        Rectangle {
            id: userInputRect
            anchors.left: parent.left
            anchors.right: parent.right
            height: userInput.implicitHeight + 10
            color: "white"
            clip: true

            Text {
                id: userInput
                anchors.right: parent.right
                anchors.rightMargin: 10
                anchors.verticalCenter: parent.verticalCenter
                color: "black"
                font.family: myResult.font.family
                font.pointSize: myResult.font.pointSize
                text: myCalculatorViewModel.userInput
            }
        }
        RowLayout {
            id: buttonRow
            anchors.left: parent.left
            anchors.right: parent.right
            height: 100
            spacing: 5

            //enum
            QtObject {
                id: operationTypes
                readonly property int none: 0
                readonly property int addition: 1
                readonly property int subtraction: 2
            }

            GridView {
                Layout.fillWidth: true
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                model: 10
                cellWidth: 52
                cellHeight: 52
                delegate: MyButton {
                            font: myResult.font
                            labelText: index
                            labelColour: "white"
                            width: 50
                            height: 50

                            onButtonClicked: {
                                // num is the parameter passed into this slot when the signal is emitted
                                // see the signal definision in the MyButton.qml file.
                                if ( myCalculatorViewModel.userInput === 0 ) {
                                    myCalculatorViewModel.userInput = num
                                } else {
                                    myCalculatorViewModel.userInput +=  num
                                }
                            }
                        }
            }
            Column {
                width: 100
                spacing: 5

                // This is a custom control. I created a custom button element
                // and saved it in a file called MyButton.qml. When QtQuick parses
                // this QML and sees this 'unknown' element name it will look for files
                // that match that name for a definision. QtQuick will look in the same directory
                // that this file is saved for other QML files; if my element was in a sub folder I
                // could include it in the look up path by stating that relatvie path in an import statement above.
                MyButton {
                    anchors.left: parent.left
                    anchors.right: parent.right
                    labelColour: "white"
                    labelText: "C"
                    font: myResult.font
                    onButtonClicked: {
                        myCalculatorViewModel.handelClear()
                    }
                }
                MyButton {
                    anchors.left: parent.left
                    anchors.right: parent.right
                    labelColour: "white"
                    labelText: "-"
                    font: myResult.font
                    onButtonClicked: {
                       myCalculatorViewModel.handleSubtraction()
                    }
                }
                MyButton {
                    anchors.left: parent.left
                    anchors.right: parent.right
                    labelColour: "white"
                    labelText: "+"
                    font: myResult.font
                    onButtonClicked: {
                        myCalculatorViewModel.handleAddition()
                    }
                }
                MyButton {
                    anchors.left: parent.left
                    anchors.right: parent.right
                    labelColour: "white"
                    labelText: "="
                    font: myResult.font
                    onButtonClicked: {
                        myCalculatorViewModel.handleEquals()
                    }
                }
            }
        }
    }
}
