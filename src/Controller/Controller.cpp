#include "Controller.h"

double s21::Controller::calculate(std::string &str) {
  double res = 0;
  if (model_.checker(str)) {
    throw("ERROR: expression is incorrect");
  } else {
    model_.parser(str);
    res = model_.calculation();
  }
  return res;
}
