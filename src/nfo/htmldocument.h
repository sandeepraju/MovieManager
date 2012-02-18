#ifndef _NFO_HTMLDOCUMENT_H_
#define _NFO_HTMLDOCUMENT_H_

#include <QtCore/QVariant>
#include <QtCore/QStringList>
#include <QtCore/QUrl>
#include <QtCore/QDate>
#include <QtCore/QTime>
#include <QtCore/QDateTime>

#include <nepomuk/simpleresource.h>

#include "nfo/plaintextdocument.h"

namespace Nepomuk {
namespace NFO {
/**
 * A HTML document, may contain links to other files. 
 */
class HtmlDocument : public virtual NFO::PlainTextDocument
{
public:
    HtmlDocument(const QUrl& uri = QUrl())
      : SimpleResource(uri), NIE::InformationElement(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#HtmlDocument", QUrl::StrictMode)), NFO::Document(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#HtmlDocument", QUrl::StrictMode)), NFO::TextDocument(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#HtmlDocument", QUrl::StrictMode)), NFO::PlainTextDocument(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#HtmlDocument", QUrl::StrictMode)) {
    }

    HtmlDocument(const SimpleResource& res)
      : SimpleResource(res), NIE::InformationElement(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#HtmlDocument", QUrl::StrictMode)), NFO::Document(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#HtmlDocument", QUrl::StrictMode)), NFO::TextDocument(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#HtmlDocument", QUrl::StrictMode)), NFO::PlainTextDocument(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#HtmlDocument", QUrl::StrictMode)) {
    }

    HtmlDocument& operator=(const SimpleResource& res) {
        SimpleResource::operator=(res);
        addType(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#HtmlDocument", QUrl::StrictMode));
        return *this;
    }

protected:
    HtmlDocument(const QUrl& uri, const QUrl& type)      : SimpleResource(uri), NIE::InformationElement(uri, type), NFO::Document(uri, type), NFO::TextDocument(uri, type), NFO::PlainTextDocument(uri, type) {
    }
    HtmlDocument(const SimpleResource& res, const QUrl& type)
      : SimpleResource(res), NIE::InformationElement(res, type), NFO::Document(res, type), NFO::TextDocument(res, type), NFO::PlainTextDocument(res, type) {
    }
};
}
}

#endif
