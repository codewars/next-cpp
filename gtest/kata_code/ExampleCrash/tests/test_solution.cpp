#include <gtest/gtest.h>
#include <solution.h>

namespace {
  TEST(ExceptionTests, CrashInAssertion) {
    EXPECT_EQ(1, crashOrNot(0)) << "incorrect answer for crashOrNot(0)";
  }

  TEST(CrashTests, CrashOutsideOfAssertion) {
	int actual = crashOrNot(-13);
	EXPECT_EQ(actual, -12) << "Answer -12 is incorrect, but should not get here";
  }
}