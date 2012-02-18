#ifndef _NCO_EMAILADDRESS_H_
#define _NCO_EMAILADDRESS_H_

#include <QtCore/QVariant>
#include <QtCore/QStringList>
#include <QtCore/QUrl>
#include <QtCore/QDate>
#include <QtCore/QTime>
#include <QtCore/QDateTime>

#include <nepomuk/simpleresource.h>

#include "nco/contactmedium.h"

namespace Nepomuk {
namespace NCO {
/**
 * An email address. The recommended best practice is to use mailto: 
 * uris for instances of this class. 
 */
class EmailAddress : public virtual NCO::ContactMedium
{
public:
    EmailAddress(const QUrl& uri = QUrl())
      : SimpleResource(uri), NCO::ContactMedium(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#EmailAddress", QUrl::StrictMode)) {
    }

    EmailAddress(const SimpleResource& res)
      : SimpleResource(res), NCO::ContactMedium(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#EmailAddress", QUrl::StrictMode)) {
    }

    EmailAddress& operator=(const SimpleResource& res) {
        SimpleResource::operator=(res);
        addType(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#EmailAddress", QUrl::StrictMode));
        return *this;
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nco#emailAddress. 
     */
    QString emailAddress() const {
        QString value;
        if(contains(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#emailAddress", QUrl::StrictMode)))
            value = property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#emailAddress", QUrl::StrictMode)).first().value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nco#emailAddress. 
     */
    void setEmailAddress(const QString& value) {
        QVariantList values;
        values << value;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#emailAddress", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nco#emailAddress. 
     */
    void addEmailAddress(const QString& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#emailAddress", QUrl::StrictMode), value);
    }

protected:
    EmailAddress(const QUrl& uri, const QUrl& type)      : SimpleResource(uri), NCO::ContactMedium(uri, type) {
    }
    EmailAddress(const SimpleResource& res, const QUrl& type)
      : SimpleResource(res), NCO::ContactMedium(res, type) {
    }
};
}
}

#endif
