#ifndef SRC_S21_SMARTCALC_H_
#define SRC_S21_SMARTCALC_H_

#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

enum x_var_status {
  VAR = 1,
  GRAPH = 2
}; // status of the x lexeme, whether it is used as variable in algebraic
   // expression or for plotting a graph
enum priority { ADDSUB = 1, MULTDIVMOD = 2, POW = 3, FUNC = 4, NONE = -69 };
// ADDSUB = ADDING + SUBTRACTION, MULTDIVMOD = MULTIPLICATION + DIVISION +
// MODULO
enum operators {
  MINUS = -3,
  PLUS = -4,
  DIV = -5,
  MUL = -6,
  MOD = -8,
  COS = -11,
  SIN = -12,
  TAN = -13,
  ACOS = -14,
  ASIN = -15,
  ATAN = -16,
  SQRT = -17,
  LN = -18,
  LOG = -19,
  LEFT_PARENTHESIS = -20,
  RIGHT_PARENTHESIS = -21
};

struct Operator_ {
  Operator_(int name) : name_(name) {
    switch (name_) {
    case -3:
    case -4:
      priority_ = ADDSUB;
      break;
    case -5:
    case -6:
    case -8:
      priority_ = MULTDIVMOD;
      break;
    case 3:
      priority_ = POW;
      break;
    case -11:
    case -12:
    case -13:
    case -14:
    case -15:
    case -16:
    case -17:
    case -18:
    case -19:
      priority_ = FUNC;
      break;
    case -20:
    case -21:
      priority_ = NONE;
      break;
    }
  }
  int priority_;
  int name_;
};

struct Lexeme {
  Lexeme(int name) : operator_(name) {}      // if lexeme is an operator
  Lexeme(double number) : number_(number) {} // if lexeme is a number
  Operator_ operator_{NONE};
  double number_{0};
};

namespace s21 {

class Model {
public:
  Model() = default;
  Model(int x_var_status) : x_var_status_(x_var_status) {}
  int checker(std::string &str);
  std::vector<Lexeme> &parser(std::string &str);
  double calculation();
  void set_x_var(int x) { x_var_ = x; }

private:
  std::vector<Lexeme> result_;
  double x_var_{0};
  const int x_var_status_{VAR};
};

} // namespace s21

#endif
