#ifndef COOKIEJAR_H_
#define COOKIEJAR_H_

#include <QtNetwork>
#include <QtNetwork/QNetworkCookieJar>

class CookieJar : public QNetworkCookieJar {
	public:
		CookieJar();
		bool setCookiesFromUrl(const QList<QNetworkCookie> & cookieList, const QUrl & url);
		void save();
		void load();
};

#endif
