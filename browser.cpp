#include "browser.h"
#include "cookiejar.h"

Browser::Browser(LastFM *lastFM) : lastFM(lastFM) {
    currentTrack = NULL;

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

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(1000);
}

QWebElement Browser::getElement(QString what) const {
    QWebFrame *frame = m_view->page()->mainFrame();
    return frame->findFirstElement(what);
}

QString Browser::getArtist() const {
    QWebElement element = getElement(".player-artist");
    return element.toPlainText();
}

QString Browser::getTitle()  const {
    QWebElement element = getElement(".playerSongTitle");
    return element.toPlainText();
}

QString Browser::getAlbum()  const {
    QWebElement element = getElement(".player-album");
    return element.toPlainText();
}

int Browser::getTrackCurrentTime() const {
    QWebElement element = getElement("#slider");
    return element.attribute("aria-valuenow").toInt();
}

int Browser::getTrackTotalTime() const {
    QWebElement element = getElement("#slider");
    return element.attribute("aria-valuemax").toInt();
}

MyTrack *Browser::getTrack() {
    MyTrack *track;
    QString artist = getArtist();
    if(artist.isEmpty()) {
        track = NULL;
    } else {
        track = new MyTrack(artist, getTitle(), getAlbum());
        track->setPlayedTime(getTrackCurrentTime());
        track->setTotalTime(getTrackTotalTime());
    }

    return track;
}

void Browser::titleHasChanged(QString title) {
}

void Browser::update() {
    QWebElementCollection collection = m_view->page()->mainFrame()->findAllElements(".flat-button");
    //Determine if music is even playing (or paused)
    if(collection.at(3).hasAttribute("disabled")==true) {
        return;
    }

    //No track is playing. If we are at this point this should not be NULL
    //  but you never know
    MyTrack *trackPlaying = getTrack();
    if(trackPlaying==NULL) {
        return;
    }

    if(!trackPlaying->equals(currentTrack)) {
        currentTrack = trackPlaying;
    }

    currentTrack->setPlayedTime(trackPlaying->getPlayedTime());

    if(!currentTrack->isScrobbled()) {
        //If we have played over half the song, scrobble
        if(currentTrack->getPlayedTime() >= currentTrack->getTotalTime()/2) {
            currentTrack->setScrobbled(true);
            currentTrack->scrobble();
        }
    }
}
