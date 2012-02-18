#ifndef _NCO_BBSNUMBER_H_
#define _NCO_BBSNUMBER_H_

#include <QtCore/QVariant>
#include <QtCore/QStringList>
#include <QtCore/QUrl>
#include <QtCore/QDate>
#include <QtCore/QTime>
#include <QtCore/QDateTime>

#include <nepomuk/simpleresource.h>

#include "nco/modemnumber.h"

namespace Nepomuk {
namespace NCO {
/**
 * A Bulletin Board System (BBS) phone number. Inspired by the 
 * (TYPE=bbsl) parameter of the TEL property as defined in RFC 
 * 2426 sec 3.3.1. 
 */
class BbsNumber : public virtual NCO::ModemNumber
{
public:
    BbsNumber(const QUrl& uri = QUrl())
      : SimpleResource(uri), NCO::ContactMedium(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#BbsNumber", QUrl::StrictMode)), NCO::PhoneNumber(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#BbsNumber", QUrl::StrictMode)), NCO::ModemNumber(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#BbsNumber", QUrl::StrictMode)) {
    }

    BbsNumber(const SimpleResource& res)
      : SimpleResource(res), NCO::ContactMedium(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#BbsNumber", QUrl::StrictMode)), NCO::PhoneNumber(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#BbsNumber", QUrl::StrictMode)), NCO::ModemNumber(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#BbsNumber", QUrl::StrictMode)) {
    }

    BbsNumber& operator=(const SimpleResource& res) {
        SimpleResource::operator=(res);
        addType(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#BbsNumber", QUrl::StrictMode));
        return *this;
    }

protected:
    BbsNumber(const QUrl& uri, const QUrl& type)      : SimpleResource(uri), NCO::ContactMedium(uri, type), NCO::PhoneNumber(uri, type), NCO::ModemNumber(uri, type) {
    }
    BbsNumber(const SimpleResource& res, const QUrl& type)
      : SimpleResource(res), NCO::ContactMedium(res, type), NCO::PhoneNumber(res, type), NCO::ModemNumber(res, type) {
    }
};
}
}

#endif
