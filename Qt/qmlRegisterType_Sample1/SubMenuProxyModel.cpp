#include "SubMenuProxyModel.h"
#include "SubMenuViewModel.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
SubMenuProxyModel::SubMenuProxyModel() :
    m_subMenu( SubMenuViewModel::SubMenuType_Home )
{
    auto model = SubMenuViewModel::getInstance();
    this->setSourceModel( model );
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
SubMenuProxyModel::~SubMenuProxyModel()
{

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool SubMenuProxyModel::filterAcceptsRow( int source_row, const QModelIndex& source_parent ) const
{
    // Here we can specify whatever filter logic we need to and can check multiple Roles. Below
    // we are simply checking the Value role to see if that value stored there is even, if so include the
    // data entry in this proxy model.

    bool ret( false );
    if ( this->sourceModel() != nullptr )
    {
        auto index = this->sourceModel()->index( source_row, 0, source_parent );
        if ( index.isValid() )
        {
            auto valueRole = index.data( SubMenuViewModel::SubMenuViewModel_Roles::SubMenuViewModel_Roles_ParentMenu );
            if ( valueRole.isValid() )
            {
                bool ok( false );
                auto value = valueRole.toInt( &ok );
                if ( ok )
                {
                    if ( SubMenuViewModel::SubMenuViewModel_SubMenuType( value ) == m_subMenu )
                    {
                        ret = true;
                    }
                }
            }
        }
    }
    return ret;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void SubMenuProxyModel::setFilter( SubMenuViewModel::SubMenuViewModel_SubMenuType filter )
{
    m_subMenu = filter;
    this->invalidateFilter(); // This tells the filter to reset becaues we've justed changed how we want to filter the data.
}
