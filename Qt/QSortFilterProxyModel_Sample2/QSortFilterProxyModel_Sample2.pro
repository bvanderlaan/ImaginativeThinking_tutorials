TEMPLATE = app

QT += qml quick widgets

HEADERS += \
        MyViewModel.h \
        MyProxyModel.h

SOURCES += \
        main.cpp \
        MyViewModel.cpp \
        MyProxyModel.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)
