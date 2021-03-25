/* =================================================
 * This file is part of the TTK qmmp plugin project
 * Copyright (C) 2015 - 2021 Greedysky Studio

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
 ================================================= */

#ifndef VISUALSONIQUEFACTORY_H
#define VISUALSONIQUEFACTORY_H

#include <QObject>
#include <qmmp/visualfactory.h>
#include <qmmp/visual.h>

/*!
 * @author Greedysky <greedysky@163.com>
 */
class VisualSoniqueFactory : public QObject, public VisualFactory
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qmmp.qmmp.VisualFactoryInterface.1.0")
    Q_INTERFACES(VisualFactory)
public:
    virtual VisualProperties properties() const override;
    virtual Visual *create(QWidget *parent) override;
    virtual QDialog *createConfigDialog(QWidget *parent) override;
    virtual void showAbout(QWidget *parent) override;
    virtual QString translation() const override;

};

#endif
