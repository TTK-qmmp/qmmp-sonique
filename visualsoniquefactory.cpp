#include "visualsoniquefactory.h"
#include "soniquewidget.h"

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
    return new SoniqueWidget(parent);
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
                       tr("This plugin adds Sonique visualization") + "\n" +
                       tr("Written by: Greedysky <greedysky@163.com>"));
}

QString VisualSoniqueFactory::translation() const
{
    return QString();
}
