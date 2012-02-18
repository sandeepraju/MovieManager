#ifndef _NFO_OPERATINGSYSTEM_H_
#define _NFO_OPERATINGSYSTEM_H_

#include <QtCore/QVariant>
#include <QtCore/QStringList>
#include <QtCore/QUrl>
#include <QtCore/QDate>
#include <QtCore/QTime>
#include <QtCore/QDateTime>

#include <nepomuk/simpleresource.h>

#include "nfo/software.h"

namespace Nepomuk {
namespace NFO {
/**
 * An OperatingSystem 
 */
class OperatingSystem : public virtual NFO::Software
{
public:
    OperatingSystem(const QUrl& uri = QUrl())
      : SimpleResource(uri), NIE::InformationElement(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#OperatingSystem", QUrl::StrictMode)), NFO::Software(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#OperatingSystem", QUrl::StrictMode)) {
    }

    OperatingSystem(const SimpleResource& res)
      : SimpleResource(res), NIE::InformationElement(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#OperatingSystem", QUrl::StrictMode)), NFO::Software(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#OperatingSystem", QUrl::StrictMode)) {
    }

    OperatingSystem& operator=(const SimpleResource& res) {
        SimpleResource::operator=(res);
        addType(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#OperatingSystem", QUrl::StrictMode));
        return *this;
    }

protected:
    OperatingSystem(const QUrl& uri, const QUrl& type)      : SimpleResource(uri), NIE::InformationElement(uri, type), NFO::Software(uri, type) {
    }
    OperatingSystem(const SimpleResource& res, const QUrl& type)
      : SimpleResource(res), NIE::InformationElement(res, type), NFO::Software(res, type) {
    }
};
}
}

#endif
