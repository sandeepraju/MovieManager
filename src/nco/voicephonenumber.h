#ifndef _NCO_VOICEPHONENUMBER_H_
#define _NCO_VOICEPHONENUMBER_H_

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
 * A telephone number with voice communication capabilities. 
 * Class inspired by the TYPE=voice parameter of the TEL property 
 * defined in RFC 2426 sec. 3.3.1 
 */
class VoicePhoneNumber : public virtual NCO::PhoneNumber
{
public:
    VoicePhoneNumber(const QUrl& uri = QUrl())
      : SimpleResource(uri), NCO::ContactMedium(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#VoicePhoneNumber", QUrl::StrictMode)), NCO::PhoneNumber(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#VoicePhoneNumber", QUrl::StrictMode)) {
    }

    VoicePhoneNumber(const SimpleResource& res)
      : SimpleResource(res), NCO::ContactMedium(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#VoicePhoneNumber", QUrl::StrictMode)), NCO::PhoneNumber(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#VoicePhoneNumber", QUrl::StrictMode)) {
    }

    VoicePhoneNumber& operator=(const SimpleResource& res) {
        SimpleResource::operator=(res);
        addType(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#VoicePhoneNumber", QUrl::StrictMode));
        return *this;
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nco#voiceMail. 
     * Indicates if the given number accepts voice mail. (e.g. there 
     * is an answering machine). Inspired by TYPE=msg parameter of 
     * the TEL property defined in RFC 2426 sec. 3.3.1 
     */
    bool voiceMail() const {
        bool value;
        if(contains(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#voiceMail", QUrl::StrictMode)))
            value = property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#voiceMail", QUrl::StrictMode)).first().value<bool>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nco#voiceMail. 
     * Indicates if the given number accepts voice mail. (e.g. there 
     * is an answering machine). Inspired by TYPE=msg parameter of 
     * the TEL property defined in RFC 2426 sec. 3.3.1 
     */
    void setVoiceMail(const bool& value) {
        QVariantList values;
        values << value;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#voiceMail", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nco#voiceMail. 
     * Indicates if the given number accepts voice mail. (e.g. there 
     * is an answering machine). Inspired by TYPE=msg parameter of 
     * the TEL property defined in RFC 2426 sec. 3.3.1 
     */
    void addVoiceMail(const bool& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#voiceMail", QUrl::StrictMode), value);
    }

protected:
    VoicePhoneNumber(const QUrl& uri, const QUrl& type)      : SimpleResource(uri), NCO::ContactMedium(uri, type), NCO::PhoneNumber(uri, type) {
    }
    VoicePhoneNumber(const SimpleResource& res, const QUrl& type)
      : SimpleResource(res), NCO::ContactMedium(res, type), NCO::PhoneNumber(res, type) {
    }
};
}
}

#endif
