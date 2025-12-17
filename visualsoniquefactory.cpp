#include "visualsoniquefactory.h"
#include "soniqueplugin.h"

#include <QMessageBox>

VisualProperties VisualSoniqueFactory::properties() const
{
    VisualProperties properties;
    properties.name = tr("Sonique Plugin");
    properties.shortName = "sonique";
    properties.hasAbout = true;
    return properties;
}

Visual *VisualSoniqueFactory::create(QWidget *parent)
{
    return new SoniquePlugin(parent);
}

#if (QMMP_VERSION_INT < 0x10700) || (0x20000 <= QMMP_VERSION_INT && QMMP_VERSION_INT < 0x20200)
QDialog *VisualSoniqueFactory::createConfigDialog(QWidget *parent)
#else
QDialog *VisualSoniqueFactory::createSettings(QWidget *parent)
#endif
{
    Q_UNUSED(parent);
    return nullptr;
}

void VisualSoniqueFactory::showAbout(QWidget *parent)
{
    QMessageBox::about(parent, tr("About Sonique Visual Plugin"),
                       tr("Qmmp Sonique Visual Plugin") + "\n" +
                       tr("Written by: Greedysky <greedysky@163.com>") + "\n" +
                       tr("Based on the source code from the Soniqueviewer") + "\n" +
                       tr("Written by juanmv94 Juan (C) 2019"));
}

QString VisualSoniqueFactory::translation() const
{
    return QString();
}

#if QT_VERSION < QT_VERSION_CHECK(5,0,0)
#include <QtPlugin>
Q_EXPORT_PLUGIN2(sonique, VisualSoniqueFactory)
#endif
