#define CATCH_CONFIG_MAIN // This tells Catch2 to generate a main function for the tests
#include <catch2/catch.hpp>

SCENARIO("mathematical addition") {
    GIVEN("are 1 & 2") {
        int a = 1;
        int b = 2;

        WHEN("adding 1 & 2") {
            int result = a + b;

            THEN("the sum should be 3") {
                REQUIRE(result == 3);
            }
        }
    }
}

TEST_CASE("Another test") {
    // ...
}
