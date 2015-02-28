#include "SubMenuViewModel.h"

SubMenuViewModel* SubMenuViewModel::m_instance = nullptr;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
SubMenuViewModel::SubMenuViewModel()
{
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
SubMenuViewModel::~SubMenuViewModel()
{
    this->clear();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
QHash<int,QByteArray> SubMenuViewModel::roleNames() const
{
    // Maps the role names used in the QML to the role name enum used in the code behind.

    QHash<int, QByteArray> roles;
    roles[Qt::DisplayRole] = "role_display";
    roles[SubMenuViewModel_Roles_ParentMenu] = "role_parentmenu";

    return roles;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void SubMenuViewModel::initialize()
{
    auto root = this->invisibleRootItem();

    auto entry = new QStandardItem();
    entry->setData(SubMenuType_Home, SubMenuViewModel_Roles_ParentMenu );
    entry->setText( "Entry 1" ); // The DisplayRole
    root->appendRow(entry);

    entry = new QStandardItem();
    entry->setData(SubMenuType_Home, SubMenuViewModel_Roles_ParentMenu );
    entry->setText( "Entry 2" ); // The DisplayRole
    root->appendRow(entry);

    entry = new QStandardItem();
    entry->setData(SubMenuType_Edit, SubMenuViewModel_Roles_ParentMenu );
    entry->setText( "Entry 3" ); // The DisplayRole
    root->appendRow(entry);

    entry = new QStandardItem();
    entry->setData(SubMenuType_Edit, SubMenuViewModel_Roles_ParentMenu );
    entry->setText( "Entry 4" ); // The DisplayRole
    root->appendRow(entry);

    entry = new QStandardItem();
    entry->setData(SubMenuType_Edit, SubMenuViewModel_Roles_ParentMenu );
    entry->setText( "Entry 5" ); // The DisplayRole
    root->appendRow(entry);

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
SubMenuViewModel* SubMenuViewModel::getInstance()
{
    if ( m_instance == nullptr )
    {
        m_instance = new SubMenuViewModel();
        m_instance->initialize();
    }

    return m_instance;
}
