#ifndef _NFO_HARDDISKPARTITION_H_
#define _NFO_HARDDISKPARTITION_H_

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
 * A partition on a hard disk 
 */
class HardDiskPartition : public virtual NIE::DataObject
{
public:
    HardDiskPartition(const QUrl& uri = QUrl())
      : SimpleResource(uri), NIE::DataObject(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#HardDiskPartition", QUrl::StrictMode)) {
    }

    HardDiskPartition(const SimpleResource& res)
      : SimpleResource(res), NIE::DataObject(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#HardDiskPartition", QUrl::StrictMode)) {
    }

    HardDiskPartition& operator=(const SimpleResource& res) {
        SimpleResource::operator=(res);
        addType(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#HardDiskPartition", QUrl::StrictMode));
        return *this;
    }

protected:
    HardDiskPartition(const QUrl& uri, const QUrl& type)      : SimpleResource(uri), NIE::DataObject(uri, type) {
    }
    HardDiskPartition(const SimpleResource& res, const QUrl& type)
      : SimpleResource(res), NIE::DataObject(res, type) {
    }
};
}
}

#endif
