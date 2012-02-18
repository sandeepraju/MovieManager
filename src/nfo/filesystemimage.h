#ifndef _NFO_FILESYSTEMIMAGE_H_
#define _NFO_FILESYSTEMIMAGE_H_

#include <QtCore/QVariant>
#include <QtCore/QStringList>
#include <QtCore/QUrl>
#include <QtCore/QDate>
#include <QtCore/QTime>
#include <QtCore/QDateTime>

#include <nepomuk/simpleresource.h>

#include "nfo/filesystem.h"

namespace Nepomuk {
namespace NFO {
/**
 * An image of a filesystem. Instances of this class may include 
 * CD images, DVD images or hard disk partition images created 
 * by various pieces of software (e.g. Norton Ghost). Deprecated 
 * in favor of nfo:Filesystem. 
 */
class FilesystemImage : public virtual NFO::Filesystem
{
public:
    FilesystemImage(const QUrl& uri = QUrl())
      : SimpleResource(uri), NIE::InformationElement(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#FilesystemImage", QUrl::StrictMode)), NFO::DataContainer(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#FilesystemImage", QUrl::StrictMode)), NFO::Filesystem(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#FilesystemImage", QUrl::StrictMode)) {
    }

    FilesystemImage(const SimpleResource& res)
      : SimpleResource(res), NIE::InformationElement(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#FilesystemImage", QUrl::StrictMode)), NFO::DataContainer(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#FilesystemImage", QUrl::StrictMode)), NFO::Filesystem(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#FilesystemImage", QUrl::StrictMode)) {
    }

    FilesystemImage& operator=(const SimpleResource& res) {
        SimpleResource::operator=(res);
        addType(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#FilesystemImage", QUrl::StrictMode));
        return *this;
    }

protected:
    FilesystemImage(const QUrl& uri, const QUrl& type)      : SimpleResource(uri), NIE::InformationElement(uri, type), NFO::DataContainer(uri, type), NFO::Filesystem(uri, type) {
    }
    FilesystemImage(const SimpleResource& res, const QUrl& type)
      : SimpleResource(res), NIE::InformationElement(res, type), NFO::DataContainer(res, type), NFO::Filesystem(res, type) {
    }
};
}
}

#endif
