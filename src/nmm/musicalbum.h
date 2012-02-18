#ifndef _NMM_MUSICALBUM_H_
#define _NMM_MUSICALBUM_H_

#include <QtCore/QVariant>
#include <QtCore/QStringList>
#include <QtCore/QUrl>
#include <QtCore/QDate>
#include <QtCore/QTime>
#include <QtCore/QDateTime>

#include <nepomuk/simpleresource.h>

#include "nfo/medialist.h"

namespace Nepomuk {
namespace NMM {
/**
 * The music album as provided by the publisher. Not to be confused 
 * with media lists or collections. 
 */
class MusicAlbum : public virtual NFO::MediaList
{
public:
    MusicAlbum(const QUrl& uri = QUrl())
      : SimpleResource(uri), NIE::InformationElement(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#MusicAlbum", QUrl::StrictMode)), NFO::MediaList(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#MusicAlbum", QUrl::StrictMode)) {
    }

    MusicAlbum(const SimpleResource& res)
      : SimpleResource(res), NIE::InformationElement(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#MusicAlbum", QUrl::StrictMode)), NFO::MediaList(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#MusicAlbum", QUrl::StrictMode)) {
    }

    MusicAlbum& operator=(const SimpleResource& res) {
        SimpleResource::operator=(res);
        addType(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#MusicAlbum", QUrl::StrictMode));
        return *this;
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#internationalStandardRecordingCode. 
     * ISRC ID. Format: 'CC-XXX-YY-NNNNN' 
     */
    QString internationalStandardRecordingCode() const {
        QString value;
        if(contains(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#internationalStandardRecordingCode", QUrl::StrictMode)))
            value = property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#internationalStandardRecordingCode", QUrl::StrictMode)).first().value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#internationalStandardRecordingCode. 
     * ISRC ID. Format: 'CC-XXX-YY-NNNNN' 
     */
    void setInternationalStandardRecordingCode(const QString& value) {
        QVariantList values;
        values << value;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#internationalStandardRecordingCode", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#internationalStandardRecordingCode. 
     * ISRC ID. Format: 'CC-XXX-YY-NNNNN' 
     */
    void addInternationalStandardRecordingCode(const QString& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#internationalStandardRecordingCode", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#musicBrainzAlbumID. 
     * MusicBrainz album ID 
     */
    QString musicBrainzAlbumID() const {
        QString value;
        if(contains(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#musicBrainzAlbumID", QUrl::StrictMode)))
            value = property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#musicBrainzAlbumID", QUrl::StrictMode)).first().value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#musicBrainzAlbumID. 
     * MusicBrainz album ID 
     */
    void setMusicBrainzAlbumID(const QString& value) {
        QVariantList values;
        values << value;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#musicBrainzAlbumID", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#musicBrainzAlbumID. 
     * MusicBrainz album ID 
     */
    void addMusicBrainzAlbumID(const QString& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#musicBrainzAlbumID", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#setSize. 
     * The number of parts in the set. 
     */
    qint64 setSize() const {
        qint64 value;
        if(contains(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#setSize", QUrl::StrictMode)))
            value = property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#setSize", QUrl::StrictMode)).first().value<qint64>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#setSize. 
     * The number of parts in the set. 
     */
    void setSetSize(const qint64& value) {
        QVariantList values;
        values << value;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#setSize", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#setSize. 
     * The number of parts in the set. 
     */
    void addSetSize(const qint64& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#setSize", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#albumTrackCount. 
     * The number of tracks in a music album. 
     */
    qint64 albumTrackCount() const {
        qint64 value;
        if(contains(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#albumTrackCount", QUrl::StrictMode)))
            value = property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#albumTrackCount", QUrl::StrictMode)).first().value<qint64>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#albumTrackCount. 
     * The number of tracks in a music album. 
     */
    void setAlbumTrackCount(const qint64& value) {
        QVariantList values;
        values << value;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#albumTrackCount", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#albumTrackCount. 
     * The number of tracks in a music album. 
     */
    void addAlbumTrackCount(const qint64& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#albumTrackCount", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#albumPeakGain. 
     * ReplayGain album(audiophile) peak gain 
     */
    double albumPeakGain() const {
        double value;
        if(contains(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#albumPeakGain", QUrl::StrictMode)))
            value = property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#albumPeakGain", QUrl::StrictMode)).first().value<double>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#albumPeakGain. 
     * ReplayGain album(audiophile) peak gain 
     */
    void setAlbumPeakGain(const double& value) {
        QVariantList values;
        values << value;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#albumPeakGain", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#albumPeakGain. 
     * ReplayGain album(audiophile) peak gain 
     */
    void addAlbumPeakGain(const double& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#albumPeakGain", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#musicCDIdentifier. 
     * Music CD identifier to for databases like FreeDB.org. This 
     * property is intended for music that comes from a CD, so that the 
     * CD can be identified in external databases. 
     */
    QStringList musicCDIdentifiers() const {
        QStringList value;
        foreach(const QVariant& v, property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#musicCDIdentifier", QUrl::StrictMode)))
            value << v.value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#musicCDIdentifier. 
     * Music CD identifier to for databases like FreeDB.org. This 
     * property is intended for music that comes from a CD, so that the 
     * CD can be identified in external databases. 
     */
    void setMusicCDIdentifiers(const QStringList& value) {
        QVariantList values;
        foreach(const QString& v, value)
            values << v;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#musicCDIdentifier", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#musicCDIdentifier. 
     * Music CD identifier to for databases like FreeDB.org. This 
     * property is intended for music that comes from a CD, so that the 
     * CD can be identified in external databases. 
     */
    void addMusicCDIdentifier(const QString& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#musicCDIdentifier", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#albumGain. 
     * ReplayGain album(audiophile) gain 
     */
    double albumGain() const {
        double value;
        if(contains(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#albumGain", QUrl::StrictMode)))
            value = property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#albumGain", QUrl::StrictMode)).first().value<double>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#albumGain. 
     * ReplayGain album(audiophile) gain 
     */
    void setAlbumGain(const double& value) {
        QVariantList values;
        values << value;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#albumGain", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#albumGain. 
     * ReplayGain album(audiophile) gain 
     */
    void addAlbumGain(const double& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#albumGain", QUrl::StrictMode), value);
    }

protected:
    MusicAlbum(const QUrl& uri, const QUrl& type)      : SimpleResource(uri), NIE::InformationElement(uri, type), NFO::MediaList(uri, type) {
    }
    MusicAlbum(const SimpleResource& res, const QUrl& type)
      : SimpleResource(res), NIE::InformationElement(res, type), NFO::MediaList(res, type) {
    }
};
}
}

#endif
