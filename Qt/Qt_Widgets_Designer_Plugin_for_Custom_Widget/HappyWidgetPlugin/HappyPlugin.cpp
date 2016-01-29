#include "HappyPlugin.hpp"
#include "HappyWidget.hpp"
#include "HappyExtensionFactory.hpp"

using namespace ImaginativeThinking::Widgets::Plugins;

HappyPlugin::HappyPlugin(QObject *parent) :
    QObject(parent),
    m_isInitialized(false)
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

void HappyPlugin::initialize(QDesignerFormEditorInterface *core)
{
    if ( !m_isInitialized )
    {
        QExtensionManager* manager = core->extensionManager();
        Q_ASSERT( manager != 0 );

        manager->registerExtensions( new HappyExtensionFactory(manager), Q_TYPEID(QDesignerPropertySheetExtension) );
        m_isInitialized = true;
    }
}

bool HappyPlugin::isInitialized() const
{
    return m_isInitialized;
}

//QString HappyPlugin::domXml() const
//{
//    return QLatin1String("\
//    <ui language=\"c++\">\
//        <widget class=\"ImaginativeThinking::Widgets::HappyWidget\" name=\"happyWidget\"/>\
//        <customwidgets>\
//            <customwidget>\
//                <class>HappyWidget</class>\
//                <propertyspecifications>\
//                <stringpropertyspecification name=\"state\" notr=\"true\" type=\"singleline\"/>\
//                </propertyspecifications>\
//            </customwidget>\
//        </customwidgets>\
//    </ui>");
//}

#if QT_VERSION < QT_VERSION_CHECK(5,0,0)
Q_EXPORT_PLUGIN2(HappyWidgetPlugin, HappyPlugin)
#endif
