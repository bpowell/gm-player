#ifndef BROWSER_H_
#define BROWSER_H_

#include <QtWidgets>
#include <QtWebKitWidgets>

#include "lastfm.h"

class Browser : public QMainWindow {
    Q_OBJECT
    private:
        LastFM *lastFM;
        QWebView *m_view;
        QWebElement getElement(QString what) const;

    public:
        Browser(LastFM *lastFM);
        QString getArtist() const;
        QString getAlbum() const;
        QString getTitle() const;
        int getTrackCurrentTime() const;
        int getTrackTotalTime() const;

    private slots:
        void titleHasChanged(QString title);
};

#endif
