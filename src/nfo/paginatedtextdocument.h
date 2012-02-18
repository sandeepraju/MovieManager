#ifndef _NFO_PAGINATEDTEXTDOCUMENT_H_
#define _NFO_PAGINATEDTEXTDOCUMENT_H_

#include <QtCore/QVariant>
#include <QtCore/QStringList>
#include <QtCore/QUrl>
#include <QtCore/QDate>
#include <QtCore/QTime>
#include <QtCore/QDateTime>

#include <nepomuk/simpleresource.h>

#include "nfo/textdocument.h"

namespace Nepomuk {
namespace NFO {
/**
 * A file containing a text document, that is unambiguously divided 
 * into pages. Examples might include PDF, DOC, PS, DVI etc. 
 */
class PaginatedTextDocument : public virtual NFO::TextDocument
{
public:
    PaginatedTextDocument(const QUrl& uri = QUrl())
      : SimpleResource(uri), NIE::InformationElement(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#PaginatedTextDocument", QUrl::StrictMode)), NFO::Document(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#PaginatedTextDocument", QUrl::StrictMode)), NFO::TextDocument(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#PaginatedTextDocument", QUrl::StrictMode)) {
    }

    PaginatedTextDocument(const SimpleResource& res)
      : SimpleResource(res), NIE::InformationElement(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#PaginatedTextDocument", QUrl::StrictMode)), NFO::Document(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#PaginatedTextDocument", QUrl::StrictMode)), NFO::TextDocument(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#PaginatedTextDocument", QUrl::StrictMode)) {
    }

    PaginatedTextDocument& operator=(const SimpleResource& res) {
        SimpleResource::operator=(res);
        addType(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#PaginatedTextDocument", QUrl::StrictMode));
        return *this;
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#pageCount. 
     * Number of pages. 
     */
    qint64 pageCount() const {
        qint64 value;
        if(contains(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#pageCount", QUrl::StrictMode)))
            value = property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#pageCount", QUrl::StrictMode)).first().value<qint64>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#pageCount. 
     * Number of pages. 
     */
    void setPageCount(const qint64& value) {
        QVariantList values;
        values << value;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#pageCount", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#pageCount. 
     * Number of pages. 
     */
    void addPageCount(const qint64& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#pageCount", QUrl::StrictMode), value);
    }

protected:
    PaginatedTextDocument(const QUrl& uri, const QUrl& type)      : SimpleResource(uri), NIE::InformationElement(uri, type), NFO::Document(uri, type), NFO::TextDocument(uri, type) {
    }
    PaginatedTextDocument(const SimpleResource& res, const QUrl& type)
      : SimpleResource(res), NIE::InformationElement(res, type), NFO::Document(res, type), NFO::TextDocument(res, type) {
    }
};
}
}

#endif
