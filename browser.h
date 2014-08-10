#ifndef BROWSER_H_
#define BROWSER_H_

#include <QtWidgets>
#include <QtWebKitWidgets>

class Browser : public QMainWindow {
    Q_OBJECT
    private:
        QWebView *view;

    public:
        Browser();
};

#endif
