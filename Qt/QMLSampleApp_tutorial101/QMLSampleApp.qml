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
                text: "0"
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
                text: "0"
            }
        }
        RowLayout {
            id: buttonRow
            anchors.left: parent.left
            anchors.right: parent.right
            height: 100
            spacing: 5

            // The QtObject is a way to make a non-UI element
            // useful for grouping properties. Here I"m using to
            // give me something similar to an enum.
            QtObject {
                id: operationTypes
                readonly property int none: 0
                readonly property int addition: 1
                readonly property int subtraction: 2
            }

            property int operation: operationTypes.none

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
                                if ( userInput.text === "0") {
                                    userInput.text = num
                                } else {
                                    userInput.text = userInput.text + num
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
                        // This is JavaScript will read/write access to the attributes in the QML

                        myResult.text = "0"
                        userInput.text = "0"
                        buttonRow.operation = operationTypes.none
                    }
                }
                MyButton {
                    anchors.left: parent.left
                    anchors.right: parent.right
                    labelColour: "white"
                    labelText: "-"
                    font: myResult.font
                    onButtonClicked: {
                        var result;
                        if ( buttonRow.operation === operationTypes.none ) {
                            result = userInput.text
                        } else {
                            result = buttonRow.subtract( parseInt( myResult.text ), parseInt( userInput.text ) )
                        }

                        myResult.text = result.toString();
                        userInput.text = "0"
                        buttonRow.operation = operationTypes.subtraction
                    }
                }
                MyButton {
                    anchors.left: parent.left
                    anchors.right: parent.right
                    labelColour: "white"
                    labelText: "+"
                    font: myResult.font
                    onButtonClicked: {
                        var result;
                        if ( buttonRow.operation === operationTypes.none ) {
                            result = userInput.text
                        } else {
                            result = buttonRow.add( parseInt( myResult.text ), parseInt( userInput.text ) )
                        }

                        myResult.text = result.toString();
                        userInput.text = "0"
                        buttonRow.operation = operationTypes.addition
                    }
                }
                MyButton {
                    anchors.left: parent.left
                    anchors.right: parent.right
                    labelColour: "white"
                    labelText: "="
                    font: myResult.font
                    onButtonClicked: {
                        var result;
                        if ( buttonRow.operation === operationTypes.addition ) {
                            result = buttonRow.add( parseInt( myResult.text ), parseInt( userInput.text ) )
                        } else if ( buttonRow.operation === operationTypes.subtraction ) {
                            result = buttonRow.subtract( parseInt( myResult.text ), parseInt( userInput.text ) )
                        } else {
                            result = parseInt( userInput.text )
                        }

                        myResult.text = result.toString();
                        userInput.text = "0"
                        buttonRow.operation = operationTypes.none
                    }
                }
            }

            // These are JavaScript functions
            function add(A, B) {
                return A + B;
            }

            function subtract(A, B) {
                return A - B;
            }
        }
    }
}

