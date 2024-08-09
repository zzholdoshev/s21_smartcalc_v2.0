#include <gtest/gtest.h>

#include "../Model/Model.h"
using namespace s21;
TEST(SmartCalc, TestAllOperations) {
  s21::Model a;
  std::string str = "-1 sin(cos(asin(acos(1)))) * tan(atan(90))  * ln(log(100)) + 1 - 2^2^3 + 17 mod -5 + sqrt(9000) * (-1)"; // MOD with NEGATIVE number, several pows (for checking whether right-associative operation is implmented correctly, all trig funcs, log and sqrt
  double res;
	a.checker(str);
	a.parser(str);
	res = a.calculation();
  EXPECT_EQ((int)res, (int)-353.957067573);
}
TEST(SmartCalc, TestChecker) {
  s21::Model a;
	std::string str = "-1 + HAHA";
	int error = a.checker(str);

  EXPECT_EQ(error, 1);
}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
