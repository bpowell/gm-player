#include "browser.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	Browser browser;
	browser.setGeometry(0,0,800,600);
	browser.show();

	return app.exec();
}
