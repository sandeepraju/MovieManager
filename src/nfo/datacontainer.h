#ifndef _NFO_DATACONTAINER_H_
#define _NFO_DATACONTAINER_H_

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
 * A superclass for all entities, whose primary purpose is to serve 
 * as containers for other data object. They usually don't have 
 * any "meaning" by themselves. Examples include folders, archives 
 * and optical disc images. 
 */
class DataContainer : public virtual NIE::InformationElement
{
public:
    DataContainer(const QUrl& uri = QUrl())
      : SimpleResource(uri), NIE::InformationElement(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#DataContainer", QUrl::StrictMode)) {
    }

    DataContainer(const SimpleResource& res)
      : SimpleResource(res), NIE::InformationElement(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#DataContainer", QUrl::StrictMode)) {
    }

    DataContainer& operator=(const SimpleResource& res) {
        SimpleResource::operator=(res);
        addType(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#DataContainer", QUrl::StrictMode));
        return *this;
    }

protected:
    DataContainer(const QUrl& uri, const QUrl& type)      : SimpleResource(uri), NIE::InformationElement(uri, type) {
    }
    DataContainer(const SimpleResource& res, const QUrl& type)
      : SimpleResource(res), NIE::InformationElement(res, type) {
    }
};
}
}

#endif
