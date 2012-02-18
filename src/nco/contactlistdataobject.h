#ifndef _NCO_CONTACTLISTDATAOBJECT_H_
#define _NCO_CONTACTLISTDATAOBJECT_H_

#include <QtCore/QVariant>
#include <QtCore/QStringList>
#include <QtCore/QUrl>
#include <QtCore/QDate>
#include <QtCore/QTime>
#include <QtCore/QDateTime>

#include <nepomuk/simpleresource.h>

#include "nie/dataobject.h"

namespace Nepomuk {
namespace NCO {
/**
 * An entity occuring on a contact list (usually interpreted as 
 * an nco:Contact) 
 */
class ContactListDataObject : public virtual NIE::DataObject
{
public:
    ContactListDataObject(const QUrl& uri = QUrl())
      : SimpleResource(uri), NIE::DataObject(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#ContactListDataObject", QUrl::StrictMode)) {
    }

    ContactListDataObject(const SimpleResource& res)
      : SimpleResource(res), NIE::DataObject(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#ContactListDataObject", QUrl::StrictMode)) {
    }

    ContactListDataObject& operator=(const SimpleResource& res) {
        SimpleResource::operator=(res);
        addType(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#ContactListDataObject", QUrl::StrictMode));
        return *this;
    }

protected:
    ContactListDataObject(const QUrl& uri, const QUrl& type)      : SimpleResource(uri), NIE::DataObject(uri, type) {
    }
    ContactListDataObject(const SimpleResource& res, const QUrl& type)
      : SimpleResource(res), NIE::DataObject(res, type) {
    }
};
}
}

#endif
