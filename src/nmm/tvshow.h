#ifndef _NMM_TVSHOW_H_
#define _NMM_TVSHOW_H_

#include <QtCore/QVariant>
#include <QtCore/QStringList>
#include <QtCore/QUrl>
#include <QtCore/QDate>
#include <QtCore/QTime>
#include <QtCore/QDateTime>

#include <nepomuk/simpleresource.h>

#include "nfo/video.h"

namespace Nepomuk {
namespace NMM {
/**
 * A TV Show 
 */
class TVShow : public virtual NFO::Video
{
public:
    TVShow(const QUrl& uri = QUrl())
      : SimpleResource(uri), NIE::InformationElement(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#TVShow", QUrl::StrictMode)), NFO::Media(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#TVShow", QUrl::StrictMode)), NFO::Visual(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#TVShow", QUrl::StrictMode)), NFO::Video(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#TVShow", QUrl::StrictMode)) {
    }

    TVShow(const SimpleResource& res)
      : SimpleResource(res), NIE::InformationElement(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#TVShow", QUrl::StrictMode)), NFO::Media(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#TVShow", QUrl::StrictMode)), NFO::Visual(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#TVShow", QUrl::StrictMode)), NFO::Video(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#TVShow", QUrl::StrictMode)) {
    }

    TVShow& operator=(const SimpleResource& res) {
        SimpleResource::operator=(res);
        addType(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#TVShow", QUrl::StrictMode));
        return *this;
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#season. 
     */
    qint64 season() const {
        qint64 value;
        if(contains(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#season", QUrl::StrictMode)))
            value = property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#season", QUrl::StrictMode)).first().value<qint64>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#season. 
     */
    void setSeason(const qint64& value) {
        QVariantList values;
        values << value;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#season", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#season. 
     */
    void addSeason(const qint64& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#season", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#series. 
     * series 
     */
    QUrl series() const {
        QUrl value;
        if(contains(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#series", QUrl::StrictMode)))
            value = property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#series", QUrl::StrictMode)).first().value<QUrl>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#series. 
     * series 
     */
    void setSeries(const QUrl& value) {
        QVariantList values;
        values << value;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#series", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#series. 
     * series 
     */
    void addSeries(const QUrl& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#series", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#episodeNumber. 
     */
    qint64 episodeNumber() const {
        qint64 value;
        if(contains(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#episodeNumber", QUrl::StrictMode)))
            value = property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#episodeNumber", QUrl::StrictMode)).first().value<qint64>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#episodeNumber. 
     */
    void setEpisodeNumber(const qint64& value) {
        QVariantList values;
        values << value;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#episodeNumber", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#episodeNumber. 
     */
    void addEpisodeNumber(const qint64& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#episodeNumber", QUrl::StrictMode), value);
    }

protected:
    TVShow(const QUrl& uri, const QUrl& type)      : SimpleResource(uri), NIE::InformationElement(uri, type), NFO::Media(uri, type), NFO::Visual(uri, type), NFO::Video(uri, type) {
    }
    TVShow(const SimpleResource& res, const QUrl& type)
      : SimpleResource(res), NIE::InformationElement(res, type), NFO::Media(res, type), NFO::Visual(res, type), NFO::Video(res, type) {
    }
};
}
}

#endif
