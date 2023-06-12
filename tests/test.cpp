#define CATCH_CONFIG_MAIN // This tells Catch2 to generate a main function for the tests
#include <catch2/catch.hpp>
#include "../src/student.h"
#include "../src/file.h"
#include "../src/student.h"
#include "../src/contact_tracing.h"

/*
Tests for: 
- contact_tracing.cpp
reset_counter_vars  ok
find_student        ok

- file.cpp
valid_input_year    ok
valid_input_month   ok
valid_input_day     ok
number_seats        ok   
available_seats     ok
room_set_occupancy  ok

- student.cpp
seat_assignment     ok
number_students     ok
*/

/*Tests for contact_tracing.cpp functions*/

TEST_CASE("reset_counter_vars valid input") {
    GIVEN("i = 5, j = 6") {
        int i = 5;
        int j = 6;

        WHEN ("call reset_counter_vars"){
            int result = reset_counter_vars(&i, &j);

            THEN("result should be 0, i and j should be 0"){
                REQUIRE(result == 0);
                REQUIRE(i == 0);
                REQUIRE(j == 0);
            }
        }
    }
}

TEST_CASE("find_student valid input"){
    GIVEN("3 students, selection 2") {
        student * head = (student *)malloc(sizeof(student));
        student * two = (student *)malloc(sizeof(student));
        student * three = (student *)malloc(sizeof(student));
        head->next = two;
        two->next = three;
        three->next = NULL;
        int selection = 2;
        student * result = NULL;

        WHEN("call find_student") {
            result = find_student(head, selection);

            THEN("result should be student two"){
                REQUIRE(result == two);
                
                free(head);
                free(two);
                free(three);
            }
        }
    }

        GIVEN("6 students, selection 6") {
        student * head = (student *)malloc(sizeof(student));
        student * two = (student *)malloc(sizeof(student));
        student * three = (student *)malloc(sizeof(student));
        student * four = (student *)malloc(sizeof(student));
        student * five = (student *)malloc(sizeof(student));
        student * six = (student *)malloc(sizeof(student));
        head->next = two;
        two->next = three;
        three->next = four;
        four->next = five;
        five->next = six;
        six->next = NULL;
        int selection = 6;
        student * result = NULL;

        WHEN("call find_student") {
            result = find_student(head, selection);

            THEN("result should be student six"){
                REQUIRE(result == six);
                
                free(head);
                free(two);
                free(three);
                free(four);
                free(five);
                free(six);
            }
        }
    }

        GIVEN("6 students, selection 1") {
        student * head = (student *)malloc(sizeof(student));
        student * two = (student *)malloc(sizeof(student));
        student * three = (student *)malloc(sizeof(student));
        student * four = (student *)malloc(sizeof(student));
        student * five = (student *)malloc(sizeof(student));
        student * six = (student *)malloc(sizeof(student));
        head->next = two;
        two->next = three;
        three->next = four;
        four->next = five;
        five->next = six;
        six->next = NULL;
        int selection = 1;
        student * result = NULL;

        WHEN("call find_student") {
            result = find_student(head, selection);

            THEN("result should be student head"){
                REQUIRE(result == head);
                
                free(head);
                free(two);
                free(three);
                free(four);
                free(five);
                free(six);
            }
        }
    }
}

TEST_CASE("find_student invalid input"){
    GIVEN("3 students, selection 0") {
        student * head = (student *)malloc(sizeof(student));
        student * two = (student *)malloc(sizeof(student));
        student * three = (student *)malloc(sizeof(student));
        head->next = two;
        two->next = three;
        three->next = NULL;
        int selection = 0;
        student * result = NULL;

        WHEN("call find_student") {
            result = find_student(head, selection);

            THEN("result should be NULL"){
                REQUIRE(result == NULL);
                
                free(head);
                free(two);
                free(three);
            }
        }
    }

        GIVEN("6 students, selection 7") {
        student * head = (student *)malloc(sizeof(student));
        student * two = (student *)malloc(sizeof(student));
        student * three = (student *)malloc(sizeof(student));
        student * four = (student *)malloc(sizeof(student));
        student * five = (student *)malloc(sizeof(student));
        student * six = (student *)malloc(sizeof(student));
        head->next = two;
        two->next = three;
        three->next = four;
        four->next = five;
        five->next = six;
        six->next = NULL;
        int selection = 7;
        student * result = NULL;

        WHEN("call find_student") {
            result = find_student(head, selection);

            THEN("result should be NULL"){
                REQUIRE(result == NULL);
                
                free(head);
                free(two);
                free(three);
                free(four);
                free(five);
                free(six);
            }
        }
    }

        GIVEN("6 students, selection -1") {
        student * head = (student *)malloc(sizeof(student));
        student * two = (student *)malloc(sizeof(student));
        student * three = (student *)malloc(sizeof(student));
        student * four = (student *)malloc(sizeof(student));
        student * five = (student *)malloc(sizeof(student));
        student * six = (student *)malloc(sizeof(student));
        head->next = two;
        two->next = three;
        three->next = four;
        four->next = five;
        five->next = six;
        six->next = NULL;
        int selection = -1;
        student * result = NULL;

        WHEN("call find_student") {
            result = find_student(head, selection);

            THEN("result should be NULL"){
                REQUIRE(result == NULL);
                
                free(head);
                free(two);
                free(three);
                free(four);
                free(five);
                free(six);
            }
        }
    }
}

/*Tests for file.cpp functions*/

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
    GIVEN("input = 2100") {
        int input = 2100;
        WHEN("call valid_input_year") {
            int result = valid_input_year(input);
            THEN("result should be 1") {
                REQUIRE(result == 1);
            }
        }
    }
        GIVEN("input = 2050") {
        int input = 2050;
        WHEN("call valid_input_year") {
            int result = valid_input_year(input);
            THEN("result should be 1") {
                REQUIRE(result == 1);
            }
        }
    }
}

TEST_CASE("valid_input_year invalid input") {
    GIVEN("input = 2022") {
        int input = 2022;

        WHEN ("call valid_input_year"){
            int result = valid_input_year(input);

            THEN("result should be 0"){
                REQUIRE(result == 0);
            }
        }
    }
    GIVEN("input = 0") {
        int input = 0;
        WHEN("call valid_input_year") {
            int result = valid_input_year(input);
            THEN("result should be 0") {
                REQUIRE(result == 0);
            }
        }
    }
        GIVEN("input = -5") {
        int input = -5;
        WHEN("call valid_input_year") {
            int result = valid_input_year(input);
            THEN("result should be 0") {
                REQUIRE(result == 0);
            }
        }
    }
        GIVEN("input = 2101") {
        int input = 2101;
        WHEN("call valid_input_year") {
            int result = valid_input_year(input);
            THEN("result should be 0") {
                REQUIRE(result == 0);
            }
        }
    }
}

TEST_CASE("valid_input_month valid input") {
    GIVEN("input = 6") {
        int input = 6;

        WHEN ("call valid_input_month"){
            int result = valid_input_month(input);

            THEN("result should be 1"){
                REQUIRE(result == 1);
            }
        }
    }
        GIVEN("input = 1") {
        int input = 1;

        WHEN ("call valid_input_month"){
            int result = valid_input_month(input);

            THEN("result should be 1"){
                REQUIRE(result == 1);
            }
        }
    }
        GIVEN("input = 12") {
        int input = 12;

        WHEN ("call valid_input_month"){
            int result = valid_input_month(input);

            THEN("result should be 1"){
                REQUIRE(result == 1);
            }
        }
    }
}

TEST_CASE("valid_input_month invalid input") {
    GIVEN("input = 0") {
        int input = 0;

        WHEN ("call valid_input_month"){
            int result = valid_input_month(input);

            THEN("result should be 0"){
                REQUIRE(result == 0);
            }
        }
    }
        GIVEN("input = 13") {
        int input = 13;

        WHEN ("call valid_input_month"){
            int result = valid_input_month(input);

            THEN("result should be 0"){
                REQUIRE(result == 0);
            }
        }
    }
        GIVEN("input = -1") {
        int input = -1;

        WHEN ("call valid_input_month"){
            int result = valid_input_month(input);

            THEN("result should be 0"){
                REQUIRE(result == 0);
            }
        }
    }
        GIVEN("input = 100") {
        int input = 100;

        WHEN ("call valid_input_month"){
            int result = valid_input_month(input);

            THEN("result should be 0"){
                REQUIRE(result == 0);
            }
        }
    }
}

TEST_CASE("valid_input_day valid input") {
    GIVEN("input = 6") {
        int input = 6;

        WHEN ("call valid_input_day"){
            int result = valid_input_day(input);

            THEN("result should be 1"){
                REQUIRE(result == 1);
            }
        }
    }
    GIVEN("input = 1") {
        int input = 1;

        WHEN ("call valid_input_day"){
            int result = valid_input_day(input);

            THEN("result should be 1"){
                REQUIRE(result == 1);
            }
        }
    }
    GIVEN("input = 31") {
        int input = 31;

        WHEN ("call valid_input_day"){
            int result = valid_input_day(input);

            THEN("result should be 1"){
                REQUIRE(result == 1);
            }
        }
    }
}

TEST_CASE("valid_input_day invalid input") {
    GIVEN("input = 0") {
        int input = 0;

        WHEN ("call valid_input_day"){
            int result = valid_input_day(input);

            THEN("result should be 0"){
                REQUIRE(result == 0);
            }
        }
    }
    GIVEN("input = 32") {
        int input = 32;

        WHEN ("call valid_input_day"){
            int result = valid_input_day(input);

            THEN("result should be 0"){
                REQUIRE(result == 0);
            }
        }
    }
    GIVEN("input = -1") {
        int input = -1;

        WHEN ("call valid_input_day"){
            int result = valid_input_day(input);

            THEN("result should be 0"){
                REQUIRE(result == 0);
            }
        }
    }
    GIVEN("input = 5466") {
        int input = 5466;

        WHEN ("call valid_input_day"){
            int result = valid_input_day(input);

            THEN("result should be 0"){
                REQUIRE(result == 0);
            }
        }
    }
}



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

            THEN("result should be 63") {
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

TEST_CASE("room_set_occupancy valid input") {
    GIVEN("selection = 1") {
        int selection = 1;
        room * test_room = (room *)malloc(sizeof(room));

        WHEN("call room_set_occupancy") {
            int result = room_set_occupancy(test_room, selection);

            THEN("result should be 1, occupancy should be 100") {
                REQUIRE(result == 1);
                REQUIRE(test_room->occupancy == 100);

                free(test_room);
            }
        }
    }

        GIVEN("selection = 2") {
        int selection = 2;
        room * test_room = (room *)malloc(sizeof(room));

        WHEN("call room_set_occupancy") {
            int result = room_set_occupancy(test_room, selection);

            THEN("result should be 1, occupancy should be 50") {
                REQUIRE(result == 1);
                REQUIRE(test_room->occupancy == 50);

                free(test_room);
            }
        }
    }

        GIVEN("selection = 3") {
        int selection = 3;
        room * test_room = (room *)malloc(sizeof(room));

        WHEN("call room_set_occupancy") {
            int result = room_set_occupancy(test_room, selection);

            THEN("result should be 1, occupancy should be 25") {
                REQUIRE(result == 1);
                REQUIRE(test_room->occupancy == 25);

                free(test_room);
            }
        }
    }
}

TEST_CASE("room_set_occupancy invalid input") {
    GIVEN("selection = 0") {
        int selection = 0;
        room * test_room = (room *)malloc(sizeof(room));

        WHEN("call room_set_occupancy") {
            int result = room_set_occupancy(test_room, selection);

            THEN("result should be 0") {
                REQUIRE(result == 0);

                free(test_room);
            }
        }
    }

        GIVEN("selection = -1") {
        int selection = -1;
        room * test_room = (room *)malloc(sizeof(room));

        WHEN("call room_set_occupancy") {
            int result = room_set_occupancy(test_room, selection);

            THEN("result should be 0") {
                REQUIRE(result == 0);

                free(test_room);
            }
        }
    }

        GIVEN("selection = 4") {
        int selection = 4;
        room * test_room = (room *)malloc(sizeof(room));

        WHEN("call room_set_occupancy") {
            int result = room_set_occupancy(test_room, selection);

            THEN("result should be 0") {
                REQUIRE(result == 0);

                free(test_room);
            }
        }
    }
}

/*Tests for student.cpp functions*/

TEST_CASE ("seat_assignment valid input"){
    GIVEN("3 students, 9 seats, occupancy 100") {
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

            THEN("result should be 0; students should be assigned seats in the first row") {
                REQUIRE(result == 0);
                REQUIRE(head->row == 0);
                REQUIRE(head->col == 0);
                REQUIRE(two->row == 0);
                REQUIRE(two->col == 1);
                REQUIRE(three->row == 0);
                REQUIRE(three->col == 2);
                free(head);
                free(two);
                free(three);
                free(test_room);
            }
        }
    }

    GIVEN("3 students, 9 seats, occupancy 50") {
        student * head = (student *)malloc(sizeof(student));
        student * two = (student *)malloc(sizeof(student));
        student * three = (student *)malloc(sizeof(student));
        head->next = two;
        two->next = three;
        three->next = NULL;

        room * test_room = (room *)malloc(sizeof(room));
        test_room->col = 3;
        test_room->row = 3;
        test_room->occupancy = 50;

        WHEN("call seat_assignment") {
            int result = seat_assignment(head, test_room);

            THEN("result should be 0; students should be assigned seats 0/0, 0/2, 1/1") {
                REQUIRE(result == 0);
                REQUIRE(head->row == 0);
                REQUIRE(head->col == 0);
                REQUIRE(two->row == 0);
                REQUIRE(two->col == 2);
                REQUIRE(three->row == 1);
                REQUIRE(three->col == 1);
                free(head);
                free(two);
                free(three);
                free(test_room);
            }
        }
    }
    GIVEN("3 students, 9 seats, occupancy 25") {
        student * head = (student *)malloc(sizeof(student));
        student * two = (student *)malloc(sizeof(student));
        student * three = (student *)malloc(sizeof(student));
        head->next = two;
        two->next = three;
        three->next = NULL;

        room * test_room = (room *)malloc(sizeof(room));
        test_room->col = 3;
        test_room->row = 3;
        test_room->occupancy = 25;

        WHEN("call seat_assignment") {
            int result = seat_assignment(head, test_room);

            THEN("result should be 0; students should be assigned seats 0/0, 0/2, 2/0") {
                REQUIRE(result == 0);
                REQUIRE(head->row == 0);
                REQUIRE(head->col == 0);
                REQUIRE(two->row == 0);
                REQUIRE(two->col == 2);
                REQUIRE(three->row == 2);
                REQUIRE(three->col == 0);
                free(head);
                free(two);
                free(three);
                free(test_room);
            }
        }
    }

    GIVEN("30 students, 30 seats, occupancy 100") {
        student * head = (student *)malloc(sizeof(student));
        student * two = (student *)malloc(sizeof(student));
        student * three = (student *)malloc(sizeof(student));
        student * four = (student *)malloc(sizeof(student));
        student * five = (student *)malloc(sizeof(student));
        student * six = (student *)malloc(sizeof(student));
        student * seven = (student *)malloc(sizeof(student));
        student * eight = (student *)malloc(sizeof(student));
        student * nine = (student *)malloc(sizeof(student));
        student * ten = (student *)malloc(sizeof(student));
        student * eleven = (student *)malloc(sizeof(student));
        student * twelve = (student *)malloc(sizeof(student));
        student * thirteen = (student *)malloc(sizeof(student));
        student * fourteen = (student *)malloc(sizeof(student));
        student * fifteen = (student *)malloc(sizeof(student));
        student * sixteen = (student *)malloc(sizeof(student));
        student * seventeen = (student *)malloc(sizeof(student));
        student * eighteen = (student *)malloc(sizeof(student));
        student * nineteen = (student *)malloc(sizeof(student));
        student * twenty = (student *)malloc(sizeof(student));
        student * twentyone = (student *)malloc(sizeof(student)); 
        student * twentytwo = (student *)malloc(sizeof(student));
        student * twentythree = (student *)malloc(sizeof(student));
        student * twentyfour = (student *)malloc(sizeof(student));
        student * twentyfive = (student *)malloc(sizeof(student)); 
        student * twentysix = (student *)malloc(sizeof(student));
        student * twentyseven = (student *)malloc(sizeof(student));
        student * twentyeight = (student *)malloc(sizeof(student));
        student * twentynine = (student *)malloc(sizeof(student));
        student * thirty = (student *)malloc(sizeof(student));

        head->next = two;
        two->next = three;
        three->next = four;
        four->next = five;
        five->next = six;
        six->next = seven;
        seven->next = eight;
        eight->next = nine;
        nine->next = ten;
        ten->next = eleven;
        eleven->next = twelve;
        twelve->next = thirteen;
        thirteen->next = fourteen;
        fourteen->next = fifteen;
        fifteen->next = sixteen;
        sixteen->next = seventeen;
        seventeen->next = eighteen;
        eighteen->next = nineteen;
        nineteen->next = twenty;
        twenty->next = twentyone;
        twentyone->next = twentytwo;
        twentytwo->next = twentythree;
        twentythree->next = twentyfour;
        twentyfour->next = twentyfive;
        twentyfive->next = twentysix;
        twentysix->next = twentyseven;
        twentyseven->next = twentyeight;
        twentyeight->next = twentynine;
        twentynine->next = thirty;
        thirty->next = NULL;

        room * test_room = (room *)malloc(sizeof(room));
        test_room->row = 5;
        test_room->col = 6;
        test_room->occupancy = 100;

        WHEN("call seat_assignment") {
            int result = seat_assignment(head, test_room);

            THEN("result should be 0; students should be assigned seats 0/0 - 4/5") {
                REQUIRE(result == 0);
                REQUIRE(head->row == 0);
                REQUIRE(head->col == 0);
                REQUIRE(two->row == 0);
                REQUIRE(two->col == 1);
                REQUIRE(three->row == 0);
                REQUIRE(three->col == 2);
                REQUIRE(four->row == 0);
                REQUIRE(four->col == 3);
                REQUIRE(five->row == 0);
                REQUIRE(five->col == 4);
                REQUIRE(six->row == 0);
                REQUIRE(six->col == 5);
                REQUIRE(seven->row == 1);
                REQUIRE(seven->col == 0);
                REQUIRE(eight->row == 1);
                REQUIRE(eight->col == 1);
                REQUIRE(nine->row == 1);
                REQUIRE(nine->col == 2);
                REQUIRE(ten->row == 1);
                REQUIRE(ten->col == 3);
                REQUIRE(eleven->row == 1);
                REQUIRE(eleven->col == 4);
                REQUIRE(twelve->row == 1);
                REQUIRE(twelve->col == 5);
                REQUIRE(thirteen->row == 2);
                REQUIRE(thirteen->col == 0);
                REQUIRE(fourteen->row == 2);
                REQUIRE(fourteen->col == 1);
                REQUIRE(fifteen->row == 2);
                REQUIRE(fifteen->col == 2);
                REQUIRE(sixteen->row == 2);
                REQUIRE(sixteen->col == 3);
                REQUIRE(seventeen->row == 2);
                REQUIRE(seventeen->col == 4);
                REQUIRE(eighteen->row == 2);
                REQUIRE(eighteen->col == 5);
                REQUIRE(nineteen->row == 3);
                REQUIRE(nineteen->col == 0);
                REQUIRE(twenty->row == 3);
                REQUIRE(twenty->col == 1);
                REQUIRE(twentyone->row == 3);
                REQUIRE(twentyone->col == 2);
                REQUIRE(twentytwo->row == 3);
                REQUIRE(twentytwo->col == 3);
                REQUIRE(twentythree->row == 3);
                REQUIRE(twentythree->col == 4);
                REQUIRE(twentyfour->row == 3);
                REQUIRE(twentyfour->col == 5);
                REQUIRE(twentyfive->row == 4);
                REQUIRE(twentyfive->col == 0);
                REQUIRE(twentysix->row == 4);
                REQUIRE(twentysix->col == 1);
                REQUIRE(twentyseven->row == 4);
                REQUIRE(twentyseven->col == 2);
                REQUIRE(twentyeight->row == 4);
                REQUIRE(twentyeight->col == 3);
                REQUIRE(twentynine->row == 4);
                REQUIRE(twentynine->col == 4);
                REQUIRE(thirty->row == 4);
                REQUIRE(thirty->col == 5);
                
                free(head); free(two);  free(three);    free(four); free(five);
                free(six); free(seven); free(eight);    free(nine); free(ten);
                free(eleven);   free(twelve);   free(thirteen); free(fourteen); free(fifteen);
                free(sixteen);  free(seventeen);    free(eighteen); free(nineteen); free(twenty);
                free(twentyone);    free(twentytwo);    free(twentythree);  free(twentyfour);   free(twentyfive);
                free(twentysix);    free(twentyseven);  free(twentyeight);  free(twentynine);   free(thirty);
                 
                free(test_room);
            }
        }
    }
}

TEST_CASE ("seat_assignment invalid input"){
    GIVEN("no students, 9 seats, occupancy 100") {
        student * head = NULL;


        room * test_room = (room *)malloc(sizeof(room));
        test_room->row = 3;
        test_room->col = 3;
        test_room->occupancy = 100;

        WHEN("call seat_assignment") {
            int result = seat_assignment(head, test_room);

            THEN("result should be 1") {
                REQUIRE(result == 1);
                free(head);
                free(test_room);
            }
        }
    }

    GIVEN("3 students, 9 seats, occupancy 0") {
        student * head = (student *)malloc(sizeof(student));
        student * two = (student *)malloc(sizeof(student));
        student * three = (student *)malloc(sizeof(student));
        head->next = two;
        two->next = three;
        three->next = NULL;

        room * test_room = (room *)malloc(sizeof(room));
        test_room->col = 3;
        test_room->row = 3;
        test_room->occupancy = 0;

        WHEN("call seat_assignment") {
            int result = seat_assignment(head, test_room);

            THEN("result should be 1") {
                REQUIRE(result == 1);
                free(head);
                free(two);
                free(three);
                free(test_room);
            }
        }
    }
}

TEST_CASE("number_students valid input") {
    GIVEN("list of 5 students") {
        student * head = (student *)malloc(sizeof(student));
        student * two = (student *)malloc(sizeof(student));
        student * three = (student *)malloc(sizeof(student));
        student * four = (student *)malloc(sizeof(student));
        student * five = (student *)malloc(sizeof(student));
        head->next = two;
        two->next = three;
        three->next = four;
        four->next = five;
        five->next = NULL;

        WHEN ("call number_students"){
            int result = number_students(head);

            THEN("result should be 5"){
                REQUIRE(result == 5);
                free(head);
                free(two);
                free(three);
                free(four);
                free(five);
            }
        }
    }

        GIVEN("list of 1 student") {
        student * head = (student *)malloc(sizeof(student));
        head->next = NULL;

        WHEN ("call number_students"){
            int result = number_students(head);

            THEN("result should be 1"){
                REQUIRE(result == 1);
                free(head);
            }
        }
    }
        GIVEN("empty list (head = NULL)") {
        student * head = NULL;

        WHEN ("call number_students"){
            int result = number_students(head);

            THEN("result should be 0"){
                REQUIRE(result == 0);
            }
        }
    }
    
}