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

#ifndef MYCALCULATORVIEWMODELTEST_H
#define MYCALCULATORVIEWMODELTEST_H

#include "MyCalculatorViewModel.h"

class MyCalculatorViewModelTest : public MyCalculatorViewModel
{
    Q_OBJECT
public:
    MyCalculatorViewModelTest();

    // Adding a set method so we can test the getOperation() method
    void injectOperation( MyCalculator_Operation operation );

    // Adding set methods that do just one thing; set the value.
    // The existing set methods do otherthings like emitt signals; we're just
    // looking to set the value so we can test the get method so we need something
    // simple that won't introduce logic errors that need to be tested first.
    void injectUserInput( int userInput );
    void injectMyResult( int myResult );

    // Exposing the private add() and subtract() methods so they
    // can be put under test independently.
    int addTest( int A, int B);
    int subtractTest( int A, int B);
};

#endif // MYCALCULATORVIEWMODELTEST_H
