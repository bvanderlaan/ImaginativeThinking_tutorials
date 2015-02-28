TEMPLATE = subdirs
SUBDIRS += QtQuickSampleApp \
    QtQuickSampleTest \
    QtQuickSampleLib

QtQuickSampleApp.depends = QtQuickSampleLib
QtQuickSampleTest.depends = QtQuickSampleLib
