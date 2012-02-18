#ifndef _NFO_MINDMAP_H_
#define _NFO_MINDMAP_H_

#include <QtCore/QVariant>
#include <QtCore/QStringList>
#include <QtCore/QUrl>
#include <QtCore/QDate>
#include <QtCore/QTime>
#include <QtCore/QDateTime>

#include <nepomuk/simpleresource.h>

#include "nfo/document.h"

namespace Nepomuk {
namespace NFO {
/**
 * A MindMap, created by a mind-mapping utility. Examples might 
 * include FreeMind or mind mapper. 
 */
class MindMap : public virtual NFO::Document
{
public:
    MindMap(const QUrl& uri = QUrl())
      : SimpleResource(uri), NIE::InformationElement(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#MindMap", QUrl::StrictMode)), NFO::Document(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#MindMap", QUrl::StrictMode)) {
    }

    MindMap(const SimpleResource& res)
      : SimpleResource(res), NIE::InformationElement(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#MindMap", QUrl::StrictMode)), NFO::Document(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#MindMap", QUrl::StrictMode)) {
    }

    MindMap& operator=(const SimpleResource& res) {
        SimpleResource::operator=(res);
        addType(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#MindMap", QUrl::StrictMode));
        return *this;
    }

protected:
    MindMap(const QUrl& uri, const QUrl& type)      : SimpleResource(uri), NIE::InformationElement(uri, type), NFO::Document(uri, type) {
    }
    MindMap(const SimpleResource& res, const QUrl& type)
      : SimpleResource(res), NIE::InformationElement(res, type), NFO::Document(res, type) {
    }
};
}
}

#endif
