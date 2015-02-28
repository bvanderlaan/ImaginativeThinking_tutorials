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

#ifndef MYCALCULATORVIEWMODEL_H
#define MYCALCULATORVIEWMODEL_H

#include <QObject>

class MyCalculatorViewModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY( int userInput READ getUserInput WRITE setUserInput NOTIFY userInputChanged )
    Q_PROPERTY( int myResult READ getMyResult WRITE setMyResult NOTIFY myResultChanged )
    Q_PROPERTY( int operation READ getOperation )

public:
    MyCalculatorViewModel();

    enum MyCalculator_Operation
    {
        MyCalculator_Operation_None,
        MyCalculator_Operation_Subtration,
        MyCalculator_Operation_Addition
    };

    int getUserInput();
    void setUserInput( int userInput );
    int getMyResult();
    void setMyResult( int myResult );
    int getOperation();

    /**
     * This is the event handler for the Equals button on the view
     */
    Q_INVOKABLE void handleEquals();

    /**
     * This is the event handler for the Addition button on the view
     */
    Q_INVOKABLE void handleAddition();

    /**
     * This is the event handler for the Subtraction button on the view
     */
    Q_INVOKABLE void handleSubtraction();

    /**
     * This is the event handler for the Clear button on the view
     */
    Q_INVOKABLE void handelClear();

signals:

    /**
     * @brief userInputChanged is emitted to tell the view to update any elements binded to the userInput property.
     */
    void userInputChanged();

    /**
     * @brief myResultChanged is emitted to tell the view to update any elements binded to the myResult property.
     */
    void myResultChanged();

private:
    /**
     * A simple addition method
     */
    int add( int A, int B);

    /**
     * A simple subtraction method
     */
    int subtract( int A, int B);

    int m_userInput;
    int m_myResult;
    MyCalculator_Operation m_currentOperation;
};

#endif // MYCALCULATORVIEWMODEL_H
