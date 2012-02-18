#ifndef _NCO_VIDEOIMACCOUNT_H_
#define _NCO_VIDEOIMACCOUNT_H_

#include <QtCore/QVariant>
#include <QtCore/QStringList>
#include <QtCore/QUrl>
#include <QtCore/QDate>
#include <QtCore/QTime>
#include <QtCore/QDateTime>

#include <nepomuk/simpleresource.h>

#include "nco/audioimaccount.h"

namespace Nepomuk {
namespace NCO {
/**
 * Deprecated in favour of nco:imCapabilityVideo. 
 */
class VideoIMAccount : public virtual NCO::AudioIMAccount
{
public:
    VideoIMAccount(const QUrl& uri = QUrl())
      : SimpleResource(uri), NCO::ContactMedium(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#VideoIMAccount", QUrl::StrictMode)), NCO::IMAccount(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#VideoIMAccount", QUrl::StrictMode)), NCO::AudioIMAccount(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#VideoIMAccount", QUrl::StrictMode)) {
    }

    VideoIMAccount(const SimpleResource& res)
      : SimpleResource(res), NCO::ContactMedium(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#VideoIMAccount", QUrl::StrictMode)), NCO::IMAccount(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#VideoIMAccount", QUrl::StrictMode)), NCO::AudioIMAccount(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#VideoIMAccount", QUrl::StrictMode)) {
    }

    VideoIMAccount& operator=(const SimpleResource& res) {
        SimpleResource::operator=(res);
        addType(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#VideoIMAccount", QUrl::StrictMode));
        return *this;
    }

protected:
    VideoIMAccount(const QUrl& uri, const QUrl& type)      : SimpleResource(uri), NCO::ContactMedium(uri, type), NCO::IMAccount(uri, type), NCO::AudioIMAccount(uri, type) {
    }
    VideoIMAccount(const SimpleResource& res, const QUrl& type)
      : SimpleResource(res), NCO::ContactMedium(res, type), NCO::IMAccount(res, type), NCO::AudioIMAccount(res, type) {
    }
};
}
}

#endif
