#ifndef _NCO_CELLPHONENUMBER_H_
#define _NCO_CELLPHONENUMBER_H_

#include <QtCore/QVariant>
#include <QtCore/QStringList>
#include <QtCore/QUrl>
#include <QtCore/QDate>
#include <QtCore/QTime>
#include <QtCore/QDateTime>

#include <nepomuk/simpleresource.h>

#include "nco/voicephonenumber.h"
#include "nco/messagingnumber.h"

namespace Nepomuk {
namespace NCO {
/**
 * A cellular phone number. Inspired by the (TYPE=cell) parameter 
 * of the TEL property as defined in RFC 2426 sec 3.3.1. Usually 
 * a cellular phone can accept voice calls as well as textual messages 
 * (SMS), therefore this class has two superclasses. 
 */
class CellPhoneNumber : public virtual NCO::VoicePhoneNumber, public virtual NCO::MessagingNumber
{
public:
    CellPhoneNumber(const QUrl& uri = QUrl())
      : SimpleResource(uri), NCO::ContactMedium(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#CellPhoneNumber", QUrl::StrictMode)), NCO::PhoneNumber(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#CellPhoneNumber", QUrl::StrictMode)), NCO::VoicePhoneNumber(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#CellPhoneNumber", QUrl::StrictMode)), NCO::MessagingNumber(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#CellPhoneNumber", QUrl::StrictMode)) {
    }

    CellPhoneNumber(const SimpleResource& res)
      : SimpleResource(res), NCO::ContactMedium(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#CellPhoneNumber", QUrl::StrictMode)), NCO::PhoneNumber(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#CellPhoneNumber", QUrl::StrictMode)), NCO::VoicePhoneNumber(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#CellPhoneNumber", QUrl::StrictMode)), NCO::MessagingNumber(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#CellPhoneNumber", QUrl::StrictMode)) {
    }

    CellPhoneNumber& operator=(const SimpleResource& res) {
        SimpleResource::operator=(res);
        addType(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#CellPhoneNumber", QUrl::StrictMode));
        return *this;
    }

protected:
    CellPhoneNumber(const QUrl& uri, const QUrl& type)      : SimpleResource(uri), NCO::ContactMedium(uri, type), NCO::PhoneNumber(uri, type), NCO::VoicePhoneNumber(uri, type), NCO::MessagingNumber(uri, type) {
    }
    CellPhoneNumber(const SimpleResource& res, const QUrl& type)
      : SimpleResource(res), NCO::ContactMedium(res, type), NCO::PhoneNumber(res, type), NCO::VoicePhoneNumber(res, type), NCO::MessagingNumber(res, type) {
    }
};
}
}

#endif
