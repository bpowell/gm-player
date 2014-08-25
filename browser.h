#ifndef BROWSER_H_
#define BROWSER_H_

#include <QtWidgets>
#include <QtWebKitWidgets>

#include "lastfm.h"
#include "track.h"

class Browser : public QMainWindow {
    Q_OBJECT
    private:
        LastFM *lastFM;
        QWebView *m_view;
        QWebElement getElement(QString what) const;
        Track *currentTrack;

    public:
        Browser(LastFM *lastFM);
        QString getArtist() const;
        QString getAlbum() const;
        QString getTitle() const;
        int getTrackCurrentTime() const;
        int getTrackTotalTime() const;
        Track *getTrack();

    private slots:
        void titleHasChanged(QString title);
        void update();
};

#endif
