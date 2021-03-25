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

QDialog *VisualSoniqueFactory::createConfigDialog(QWidget *parent)
{
    Q_UNUSED(parent);
    return nullptr;
}

void VisualSoniqueFactory::showAbout(QWidget *parent)
{
    QMessageBox::about (parent, tr("About Sonique Visual Plugin"),
                        tr("Qmmp Sonique Visual Plugin")+"\n"+
                        tr("This plugin adds Sonique visualization")+"\n"+
                        tr("Written by: Greedysky <greedysky@163.com>"));
}

QString VisualSoniqueFactory::translation() const
{
    return QString();
}
