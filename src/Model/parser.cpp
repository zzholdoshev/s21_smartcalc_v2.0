#include "Model.h"
#include <cstring>
#include <iterator>

void write_to_result(std::vector<Lexeme> &result,
                     std::stack<Lexeme> &operators) {
  if (!operators.empty()) {
    result.push_back(operators.top());
    operators.pop();
  }
}

void shunting_yard(std::stack<Lexeme> &operators, int lexeme,
                   std::vector<Lexeme>
                       &result) { // Deijkstra's algorithm for converting to RPN
  Lexeme current = lexeme;
  if (operators.empty() ||
      operators.top().operator_.priority_ < current.operator_.priority_ ||
      (operators.top().operator_.name_ == POW &&
       current.operator_.name_ == POW)) {
    operators.push(lexeme);
  } else {
    while (!operators.empty() &&
           operators.top().operator_.priority_ >= current.operator_.priority_) {
      write_to_result(result, operators);
    }
    operators.push(lexeme);
  }
}

void x_var_read(double *x, int i, std::string str) {
  while ((str[i] < 48 || str[i] > 57)) {
    i++;
  }
  const char *temp = str.c_str();
  *x = atof(temp + i);
}
void parentheses_process(
    std::stack<Lexeme> &operators,
    std::vector<Lexeme>
        &result) { // parse parentheses when closing parentheses occurs
  while (!operators.empty() &&
         operators.top().operator_.name_ != LEFT_PARENTHESIS) {
    write_to_result(result, operators);
  }
  if (!operators.empty() && operators.top().operator_.name_ == LEFT_PARENTHESIS)
    operators.pop();
}
void skip_number(std::string &str, size_t &i) {
  while ((str[i] >= 48 && str[i] <= 57) || str[i] == '.' || str[i] == ',') {
    ++i;
  }
  --i;
}
std::vector<Lexeme> &s21::Model::parser(std::string &str) {
  std::stack<Lexeme> operators;
  std::locale::global(std::locale("C"));
  for (size_t i = 0; i < str.size(); ++i) {
    switch (str[i]) {
    case '=': // '=' can occur only with x variable
      if (x_var_status_ != GRAPH) {
        x_var_read(&x_var_, ++i, str); // reads the x variable
      } else {
        throw("ERROR: incorrect expression");
      }
      break;
    case '+':
      shunting_yard(operators, PLUS, result_);
      break;
    case '-':
      shunting_yard(operators, MINUS, result_);
      break;
    case '~':
      result_.push_back(atof((str.c_str() + ++i)) * (-1));
      skip_number(str, i);
      break;
    case 'm':
      shunting_yard(operators, MOD, result_);
      break;
    case '*':
      shunting_yard(operators, MUL, result_);
      break;
    case '/':
      shunting_yard(operators, DIV, result_);
      break;
    case '^':
      shunting_yard(operators, POW, result_);
      break;
    case 's':
      if (i < str.size() - 1 && str[i + 1] == 'i')
        shunting_yard(operators, SIN, result_);
      if (i < str.size() - 1 && str[i + 1] == 'q')
        shunting_yard(operators, SQRT, result_);
      break;
    case 'c':
      shunting_yard(operators, COS, result_);
      break;
    case 'a':
      if (i < str.size() - 3 && str.substr(i, 4) == "asin")
        shunting_yard(operators, ASIN, result_);
      if (str.substr(i, 4) == "atan")
        shunting_yard(operators, ATAN, result_);
      if (str.substr(i, 4) == "acos")
        shunting_yard(operators, ACOS, result_);
      i += 3;
      break;
    case 't':
      if (i < str.size() - 1 && str[i + 1] == 'a') {
        shunting_yard(operators, TAN, result_);
        ++i;
      }
      break;
    case 'l':
      if (i < str.size() - 2 && str.substr(i, 3) == "log")
        shunting_yard(operators, LOG, result_);
      if (i < str.size() - 1 && str[i + 1] == 'n')
        shunting_yard(operators, LN, result_);
      break;
    case '(':
      operators.push(LEFT_PARENTHESIS);
      break;
    case ')':
      parentheses_process(operators, result_);
      break;
    case 'x':
    case 'X':
      result_.push_back(x_var_);
      break;
    default:
      if (str[i] >= 48 && str[i] <= 57) {
        result_.push_back(atof((str.c_str() + i)));
        skip_number(str, i);
      }
      break;
    }
  }
  while (!operators.empty()) {
    write_to_result(result_, operators);
  }
  return result_;
}

void calc_binary_operator_(std::vector<Lexeme> &result,
                           std::stack<double> &operands, int i) {
  double a = 0.0;
  double b = 0.0;
  if (!operands.empty()) {
    b = operands.top();
    operands.pop();
  }
  if (!operands.empty()) {
    a = operands.top();
    operands.pop();
  }
  switch (result[i].operator_.name_) {
  case PLUS:
    operands.push(a + b);
    break;
  case MINUS:
    operands.push(a - b);
    break;
  case MUL:
    operands.push(a * b);
    break;
  case DIV:
    operands.push(a / b);
    break;
  case MOD:
    if (((int)a ^ (int)b) < 0) { // checks if one of the operands is negative,
                                 // bc in this case MOD is no the same as %
      operands.push(b < 0 ? b + (int)a % (int)b : b - abs((int)a) % (int)b);
    } else {
      operands.push((double)((int)a % (int)b));
    }
    break;
  case POW:
    operands.push(pow(a, b));
    break;
  }
}

void calc_func_operator_(std::vector<Lexeme> &result,
                         std::stack<double> &operands, int i) {
  double res = 0;
  if (!operands.empty()) {
    res = operands.top();
    operands.pop();
  }
  switch (result[i].operator_.name_) {
  case SIN:
    operands.push(sin((M_PI / (double)180) * res));
    break;
  case SQRT:
    operands.push(sqrt(res));
    break;
  case COS:
    operands.push(cos((M_PI / (double)180) * res));
    break;
  case ACOS:
    if (res <= 1 && res >= -1) {
      operands.push(acos(res) * 180 / M_PI);
    } else {
      result.erase(result.begin(), result.end());
      throw("ERROR: undefined for values outside [-1, 1]");
    }
    break;
  case ASIN:
    if (res <= 1 && res >= -1) {
      operands.push(asin(res) * 180 / M_PI);
    } else {
      result.erase(result.begin(), result.end());
      throw("ERROR: undefined for values outisde [-1, 1]");
    }
    break;
  case ATAN:
    operands.push(atan(res) * (180 / M_PI));
    break;
  case TAN:
    if (res < 90 || (int)res % 90 != 0) {
      operands.push(tan((M_PI / 180) * res));
    } else {
      result.erase(result.begin(), result.end());
      throw("ERROR: Tangent is undefined for angles that are multiples of π "
            "(180°) from π∕2 (90°)");
    }
    break;
  case LN:
    if (res > 0) {
      operands.push(log(res));
    } else {
      result.erase(result.begin(), result.end());
      throw("ERROR: Log is defined only for positive numbers");
    }
    break;
  case LOG:
    if (res > 0) {
      operands.push(log10(res));
    } else {
      throw("ERROR: Log is defined only for positive numbers");
    }
    break;
  }
}

double s21::Model::calculation() {
  std::stack<double> operands;
  for (size_t i = 0; i < result_.size(); ++i) {
    switch (result_[i].operator_.name_) {
    case MINUS:
    case PLUS:
    case DIV:
    case MUL:
    case MOD:
    case POW:
      calc_binary_operator_(result_, operands, i);
      break;
    case SIN:
    case SQRT:
    case COS:
    case TAN:
    case ATAN:
    case ACOS:
    case ASIN:
    case LN:
    case LOG:
      calc_func_operator_(result_, operands, i);
      break;
    case NONE: // if operation is NONE, then it is operand
      operands.push(result_[i].number_);
      break;
    }
  }
  double res = operands.top();
  result_.erase(result_.begin(), result_.end());
  return res;
}
