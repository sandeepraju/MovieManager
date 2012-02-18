#ifndef _NCO_CONTACTGROUP_H_
#define _NCO_CONTACTGROUP_H_

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
 * A group of Contacts. Could be used to express a group in an addressbook 
 * or on a contact list of an IM application. One contact can belong 
 * to many groups. 
 */
class ContactGroup : public virtual NIE::InformationElement
{
public:
    ContactGroup(const QUrl& uri = QUrl())
      : SimpleResource(uri), NIE::InformationElement(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#ContactGroup", QUrl::StrictMode)) {
    }

    ContactGroup(const SimpleResource& res)
      : SimpleResource(res), NIE::InformationElement(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#ContactGroup", QUrl::StrictMode)) {
    }

    ContactGroup& operator=(const SimpleResource& res) {
        SimpleResource::operator=(res);
        addType(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#ContactGroup", QUrl::StrictMode));
        return *this;
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nco#contactGroupName. 
     * The name of the contact group. This property was NOT defined 
     * in the VCARD standard. See documentation of the 'ContactGroup' 
     * class for details 
     */
    QString contactGroupName() const {
        QString value;
        if(contains(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#contactGroupName", QUrl::StrictMode)))
            value = property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#contactGroupName", QUrl::StrictMode)).first().value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nco#contactGroupName. 
     * The name of the contact group. This property was NOT defined 
     * in the VCARD standard. See documentation of the 'ContactGroup' 
     * class for details 
     */
    void setContactGroupName(const QString& value) {
        QVariantList values;
        values << value;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#contactGroupName", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nco#contactGroupName. 
     * The name of the contact group. This property was NOT defined 
     * in the VCARD standard. See documentation of the 'ContactGroup' 
     * class for details 
     */
    void addContactGroupName(const QString& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#contactGroupName", QUrl::StrictMode), value);
    }

protected:
    ContactGroup(const QUrl& uri, const QUrl& type)      : SimpleResource(uri), NIE::InformationElement(uri, type) {
    }
    ContactGroup(const SimpleResource& res, const QUrl& type)
      : SimpleResource(res), NIE::InformationElement(res, type) {
    }
};
}
}

#endif
