#ifndef _NFO_PRESENTATION_H_
#define _NFO_PRESENTATION_H_

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
 * A Presentation made by some presentation software (Corel Presentations, 
 * OpenOffice Impress, MS Powerpoint etc.) 
 */
class Presentation : public virtual NFO::Document
{
public:
    Presentation(const QUrl& uri = QUrl())
      : SimpleResource(uri), NIE::InformationElement(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Presentation", QUrl::StrictMode)), NFO::Document(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Presentation", QUrl::StrictMode)) {
    }

    Presentation(const SimpleResource& res)
      : SimpleResource(res), NIE::InformationElement(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Presentation", QUrl::StrictMode)), NFO::Document(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Presentation", QUrl::StrictMode)) {
    }

    Presentation& operator=(const SimpleResource& res) {
        SimpleResource::operator=(res);
        addType(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Presentation", QUrl::StrictMode));
        return *this;
    }

protected:
    Presentation(const QUrl& uri, const QUrl& type)      : SimpleResource(uri), NIE::InformationElement(uri, type), NFO::Document(uri, type) {
    }
    Presentation(const SimpleResource& res, const QUrl& type)
      : SimpleResource(res), NIE::InformationElement(res, type), NFO::Document(res, type) {
    }
};
}
}

#endif
