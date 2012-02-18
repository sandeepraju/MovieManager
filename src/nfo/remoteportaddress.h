#ifndef _NFO_REMOTEPORTADDRESS_H_
#define _NFO_REMOTEPORTADDRESS_H_

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
 * An address specifying a remote host and port. Such an address 
 * can be interpreted in many ways (examples of such interpretations 
 * include mailboxes, websites, remote calendars or filesystems), 
 * depending on an interpretation, various kinds of data may be 
 * extracted from such an address. 
 */
class RemotePortAddress : public virtual NIE::DataObject
{
public:
    RemotePortAddress(const QUrl& uri = QUrl())
      : SimpleResource(uri), NIE::DataObject(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#RemotePortAddress", QUrl::StrictMode)) {
    }

    RemotePortAddress(const SimpleResource& res)
      : SimpleResource(res), NIE::DataObject(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#RemotePortAddress", QUrl::StrictMode)) {
    }

    RemotePortAddress& operator=(const SimpleResource& res) {
        SimpleResource::operator=(res);
        addType(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#RemotePortAddress", QUrl::StrictMode));
        return *this;
    }

protected:
    RemotePortAddress(const QUrl& uri, const QUrl& type)      : SimpleResource(uri), NIE::DataObject(uri, type) {
    }
    RemotePortAddress(const SimpleResource& res, const QUrl& type)
      : SimpleResource(res), NIE::DataObject(res, type) {
    }
};
}
}

#endif
