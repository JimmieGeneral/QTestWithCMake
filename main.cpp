#include <QApplication>
#include <QIcon>
#include "Src/QTestWidget.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);

  a.setWindowIcon(QIcon("./skin/app.png"));

  QTestWidget testWidget;
  testWidget.show();

  return QApplication::exec();
}
