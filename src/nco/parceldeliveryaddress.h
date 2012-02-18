#ifndef _NCO_PARCELDELIVERYADDRESS_H_
#define _NCO_PARCELDELIVERYADDRESS_H_

#include <QtCore/QVariant>
#include <QtCore/QStringList>
#include <QtCore/QUrl>
#include <QtCore/QDate>
#include <QtCore/QTime>
#include <QtCore/QDateTime>

#include <nepomuk/simpleresource.h>

#include "nco/postaladdress.h"

namespace Nepomuk {
namespace NCO {
/**
 * Parcel Delivery Addresse. Class inspired by TYPE=parcel parameter 
 * of the ADR property defined in RFC 2426 sec. 3.2.1 
 */
class ParcelDeliveryAddress : public virtual NCO::PostalAddress
{
public:
    ParcelDeliveryAddress(const QUrl& uri = QUrl())
      : SimpleResource(uri), NCO::ContactMedium(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#ParcelDeliveryAddress", QUrl::StrictMode)), NCO::PostalAddress(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#ParcelDeliveryAddress", QUrl::StrictMode)) {
    }

    ParcelDeliveryAddress(const SimpleResource& res)
      : SimpleResource(res), NCO::ContactMedium(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#ParcelDeliveryAddress", QUrl::StrictMode)), NCO::PostalAddress(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#ParcelDeliveryAddress", QUrl::StrictMode)) {
    }

    ParcelDeliveryAddress& operator=(const SimpleResource& res) {
        SimpleResource::operator=(res);
        addType(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#ParcelDeliveryAddress", QUrl::StrictMode));
        return *this;
    }

protected:
    ParcelDeliveryAddress(const QUrl& uri, const QUrl& type)      : SimpleResource(uri), NCO::ContactMedium(uri, type), NCO::PostalAddress(uri, type) {
    }
    ParcelDeliveryAddress(const SimpleResource& res, const QUrl& type)
      : SimpleResource(res), NCO::ContactMedium(res, type), NCO::PostalAddress(res, type) {
    }
};
}
}

#endif
