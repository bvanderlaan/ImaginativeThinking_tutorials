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
#include <QPainter>
#include "HappyWidget.hpp"

using namespace ImaginativeThinking::Widgets;

HappyWidget::HappyWidget(QWidget *parent) :
    QWidget(parent),
    m_diameterInPixels(100),
    m_colour( QColor("yellow") )
{

}

double HappyWidget::getDiameterInPixels() const
{
    return m_diameterInPixels;
}

void HappyWidget::setDiameterInPixels(double diameter)
{
    if ( m_diameterInPixels != diameter )
    {
        m_diameterInPixels = diameter;
        update();
    }
}

QColor HappyWidget::getColour() const
{
    return m_colour;
}

void HappyWidget::setColour(const QColor &colour)
{
    if ( m_colour != colour )
    {
        m_colour = colour;
        update();
    }
}

int HappyWidget::heightForWidth(int width) const
{
    return width;
}

QSize HappyWidget::sizeHint() const
{
    return QSize( m_diameterInPixels, m_diameterInPixels );
}

QSize HappyWidget::minimumSizeHint() const
{
    return QSize( 100, 100 );
}

void HappyWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED( event );

    int x( 0 );
    int y( 0 );
    int width = x + m_diameterInPixels;
    int height = y + m_diameterInPixels;
    QBrush brush( m_colour );

    QPainter painter(this);
    painter.setBrush( brush );
    painter.setPen( QColor("black") );
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.drawEllipse( x, y, (width - 1), (height - 1) );
}
