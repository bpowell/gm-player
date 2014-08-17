#ifndef BROWSER_H_
#define BROWSER_H_

#include <QtWidgets>
#include <QtWebKitWidgets>

class Browser : public QMainWindow {
    Q_OBJECT
    private:
        QWebView *m_view;
        QWebElement getElement(QString what);

    public:
        Browser();
        QString getArtist();
        QString getAlbum();
        QString getTitle();
        int getTrackCurrentTime();
        int getTrackTotalTime();

    private slots:
        void titleHasChanged(QString title);
};

#endif
