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

#ifndef SUBMENUPROXYMODEL_H
#define SUBMENUPROXYMODEL_H

#include <QSortFilterProxyModel>
#include "SubMenuViewModel.h"

class SubMenuProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT

public:
    SubMenuProxyModel();
    virtual ~SubMenuProxyModel();

protected:

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

public slots:

    /**
     * @brief setFilter sets the current filter.
     * @param filter is the filter setting the proxy model should use.
     */
    void setFilter( SubMenuViewModel::SubMenuViewModel_SubMenuType filter );

private:

    /**
     * @brief m_subMenu is the current filter to apply to the source data set.
     */
    SubMenuViewModel::SubMenuViewModel_SubMenuType m_subMenu;
};

#endif // SUBMENUPROXYMODEL_H
