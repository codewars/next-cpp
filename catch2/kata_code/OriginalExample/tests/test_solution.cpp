#include <vector>

#include <preloaded.h>
#include <catch2/catch_test_macros.hpp>


TEST_CASE( "vectors can be sized and resized" ) {
    // For each section, vector v is anew:
    std::vector<int> v( 5 );

    REQUIRE( v.size() == 5 );
    REQUIRE( v.capacity() >= 5 );

    SECTION( "resizing bigger changes size and capacity" ) {
        v.resize( 10 );

        REQUIRE( v.size() == 10 );
        REQUIRE( v.capacity() >= 10 );
    }
    SECTION( "resizing smaller changes size but not capacity" ) {
        v.resize( 0 );

        REQUIRE( v.size() == 0 );
        REQUIRE( v.capacity() >= 5 );
    }
    SECTION( "reserving bigger changes capacity but not size" ) {
        v.reserve( 10 );

        REQUIRE( v.size() == 5 );
        REQUIRE( v.capacity() >= 10 );
    }

    SECTION( "reserving smaller does not change size or capacity" ) {
        v.reserve( 0 );

        REQUIRE( v.size() == 5 );
        REQUIRE( v.capacity() >= 5 );
    }
}

TEST_CASE("Counter") {
    SECTION("Decrement") {
        Counter c;
        REQUIRE(c.Decrement() == 0);
        REQUIRE(c.Increment() == 0);
        REQUIRE(c.Increment() == 1);
        REQUIRE(c.Increment() == 2);
        REQUIRE(c.Decrement() == 3);
    }
}