#ifndef SRC_S21_SMARTCALC_H
#define SRC_S21_SMARTCALC_H

#include "../Model/Model.h"

namespace s21 {
class Controller {
public:
  Controller() = default;
  Controller(int x_var_status) : model_(x_var_status) {}
  double calculate(std::string &str);
  void set_x_var(int x) { model_.set_x_var(x); }

private:
  Model model_;
};
} // namespace s21

#endif
