import QtQuick 2.0

// Here i'm defining a custom element that I can reuse above
// It is a rectangle with rounded corners, a text label in the middle
// and when clicked will darken and emit a signal.
Item {
    id: myButton
    height: buttonLabel.implicitHeight + 10

    // I have to define alias in order to grant access to my childrens
    // properties to my parent. Property scope in QML is only one level deep.
    // My parent can see all my properties and I can see all my parent and siblings properties
    // but they can't see my childrens properties nor can I see their childrens properties.
    property alias font: buttonLabel.font
    property alias labelColour: buttonLabel.color
    property alias labelText: buttonLabel.text

    // This defines a custom signal. Note the slot for this signal
    // is auto generated and is named "onButtonClicked"
    // As this is a reusable button and I will have many in my application
    // I will define the slot for each instance of this custom element when
    // I include it in the application.
    signal buttonClicked( string num )

    Rectangle {
        anchors.fill: parent
        color: buttonMouseArea.pressed ? Qt.darker("gray", 1.5) : "gray"
        border.color: "lightgray"
        border.width: 2
        radius: 5

        Text {
            id: buttonLabel
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
        }
        MouseArea {
            id: buttonMouseArea
            anchors.fill: parent
            onClicked : {
                // JavaScript
                // Right here I'm emitting the buttonClicked signal
                buttonClicked( buttonLabel.text )
            }
        }
    }
}
