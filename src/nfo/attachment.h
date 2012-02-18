#ifndef _NFO_ATTACHMENT_H_
#define _NFO_ATTACHMENT_H_

#include <QtCore/QVariant>
#include <QtCore/QStringList>
#include <QtCore/QUrl>
#include <QtCore/QDate>
#include <QtCore/QTime>
#include <QtCore/QDateTime>

#include <nepomuk/simpleresource.h>

#include "nfo/embeddedfiledataobject.h"

namespace Nepomuk {
namespace NFO {
/**
 * A file attached to another data object. Many data formats allow 
 * for attachments: emails, vcards, ical events, id3 and exif... 
 */
class Attachment : public virtual NFO::EmbeddedFileDataObject
{
public:
    Attachment(const QUrl& uri = QUrl())
      : SimpleResource(uri), NIE::DataObject(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Attachment", QUrl::StrictMode)), NFO::FileDataObject(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Attachment", QUrl::StrictMode)), NFO::EmbeddedFileDataObject(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Attachment", QUrl::StrictMode)) {
    }

    Attachment(const SimpleResource& res)
      : SimpleResource(res), NIE::DataObject(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Attachment", QUrl::StrictMode)), NFO::FileDataObject(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Attachment", QUrl::StrictMode)), NFO::EmbeddedFileDataObject(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Attachment", QUrl::StrictMode)) {
    }

    Attachment& operator=(const SimpleResource& res) {
        SimpleResource::operator=(res);
        addType(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Attachment", QUrl::StrictMode));
        return *this;
    }

protected:
    Attachment(const QUrl& uri, const QUrl& type)      : SimpleResource(uri), NIE::DataObject(uri, type), NFO::FileDataObject(uri, type), NFO::EmbeddedFileDataObject(uri, type) {
    }
    Attachment(const SimpleResource& res, const QUrl& type)
      : SimpleResource(res), NIE::DataObject(res, type), NFO::FileDataObject(res, type), NFO::EmbeddedFileDataObject(res, type) {
    }
};
}
}

#endif
