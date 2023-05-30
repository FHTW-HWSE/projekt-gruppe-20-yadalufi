#define CATCH_CONFIG_MAIN // This tells Catch2 to generate a main function for the tests
#include <catch2/catch.hpp>
#include "../src/matrix.h"
#include "../src/file.h"
/*
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
*/

TEST_CASE("number_seats valid input") {
    GIVEN("row = 3, col = 3") {
        int row = 3;
        int col = 3;
        
        WHEN("call number_seats") {
            int result = number_seats(row, col);

            THEN("result should be 9"){
            REQUIRE(result == 9);
            }
        }
    }
    GIVEN("row = 155, col = 324") {
        int row = 155;
        int col = 324; 
            WHEN("call number_seats") {
                int result = number_seats(row, col);
                THEN("result should be 50220") {
                    REQUIRE(result == 50220);
                }
           }
    }
        GIVEN("row = 1, col = 1") {
        int row = 1;
        int col = 1; 
            WHEN("call number_seats") {
                int result = number_seats(row, col);
                THEN("result should be 1") {
                    REQUIRE(result == 1);
                }
           }
    }
}

TEST_CASE("number_seats invalid input") {
    GIVEN("row = 0, col = 3") {
        int row = 0;
        int col = 3;
        
        WHEN("call number_seats") {
            int result = number_seats(row, col);

            THEN("result should be -1"){
            REQUIRE(result == -1);
            }
        }
    }
    GIVEN("row = 2, col = 0") {
        int row = 2;
        int col = 0; 
            WHEN("call number_seats") {
                int result = number_seats(row, col);
                THEN("result should be -1") {
                    REQUIRE(result == -1);
                }
           }
    }

        GIVEN("row = 0, col = 0") {
        int row = 0;
        int col = 0; 
            WHEN("call number_seats") {
                int result = number_seats(row, col);
                THEN("result should be -1") {
                    REQUIRE(result == -1);
                }
           }
    }

        GIVEN("row = -2, col = 0") {
        int row = -2;
        int col = 0; 
            WHEN("call number_seats") {
                int result = number_seats(row, col);
                THEN("result should be -1") {
                    REQUIRE(result == -1);
                }
           }
    }

        GIVEN("row = -45, col = -23.2") {
        int row = -45;
        int col = -23.2; 
            WHEN("call number_seats") {
                int result = number_seats(row, col);
                THEN("result should be -1") {
                    REQUIRE(result == -1);
                }
           }
    }
}

TEST_CASE("available_seats valid input") {
    GIVEN("num_seats = 20, occupancy = 50") {
        int num_seats = 20;
        room *p;
        p->occupancy = 50;
    //    int occupancy = 50;

        WHEN("call available_seats") {
            int result = available_seats(num_seats, p->occupancy);

            THEN("result should be 10") {
                REQUIRE(result == 10);
            }
        }
    }
    GIVEN("num_seats = 234, occupancy = 25") {
        int num_seats = 234;
        int occupancy = 25;

        WHEN("call available_seats") {
            int result = available_seats(num_seats, occupancy);

            THEN("result should be 58") {
                REQUIRE(result == 58);
            }
        }
    }

        GIVEN("num_seats = 32, occupancy = 100") {
        int num_seats = 32;
        int occupancy = 100;

        WHEN("call available_seats") {
            int result = available_seats(num_seats, occupancy);

            THEN("result should be 32") {
                REQUIRE(result == 32);
            }
        }
    }

        GIVEN("num_seats = 2, occupancy = 25") {
        int num_seats = 2;
        int occupancy = 25;

        WHEN("call available_seats") {
            int result = available_seats(num_seats, occupancy);

            THEN("result should be 1") {
                REQUIRE(result == 1);
            }
        }
    }
}

TEST_CASE("available_seats invalid input") {
    GIVEN("num_seats = 0, occupancy = 100") {
        int num_seats = 0;
        int occupancy = 100; 

        WHEN ("call available_seats"){
            int result = available_seats(num_seats, occupancy);

            THEN("result should be -1"){
                REQUIRE(result == -1);
            }
        }
    }

        GIVEN("num_seats = -5, occupancy = 100") {
        int num_seats = -5;
        int occupancy = 100; 

        WHEN ("call available_seats"){
            int result = available_seats(num_seats, occupancy);

            THEN("result should be -1"){
                REQUIRE(result == -1);
            }
        }
    }

            GIVEN("num_seats = 40, occupancy = 0") {
        int num_seats = 40;
        int occupancy = 0; 

        WHEN ("call available_seats"){
            int result = available_seats(num_seats, occupancy);

            THEN("result should be -1"){
                REQUIRE(result == -1);
            }
        }
    }
}

TEST_CASE("valid_input_year valid input") {
    GIVEN("input = 2023") {
        int input = 2023;

        WHEN ("call valid_input_year"){
            int result = valid_input_year(input);

            THEN("result should be 1"){
                REQUIRE(result == 1);
            }
        }
    }
}