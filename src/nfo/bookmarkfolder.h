#ifndef _NFO_BOOKMARKFOLDER_H_
#define _NFO_BOOKMARKFOLDER_H_

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
 * A folder with bookmarks of a webbrowser. Use nfo:containsBookmark 
 * to relate Bookmarks. Folders can contain subfolders, use containsBookmarkFolder 
 * to relate them. 
 */
class BookmarkFolder : public virtual NIE::InformationElement
{
public:
    BookmarkFolder(const QUrl& uri = QUrl())
      : SimpleResource(uri), NIE::InformationElement(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#BookmarkFolder", QUrl::StrictMode)) {
    }

    BookmarkFolder(const SimpleResource& res)
      : SimpleResource(res), NIE::InformationElement(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#BookmarkFolder", QUrl::StrictMode)) {
    }

    BookmarkFolder& operator=(const SimpleResource& res) {
        SimpleResource::operator=(res);
        addType(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#BookmarkFolder", QUrl::StrictMode));
        return *this;
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#containsBookmark. 
     * The folder contains a bookmark. 
     */
    QList<QUrl> containsBookmarks() const {
        QList<QUrl> value;
        foreach(const QVariant& v, property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#containsBookmark", QUrl::StrictMode)))
            value << v.value<QUrl>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#containsBookmark. 
     * The folder contains a bookmark. 
     */
    void setContainsBookmarks(const QList<QUrl>& value) {
        QVariantList values;
        foreach(const QUrl& v, value)
            values << v;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#containsBookmark", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#containsBookmark. 
     * The folder contains a bookmark. 
     */
    void addContainsBookmark(const QUrl& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#containsBookmark", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#containsBookmarkFolder. 
     * The folder contains a bookmark folder. 
     */
    QList<QUrl> containsBookmarkFolders() const {
        QList<QUrl> value;
        foreach(const QVariant& v, property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#containsBookmarkFolder", QUrl::StrictMode)))
            value << v.value<QUrl>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#containsBookmarkFolder. 
     * The folder contains a bookmark folder. 
     */
    void setContainsBookmarkFolders(const QList<QUrl>& value) {
        QVariantList values;
        foreach(const QUrl& v, value)
            values << v;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#containsBookmarkFolder", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#containsBookmarkFolder. 
     * The folder contains a bookmark folder. 
     */
    void addContainsBookmarkFolder(const QUrl& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#containsBookmarkFolder", QUrl::StrictMode), value);
    }

protected:
    BookmarkFolder(const QUrl& uri, const QUrl& type)      : SimpleResource(uri), NIE::InformationElement(uri, type) {
    }
    BookmarkFolder(const SimpleResource& res, const QUrl& type)
      : SimpleResource(res), NIE::InformationElement(res, type) {
    }
};
}
}

#endif
