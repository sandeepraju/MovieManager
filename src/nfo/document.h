#ifndef _NFO_DOCUMENT_H_
#define _NFO_DOCUMENT_H_

#include <QtCore/QVariant>
#include <QtCore/QStringList>
#include <QtCore/QUrl>
#include <QtCore/QDate>
#include <QtCore/QTime>
#include <QtCore/QDateTime>

#include <nepomuk/simpleresource.h>

#include "nie/informationelement.h"

namespace Nepomuk {
namespace NFO {
/**
 * A generic document. A common superclass for all documents on 
 * the desktop. 
 */
class Document : public virtual NIE::InformationElement
{
public:
    Document(const QUrl& uri = QUrl())
      : SimpleResource(uri), NIE::InformationElement(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Document", QUrl::StrictMode)) {
    }

    Document(const SimpleResource& res)
      : SimpleResource(res), NIE::InformationElement(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Document", QUrl::StrictMode)) {
    }

    Document& operator=(const SimpleResource& res) {
        SimpleResource::operator=(res);
        addType(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Document", QUrl::StrictMode));
        return *this;
    }

protected:
    Document(const QUrl& uri, const QUrl& type)      : SimpleResource(uri), NIE::InformationElement(uri, type) {
    }
    Document(const SimpleResource& res, const QUrl& type)
      : SimpleResource(res), NIE::InformationElement(res, type) {
    }
};
}
}

#endif
