/*
 * Copyright 2014 ImaginativeThinking
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
#ifndef MYPROXYMODEL_EVENENTRIES_H
#define MYPROXYMODEL_EVENENTRIES_H

#include <QSortFilterProxyModel>

class MyViewModel; // Forward declaration so we don't have to include the MyViewModel.h header file (we'll do that in the CPP file).
class MyProxyModel_EvenEntries : public QSortFilterProxyModel
{
    Q_OBJECT

public:
    /**
     * @brief MyProxyModel_EvenEntries is the Constructor that will create an instance of this class
     */
    MyProxyModel_EvenEntries( MyViewModel* model );

    /**
     * @brief ~MyProxyModel_EvenEntries is the destructor that will clean up this object when its not needed anymore.
     */
    virtual ~MyProxyModel_EvenEntries();

    /**
     * @brief filterAcceptsRow is a predict that is run against each data entry when the souce model is added or changed.
     * If this method returns true then the data entry has satisfied the filter logic and is to be included in the proxys data set.
     * If this method returns false then the data entry is ignored (looks like it does not exist).
     * @note The base implementations of index(), parent(), rowCount(), columnCount(), data(), and setData() are all aware of the results
     * of this predict, that is they to will ignore any data entries from the source model that don't pass the filter logic.
     * @param source_row is the row number within the source model of a data entry to check.
     * @param source_parent is the parent of the data entry (used if the source model is a tree).
     * @return Returns true if the data entry passed the filter logic, false otherwise
     */
    bool filterAcceptsRow( int source_row, const QModelIndex& source_parent ) const override;

};

#endif // MYPROXYMODEL_EVENENTRIES_H
