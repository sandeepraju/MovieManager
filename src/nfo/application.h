#ifndef _NFO_APPLICATION_H_
#define _NFO_APPLICATION_H_

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
 * An application 
 */
class Application : public virtual NFO::Software
{
public:
    Application(const QUrl& uri = QUrl())
      : SimpleResource(uri), NIE::InformationElement(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Application", QUrl::StrictMode)), NFO::Software(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Application", QUrl::StrictMode)) {
    }

    Application(const SimpleResource& res)
      : SimpleResource(res), NIE::InformationElement(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Application", QUrl::StrictMode)), NFO::Software(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Application", QUrl::StrictMode)) {
    }

    Application& operator=(const SimpleResource& res) {
        SimpleResource::operator=(res);
        addType(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Application", QUrl::StrictMode));
        return *this;
    }

protected:
    Application(const QUrl& uri, const QUrl& type)      : SimpleResource(uri), NIE::InformationElement(uri, type), NFO::Software(uri, type) {
    }
    Application(const SimpleResource& res, const QUrl& type)
      : SimpleResource(res), NIE::InformationElement(res, type), NFO::Software(res, type) {
    }
};
}
}

#endif
