#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"
#include "student.h"

#define MAX_STRING 250

/**
 * @brief       Allocates memory for a new student_first_name
 *
 * @param       new_student Pointer to the new student
 *
 * @return      char*
 */
char *allocate_new_student_first_name(student *new_student)
{
    new_student->first_name = (char *)malloc(sizeof(char) * MAX_STRING);
    if (new_student->first_name == NULL)
    {
        perror("malloc");
    }

    return new_student->first_name;
}

/**
 * @brief       Allocates memory for a new student_last_name
 *
 * @param       new_student Pointer to the new student
 *
 * @return      char*
 */
char *allocate_new_student_last_name(student *new_student)
{
    new_student->last_name = (char *)malloc(sizeof(char) * MAX_STRING);
    if (new_student->last_name == NULL)
    {
        perror("malloc");
    }

    return new_student->last_name;
}

/**
 * @brief       Allocates memory for a new student_id
 *
 * @param       new_student Pointer to the new student
 *
 * @return      char*
 */
char *allocate_new_student_id(student *new_student)
{
    new_student->student_id = (char *)malloc(sizeof(char) * MAX_STRING);
    if (new_student->student_id == NULL)
    {
        perror("malloc");
    }

    return new_student->student_id;
}

/**
 * @brief       Allocates memory for a new student
 *
 * @return      student*
 */
student *allocate_new_student()
{
    student *new_student;
    new_student = (student *)malloc(sizeof(student));
    if (new_student == NULL)
    {
        perror("malloc");
    }

    return new_student;
}

/**
 * @brief       Creates a new student
 *
 * @param       st_head Pointer to the head of the student list
 * @param       st_room Pointer to the room of the student
 *
 * @return      student*
 */
student *create_student(student *st_head, room *st_room)
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
    { // Schleife zum Erstellen der students für die Liste

        new_student = allocate_new_student();
        new_student->first_name = allocate_new_student_first_name(new_student);
        new_student->last_name = allocate_new_student_last_name(new_student);
        new_student->student_id = allocate_new_student_id(new_student);

        new_student->next = NULL;

        do
        {
            printf("Please enter student's first name(s)\nor (q) to cancel\n");
            scanf(" %[^\n]", input);
            if (strcmp(input, "q") == 0)
            {
                return (head);
            }
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

        // room mitgeben, hier catch, falls max seat -> kein Student mehr dazu!
        int seats = available_seats(st_room->row, st_room->col, st_room->occupancy);
        int num_students = number_students(head);
        if (num_students >= seats)
        {
            printf("All seats are taken.\n");
            return(head);
        }

            printf("\nDo you want to add another student?\nEnter (y) or (n)\n");
            scanf(" %s", input);
            while (strcmp(input, "y") != 0 && strcmp(input, "n") != 0)
            {
                printf("Input invalid, please enter (y) or (n)\n");
                scanf(" %s", input);
            }
        }
        while (strcmp(input, "n") != 0);

        return head;
    }

/**
 * @brief       Frees the memory of the student list
 *
 * @param       head Pointer to the head of the student list
 *
 * @return      int
 */
int free_student(student * new_student)
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

/**
 * @brief       Assigns a seat to students in the student list
 *
 * @param       head Pointer to the head of the student list
 * @param       room Pointer to the room of the student
 *
 * @return      int
 */
int seat_assignment(student * head, room * sa_room)
{
    if (head == NULL)
    {
        printf("Empty student list\n");
        return EXIT_FAILURE;
    }
    student *current = head;

    switch (sa_room->occupancy)
    {
    case 100:
        for (int sa_row = 0; sa_row < sa_room->row; sa_row++)
        {
            for (int sa_col = 0; sa_col < sa_room->col; sa_col++)
            {
                current->row = sa_row;
                current->col = sa_col;
                current = current->next;
                if (current == NULL)
                {
                    return EXIT_SUCCESS;
                }
            }
        }
        break;

    case 50:
        for (int sa_row = 0; sa_row < sa_room->row; sa_row++)
        {
            if (sa_row % 2 == 0)
            {
                for (int sa_col = 0; sa_col < sa_room->col; sa_col += 2)
                {
                    current->row = sa_row;
                    current->col = sa_col;
                    current = current->next;
                    if (current == NULL)
                    {
                        return EXIT_SUCCESS;
                    }
                }
            }
            else
            {
                for (int sa_col = 1; sa_col < sa_room->col; sa_col += 2)
                {
                    current->row = sa_row;
                    current->col = sa_col;
                    current = current->next;
                    if (current == NULL)
                    {
                        return EXIT_SUCCESS;
                    }
                }
            }
        }
        break;
    case 25:
        for (int sa_row = 0; sa_row < sa_room->row; sa_row += 2)
        {
            for (int sa_col = 0; sa_col < sa_room->col; sa_col += 2)
            {
                current->row = sa_row;
                current->col = sa_col;
                current = current->next;
                if (current == NULL)
                {
                    return EXIT_SUCCESS;
                }
            }
        }
        break;
    default:
        return EXIT_FAILURE;
        break;
    }
    return EXIT_FAILURE;
}

/**
 * @brief       Counts the number of students in the student list
 *
 * @param       head Pointer to the head of the student list
 *
 * @return      int
 */
int number_students(student * head)
{
    student *current = head;
    int num_students = 0;
    while (current != NULL)
    {
        num_students++;
        current = current->next;
    }
    return num_students;
}
