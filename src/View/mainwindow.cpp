#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QCompleter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  graph_window_ = new graph_window(this);
  QStringList wordList = {"sin()",  "cos()", "tan()", "asin()", "atan()",
                          "acos()", "log()", "ln()",  "mod"};
  QCompleter *completer = new QCompleter(wordList, ui->lineEdit);
  ui->lineEdit->setCompleter(completer);
  ui->lineEdit->setFocus();
  connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digit_numbers()));
  connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digit_numbers()));
  connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digit_numbers()));
  connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digit_numbers()));
  connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digit_numbers()));
  connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digit_numbers()));
  connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digit_numbers()));
  connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digit_numbers()));
  connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digit_numbers()));
  connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digit_numbers()));
  connect(ui->pushButton_dot, SIGNAL(clicked()), this, SLOT(digit_numbers()));
  connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(operations()));
  connect(ui->pushButton_mul, SIGNAL(clicked()), this, SLOT(operations()));
  connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(operations()));
  connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(operations()));
  connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(operations()));
  connect(ui->pushButton_left_parenthesis, SIGNAL(clicked()), this,
          SLOT(operations()));
  connect(ui->pushButton_pow, SIGNAL(clicked()), this, SLOT(operations()));
  connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(operations()));
  connect(ui->pushButton_right_parenthesis, SIGNAL(clicked()), this,
          SLOT(operations()));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::digit_numbers() {
  QPushButton *button = (QPushButton *)sender();
  ui->lineEdit->insert(button->text());
  ui->lineEdit->setFocus();
}
void MainWindow::operations() {
  QString new_line_text;
  QPushButton *button = (QPushButton *)sender();
  if (button->text() == "÷") {
    ui->lineEdit->insert("/");
  } else {
    if (button->text() == "x") {
      ui->lineEdit->insert("*");
    } else {
      if (button->text().contains(QChar(0x221A))) {
        ui->lineEdit->insert("sqrt()");
        ui->lineEdit->setCursorPosition(set_position(
            ui->lineEdit->text(), ui->lineEdit->cursorPosition() - 1));

      } else {
        if (button->text() == "–") {
          ui->lineEdit->insert("-");
        } else {
          ui->lineEdit->insert(button->text());
        }
      }
    }
  }
  ui->lineEdit->setFocus();
}

void MainWindow::on_pushButton_pi_clicked() {
  ui->lineEdit->insert(QString::number(M_PI, 'f', 9));
  ui->lineEdit->setFocus();
}

void MainWindow::on_pushButton_clear_clicked() {
  ui->lineEdit->clear();
  ui->lineEdit->setFocus();
}

void remove_trailing_zeroes(QString &res_str) {
  int i = res_str.size() - 1;
  while (res_str[i] != '.' && res_str[i] != ',' && res_str[i] == '0' && i > 0) {
    res_str.chop(1);
    if (res_str[i - 1] == '.') {
      res_str.chop(1);
      return;
    }
    --i;
  }
}
void MainWindow::on_pushButton_equal_clicked() {
  if (ui->lineEdit->text().size() > 0) {
    double res = 0;
    int error = 0;
    QString input_string = ui->lineEdit->text();
    try {
      std::string str = ui->lineEdit->text().toStdString();
      res = Controller_.calculate(str);
    } catch (const char *calc_error) {
      ui->textBrowser->append(QString(calc_error));
      error = 1;
    }
    if (!error) {
      ui->lineEdit->clear();
      QString res_str = QString::number(res, 'f', 9);
      remove_trailing_zeroes(res_str);
      ui->lineEdit->insert(res_str);
      ui->textBrowser->append(input_string + QString("    =    ") + res_str);
    }
  }
  ui->lineEdit->setFocus();
}

void MainWindow::on_lineEdit_returnPressed() { on_pushButton_equal_clicked(); }

void MainWindow::on_lineEdit_textChanged(const QString &arg1) {
  if (ui->lineEdit->text().size() >= line_previous_text.size()) {
    if (!strncmp(ui->lineEdit->text().toStdString().c_str() +
                     ui->lineEdit->cursorPosition() - 2,
                 "si", 2)) {
      ui->lineEdit->insert("n()");
      ui->lineEdit->setCursorPosition(set_position(
          ui->lineEdit->text(), ui->lineEdit->cursorPosition() - 1));
    }

    if (!strncmp(ui->lineEdit->text().toStdString().c_str() +
                     ui->lineEdit->cursorPosition() - 2,
                 "as", 2)) {
      ui->lineEdit->insert("in()");
      ui->lineEdit->setCursorPosition(set_position(
          ui->lineEdit->text(), ui->lineEdit->cursorPosition() - 1));
    }

    if (!strncmp(ui->lineEdit->text().toStdString().c_str() +
                     ui->lineEdit->cursorPosition() - 2,
                 "sq", 2)) {
      ui->lineEdit->insert("rt()");
      ui->lineEdit->setCursorPosition(set_position(
          ui->lineEdit->text(), ui->lineEdit->cursorPosition() - 1));
    }
    if (!strncmp(ui->lineEdit->text().toStdString().c_str() +
                     ui->lineEdit->cursorPosition() - 1,
                 "c", 1)) {
      ui->lineEdit->insert("os()");
      ui->lineEdit->setCursorPosition(set_position(
          ui->lineEdit->text(), ui->lineEdit->cursorPosition() - 1));
    }
    if (!strncmp(ui->lineEdit->text().toStdString().c_str() +
                     ui->lineEdit->cursorPosition() - 2,
                 "lo", 2)) {
      ui->lineEdit->insert("g()");
      ui->lineEdit->setCursorPosition(set_position(
          ui->lineEdit->text(), ui->lineEdit->cursorPosition() - 1));
    }
    if (!strncmp(ui->lineEdit->text().toStdString().c_str() +
                     ui->lineEdit->cursorPosition() - 2,
                 "l", 1)) {
      ui->lineEdit->insert("()");
      ui->lineEdit->setCursorPosition(set_position(
          ui->lineEdit->text(), ui->lineEdit->cursorPosition() - 1));
    }
    if (!strncmp(ui->lineEdit->text().toStdString().c_str() +
                     ui->lineEdit->cursorPosition() - 1,
                 "t", 1)) {
      ui->lineEdit->insert("an()");
      ui->lineEdit->setCursorPosition(set_position(
          ui->lineEdit->text(), ui->lineEdit->cursorPosition() - 1));
    }
    if (arg1.right(1) == 'm') {
      ui->lineEdit->insert("od ");
    }
  }
  if (ui->lineEdit->text().trimmed().isEmpty()) {
    ui->lineEdit->setText("");
  }
  line_previous_text = ui->lineEdit->text();
}

void MainWindow::on_pushButton_clicked() { graph_window_->show(); }
