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
#ifndef HAPPYPROPERTYSHEETEXTENSION_HPP
#define HAPPYPROPERTYSHEETEXTENSION_HPP

#include <QObject>
#include <QDesignerPropertySheetExtension>

namespace ImaginativeThinking
{
    namespace Widgets
    {
        class HappyWidget;
        namespace Plugins
        {
            class HappyPropertySheetExtension : public QObject, public QDesignerPropertySheetExtension
            {
                Q_OBJECT
                Q_INTERFACES(QDesignerPropertySheetExtension)
            public:
                explicit HappyPropertySheetExtension(HappyWidget* widget, QObject *parent = 0);
                virtual ~HappyPropertySheetExtension() {}

            public:
                int count() const Q_DECL_OVERRIDE;
                int indexOf(const QString &name) const Q_DECL_OVERRIDE;
                QString propertyName(int index) const Q_DECL_OVERRIDE;
                QString propertyGroup(int index) const Q_DECL_OVERRIDE;
                void setPropertyGroup(int index, const QString &group) Q_DECL_OVERRIDE;
                bool hasReset(int index) const Q_DECL_OVERRIDE;
                bool reset(int index) Q_DECL_OVERRIDE;
                bool isVisible(int index) const Q_DECL_OVERRIDE;
                void setVisible(int index, bool b) Q_DECL_OVERRIDE;
                bool isAttribute(int index) const Q_DECL_OVERRIDE;
                void setAttribute(int index, bool b) Q_DECL_OVERRIDE;
                QVariant property(int index) const Q_DECL_OVERRIDE;
                void setProperty(int index, const QVariant &value) Q_DECL_OVERRIDE;
                bool isChanged(int index) const Q_DECL_OVERRIDE;
                void setChanged(int index, bool changed) Q_DECL_OVERRIDE;

            private:
                HappyWidget* m_widget;
            };
        }
    }
}

#endif // HAPPYPROPERTYSHEETEXTENSION_HPP
