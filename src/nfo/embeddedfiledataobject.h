#ifndef _NFO_EMBEDDEDFILEDATAOBJECT_H_
#define _NFO_EMBEDDEDFILEDATAOBJECT_H_

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
 * A file embedded in another data object. There are many ways in 
 * which a file may be embedded in another one. Use this class directly 
 * only in cases if none of the subclasses gives a better description 
 * of your case. 
 */
class EmbeddedFileDataObject : public virtual NFO::FileDataObject
{
public:
    EmbeddedFileDataObject(const QUrl& uri = QUrl())
      : SimpleResource(uri), NIE::DataObject(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#EmbeddedFileDataObject", QUrl::StrictMode)), NFO::FileDataObject(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#EmbeddedFileDataObject", QUrl::StrictMode)) {
    }

    EmbeddedFileDataObject(const SimpleResource& res)
      : SimpleResource(res), NIE::DataObject(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#EmbeddedFileDataObject", QUrl::StrictMode)), NFO::FileDataObject(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#EmbeddedFileDataObject", QUrl::StrictMode)) {
    }

    EmbeddedFileDataObject& operator=(const SimpleResource& res) {
        SimpleResource::operator=(res);
        addType(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#EmbeddedFileDataObject", QUrl::StrictMode));
        return *this;
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#encoding. 
     * The encoding used for the Embedded File. Examples might include 
     * BASE64 or UUEncode 
     */
    QString encoding() const {
        QString value;
        if(contains(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#encoding", QUrl::StrictMode)))
            value = property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#encoding", QUrl::StrictMode)).first().value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#encoding. 
     * The encoding used for the Embedded File. Examples might include 
     * BASE64 or UUEncode 
     */
    void setEncoding(const QString& value) {
        QVariantList values;
        values << value;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#encoding", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#encoding. 
     * The encoding used for the Embedded File. Examples might include 
     * BASE64 or UUEncode 
     */
    void addEncoding(const QString& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#encoding", QUrl::StrictMode), value);
    }

protected:
    EmbeddedFileDataObject(const QUrl& uri, const QUrl& type)      : SimpleResource(uri), NIE::DataObject(uri, type), NFO::FileDataObject(uri, type) {
    }
    EmbeddedFileDataObject(const SimpleResource& res, const QUrl& type)
      : SimpleResource(res), NIE::DataObject(res, type), NFO::FileDataObject(res, type) {
    }
};
}
}

#endif
