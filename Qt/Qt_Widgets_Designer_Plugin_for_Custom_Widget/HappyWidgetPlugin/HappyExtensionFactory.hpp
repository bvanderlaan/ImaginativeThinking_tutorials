/*
 * Copyright 2016 ImaginativeThinking
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
#ifndef HAPPYEXTENSIONFACTORY_HPP
#define HAPPYEXTENSIONFACTORY_HPP

#include <QExtensionFactory>

namespace ImaginativeThinking
{
    namespace Widgets
    {
        namespace Plugins
        {
            class HappyExtensionFactory : public QExtensionFactory
            {
                Q_OBJECT
            public:
                explicit HappyExtensionFactory(QExtensionManager *parent = 0);
                virtual ~HappyExtensionFactory() {}

            protected:
                QObject *createExtension(QObject *object, const QString &iid, QObject *parent) const;
            };
        }
    }
}

#endif // HAPPYEXTENSIONFACTORY_HPP
