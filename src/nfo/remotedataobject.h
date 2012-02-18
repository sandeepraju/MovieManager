#ifndef _NFO_REMOTEDATAOBJECT_H_
#define _NFO_REMOTEDATAOBJECT_H_

#include <QtCore/QVariant>
#include <QtCore/QStringList>
#include <QtCore/QUrl>
#include <QtCore/QDate>
#include <QtCore/QTime>
#include <QtCore/QDateTime>

#include <nepomuk/simpleresource.h>

#include "nfo/filedataobject.h"

namespace Nepomuk {
namespace NFO {
/**
 * A file data object stored at a remote location. Don't confuse 
 * this class with a RemotePortAddress. This one applies to a particular 
 * resource, RemotePortAddress applies to an address, that can 
 * have various interpretations. 
 */
class RemoteDataObject : public virtual NFO::FileDataObject
{
public:
    RemoteDataObject(const QUrl& uri = QUrl())
      : SimpleResource(uri), NIE::DataObject(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#RemoteDataObject", QUrl::StrictMode)), NFO::FileDataObject(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#RemoteDataObject", QUrl::StrictMode)) {
    }

    RemoteDataObject(const SimpleResource& res)
      : SimpleResource(res), NIE::DataObject(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#RemoteDataObject", QUrl::StrictMode)), NFO::FileDataObject(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#RemoteDataObject", QUrl::StrictMode)) {
    }

    RemoteDataObject& operator=(const SimpleResource& res) {
        SimpleResource::operator=(res);
        addType(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#RemoteDataObject", QUrl::StrictMode));
        return *this;
    }

protected:
    RemoteDataObject(const QUrl& uri, const QUrl& type)      : SimpleResource(uri), NIE::DataObject(uri, type), NFO::FileDataObject(uri, type) {
    }
    RemoteDataObject(const SimpleResource& res, const QUrl& type)
      : SimpleResource(res), NIE::DataObject(res, type), NFO::FileDataObject(res, type) {
    }
};
}
}

#endif
