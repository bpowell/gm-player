#ifndef TRACK_H_
#define TRACK_H_

#include <QtCore>

class Track {
    private:
        QString m_artist;
        QString m_title;
        QString m_album;

    public:
        QString getArtist() const;
        QString getTitle() const;
        QString getAlbum() const;

        bool operator==(const Track &track);
        Track(QString artist, QString title, QString album);
};

#endif
