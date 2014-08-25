#include "track.h"

Track::Track(QString artist, QString title, QString album) :
    m_artist(artist), m_title(title), m_album(album) {
    }

QString Track::getArtist() const {
    return m_artist;
}

QString Track::getTitle() const {
    return m_title;
}

QString Track::getAlbum() const {
    return m_album;
}

bool Track::operator==(const Track &track) {
    if(m_artist==track.getArtist() &&
            m_title==track.getTitle() &&
            m_album==track.getAlbum()) {
        return true;
    } else {
        return false;
    }
}
