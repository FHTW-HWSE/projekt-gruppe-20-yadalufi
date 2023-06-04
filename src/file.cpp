#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"
#include "student.h"

#define MAX_STRING 250
#define MIN_YEAR 2023
#define MAX_YEAR 2100

// allocates memory for exam_name
char * allocate_exam_name(room * new_room){
    new_room->exam_name = (char*)malloc(sizeof(char) * MAX_STRING);
    if (new_room->exam_name == NULL) {
        perror("malloc");
    }
    return new_room->exam_name;
}

// allocates memory for room_name
char * allocate_room_name(room * new_room){
    new_room->room_name = (char *)malloc(sizeof(char) * MAX_STRING);
    if (new_room->room_name == NULL)
    {
        perror("malloc");
    }
    return new_room->room_name;
}

// allocates memory for new_room (struct room)
room * allocate_new_room(room * new_room){
    new_room = (room *)malloc(sizeof(room));
    if (new_room == NULL)
    {
        perror("malloc");
    }
    return new_room;
}

/* allocates memory for new_room (Struct room)
*  allocates memory for room_name and exam_name
*  returns new_room
*/
room *new_room()
{
    room * new_room = allocate_new_room(new_room);

    new_room->room_name = allocate_room_name(new_room);

    new_room->exam_name = allocate_exam_name(new_room);

    return new_room;
}

void set_room_name(room *p_room, char *name)
{
    if ((strcpy(p_room->room_name, name)) == NULL)
    {
        perror("strcpy");
    }
}

void set_exam_name(room *p_room, char *name)
{
    if ((strcpy(p_room->exam_name, name)) == NULL)
    {
        perror("strcpy");
    }
}

// checks if year is valid
// returns 1 if year is valid
// returns 0 if year is invalid
int valid_input_year(int input){
    if (input == 0)
    {
        printf("Please enter valid number\n");
        return 0;
    }
    if (input < MIN_YEAR || input > MAX_YEAR)
    {
        printf("Please enter valid number\n");
        return 0;
    }
    else
    {
        return 1;
    }
}

// reads input for year and checks if input is valid
int prompt_exam_date_year()
{
    char input[MAX_STRING];
    int int_input;
    char *ptr;
    int valid; 

    do {
        scanf(" %s", input);
        int_input = strtol(input, &ptr, 10);
        valid = valid_input_year(int_input);

    } while (valid == 0);

    return int_input;
}

// checks if month is valid
// returns 1 if month is valid
// returns 0 if month is invalid
int valid_input_month(int input){
    if (input == 0)
    {
        printf("Please enter valid number\n");
        return 0;
    }
    if (input < 1 || input > 12)
    {
        printf("Please enter valid number\n");
        return 0;
    }
    else
    {
        return 1;
    }
}

// reads input for month and checks if input is valid
int prompt_exam_date_month()
{
    char input[MAX_STRING];
    int int_input;
    char *ptr;

    int valid; 

    do {
        scanf(" %s", input);
        int_input = strtol(input, &ptr, 10);
        valid = valid_input_month(int_input);

    } while (valid == 0);

    return int_input;
}

// checks if day is valid
// returns 1 if day is valid
// returns 0 if day is invalid
int valid_input_day(int input){
    if (input == 0)
    {
        printf("Please enter valid number\n");
        return 0;
    }
    if (input < 1 || input > 31)
    {
        printf("Please enter valid number\n");
        return 0;
    }
    else
    {
        return 1;
    }
}

// reads input for day and checks if input is valid
int prompt_exam_date_day()
{
    char input[MAX_STRING];
    int int_input;
    char *ptr;

    int valid; 

    do {
        scanf(" %s", input);
        int_input = strtol(input, &ptr, 10);
        valid = valid_input_day(int_input);

    } while (valid == 0);

    return int_input;
}

room *create_room(room * r_room, student * r_head)
{
    room *p_room = r_room;

    char input[MAX_STRING];
    int int_input; // Input-Variable für die Eingabeüberprüfung bei Zahlen
    char *ptr;     // benötigt fürs Parsen v. String nach Integer

    do
    {
        printf("Please enter room name\nor (q) to cancel\n"); // Nacheinander werden die Room-Infos abgefragt und befüllt

        scanf(" %[^\n]", input);
        if (strcmp(input, "q") == 0) {
            return p_room;
        }
        p_room = new_room();
        set_room_name(p_room, input);

        printf("Please enter exam name\n");
        scanf(" %[^\n]", input);
        set_exam_name(p_room, input);

        printf("Exam date: please enter year 'yyyy'\n"); // für alle Integers: scan als String, parsen und Überprüfung, ob Zahl
        p_room->exam_date.year = prompt_exam_date_year(); // ins Struct kopieren, die anderen Integers folgen demselben Schema

        printf("Exam date: please enter month 'mm'\n");
        p_room->exam_date.month = prompt_exam_date_month();

        printf("Exam date: please enter day 'dd'\n"); // ev. zu tun: mögliche Tagesanzahl des Monats überprüfen
        p_room->exam_date.day = prompt_exam_date_day();

        printf("Please enter number of rows in the classroom\n");
        while (1)
        {
            scanf(" %s", input);
            int_input = strtol(input, &ptr, 10);

            if (int_input < 1)
            { // weniger als 1 Reihe/Spalte nicht möglich
                printf("Please enter valid number\n");
                continue;
            }

            break;
        }
        p_room->row = int_input;

        printf("Please enter number of seats per row\n");
        while (1)
        {
            scanf(" %s", input);
            int_input = strtol(input, &ptr, 10);

            if (int_input < 1)
            {
                printf("Please enter valid number\n");
                continue;
            }

            break;
        }
        p_room->col = int_input;

        printf("Please enter occupancy rate:"); // Auslastung des Raumes
        printf("\n(1) for 100%%");
        printf("\n(2) for 50%%");
        printf("\n(3) for 25%%\n");

        while (1)
        {
            scanf(" %s", input);
            int_input = strtol(input, &ptr, 10);

            if (int_input < 1 || int_input > 3)
            {
                printf("Please enter valid number\n");
                continue;
            }

            break;
        }

        room_set_occupancy(p_room, int_input);

        printf("\nRoom name is: %s\n", p_room->room_name);
        printf("Exam: %s\n", p_room->exam_name);
        printf("Date of the exam: %d/%d/%d\n", p_room->exam_date.day, p_room->exam_date.month, p_room->exam_date.year);
        printf("Classroom size: %d x %d\n", p_room->row, p_room->col);
        printf("You want an occupancy rate of %d%%\n", p_room->occupancy);
        int num_seats = number_seats(p_room->row, p_room->col);
        int av_seats = available_seats(p_room->row, p_room->col, p_room->occupancy);
        printf("You can fit %d students in the classroom\n", av_seats);

        // Falls es schon students gibt und die Platzanzahl zu gering wäre, muss man nochmal beginnen/aussteigen

        if (r_head != NULL) {
            int num_students = number_students(r_head);
            if (num_students > av_seats) {
                printf("\nThe room you created does not have enough seats for the students.\nPlease create an adequate room.\n");
                free_room(p_room);
                p_room = NULL;
                continue;
            }
        }

        // Hier die Möglichkeit, von Neuem zu beginnen
        printf("\n\nAre you happy with your input?\nIf you want to delete your input and start again, enter (n)\nIf your input is correct, enter (y)\n");
        scanf(" %s", input);
        while (strcmp(input, "y") != 0 && strcmp(input, "n") != 0)
        {
            printf("Input invalid, please enter (y) or (n)\n");
            scanf(" %s", input);
        }

    } while (strcmp(input, "y") != 0);

    return p_room;
}

int room_set_occupancy(room * p_room, int selection) {
    switch (selection)
    {
        case 1:
            p_room->occupancy = 100;
            return 1;
        case 2:
            p_room->occupancy = 50;
            return 1;
        case 3:
            p_room->occupancy = 25;
            return 1;
        default:
            return 0;
    }
}

int free_room(room *new_room)
{ // gibt zuerst den Speicher der Strings frei, dann jenen des Structs
    free(new_room->room_name);
    free(new_room->exam_name);
    free(new_room);
    return EXIT_SUCCESS;
}

int number_seats(int row, int col) {
    int seats = 0;

    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            seats++;
        }
    }

    if (row < 1 || col < 1) {
        seats = -1;
    }
    return seats;
}

int available_seats(int row, int col, int occupancy) {
    int av_seats = 0;
    switch (occupancy) {
        case 100: 
            av_seats = row * col;
            break;
        case 50: 
            av_seats = (row *col) / 2;
            if ((row * col) % 2 == 1) {
                av_seats++;
            }
            break;
        case 25: 
            for (int i = 0; i < row; i+=2) {
                for (int j = 0; j < col; j+=2) {
                    av_seats++;
                }
            }
            break;
        default: 
            return -1;
    }
    if (av_seats < 1) {
        return -1;
    } else {
    return av_seats;
    }
}



int show_room(room *rm, student *head)
{
    student *temp = head;
    int printed = 0;                                        // boolean for printing of "<empty>"
    printf("%s - %s (%d/%d/%d)\n\n", rm->room_name, rm->exam_name, rm->exam_date.day, rm->exam_date.month, rm->exam_date.year);

    for (int i = rm->row - 1; i >= 0; i--)                  // prints the rows from back to front
    {
        printf("%-10d", i + 1);
        for (int j = 0; j < rm->col; j++)                   // prints the name from left to right
        {
            for (temp = head; temp != NULL; temp = temp->next)
            {
                if (temp != NULL && temp->row == i && temp->col == j)
                {
                    char initial[3];
                    initial[0] = temp->first_name[0];
                    initial[1] = '.';
                    initial[2] = '\0';
                    printf("%2s %-30s", initial, temp->last_name);
                    printed = 1;
                }
            }
            if (printed == 0)
            {
                printf("%-32s", "<empty>");
            }
            printed = 0;
        }
        printf("\n%-10c", ' ');

        for (int j = 0; j < rm->col; j++)                   // prints the student id number from left to right
        {
            for (temp = head; temp != NULL; temp = temp->next)
            {
                if (temp != NULL && temp->row == i && temp->col == j)
                {
                    printf("%-30s %2c", temp->student_id, ' ');
                    printed = 1;
                }
            }
            if (printed == 0)
            {
                printf("%-32s", "       ");
            }
            printed = 0;
        }
        printf("\n\n");
    }
    printf("\n");

    return EXIT_SUCCESS;
}
