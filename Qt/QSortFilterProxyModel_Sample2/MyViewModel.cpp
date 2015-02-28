#include "MyViewModel.h"
#include <QDebug>

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
            auto value = entry->data( MyViewModel_Roles::MyViewModel_Roles_Value ).toInt();
            if ( ( value % 2) == 0 )
            {
                ret = true;
            }
        }
    }
    return ret;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MyViewModel::doWork()
{
    auto child = this->invisibleRootItem()->child(1);
    child->setData(88, MyViewModel_Roles::MyViewModel_Roles_Value);
    child = this->invisibleRootItem()->child(3);
    child->setData(99, MyViewModel_Roles::MyViewModel_Roles_Value);

    //QVector<int> roles;
    //roles.append( MyViewModel_Roles::MyViewModel_Roles_Value );
    //emit dataChanged( child->index(), child->index(), roles );
}
