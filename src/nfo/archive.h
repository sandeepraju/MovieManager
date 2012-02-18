#ifndef _NFO_ARCHIVE_H_
#define _NFO_ARCHIVE_H_

#include <QtCore/QVariant>
#include <QtCore/QStringList>
#include <QtCore/QUrl>
#include <QtCore/QDate>
#include <QtCore/QTime>
#include <QtCore/QDateTime>

#include <nepomuk/simpleresource.h>

#include "nfo/datacontainer.h"

namespace Nepomuk {
namespace NFO {
/**
 * A compressed file. May contain other files or folder inside. 
 */
class Archive : public virtual NFO::DataContainer
{
public:
    Archive(const QUrl& uri = QUrl())
      : SimpleResource(uri), NIE::InformationElement(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Archive", QUrl::StrictMode)), NFO::DataContainer(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Archive", QUrl::StrictMode)) {
    }

    Archive(const SimpleResource& res)
      : SimpleResource(res), NIE::InformationElement(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Archive", QUrl::StrictMode)), NFO::DataContainer(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Archive", QUrl::StrictMode)) {
    }

    Archive& operator=(const SimpleResource& res) {
        SimpleResource::operator=(res);
        addType(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Archive", QUrl::StrictMode));
        return *this;
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#uncompressedSize. 
     * Uncompressed size of the content of a compressed file. 
     */
    qint64 uncompressedSize() const {
        qint64 value;
        if(contains(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#uncompressedSize", QUrl::StrictMode)))
            value = property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#uncompressedSize", QUrl::StrictMode)).first().value<qint64>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#uncompressedSize. 
     * Uncompressed size of the content of a compressed file. 
     */
    void setUncompressedSize(const qint64& value) {
        QVariantList values;
        values << value;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#uncompressedSize", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#uncompressedSize. 
     * Uncompressed size of the content of a compressed file. 
     */
    void addUncompressedSize(const qint64& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#uncompressedSize", QUrl::StrictMode), value);
    }

protected:
    Archive(const QUrl& uri, const QUrl& type)      : SimpleResource(uri), NIE::InformationElement(uri, type), NFO::DataContainer(uri, type) {
    }
    Archive(const SimpleResource& res, const QUrl& type)
      : SimpleResource(res), NIE::InformationElement(res, type), NFO::DataContainer(res, type) {
    }
};
}
}

#endif
