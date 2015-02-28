#include "MyProxyModel_EvenEntries.h"
#include "MyViewModel.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
MyProxyModel_EvenEntries::MyProxyModel_EvenEntries( MyViewModel* model )
{
    this->setSourceModel( model );
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
MyProxyModel_EvenEntries::~MyProxyModel_EvenEntries()
{
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool MyProxyModel_EvenEntries::filterAcceptsRow( int source_row, const QModelIndex& source_parent ) const
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
            auto valueRole = index.data( MyViewModel::MyViewModel_Roles::MyViewModel_Roles_Value );
            if ( valueRole.isValid() )
            {
                bool ok( false );
                auto value = valueRole.toInt( &ok );
                if ( ok )
                {
                    if ( ( value % 2 ) == 0 )
                    {
                        ret = true;
                    }
                }
            }
        }
    }
    return ret;
}
