#include "browser.h"
#include "cookiejar.h"

Browser::Browser() {
    //Flash support
    QWebSettings::globalSettings()->setAttribute(QWebSettings::PluginsEnabled, true);

    view = new QWebView(this);
    QNetworkAccessManager *nam = new QNetworkAccessManager();
    CookieJar *cookies = new CookieJar();

    nam->setCookieJar(cookies);
    view->page()->setNetworkAccessManager(nam);
    view->load(QUrl("https://music.google.com"));
    view->setGeometry(0,0,800,600);
}
