#ifndef _NFO_MEDIASTREAM_H_
#define _NFO_MEDIASTREAM_H_

#include <QtCore/QVariant>
#include <QtCore/QStringList>
#include <QtCore/QUrl>
#include <QtCore/QDate>
#include <QtCore/QTime>
#include <QtCore/QDateTime>

#include <nepomuk/simpleresource.h>

#include "nie/dataobject.h"

namespace Nepomuk {
namespace NFO {
/**
 * A stream of multimedia content, usually contained within a 
 * media container such as a movie (containing both audio and video) 
 * or a DVD (possibly containing many streams of audio and video). 
 * Most common interpretations for such a DataObject include 
 * Audio and Video. 
 */
class MediaStream : public virtual NIE::DataObject
{
public:
    MediaStream(const QUrl& uri = QUrl())
      : SimpleResource(uri), NIE::DataObject(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#MediaStream", QUrl::StrictMode)) {
    }

    MediaStream(const SimpleResource& res)
      : SimpleResource(res), NIE::DataObject(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#MediaStream", QUrl::StrictMode)) {
    }

    MediaStream& operator=(const SimpleResource& res) {
        SimpleResource::operator=(res);
        addType(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#MediaStream", QUrl::StrictMode));
        return *this;
    }

protected:
    MediaStream(const QUrl& uri, const QUrl& type)      : SimpleResource(uri), NIE::DataObject(uri, type) {
    }
    MediaStream(const SimpleResource& res, const QUrl& type)
      : SimpleResource(res), NIE::DataObject(res, type) {
    }
};
}
}

#endif
