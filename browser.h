#ifndef BROWSER_H_
#define BROWSER_H_

#include <QtWidgets>
#include <QtWebKitWidgets>

#include "track.h"

class Browser : public QMainWindow {
    Q_OBJECT
    private:
        QWebView *m_view;
        QWebElement getElement(QString what) const;
        MyTrack *currentTrack;

    public:
        Browser();
        QString getArtist() const;
        QString getAlbum() const;
        QString getTitle() const;
        int getTrackCurrentTime() const;
        int getTrackTotalTime() const;
        MyTrack *getTrack();

    private slots:
        void titleHasChanged(QString title);
        void update();
};

#endif
