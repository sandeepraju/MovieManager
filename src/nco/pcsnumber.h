#ifndef _NCO_PCSNUMBER_H_
#define _NCO_PCSNUMBER_H_

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
 * Personal Communication Services Number. A class inspired 
 * by the TYPE=pcs parameter of the TEL property defined in RFC 
 * 2426 sec. 3.3.1 
 */
class PcsNumber : public virtual NCO::VoicePhoneNumber
{
public:
    PcsNumber(const QUrl& uri = QUrl())
      : SimpleResource(uri), NCO::ContactMedium(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#PcsNumber", QUrl::StrictMode)), NCO::PhoneNumber(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#PcsNumber", QUrl::StrictMode)), NCO::VoicePhoneNumber(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#PcsNumber", QUrl::StrictMode)) {
    }

    PcsNumber(const SimpleResource& res)
      : SimpleResource(res), NCO::ContactMedium(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#PcsNumber", QUrl::StrictMode)), NCO::PhoneNumber(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#PcsNumber", QUrl::StrictMode)), NCO::VoicePhoneNumber(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#PcsNumber", QUrl::StrictMode)) {
    }

    PcsNumber& operator=(const SimpleResource& res) {
        SimpleResource::operator=(res);
        addType(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#PcsNumber", QUrl::StrictMode));
        return *this;
    }

protected:
    PcsNumber(const QUrl& uri, const QUrl& type)      : SimpleResource(uri), NCO::ContactMedium(uri, type), NCO::PhoneNumber(uri, type), NCO::VoicePhoneNumber(uri, type) {
    }
    PcsNumber(const SimpleResource& res, const QUrl& type)
      : SimpleResource(res), NCO::ContactMedium(res, type), NCO::PhoneNumber(res, type), NCO::VoicePhoneNumber(res, type) {
    }
};
}
}

#endif
