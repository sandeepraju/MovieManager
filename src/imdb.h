/***************************************************************************
 *   Copyright (C) 2012 by Sandeep Raju P <sandeep080@gmail.com>           *
 *   Copyright (C) 2012 by Sadan Sohan M <sadansohanm@gmail.com>           *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA .        *
 ***************************************************************************/

#ifndef IMDB_H
#define IMDB_H

#include <Qt>
#include <QDebug>
#include <QtNetwork>
#include <qjson/parser.h>

class IMDB: public QObject
{
    Q_OBJECT

public:
    IMDB(QString queryName);
    virtual ~IMDB();
    void getData();

private slots:
        void successResponse(QNetworkReply* reply);

private:
     QString* movieName;
     QString* responseJSON;
     QString* baseURL;
     QJson::Parser* parser;
     QVariantMap parsedResponse;

};

#endif // IMDB_H
