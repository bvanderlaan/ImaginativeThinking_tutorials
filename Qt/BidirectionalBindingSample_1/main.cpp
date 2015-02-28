#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "MyModel.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MyModel* model = new MyModel();

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("MyModel", model );
    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));


    return app.exec();
}
