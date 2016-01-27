#include "HappyPlugin.hpp"
#include "HappyWidget.hpp"

using namespace ImaginativeThinking::Widgets::Plugins;

HappyPlugin::HappyPlugin(QObject *parent) :
    QObject(parent)
{
}

QString HappyPlugin::name() const
{
    return QStringLiteral("HappyWidget");
}

QString HappyPlugin::group() const
{
    return QStringLiteral("ImaginativeThinking Custom Widgets");
}

QString HappyPlugin::toolTip() const
{
    return QStringLiteral("A very Happy Widget");
}

QString HappyPlugin::whatsThis() const
{
    return this->toolTip();
}

QString HappyPlugin::includeFile() const
{
    return QStringLiteral("HappyWidget.hpp");
}

QIcon HappyPlugin::icon() const
{
    return QIcon();
}

bool HappyPlugin::isContainer() const
{
    return false;
}

QWidget *HappyPlugin::createWidget(QWidget *parent)
{
    return new HappyWidget(parent);
}

#if QT_VERSION < QT_VERSION_CHECK(5,0,0)
Q_EXPORT_PLUGIN2(HappyWidgetPlugin, HappyPlugin)
#endif
