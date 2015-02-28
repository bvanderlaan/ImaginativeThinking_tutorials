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

#ifndef MYVIEWMODEL_H
#define MYVIEWMODEL_H

#include <QStandardItemModel>
#include <QObject>

class MyViewModel : public QStandardItemModel
{
    Q_OBJECT
    Q_PROPERTY( int count READ getRowCount() NOTIFY rowCountChanged() )

public:
    /**
     * @brief Defines a list of application-specific roles particually related to this view model's data model.
     *
     * Each item in the view model has a set of data elements associated with it, each with its own role.
     * Roles are used by the view to indicate to the view model which type of data it needs.  The roles
     * defined in this enum are specific to this view models data model.
     * @see <a href="http://qt-project.org/doc/qt-5.0/qtcore/qt.html#ItemDataRole-enum" style="font-weight:bold;">Qt::ItemDataRole</a>
     */
    enum MyViewModel_Roles
    {
        MyViewModel_Roles_Display = Qt::UserRole + 1,   /**< This role holds the display string for an entry in the model. */
        MyViewModel_Roles_Details,                      /**< This role holds the details string for an entry in the model. **/
        MyViewModel_Roles_KeyId,                        /**< This role holds the key id for an entry in the model. **/
        MyViewModel_Roles_Value,                        /**< This role holds the value for an entry in the model. **/
    };

    /**
     * @brief MyViewModel is the Constructor that will create an instance of this class
     */
    MyViewModel();

    /**
     * @brief ~MyViewModel is the destructor that will clean up this object when its not needed anymore.
     */
    virtual ~MyViewModel();

    /**
     * @brief Initializes the ViewModel and populates it with data
     */
    void initialize();

    /**
     * @return A collection of the view models role names.
     * @see MenuRoles
     * @see <a href="http://qt-project.org/doc/qt-5.0/qtcore/qabstractitemmodel.html#roleNames" style="font-weight:bold;">QAbstractItemModel</a>
     */
    virtual QHash<int,QByteArray> roleNames() const;

    /**
     * @param rowNumber is the index within the model for the item we want to check.
     * @return Returns true if the entry's value role holds an even number.
     */
    Q_INVOKABLE bool isEven( int rowNumber );

    /**
     * @param rowNumber specifies which row within the model the item we want to check is located.
     * @return Returns a map that holds all the attributes about the item using the role names as the key.
     * @note The return value is a key/value pair where the keys are available in QML so we can
     * use the returned object to get any of the role information about the data (e.g. returnObject.role_display)
     */
    Q_INVOKABLE QVariantMap get( int rowNumber ) const;

signals:

    /**
     * @brief rowCountChanged is emitted whenever the row count changes
     */
    void rowCountChanged();

private slots:
    /**
     * @return Returns the number of rows in the model
     */
    int getRowCount();

};

#endif // MYVIEWMODEL_H
