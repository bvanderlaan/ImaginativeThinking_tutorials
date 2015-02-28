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

#ifndef QTQUICKSAMPLEAPPLICATIONTEST_H
#define QTQUICKSAMPLEAPPLICATIONTEST_H

#include <QObject>

class QtQuickSampleApplicationTest : public QObject
{
    Q_OBJECT
public:
    explicit QtQuickSampleApplicationTest( QObject *parent = 0);

private slots:
    void myCalculatorViewModelUserInputDefaultValuesTest();
    void myCalculatorViewModelGetUserInputTest();
    void myCalculatorViewModelSetUserInputTest();
    void myCalculatorViewModelMyResultDefaultValuesTest();
    void myCalculatorViewModelGetMyResultTest();
    void myCalculatorViewModelSetMyResultTest();
    void myCalculatorViewModelOperationDefaultValuesTest();
    void myCalculatorViewModelOperationTest();
    void myCalculatorViewModelAddTest();
    void myCalculatorViewModelSubtractTest();
    void myCalculatorViewModelHandleClearTest();
    void myCalculatorViewModelHandleSubtractionNoOperatorTest();
    void myCalculatorViewModelHandleSubtractionSubtractOperatorTest();
    void myCalculatorViewModelHandleAdditionNoOperatorTest();
    void myCalculatorViewModelHandleAdditionOperatorTest();
    void myCalculatorViewModelHandleEqualsNoOperatorTest();
    void myCalculatorViewModelHandleEqualsAdditionOperatorTest();
    void myCalculatorViewModelHandleEqualsSubtractionOperatorTest();
};

#endif // QTQUICKSAMPLEAPPLICATIONTEST_H
