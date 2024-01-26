#include <gtest/gtest.h>
#include <solution.h>

namespace {

  TEST(ExceptionTests, ExpectedThrownOutsideOfAssertion) {
	int actual = throwOrNot(7);
	EXPECT_EQ(actual, 8) << "Answer 8 is incorrect, but should not get here";
  }
  TEST(ExceptionTests, ExpectedNone_ActualNone) {
	int actval = 10;
	EXPECT_NO_THROW( actval = throwOrNot(2) ) << "throwOrNot(2) should not throw";
    EXPECT_EQ(actval, 3) << "incorrect answer for throwOrNot(2)";
  }
  TEST(ExceptionTests, ExpectedNone_ActualThrown) {
	int actval = 10;
	EXPECT_NO_THROW( actval = throwOrNot(7) ) << "throwOrNot(7) should not throw";
    EXPECT_EQ(actval, 8) << "incorrect answer for throwOrNot(7)";
  }
  TEST(ExceptionTests, ExpectedThrown_ActualNone) {
	EXPECT_ANY_THROW( throwOrNot(0) ) << "should throw for throwOrNot(7)";
  }  
  TEST(ExceptionTests, ExpectedThrown_ActualThrown) {
	EXPECT_ANY_THROW( throwOrNot(7) ) << "should throw for throwOrNot(7)";
  }  
}