#include <QApplication>
#include <QIcon>
#include "QTestWidget.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	a.setWindowIcon(QIcon("./app.png"));

	QTestWidget testWidget;
	testWidget.show();

	return QApplication::exec();
}
