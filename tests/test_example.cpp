#define CATCH_CONFIG_MAIN // This tells Catch2 to generate a main function for the tests
#include <catch2/catch.hpp>
#include "../src/student.h"
#include "../src/file.h"
#include "../src/student.h"
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
    GIVEN("number of seats: 25, occupancy = 50") {
        room *p = (room *)malloc(sizeof(room));
        p->row = 5;
        p->col = 5;
        p->occupancy = 50;

        WHEN("call available_seats") {
            int result = available_seats(p->row, p->col, p->occupancy);

            THEN("result should be 13") {
                REQUIRE(result == 13);
            }
        }
    }

    GIVEN("number of seats: 221, occupancy = 25") {
        int row = 17;
        int col = 13;
        int occupancy = 25;

        WHEN("call available_seats") {
            int result = available_seats(row, col, occupancy);

            THEN("result should be 60") {
                REQUIRE(result == 63);
            }
        }
    }

    GIVEN("number of seats: 32, occupancy = 100") {
        int row = 8;
        int col = 4;
        int occupancy = 100;

        WHEN("call available_seats") {
            int result = available_seats(row, col, occupancy);

            THEN("result should be 32") {
                REQUIRE(result == 32);
            }
        }
    }

        GIVEN("number of seats: 2, occupancy = 25") {
        int row = 1;
        int col = 2;
        int occupancy = 25;

        WHEN("call available_seats") {
            int result = available_seats(row, col, occupancy);

            THEN("result should be 1") {
                REQUIRE(result == 1);
            }
        }
    }
}

TEST_CASE("available_seats invalid input") {
    GIVEN("number of seats: 0, occupancy = 100") {
        int row = 0;
        int col = 0;
        int occupancy = 100; 

        WHEN ("call available_seats"){
            int result = available_seats(row, col, occupancy);

            THEN("result should be -1"){
                REQUIRE(result == -1);
            }
        }
    }

    GIVEN("number of seats: -5, occupancy = 100") {
        int row = 1;
        int col = -5;
        int occupancy = 100; 

        WHEN ("call available_seats"){
            int result = available_seats(row, col, occupancy);

            THEN("result should be -1"){
                REQUIRE(result == -1);
            }
        }
    }

    GIVEN("num_seats = 40, occupancy = 0") {
        int row = 2;
        int col = 20;
        int occupancy = 0; 

        WHEN ("call available_seats"){
            int result = available_seats(row, col, occupancy);

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

TEST_CASE ("seat_assignment valid input"){
    GIVEN("3 students") {
        student * head = (student *)malloc(sizeof(student));
        student * two = (student *)malloc(sizeof(student));
        student * three = (student *)malloc(sizeof(student));
        head->next = two;
        two->next = three;
        three->next = NULL;

        room * test_room = (room *)malloc(sizeof(room));
        test_room->col = 3;
        test_room->row = 3;
        test_room->occupancy = 100;

        WHEN("call seat_assignment") {
            int result = seat_assignment(head, test_room);

            THEN("result should be 0") {
                REQUIRE(result == 0);
            }
        }
    }

    GIVEN("3 students") {
        student * head = (student *)malloc(sizeof(student));
        student * two = (student *)malloc(sizeof(student));
        student * three = (student *)malloc(sizeof(student));
        head->next = two;
        two->next = three;
        three->next = NULL;

        room * test_room = (room *)malloc(sizeof(room));
        test_room->col = 3;
        test_room->row = 3;
        test_room->occupancy = 100;

        WHEN("call seat_assignment") {
            seat_assignment(head, test_room);

            THEN("students should be assigned seats in the first row") {
                REQUIRE(head->row == 0);
                REQUIRE(head->col == 0);
                REQUIRE(two->row == 0);
                REQUIRE(two->col == 1);
                REQUIRE(three->row == 0);
                REQUIRE(three->col == 2);
            }
        }
    }
}