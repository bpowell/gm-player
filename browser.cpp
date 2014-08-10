#include "browser.h"

Browser::Browser() {
	//Flash support
	QWebSettings::globalSettings()->setAttribute(QWebSettings::PluginsEnabled, true);

	view = new QWebView(this);
	view->load(QUrl("https://music.google.com"));
	view->setGeometry(0,0,800,600);
}
