#include <cstdio>
#include <cinttypes>
#include <string>

#include <gtest/gtest.h>

using ::std::fprintf;
using ::std::fflush;

using ::testing::EmptyTestEventListener;
using ::testing::InitGoogleTest;
using ::testing::Test;
using ::testing::TestCase;
using ::testing::TestSuite;
using ::testing::TestEventListeners;
using ::testing::TestInfo;
using ::testing::TestResult;
using ::testing::TestPartResult;
using ::testing::UnitTest;

namespace {
class QualifiedReporter : public EmptyTestEventListener {
 private:
  // Called before any test activity starts.
  void OnTestProgramStart(const UnitTest& /* unit_test */) override {
    // This line is used as a marker to separate the test outputs from the build outputs.
    fprintf(stdout, "--- Starting gtest\n");
    fflush(stdout);
  }

  void OnTestSuiteStart(const TestSuite& test_suite) override {
      fprintf(stdout, "\n<DESCRIBE::>%s\n", test_suite.name());
  }
  void OnTestSuiteEnd(const TestSuite& test_suite) override {
      fprintf(stdout, "\n<COMPLETEDIN::>%" PRId64 "\n", test_suite.elapsed_time());
      fflush(stdout);
  }

  void OnTestStart(const TestInfo& test_info) override {
    fprintf(stdout, "\n<IT::>%s\n", test_info.name());
    fflush(stdout);
  }

  // Called after a failed assertion or a SUCCEED() invocation.
  void OnTestPartResult(const TestPartResult& test_part_result) override {
    fprintf(stdout,
      "\n<%s::>%s\n",
      test_part_result.failed() ? "FAILED" : "PASSED",
      escape_lf(test_part_result.summary()).c_str()
    );
    fflush(stdout);
  }

  // Called after a test ends.
  void OnTestEnd(const TestInfo& test_info) override {
    const TestResult& result = *test_info.result();
    if (result.Passed()) {
      fprintf(stdout, "\n<PASSED::>Test Passed\n");
    }
    fprintf(stdout, "\n<COMPLETEDIN::>%" PRId64 "\n", result.elapsed_time());
    fflush(stdout);
  }

  // Called after all test activities have ended.
  void OnTestProgramEnd(const UnitTest& /* unit_test */) override {
    fflush(stdout);
  }

  std::string escape_lf(std::string str) {
    size_t start_pos = 0;
    while ((start_pos = str.find("\n", start_pos)) != std::string::npos) {
      str.replace(start_pos, 1, "<:LF:>");
      start_pos += 6;
    }
    return str;
  }
};
}

int main(int argc, char** argv) {
  InitGoogleTest(&argc, argv);
  UnitTest& unit_test = *UnitTest::GetInstance();
  // Remove the default console output listener from the list and
  // append the custom output listener to the list.
  TestEventListeners& listeners = unit_test.listeners();
  delete listeners.Release(listeners.default_result_printer());
  listeners.Append(new QualifiedReporter);
  return RUN_ALL_TESTS();
}
