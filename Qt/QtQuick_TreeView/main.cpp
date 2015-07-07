#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "MyTreeModel.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    qmlRegisterType<ImaginativeThinking::Tutorials::MyTreeModel>("ca.imaginativethinking.tutorials.models", 1, 0, "MyTreeModel" );


    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
