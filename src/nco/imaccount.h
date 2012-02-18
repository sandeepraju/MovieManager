#ifndef _NCO_IMACCOUNT_H_
#define _NCO_IMACCOUNT_H_

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
 * An account in an Instant Messaging system. 
 */
class IMAccount : public virtual NCO::ContactMedium
{
public:
    IMAccount(const QUrl& uri = QUrl())
      : SimpleResource(uri), NCO::ContactMedium(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#IMAccount", QUrl::StrictMode)) {
    }

    IMAccount(const SimpleResource& res)
      : SimpleResource(res), NCO::ContactMedium(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#IMAccount", QUrl::StrictMode)) {
    }

    IMAccount& operator=(const SimpleResource& res) {
        SimpleResource::operator=(res);
        addType(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#IMAccount", QUrl::StrictMode));
        return *this;
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nco#requestedPresenceSubscriptionTo. 
     * Indicates that this IMAccount has requested a subscription 
     * to the presence information of the other IMAccount. 
     */
    QList<QUrl> requestedPresenceSubscriptionTos() const {
        QList<QUrl> value;
        foreach(const QVariant& v, property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#requestedPresenceSubscriptionTo", QUrl::StrictMode)))
            value << v.value<QUrl>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nco#requestedPresenceSubscriptionTo. 
     * Indicates that this IMAccount has requested a subscription 
     * to the presence information of the other IMAccount. 
     */
    void setRequestedPresenceSubscriptionTos(const QList<QUrl>& value) {
        QVariantList values;
        foreach(const QUrl& v, value)
            values << v;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#requestedPresenceSubscriptionTo", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nco#requestedPresenceSubscriptionTo. 
     * Indicates that this IMAccount has requested a subscription 
     * to the presence information of the other IMAccount. 
     */
    void addRequestedPresenceSubscriptionTo(const QUrl& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#requestedPresenceSubscriptionTo", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nco#imNickname. 
     * A nickname attached to a particular IM Account. 
     */
    QStringList imNicknames() const {
        QStringList value;
        foreach(const QVariant& v, property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#imNickname", QUrl::StrictMode)))
            value << v.value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nco#imNickname. 
     * A nickname attached to a particular IM Account. 
     */
    void setImNicknames(const QStringList& value) {
        QVariantList values;
        foreach(const QString& v, value)
            values << v;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#imNickname", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nco#imNickname. 
     * A nickname attached to a particular IM Account. 
     */
    void addImNickname(const QString& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#imNickname", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nco#isBlocked. 
     * Indicates that this IMAccount has been blocked. 
     */
    bool isBlocked() const {
        bool value;
        if(contains(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#isBlocked", QUrl::StrictMode)))
            value = property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#isBlocked", QUrl::StrictMode)).first().value<bool>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nco#isBlocked. 
     * Indicates that this IMAccount has been blocked. 
     */
    void setIsBlocked(const bool& value) {
        QVariantList values;
        values << value;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#isBlocked", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nco#isBlocked. 
     * Indicates that this IMAccount has been blocked. 
     */
    void addIsBlocked(const bool& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#isBlocked", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nco#imStatusMessage. 
     * A feature common in most IM systems. A message left by the user 
     * for all his/her contacts to see. 
     */
    QString imStatusMessage() const {
        QString value;
        if(contains(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#imStatusMessage", QUrl::StrictMode)))
            value = property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#imStatusMessage", QUrl::StrictMode)).first().value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nco#imStatusMessage. 
     * A feature common in most IM systems. A message left by the user 
     * for all his/her contacts to see. 
     */
    void setImStatusMessage(const QString& value) {
        QVariantList values;
        values << value;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#imStatusMessage", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nco#imStatusMessage. 
     * A feature common in most IM systems. A message left by the user 
     * for all his/her contacts to see. 
     */
    void addImStatusMessage(const QString& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#imStatusMessage", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nco#imAccountType. 
     * Type of the IM account. This may be the name of the service that 
     * provides the IM functionality. Examples might include Jabber, 
     * ICQ, MSN etc 
     */
    QString imAccountType() const {
        QString value;
        if(contains(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#imAccountType", QUrl::StrictMode)))
            value = property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#imAccountType", QUrl::StrictMode)).first().value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nco#imAccountType. 
     * Type of the IM account. This may be the name of the service that 
     * provides the IM functionality. Examples might include Jabber, 
     * ICQ, MSN etc 
     */
    void setImAccountType(const QString& value) {
        QVariantList values;
        values << value;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#imAccountType", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nco#imAccountType. 
     * Type of the IM account. This may be the name of the service that 
     * provides the IM functionality. Examples might include Jabber, 
     * ICQ, MSN etc 
     */
    void addImAccountType(const QString& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#imAccountType", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nco#isAccessedBy. 
     * Indicates the local IMAccount by which this IMAccount is accessed. 
     * This does not imply membership of a contact list. 
     */
    QList<QUrl> isAccessedBys() const {
        QList<QUrl> value;
        foreach(const QVariant& v, property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#isAccessedBy", QUrl::StrictMode)))
            value << v.value<QUrl>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nco#isAccessedBy. 
     * Indicates the local IMAccount by which this IMAccount is accessed. 
     * This does not imply membership of a contact list. 
     */
    void setIsAccessedBys(const QList<QUrl>& value) {
        QVariantList values;
        foreach(const QUrl& v, value)
            values << v;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#isAccessedBy", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nco#isAccessedBy. 
     * Indicates the local IMAccount by which this IMAccount is accessed. 
     * This does not imply membership of a contact list. 
     */
    void addIsAccessedBy(const QUrl& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#isAccessedBy", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nco#hasIMCapability. 
     * Indicates that an IMAccount has a certain capability. 
     */
    QList<QUrl> iMCapabilitys() const {
        QList<QUrl> value;
        foreach(const QVariant& v, property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#hasIMCapability", QUrl::StrictMode)))
            value << v.value<QUrl>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nco#hasIMCapability. 
     * Indicates that an IMAccount has a certain capability. 
     */
    void setIMCapabilitys(const QList<QUrl>& value) {
        QVariantList values;
        foreach(const QUrl& v, value)
            values << v;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#hasIMCapability", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nco#hasIMCapability. 
     * Indicates that an IMAccount has a certain capability. 
     */
    void addIMCapability(const QUrl& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#hasIMCapability", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nco#imStatus. 
     * Current status of the given IM account. When this property is 
     * set, the nco:imStatusType should also always be set. Applications 
     * should attempt to parse this property to determine the presence, 
     * only falling back to the nco:imStatusType property in the case 
     * that this property's value is unrecognised. Values for this 
     * property may include 'available', 'offline', 'busy' etc. 
     * The exact choice of them is unspecified, although it is recommended 
     * to follow the guidance of the Telepathy project when choosing 
     * a string identifier http://telepathy.freedesktop.org/spec/Connection_Interface_Simple_Presence.html#description 
     */
    QString imStatus() const {
        QString value;
        if(contains(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#imStatus", QUrl::StrictMode)))
            value = property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#imStatus", QUrl::StrictMode)).first().value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nco#imStatus. 
     * Current status of the given IM account. When this property is 
     * set, the nco:imStatusType should also always be set. Applications 
     * should attempt to parse this property to determine the presence, 
     * only falling back to the nco:imStatusType property in the case 
     * that this property's value is unrecognised. Values for this 
     * property may include 'available', 'offline', 'busy' etc. 
     * The exact choice of them is unspecified, although it is recommended 
     * to follow the guidance of the Telepathy project when choosing 
     * a string identifier http://telepathy.freedesktop.org/spec/Connection_Interface_Simple_Presence.html#description 
     */
    void setImStatus(const QString& value) {
        QVariantList values;
        values << value;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#imStatus", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nco#imStatus. 
     * Current status of the given IM account. When this property is 
     * set, the nco:imStatusType should also always be set. Applications 
     * should attempt to parse this property to determine the presence, 
     * only falling back to the nco:imStatusType property in the case 
     * that this property's value is unrecognised. Values for this 
     * property may include 'available', 'offline', 'busy' etc. 
     * The exact choice of them is unspecified, although it is recommended 
     * to follow the guidance of the Telepathy project when choosing 
     * a string identifier http://telepathy.freedesktop.org/spec/Connection_Interface_Simple_Presence.html#description 
     */
    void addImStatus(const QString& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#imStatus", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nco#publishesPresenceTo. 
     * Indicates that this IMAccount publishes its presence information 
     * to the other IMAccount. 
     */
    QList<QUrl> publishesPresenceTos() const {
        QList<QUrl> value;
        foreach(const QVariant& v, property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#publishesPresenceTo", QUrl::StrictMode)))
            value << v.value<QUrl>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nco#publishesPresenceTo. 
     * Indicates that this IMAccount publishes its presence information 
     * to the other IMAccount. 
     */
    void setPublishesPresenceTos(const QList<QUrl>& value) {
        QVariantList values;
        foreach(const QUrl& v, value)
            values << v;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#publishesPresenceTo", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nco#publishesPresenceTo. 
     * Indicates that this IMAccount publishes its presence information 
     * to the other IMAccount. 
     */
    void addPublishesPresenceTo(const QUrl& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#publishesPresenceTo", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nco#imStatusType. 
     * Current status type of the given IM account. When this property 
     * is set, the nco:imStatus property should also always be set. 
     * Applications should attempt to parse the nco:imStatus property 
     * to determine the presence, only falling back to this property 
     * in the case that the nco:imStatus property's value is unrecognised. 
     */
    QUrl imStatusType() const {
        QUrl value;
        if(contains(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#imStatusType", QUrl::StrictMode)))
            value = property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#imStatusType", QUrl::StrictMode)).first().value<QUrl>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nco#imStatusType. 
     * Current status type of the given IM account. When this property 
     * is set, the nco:imStatus property should also always be set. 
     * Applications should attempt to parse the nco:imStatus property 
     * to determine the presence, only falling back to this property 
     * in the case that the nco:imStatus property's value is unrecognised. 
     */
    void setImStatusType(const QUrl& value) {
        QVariantList values;
        values << value;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#imStatusType", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nco#imStatusType. 
     * Current status type of the given IM account. When this property 
     * is set, the nco:imStatus property should also always be set. 
     * Applications should attempt to parse the nco:imStatus property 
     * to determine the presence, only falling back to this property 
     * in the case that the nco:imStatus property's value is unrecognised. 
     */
    void addImStatusType(const QUrl& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#imStatusType", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nco#imID. 
     * Identifier of the IM account. Examples of such identifier might 
     * include ICQ UINs, Jabber IDs, Skype names etc. 
     */
    QStringList imIDs() const {
        QStringList value;
        foreach(const QVariant& v, property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#imID", QUrl::StrictMode)))
            value << v.value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nco#imID. 
     * Identifier of the IM account. Examples of such identifier might 
     * include ICQ UINs, Jabber IDs, Skype names etc. 
     */
    void setImIDs(const QStringList& value) {
        QVariantList values;
        foreach(const QString& v, value)
            values << v;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#imID", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nco#imID. 
     * Identifier of the IM account. Examples of such identifier might 
     * include ICQ UINs, Jabber IDs, Skype names etc. 
     */
    void addImID(const QString& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#imID", QUrl::StrictMode), value);
    }

protected:
    IMAccount(const QUrl& uri, const QUrl& type)      : SimpleResource(uri), NCO::ContactMedium(uri, type) {
    }
    IMAccount(const SimpleResource& res, const QUrl& type)
      : SimpleResource(res), NCO::ContactMedium(res, type) {
    }
};
}
}

#endif
