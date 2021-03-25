#include <QMenu>
#include <QTimer>
#include <QBoxLayout>

#include "soniquewidget.h"
#include "soniqueplugin.h"

SoniquePlugin::SoniquePlugin(QWidget *parent)
    : Visual(parent)
{
    setWindowTitle(tr("Sonique Widget"));

    m_soniqueWidget = new SoniqueWidget(this);

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(m_soniqueWidget);
    layout->setContentsMargins(0, 0, 0, 0);
    setLayout(layout);

    m_timer = new QTimer(this);
    m_timer->setInterval(40);
    connect(m_timer, SIGNAL(timeout()), SLOT(updateVisual()));

    m_screenAction = new QAction(tr("Fullscreen"), this);
    m_screenAction->setCheckable(true);
    connect(m_screenAction, SIGNAL(triggered(bool)), this, SLOT(setFullScreen(bool)));
}

SoniquePlugin::~SoniquePlugin()
{

}
void SoniquePlugin::start()
{
    if(isVisible())
        m_timer->start();
}

void SoniquePlugin::stop()
{
    m_timer->stop();
}

void SoniquePlugin::updateVisual()
{
    if(takeData(m_left, m_right))
    {
        process(m_left, m_right);
        update();
    }
}

void SoniquePlugin::setFullScreen(bool yes)
{
    if(yes)
        setWindowState(windowState() | Qt::WindowFullScreen);
    else
        setWindowState(windowState() & ~Qt::WindowFullScreen);
}

void SoniquePlugin::hideEvent(QHideEvent *)
{
    m_timer->stop();
}

void SoniquePlugin::showEvent(QShowEvent *)
{
    m_timer->start();
}

void SoniquePlugin::contextMenuEvent(QContextMenuEvent *)
{
    QMenu menu(this);
    menu.addAction(m_screenAction);
    menu.addSeparator();
    menu.addAction(tr("&Next Preset"), m_soniqueWidget, SLOT(nextPreset()), tr("N"));
    menu.addAction(tr("&Previous Preset"), m_soniqueWidget, SLOT(previousPreset()), tr("P"));
    menu.addAction(tr("&Random Preset"), m_soniqueWidget, SLOT(randomPreset()), tr("R"));
    menu.exec(QCursor::pos());
}

void SoniquePlugin::process(float *left, float *right)
{
    m_soniqueWidget->addBuffer(left, right);
}
