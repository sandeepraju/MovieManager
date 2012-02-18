#ifndef _NMM_MOVIE_H_
#define _NMM_MOVIE_H_

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
 * A Movie 
 */
class Movie : public virtual NFO::Video
{
public:
    Movie(const QUrl& uri = QUrl())
      : SimpleResource(uri), NIE::InformationElement(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#Movie", QUrl::StrictMode)), NFO::Media(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#Movie", QUrl::StrictMode)), NFO::Visual(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#Movie", QUrl::StrictMode)), NFO::Video(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#Movie", QUrl::StrictMode)) {
    }

    Movie(const SimpleResource& res)
      : SimpleResource(res), NIE::InformationElement(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#Movie", QUrl::StrictMode)), NFO::Media(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#Movie", QUrl::StrictMode)), NFO::Visual(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#Movie", QUrl::StrictMode)), NFO::Video(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#Movie", QUrl::StrictMode)) {
    }

    Movie& operator=(const SimpleResource& res) {
        SimpleResource::operator=(res);
        addType(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#Movie", QUrl::StrictMode));
        return *this;
    }

protected:
    Movie(const QUrl& uri, const QUrl& type)      : SimpleResource(uri), NIE::InformationElement(uri, type), NFO::Media(uri, type), NFO::Visual(uri, type), NFO::Video(uri, type) {
    }
    Movie(const SimpleResource& res, const QUrl& type)
      : SimpleResource(res), NIE::InformationElement(res, type), NFO::Media(res, type), NFO::Visual(res, type), NFO::Video(res, type) {
    }
};
}
}

#endif
