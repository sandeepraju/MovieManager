#ifndef _NCO_PAGERNUMBER_H_
#define _NCO_PAGERNUMBER_H_

#include <QtCore/QVariant>
#include <QtCore/QStringList>
#include <QtCore/QUrl>
#include <QtCore/QDate>
#include <QtCore/QTime>
#include <QtCore/QDateTime>

#include <nepomuk/simpleresource.h>

#include "nco/messagingnumber.h"

namespace Nepomuk {
namespace NCO {
/**
 * A pager phone number. Inspired by the (TYPE=pager) parameter 
 * of the TEL property as defined in RFC 2426 sec 3.3.1. 
 */
class PagerNumber : public virtual NCO::MessagingNumber
{
public:
    PagerNumber(const QUrl& uri = QUrl())
      : SimpleResource(uri), NCO::ContactMedium(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#PagerNumber", QUrl::StrictMode)), NCO::PhoneNumber(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#PagerNumber", QUrl::StrictMode)), NCO::MessagingNumber(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#PagerNumber", QUrl::StrictMode)) {
    }

    PagerNumber(const SimpleResource& res)
      : SimpleResource(res), NCO::ContactMedium(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#PagerNumber", QUrl::StrictMode)), NCO::PhoneNumber(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#PagerNumber", QUrl::StrictMode)), NCO::MessagingNumber(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#PagerNumber", QUrl::StrictMode)) {
    }

    PagerNumber& operator=(const SimpleResource& res) {
        SimpleResource::operator=(res);
        addType(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#PagerNumber", QUrl::StrictMode));
        return *this;
    }

protected:
    PagerNumber(const QUrl& uri, const QUrl& type)      : SimpleResource(uri), NCO::ContactMedium(uri, type), NCO::PhoneNumber(uri, type), NCO::MessagingNumber(uri, type) {
    }
    PagerNumber(const SimpleResource& res, const QUrl& type)
      : SimpleResource(res), NCO::ContactMedium(res, type), NCO::PhoneNumber(res, type), NCO::MessagingNumber(res, type) {
    }
};
}
}

#endif
