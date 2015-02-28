#include <QApplication>
#include <QQmlContext>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "MyViewModel.h"
#include "MyProxyModel.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Create an instance of our ViewModel; this holds the total list of data
    auto vm = new MyViewModel();
    vm->initialize();

    // Create an instance of our ProxyModel
    auto myProxyModel = new MyProxyModel( vm );

    // The MyProxyModel is exposing Enums as as such requires the MyProxyModel type
    // to be registered with QML so the QML engine knows how to look up the values
    // of the exposed enums. To do this we call the below non-member function from QtQml.h
    qmlRegisterType<MyProxyModel>("ca.imaginativethinking.tutorial.proxymodels", 1, 0, "FilterTypes");


    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("MyModel", vm );
    engine.rootContext()->setContextProperty("MyProxyModel", myProxyModel );
    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));

    return app.exec();
}
