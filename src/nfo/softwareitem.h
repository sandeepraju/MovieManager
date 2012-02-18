#ifndef _NFO_SOFTWAREITEM_H_
#define _NFO_SOFTWAREITEM_H_

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
 * A DataObject representing a piece of software. Examples of 
 * interpretations of a SoftwareItem include an Application 
 * and an OperatingSystem. 
 */
class SoftwareItem : public virtual NIE::DataObject
{
public:
    SoftwareItem(const QUrl& uri = QUrl())
      : SimpleResource(uri), NIE::DataObject(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#SoftwareItem", QUrl::StrictMode)) {
    }

    SoftwareItem(const SimpleResource& res)
      : SimpleResource(res), NIE::DataObject(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#SoftwareItem", QUrl::StrictMode)) {
    }

    SoftwareItem& operator=(const SimpleResource& res) {
        SimpleResource::operator=(res);
        addType(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#SoftwareItem", QUrl::StrictMode));
        return *this;
    }

protected:
    SoftwareItem(const QUrl& uri, const QUrl& type)      : SimpleResource(uri), NIE::DataObject(uri, type) {
    }
    SoftwareItem(const SimpleResource& res, const QUrl& type)
      : SimpleResource(res), NIE::DataObject(res, type) {
    }
};
}
}

#endif
