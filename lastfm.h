#ifndef LASTFM_
#define LASTFM_

#include <QtCore>
#include <QCryptographicHash>
#include <QObject>
#include <QtNetwork>
#include <Audioscrobbler.h>
#include <ws.h>
#include <misc.h>
#include <XmlQuery.h>
#include <Artist.h>
#include <Track.h>

class LastFM : public QObject {
 Q_OBJECT

private:
    QNetworkReply *m_authenticateReply;
    lastfm::Audioscrobbler m_scrobbler;
    QString m_password;
    QBoolean m_is_authenticated;

public:
    LastFM();
    void scrobble();
    void loadSettings();
    QString md5(const QByteArray& src);

private slots:
    void authenticated();
    void scrobbled();
};

#endif
