#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"
#include "student.h"

#define MAX_STRING 250
#define MIN_YEAR 2023
#define MAX_YEAR 2100

/**
 * @brief      Allocates memory for exam_name
 *
 * @param      new_room  Pointer to the room structure
 *
 * @return     char*
 */
char *allocate_exam_name(room *new_room)
{
    new_room->exam_name = (char *)malloc(sizeof(char) * MAX_STRING);
    if (new_room->exam_name == NULL)
    {
        perror("malloc");
    }
    return new_room->exam_name;
}

/**
 * @brief      Allocates memory for room_name
 *
 * @param      new_room  Pointer to the room structure
 *
 * @return     char*
 */
char *allocate_room_name(room *new_room)
{
    new_room->room_name = (char *)malloc(sizeof(char) * MAX_STRING);
    if (new_room->room_name == NULL)
    {
        perror("malloc");
    }
    return new_room->room_name;
}

/**
 * @brief      Allocates memory for new_room (Struct room)
 *
 * @param      new_room  Pointer to the room structure
 *
 * @return     room*
 */
room *allocate_new_room(room *new_room)
{
    new_room = (room *)malloc(sizeof(room));
    if (new_room == NULL)
    {
        perror("malloc");
    }
    return new_room;
}

/**
 * @brief       Allocates memory for new_room (Struct room)
 *              Allocates memory for room_name and exam_name
 *
 * @return      room*
 */
room *new_room()
{
    room *new_room = allocate_new_room(new_room);

    new_room->room_name = allocate_room_name(new_room);

    new_room->exam_name = allocate_exam_name(new_room);

    return new_room;
}

/**
* @brief        Set the room name for a given room.
*
* @param        p_room Pointer to the room structure.
* @param        name   Pointer to the string containing the room name
 *
* @return       void
*/
void set_room_name(room *p_room, char *name)
{
    if ((strcpy(p_room->room_name, name)) == NULL)
    {
        perror("strcpy");
    }
}

/**
 * @brief       Sets the exam name for a given room.
 *
 * @param        p_room Pointer to the room structure.
 * @param        name   Pointer to the string containing the room name
 *
 * @return       void
 */
void set_exam_name(room *p_room, char *name)
{
    if ((strcpy(p_room->exam_name, name)) == NULL)
    {
        perror("strcpy");
    }
}

/**
 * @brief      Checks if year is valid
 *
 * @param      input  The input
 *
 * @return     int
 */
int valid_input_year(int input)
{
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

/**
 * @brief      Reads input for year and checks if input is valid
 *
 * @return     int
 */
int prompt_exam_date_year()
{
    char input[MAX_STRING];
    int int_input;
    char *ptr;
    int valid;

    do
    {
        scanf(" %s", input);
        int_input = strtol(input, &ptr, 10);
        valid = valid_input_year(int_input);

    } while (valid == 0);

    return int_input;
}

/**
 * @brief      Checks if month is valid
 *
 * @param      input  The input
 *
 * @return     int
 */
int valid_input_month(int input)
{
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

/**
 * @brief      Reads input for month and checks if input is valid
 *
 * @return     int
 */
int prompt_exam_date_month()
{
    char input[MAX_STRING];
    int int_input;
    char *ptr;

    int valid;

    do
    {
        scanf(" %s", input);
        int_input = strtol(input, &ptr, 10);
        valid = valid_input_month(int_input);

    } while (valid == 0);

    return int_input;
}

/**
 * @brief      Checks if day is valid
 *
 * @param      input  The input
 *
 * @return     int
 */
int valid_input_day(int input)
{
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

/**
 * @brief      Reads input for day and checks if input is valid
 *
 * @return     int
 */
int prompt_exam_date_day()
{
    char input[MAX_STRING];
    int int_input;
    char *ptr;

    int valid;

    do
    {
        scanf(" %s", input);
        int_input = strtol(input, &ptr, 10);
        valid = valid_input_day(int_input);

    } while (valid == 0);

    return int_input;
}

/**
 * @brief       Creates a new room with user input for room details.
 *
 * @param       r_room   Pointer to an existing room structure to be updated or NULL to create a new room.
 * @param       r_head   Pointer to the head of the student list.
 *
 * @return      room*
 */
room *create_room(room *r_room, student *r_head)
{
    room *p_room = r_room;

    char input[MAX_STRING];
    int int_input; // Input variable for checking numeric input
    char *ptr;     // used for parsing string to int

    do
    {
        printf("Please enter room name\n"); // Room-infos are prompted one after another and written to room

        scanf(" %[^\n]", input);
        if (strcmp(input, "q") == 0)
        {
            return p_room;
        }
        p_room = new_room();
        set_room_name(p_room, input);

        printf("Please enter exam name\n");
        scanf(" %[^\n]", input);
        set_exam_name(p_room, input);

        printf("Exam date: please enter year 'yyyy'\n");  // for all int: scan as string, parsed and checked if numeric
        p_room->exam_date.year = prompt_exam_date_year(); // copy into struct - other ints follow the same pattern

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
            { // less than 1 row/col not possible
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

        if (r_head != NULL)
        {
            int num_students = number_students(r_head);
            if (num_students > av_seats)
            {
                printf("\nThe room you created does not have enough seats for the students.\nPlease create an adequate room.\n");
                free_room(p_room);
                p_room = NULL;
                continue;
            }
        }

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

/**
 * @brief       Sets the occupancy rate of a room based on user input.
 *
 * @param       p_room     Pointer to the room structure.
 * @param       selection  The selection for the occupancy rate.
 *
 * @return      int
 */
int room_set_occupancy(room *p_room, int selection)
{
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

/**
 * @brief       Frees the memory occupied by a room structure.
 *
 * @param       new_room  Pointer to the room structure to free.
 *
 * @return      int
 */
int free_room(room *new_room)
{ // free memory of strings first, then of struct
    free(new_room->room_name);
    free(new_room->exam_name);
    free(new_room);
    return EXIT_SUCCESS;
}

/**
 * @brief       Calculates the number of seats in a room.
 *
 * @param       row  Number of rows in the room.
 * @param       col  Number of seats per row.
 *
 * @return      int
 */
int number_seats(int row, int col)
{
    int seats = 0;

    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            seats++;
        }
    }

    if (row < 1 || col < 1)
    {
        seats = -1;
    }
    return seats;
}

/**
 * @brief       Calculates the number of available seats in a room, according to user input for occupancy rate.
 *
 * @param       row        Number of rows in the room.
 * @param       col        Number of seats per row.
 * @param       occupancy  The occupancy rate of the room.
 *
 * @return      int
 */
int available_seats(int row, int col, int occupancy)
{
    int av_seats = 0;
    switch (occupancy)
    {
    case 100:
        av_seats = row * col;
        break;
    case 50:
        av_seats = (row * col) / 2;
        if ((row * col) % 2 == 1)
        {
            av_seats++;
        }
        break;
    case 25:
        for (int i = 0; i < row; i += 2)
        {
            for (int j = 0; j < col; j += 2)
            {
                av_seats++;
            }
        }
        break;
    default:
        return -1;
    }
    if (av_seats < 1)
    {
        return -1;
    }
    else
    {
        return av_seats;
    }
}

/**
 * @brief       Creates a new student structure.
 *
 * @param       st_head  Pointer to the head of the student list.
 *
 * @return      student*
 */
student *create_student(student *st_head)
{
    student *new_student;
    char input[MAX_STRING];
    int int_input;
    char *ptr;
    student *head = NULL;
    student *current = NULL;
    if (st_head != NULL)
    { // If the student list has already been started, we append the new students
        head = st_head;
        current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
    }

    do
    { // loop to create students for the list

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

/**
 * @brief       Displays the seating arrangement of a room along with student information.
 *
 * This function prints the room name, exam name, and exam date, followed by the seating arrangement
 * with corresponding student information. It iterates through the rows and columns of the room,
 * matching the coordinates with the students' positions. If a student is found at a particular position,
 * their initials and last name are printed. If a position is empty, "<empty>" is displayed.
 *
 * @param       rm    Pointer to the room structure.
 * @param       head  Pointer to the head of the student list.
 * @return      int
 */
int show_room(room *rm, student *head)
{
    student *temp = head;
    int printed = 0; // boolean for printing of "<empty>"
    printf("%s - %s (%d/%d/%d)\n", rm->room_name, rm->exam_name, rm->exam_date.day, rm->exam_date.month, rm->exam_date.year);
    printf("Rows: %d / Seats per row: %d \n\n", rm->row, rm->col);
    int i = 1;
    while (temp != NULL) {
        printf("%d. %s, %s\n", i, temp->last_name, temp->first_name);
        printf("\t\tID: %s\tSeat: %d/%d\n", temp->student_id, temp->row+1, temp->col+1);
        temp = temp->next;
        i++;
    }
    
/*
    for (int i = rm->row - 1; i >= 0; i--) // prints the rows from back to front
    {
        printf("%-10d", i + 1);
        for (int j = 0; j < rm->col; j++) // prints the name from left to right
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

        for (int j = 0; j < rm->col; j++) // prints the student id number from left to right
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
    }*/
    printf("\n\n");

    return EXIT_SUCCESS;
}

void show_seat_pattern(room * sp_room) {
    switch (sp_room->occupancy) {
        case 100: 
            for (int i = 0; i < sp_room->row; i++) {
                for(int j = 0; j < sp_room->col; j++) {
                    printf("   X   ");
                }
                printf("\n");
            }
            break;
        case 50: 
            for (int i = sp_room->row; i > 0; i--) {
                if (i%2 != 0) {
                    for(int j = 1; j <= sp_room->col; j++) {
                        if (j%2 != 0) {
                            printf("   X   ");
                        } else {
                            printf("   0   ");
                        }
                    }
                } else {
                    for (int j = 1; j <= sp_room->col; j++) {
                        if (j%2 != 0) {
                            printf("   0   ");
                        } else {
                            printf("   X   ");
                        }
                    }
                }
                printf("\n");
            }
            break;
        case 25:
            for (int i = sp_room->row; i > 0; i--) {
                if(i%2 != 0) {
                    for(int j = 1; j <= sp_room->col; j++) {
                        if(j%2 != 0) {
                            printf("   X   ");
                        } else {
                            printf("   0   ");
                        }
                    }
                } else {
                    for (int j = 1; j <= sp_room->col; j++) {
                        printf("   0   ");
                    }
                }
                printf("\n");
            }
            break;
        default: 
        printf("Occupancy faulty\n");
        break;
    }
    printf("\n(X: available seat)\n\n");
}
