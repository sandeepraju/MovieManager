#ifndef _NFO_PLAINTEXTDOCUMENT_H_
#define _NFO_PLAINTEXTDOCUMENT_H_

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
 * A file containing plain text (ASCII, Unicode or other encodings). 
 * Examples may include TXT, HTML, XML, program source code etc. 
 */
class PlainTextDocument : public virtual NFO::TextDocument
{
public:
    PlainTextDocument(const QUrl& uri = QUrl())
      : SimpleResource(uri), NIE::InformationElement(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#PlainTextDocument", QUrl::StrictMode)), NFO::Document(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#PlainTextDocument", QUrl::StrictMode)), NFO::TextDocument(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#PlainTextDocument", QUrl::StrictMode)) {
    }

    PlainTextDocument(const SimpleResource& res)
      : SimpleResource(res), NIE::InformationElement(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#PlainTextDocument", QUrl::StrictMode)), NFO::Document(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#PlainTextDocument", QUrl::StrictMode)), NFO::TextDocument(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#PlainTextDocument", QUrl::StrictMode)) {
    }

    PlainTextDocument& operator=(const SimpleResource& res) {
        SimpleResource::operator=(res);
        addType(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#PlainTextDocument", QUrl::StrictMode));
        return *this;
    }

protected:
    PlainTextDocument(const QUrl& uri, const QUrl& type)      : SimpleResource(uri), NIE::InformationElement(uri, type), NFO::Document(uri, type), NFO::TextDocument(uri, type) {
    }
    PlainTextDocument(const SimpleResource& res, const QUrl& type)
      : SimpleResource(res), NIE::InformationElement(res, type), NFO::Document(res, type), NFO::TextDocument(res, type) {
    }
};
}
}

#endif
