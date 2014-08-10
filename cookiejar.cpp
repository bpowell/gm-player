#include "cookiejar.h"

QDataStream &operator<<(QDataStream &stream, const QList<QNetworkCookie> &list)
{
	stream << quint32(list.size());
	for (int i = 0; i < list.size(); ++i)
		stream << list.at(i).toRawForm();
	return stream;
}

QDataStream &operator>>(QDataStream &stream, QList<QNetworkCookie> &list)
{
	list.clear();

	quint32 count;
	stream >> count;
	for (quint32 i = 0; i < count; ++i) {
		QByteArray value;
		stream >> value;
		QList<QNetworkCookie> newCookies = QNetworkCookie::parseCookies(value);
		if (newCookies.count() == 0 && value.length() != 0) {
			qWarning() << "CookieJar: Unable to parse saved cookie:" << value;
		}
		for (int j = 0; j < newCookies.count(); ++j)
			list.append(newCookies.at(j));
		if (stream.atEnd())
			break;
	}
	return stream;
}

CookieJar::CookieJar() {
	load();
}

bool CookieJar::setCookiesFromUrl(const QList<QNetworkCookie> & cookieList, const QUrl & url) {
	QNetworkCookieJar::setCookiesFromUrl(cookieList, url);
	save();
	return true;
}

void CookieJar::save() {
	QSettings cookieSettings(QLatin1String("cookies.ini"), QSettings::IniFormat);

	QList<QNetworkCookie> cookies = allCookies();
	for (int i = cookies.count() - 1; i >= 0; --i) {
		if (cookies.at(i).isSessionCookie())
			cookies.removeAt(i);
	}
	cookieSettings.setValue(QLatin1String("cookies"), qVariantFromValue<QList<QNetworkCookie> >(cookies));
}

void CookieJar::load() {
	qRegisterMetaTypeStreamOperators<QList<QNetworkCookie> >("QList<QNetworkCookie>");
	QSettings cookieSettings(QLatin1String("cookies.ini"), QSettings::IniFormat);
	setAllCookies(qvariant_cast<QList<QNetworkCookie> >(cookieSettings.value(QLatin1String("cookies"))));
}
