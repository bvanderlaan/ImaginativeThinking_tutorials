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

import QtQuick 2.0

/**
 * This is a home grown button control which when pressed
 * will turn dark blue while depressed then return to a blue colour once released.
 * This control emits the signal clicked() when the user completes a press event.
 */
Rectangle {
    width: buttonText.implicitWidth + 20
    height: buttonText.implicitHeight + 20
    color: buttonMouseArea.pressed ? "darkblue" : "blue"

    /** type:string text is the text shown in the center of the button. */
    property alias text: buttonText.text

    /** clicked() is emitted when the user presses and releases the button. */
    signal clicked()

    Text {
        id: buttonText
        anchors.centerIn: parent
        color: "white"
    }
    MouseArea {
        id: buttonMouseArea
        anchors.fill: parent
        onClicked: {
            parent.clicked();
        }
    }
}
