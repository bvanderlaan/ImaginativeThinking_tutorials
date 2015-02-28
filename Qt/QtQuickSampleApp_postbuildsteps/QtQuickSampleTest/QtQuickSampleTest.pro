QT       += core testlib
QT       -= gui

TARGET = QtQuickSampleTest
CONFIG   += console
CONFIG   -= app_bundle
CONFIG   += testcase
TEMPLATE = app

SOURCES += main.cpp \
    QtQuickSampleApplicationTest.cpp \
    MyCalculatorViewModelTest.cpp

HEADERS += \
    QtQuickSampleApplicationTest.h \
    MyCalculatorViewModelTest.h

# Adds the QtQuickSampleLib project path to the header file include lookup path
INCLUDEPATH += $$PWD/../QtQuickSampleLib

# Adds the QtQuickSampleLib.lib to the linker
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../QtQuickSampleLib/release/ -lQtQuickSampleLib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../QtQuickSampleLib/debug/ -lQtQuickSampleLib
