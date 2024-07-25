#include "Model.h"

void mult_sign_paste(std::string &str, int i) { str.insert(i, 1, '*'); }

void check_unary_operator_(std::string &str, int i) {
  int initial_i = i;
  int flag = 0;
  int status = 0;
  if (i != 0) {
    while (i > 0 && !status && !flag) {
      --i;
      switch (str[i]) {
      case ' ':
        break;
      case '(':
      case 'd': // checks for "mod"
        status = 1;
        break;
      default:
        flag = 1;
        break;
      }
    }
  }
  if (!initial_i || status == 1) {
    if (str[initial_i] == '-') {
      str[initial_i] = '~';
    } else {
      str[initial_i] = ' ';
    }
  }
}

void before_number_mult_sign(std::string &str, int i) {
  int flag = 0;
  int status = 0;
  while (i > 0 && !flag && !status) {
    --i;
    switch (str[i]) {
    case ' ':
      break;
    case ')':
      mult_sign_paste(str, i + 1);
      status = 1;
      break;
    default:
      flag = 1;
      break;
    }
  }
}

int after_number_checker(std::string &str, int i) {
  before_number_mult_sign(str, i);
  int status = 0;
  int flag = 0;
  ++i;
  while ((size_t)i < str.size() && !status && !flag) {
    switch (str[i]) {
    case '.':
    case ',':
      if (str[i + 1] >= 48 && str[i + 1] <= 57) {
        ++i;
        int whole_number = 0;
        while (!whole_number && (size_t)i < str.size()) {
          switch (str[i]) {
          case '+':
          case '-':
          case '*':
          case '/':
          case '^':
          case ')':
          case ' ':
            whole_number++;
            break;
          default:
            if (str[i] > 57 || str[i] < 48) {
              flag = 1;
            }
            break;
          }
          ++i;
        }
      } else {
        flag = 1;
      }
      break;
    case '-':
    case '+':
    case '*':
    case '/':
    case '^':
    case '=':
    case 'm':
      status = 1;
      break;
    case ')':
    case ' ':
      break;
    case 's':
    case 'c':
    case 'a':
    case 't':
    case 'l':
    case 'x':
    case 'X':
    case '(':
      status = 1;
      mult_sign_paste(str, i);
      break;
    default:
      if (str[i] > 57 || str[i] < 48) {
        flag = 1;
      }
      break;
    }
    ++i;
  }
  return flag;
}

int m_check_core(std::string &str, int i,
                 int parenthesis) { // allows checking post/pre mod expressions
                                    // inside parentheses
  int flag = 0;
  int status = 0;
  int number = 0;
  int actual_parenthesis = 0;
  while (i >= 0 && (size_t)i < str.size() && !status) {
    switch (str[i]) {
    case '(':
      if (!actual_parenthesis) {
        actual_parenthesis = LEFT_PARENTHESIS;
      } else {
        if (actual_parenthesis == RIGHT_PARENTHESIS) {
          status = 1;
        }
      }
      break;
    case ')':
      if (!actual_parenthesis) {
        actual_parenthesis = RIGHT_PARENTHESIS;
      } else {
        if (actual_parenthesis == LEFT_PARENTHESIS) {
          status = 1;
        }
      }
      break;
    case '-':
      check_unary_operator_(
          str, i); // if there are no parentheses => operators are end of
                   // pre/post-mod expression; also checks for wrong parenthesis
      break;
    case '+':
    case '*':
    case '/':
    case '^':
      if (actual_parenthesis !=
          parenthesis) // if there are no parentheses => operators are end of
                       // pre/post-mod expression; also checks for wrong
                       // parenthesis
        status = 1;
      break;
    case '~':
    case ' ':
      break;
    default:
      if (str[i] < 48 || str[i] > 57) {
        flag = 1;
      } else {
        ++number;
      }
      break;
    }
    if (parenthesis == RIGHT_PARENTHESIS) {
      --i;
    } else {
      ++i;
    }
  }
  if (!number)
    flag = 1;
  return flag;
}

int m_checker(std::string &str, int i) {
  int flag = 0;
  flag = m_check_core(str, i - 1, RIGHT_PARENTHESIS);
  if (!flag) {
    flag = m_check_core(str, i + 3, LEFT_PARENTHESIS);
  }
  return flag;
}

int func_checker(std::string &string, int i) { // check if funcs are legit
  int flag = 0;
  int number = 0;
  char func[255] = {0};
  int x = 0;
  for (; string[i] != '('; x++) {
    if (!string[i] || string[i] == '\n') {
      flag = 1;
      break;
    }
    func[x] = string[i];
    ++i;
  }
  for (int q = i + 1; string[q] != 0 && string[q] != '\n' && string[q] != ')';
       q++) {
    if (strchr("0123456789xX.,", string[q]) != NULL) {
      number = 1;
      break;
    }
  }
  if (!flag) {
    func[x] = string[i];
    switch (func[0]) {
    case 's':
      if (strcmp(func, "sin(") != 0 && strcmp(func, "sqrt(") != 0) {
        flag = 1;
      }
      break;
    case 'c':
      if (strcmp(func, "cos(") != 0) {
        flag = 1;
      }
      break;
    case 'a':
      if (strcmp(func, "acos(") != 0 && strcmp(func, "asin(") != 0 &&
          strcmp(func, "atan(") != 0) {
        flag = 1;
      }
      break;
    case 't':
      if (strcmp(func, "tan(") != 0) {
        flag = 1;
      }
      break;
    case 'l':
      if (strcmp(func, "log(") != 0) {
        if (strcmp(func, "ln(") != 0) {
          flag = 1;
        }
      }
      break;
    }
  }
  if (!number)
    flag = 1;
  return flag;
}

int after_sign_checker(std::string &str, int i) {
  int flag = 0;
  int status = 0;
  if (i == 255) {
    flag = 1;
  } else {
    ++i;
    while (!flag && (size_t)i < str.size() && !status) {
      if (str[i] > 57 ||
          str[i] < 48) { // if after sign char is not a number, then...
        switch (str[i]) {
        case ' ':
          ++i;
          break;
        case 'x':
        case 'X':
        case 's': // funcs - check later, skip for now
        case 'c':
        case 'a':
        case 't':
        case 'l':
        case '(': // parenthesis - OK, break
        case ')':
          status = 1;
          break;
        default: // other - return error
          flag = 1;
          break;
        }
      } else { // if number -> ok
        break;
      }
    }
  }
  return flag;
}

int s21::Model::checker(std::string &str) {
  int equal = 0;
  int left_parenthesis = 0;
  int right_parenthesis = 0;
  int flag = 0;
  size_t i = 0;
  if ((int)str.size() > 255) {
    flag = 1;
  } else {
    for (; i < str.size() && !flag; ++i) {
      switch (str[i]) {
      case 'X':
      case 'x':
        flag = after_number_checker(str, i);
        break;
      case '=':
        equal++;
        break;
      case ' ':
      case '~':
        break;
      case '.':
        flag = after_number_checker(str, i);
        break;
      case ',':
        str[i] = '.';
        flag = after_number_checker(str, i);
        break;
      case '(':
        left_parenthesis++;
        break;
      case ')':
        right_parenthesis++;
        if (right_parenthesis > left_parenthesis) {
          flag = 1;
        }
        break;
      case 'm':
        flag = m_checker(str, i);
        i += 2;
        break;
      case 's':
      case 'a':
      case 'c':
      case 'l':
      case 't':
        flag = func_checker(str, i);
        while (i < str.size() && str[i] != '(') {
          ++i;
        }
        --i;
        break;
      case '-':
      case '+':
        check_unary_operator_(str, i);
        flag = after_sign_checker(str, i);
        break;
      case '/':
      case '*':
      case '^':
        flag = after_sign_checker(str, i);
        break;
      default:
        if (str[i] < 48 || str[i] > 57) {
          flag = 1;
        } else {
          flag = after_number_checker(str, i);
        }
        break;
      }
    }
    if (left_parenthesis != right_parenthesis || equal > 1)
      flag = 1;
  }
  return flag;
}
