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
#include "HappyPropertySheetExtension.hpp"
#include "HappyWidget.hpp"

using namespace ImaginativeThinking::Widgets;
using namespace ImaginativeThinking::Widgets::Plugins;

HappyPropertySheetExtension::HappyPropertySheetExtension(HappyWidget* widget, QObject *parent) :
    QObject(parent),
    m_widget( widget )
{

}

int HappyPropertySheetExtension::count() const
{
    return 6;
}

int HappyPropertySheetExtension::indexOf(const QString &name) const
{
    if ( name == "objectName" )
    {
        return 0;
    }
    else if ( name == "geometry" )
    {
        return 1;
    }
    else if ( name == "diameter" )
    {
        return 2;
    }
    else if ( name == "colour" )
    {
        return 3;
    }
    else if ( name == "hair length" )
    {
        return 4;
    }
    else if ( name == "hair colour" )
    {
        return 5;
    }
    return -1;
}

QString HappyPropertySheetExtension::propertyName(int index) const
{
    if ( index == 0 )
    {
        return "objectName";
    }
    else if ( index == 1 )
    {
        return "geometry";
    }
    else if ( index == 2 )
    {
        return "diameter";
    }
    else if ( index == 3 )
    {
        return "colour";
    }
    else if ( index == 4 )
    {
        return "hair length";
    }
    else if ( index == 5 )
    {
        return "hair colour";
    }
    return QStringLiteral("");
}

QString HappyPropertySheetExtension::propertyGroup(int index) const
{
    switch( index )
    {
        case 0:
            return "QObject";
        case 1:
            return "QWidget";
        case 2:
        case 3:
        default:
            return "Happy Widget Yo!";
        case 4:
        case 5:
            return "Hair";
    }
}

void HappyPropertySheetExtension::setPropertyGroup(int index, const QString &group)
{
    Q_UNUSED( index );
    Q_UNUSED( group );
}

bool HappyPropertySheetExtension::hasReset(int index) const
{
    Q_UNUSED( index );
    return false;
}

bool HappyPropertySheetExtension::reset(int index)
{
    Q_UNUSED( index );
    return false;
}

bool HappyPropertySheetExtension::isVisible(int index) const
{
    Q_UNUSED(index);
    return true;
}

void HappyPropertySheetExtension::setVisible(int index, bool b)
{
    Q_UNUSED( index );
    Q_UNUSED( b );
}

bool HappyPropertySheetExtension::isAttribute(int index) const
{
    Q_UNUSED( index );
    return false;
}

void HappyPropertySheetExtension::setAttribute(int index, bool b)
{
    Q_UNUSED( index );
    Q_UNUSED( b );
}

QVariant HappyPropertySheetExtension::property(int index) const
{
    if ( index == 0 )
    {
        return m_widget->objectName();
    }
    else if ( index == 1 )
    {
        return m_widget->geometry();
    }
    else if ( index == 2 )
    {
        return m_widget->getDiameterInPixels();
    }
    else if ( index == 3 )
    {
        return m_widget->getColour();
    }
    else if ( index == 4 )
    {
        return m_widget->getScalpHair().getLength();
    }
    else if ( index == 5 )
    {
        return m_widget->getScalpHair().getColour();
    }

    return QVariant();
}

void HappyPropertySheetExtension::setProperty(int index, const QVariant &value)
{
    if ( index == 0 )
    {
        m_widget->setObjectName( value.toString() );
    }
    else if ( index == 1 )
    {
        m_widget->setGeometry( value.toRect() );
    }
    else if ( index == 2 )
    {
        m_widget->setDiameterInPixels( value.toInt() );
    }
    else if ( index == 3 )
    {
        m_widget->setColour( value.toString() );
    }
    else if ( index == 4 )
    {
//        m_widget->setScalpHair( value.value<ImaginativeThinking::Hair>() );
    }
    else if ( index == 5 )
    {
//        m_widget->setScalpHair( value.value<ImaginativeThinking::Hair>() );
    }
}

bool HappyPropertySheetExtension::isChanged(int index) const
{
    Q_UNUSED( index );
    return true;
}

void HappyPropertySheetExtension::setChanged(int index, bool changed)
{
    Q_UNUSED( index );
    Q_UNUSED( changed );
}
