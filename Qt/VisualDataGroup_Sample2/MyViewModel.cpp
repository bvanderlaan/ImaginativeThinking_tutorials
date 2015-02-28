#include "MyViewModel.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
MyViewModel::MyViewModel()
{
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
MyViewModel::~MyViewModel()
{
    this->clear();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
QHash<int,QByteArray> MyViewModel::roleNames() const
{
    // Maps the role names used in the QML to the role name enum used in the code behind.

    QHash<int, QByteArray> roles;
    roles[MyViewModel_Roles_Display] = "role_display";
    roles[MyViewModel_Roles_Details] = "role_details";
    roles[MyViewModel_Roles_KeyId] = "role_keyid";
    roles[MyViewModel_Roles_Value] = "role_value";

    return roles;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MyViewModel::initialize()
{
    auto root = this->invisibleRootItem();

    QStandardItem* entry = new QStandardItem();
    entry->setData("One", MyViewModel_Roles_Display );
    entry->setData(0, MyViewModel_Roles_Value );
    root->appendRow(entry);

    entry = new QStandardItem();
    entry->setData("One", MyViewModel_Roles_Display );
    entry->setData(2, MyViewModel_Roles_Value );
    root->appendRow(entry);

    entry = new QStandardItem();
    entry->setData("One", MyViewModel_Roles_Display );
    entry->setData(3, MyViewModel_Roles_Value );
    root->appendRow(entry);

    entry = new QStandardItem();
    entry->setData("One", MyViewModel_Roles_Display );
    entry->setData(4, MyViewModel_Roles_Value );
    root->appendRow(entry);

    entry = new QStandardItem();
    entry->setData("Two", MyViewModel_Roles_Details );
    entry->setData(5, MyViewModel_Roles_Value );
    root->appendRow(entry);

    entry = new QStandardItem();
    entry->setData("Three", MyViewModel_Roles_Details );
    entry->setData(6, MyViewModel_Roles_Value );
    root->appendRow(entry);

    entry = new QStandardItem();
    entry->setData("Four", MyViewModel_Roles_Details );
    entry->setData(7, MyViewModel_Roles_Value );
    root->appendRow(entry);

    entry = new QStandardItem();
    entry->setData("Five", MyViewModel_Roles_Details );
    entry->setData(8, MyViewModel_Roles_Value );
    root->appendRow(entry);

    entry = new QStandardItem();
    entry->setData("Six", MyViewModel_Roles_Details );
    entry->setData(9, MyViewModel_Roles_Value );
    root->appendRow(entry);

    entry = new QStandardItem();
    entry->setData("Seven", MyViewModel_Roles_KeyId );
    entry->setData(10, MyViewModel_Roles_Value );
    root->appendRow(entry);

    entry = new QStandardItem();
    entry->setData("Eight", MyViewModel_Roles_KeyId );
    entry->setData(11, MyViewModel_Roles_Value );
    root->appendRow(entry);

    entry = new QStandardItem();
    entry->setData("hello", MyViewModel_Roles_KeyId );
    entry->setData(12, MyViewModel_Roles_Value );
    root->appendRow(entry);

    emit rowCountChanged();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int MyViewModel::getRowCount()
{
    return this->rowCount();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool MyViewModel::isEven(int rowNumber)
{
    bool ret( false );
    if ( this->invisibleRootItem() != nullptr )
    {
        if ( this->invisibleRootItem()->rowCount() > rowNumber )
        {
            auto entry = this->invisibleRootItem()->child( rowNumber );
            bool ok( false );
            auto value = entry->data( MyViewModel_Roles::MyViewModel_Roles_Value ).toInt( &ok );
            if ( ok )
            {
                if ( ( value % 2) == 0 )
                {
                    ret = true;
                }
            }
        }
    }
    return ret;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
QVariantMap MyViewModel::get( int rowNumber ) const
{
    // Create a map to hold all the role information about the data item in question
    // Use the role names as the keys for the map so that the same referances can be
    // used in the QML to get the data (i.e. role_display, role_value).
    QVariantMap map;
    QHash<int,QByteArray> roleName = roleNames();
    foreach (int i, roleName.keys())
    {
        map[roleName.value(i)] = data( index( rowNumber,0 ), i );
    }
    return map;
}
