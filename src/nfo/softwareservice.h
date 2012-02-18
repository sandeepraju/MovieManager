#ifndef _NFO_SOFTWARESERVICE_H_
#define _NFO_SOFTWARESERVICE_H_

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
 * A service published by a piece of software, either by an operating 
 * system or an application. Examples of such services may include 
 * calendar, addressbook and mailbox managed by a PIM application. 
 * This category is introduced to distinguish between data available 
 * directly from the applications (Via some Interprocess Communication 
 * Mechanisms) and data available from files on a disk. In either 
 * case both DataObjects would receive a similar interpretation 
 * (e.g. a Mailbox) and wouldn't differ on the content level. 
 */
class SoftwareService : public virtual NIE::DataObject
{
public:
    SoftwareService(const QUrl& uri = QUrl())
      : SimpleResource(uri), NIE::DataObject(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#SoftwareService", QUrl::StrictMode)) {
    }

    SoftwareService(const SimpleResource& res)
      : SimpleResource(res), NIE::DataObject(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#SoftwareService", QUrl::StrictMode)) {
    }

    SoftwareService& operator=(const SimpleResource& res) {
        SimpleResource::operator=(res);
        addType(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#SoftwareService", QUrl::StrictMode));
        return *this;
    }

protected:
    SoftwareService(const QUrl& uri, const QUrl& type)      : SimpleResource(uri), NIE::DataObject(uri, type) {
    }
    SoftwareService(const SimpleResource& res, const QUrl& type)
      : SimpleResource(res), NIE::DataObject(res, type) {
    }
};
}
}

#endif
