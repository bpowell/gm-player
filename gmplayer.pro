greaterThan(QT_MAJOR_VERSION, 4):QT += widgets webkitwidgets network xml
SOURCES += main.cpp browser.cpp cookiejar.cpp lastfm.cpp track.cpp
HEADERS += browser.h cookiejar.h lastfm.h track.h
unix:INCLUDEPATH += "/home/brandon/p/lastfm/source/src" "/home/brandon/p/lastfm/build/src/"
LIBS += -L/home/brandon/p/lastfm/build/src -llastfm
QMAKE_CXX = clang++
