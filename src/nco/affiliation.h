#ifndef _NCO_AFFILIATION_H_
#define _NCO_AFFILIATION_H_

#include <QtCore/QVariant>
#include <QtCore/QStringList>
#include <QtCore/QUrl>
#include <QtCore/QDate>
#include <QtCore/QTime>
#include <QtCore/QDateTime>

#include <nepomuk/simpleresource.h>

#include "nco/role.h"

namespace Nepomuk {
namespace NCO {
/**
 * Aggregates three properties defined in RFC2426. Originally 
 * all three were attached directly to a person. One person could 
 * have only one title and one role within one organization. This 
 * class is intended to lift this limitation. 
 */
class Affiliation : public virtual NCO::Role
{
public:
    Affiliation(const QUrl& uri = QUrl())
      : SimpleResource(uri), NCO::Role(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#Affiliation", QUrl::StrictMode)) {
    }

    Affiliation(const SimpleResource& res)
      : SimpleResource(res), NCO::Role(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#Affiliation", QUrl::StrictMode)) {
    }

    Affiliation& operator=(const SimpleResource& res) {
        SimpleResource::operator=(res);
        addType(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#Affiliation", QUrl::StrictMode));
        return *this;
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nco#title. 
     * The official title the object represented by this contact in 
     * an organization. E.g. 'CEO', 'Director, Research and Development', 
     * 'Junior Software Developer/Analyst' etc. An equivalent of 
     * the 'TITLE' property defined in RFC 2426 Sec. 3.5.1 
     */
    QString title() const {
        QString value;
        if(contains(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#title", QUrl::StrictMode)))
            value = property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#title", QUrl::StrictMode)).first().value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nco#title. 
     * The official title the object represented by this contact in 
     * an organization. E.g. 'CEO', 'Director, Research and Development', 
     * 'Junior Software Developer/Analyst' etc. An equivalent of 
     * the 'TITLE' property defined in RFC 2426 Sec. 3.5.1 
     */
    void setTitle(const QString& value) {
        QVariantList values;
        values << value;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#title", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nco#title. 
     * The official title the object represented by this contact in 
     * an organization. E.g. 'CEO', 'Director, Research and Development', 
     * 'Junior Software Developer/Analyst' etc. An equivalent of 
     * the 'TITLE' property defined in RFC 2426 Sec. 3.5.1 
     */
    void addTitle(const QString& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#title", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nco#org. 
     * Name of an organization or a unit within an organization the 
     * object represented by a Contact is associated with. An equivalent 
     * of the 'ORG' property defined in RFC 2426 Sec. 3.5.5 
     */
    QUrl org() const {
        QUrl value;
        if(contains(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#org", QUrl::StrictMode)))
            value = property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#org", QUrl::StrictMode)).first().value<QUrl>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nco#org. 
     * Name of an organization or a unit within an organization the 
     * object represented by a Contact is associated with. An equivalent 
     * of the 'ORG' property defined in RFC 2426 Sec. 3.5.5 
     */
    void setOrg(const QUrl& value) {
        QVariantList values;
        values << value;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#org", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nco#org. 
     * Name of an organization or a unit within an organization the 
     * object represented by a Contact is associated with. An equivalent 
     * of the 'ORG' property defined in RFC 2426 Sec. 3.5.5 
     */
    void addOrg(const QUrl& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#org", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nco#department. 
     * Department. The organizational unit within the organization. 
     */
    QStringList departments() const {
        QStringList value;
        foreach(const QVariant& v, property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#department", QUrl::StrictMode)))
            value << v.value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nco#department. 
     * Department. The organizational unit within the organization. 
     */
    void setDepartments(const QStringList& value) {
        QVariantList values;
        foreach(const QString& v, value)
            values << v;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#department", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nco#department. 
     * Department. The organizational unit within the organization. 
     */
    void addDepartment(const QString& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#department", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nco#role. 
     * Role an object represented by this contact represents in the 
     * organization. This might include 'Programmer', 'Manager', 
     * 'Sales Representative'. Be careful to avoid confusion with 
     * the title property. An equivalent of the 'ROLE' property as 
     * defined in RFC 2426. Sec. 3.5.2. Note the difference between 
     * nco:Role class and nco:role property. 
     */
    QStringList roles() const {
        QStringList value;
        foreach(const QVariant& v, property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#role", QUrl::StrictMode)))
            value << v.value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nco#role. 
     * Role an object represented by this contact represents in the 
     * organization. This might include 'Programmer', 'Manager', 
     * 'Sales Representative'. Be careful to avoid confusion with 
     * the title property. An equivalent of the 'ROLE' property as 
     * defined in RFC 2426. Sec. 3.5.2. Note the difference between 
     * nco:Role class and nco:role property. 
     */
    void setRoles(const QStringList& value) {
        QVariantList values;
        foreach(const QString& v, value)
            values << v;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#role", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nco#role. 
     * Role an object represented by this contact represents in the 
     * organization. This might include 'Programmer', 'Manager', 
     * 'Sales Representative'. Be careful to avoid confusion with 
     * the title property. An equivalent of the 'ROLE' property as 
     * defined in RFC 2426. Sec. 3.5.2. Note the difference between 
     * nco:Role class and nco:role property. 
     */
    void addRole(const QString& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#role", QUrl::StrictMode), value);
    }

protected:
    Affiliation(const QUrl& uri, const QUrl& type)      : SimpleResource(uri), NCO::Role(uri, type) {
    }
    Affiliation(const SimpleResource& res, const QUrl& type)
      : SimpleResource(res), NCO::Role(res, type) {
    }
};
}
}

#endif
