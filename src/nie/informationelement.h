#ifndef _NIE_INFORMATIONELEMENT_H_
#define _NIE_INFORMATIONELEMENT_H_

#include <QtCore/QVariant>
#include <QtCore/QStringList>
#include <QtCore/QUrl>
#include <QtCore/QDate>
#include <QtCore/QTime>
#include <QtCore/QDateTime>

#include <nepomuk/simpleresource.h>

namespace Nepomuk {
namespace NIE {
/**
 * A unit of content the user works with. This is a superclass for 
 * all interpretations of a DataObject. 
 */
class InformationElement : public virtual Nepomuk::SimpleResource
{
public:
    InformationElement(const QUrl& uri = QUrl())
      : SimpleResource(uri) {
        addType(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
    }

    InformationElement(const SimpleResource& res)
      : SimpleResource(res) {
        addType(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
    }

    InformationElement& operator=(const SimpleResource& res) {
        SimpleResource::operator=(res);
        addType(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        return *this;
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#depends. 
     * Dependency relation. A piece of content depends on another 
     * piece of data in order to be properly understood/used/interpreted. 
     */
    QList<QUrl> dependses() const {
        QList<QUrl> value;
        foreach(const QVariant& v, property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#depends", QUrl::StrictMode)))
            value << v.value<QUrl>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#depends. 
     * Dependency relation. A piece of content depends on another 
     * piece of data in order to be properly understood/used/interpreted. 
     */
    void setDependses(const QList<QUrl>& value) {
        QVariantList values;
        foreach(const QUrl& v, value)
            values << v;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#depends", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#depends. 
     * Dependency relation. A piece of content depends on another 
     * piece of data in order to be properly understood/used/interpreted. 
     */
    void addDepends(const QUrl& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#depends", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#sideChannels. 
     * Number of side channels 
     */
    qint64 sideChannels() const {
        qint64 value;
        if(contains(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#sideChannels", QUrl::StrictMode)))
            value = property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#sideChannels", QUrl::StrictMode)).first().value<qint64>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#sideChannels. 
     * Number of side channels 
     */
    void setSideChannels(const qint64& value) {
        QVariantList values;
        values << value;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#sideChannels", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#sideChannels. 
     * Number of side channels 
     */
    void addSideChannels(const qint64& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#sideChannels", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nco#creator. 
     * Creator of an information element, an entity primarily responsible 
     * for the creation of the content of the data object. 
     */
    QList<QUrl> creators() const {
        QList<QUrl> value;
        foreach(const QVariant& v, property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#creator", QUrl::StrictMode)))
            value << v.value<QUrl>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nco#creator. 
     * Creator of an information element, an entity primarily responsible 
     * for the creation of the content of the data object. 
     */
    void setCreators(const QList<QUrl>& value) {
        QVariantList values;
        foreach(const QUrl& v, value)
            values << v;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#creator", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nco#creator. 
     * Creator of an information element, an entity primarily responsible 
     * for the creation of the content of the data object. 
     */
    void addCreator(const QUrl& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#creator", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#contentLastModified. 
     * The date of the last modification of the original content (not 
     * its corresponding DataObject or local copy). Compare with 
     * nie:lastModified. 
     */
    QDateTime contentLastModified() const {
        QDateTime value;
        if(contains(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#contentLastModified", QUrl::StrictMode)))
            value = property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#contentLastModified", QUrl::StrictMode)).first().value<QDateTime>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#contentLastModified. 
     * The date of the last modification of the original content (not 
     * its corresponding DataObject or local copy). Compare with 
     * nie:lastModified. 
     */
    void setContentLastModified(const QDateTime& value) {
        QVariantList values;
        values << value;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#contentLastModified", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#contentLastModified. 
     * The date of the last modification of the original content (not 
     * its corresponding DataObject or local copy). Compare with 
     * nie:lastModified. 
     */
    void addContentLastModified(const QDateTime& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#contentLastModified", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#disclaimer. 
     * A disclaimer 
     */
    QStringList disclaimers() const {
        QStringList value;
        foreach(const QVariant& v, property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#disclaimer", QUrl::StrictMode)))
            value << v.value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#disclaimer. 
     * A disclaimer 
     */
    void setDisclaimers(const QStringList& value) {
        QVariantList values;
        foreach(const QString& v, value)
            values << v;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#disclaimer", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#disclaimer. 
     * A disclaimer 
     */
    void addDisclaimer(const QString& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#disclaimer", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#htmlContent. 
     * The HTML content of an information element. This property can 
     * be used to store text including formatting in a generic fashion. 
     */
    QString htmlContent() const {
        QString value;
        if(contains(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#htmlContent", QUrl::StrictMode)))
            value = property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#htmlContent", QUrl::StrictMode)).first().value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#htmlContent. 
     * The HTML content of an information element. This property can 
     * be used to store text including formatting in a generic fashion. 
     */
    void setHtmlContent(const QString& value) {
        QVariantList values;
        values << value;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#htmlContent", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#htmlContent. 
     * The HTML content of an information element. This property can 
     * be used to store text including formatting in a generic fashion. 
     */
    void addHtmlContent(const QString& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#htmlContent", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#hasLogicalPart. 
     * Generic property used to express 'logical' containment relationships 
     * between InformationElements. NIE extensions are encouraged 
     * to provide more specific subproperties of this one. It is advisable 
     * for actual instances of InformationElement to use those specific 
     * subproperties. Note the difference between 'physical' containment 
     * (hasPart) and logical containment (hasLogicalPart) 
     */
    QList<QUrl> logicalParts() const {
        QList<QUrl> value;
        foreach(const QVariant& v, property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#hasLogicalPart", QUrl::StrictMode)))
            value << v.value<QUrl>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#hasLogicalPart. 
     * Generic property used to express 'logical' containment relationships 
     * between InformationElements. NIE extensions are encouraged 
     * to provide more specific subproperties of this one. It is advisable 
     * for actual instances of InformationElement to use those specific 
     * subproperties. Note the difference between 'physical' containment 
     * (hasPart) and logical containment (hasLogicalPart) 
     */
    void setLogicalParts(const QList<QUrl>& value) {
        QVariantList values;
        foreach(const QUrl& v, value)
            values << v;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#hasLogicalPart", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#hasLogicalPart. 
     * Generic property used to express 'logical' containment relationships 
     * between InformationElements. NIE extensions are encouraged 
     * to provide more specific subproperties of this one. It is advisable 
     * for actual instances of InformationElement to use those specific 
     * subproperties. Note the difference between 'physical' containment 
     * (hasPart) and logical containment (hasLogicalPart) 
     */
    void addLogicalPart(const QUrl& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#hasLogicalPart", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#rootElementOf. 
     * DataObjects extracted from a single data source are organized 
     * into a containment tree. This property links the root of that 
     * tree with the datasource it has been extracted from 
     */
    QList<QUrl> rootElementOfs() const {
        QList<QUrl> value;
        foreach(const QVariant& v, property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#rootElementOf", QUrl::StrictMode)))
            value << v.value<QUrl>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#rootElementOf. 
     * DataObjects extracted from a single data source are organized 
     * into a containment tree. This property links the root of that 
     * tree with the datasource it has been extracted from 
     */
    void setRootElementOfs(const QList<QUrl>& value) {
        QVariantList values;
        foreach(const QUrl& v, value)
            values << v;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#rootElementOf", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#rootElementOf. 
     * DataObjects extracted from a single data source are organized 
     * into a containment tree. This property links the root of that 
     * tree with the datasource it has been extracted from 
     */
    void addRootElementOf(const QUrl& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#rootElementOf", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#license. 
     * Terms and intellectual property rights licensing conditions. 
     */
    QStringList licenses() const {
        QStringList value;
        foreach(const QVariant& v, property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#license", QUrl::StrictMode)))
            value << v.value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#license. 
     * Terms and intellectual property rights licensing conditions. 
     */
    void setLicenses(const QStringList& value) {
        QVariantList values;
        foreach(const QString& v, value)
            values << v;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#license", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#license. 
     * Terms and intellectual property rights licensing conditions. 
     */
    void addLicense(const QString& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#license", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#frontChannels. 
     * Number of front channels. 
     */
    qint64 frontChannels() const {
        qint64 value;
        if(contains(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#frontChannels", QUrl::StrictMode)))
            value = property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#frontChannels", QUrl::StrictMode)).first().value<qint64>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#frontChannels. 
     * Number of front channels. 
     */
    void setFrontChannels(const qint64& value) {
        QVariantList values;
        values << value;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#frontChannels", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#frontChannels. 
     * Number of front channels. 
     */
    void addFrontChannels(const qint64& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#frontChannels", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#copyright. 
     * Content copyright 
     */
    QStringList copyrights() const {
        QStringList value;
        foreach(const QVariant& v, property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#copyright", QUrl::StrictMode)))
            value << v.value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#copyright. 
     * Content copyright 
     */
    void setCopyrights(const QStringList& value) {
        QVariantList values;
        foreach(const QString& v, value)
            values << v;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#copyright", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#copyright. 
     * Content copyright 
     */
    void addCopyright(const QString& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#copyright", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#rearChannels. 
     * Number of rear channels. 
     */
    qint64 rearChannels() const {
        qint64 value;
        if(contains(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#rearChannels", QUrl::StrictMode)))
            value = property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#rearChannels", QUrl::StrictMode)).first().value<qint64>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#rearChannels. 
     * Number of rear channels. 
     */
    void setRearChannels(const qint64& value) {
        QVariantList values;
        values << value;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#rearChannels", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#rearChannels. 
     * Number of rear channels. 
     */
    void addRearChannels(const qint64& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#rearChannels", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#comment. 
     * A user comment about an InformationElement. 
     */
    QStringList comments() const {
        QStringList value;
        foreach(const QVariant& v, property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#comment", QUrl::StrictMode)))
            value << v.value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#comment. 
     * A user comment about an InformationElement. 
     */
    void setComments(const QStringList& value) {
        QVariantList values;
        foreach(const QString& v, value)
            values << v;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#comment", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#comment. 
     * A user comment about an InformationElement. 
     */
    void addComment(const QString& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#comment", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#plainTextContent. 
     * Plain-text representation of the content of a InformationElement 
     * with all markup removed. The main purpose of this property is 
     * full-text indexing and search. Its exact content is considered 
     * application-specific. The user can make no assumptions about 
     * what is and what is not contained within. Applications should 
     * use more specific properties wherever possible. 
     */
    QString plainTextContent() const {
        QString value;
        if(contains(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#plainTextContent", QUrl::StrictMode)))
            value = property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#plainTextContent", QUrl::StrictMode)).first().value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#plainTextContent. 
     * Plain-text representation of the content of a InformationElement 
     * with all markup removed. The main purpose of this property is 
     * full-text indexing and search. Its exact content is considered 
     * application-specific. The user can make no assumptions about 
     * what is and what is not contained within. Applications should 
     * use more specific properties wherever possible. 
     */
    void setPlainTextContent(const QString& value) {
        QVariantList values;
        values << value;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#plainTextContent", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#plainTextContent. 
     * Plain-text representation of the content of a InformationElement 
     * with all markup removed. The main purpose of this property is 
     * full-text indexing and search. Its exact content is considered 
     * application-specific. The user can make no assumptions about 
     * what is and what is not contained within. Applications should 
     * use more specific properties wherever possible. 
     */
    void addPlainTextContent(const QString& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#plainTextContent", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#title. 
     * Name given to an InformationElement 
     */
    QString title() const {
        QString value;
        if(contains(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#title", QUrl::StrictMode)))
            value = property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#title", QUrl::StrictMode)).first().value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#title. 
     * Name given to an InformationElement 
     */
    void setTitle(const QString& value) {
        QVariantList values;
        values << value;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#title", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#title. 
     * Name given to an InformationElement 
     */
    void addTitle(const QString& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#title", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#version. 
     * The current version of the given data object. Exact semantics 
     * is unspecified at this level. Use more specific subproperties 
     * if needed. 
     */
    QStringList versions() const {
        QStringList value;
        foreach(const QVariant& v, property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#version", QUrl::StrictMode)))
            value << v.value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#version. 
     * The current version of the given data object. Exact semantics 
     * is unspecified at this level. Use more specific subproperties 
     * if needed. 
     */
    void setVersions(const QStringList& value) {
        QVariantList values;
        foreach(const QString& v, value)
            values << v;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#version", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#version. 
     * The current version of the given data object. Exact semantics 
     * is unspecified at this level. Use more specific subproperties 
     * if needed. 
     */
    void addVersion(const QString& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#version", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#lfeChannels. 
     * Number of Low Frequency Expansion (subwoofer) channels. 
     */
    qint64 lfeChannels() const {
        qint64 value;
        if(contains(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#lfeChannels", QUrl::StrictMode)))
            value = property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#lfeChannels", QUrl::StrictMode)).first().value<qint64>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#lfeChannels. 
     * Number of Low Frequency Expansion (subwoofer) channels. 
     */
    void setLfeChannels(const qint64& value) {
        QVariantList values;
        values << value;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#lfeChannels", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#lfeChannels. 
     * Number of Low Frequency Expansion (subwoofer) channels. 
     */
    void addLfeChannels(const qint64& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#lfeChannels", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#links. 
     * A linking relation. A piece of content links/mentions a piece 
     * of data 
     */
    QList<QUrl> linkses() const {
        QList<QUrl> value;
        foreach(const QVariant& v, property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#links", QUrl::StrictMode)))
            value << v.value<QUrl>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#links. 
     * A linking relation. A piece of content links/mentions a piece 
     * of data 
     */
    void setLinkses(const QList<QUrl>& value) {
        QVariantList values;
        foreach(const QUrl& v, value)
            values << v;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#links", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#links. 
     * A linking relation. A piece of content links/mentions a piece 
     * of data 
     */
    void addLinks(const QUrl& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#links", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nco#contributor. 
     * An entity responsible for making contributions to the content 
     * of the InformationElement. 
     */
    QList<QUrl> contributors() const {
        QList<QUrl> value;
        foreach(const QVariant& v, property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#contributor", QUrl::StrictMode)))
            value << v.value<QUrl>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nco#contributor. 
     * An entity responsible for making contributions to the content 
     * of the InformationElement. 
     */
    void setContributors(const QList<QUrl>& value) {
        QVariantList values;
        foreach(const QUrl& v, value)
            values << v;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#contributor", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nco#contributor. 
     * An entity responsible for making contributions to the content 
     * of the InformationElement. 
     */
    void addContributor(const QUrl& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#contributor", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#identifier. 
     * An unambiguous reference to the InformationElement within 
     * a given context. Recommended best practice is to identify the 
     * resource by means of a string conforming to a formal identification 
     * system. 
     */
    QStringList identifiers() const {
        QStringList value;
        foreach(const QVariant& v, property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#identifier", QUrl::StrictMode)))
            value << v.value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#identifier. 
     * An unambiguous reference to the InformationElement within 
     * a given context. Recommended best practice is to identify the 
     * resource by means of a string conforming to a formal identification 
     * system. 
     */
    void setIdentifiers(const QStringList& value) {
        QVariantList values;
        foreach(const QString& v, value)
            values << v;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#identifier", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#identifier. 
     * An unambiguous reference to the InformationElement within 
     * a given context. Recommended best practice is to identify the 
     * resource by means of a string conforming to a formal identification 
     * system. 
     */
    void addIdentifier(const QString& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#identifier", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#contentCreated. 
     * The date of the content creation. This may not necessarily be 
     * equal to the date when the DataObject (i.e. the physical representation) 
     * itself was created. Compare with nie:created property. 
     */
    QDateTime contentCreated() const {
        QDateTime value;
        if(contains(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#contentCreated", QUrl::StrictMode)))
            value = property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#contentCreated", QUrl::StrictMode)).first().value<QDateTime>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#contentCreated. 
     * The date of the content creation. This may not necessarily be 
     * equal to the date when the DataObject (i.e. the physical representation) 
     * itself was created. Compare with nie:created property. 
     */
    void setContentCreated(const QDateTime& value) {
        QVariantList values;
        values << value;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#contentCreated", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#contentCreated. 
     * The date of the content creation. This may not necessarily be 
     * equal to the date when the DataObject (i.e. the physical representation) 
     * itself was created. Compare with nie:created property. 
     */
    void addContentCreated(const QDateTime& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#contentCreated", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#legal. 
     * A common superproperty for all properties that point at legal 
     * information about an Information Element 
     */
    QStringList legals() const {
        QStringList value;
        foreach(const QVariant& v, property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#legal", QUrl::StrictMode)))
            value << v.value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#legal. 
     * A common superproperty for all properties that point at legal 
     * information about an Information Element 
     */
    void setLegals(const QStringList& value) {
        QVariantList values;
        foreach(const QString& v, value)
            values << v;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#legal", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#legal. 
     * A common superproperty for all properties that point at legal 
     * information about an Information Element 
     */
    void addLegal(const QString& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#legal", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#licenseType. 
     * The type of the license. Possible values for this field may include 
     * "GPL", "BSD", "Creative Commons" etc. 
     */
    QStringList licenseTypes() const {
        QStringList value;
        foreach(const QVariant& v, property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#licenseType", QUrl::StrictMode)))
            value << v.value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#licenseType. 
     * The type of the license. Possible values for this field may include 
     * "GPL", "BSD", "Creative Commons" etc. 
     */
    void setLicenseTypes(const QStringList& value) {
        QVariantList values;
        foreach(const QString& v, value)
            values << v;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#licenseType", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#licenseType. 
     * The type of the license. Possible values for this field may include 
     * "GPL", "BSD", "Creative Commons" etc. 
     */
    void addLicenseType(const QString& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#licenseType", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#isStoredAs. 
     * Links the information element with the DataObject it is stored 
     * in. 
     */
    QList<QUrl> isStoredAses() const {
        QList<QUrl> value;
        foreach(const QVariant& v, property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#isStoredAs", QUrl::StrictMode)))
            value << v.value<QUrl>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#isStoredAs. 
     * Links the information element with the DataObject it is stored 
     * in. 
     */
    void setIsStoredAses(const QList<QUrl>& value) {
        QVariantList values;
        foreach(const QUrl& v, value)
            values << v;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#isStoredAs", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#isStoredAs. 
     * Links the information element with the DataObject it is stored 
     * in. 
     */
    void addIsStoredAs(const QUrl& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#isStoredAs", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#language. 
     * Language the InformationElement is expressed in. This property 
     * applies to the data object in its entirety. If the data object 
     * is divisible into parts expressed in multiple languages - more 
     * specific properties should be used. Users are encouraged to 
     * use the two-letter code specified in the RFC 3066 
     */
    QString language() const {
        QString value;
        if(contains(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#language", QUrl::StrictMode)))
            value = property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#language", QUrl::StrictMode)).first().value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#language. 
     * Language the InformationElement is expressed in. This property 
     * applies to the data object in its entirety. If the data object 
     * is divisible into parts expressed in multiple languages - more 
     * specific properties should be used. Users are encouraged to 
     * use the two-letter code specified in the RFC 3066 
     */
    void setLanguage(const QString& value) {
        QVariantList values;
        values << value;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#language", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#language. 
     * Language the InformationElement is expressed in. This property 
     * applies to the data object in its entirety. If the data object 
     * is divisible into parts expressed in multiple languages - more 
     * specific properties should be used. Users are encouraged to 
     * use the two-letter code specified in the RFC 3066 
     */
    void addLanguage(const QString& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#language", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#mimeType. 
     * The mime type of the resource, if available. Example: "text/plain". 
     * See http://www.iana.org/assignments/media-types/. This 
     * property applies to data objects that can be described with 
     * one mime type. In cases where the object as a whole has one mime 
     * type, while it's parts have other mime types, or there is no mime 
     * type that can be applied to the object as a whole, but some parts 
     * of the content have mime types - use more specific properties. 
     */
    QString mimeType() const {
        QString value;
        if(contains(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#mimeType", QUrl::StrictMode)))
            value = property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#mimeType", QUrl::StrictMode)).first().value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#mimeType. 
     * The mime type of the resource, if available. Example: "text/plain". 
     * See http://www.iana.org/assignments/media-types/. This 
     * property applies to data objects that can be described with 
     * one mime type. In cases where the object as a whole has one mime 
     * type, while it's parts have other mime types, or there is no mime 
     * type that can be applied to the object as a whole, but some parts 
     * of the content have mime types - use more specific properties. 
     */
    void setMimeType(const QString& value) {
        QVariantList values;
        values << value;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#mimeType", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#mimeType. 
     * The mime type of the resource, if available. Example: "text/plain". 
     * See http://www.iana.org/assignments/media-types/. This 
     * property applies to data objects that can be described with 
     * one mime type. In cases where the object as a whole has one mime 
     * type, while it's parts have other mime types, or there is no mime 
     * type that can be applied to the object as a whole, but some parts 
     * of the content have mime types - use more specific properties. 
     */
    void addMimeType(const QString& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#mimeType", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#isLogicalPartOf. 
     * Generic property used to express 'logical' containment relationships 
     * between DataObjects. NIE extensions are encouraged to provide 
     * more specific subproperties of this one. It is advisable for 
     * actual instances of InformationElement to use those specific 
     * subproperties. Note the difference between 'physical' containment 
     * (isPartOf) and logical containment (isLogicalPartOf) 
     */
    QList<QUrl> isLogicalPartOfs() const {
        QList<QUrl> value;
        foreach(const QVariant& v, property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#isLogicalPartOf", QUrl::StrictMode)))
            value << v.value<QUrl>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#isLogicalPartOf. 
     * Generic property used to express 'logical' containment relationships 
     * between DataObjects. NIE extensions are encouraged to provide 
     * more specific subproperties of this one. It is advisable for 
     * actual instances of InformationElement to use those specific 
     * subproperties. Note the difference between 'physical' containment 
     * (isPartOf) and logical containment (isLogicalPartOf) 
     */
    void setIsLogicalPartOfs(const QList<QUrl>& value) {
        QVariantList values;
        foreach(const QUrl& v, value)
            values << v;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#isLogicalPartOf", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#isLogicalPartOf. 
     * Generic property used to express 'logical' containment relationships 
     * between DataObjects. NIE extensions are encouraged to provide 
     * more specific subproperties of this one. It is advisable for 
     * actual instances of InformationElement to use those specific 
     * subproperties. Note the difference between 'physical' containment 
     * (isPartOf) and logical containment (isLogicalPartOf) 
     */
    void addIsLogicalPartOf(const QUrl& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#isLogicalPartOf", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#contentSize. 
     * The size of the content. This property can be used whenever the 
     * size of the content of an InformationElement differs from the 
     * size of the DataObject. (e.g. because of compression, encoding, 
     * encryption or any other representation issues). The contentSize 
     * in expressed in bytes. 
     */
    qint64 contentSize() const {
        qint64 value;
        if(contains(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#contentSize", QUrl::StrictMode)))
            value = property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#contentSize", QUrl::StrictMode)).first().value<qint64>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#contentSize. 
     * The size of the content. This property can be used whenever the 
     * size of the content of an InformationElement differs from the 
     * size of the DataObject. (e.g. because of compression, encoding, 
     * encryption or any other representation issues). The contentSize 
     * in expressed in bytes. 
     */
    void setContentSize(const qint64& value) {
        QVariantList values;
        values << value;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#contentSize", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#contentSize. 
     * The size of the content. This property can be used whenever the 
     * size of the content of an InformationElement differs from the 
     * size of the DataObject. (e.g. because of compression, encoding, 
     * encryption or any other representation issues). The contentSize 
     * in expressed in bytes. 
     */
    void addContentSize(const qint64& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#contentSize", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#relatedTo. 
     * A common superproperty for all relations between a piece of 
     * content and other pieces of data (which may be interpreted as 
     * other pieces of content). 
     */
    QList<QUrl> relatedTos() const {
        QList<QUrl> value;
        foreach(const QVariant& v, property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#relatedTo", QUrl::StrictMode)))
            value << v.value<QUrl>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#relatedTo. 
     * A common superproperty for all relations between a piece of 
     * content and other pieces of data (which may be interpreted as 
     * other pieces of content). 
     */
    void setRelatedTos(const QList<QUrl>& value) {
        QVariantList values;
        foreach(const QUrl& v, value)
            values << v;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#relatedTo", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#relatedTo. 
     * A common superproperty for all relations between a piece of 
     * content and other pieces of data (which may be interpreted as 
     * other pieces of content). 
     */
    void addRelatedTo(const QUrl& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#relatedTo", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#description. 
     * A textual description of the resource. This property may be 
     * used for any metadata fields that provide some meta-information 
     * or comment about a resource in the form of a passage of text. This 
     * property is not to be confused with nie:plainTextContent. 
     * Use more specific subproperties wherever possible. 
     */
    QStringList descriptions() const {
        QStringList value;
        foreach(const QVariant& v, property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#description", QUrl::StrictMode)))
            value << v.value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#description. 
     * A textual description of the resource. This property may be 
     * used for any metadata fields that provide some meta-information 
     * or comment about a resource in the form of a passage of text. This 
     * property is not to be confused with nie:plainTextContent. 
     * Use more specific subproperties wherever possible. 
     */
    void setDescriptions(const QStringList& value) {
        QVariantList values;
        foreach(const QString& v, value)
            values << v;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#description", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#description. 
     * A textual description of the resource. This property may be 
     * used for any metadata fields that provide some meta-information 
     * or comment about a resource in the form of a passage of text. This 
     * property is not to be confused with nie:plainTextContent. 
     * Use more specific subproperties wherever possible. 
     */
    void addDescription(const QString& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#description", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#subject. 
     * An overall topic of the content of a InformationElement 
     */
    QStringList subjects() const {
        QStringList value;
        foreach(const QVariant& v, property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#subject", QUrl::StrictMode)))
            value << v.value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#subject. 
     * An overall topic of the content of a InformationElement 
     */
    void setSubjects(const QStringList& value) {
        QVariantList values;
        foreach(const QString& v, value)
            values << v;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#subject", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#subject. 
     * An overall topic of the content of a InformationElement 
     */
    void addSubject(const QString& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#subject", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#depiction. 
     * Relates an information element to an image which depicts said 
     * element. 
     */
    QList<QUrl> depictions() const {
        QList<QUrl> value;
        foreach(const QVariant& v, property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#depiction", QUrl::StrictMode)))
            value << v.value<QUrl>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#depiction. 
     * Relates an information element to an image which depicts said 
     * element. 
     */
    void setDepictions(const QList<QUrl>& value) {
        QVariantList values;
        foreach(const QUrl& v, value)
            values << v;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#depiction", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#depiction. 
     * Relates an information element to an image which depicts said 
     * element. 
     */
    void addDepiction(const QUrl& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#depiction", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#hasPart. 
     * Generic property used to express 'physical' containment relationships 
     * between DataObjects. NIE extensions are encouraged to provide 
     * more specific subproperties of this one. It is advisable for 
     * actual instances of DataObjects to use those specific subproperties. 
     * Note to the developers: Please be aware of the distinction between 
     * containment relation and provenance. The hasPart relation 
     * models physical containment, an InformationElement (a nmo:Message) 
     * can have a 'physical' part (an nfo:Attachment). Also, please 
     * note the difference between physical containment (hasPart) 
     * and logical containment (hasLogicalPart) the former has more 
     * strict meaning. They may occur independently of each other. 
     */
    QList<QUrl> parts() const {
        QList<QUrl> value;
        foreach(const QVariant& v, property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#hasPart", QUrl::StrictMode)))
            value << v.value<QUrl>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#hasPart. 
     * Generic property used to express 'physical' containment relationships 
     * between DataObjects. NIE extensions are encouraged to provide 
     * more specific subproperties of this one. It is advisable for 
     * actual instances of DataObjects to use those specific subproperties. 
     * Note to the developers: Please be aware of the distinction between 
     * containment relation and provenance. The hasPart relation 
     * models physical containment, an InformationElement (a nmo:Message) 
     * can have a 'physical' part (an nfo:Attachment). Also, please 
     * note the difference between physical containment (hasPart) 
     * and logical containment (hasLogicalPart) the former has more 
     * strict meaning. They may occur independently of each other. 
     */
    void setParts(const QList<QUrl>& value) {
        QVariantList values;
        foreach(const QUrl& v, value)
            values << v;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#hasPart", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#hasPart. 
     * Generic property used to express 'physical' containment relationships 
     * between DataObjects. NIE extensions are encouraged to provide 
     * more specific subproperties of this one. It is advisable for 
     * actual instances of DataObjects to use those specific subproperties. 
     * Note to the developers: Please be aware of the distinction between 
     * containment relation and provenance. The hasPart relation 
     * models physical containment, an InformationElement (a nmo:Message) 
     * can have a 'physical' part (an nfo:Attachment). Also, please 
     * note the difference between physical containment (hasPart) 
     * and logical containment (hasLogicalPart) the former has more 
     * strict meaning. They may occur independently of each other. 
     */
    void addPart(const QUrl& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#hasPart", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#encryptionStatus. 
     * The status of the encryption of the InformationElement. 
     */
    QUrl encryptionStatus() const {
        QUrl value;
        if(contains(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#encryptionStatus", QUrl::StrictMode)))
            value = property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#encryptionStatus", QUrl::StrictMode)).first().value<QUrl>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#encryptionStatus. 
     * The status of the encryption of the InformationElement. 
     */
    void setEncryptionStatus(const QUrl& value) {
        QVariantList values;
        values << value;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#encryptionStatus", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#encryptionStatus. 
     * The status of the encryption of the InformationElement. 
     */
    void addEncryptionStatus(const QUrl& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#encryptionStatus", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#contentModified. 
     * The date of a modification of the original content (not its corresponding 
     * DataObject or local copy). Compare with nie:modified. 
     */
    QList<QDateTime> contentModifieds() const {
        QList<QDateTime> value;
        foreach(const QVariant& v, property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#contentModified", QUrl::StrictMode)))
            value << v.value<QDateTime>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#contentModified. 
     * The date of a modification of the original content (not its corresponding 
     * DataObject or local copy). Compare with nie:modified. 
     */
    void setContentModifieds(const QList<QDateTime>& value) {
        QVariantList values;
        foreach(const QDateTime& v, value)
            values << v;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#contentModified", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#contentModified. 
     * The date of a modification of the original content (not its corresponding 
     * DataObject or local copy). Compare with nie:modified. 
     */
    void addContentModified(const QDateTime& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#contentModified", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nco#publisher. 
     * An entity responsible for making the InformationElement available. 
     */
    QList<QUrl> publishers() const {
        QList<QUrl> value;
        foreach(const QVariant& v, property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#publisher", QUrl::StrictMode)))
            value << v.value<QUrl>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nco#publisher. 
     * An entity responsible for making the InformationElement available. 
     */
    void setPublishers(const QList<QUrl>& value) {
        QVariantList values;
        foreach(const QUrl& v, value)
            values << v;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#publisher", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nco#publisher. 
     * An entity responsible for making the InformationElement available. 
     */
    void addPublisher(const QUrl& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nco#publisher", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#characterSet. 
     * Characterset in which the content of the InformationElement 
     * was created. Example: ISO-8859-1, UTF-8. One of the registered 
     * character sets at http://www.iana.org/assignments/character-sets. 
     * This characterSet is used to interpret any textual parts of 
     * the content. If more than one characterSet is used within one 
     * data object, use more specific properties. 
     */
    QString characterSet() const {
        QString value;
        if(contains(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#characterSet", QUrl::StrictMode)))
            value = property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#characterSet", QUrl::StrictMode)).first().value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#characterSet. 
     * Characterset in which the content of the InformationElement 
     * was created. Example: ISO-8859-1, UTF-8. One of the registered 
     * character sets at http://www.iana.org/assignments/character-sets. 
     * This characterSet is used to interpret any textual parts of 
     * the content. If more than one characterSet is used within one 
     * data object, use more specific properties. 
     */
    void setCharacterSet(const QString& value) {
        QVariantList values;
        values << value;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#characterSet", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#characterSet. 
     * Characterset in which the content of the InformationElement 
     * was created. Example: ISO-8859-1, UTF-8. One of the registered 
     * character sets at http://www.iana.org/assignments/character-sets. 
     * This characterSet is used to interpret any textual parts of 
     * the content. If more than one characterSet is used within one 
     * data object, use more specific properties. 
     */
    void addCharacterSet(const QString& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#characterSet", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#informationElementDate. 
     * A point or period of time associated with an event in the lifecycle 
     * of an Information Element. A common superproperty for all date-related 
     * properties of InformationElements in the NIE Framework. 
     */
    QList<QDateTime> informationElementDates() const {
        QList<QDateTime> value;
        foreach(const QVariant& v, property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#informationElementDate", QUrl::StrictMode)))
            value << v.value<QDateTime>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#informationElementDate. 
     * A point or period of time associated with an event in the lifecycle 
     * of an Information Element. A common superproperty for all date-related 
     * properties of InformationElements in the NIE Framework. 
     */
    void setInformationElementDates(const QList<QDateTime>& value) {
        QVariantList values;
        foreach(const QDateTime& v, value)
            values << v;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#informationElementDate", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#informationElementDate. 
     * A point or period of time associated with an event in the lifecycle 
     * of an Information Element. A common superproperty for all date-related 
     * properties of InformationElements in the NIE Framework. 
     */
    void addInformationElementDate(const QDateTime& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#informationElementDate", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#keyword. 
     * Adapted DublinCore: The topic of the content of the resource, 
     * as keyword. No sentences here. Recommended best practice is 
     * to select a value from a controlled vocabulary or formal classification 
     * scheme. 
     */
    QStringList keywords() const {
        QStringList value;
        foreach(const QVariant& v, property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#keyword", QUrl::StrictMode)))
            value << v.value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#keyword. 
     * Adapted DublinCore: The topic of the content of the resource, 
     * as keyword. No sentences here. Recommended best practice is 
     * to select a value from a controlled vocabulary or formal classification 
     * scheme. 
     */
    void setKeywords(const QStringList& value) {
        QVariantList values;
        foreach(const QString& v, value)
            values << v;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#keyword", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#keyword. 
     * Adapted DublinCore: The topic of the content of the resource, 
     * as keyword. No sentences here. Recommended best practice is 
     * to select a value from a controlled vocabulary or formal classification 
     * scheme. 
     */
    void addKeyword(const QString& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#keyword", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#generator. 
     * Software used to "generate" the contents. E.g. a word processor 
     * name. 
     */
    QStringList generators() const {
        QStringList value;
        foreach(const QVariant& v, property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#generator", QUrl::StrictMode)))
            value << v.value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#generator. 
     * Software used to "generate" the contents. E.g. a word processor 
     * name. 
     */
    void setGenerators(const QStringList& value) {
        QVariantList values;
        foreach(const QString& v, value)
            values << v;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#generator", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#generator. 
     * Software used to "generate" the contents. E.g. a word processor 
     * name. 
     */
    void addGenerator(const QString& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#generator", QUrl::StrictMode), value);
    }

protected:
    InformationElement(const QUrl& uri, const QUrl& type)      : SimpleResource(uri) {
        addType(type);
    }
    InformationElement(const SimpleResource& res, const QUrl& type)
      : SimpleResource(res) {
        addType(type);
    }
};
}
}

#endif
