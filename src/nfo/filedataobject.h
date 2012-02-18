#ifndef _NFO_FILEDATAOBJECT_H_
#define _NFO_FILEDATAOBJECT_H_

#include <QtCore/QVariant>
#include <QtCore/QStringList>
#include <QtCore/QUrl>
#include <QtCore/QDate>
#include <QtCore/QTime>
#include <QtCore/QDateTime>

#include <nepomuk/simpleresource.h>

#include "nie/dataobject.h"

namespace Nepomuk {
namespace NFO {
/**
 * A resource containing a finite sequence of bytes with arbitrary 
 * information, that is available to a computer program and is 
 * usually based on some kind of durable storage. A file is durable 
 * in the sense that it remains available for programs to use after 
 * the current program has finished. 
 */
class FileDataObject : public virtual NIE::DataObject
{
public:
    FileDataObject(const QUrl& uri = QUrl())
      : SimpleResource(uri), NIE::DataObject(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#FileDataObject", QUrl::StrictMode)) {
    }

    FileDataObject(const SimpleResource& res)
      : SimpleResource(res), NIE::DataObject(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#FileDataObject", QUrl::StrictMode)) {
    }

    FileDataObject& operator=(const SimpleResource& res) {
        SimpleResource::operator=(res);
        addType(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#FileDataObject", QUrl::StrictMode));
        return *this;
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileLastModified. 
     * last modification date 
     */
    QList<QDateTime> fileLastModifieds() const {
        QList<QDateTime> value;
        foreach(const QVariant& v, property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileLastModified", QUrl::StrictMode)))
            value << v.value<QDateTime>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileLastModified. 
     * last modification date 
     */
    void setFileLastModifieds(const QList<QDateTime>& value) {
        QVariantList values;
        foreach(const QDateTime& v, value)
            values << v;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileLastModified", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileLastModified. 
     * last modification date 
     */
    void addFileLastModified(const QDateTime& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileLastModified", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileName. 
     * Name of the file, together with the extension 
     */
    QString fileName() const {
        QString value;
        if(contains(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileName", QUrl::StrictMode)))
            value = property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileName", QUrl::StrictMode)).first().value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileName. 
     * Name of the file, together with the extension 
     */
    void setFileName(const QString& value) {
        QVariantList values;
        values << value;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileName", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileName. 
     * Name of the file, together with the extension 
     */
    void addFileName(const QString& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileName", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileCreated. 
     * File creation date 
     */
    QDateTime fileCreated() const {
        QDateTime value;
        if(contains(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileCreated", QUrl::StrictMode)))
            value = property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileCreated", QUrl::StrictMode)).first().value<QDateTime>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileCreated. 
     * File creation date 
     */
    void setFileCreated(const QDateTime& value) {
        QVariantList values;
        values << value;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileCreated", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileCreated. 
     * File creation date 
     */
    void addFileCreated(const QDateTime& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileCreated", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileUrl. 
     * URL of the file. It points at the location of the file. In cases 
     * where creating a simple file:// or http:// URL for a file is difficult 
     * (e.g. for files inside compressed archives) the applications 
     * are encouraged to use conventions defined by Apache Commons 
     * VFS Project at http://jakarta.apache.org/ commons/ vfs/ 
     * filesystems.html. 
     */
    QList<QUrl> fileUrls() const {
        QList<QUrl> value;
        foreach(const QVariant& v, property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileUrl", QUrl::StrictMode)))
            value << v.value<QUrl>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileUrl. 
     * URL of the file. It points at the location of the file. In cases 
     * where creating a simple file:// or http:// URL for a file is difficult 
     * (e.g. for files inside compressed archives) the applications 
     * are encouraged to use conventions defined by Apache Commons 
     * VFS Project at http://jakarta.apache.org/ commons/ vfs/ 
     * filesystems.html. 
     */
    void setFileUrls(const QList<QUrl>& value) {
        QVariantList values;
        foreach(const QUrl& v, value)
            values << v;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileUrl", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileUrl. 
     * URL of the file. It points at the location of the file. In cases 
     * where creating a simple file:// or http:// URL for a file is difficult 
     * (e.g. for files inside compressed archives) the applications 
     * are encouraged to use conventions defined by Apache Commons 
     * VFS Project at http://jakarta.apache.org/ commons/ vfs/ 
     * filesystems.html. 
     */
    void addFileUrl(const QUrl& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileUrl", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileSize. 
     * The size of the file in bytes. For compressed files it means the 
     * size of the packed file, not of the contents. For folders it means 
     * the aggregated size of all contained files and folders 
     */
    qint64 fileSize() const {
        qint64 value;
        if(contains(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileSize", QUrl::StrictMode)))
            value = property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileSize", QUrl::StrictMode)).first().value<qint64>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileSize. 
     * The size of the file in bytes. For compressed files it means the 
     * size of the packed file, not of the contents. For folders it means 
     * the aggregated size of all contained files and folders 
     */
    void setFileSize(const qint64& value) {
        QVariantList values;
        values << value;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileSize", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileSize. 
     * The size of the file in bytes. For compressed files it means the 
     * size of the packed file, not of the contents. For folders it means 
     * the aggregated size of all contained files and folders 
     */
    void addFileSize(const qint64& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileSize", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#permissions. 
     * A string containing the permissions of a file. A feature common 
     * in many UNIX-like operating systems. 
     */
    QString permissions() const {
        QString value;
        if(contains(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#permissions", QUrl::StrictMode)))
            value = property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#permissions", QUrl::StrictMode)).first().value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#permissions. 
     * A string containing the permissions of a file. A feature common 
     * in many UNIX-like operating systems. 
     */
    void setPermissions(const QString& value) {
        QVariantList values;
        values << value;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#permissions", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#permissions. 
     * A string containing the permissions of a file. A feature common 
     * in many UNIX-like operating systems. 
     */
    void addPermissions(const QString& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#permissions", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#hasHash. 
     * Links the file with it's hash value. 
     */
    QList<QUrl> hashs() const {
        QList<QUrl> value;
        foreach(const QVariant& v, property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#hasHash", QUrl::StrictMode)))
            value << v.value<QUrl>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#hasHash. 
     * Links the file with it's hash value. 
     */
    void setHashs(const QList<QUrl>& value) {
        QVariantList values;
        foreach(const QUrl& v, value)
            values << v;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#hasHash", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#hasHash. 
     * Links the file with it's hash value. 
     */
    void addHash(const QUrl& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#hasHash", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileLastAccessed. 
     * Time when the file was last accessed. 
     */
    QDateTime fileLastAccessed() const {
        QDateTime value;
        if(contains(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileLastAccessed", QUrl::StrictMode)))
            value = property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileLastAccessed", QUrl::StrictMode)).first().value<QDateTime>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileLastAccessed. 
     * Time when the file was last accessed. 
     */
    void setFileLastAccessed(const QDateTime& value) {
        QVariantList values;
        values << value;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileLastAccessed", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileLastAccessed. 
     * Time when the file was last accessed. 
     */
    void addFileLastAccessed(const QDateTime& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileLastAccessed", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileOwner. 
     * The owner of the file as defined by the file system access rights 
     * feature. 
     */
    QUrl fileOwner() const {
        QUrl value;
        if(contains(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileOwner", QUrl::StrictMode)))
            value = property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileOwner", QUrl::StrictMode)).first().value<QUrl>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileOwner. 
     * The owner of the file as defined by the file system access rights 
     * feature. 
     */
    void setFileOwner(const QUrl& value) {
        QVariantList values;
        values << value;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileOwner", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileOwner. 
     * The owner of the file as defined by the file system access rights 
     * feature. 
     */
    void addFileOwner(const QUrl& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileOwner", QUrl::StrictMode), value);
    }

protected:
    FileDataObject(const QUrl& uri, const QUrl& type)      : SimpleResource(uri), NIE::DataObject(uri, type) {
    }
    FileDataObject(const SimpleResource& res, const QUrl& type)
      : SimpleResource(res), NIE::DataObject(res, type) {
    }
};
}
}

#endif
