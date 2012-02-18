#ifndef _NCO_CARPHONENUMBER_H_
#define _NCO_CARPHONENUMBER_H_

#include <QtCore/QVariant>
#include <QtCore/QStringList>
#include <QtCore/QUrl>
#include <QtCore/QDate>
#include <QtCore/QTime>
#include <QtCore/QDateTime>

#include <nepomuk/simpleresource.h>

#include "nco/voicephonenumber.h"

namespace Nepomuk {
namespace NCO {
/**
 * A car phone number. Inspired by the (TYPE=car) parameter of 
 * the TEL property as defined in RFC 2426 sec 3.3.1. 
 */
class CarPhoneNumber : public virtual NCO::VoicePhoneNumber
{
public:
    CarPhoneNumber(const QUrl& uri = QUrl())
      : SimpleResource(uri), NCO::ContactMedium(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#CarPhoneNumber", QUrl::StrictMode)), NCO::PhoneNumber(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#CarPhoneNumber", QUrl::StrictMode)), NCO::VoicePhoneNumber(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#CarPhoneNumber", QUrl::StrictMode)) {
    }

    CarPhoneNumber(const SimpleResource& res)
      : SimpleResource(res), NCO::ContactMedium(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#CarPhoneNumber", QUrl::StrictMode)), NCO::PhoneNumber(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#CarPhoneNumber", QUrl::StrictMode)), NCO::VoicePhoneNumber(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#CarPhoneNumber", QUrl::StrictMode)) {
    }

    CarPhoneNumber& operator=(const SimpleResource& res) {
        SimpleResource::operator=(res);
        addType(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#CarPhoneNumber", QUrl::StrictMode));
        return *this;
    }

protected:
    CarPhoneNumber(const QUrl& uri, const QUrl& type)      : SimpleResource(uri), NCO::ContactMedium(uri, type), NCO::PhoneNumber(uri, type), NCO::VoicePhoneNumber(uri, type) {
    }
    CarPhoneNumber(const SimpleResource& res, const QUrl& type)
      : SimpleResource(res), NCO::ContactMedium(res, type), NCO::PhoneNumber(res, type), NCO::VoicePhoneNumber(res, type) {
    }
};
}
}

#endif
