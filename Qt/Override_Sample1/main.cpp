#include <QApplication>
#include <QQmlApplicationEngine>
#include "MyChildClass.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    MyChildClass myClass; // This generates the error

    return app.exec();
}
