///@brief This function creates the struct 'room' and allows the user
/// to fill in the data. It prompts the input of room name, exam name, exam date, rows, columns and occupancy rate
///@param void
///@return struct room

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"
#include "matrix.h"

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
room * allocate_new_room(room){
    room * new_room = (room *)malloc(sizeof(room));
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
    room * new_room = allocate_new_room(* new_room);

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

/* checks if year is valid
*  returns 1 if year is valid
*  returns 0 if year is invalid
*/
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

/* checks if month is valid
* returns 1 if month is valid
* returns 0 if month is invalid
*/
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

/* checks if day is valid
* returns 1 if day is valid
* returns 0 if day is invalid
*/
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

room *create_room()
{
    room *p_room = new_room();

    char input[MAX_STRING];
    int int_input; // Input variable for checking numeric input
    char *ptr;     // used for parsing string to int

    do
    {
        printf("Please enter room name\n"); // Room-infos are prompted one after another and written to room

        scanf(" %[^\n]", input);
        set_room_name(p_room, input);

        printf("Please enter exam name\n");
        scanf(" %[^\n]", input);
        set_exam_name(p_room, input);

        printf("Exam date: please enter year 'yyyy'\n"); // for all int: scan as string, parsed and checked if numeric
        p_room->exam_date.year = prompt_exam_date_year(); // copy into struct - other ints follow the same pattern

        printf("Exam date: please enter month 'mm'\n");
        p_room->exam_date.month = prompt_exam_date_month();

        printf("Exam date: please enter day 'dd'\n"); // ev. zu tun: mögliche Tagesanzahl des Monats überprüfen
        p_room->exam_date.day = prompt_exam_date_day();

        printf("Please enter number of rows in the classroom\n");
        scanf(" %s", input);
        while (1)
        {
            int_input = strtol(input, &ptr, 10);

            if (int_input == 0)
            {
                printf("Please enter valid number\n");
                scanf(" %s", input);
                continue;
            }
            if (int_input < 1)
            {   // less than 1 row/col not possible
                printf("Please enter valid number\n");
                scanf(" %s", input);
                continue;
            }
            else
            {
                break;
            }
        }
        p_room->row = int_input;

        printf("Please enter number of seats per row\n");
        scanf(" %s", input);
        while (1)
        {
            int_input = strtol(input, &ptr, 10);

            if (int_input == 0)
            {
                printf("Please enter valid number\n");
                scanf(" %s", input);
                continue;
            }
            if (int_input < 1)
            {
                printf("Please enter valid number\n");
                scanf(" %s", input);
                continue;
            }
            else
            {
                break;
            }
        }
        p_room->col = int_input;

        printf("Please enter occupancy rate:"); // Auslastung des Raumes
        printf("\n(1) for 100%%");
        printf("\n(2) for 50%%");
        printf("\n(3) for 25%%\n");

        scanf(" %s", input);
        while (1)
        {
            int_input = strtol(input, &ptr, 10);

            if (int_input == 0)
            {
                printf("Please enter valid number\n");
                scanf(" %s", input);
                continue;
            }
            if (int_input < 1 || int_input > 3)
            {
                printf("Please enter valid number\n");
                scanf(" %s", input);
                continue;
            }
            else
            {
                break;
            }
        }
        switch (int_input)
        {
        case 1:
            p_room->occupancy = 100;
            break;
        case 2:
            p_room->occupancy = 50;
            break;
        case 3:
            p_room->occupancy = 25;
            break;
        }


        printf("\nRoom name is: %s\n", p_room->room_name);
        printf("Exam: %s\n", p_room->exam_name);
        printf("Date of the exam: %d/%d/%d\n", p_room->exam_date.day, p_room->exam_date.month, p_room->exam_date.year);
        printf("Classroom size: %d x %d\n", p_room->row, p_room->col);
        printf("You want an occupancy rate of %d%%\n", p_room->occupancy);
        int num_seats = number_seats(p_room->row, p_room->col);
        int av_seats = available_seats(num_seats, p_room->occupancy);
        printf("You can fit %d students in the classroom\n", av_seats);

        // here the possibility to start over
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

int free_room(room *new_room)
{   // free memory of strings first, then of struct
    free(new_room->room_name);
    free(new_room->exam_name);
    free(new_room);
    return EXIT_SUCCESS;
}

//allocates memory for a new student_first_name
char * allocate_new_student_first_name(student * new_student)
{
    new_student->first_name = (char *)malloc(sizeof(char) * MAX_STRING);
    if (new_student->first_name == NULL)
    {
        perror("malloc");
    }

    return new_student->first_name;
}

//allocates memory for a new student_last_name
char * allocate_new_student_last_name(student * new_student)
{
    new_student->last_name = (char *)malloc(sizeof(char) * MAX_STRING);
    if (new_student->last_name == NULL)
    {
        perror("malloc");
    }

    return new_student->last_name;
}

//allocates memory for a new student_id
char * allocate_new_student_id(student * new_student)
{
    new_student->student_id = (char *)malloc(sizeof(char) * MAX_STRING);
    if (new_student->student_id == NULL)
    {
        perror("malloc");
    }

    return new_student->student_id;
}

//allocates memory for a new student
student * allocate_new_student()
{
    student *new_student;
    new_student = (student *)malloc(sizeof(student));
    if (new_student == NULL)
    {
        perror("malloc");
    }

    return new_student;
}

int available_seats(int num_seats, int occupancy) {
    int av_seats = num_seats * (occupancy * 0.01);
    if (num_seats < 1 || occupancy < 1) {
        av_seats = -1;
    }
    if (num_seats < 4 && occupancy == 25) {
        av_seats = 1;
    }
    return av_seats;
}

//creates a new student and returns a pointer to it
student *create_student(student *st_head)
{
    student *new_student;
    char input[MAX_STRING];
    int int_input;
    char *ptr;
    student *head = NULL;    
    student *current = NULL;
        if (st_head != NULL) {              // If the student list has already been started, we append the new students
        head = st_head;
        current = head;
        while(current->next != NULL) {
            current = current->next;
        }
    }

    do
    {   // loop to create students for the list

        new_student = allocate_new_student();
        new_student->first_name = allocate_new_student_first_name(new_student);
        new_student->last_name = allocate_new_student_last_name(new_student);
        new_student->student_id = allocate_new_student_id(new_student);

        new_student->next = NULL;

        do
        {
            printf("Please enter student's first name(s)\n");
            scanf(" %[^\n]", input);
            if ((strcpy(new_student->first_name, input)) == NULL)
            {
                perror("strcpy");
            }

            printf("Please enter student's last name(s)\n");
            scanf(" %[^\n]", input);
            if ((strcpy(new_student->last_name, input)) == NULL)
            {
                perror("strcpy");
            }

            printf("Please enter student's ID number\n");
            scanf(" %[^\n]", input);
            if ((strcpy(new_student->student_id, input)) == NULL)
            {
                perror("strcpy");
            }

            /* Here comes the function that assigns the seat (row/col) to the student*/

            printf("\nThe student's name is: %s %s\n", new_student->first_name, new_student->last_name);
            printf("Their ID is: %s\n", new_student->student_id);

            printf("\n\nAre you happy with your input?\nIf you want to delete your input and start again, enter (n)\nIf your input is correct, enter (y)\n");
            scanf(" %s", input);
            while (strcmp(input, "y") != 0 && strcmp(input, "n") != 0)
            {
                printf("Input invalid, please enter (y) or (n)\n");
                scanf(" %s", input);
            }

        } while (strcmp(input, "y") != 0);

        if (head == NULL)
        {
            head = new_student;
            current = new_student;
        }
        else
        {
            current->next = new_student;
            current = new_student;
        }

        printf("\nDo you want to add another student?\nEnter (y) or (n)\n");
        scanf(" %s", input);
        while (strcmp(input, "y") != 0 && strcmp(input, "n") != 0)
        {
            printf("Input invalid, please enter (y) or (n)\n");
            scanf(" %s", input);
        }

    } while (strcmp(input, "n") != 0);

    return head;
}

int free_student(student *new_student)
{
    student *temp = new_student;

    while (new_student != NULL)
    {
        free(new_student->first_name);
        free(new_student->last_name);
        free(new_student->student_id);
        temp = new_student;
        new_student = new_student->next;
        free(temp);
    }
    return EXIT_SUCCESS;
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
