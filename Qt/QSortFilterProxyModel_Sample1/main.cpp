#include <QApplication>
#include <QQmlContext>
#include <QQmlApplicationEngine>
#include "MyProxyModel_EvenEntries.h"
#include "MyViewModel.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Create an instance of our ViewModel; this holds the total list of data
    auto vm = new MyViewModel();
    vm->initialize();

    // Create an instance of a QSortFilterProxyModel and tell it to filter out any
    // data entries whose MyViewModel_Roles_Detils role value is blank (which it will be if absent)
    auto detailsProxyModel = new QSortFilterProxyModel();
    detailsProxyModel->setFilterRole( MyViewModel::MyViewModel_Roles::MyViewModel_Roles_Details);
    detailsProxyModel->setFilterRegExp( "^\\S+$" );
    detailsProxyModel->setSourceModel( vm );

    // Create an instance of a QSortFilterProxyModel and tell it to filter out any
    // data entries whose MyViewModel_Roles_Display role value is blank (which it will be if absent)
    auto displayProxyModel = new QSortFilterProxyModel();
    displayProxyModel->setFilterRole( MyViewModel::MyViewModel_Roles::MyViewModel_Roles_Display);
    displayProxyModel->setFilterRegExp( "^\\S+$" );
    displayProxyModel->setSourceModel( vm );

    // Create an instance of our custom QSortFilterProxyModel which filters out any entries whose
    // data entries have an odd numbered value.
    auto evenEntriesModel = new QSortFilterProxyModel();
    evenEntriesModel->setFilterRole( MyViewModel::MyViewModel_Roles::MyViewModel_Roles_Value );
    evenEntriesModel->setFilterRegExp( "^\\d*[02468]$" );
    evenEntriesModel->setSourceModel( vm );

    // Does the same as above but is a custom version of the QSortFilterProxy to ilistrate how one can
    // crate a proxy model with custom filter logic.
    auto myEvenEntriesModel = new MyProxyModel_EvenEntries( vm );

    // Notice that all three above proxy modesl use the same source model; we've not copied any data
    // just filtered it out (when the view asks one of the proxy models for the item at row 2 it will map
    // that row number to the correct row in the view model (could be row 6 depending on the filter applied)
    // and relays the data (the proxy models don't store a copy of the data its all referance based).

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("MyModel", vm );
    engine.rootContext()->setContextProperty("DetailsRoleModel", detailsProxyModel );
    engine.rootContext()->setContextProperty("DisplayRoleModel", displayProxyModel );
    engine.rootContext()->setContextProperty("EvenEntriesModel", evenEntriesModel );
    engine.rootContext()->setContextProperty("MyEvenEntriesModel", myEvenEntriesModel );
    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));

    return app.exec();
}
