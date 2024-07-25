#ifndef COMMON_
#define COMMON_
#include <QString>

class common_funcs {

public:
  int set_position(const QString &str, int i) {
    while (i > 0 && str.at(i) != '(') {
      --i;
    }
    return i + 1;
  }
};

#endif
