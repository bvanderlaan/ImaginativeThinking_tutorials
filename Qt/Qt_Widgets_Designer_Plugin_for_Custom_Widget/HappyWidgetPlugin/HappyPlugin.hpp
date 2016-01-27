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
#ifndef HAPPYPLUGIN_HPP
#define HAPPYPLUGIN_HPP

#include <QtUiPlugin/QDesignerCustomWidgetInterface>

namespace ImaginativeThinking
{
    namespace Widgets
    {
        namespace Plugins
        {
            class HappyPlugin : public QObject, public QDesignerCustomWidgetInterface
            {
                Q_OBJECT
                Q_INTERFACES(QDesignerCustomWidgetInterface)
            #if QT_VERSION >= QT_VERSION_CHECK(5,0,0)
                Q_PLUGIN_METADATA(IID "ca.imaginativethinking.widget.plugin.HappyPlugin")
            #endif

            public:
                HappyPlugin(QObject *parent = 0);

                QString name() const Q_DECL_OVERRIDE;
                QString group() const Q_DECL_OVERRIDE;
                QString toolTip() const Q_DECL_OVERRIDE;
                QString whatsThis() const Q_DECL_OVERRIDE;
                QString includeFile() const Q_DECL_OVERRIDE;
                QIcon icon() const Q_DECL_OVERRIDE;
                bool isContainer() const Q_DECL_OVERRIDE;
                QWidget *createWidget(QWidget *parent) Q_DECL_OVERRIDE;
            };
        }
    }
}

#endif // HAPPYPLUGIN_HPP
