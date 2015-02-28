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

#ifndef SUBMENUVIEWMODEL_H
#define SUBMENUVIEWMODEL_H

#include <QStandardItemModel>

class SubMenuViewModel : public QStandardItemModel
{
    Q_OBJECT
    Q_ENUMS( SubMenuViewModel_SubMenuType )

protected:
    SubMenuViewModel();

public:
    virtual ~SubMenuViewModel();

    /**
     * @return Returns the signalton instance.
     */
    static SubMenuViewModel* getInstance();

    /**
     * @brief Defines a list of application-specific roles particually related to this view model's data model.
     *
     * Each item in the view model has a set of data elements associated with it, each with its own role.
     * Roles are used by the view to indicate to the view model which type of data it needs.  The roles
     * defined in this enum are specific to this view models data model.
     * @see <a href="http://qt-project.org/doc/qt-5.0/qtcore/qt.html#ItemDataRole-enum" style="font-weight:bold;">Qt::ItemDataRole</a>
     */
    enum SubMenuViewModel_Roles
    {
        SubMenuViewModel_Roles_ParentMenu = Qt::UserRole + 1   /**< This role holds which main menu item this sub menu item falls under. */
    };

    /**
     * @brief The SubMenuViewModel_SubMenuType enum lists the different main menu items that sub menu items can belong to.
     */
    enum SubMenuViewModel_SubMenuType
    {
        SubMenuType_Home,   /**< This sub menu is for the "Home" main menu. */
        SubMenuType_Edit    /**< This sub menu is for the "Edit" main menu. */
    };

    /**
     * @brief Initializes the ViewModel and populates it with data
     */
    void initialize();

    /**
     * @return A collection of the view models role names.
     * @see <a href="http://qt-project.org/doc/qt-5.0/qtcore/qabstractitemmodel.html#roleNames" style="font-weight:bold;">QAbstractItemModel</a>
     */
    virtual QHash<int,QByteArray> roleNames() const override;

private:

    static SubMenuViewModel* m_instance;
};

#endif // SUBMENUVIEWMODEL_H
