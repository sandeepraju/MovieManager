#ifndef _NCO_CONTACTLIST_H_
#define _NCO_CONTACTLIST_H_

#include <QtCore/QVariant>
#include <QtCore/QStringList>
#include <QtCore/QUrl>
#include <QtCore/QDate>
#include <QtCore/QTime>
#include <QtCore/QDateTime>

#include <nepomuk/simpleresource.h>

#include "nie/informationelement.h"

namespace Nepomuk {
namespace NCO {
/**
 * A contact list, this class represents an addressbook or a contact 
 * list of an IM application. Contacts inside a contact list can 
 * belong to contact groups. 
 */
class ContactList : public virtual NIE::InformationElement
{
public:
    ContactList(const QUrl& uri = QUrl())
      : SimpleResource(uri), NIE::InformationElement(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#ContactList", QUrl::StrictMode)) {
    }

    ContactList(const SimpleResource& res)
      : SimpleResource(res), NIE::InformationElement(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#ContactList", QUrl::StrictMode)) {
    }

    ContactList& operator=(const SimpleResource& res) {
        SimpleResource::operator=(res);
        addType(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#ContactList", QUrl::StrictMode));
        return *this;
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nco#containsContact. 
     * A property used to group contacts into contact groups. This 
     * property was NOT defined in the VCARD standard. See documentation 
     * for the 'ContactList' class for details 
     */
    QList<QUrl> containsContacts() const {
        QList<QUrl> value;
        foreach(const QVariant& v, property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#containsContact", QUrl::StrictMode)))
            value << v.value<QUrl>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nco#containsContact. 
     * A property used to group contacts into contact groups. This 
     * property was NOT defined in the VCARD standard. See documentation 
     * for the 'ContactList' class for details 
     */
    void setContainsContacts(const QList<QUrl>& value) {
        QVariantList values;
        foreach(const QUrl& v, value)
            values << v;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#containsContact", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nco#containsContact. 
     * A property used to group contacts into contact groups. This 
     * property was NOT defined in the VCARD standard. See documentation 
     * for the 'ContactList' class for details 
     */
    void addContainsContact(const QUrl& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#containsContact", QUrl::StrictMode), value);
    }

protected:
    ContactList(const QUrl& uri, const QUrl& type)      : SimpleResource(uri), NIE::InformationElement(uri, type) {
    }
    ContactList(const SimpleResource& res, const QUrl& type)
      : SimpleResource(res), NIE::InformationElement(res, type) {
    }
};
}
}

#endif
