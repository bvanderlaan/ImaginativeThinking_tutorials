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
import ca.imaginativethinking.tutorial.objectone 1.0 as ObjectOne
import ca.imaginativethinking.tutorial.objecttwo 1.0 as ObjectTwo

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Naming Conflict Sample 2")
    menuBar: menu

    ObjectOne.MyObject {
        id: objectOne
    }
    ObjectTwo.MyObject {
        id: objectTwo
    }
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
    Column {
        anchors.fill: parent
        anchors.margins: 20
        spacing: 40

        Text {
            text: "In this example we have two C++ objects both registered in different module/namespaces " +
                  "but with the same name \"MyObject\". If you were to use both of them in the same QML script " +
                  "you would have a naming conflict. This could occure if the registration " +
                  "was done as part of a library that you linked against and have no control over. How do we " +
                  "resolve C++ component naming conflicts? " +
                  "\n\r\n\rQML like C# allows you to alias the module/namespace that your using. When we " +
                  "import the module 'ca.imaginativethinking.tutorial.objectone' its sort of like a " +
                  "combination of #include<> and the 'using' statemnt in C++. That is not only does it include " +
                  "the module but I can use any of its components without qualification. In order to explicity " +
                  "tell the QML engine which one of the two MyObject components I mean to use I need to " +
                  "qulaify it with an alias. We can use the 'as' keyword to do this. " +
                  "\n\r\n\r\tExample: import ca.imaginativethinking.tutorial.objectone as ObjectOne " +
                  "\n\r\n\rNow  we can use the ObjectOne component explicitly by declaring it like so: " +
                  "\n\r\n\r\t ObjectOne.MyObject {...} "
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
        Column {
            spacing: 4
            anchors.left: parent.left
            anchors.right: parent.right

            Row {
                anchors.horizontalCenter: parent.horizontalCenter
                spacing: 10
                width: childrenRect.width

                Text {
                    text: "Object One: "
                }
                Text {
                    text: objectOne.value
                }
            }
            Row {
                anchors.horizontalCenter: parent.horizontalCenter
                spacing: 10
                width: childrenRect.width

                Text {
                    text: "Object Two: "
                }
                Text {
                    text: objectTwo.value
                }
            }
        }
    }
}
