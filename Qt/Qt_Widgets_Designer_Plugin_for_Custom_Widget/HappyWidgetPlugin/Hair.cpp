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
#include "Hair.hpp"

using namespace ImaginativeThinking;

Hair::Hair(/*QObject *parent*/) :
//    QObject(parent),
    m_length( Hair_Length_Medium ),
    m_colour( "brown" )
{

}

Hair::Hair_Length Hair::getLength() const
{
    return m_length;
}

void Hair::setLength(Hair::Hair_Length length)
{
    if ( m_length != length)
    {
        m_length = length;
//        emit hairLengthChanged( m_length );
    }
}

QColor Hair::getColour() const
{
    return m_colour;
}

void Hair::setColour(const QColor &colour)
{
    if ( m_colour != colour )
    {
        m_colour = colour;
//        emit hairColourChanged( m_colour );
    }
}
