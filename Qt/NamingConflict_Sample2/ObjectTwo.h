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

#ifndef OBJECTTWO_H
#define OBJECTTWO_H

#include<QObject>

/**
 * @brief The ObjectTwo class is a simple object with a signle property value.
 */
class ObjectTwo : public QObject
{
    Q_OBJECT
    Q_PROPERTY( QString value READ getValue NOTIFY valueChanged )

public:
    ObjectTwo();
    virtual ~ObjectTwo();

    /**
     * @return Returns the value of this object
     */
    QString getValue();

signals:
    /** This signal is emitted when the value is changed. **/
    void valueChanged();
};

#endif // OBJECTTWO_H
