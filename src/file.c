///@brief This function creates the struct 'room' and allows the user
/// to fill in the data. It prompts the input of room name, exam name, exam date, rows, columns and occupancy rate
///@param void
///@return struct room

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs/student.h"

typedef struct
{
    int year;
    int month;
    int day;
} date;

typedef struct
{
    char *room_name;
    char *exam_name;
    date exam_date;
    int row;
    int col;
    int occupancy;
} room;

typedef struct student
{
    char *first_name;
    char *last_name;
    char *student_id;
    int col;
    int row;
    struct student *next;
} student;

#define MAX_STRING 250
#define MIN_YEAR 2023
#define MAX_YEAR 2100

room *create_room();
int free_room(room *new_room);
student *create_student();
int free_student(student *new_student);

room *create_room()
{
    room *new_room = malloc(sizeof(room)); // Vor Beginn der Eingabe: allozieren des Speichers für
    if (new_room == NULL)
    { // das Struct und die 2 Strings
        perror("malloc");
    }

    new_room->room_name = malloc(sizeof(char) * MAX_STRING);
    if (new_room->room_name == NULL)
    {
        perror("malloc");
    }

    new_room->exam_name = malloc(sizeof(char) * MAX_STRING);
    if (new_room->exam_name == NULL)
    {
        perror("malloc");
    }

    char input[MAX_STRING];
    int int_input; // Input-Variable für die Eingabeüberprüfung bei Zahlen
    char *ptr;     // benötigt fürs Parsen v. String nach Integer

    do
    {
        printf("Please enter room name\n"); // Nacheinander werden die Room-Infos abgefragt und befüllt

        scanf(" %[^\n]", input);
        if ((strcpy(new_room->room_name, input)) == NULL)
        {
            perror("strcpy");
        }

        printf("Please enter exam name\n");
        scanf(" %[^\n]", input);

        if ((strcpy(new_room->exam_name, input)) == NULL)
        {
            perror("strcpy");
        }

        printf("Exam date: please enter year 'yyyy'\n"); // für alle Integers: scan als String, parsen und Überprüfung, ob Zahl
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
            if (int_input < MIN_YEAR || int_input > MAX_YEAR)
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
        new_room->exam_date.year = int_input; // ins Struct kopieren, die anderen Integers folgen demselben Schema

        printf("Exam date: please enter month 'mm'\n");
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
            if (int_input < 1 || int_input > 12)
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
        new_room->exam_date.month = int_input;

        printf("Exam date: please enter day 'dd'\n"); // ev. zu tun: mögliche Tagesanzahl des Monats überprüfen
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
            if (int_input < 1 || int_input > 31)
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
        new_room->exam_date.day = int_input;

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
            { // weniger als 1 Reihe/Spalte nicht möglich
                printf("Please enter valid number\n");
                scanf(" %s", input);
                continue;
            }
            else
            {
                break;
            }
        }
        new_room->row = int_input;

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
        new_room->col = int_input;

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
            new_room->occupancy = 100;
            break;
        case 2:
            new_room->occupancy = 50;
            break;
        case 3:
            new_room->occupancy = 25;
            break;
        }

        printf("\nRoom name is: %s\n", new_room->room_name);
        printf("Exam: %s\n", new_room->exam_name);
        printf("Date of the exam: %d/%d/%d\n", new_room->exam_date.day, new_room->exam_date.month, new_room->exam_date.year);
        printf("Classroom size: %d x %d\n", new_room->row, new_room->col);
        printf("You want an occupancy rate of %d%%\n", new_room->occupancy);
        int num_seats = (new_room->row * new_room->col) * (new_room->occupancy * 0.01);
        printf("You can fit %d students in the classroom\n", num_seats);

        // Hier die Möglichkeit, von Neuem zu beginnen
        printf("\n\nAre you happy with your input?\nIf you want to delete your input and start again, enter (n)\nIf your input is correct, enter (y)\n");
        scanf(" %s", input);
        while (strcmp(input, "y") != 0 && strcmp(input, "n") != 0)
        {
            printf("Input invalid, please enter (y) or (n)\n");
            scanf(" %s", input);
        }

    } while (strcmp(input, "y") != 0);

    return new_room;
}

int free_room(room *new_room)
{ // gibt zuerst den Speicher der Strings frei, dann jenen des Structs
    free(new_room->room_name);
    free(new_room->exam_name);
    free(new_room);
    return EXIT_SUCCESS;
}

student *create_student()
{

    student *new_student;
    char input[MAX_STRING];
    int int_input;
    char *ptr;
    student *head = NULL;
    student *current = NULL;

    do
    { // Schleife zum Erstellen der students für die Liste

        new_student = malloc(sizeof(student));
        if (new_student == NULL)
        {
            perror("malloc");
        }

        new_student->first_name = malloc(sizeof(char) * MAX_STRING);
        if (new_student->first_name == NULL)
        {
            perror("malloc");
        }

        new_student->last_name = malloc(sizeof(char) * MAX_STRING);
        if (new_student->last_name == NULL)
        {
            perror("malloc");
        }

        new_student->student_id = malloc(sizeof(char) * MAX_STRING);
        if (new_student->student_id == NULL)
        {
            perror("malloc");
        }

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