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

#ifndef MYMODEL_H
#define MYMODEL_H

#include <QObject>

class MyModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY( QString myValue READ getValue WRITE setValue NOTIFY valueChanged )

public:
    MyModel();
    QString getValue();

public slots:
    void setValue( QString value );

signals:
    void valueChanged();

private:
    QString m_value;

};

#endif // MYMODEL_H
