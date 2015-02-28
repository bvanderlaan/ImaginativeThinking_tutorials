#include "MyProxyModel.h"
#include "MyViewModel.h"

#include <QDebug>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
MyProxyModel::MyProxyModel( MyViewModel* model ):
    QSortFilterProxyModel(),
    m_currentFilter( MyProxyModel_Filters::Details )
{
    this->setSourceModel( model );
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
MyProxyModel::~MyProxyModel()
{
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool MyProxyModel::filterAcceptsRow( int source_row, const QModelIndex& source_parent ) const
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
            if ( m_currentFilter == MyProxyModel::MyProxyModel_Filters::Display )
            {
                // If the data item has a display role then its included.
                auto displayRole = index.data( MyViewModel::MyViewModel_Roles::MyViewModel_Roles_Display );
                ret = displayRole.isValid();
            }
            else if ( m_currentFilter == MyProxyModel::MyProxyModel_Filters::Details )
            {
                // If the data item has a details role then its included.
                auto detailsRole = index.data( MyViewModel::MyViewModel_Roles::MyViewModel_Roles_Details );
                ret = detailsRole.isValid();
            }
            else if ( m_currentFilter == MyProxyModel::MyProxyModel_Filters::EvenNumbers )
            {
                // If the data's value is even then its included.
                auto valueRole =index.data( MyViewModel::MyViewModel_Roles::MyViewModel_Roles_Value );
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
            else
            {
                // If not current filter is set then don't filter the data set.
                ret = true;
            }
        }
    }
    return ret;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MyProxyModel::setFilter( int filter )
{
    auto filterType = MyProxyModel::MyProxyModel_Filters( filter );
    m_currentFilter = filterType;
    emit filterChanged();
    this->invalidateFilter(); // This tells the filter to reset becaues we've justed changed how we want to filter the data.
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int MyProxyModel::getFilter()
{
    return (int)m_currentFilter;
}
