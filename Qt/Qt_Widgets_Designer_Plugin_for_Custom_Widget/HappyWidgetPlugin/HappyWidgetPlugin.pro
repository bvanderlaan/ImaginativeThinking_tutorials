greaterThan(QT_MAJOR_VERSION, 4) {
    QT += widgets designer
}

lessThan(QT_MAJOR_VERSION, 5) {
    CONFIG += designer
}

CONFIG += plugin release

TEMPLATE = lib

TARGET = $$qtLibraryTarget($$TARGET)
target.path = C:/Qt/Tools/QtCreator/bin/plugins/designer # $$[QT_INSTALL_PLUGINS]/designer
INSTALLS += target

INCLUDEPATH += .

SOURCES += \
    HappyPlugin.cpp \
    HappyWidget.cpp \
    Hair.cpp \
    HappyPropertySheetExtension.cpp \
    HappyExtensionFactory.cpp

HEADERS += \
    HappyPlugin.hpp \
    HappyWidget.hpp \
    Hair.hpp \
    HappyPropertySheetExtension.hpp \
    HappyExtensionFactory.hpp
