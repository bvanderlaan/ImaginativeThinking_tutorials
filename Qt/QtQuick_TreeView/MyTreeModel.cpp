/*
 * Copyright 2015 ImaginativeThinking
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

#include "MyTreeModel.hpp"

using namespace ImaginativeThinking::Tutorials;

MyTreeModel::MyTreeModel(QObject *parent) :
    QStandardItemModel(parent)
{

    m_roleNameMapping[MyTreeModel_Role_Name] = "name_role";
    m_roleNameMapping[MyTreeModel_Role_Description] = "description_role";

    addEntry( "Option A", "Recommended", "This is Option A" );
    addEntry( "Option B", "Recommended", "This is Option B" );
    addEntry( "Option C", "Recommended", "This is Option C" );
    addEntry( "Option D", "Recommended", "This is Option D" );

    addEntry( "Option E", "Optional", "This is Option E" );
    addEntry( "Option F", "Optional", "This is Option F" );
    addEntry( "Option G", "Optional", "This is Option G" );
    addEntry( "Option H", "Optional", "This is Option H" );
}

void MyTreeModel::addEntry( const QString& name, const QString& type, const QString& description )
{  
    auto childEntry = new QStandardItem( name );
    childEntry->setData( description, MyTreeModel_Role_Description );

    QStandardItem* entry = getBranch( type );
    entry->appendRow( childEntry );
}

QStandardItem *MyTreeModel::getBranch(const QString &branchName)
{
    QStandardItem* entry;
    auto entries = this->findItems( branchName );
    if ( entries.count() > 0 )
    {
        entry = entries.at(0);
    }
    else
    {
        entry = new QStandardItem( branchName );
        this->appendRow( entry );
    }
    return entry;
}

QHash<int, QByteArray> MyTreeModel::roleNames() const
{
    return m_roleNameMapping;
}
