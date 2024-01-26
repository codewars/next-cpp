#include <gtest/gtest.h>
#include <solution.h>

namespace namespace1 {
	
	TEST(RegularTestSuite1, Test1) {
	  ASSERT_EQ(1, 2);
	}

	TEST(RegularTestSuite1, Test2) {
	  ASSERT_EQ(1, 2);
	}
	
	TEST(RegularTestSuite2, Test1) {
	  ASSERT_EQ(1, 2);
	}

	TEST(RegularTestSuite2, Test2) {
	  ASSERT_EQ(1, 2);
	}	
}

namespace namespace2 {
	
	TEST(RegularTestSuite1, Test1) {
	  ASSERT_EQ(1, 2);
	}

	TEST(RegularTestSuite1, Test2) {
	  ASSERT_EQ(1, 2);
	}
	
	TEST(RegularTestSuite2, Test1) {
	  ASSERT_EQ(1, 2);
	}

	TEST(RegularTestSuite2, Test2) {
	  ASSERT_EQ(1, 2);
	}	
}

namespace namepace3 {
	
	class TestFixtureClass1: public ::testing::Test {};
	class TestFixtureClass2: public ::testing::Test {};
	
	TEST_F(TestFixtureClass1, Test1) {
	  ASSERT_EQ(1, 2);
	}
	TEST_F(TestFixtureClass1, Test2) {
	  ASSERT_EQ(1, 2);
	}
	TEST_F(TestFixtureClass2, Test1) {
	  ASSERT_EQ(1, 2);
	}
	TEST_F(TestFixtureClass2, Test2) {
	  ASSERT_EQ(1, 2);
	}	
}

namespace namespace4 {
	
  typedef std::pair<int, bool> MyTestCase;
  class ParametrizedTestsFixture1: public ::testing::TestWithParam<MyTestCase> { };
  class ParametrizedTestsFixture2: public ::testing::TestWithParam<MyTestCase> { };

  static std::vector<MyTestCase> generateTests() {
    std::vector<MyTestCase> cases;
	for(int i=0; i<5; ++i) {
		cases.push_back({ i * 2 + 540, true });
		cases.push_back({ i * 2 + 947, false});
	}
	return cases;
  }

  TEST_P(ParametrizedTestsFixture1, TestsSet1) {
    ASSERT_EQ(1, 2);
  }
  TEST_P(ParametrizedTestsFixture1, TestsSet2) {
    ASSERT_EQ(1, 2);
  }
	TEST_P(ParametrizedTestsFixture2, TestsSet1) {
    ASSERT_EQ(1, 2);
  }
  TEST_P(ParametrizedTestsFixture2, TestsSet2) {
    ASSERT_EQ(1, 2);
  }  
  
  INSTANTIATE_TEST_SUITE_P(BasicForm,ParametrizedTestsFixture1,::testing::ValuesIn(generateTests()));
  INSTANTIATE_TEST_SUITE_P(WithNameGen,ParametrizedTestsFixture1,::testing::ValuesIn(generateTests()),
    [](const testing::TestParamInfo<MyTestCase>& info) {
      return "parameters_for_fixture1_are_" + std::to_string(info.param.first);
    });
  INSTANTIATE_TEST_SUITE_P(BasicForm,ParametrizedTestsFixture2,::testing::ValuesIn(generateTests()));
  INSTANTIATE_TEST_SUITE_P(WithNameGen,ParametrizedTestsFixture2,::testing::ValuesIn(generateTests()),
    [](const testing::TestParamInfo<MyTestCase>& info) {
      return "parameters_for_fixture2_are_" + std::to_string(info.param.first);
    });	
}