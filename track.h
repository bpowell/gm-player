#ifndef TRACK_H_
#define TRACK_H_

#include <QtCore>
#include <ostream>

class Track {
    private:
        QString m_artist;
        QString m_title;
        QString m_album;
        int m_playedTime;
        int m_totalTime;
        bool m_scrobbled;

    public:
        QString getArtist() const;
        QString getTitle() const;
        QString getAlbum() const;
        int getPlayedTime() const;
        int getTotalTime() const;
        bool isScrobbled() const;

        void setPlayedTime(int t);
        void setTotalTime(int t);
        void setScrobbled(bool s);

        bool operator==(const Track &track);
        Track(QString artist, QString title, QString album);
};

#endif
