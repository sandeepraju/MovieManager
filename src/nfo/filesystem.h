#ifndef _NFO_FILESYSTEM_H_
#define _NFO_FILESYSTEM_H_

#include <QtCore/QVariant>
#include <QtCore/QStringList>
#include <QtCore/QUrl>
#include <QtCore/QDate>
#include <QtCore/QTime>
#include <QtCore/QDateTime>

#include <nepomuk/simpleresource.h>

#include "nfo/datacontainer.h"

namespace Nepomuk {
namespace NFO {
/**
 * A filesystem. Examples of filesystems include hard disk partitions, 
 * removable media, but also images thereof stored in files such 
 * as ISO. 
 */
class Filesystem : public virtual NFO::DataContainer
{
public:
    Filesystem(const QUrl& uri = QUrl())
      : SimpleResource(uri), NIE::InformationElement(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Filesystem", QUrl::StrictMode)), NFO::DataContainer(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Filesystem", QUrl::StrictMode)) {
    }

    Filesystem(const SimpleResource& res)
      : SimpleResource(res), NIE::InformationElement(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Filesystem", QUrl::StrictMode)), NFO::DataContainer(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Filesystem", QUrl::StrictMode)) {
    }

    Filesystem& operator=(const SimpleResource& res) {
        SimpleResource::operator=(res);
        addType(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Filesystem", QUrl::StrictMode));
        return *this;
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#occupiedSpace. 
     * Occupied storage space of the filesystem. 
     */
    qint64 occupiedSpace() const {
        qint64 value;
        if(contains(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#occupiedSpace", QUrl::StrictMode)))
            value = property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#occupiedSpace", QUrl::StrictMode)).first().value<qint64>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#occupiedSpace. 
     * Occupied storage space of the filesystem. 
     */
    void setOccupiedSpace(const qint64& value) {
        QVariantList values;
        values << value;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#occupiedSpace", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#occupiedSpace. 
     * Occupied storage space of the filesystem. 
     */
    void addOccupiedSpace(const qint64& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#occupiedSpace", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#freeSpace. 
     * Unoccupied storage space of the filesystem. 
     */
    qint64 freeSpace() const {
        qint64 value;
        if(contains(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#freeSpace", QUrl::StrictMode)))
            value = property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#freeSpace", QUrl::StrictMode)).first().value<qint64>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#freeSpace. 
     * Unoccupied storage space of the filesystem. 
     */
    void setFreeSpace(const qint64& value) {
        QVariantList values;
        values << value;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#freeSpace", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#freeSpace. 
     * Unoccupied storage space of the filesystem. 
     */
    void addFreeSpace(const qint64& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#freeSpace", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#uuid. 
     * Universally unique identifier of the filesystem. In the future, 
     * this property may have its parent changed to a more generic class. 
     */
    QStringList uuids() const {
        QStringList value;
        foreach(const QVariant& v, property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#uuid", QUrl::StrictMode)))
            value << v.value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#uuid. 
     * Universally unique identifier of the filesystem. In the future, 
     * this property may have its parent changed to a more generic class. 
     */
    void setUuids(const QStringList& value) {
        QVariantList values;
        foreach(const QString& v, value)
            values << v;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#uuid", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#uuid. 
     * Universally unique identifier of the filesystem. In the future, 
     * this property may have its parent changed to a more generic class. 
     */
    void addUuid(const QString& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#uuid", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#filesystemType. 
     * Type of filesystem such as ext3 and ntfs. 
     */
    QString filesystemType() const {
        QString value;
        if(contains(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#filesystemType", QUrl::StrictMode)))
            value = property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#filesystemType", QUrl::StrictMode)).first().value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#filesystemType. 
     * Type of filesystem such as ext3 and ntfs. 
     */
    void setFilesystemType(const QString& value) {
        QVariantList values;
        values << value;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#filesystemType", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#filesystemType. 
     * Type of filesystem such as ext3 and ntfs. 
     */
    void addFilesystemType(const QString& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#filesystemType", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#totalSpace. 
     * Total storage space of the filesystem, which can be different 
     * from nie:contentSize because the latter includes filesystem 
     * format overhead. 
     */
    qint64 totalSpace() const {
        qint64 value;
        if(contains(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#totalSpace", QUrl::StrictMode)))
            value = property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#totalSpace", QUrl::StrictMode)).first().value<qint64>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#totalSpace. 
     * Total storage space of the filesystem, which can be different 
     * from nie:contentSize because the latter includes filesystem 
     * format overhead. 
     */
    void setTotalSpace(const qint64& value) {
        QVariantList values;
        values << value;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#totalSpace", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#totalSpace. 
     * Total storage space of the filesystem, which can be different 
     * from nie:contentSize because the latter includes filesystem 
     * format overhead. 
     */
    void addTotalSpace(const qint64& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#totalSpace", QUrl::StrictMode), value);
    }

protected:
    Filesystem(const QUrl& uri, const QUrl& type)      : SimpleResource(uri), NIE::InformationElement(uri, type), NFO::DataContainer(uri, type) {
    }
    Filesystem(const SimpleResource& res, const QUrl& type)
      : SimpleResource(res), NIE::InformationElement(res, type), NFO::DataContainer(res, type) {
    }
};
}
}

#endif
