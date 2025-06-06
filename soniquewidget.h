/***************************************************************************
 * This file is part of the TTK qmmp plugin project
 * Copyright (C) 2015 - 2025 Greedysky Studio

 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License along
 * with this program; If not, see <http://www.gnu.org/licenses/>.
 ***************************************************************************/

#ifndef SONIQUEWIDGET_H
#define SONIQUEWIDGET_H

#include "visual.h"
#include "kiss_fft.h"
#include <QLibrary>
#include <qmmp/visual.h>

/*!
 * @author Greedysky <greedysky@163.com>
 */
class SoniqueWidget : public Visual
{
    Q_OBJECT
public:
    explicit SoniqueWidget(QWidget *parent = nullptr);
    virtual ~SoniqueWidget();

public slots:
    virtual void start() override final;
    virtual void stop() override final;

private slots:
    void nextPreset();
    void previousPreset();
    void randomPreset();
    void updateVisual();
    void setFullScreen(bool yes);

protected:
    virtual void hideEvent(QHideEvent *e) override final;
    virtual void showEvent(QShowEvent *e) override final;
    virtual void resizeEvent(QResizeEvent *e) override final;
    virtual void paintEvent(QPaintEvent *e) override final;
    virtual void contextMenuEvent(QContextMenuEvent *) override final;

    void process(float *left, float *right);
    void initialize();
    void closePreset();
    void generatePreset();

    VisInfo *m_sonique = nullptr;
    VisData *m_visData = nullptr;
    unsigned int *m_texture = nullptr;
    unsigned int *m_visProc = nullptr;
    QLibrary *m_instance = nullptr;
    int m_currentIndex = -1;
    QStringList m_presetList;

    kiss_fft_cfg m_kissCfg;
    kiss_fft_cpx *m_inputFreqData = nullptr;
    kiss_fft_cpx *m_outFreqData = nullptr;

    QTimer *m_timer = nullptr;
    float m_left[QMMP_VISUAL_NODE_SIZE];
    float m_right[QMMP_VISUAL_NODE_SIZE];
    QAction *m_screenAction = nullptr;

};

#endif
