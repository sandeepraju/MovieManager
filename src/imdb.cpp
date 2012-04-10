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
//#include "nco/contact.h"
#include <Nepomuk/Vocabulary/NCO>
#include <Nepomuk/Vocabulary/NMM>
#include "nfo/image.h"
#include "nfo/webdataobject.h"
#include "nco/contact.h"



IMDB::IMDB(QString queryName, Nepomuk::Resource movieResource)
{

    this->movieName = new QString(queryName.toLatin1().data());
    this->baseURL = new QString("http://www.imdbapi.com/?t=");
    this->mResource = movieResource;
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
    //qDebug("got successfully!");
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

    if(true/*parsedResponse["Response"].toString().compare("True") == 0*/)
    {

        qDebug() << "Movie Title:" << parsedResponse["Title"].toString();

        QDownloader* downloader = new QDownloader("/home/sandeep/.moviemanager/", parsedResponse["ID"].toString() + ".jpg");
        downloader->setFile(parsedResponse["Poster"].toString());

        /*
          {"Title":"Avatar",
            "Year":"2009",
            "Rated":"PG-13",
            "Released":"18 Dec 2009",
            "Genre":"Action, Adventure, Fantasy, Sci-Fi",
            "Director":"James Cameron",
            "Writer":"James Cameron",
            "Actors":"Sam Worthington, Zoe Saldana, Sigourney Weaver, Michelle Rodriguez",
            "Plot":"A paraplegic marine dispatched to the moon Pandora on a unique mission becomes torn between following his orders and protecting the world he feels is his home.",
            "Poster":"http://ia.media-imdb.com/images/M/MV5BMTYwOTEwNjAzMl5BMl5BanBnXkFtZTcwODc5MTUwMw@@._V1_SX320.jpg",
            "Runtime":"2 hrs 42 mins",
            "Rating":"8.1",
            "Votes":"386930",
            "ID":"tt0499549",
            "Response":"True"}
          */

        /*
            // create all the regular actor resources which we will add to all episodes
             QList<Nepomuk::NCO::Contact> regularActors;
             foreach(const QString& actor, series.actors()) {
                 Nepomuk::NCO::Contact contact;
                 contact.setFullname(actor);
                 regularActors << contact;
                 graph << contact;
             }

        */

       Nepomuk::Resource tempActor;
       tempActor.addType(Nepomuk::Vocabulary::NCO::Contact());
       tempActor.setLabel(QString("Phaneendra hegde"));


        //accessing mResource
        qDebug() << mResource.property(Nepomuk::Vocabulary::NFO::fileName()).toString() << "wohoooo";
        //how to add another actor? tvnamer.cpp line no.333 to 340
//        mResource.setProperty(Nepomuk::Vocabulary::NMM::actor(),parsedResponse["Actors"].toString());
        qDebug() << parsedResponse["Actors"].toString();
        qDebug() << parsedResponse["Director"].toString();
//        qDebug() << parsedResponse["Actors"].toString();
//        qDebug() << parsedResponse["Actors"].toString();
//        qDebug() << parsedResponse["Actors"].toString();
        //mResource.addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#hero", QUrl::StrictMode),"Upendra");

        //mResource.setProperty(Nepomuk::Vocabulary::NMM::artwork(),parsedResponse["Poster"].toString());//qurl
        /*mResource.setProperty(Nepomuk::Vocabulary::NMM::director(),parsedResponse["Director"].toString());
        mResource.setProperty(Nepomuk::Vocabulary::NMM::writer(),parsedResponse["Writer"].toString());
        mResource.setProperty(Nepomuk::Vocabulary::NMM::genre(),parsedResponse["Genre"].toString());
        mResource.setProperty(Nepomuk::Vocabulary::NMM::releaseDate(),parsedResponse["Released"].toString());
        mResource.setProperty(Nepomuk::Vocabulary::NMM::audienceRating(),parsedResponse["Rating"].toString());
        mResource.setProperty(Nepomuk::Vocabulary::NMM::actor(),tempActor);
        */
        Nepomuk::Resource tempActor2;
        tempActor2.addType(Nepomuk::Vocabulary::NCO::Contact());
        tempActor2.setLabel(QString("Vijay Mahantesh"));

        mResource.setProperty(Nepomuk::Vocabulary::NMM::writer(),tempActor2 );

        mResource.setProperty(Nepomuk::Vocabulary::NMM::synopsis(),parsedResponse["ID"].toString());

        Nepomuk::Resource* tempImage = new Nepomuk::Resource("/home/sandeep/.moviemanager/"+parsedResponse["ID"].toString() +".jpg");
        tempImage->addType(Nepomuk::Vocabulary::NFO::Image());
        //tempActor.set

        mResource.setProperty(Nepomuk::Vocabulary::NMM::artwork(),*tempImage);

        //mResource.setProperty(Nepomuk::Vocabulary);


    }
    else
    {
        qDebug("movie not found!");
    }




}



IMDB::~IMDB()
{
}
