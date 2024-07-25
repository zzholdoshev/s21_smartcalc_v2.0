#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../Controller/Controller.h"
#include "common.h"
#include "graph_window.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow, public common_funcs {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private slots:
  void digit_numbers();
  void operations();
  void on_pushButton_pi_clicked();
  void on_pushButton_clear_clicked();
  void on_pushButton_equal_clicked();
  void on_lineEdit_returnPressed();

  void on_lineEdit_textChanged(const QString &arg1);

  void on_pushButton_clicked();

private:
  Ui::MainWindow *ui;
  s21::Controller Controller_;
  graph_window *graph_window_;
  QString line_previous_text;
};
#endif // MAINWINDOW_H
