#ifndef _NFO_SOFTWARE_H_
#define _NFO_SOFTWARE_H_

#include <QtCore/QVariant>
#include <QtCore/QStringList>
#include <QtCore/QUrl>
#include <QtCore/QDate>
#include <QtCore/QTime>
#include <QtCore/QDateTime>

#include <nepomuk/simpleresource.h>

#include "nie/informationelement.h"

namespace Nepomuk {
namespace NFO {
/**
 * A piece of software. Examples may include applications and 
 * the operating system. This interpretation most commonly applies 
 * to SoftwareItems. 
 */
class Software : public virtual NIE::InformationElement
{
public:
    Software(const QUrl& uri = QUrl())
      : SimpleResource(uri), NIE::InformationElement(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Software", QUrl::StrictMode)) {
    }

    Software(const SimpleResource& res)
      : SimpleResource(res), NIE::InformationElement(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Software", QUrl::StrictMode)) {
    }

    Software& operator=(const SimpleResource& res) {
        SimpleResource::operator=(res);
        addType(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Software", QUrl::StrictMode));
        return *this;
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#conflicts. 
     * States that a piece of software is in conflict with another piece 
     * of software. 
     */
    QList<QUrl> conflictses() const {
        QList<QUrl> value;
        foreach(const QVariant& v, property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#conflicts", QUrl::StrictMode)))
            value << v.value<QUrl>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#conflicts. 
     * States that a piece of software is in conflict with another piece 
     * of software. 
     */
    void setConflictses(const QList<QUrl>& value) {
        QVariantList values;
        foreach(const QUrl& v, value)
            values << v;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#conflicts", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#conflicts. 
     * States that a piece of software is in conflict with another piece 
     * of software. 
     */
    void addConflicts(const QUrl& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#conflicts", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#supercedes. 
     * States that a piece of software supercedes another piece of 
     * software. 
     */
    QList<QUrl> supercedeses() const {
        QList<QUrl> value;
        foreach(const QVariant& v, property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#supercedes", QUrl::StrictMode)))
            value << v.value<QUrl>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#supercedes. 
     * States that a piece of software supercedes another piece of 
     * software. 
     */
    void setSupercedeses(const QList<QUrl>& value) {
        QVariantList values;
        foreach(const QUrl& v, value)
            values << v;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#supercedes", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#supercedes. 
     * States that a piece of software supercedes another piece of 
     * software. 
     */
    void addSupercedes(const QUrl& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#supercedes", QUrl::StrictMode), value);
    }

protected:
    Software(const QUrl& uri, const QUrl& type)      : SimpleResource(uri), NIE::InformationElement(uri, type) {
    }
    Software(const SimpleResource& res, const QUrl& type)
      : SimpleResource(res), NIE::InformationElement(res, type) {
    }
};
}
}

#endif
