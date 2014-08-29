#include "track.h"

Track::Track(QString artist, QString title, QString album) :
    m_artist(artist), m_title(title), m_album(album), m_scrobbled(false) {
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

int Track::getPlayedTime() const {
    return m_playedTime;
}

int Track::getTotalTime() const {
    return m_totalTime;
}

bool Track::isScrobbled() const {
    return m_scrobbled;
}

void Track::setPlayedTime(int t) {
    m_playedTime = t;
}

void Track::setTotalTime(int t) {
    m_totalTime = t;
}

void Track::setScrobbled(bool s) {
    m_scrobbled = s;
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

std::ostream &operator<<(std::ostream &out, Track &track) {
    out << "Artist: " << track.getArtist().toStdString()
        << ", Title: " << track.getTitle().toStdString()
        << ", Album: " << track.getAlbum().toStdString();
    return out;
}
