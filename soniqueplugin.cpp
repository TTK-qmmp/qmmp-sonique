#include "soniqueplugin.h"
#include "soniquewidget.h"

#include <QMenu>
#include <QTimer>
#include <QSplitter>
#include <QScrollBar>
#include <QBoxLayout>

#if QT_VERSION >= QT_VERSION_CHECK(6,3,0)
#  define QtAddAction(p, a, b, c, d) p->addAction(a, d, b, c)
#else
#  define QtAddAction(p, a, b, c, d) p->addAction(a, b, c, d)
#endif

SoniquePlugin::SoniquePlugin(QWidget *parent)
    : Visual(parent)
{
    setWindowTitle(tr("Sonique Widget"));

    m_splitter = new QSplitter(Qt::Horizontal, this);
    m_itemWidget = new QListWidget(m_splitter);
    m_itemWidget->setVisible(false);
    m_itemWidget->setAlternatingRowColors(true);
    m_itemWidget->verticalScrollBar()->setStyleSheet(" \
            QScrollBar{ background:transparent; width:8px; padding-top:0px; padding-bottom:0px; } \
            QScrollBar::handle:vertical{ border-radius:4px; background:#CFCFCF; min-height: 30px; } \
            QScrollBar::handle:vertical::disabled{ background:#DBDBDB; } \
            QScrollBar::handle:vertical:hover{ background:#BBBBBB; } \
            QScrollBar::add-line, QScrollBar::sub-line{ background:none; border:none; } \
            QScrollBar::add-page, QScrollBar::sub-page{ background:none; }");
    m_itemWidget->horizontalScrollBar()->setStyleSheet(" \
            QScrollBar{ background:transparent; height:8px; padding-left:0px; padding-right:0px; } \
            QScrollBar::handle:horizontal{ border-radius:4px; background:#CFCFCF; min-width: 30px; } \
            QScrollBar::handle:horizontal::disabled{ background:#DBDBDB; } \
            QScrollBar::handle:horizontal:hover{ background:#BBBBBB; } \
            QScrollBar::add-line, QScrollBar::sub-line{ background:none; border:none; } \
            QScrollBar::add-page, QScrollBar::sub-page{ background:none; }");
    m_container = new SoniqueWidget(m_itemWidget, m_splitter);

    m_splitter->addWidget(m_itemWidget);
    m_splitter->addWidget(m_container);
    m_splitter->setStretchFactor(1, 1);

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(m_splitter);
    layout->setContentsMargins(0, 0, 0, 0);
    setLayout(layout);

    m_menu = new QMenu(this);
    m_menu->addAction(m_screenAction);
    m_menu->addSeparator();
    QtAddAction(m_menu, tr("&Show Menu"), m_itemWidget, SLOT(setVisible(bool)), {"M"})->setCheckable(true);
    m_menu->addSeparator();
    QtAddAction(m_menu, tr("&Next Preset"), m_container, SLOT(nextPreset()), {"N"});
    QtAddAction(m_menu, tr("&Previous Preset"), m_container, SLOT(previousPreset()), {"P"});
    QtAddAction( m_menu, tr("&Random Preset"), m_container, SLOT(randomPreset()), {"R"});

    m_timer = new QTimer(this);
    m_timer->setInterval(40);
    connect(m_timer, SIGNAL(timeout()), SLOT(updateVisual()));

    m_screenAction = new QAction(tr("Fullscreen"), this);
    m_screenAction->setCheckable(true);
    connect(m_screenAction, SIGNAL(triggered(bool)), this, SLOT(setFullScreen(bool)));
}

void SoniquePlugin::start()
{
    if(isVisible())
    {
        m_timer->start();
    }
}

void SoniquePlugin::stop()
{
    m_timer->stop();
}

void SoniquePlugin::updateVisual()
{
    if(takeData(m_left, m_right))
    {
        m_container->addBuffer(m_left, m_right);
        m_container->update();
    }
}

void SoniquePlugin::setFullScreen(bool yes)
{
    if(yes)
    {
        setWindowState(windowState() | Qt::WindowFullScreen);
    }
    else
    {
        setWindowState(windowState() & ~Qt::WindowFullScreen);
    }
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
    m_menu->exec(QCursor::pos());
}
