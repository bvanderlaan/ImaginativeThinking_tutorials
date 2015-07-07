TEMPLATE = app

QT += qml quick widgets
CONFIG += C++14

SOURCES += main.cpp \
    MyTreeModel.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    MyTreeModel.hpp
