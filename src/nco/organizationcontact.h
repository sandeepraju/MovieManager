#ifndef _NCO_ORGANIZATIONCONTACT_H_
#define _NCO_ORGANIZATIONCONTACT_H_

#include <QtCore/QVariant>
#include <QtCore/QStringList>
#include <QtCore/QUrl>
#include <QtCore/QDate>
#include <QtCore/QTime>
#include <QtCore/QDateTime>

#include <nepomuk/simpleresource.h>

#include "nco/contact.h"

namespace Nepomuk {
namespace NCO {
/**
 * A Contact that denotes on Organization. 
 */
class OrganizationContact : public virtual NCO::Contact
{
public:
    OrganizationContact(const QUrl& uri = QUrl())
      : SimpleResource(uri), NIE::InformationElement(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#OrganizationContact", QUrl::StrictMode)), NCO::Role(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#OrganizationContact", QUrl::StrictMode)), NCO::Contact(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#OrganizationContact", QUrl::StrictMode)) {
    }

    OrganizationContact(const SimpleResource& res)
      : SimpleResource(res), NIE::InformationElement(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#OrganizationContact", QUrl::StrictMode)), NCO::Role(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#OrganizationContact", QUrl::StrictMode)), NCO::Contact(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#OrganizationContact", QUrl::StrictMode)) {
    }

    OrganizationContact& operator=(const SimpleResource& res) {
        SimpleResource::operator=(res);
        addType(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#OrganizationContact", QUrl::StrictMode));
        return *this;
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nco#logo. 
     * Logo of a company. Inspired by the LOGO property defined in RFC 
     * 2426 sec. 3.5.3 
     */
    QList<QUrl> logos() const {
        QList<QUrl> value;
        foreach(const QVariant& v, property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#logo", QUrl::StrictMode)))
            value << v.value<QUrl>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nco#logo. 
     * Logo of a company. Inspired by the LOGO property defined in RFC 
     * 2426 sec. 3.5.3 
     */
    void setLogos(const QList<QUrl>& value) {
        QVariantList values;
        foreach(const QUrl& v, value)
            values << v;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#logo", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nco#logo. 
     * Logo of a company. Inspired by the LOGO property defined in RFC 
     * 2426 sec. 3.5.3 
     */
    void addLogo(const QUrl& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#logo", QUrl::StrictMode), value);
    }

protected:
    OrganizationContact(const QUrl& uri, const QUrl& type)      : SimpleResource(uri), NIE::InformationElement(uri, type), NCO::Role(uri, type), NCO::Contact(uri, type) {
    }
    OrganizationContact(const SimpleResource& res, const QUrl& type)
      : SimpleResource(res), NIE::InformationElement(res, type), NCO::Role(res, type), NCO::Contact(res, type) {
    }
};
}
}

#endif
