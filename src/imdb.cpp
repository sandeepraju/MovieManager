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

#include "imdb.h"
#include <Qt>
#include <QDebug>
#include <QVariant>
#include "qdownloader.h"

IMDB::IMDB(QString queryName)
{

    this->movieName = new QString(queryName.toLatin1().data());
    this->baseURL = new QString("http://www.imdbapi.com/?t=");
}

void IMDB::getData()
{
    QNetworkAccessManager* pageLoader = new QNetworkAccessManager();

    connect(pageLoader, SIGNAL(finished(QNetworkReply*)),this, SLOT(successResponse(QNetworkReply*)));

    QString* finalURL = new QString(this->baseURL->toLatin1().data());
    finalURL->append(this->movieName);

    pageLoader->get(QNetworkRequest(QUrl(*(finalURL))));
}

void IMDB::successResponse(QNetworkReply *reply)
{
    QByteArray data = reply->readAll();
    this->responseJSON = new QString(data);
    qDebug("got successfully!");
    //qDebug(this->responseJSON->toLatin1().data());

    //QJson::Parser parser;
    parser = new QJson::Parser();
    bool ok;

    //parsedResponse = new QVariantMap();

    parsedResponse = parser->parse(this->responseJSON->toLatin1(), &ok).toMap();
    if (!ok) {
      qFatal("An error occured during parsing");
      exit (1);
    }

    if(parsedResponse["Response"].toString().compare("True") == 0)
    {

        //Title
        if(parsedResponse["Title"].toString().contains("N/A") != true)
        {
            //extract Title here and set it to nepomuk db
        }
        else
        {
            qDebug("Title Not found!");
        }

        //Year
        if(parsedResponse["Year"].toString().contains("N/A") != true)
        {
            //extract Year here and set it to nepomuk db
        }
        else
        {
            qDebug("Year Not found!");
        }

        //Rated
        if(parsedResponse["Rated"].toString().contains("N/A") != true)
        {
            //extract Rated here and set it to nepomuk db
        }
        else
        {
            qDebug("Rated Not found!");
        }

        //Released
        if(parsedResponse["Released"].toString().contains("N/A") != true)
        {
            //extract Released here and set it to nepomuk db
        }
        else
        {
            qDebug("Released Not found!");
        }

        //Genre
        if(parsedResponse["Genre"].toString().contains("N/A") != true)
        {
            //extract Genre here and set it to nepomuk db
            //!!!! contains multivalues.. BEWARE!
        }
        else
        {
            qDebug("Genre Not found!");
        }

        //Director
        if(parsedResponse["Director"].toString().contains("N/A") != true)
        {
            //extract Director here and set it to nepomuk db

        }
        else
        {
            qDebug("Director Not found!");
        }

        //... and so on...






        qDebug() << "Movie Title:" << parsedResponse["Title"].toString();

        QDownloader* downloader = new QDownloader("/home/sandeep/.moviemanager/");
        downloader->setFile(parsedResponse["Poster"].toString());

    }
    else
    {
        qDebug("movie not found!");
    }




}



IMDB::~IMDB()
{
}
