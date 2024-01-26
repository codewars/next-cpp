#include <gtest/gtest.h>
#include <solution.h>
#include <utility>

namespace {
  TEST(FixedTests, test_0) {
    EXPECT_EQ(evenOrOdd(0), true) << "evenOrOdd(0)";
  }
  TEST(FixedTests, test_1) {
    EXPECT_EQ(evenOrOdd(1), false) << "evenOrOdd(1)";
  }
  TEST(FixedTests, test_minus_1) {
    EXPECT_EQ(evenOrOdd(-1), false) << "evenOrOdd(-1)";
  }

  typedef std::pair<int, bool> MyTestCase;
  class RandomTests: public ::testing::TestWithParam<MyTestCase> {
	public:
	int n;
	bool exp;
	
	void SetUp() override { 
		auto param = GetParam();
		n = param.first;
		exp = param.second;
	}
  };

  static std::vector<MyTestCase> generateTests() {
    std::vector<MyTestCase> cases;
	for(int i=0; i<5; ++i) {
		cases.push_back({ i * 2 + 540, true });
		cases.push_back({ i * 2 + 947, false});
	}
	return cases;
  }

  TEST_P(RandomTests, PassingCases) {
    EXPECT_EQ(evenOrOdd(n), exp) << "evenOrOdd(" << n << ")";
  }
  TEST_P(RandomTests, FailingCases) {
    EXPECT_EQ(evenOrOdd(n), true) << "evenOrOdd(" << n << ")";
  }  
  INSTANTIATE_TEST_SUITE_P(BasicForm,RandomTests,::testing::ValuesIn(generateTests()));
  INSTANTIATE_TEST_SUITE_P(WithNameGen,RandomTests,::testing::ValuesIn(generateTests()),
    [](const testing::TestParamInfo<MyTestCase>& info) {
      return "evenOrOdd_" + std::to_string(info.param.first);
    });
}