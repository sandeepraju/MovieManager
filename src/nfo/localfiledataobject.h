#ifndef _NFO_LOCALFILEDATAOBJECT_H_
#define _NFO_LOCALFILEDATAOBJECT_H_

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
 * A local file data object which is stored on a local file system. 
 * Its nie:url always uses the file:/ protocol. The main use of 
 * this class is to distinguish local and non-local files. 
 */
class LocalFileDataObject : public virtual NFO::FileDataObject
{
public:
    LocalFileDataObject(const QUrl& uri = QUrl())
      : SimpleResource(uri), NIE::DataObject(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#LocalFileDataObject", QUrl::StrictMode)), NFO::FileDataObject(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#LocalFileDataObject", QUrl::StrictMode)) {
    }

    LocalFileDataObject(const SimpleResource& res)
      : SimpleResource(res), NIE::DataObject(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#LocalFileDataObject", QUrl::StrictMode)), NFO::FileDataObject(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#LocalFileDataObject", QUrl::StrictMode)) {
    }

    LocalFileDataObject& operator=(const SimpleResource& res) {
        SimpleResource::operator=(res);
        addType(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#LocalFileDataObject", QUrl::StrictMode));
        return *this;
    }

protected:
    LocalFileDataObject(const QUrl& uri, const QUrl& type)      : SimpleResource(uri), NIE::DataObject(uri, type), NFO::FileDataObject(uri, type) {
    }
    LocalFileDataObject(const SimpleResource& res, const QUrl& type)
      : SimpleResource(res), NIE::DataObject(res, type), NFO::FileDataObject(res, type) {
    }
};
}
}

#endif
