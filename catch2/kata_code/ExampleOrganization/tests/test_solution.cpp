#include <vector>

#include <preloaded.h>
#include <catch2/catch_test_macros.hpp>


TEST_CASE( "TestCase1" ) {
    
    REQUIRE( 5 == 5 );
    REQUIRE( 12 >= 5 );

    SECTION( "Outermost section 1" ) {
        REQUIRE( 10 == 10 );
        REQUIRE( 15 >= 10 );
		
		SECTION( "MidLevel section 11" ) {
			REQUIRE( 10 == 10 );
			REQUIRE( 15 >= 10 );
			
			SECTION( "Innermost section 111" ) {
				REQUIRE( 10 == 10 );
				REQUIRE( 15 >= 10 );
			}
			SECTION( "Innermost section 112" ) {
				REQUIRE( 10 == 10 );
				REQUIRE( 15 >= 10 );
			}
		}
		SECTION( "MidLevel section 21" ) {
			REQUIRE( 10 == 10 );
			REQUIRE( 15 >= 10 );
			
			SECTION( "Innermost section 121" ) {
				REQUIRE( 10 == 10 );
				REQUIRE( 15 >= 10 );
			}
			SECTION( "Innermost section 221" ) {
				REQUIRE( 10 == 10 );
				REQUIRE( 15 >= 10 );
			}
		}		
    }
    SECTION( "Outermost section 2" ) {
        REQUIRE( 10 == 10 );
        REQUIRE( 15 >= 10 );
		
		SECTION( "MidLevel section 12" ) {
			REQUIRE( 10 == 10 );
			REQUIRE( 15 >= 10 );
			
			SECTION( "Innermost section 112" ) {
				REQUIRE( 10 == 10 );
				REQUIRE( 15 >= 10 );
			}
			SECTION( "Innermost section 212" ) {
				REQUIRE( 10 == 10 );
				REQUIRE( 15 >= 10 );
			}
		}
		SECTION( "MidLevel section 22" ) {
			REQUIRE( 10 == 10 );
			REQUIRE( 15 >= 10 );
			
			SECTION( "Innermost section 122" ) {
				REQUIRE( 10 == 10 );
				REQUIRE( 15 >= 10 );
			}
			SECTION( "Innermost section 122" ) {
				REQUIRE( 10 == 10 );
				REQUIRE( 15 >= 10 );
			}
		}		
    }	
}

TEST_CASE( "TestCase2" ) {
    
    REQUIRE( 5 == 5 );
    REQUIRE( 12 >= 5 );

    SECTION( "Outermost section 1" ) {
        REQUIRE( 10 == 10 );
        REQUIRE( 15 >= 10 );
		
		SECTION( "MidLevel section 11" ) {
			REQUIRE( 10 == 10 );
			REQUIRE( 15 >= 10 );
			
			SECTION( "Innermost section 111" ) {
				REQUIRE( 10 == 10 );
				REQUIRE( 15 >= 10 );
			}
			SECTION( "Innermost section 112" ) {
				REQUIRE( 10 == 10 );
				REQUIRE( 15 >= 10 );
			}
		}
		SECTION( "MidLevel section 21" ) {
			REQUIRE( 10 == 10 );
			REQUIRE( 15 >= 10 );
			
			SECTION( "Innermost section 121" ) {
				REQUIRE( 10 == 10 );
				REQUIRE( 15 >= 10 );
			}
			SECTION( "Innermost section 221" ) {
				REQUIRE( 10 == 10 );
				REQUIRE( 15 >= 10 );
			}
		}		
    }
    SECTION( "Outermost section 2" ) {
        REQUIRE( 10 == 10 );
        REQUIRE( 15 >= 10 );
		
		SECTION( "MidLevel section 12" ) {
			REQUIRE( 10 == 10 );
			REQUIRE( 15 >= 10 );
			
			SECTION( "Innermost section 112" ) {
				REQUIRE( 10 == 10 );
				REQUIRE( 15 >= 10 );
			}
			SECTION( "Innermost section 212" ) {
				REQUIRE( 10 == 10 );
				REQUIRE( 15 >= 10 );
			}
		}
		SECTION( "MidLevel section 22" ) {
			REQUIRE( 10 == 10 );
			REQUIRE( 15 >= 10 );
			
			SECTION( "Innermost section 122" ) {
				REQUIRE( 10 == 10 );
				REQUIRE( 15 >= 10 );
			}
			SECTION( "Innermost section 122" ) {
				REQUIRE( 10 == 10 );
				REQUIRE( 15 >= 10 );
			}
		}		
    }	
}