#ifndef _NMM_MUSICPIECE_H_
#define _NMM_MUSICPIECE_H_

#include <QtCore/QVariant>
#include <QtCore/QStringList>
#include <QtCore/QUrl>
#include <QtCore/QDate>
#include <QtCore/QTime>
#include <QtCore/QDateTime>

#include <nepomuk/simpleresource.h>

#include "nfo/audio.h"

namespace Nepomuk {
namespace NMM {
/**
 * Used to assign music-specific properties such a BPM to video 
 * and audio 
 */
class MusicPiece : public virtual NFO::Audio
{
public:
    MusicPiece(const QUrl& uri = QUrl())
      : SimpleResource(uri), NIE::InformationElement(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#MusicPiece", QUrl::StrictMode)), NFO::Media(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#MusicPiece", QUrl::StrictMode)), NFO::Audio(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#MusicPiece", QUrl::StrictMode)) {
    }

    MusicPiece(const SimpleResource& res)
      : SimpleResource(res), NIE::InformationElement(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#MusicPiece", QUrl::StrictMode)), NFO::Media(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#MusicPiece", QUrl::StrictMode)), NFO::Audio(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#MusicPiece", QUrl::StrictMode)) {
    }

    MusicPiece& operator=(const SimpleResource& res) {
        SimpleResource::operator=(res);
        addType(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#MusicPiece", QUrl::StrictMode));
        return *this;
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#musicBrainzTrackID. 
     * MusicBrainz track ID 
     */
    qint64 musicBrainzTrackID() const {
        qint64 value;
        if(contains(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#musicBrainzTrackID", QUrl::StrictMode)))
            value = property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#musicBrainzTrackID", QUrl::StrictMode)).first().value<qint64>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#musicBrainzTrackID. 
     * MusicBrainz track ID 
     */
    void setMusicBrainzTrackID(const qint64& value) {
        QVariantList values;
        values << value;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#musicBrainzTrackID", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#musicBrainzTrackID. 
     * MusicBrainz track ID 
     */
    void addMusicBrainzTrackID(const qint64& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#musicBrainzTrackID", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#setNumber. 
     * The part of a set the audio came from. 
     */
    qint64 setNumber() const {
        qint64 value;
        if(contains(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#setNumber", QUrl::StrictMode)))
            value = property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#setNumber", QUrl::StrictMode)).first().value<qint64>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#setNumber. 
     * The part of a set the audio came from. 
     */
    void setSetNumber(const qint64& value) {
        QVariantList values;
        values << value;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#setNumber", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#setNumber. 
     * The part of a set the audio came from. 
     */
    void addSetNumber(const qint64& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#setNumber", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#lyricist. 
     * Lyricist 
     */
    QList<QUrl> lyricists() const {
        QList<QUrl> value;
        foreach(const QVariant& v, property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#lyricist", QUrl::StrictMode)))
            value << v.value<QUrl>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#lyricist. 
     * Lyricist 
     */
    void setLyricists(const QList<QUrl>& value) {
        QVariantList values;
        foreach(const QUrl& v, value)
            values << v;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#lyricist", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#lyricist. 
     * Lyricist 
     */
    void addLyricist(const QUrl& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#lyricist", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#trackNumber. 
     * Track number of the music in its album 
     */
    qint64 trackNumber() const {
        qint64 value;
        if(contains(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#trackNumber", QUrl::StrictMode)))
            value = property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#trackNumber", QUrl::StrictMode)).first().value<qint64>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#trackNumber. 
     * Track number of the music in its album 
     */
    void setTrackNumber(const qint64& value) {
        QVariantList values;
        values << value;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#trackNumber", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#trackNumber. 
     * Track number of the music in its album 
     */
    void addTrackNumber(const qint64& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#trackNumber", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#musicAlbum. 
     * Album the music belongs to 
     */
    QUrl musicAlbum() const {
        QUrl value;
        if(contains(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#musicAlbum", QUrl::StrictMode)))
            value = property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#musicAlbum", QUrl::StrictMode)).first().value<QUrl>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#musicAlbum. 
     * Album the music belongs to 
     */
    void setMusicAlbum(const QUrl& value) {
        QVariantList values;
        values << value;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#musicAlbum", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#musicAlbum. 
     * Album the music belongs to 
     */
    void addMusicAlbum(const QUrl& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#musicAlbum", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#trackPeakGain. 
     * ReplayGain track peak gain 
     */
    double trackPeakGain() const {
        double value;
        if(contains(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#trackPeakGain", QUrl::StrictMode)))
            value = property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#trackPeakGain", QUrl::StrictMode)).first().value<double>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#trackPeakGain. 
     * ReplayGain track peak gain 
     */
    void setTrackPeakGain(const double& value) {
        QVariantList values;
        values << value;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#trackPeakGain", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#trackPeakGain. 
     * ReplayGain track peak gain 
     */
    void addTrackPeakGain(const double& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#trackPeakGain", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#beatsPerMinute. 
     * beats per minute 
     */
    QList<qint64> beatsPerMinutes() const {
        QList<qint64> value;
        foreach(const QVariant& v, property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#beatsPerMinute", QUrl::StrictMode)))
            value << v.value<qint64>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#beatsPerMinute. 
     * beats per minute 
     */
    void setBeatsPerMinutes(const QList<qint64>& value) {
        QVariantList values;
        foreach(const qint64& v, value)
            values << v;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#beatsPerMinute", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#beatsPerMinute. 
     * beats per minute 
     */
    void addBeatsPerMinute(const qint64& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#beatsPerMinute", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#composer. 
     * Composer 
     */
    QList<QUrl> composers() const {
        QList<QUrl> value;
        foreach(const QVariant& v, property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#composer", QUrl::StrictMode)))
            value << v.value<QUrl>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#composer. 
     * Composer 
     */
    void setComposers(const QList<QUrl>& value) {
        QVariantList values;
        foreach(const QUrl& v, value)
            values << v;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#composer", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#composer. 
     * Composer 
     */
    void addComposer(const QUrl& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#composer", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#trackGain. 
     * ReplayGain track gain 
     */
    double trackGain() const {
        double value;
        if(contains(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#trackGain", QUrl::StrictMode)))
            value = property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#trackGain", QUrl::StrictMode)).first().value<double>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#trackGain. 
     * ReplayGain track gain 
     */
    void setTrackGain(const double& value) {
        QVariantList values;
        values << value;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#trackGain", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#trackGain. 
     * ReplayGain track gain 
     */
    void addTrackGain(const double& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#trackGain", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#performer. 
     * Performer 
     */
    QList<QUrl> performers() const {
        QList<QUrl> value;
        foreach(const QVariant& v, property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#performer", QUrl::StrictMode)))
            value << v.value<QUrl>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#performer. 
     * Performer 
     */
    void setPerformers(const QList<QUrl>& value) {
        QVariantList values;
        foreach(const QUrl& v, value)
            values << v;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#performer", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#performer. 
     * Performer 
     */
    void addPerformer(const QUrl& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#performer", QUrl::StrictMode), value);
    }

protected:
    MusicPiece(const QUrl& uri, const QUrl& type)      : SimpleResource(uri), NIE::InformationElement(uri, type), NFO::Media(uri, type), NFO::Audio(uri, type) {
    }
    MusicPiece(const SimpleResource& res, const QUrl& type)
      : SimpleResource(res), NIE::InformationElement(res, type), NFO::Media(res, type), NFO::Audio(res, type) {
    }
};
}
}

#endif
