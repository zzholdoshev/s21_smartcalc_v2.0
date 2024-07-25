#include "graph_window.h"

graph_window::graph_window(QWidget *parent)
    : QDialog(parent), ui(new Ui::graph_window) {
  ui->setupUi(this);
  this->setWindowTitle("Graph");
}

graph_window::~graph_window() { delete ui; }
void graph_window::on_lineEdit_5_textChanged(const QString &arg1) {
  if (ui->lineEdit_5->text().size() >= line_previous_text.size()) {
    if (!strncmp(ui->lineEdit_5->text().toStdString().c_str() +
                     ui->lineEdit_5->cursorPosition() - 2,
                 "si", 2)) {
      ui->lineEdit_5->insert("n()");
      ui->lineEdit_5->setCursorPosition(set_position(
          ui->lineEdit_5->text(), ui->lineEdit_5->cursorPosition() - 1));
    }

    if (!strncmp(ui->lineEdit_5->text().toStdString().c_str() +
                     ui->lineEdit_5->cursorPosition() - 2,
                 "as", 2)) {
      ui->lineEdit_5->insert("in()");
      ui->lineEdit_5->setCursorPosition(set_position(
          ui->lineEdit_5->text(), ui->lineEdit_5->cursorPosition() - 1));
    }

    if (!strncmp(ui->lineEdit_5->text().toStdString().c_str() +
                     ui->lineEdit_5->cursorPosition() - 2,
                 "sq", 2)) {
      ui->lineEdit_5->insert("rt()");
      ui->lineEdit_5->setCursorPosition(set_position(
          ui->lineEdit_5->text(), ui->lineEdit_5->cursorPosition() - 1));
    }
    if (!strncmp(ui->lineEdit_5->text().toStdString().c_str() +
                     ui->lineEdit_5->cursorPosition() - 1,
                 "c", 1)) {
      ui->lineEdit_5->insert("os()");
      ui->lineEdit_5->setCursorPosition(set_position(
          ui->lineEdit_5->text(), ui->lineEdit_5->cursorPosition() - 1));
    }
    if (!strncmp(ui->lineEdit_5->text().toStdString().c_str() +
                     ui->lineEdit_5->cursorPosition() - 2,
                 "lo", 2)) {
      ui->lineEdit_5->insert("g()");
      ui->lineEdit_5->setCursorPosition(set_position(
          ui->lineEdit_5->text(), ui->lineEdit_5->cursorPosition() - 1));
    }
    if (!strncmp(ui->lineEdit_5->text().toStdString().c_str() +
                     ui->lineEdit_5->cursorPosition() - 2,
                 "l", 1)) {
      ui->lineEdit_5->insert("()");
      ui->lineEdit_5->setCursorPosition(set_position(
          ui->lineEdit_5->text(), ui->lineEdit_5->cursorPosition() - 1));
    }
    if (!strncmp(ui->lineEdit_5->text().toStdString().c_str() +
                     ui->lineEdit_5->cursorPosition() - 1,
                 "t", 1)) {
      ui->lineEdit_5->insert("an()");
      ui->lineEdit_5->setCursorPosition(set_position(
          ui->lineEdit_5->text(), ui->lineEdit_5->cursorPosition() - 1));
    }
    if (arg1.right(1) == 'm') {
      ui->lineEdit_5->insert("od ");
    }
  }
  if (ui->lineEdit_5->text().trimmed().isEmpty()) {
    ui->lineEdit_5->setText("");
  }
  line_previous_text = ui->lineEdit_5->text();
}

void graph_window::on_pushButton_clicked() {
  std::string user_input = ui->lineEdit_5->text().toStdString();
  double x_min = ui->lineEdit->text().toDouble();
  double x_max = ui->lineEdit_2->text().toDouble();
  double y_min = ui->lineEdit_3->text().toDouble();
  double y_max = ui->lineEdit_4->text().toDouble();
  double step = 0.01;
  QVector<double> x;
  QVector<double> y;
  ui->widget->xAxis->setRange(x_min, x_max);
  ui->widget->yAxis->setRange(y_min, y_max);
  int n = (x_max - x_min) / step + 1;
  int i = 0;
  ui->widget->clearGraphs();

  if (user_input.size() != 0) {
    for (double v = x_min; i < n; v += step) {
      Controller_.set_x_var(v);
      try {
        y.push_back(Controller_.calculate(user_input));
        x.push_back(v);
      } catch (const char *e) {
      }
      ++i;
    }
    ui->widget->addGraph();
    // Set the scatter style to display bold dots
    ui->widget->graph(0)->setScatterStyle(QCPScatterStyle(
        QCPScatterStyle::ssDisc, QPen(Qt::black, 1), QBrush(Qt::black), 5));

    ui->widget->graph(0)->setLineStyle(QCPGraph::lsNone);
    ui->widget->graph(0)->addData(x, y);

    ui->widget->setInteraction(QCP::iRangeZoom, true);

    ui->widget->replot();
  }
}
