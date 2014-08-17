#include "browser.h"
#include "cookiejar.h"

Browser::Browser() {
    //Flash support
    QWebSettings::globalSettings()->setAttribute(QWebSettings::PluginsEnabled, true);

    m_view = new QWebView(this);
    QNetworkAccessManager *nam = new QNetworkAccessManager();
    CookieJar *cookies = new CookieJar();

    nam->setCookieJar(cookies);
    m_view->page()->setNetworkAccessManager(nam);
    m_view->load(QUrl("https://music.google.com"));
    m_view->setGeometry(0,0,800,600);

    connect(m_view, SIGNAL(titleChanged(QString)), this, SLOT(titleHasChanged(QString)));
}

QWebElement Browser::getElement(QString what) {
    QWebFrame *frame = m_view->page()->mainFrame();
    return frame->findFirstElement(what);
}

QString Browser::getArtist() {
    QWebElement element = getElement(".player-artist");
    return element.toPlainText();
}

QString Browser::getAlbum() {
    QWebElement element = getElement(".playerSongTitle");
    return element.toPlainText();
}

int Browser::getTrackCurrentTime() {
    QWebElement element = getElement("#slider");
    return element.attribute("aria-valuemin").toInt();
}

int Browser::getTrackTotalTime() {
    QWebElement element = getElement("#slider");
    return element.attribute("aria-valuemax").toInt();
}

void Browser::titleHasChanged(QString title) {
}
