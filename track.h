#ifndef TRACK_H_
#define TRACK_H_

#include <QtCore>
#include <ostream>

#include <Track.h>

class MyTrack {
    private:
        QString m_artist;
        QString m_title;
        QString m_album;
        int m_playedTime;
        int m_totalTime;
        bool m_scrobbled;
        lastfm::MutableTrack m_track;

    public:
        QString getArtist() const;
        QString getTitle() const;
        QString getAlbum() const;
        int getPlayedTime() const;
        int getTotalTime() const;
        bool isScrobbled() const;
        QString toString() const;

        void setPlayedTime(int t);
        void setTotalTime(int t);
        void setScrobbled(bool s);

        bool equals(const MyTrack *track);
        MyTrack(QString artist, QString title, QString album);

        void scrobble();
};

#endif
