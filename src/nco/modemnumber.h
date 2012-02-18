#ifndef _NCO_MODEMNUMBER_H_
#define _NCO_MODEMNUMBER_H_

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
 * A modem phone number. Inspired by the (TYPE=modem) parameter 
 * of the TEL property as defined in RFC 2426 sec 3.3.1. 
 */
class ModemNumber : public virtual NCO::PhoneNumber
{
public:
    ModemNumber(const QUrl& uri = QUrl())
      : SimpleResource(uri), NCO::ContactMedium(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#ModemNumber", QUrl::StrictMode)), NCO::PhoneNumber(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#ModemNumber", QUrl::StrictMode)) {
    }

    ModemNumber(const SimpleResource& res)
      : SimpleResource(res), NCO::ContactMedium(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#ModemNumber", QUrl::StrictMode)), NCO::PhoneNumber(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#ModemNumber", QUrl::StrictMode)) {
    }

    ModemNumber& operator=(const SimpleResource& res) {
        SimpleResource::operator=(res);
        addType(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#ModemNumber", QUrl::StrictMode));
        return *this;
    }

protected:
    ModemNumber(const QUrl& uri, const QUrl& type)      : SimpleResource(uri), NCO::ContactMedium(uri, type), NCO::PhoneNumber(uri, type) {
    }
    ModemNumber(const SimpleResource& res, const QUrl& type)
      : SimpleResource(res), NCO::ContactMedium(res, type), NCO::PhoneNumber(res, type) {
    }
};
}
}

#endif
