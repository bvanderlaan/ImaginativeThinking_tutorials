#include <QApplication>
#include <QQmlContext>
#include <QQmlApplicationEngine>
#include "MyViewModel.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MyViewModel* viewModel = new MyViewModel();
    viewModel->initialize();

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("MyModel", viewModel );
    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));

    return app.exec();
}
