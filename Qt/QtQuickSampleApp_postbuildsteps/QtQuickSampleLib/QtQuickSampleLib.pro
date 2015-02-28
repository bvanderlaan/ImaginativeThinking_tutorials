QT       -= gui

TARGET = QtQuickSampleLib
TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
        MyCalculatorViewModel.cpp

HEADERS += \
        MyCalculatorViewModel.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
