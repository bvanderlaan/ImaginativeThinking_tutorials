/*
 * Copyright 2015 ImaginativeThinking
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

#ifndef MYCHILDCLASS_H
#define MYCHILDCLASS_H

#include "MyParentClass.h"

class MyChildClass: public MyParentClass
{
public:
    MyChildClass() {}
    virtual ~MyChildClass() {}

    virtual double getFOO();
//    virtual int getBAR( bool hello ); // Error MyParentClass::getBAR() is missing its implementation but the error message does not tell you that.
//    int getBAR( bool hello ); // Error MyParentClass::getBAR() is missing its implementation but the error message does not tell you that.
    int getBAR( bool hello ) override; // You get two errors one is the confusion can't declare abstract class you see with the above two lines but the second is hay you marked this override and it does not override anything.
    bool isFubar();
//    QString getHelloWorld() override; // ERROR: MyParentClass::getHelloWorld() is not virtual
};

#endif // MYCHILDCLASS_H
