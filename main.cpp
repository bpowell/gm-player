#include "browser.h"
#include "lastfm.h"
#include <QtCore>
#include <QCryptographicHash>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setApplicationName("GM Player");

    LastFM *last = new LastFM();

    Browser *browser = new Browser(last);
    browser->setGeometry(0,0,800,600);
    browser->show();

    return app.exec();
}
