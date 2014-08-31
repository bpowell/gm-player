#include "track.h"
#include "lastfm.h"

MyTrack::MyTrack(QString artist, QString title, QString album) :
    m_artist(artist), m_title(title), m_album(album), m_scrobbled(false) {
        m_track.setArtist(artist);
        m_track.setTitle(title);
        m_track.setAlbum(album);
        m_track.stamp();
    }

QString MyTrack::getArtist() const {
    return m_artist;
}

QString MyTrack::getTitle() const {
    return m_title;
}

QString MyTrack::getAlbum() const {
    return m_album;
}

int MyTrack::getPlayedTime() const {
    return m_playedTime;
}

int MyTrack::getTotalTime() const {
    return m_totalTime;
}

bool MyTrack::isScrobbled() const {
    return m_scrobbled;
}

void MyTrack::setPlayedTime(int t) {
    m_playedTime = t;
}

void MyTrack::setTotalTime(int t) {
    m_totalTime = t;
}

void MyTrack::setScrobbled(bool s) {
    m_scrobbled = s;
}

bool MyTrack::equals(const MyTrack *track) {
    if(track==NULL) {
        return false;
    }

    if(m_artist==track->getArtist() &&
            m_title==track->getTitle() &&
            m_album==track->getAlbum()) {
        return true;
    } else {
        return false;
    }
}

QString MyTrack::toString() const {
    QString ret = "Artist: " + getArtist();
    ret += ", Album: " + getAlbum();
    ret += ", Track: " + getTitle();

    return ret;
}

void MyTrack::scrobble() {
    m_track.scrobble();
}
