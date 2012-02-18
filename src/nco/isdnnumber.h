#ifndef _NCO_ISDNNUMBER_H_
#define _NCO_ISDNNUMBER_H_

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
 * An ISDN phone number. Inspired by the (TYPE=isdn) parameter 
 * of the TEL property as defined in RFC 2426 sec 3.3.1. 
 */
class IsdnNumber : public virtual NCO::VoicePhoneNumber
{
public:
    IsdnNumber(const QUrl& uri = QUrl())
      : SimpleResource(uri), NCO::ContactMedium(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#IsdnNumber", QUrl::StrictMode)), NCO::PhoneNumber(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#IsdnNumber", QUrl::StrictMode)), NCO::VoicePhoneNumber(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#IsdnNumber", QUrl::StrictMode)) {
    }

    IsdnNumber(const SimpleResource& res)
      : SimpleResource(res), NCO::ContactMedium(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#IsdnNumber", QUrl::StrictMode)), NCO::PhoneNumber(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#IsdnNumber", QUrl::StrictMode)), NCO::VoicePhoneNumber(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#IsdnNumber", QUrl::StrictMode)) {
    }

    IsdnNumber& operator=(const SimpleResource& res) {
        SimpleResource::operator=(res);
        addType(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#IsdnNumber", QUrl::StrictMode));
        return *this;
    }

protected:
    IsdnNumber(const QUrl& uri, const QUrl& type)      : SimpleResource(uri), NCO::ContactMedium(uri, type), NCO::PhoneNumber(uri, type), NCO::VoicePhoneNumber(uri, type) {
    }
    IsdnNumber(const SimpleResource& res, const QUrl& type)
      : SimpleResource(res), NCO::ContactMedium(res, type), NCO::PhoneNumber(res, type), NCO::VoicePhoneNumber(res, type) {
    }
};
}
}

#endif
