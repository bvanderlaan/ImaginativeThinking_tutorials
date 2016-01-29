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
#include <QDesignerPropertySheetExtension>
#include "HappyExtensionFactory.hpp"
#include "HappyWidget.hpp"
#include "HappyPropertySheetExtension.hpp"

using namespace ImaginativeThinking::Widgets::Plugins;

HappyExtensionFactory::HappyExtensionFactory(QExtensionManager *parent) :
    QExtensionFactory(parent)
{

}

QObject *HappyExtensionFactory::createExtension(QObject *object, const QString &iid, QObject *parent) const
{
    if ( iid == Q_TYPEID(QDesignerPropertySheetExtension) )
    {
        HappyWidget* widget = qobject_cast<HappyWidget*>(object);
        if ( widget != nullptr )
        {
            return new HappyPropertySheetExtension( widget, parent );
        }
    }
    return nullptr;
}
