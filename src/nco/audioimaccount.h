#ifndef _NCO_AUDIOIMACCOUNT_H_
#define _NCO_AUDIOIMACCOUNT_H_

#include <QtCore/QVariant>
#include <QtCore/QStringList>
#include <QtCore/QUrl>
#include <QtCore/QDate>
#include <QtCore/QTime>
#include <QtCore/QDateTime>

#include <nepomuk/simpleresource.h>

#include "nco/imaccount.h"

namespace Nepomuk {
namespace NCO {
/**
 * Deprecated in favour of nco:imCapabilityAudio. 
 */
class AudioIMAccount : public virtual NCO::IMAccount
{
public:
    AudioIMAccount(const QUrl& uri = QUrl())
      : SimpleResource(uri), NCO::ContactMedium(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#AudioIMAccount", QUrl::StrictMode)), NCO::IMAccount(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#AudioIMAccount", QUrl::StrictMode)) {
    }

    AudioIMAccount(const SimpleResource& res)
      : SimpleResource(res), NCO::ContactMedium(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#AudioIMAccount", QUrl::StrictMode)), NCO::IMAccount(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#AudioIMAccount", QUrl::StrictMode)) {
    }

    AudioIMAccount& operator=(const SimpleResource& res) {
        SimpleResource::operator=(res);
        addType(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#AudioIMAccount", QUrl::StrictMode));
        return *this;
    }

protected:
    AudioIMAccount(const QUrl& uri, const QUrl& type)      : SimpleResource(uri), NCO::ContactMedium(uri, type), NCO::IMAccount(uri, type) {
    }
    AudioIMAccount(const SimpleResource& res, const QUrl& type)
      : SimpleResource(res), NCO::ContactMedium(res, type), NCO::IMAccount(res, type) {
    }
};
}
}

#endif
