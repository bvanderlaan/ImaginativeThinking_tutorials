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
#ifndef HAIR_HPP
#define HAIR_HPP

#include <QObject>
#include <QColor>

namespace ImaginativeThinking
{
    class Hair //: public QObject
    {
//        Q_OBJECT
//        Q_ENUMS( Hair_Length )
//        Q_PROPERTY(Hair_Length length READ getLength WRITE setLength NOTIFY hairLengthChanged )
//        Q_PROPERTY(QColor colour READ getColour WRITE setColour NOTIFY hairColourChanged )
    public:
        explicit Hair(/*QObject *parent = 0*/);
        virtual ~Hair() {}
    
        enum Hair_Length
        {
            Hair_Length_Long,
            Hair_Length_Medium,
            Hair_Length_Short,
            Hair_Length_None
        };

        Hair_Length getLength() const;
        void setLength( Hair_Length length );

        QColor getColour() const;
        void setColour( const QColor& colour );


        bool operator==( const Hair& other );
        
        
//    signals:
//        void hairLengthChanged( Hair_Length length );
//        void hairColourChanged( QColor colour );
    
    private:
        Hair_Length m_length;
        QColor m_colour;
    };

    inline bool operator==( const Hair& left, const Hair& right )
    {
        return ( ( left.getColour() == right.getColour() ) &&
                 ( left.getLength() == right.getLength() ) );
    }

    inline bool operator!=( const Hair& left, const Hair& right )
    {
        return !( left == right );
    }
}
Q_DECLARE_METATYPE(ImaginativeThinking::Hair)

#endif // HAIR_HPP
