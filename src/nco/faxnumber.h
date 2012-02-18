#ifndef _NCO_FAXNUMBER_H_
#define _NCO_FAXNUMBER_H_

#include <QtCore/QVariant>
#include <QtCore/QStringList>
#include <QtCore/QUrl>
#include <QtCore/QDate>
#include <QtCore/QTime>
#include <QtCore/QDateTime>

#include <nepomuk/simpleresource.h>

#include "nco/phonenumber.h"

namespace Nepomuk {
namespace NCO {
/**
 * A fax number. Inspired by the (TYPE=fax) parameter of the TEL 
 * property as defined in RFC 2426 sec 3.3.1. 
 */
class FaxNumber : public virtual NCO::PhoneNumber
{
public:
    FaxNumber(const QUrl& uri = QUrl())
      : SimpleResource(uri), NCO::ContactMedium(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#FaxNumber", QUrl::StrictMode)), NCO::PhoneNumber(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#FaxNumber", QUrl::StrictMode)) {
    }

    FaxNumber(const SimpleResource& res)
      : SimpleResource(res), NCO::ContactMedium(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#FaxNumber", QUrl::StrictMode)), NCO::PhoneNumber(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#FaxNumber", QUrl::StrictMode)) {
    }

    FaxNumber& operator=(const SimpleResource& res) {
        SimpleResource::operator=(res);
        addType(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#FaxNumber", QUrl::StrictMode));
        return *this;
    }

protected:
    FaxNumber(const QUrl& uri, const QUrl& type)      : SimpleResource(uri), NCO::ContactMedium(uri, type), NCO::PhoneNumber(uri, type) {
    }
    FaxNumber(const SimpleResource& res, const QUrl& type)
      : SimpleResource(res), NCO::ContactMedium(res, type), NCO::PhoneNumber(res, type) {
    }
};
}
}

#endif
