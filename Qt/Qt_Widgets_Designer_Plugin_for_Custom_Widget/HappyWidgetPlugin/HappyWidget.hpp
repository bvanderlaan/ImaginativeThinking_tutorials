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
#ifndef HAPPYWIDGET_H
#define HAPPYWIDGET_H

#include <QWidget>
#include <QtDesigner/QtDesigner>

namespace ImaginativeThinking
{
    namespace Widgets
    {
        class QDESIGNER_WIDGET_EXPORT HappyWidget : public QWidget
        {
            Q_OBJECT
            Q_PROPERTY(int diameter READ getDiameterInPixels WRITE setDiameterInPixels)
            Q_PROPERTY(QColor color READ getColour WRITE setColour)
        public:
            explicit HappyWidget(QWidget *parent = 0);
            virtual ~HappyWidget() {}

            int getDiameterInPixels() const;
            void setDiameterInPixels( int diameter );

            QColor getColour() const;
            void setColour( const QColor& colour );

            int heightForWidth(int width) const Q_DECL_OVERRIDE;
            QSize sizeHint() const Q_DECL_OVERRIDE;
            QSize minimumSizeHint() const Q_DECL_OVERRIDE;

        protected:
            void paintEvent(QPaintEvent* event) Q_DECL_OVERRIDE;

        private:
            QColor m_colour;
        };
    }
}

#endif // HAPPYWIDGET_H
