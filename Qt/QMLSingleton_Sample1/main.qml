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
import "qrc:///styles/"

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("QML Singleton Sample 1")
    menuBar: menu

    MenuBar {
        id: menu

        Menu {
            title: qsTr("File")

            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
    }
    GridView {
        anchors.fill: parent
        model: 100
        delegate: gridDelegate
        cellHeight: 50
        cellWidth: cellHeight
    }
    Component {
        id: gridDelegate

        Rectangle {
            width: 50
            height: width
            color: myStyle.colourBlue
            border.color: MyStyle.colourRed
            border.width: MyStyle.borderSize

            Text {
                anchors.centerIn: parent
                text: index
                font.pointSize: myStyle.fontPointSize
                color: myStyle.colourWhite
            }
            MyStyleObject {
                id: myStyle
            }
        }
    }
}
