#ifndef BROWSER_H_
#define BROWSER_H_

#include <QtWidgets>
#include <QtWebKitWidgets>

class Browser : public QMainWindow {
    Q_OBJECT
    private:
        QWebView *m_view;
        QWebElement getElement(QString what) const;

    public:
        Browser();
        QString getArtist() const;
        QString getAlbum() const;
        QString getTitle() const;
        int getTrackCurrentTime() const;
        int getTrackTotalTime() const;

    private slots:
        void titleHasChanged(QString title);
};

#endif
