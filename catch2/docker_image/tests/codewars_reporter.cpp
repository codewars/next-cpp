#include <catch2/reporters/catch_reporter_helpers.hpp>
#include <catch2/reporters/catch_reporter_streaming_base.hpp>
#include <catch2/catch_test_case_info.hpp>
#include <catch2/reporters/catch_reporter_registrars.hpp>
#include <catch2/catch_timer.hpp>

#include <iostream>
#include <string>

// TODO Complete custom reporter
// - https://github.com/catchorg/Catch2/blob/devel/docs/reporters.md
// - https://github.com/catchorg/Catch2/blob/devel/docs/reporter-events.md
// - https://github.com/catchorg/Catch2/blob/devel/docs/test-cases-and-sections.md
class CodewarsReporter : public Catch::StreamingReporterBase {
	
private:
	unsigned nestedSections = 0;
	
public:
    using StreamingReporterBase::StreamingReporterBase;

	CodewarsReporter( Catch::ReporterConfig&& config ):
		StreamingReporterBase( CATCH_MOVE(config) ) {
		// This is necessary to emit <COMPLETEDIN::> to syntetic, per-assertion IT's
		m_preferences.shouldReportAllAssertions = true;
	}

    static std::string getDescription() {
        return "Reporter for Codewars";
    }

    // Emitted before the first test case is executed.
    void testRunStarting(Catch::TestRunInfo const& testRunInfo) override {
        std::cout << "\ntestRunStarting " << testRunInfo.name << '\n';
    }

    // Emitted after all the test cases have been executed.
    void testRunEnded(__attribute__((unused)) Catch::TestRunStats const& testRunStats) override {
        std::cout << "\ntestRunEnded\n";
    }

    void sectionStarting(Catch::SectionInfo const& sectionInfo) override {        
		// Do not emit groups for implicit sections, put results in
		// the related test case (or test case partial)
		if(nestedSections++ <= 0)
			return;
        std::cout << "\n<DESCRIBE::>[S]" << sectionInfo.name << '\n';
    }

    void sectionEnded(__attribute__((unused)) Catch::SectionStats const& sectionStats) override {
		if(--nestedSections <= 0)
			return;
        std::cout << "\n<COMPLETEDIN::>\n";
    }

    void testCaseStarting(Catch::TestCaseInfo const& testInfo) override {
        std::cout << "\n<DESCRIBE::>[TC]" << testInfo.name << '\n';
    }

    void testCaseEnded(__attribute__((unused)) Catch::TestCaseStats const& testCaseStats) override {
        std::cout << "\n<COMPLETEDIN::>\n";
    }

    void testCasePartialStarting(Catch::TestCaseInfo const& testInfo, uint64_t partNumber) override {
        std::cout << "\n<DESCRIBE::>[TCP]" << testInfo.name << '#' << partNumber << '\n';
    }

    void testCasePartialEnded(__attribute__((unused)) Catch::TestCaseStats const& testCaseStats, __attribute__((unused)) uint64_t partNumber) override {
        std::cout << "\n<COMPLETEDIN::>\n";
    }
	
	void assertionStarting(__attribute__((unused)) Catch::AssertionInfo const& assertionInfo ) override {
		std::cout << "\n<IT::>Assertion: " << assertionInfo.macroName << "(" << assertionInfo.capturedExpression << ")\n";
	}
	void assertionEnded(Catch::AssertionStats const& assertionStats ) override {
		const Catch::AssertionResult& result = assertionStats.assertionResult;
		std::string resultTag = result.succeeded() ? "PASSED" : "FAILED";
		std::string message = result.hasMessage() ? static_cast<std::string>(result.getMessage()) : (result.succeeded() ? "Test passed" : "Test failed");
		std::cout << "\n<" << resultTag << "::>" << message << "\n";
		std::cout << "\n<COMPLETEDIN::>\n";
	}
	
};


CATCH_REGISTER_REPORTER("codewars", CodewarsReporter)