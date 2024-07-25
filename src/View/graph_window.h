#ifndef GRAPH_WINDOW_H
#define GRAPH_WINDOW_H

#include "../QCustomPlot/qcustomplot.h"
#include "Controller/Controller.h"
#include "common.h"
#include "ui_graph_window.h"
#include <QDialog>
#include <QVector>

namespace Ui {
class graph_window;
}

class graph_window : public QDialog, public common_funcs {
  Q_OBJECT

public:
  explicit graph_window(QWidget *parent = nullptr);
  ~graph_window();

private slots:

  void on_lineEdit_5_textChanged(const QString &arg1);

  void on_pushButton_clicked();

private:
  QString line_previous_text;
  Ui::graph_window *ui;
  s21::Controller Controller_{GRAPH};
};

#endif // GRAPH_WINDOW_H
