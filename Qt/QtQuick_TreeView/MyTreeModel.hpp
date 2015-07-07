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

#ifndef MYTREEMODEL_HPP
#define MYTREEMODEL_HPP

#include <QStandardItemModel>

namespace ImaginativeThinking
{
    namespace Tutorials
    {
        class MyTreeModel : public QStandardItemModel
        {
            Q_OBJECT
        public:
            explicit MyTreeModel(QObject *parent = 0);
            virtual ~MyTreeModel() = default;

            enum MyTreeModel_Roles
            {
                MyTreeModel_Role_Name = Qt::DisplayRole,
                MyTreeModel_Role_Description = Qt::WhatsThisRole
            };

            QHash<int, QByteArray> roleNames() const override;

        private:
            void addEntry( const QString& name, const QString& type, const QString& description );
            QStandardItem* getBranch( const QString& branchName );
            QHash<int, QByteArray> m_roleNameMapping;

        };
    }
}

#endif // MYTREEMODEL_HPP
