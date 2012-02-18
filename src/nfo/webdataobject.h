#ifndef _NFO_WEBDATAOBJECT_H_
#define _NFO_WEBDATAOBJECT_H_

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
 * An information resources of which representations (files, 
 * streams) can be retrieved through a web server. They may be generated 
 * at retrieval time. Typical examples are pages served by PHP 
 * or AJAX or mp3 streams. 
 */
class WebDataObject : public virtual NIE::DataObject
{
public:
    WebDataObject(const QUrl& uri = QUrl())
      : SimpleResource(uri), NIE::DataObject(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#WebDataObject", QUrl::StrictMode)) {
    }

    WebDataObject(const SimpleResource& res)
      : SimpleResource(res), NIE::DataObject(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#WebDataObject", QUrl::StrictMode)) {
    }

    WebDataObject& operator=(const SimpleResource& res) {
        SimpleResource::operator=(res);
        addType(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#WebDataObject", QUrl::StrictMode));
        return *this;
    }

protected:
    WebDataObject(const QUrl& uri, const QUrl& type)      : SimpleResource(uri), NIE::DataObject(uri, type) {
    }
    WebDataObject(const SimpleResource& res, const QUrl& type)
      : SimpleResource(res), NIE::DataObject(res, type) {
    }
};
}
}

#endif
