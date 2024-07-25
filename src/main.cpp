#include "./View/mainwindow.h"

#include <QApplication>
#include <QCompleter>
int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  MainWindow w;
  w.show();
  return a.exec();
}
