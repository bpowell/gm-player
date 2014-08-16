#include "lastfm.h"

LastFM::LastFM() : m_scrobbler("GM Player"){
    lastfm::ws::ApiKey = "036521024cdba0712f16f59833b50d06";
    lastfm::ws::SharedSecret = "12b55a5bff43c973fc83f5e188037649";
    m_is_authenticated = false;
    loadSettings();

    const QString authToken = md5( QString( "%1%2" ).arg( lastfm::ws::Username ).arg(md5( m_password.toUtf8() ) ).toUtf8() );
    QMap<QString, QString> query;
    query[ "method" ] = "auth.getMobileSession";
    query[ "username" ] = lastfm::ws::Username;
    query[ "authToken" ] = authToken;
    m_authenticateReply = lastfm::ws::post( query );

    connect( m_authenticateReply, SIGNAL(finished()), SLOT(authenticated()) );
}

QString LastFM::md5( const QByteArray& src ) {
    QByteArray const digest = QCryptographicHash::hash( src, QCryptographicHash::Md5 );
    return QString::fromLatin1( digest.toHex() ).rightJustified( 32, '0' );
}

void LastFM::authenticated() {
    switch( m_authenticateReply ? m_authenticateReply->error() : QNetworkReply::UnknownNetworkError )
    {
        case QNetworkReply::NoError:
        {
            lastfm::XmlQuery lfm;
            if( !lfm.parse( m_authenticateReply->readAll() ) || lfm.children( "error" ).size() > 0 )
            {
                qDebug() << "error authenticating with last.fm service:" << lfm.text();
                break;
            }

            lastfm::ws::Username = lfm["session"]["name"].text();
            lastfm::ws::SessionKey = lfm["session"]["key"].text();
            m_is_authenticated = true;
            break;
        }
        case QNetworkReply::AuthenticationRequiredError:
        {
            qDebug() << "Authenticated required error";
            break;
        }
        default:
        {
            qDebug() << "Network problems";
            break;
        }
    }
}

void LastFM::scrobbled() {
    qDebug() << "we scrobbled";
}

void LastFM::scrobble() {
    lastfm::MutableTrack t;
    t.setArtist("Test Artist");
    t.setTitle("Test Track");
    t.setTimeStamp(QDateTime::currentDateTime());
    m_authenticateReply = t.scrobble();
    connect( m_authenticateReply, SIGNAL(finished()), SLOT(scrobbled()) );
    switch( t.scrobbleStatus() )
    {
        case lastfm::Track::Cached:
        case lastfm::Track::Submitted:
            qDebug() << "submit";
            break;
        case lastfm::Track::Null:
            qDebug() << "null";
            break;
        case lastfm::Track::Error:
            qDebug() << "error";
            break;
    }
}

void LastFM::loadSettings() {
    QSettings settings(QLatin1String("lastfm.ini"), QSettings::IniFormat);
    lastfm::ws::Username = settings.value("username").toString();
    m_password = settings.value("password").toString();
}
