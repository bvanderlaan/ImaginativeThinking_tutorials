#include <QApplication>
#include <QQmlContext>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "SubMenuViewModel.h"
#include "SubMenuProxyModel.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Register the enum SubMenuViewModel_SubMenuType so that it can be used in the QML script

    // Here we are registring the SubMenuViewModel C++ class with the QML script so that we can
    // access the Enums it exposes via the Q_ENUM macro. Notice here that we define its QML Name as
    // SubMenuTypes to hint that we inted to use it for its enums only.
    qmlRegisterType<SubMenuViewModel>("ca.imaginativethinking.tutorial.proxymodels", 1, 0, "SubMenuTypes");

    // Here we register the enum that we want to use in our QML as a meta type via the qRegisterMetaType<type>()
    // template function. We do this so that we can pass it as a parameter via a function (or signal/slot) call.
    // We do this so that instead of passing it in as an int we can pass it in as an enum. This allows us to
    // make our method signature easy to understand that we are expecting a limit set of integer values (only
    // those defined in the SubMenuViewModel_SubMenuTypes enum). Where qmlRegisterType() registers a type
    // with the QML Engine, qRegisterMetaType() registers a type with the Qt Meta Engine.
    qRegisterMetaType<SubMenuViewModel::SubMenuViewModel_SubMenuType>( "SubMenuViewModel::SubMenuViewModel_SubMenuType" );

    // Register the SubMenuProxyModel so that it can be instantiated in QML scripts.
    qmlRegisterType<SubMenuProxyModel>("ca.imaginativethinking.tutorial.proxymodels", 1, 0, "SubMenuProxyModel");


    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));

    return app.exec();
}
