#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "ObjectOne.h"
#include "ObjectTwo.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    qmlRegisterType<ObjectOne>("ca.imaginativethinking.tutorial.objectone", 1, 0, "MyObject");
    qmlRegisterType<ObjectTwo>("ca.imaginativethinking.tutorial.objecttwo", 1, 0, "MyObject");


    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));

    return app.exec();
}
