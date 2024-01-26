#include <vector>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <solution.h>

using namespace ::testing;

// Each assertion and matcher is presented with and
// without an optional failure message.

namespace {
  TEST(FailureMessageTests, Assertions) {
    EXPECT_TRUE( false );
    EXPECT_TRUE( false ) << "Tested assertion: EXPECT_TRUE";
    
    EXPECT_FALSE( true );
    EXPECT_FALSE( true ) << "Tested assertion: EXPECT_FALSE";
    
    EXPECT_EQ( alwaysFails(13), 42 );
    EXPECT_EQ( alwaysFails(13), 42 ) << "Tested assertion: EXPECT_EQ";
    
    EXPECT_NE( alwaysFails(42), 42 );
    EXPECT_NE( alwaysFails(42), 42 ) << "Tested assertion: EXPECT_NE";
    
    EXPECT_LT( alwaysFails(256), 42 );
    EXPECT_LT( alwaysFails(256), 42 ) << "Tested assertion: EXPECT_LT";
    
    EXPECT_STREQ( "13", "42" );
    EXPECT_STREQ( "13", "42" ) << "Tested assertion: EXPECT_STREQ";
    
    EXPECT_NEAR( (double)alwaysFails(13), 42.0, 1e-3 );
    EXPECT_NEAR( (double)alwaysFails(13), 42.0, 1e-3 ) << "Tested assertion: EXPECT_NEAR";
    
    EXPECT_PRED1( isEven, 13 );
    EXPECT_PRED1( isEven, 13 ) << "Tested assertion: EXPECT_PRED1";
  }

  TEST(FailureMessageTests, Matchers) {
    EXPECT_THAT( false, ::testing::IsTrue() );
    EXPECT_THAT( false, ::testing::IsTrue() ) << "Tested matcher: IsTrue";
    
    EXPECT_THAT( true, IsFalse() );
    EXPECT_THAT( true, IsFalse() ) << "Tested matcher: IsFalse";
    
    EXPECT_THAT( alwaysFails(13), Eq(42) );
    EXPECT_THAT( alwaysFails(13), Eq(42) ) << "Tested Matcher: Eq";
    
    EXPECT_THAT( alwaysFails(42), Ne(42) );
    EXPECT_THAT( alwaysFails(42), Ne(42) ) << "Tested matcher: Ne";
    
    EXPECT_THAT( alwaysFails(256), Lt(42) );
    EXPECT_THAT( alwaysFails(256), Lt(42) ) << "Tested matcher: Lt";
    
    EXPECT_THAT( "13", StrEq("42") );
    EXPECT_THAT( "13", StrEq("42") ) << "Tested matcher: StrEq";
    
    EXPECT_THAT( (double)alwaysFails(13), DoubleNear(42.0, 1e-3) );
    EXPECT_THAT( (double)alwaysFails(13), DoubleNear(42.0, 1e-3) ) << "Tested matcher: DoubleNear";
    
    EXPECT_THAT( std::vector<int>(2), ContainerEq(std::vector<int>(3)) );
    EXPECT_THAT( std::vector<int>(2), ContainerEq(std::vector<int>(3)) )  << "Tested matcher: ContainerEq";
    
    EXPECT_THAT( std::vector<int>{2}, WhenSorted(ContainerEq(std::vector<int>{3})));
    EXPECT_THAT( std::vector<int>{2}, WhenSorted(ContainerEq(std::vector<int>{3}))) << "Tested matcher: WhenSorted     ContainerEq";
  }
}