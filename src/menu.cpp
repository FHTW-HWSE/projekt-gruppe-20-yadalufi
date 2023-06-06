#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "menu/create_plan.h"
#include "menu.h"
#include "file.h"
#include "student.h"

enum menu_elements
{
    create_plan = 1,
    show_rm,
    show_seats,
    add_student,
    edit_student,
    remove_student,
    load_csv_file,
    contact_tracing,
    quit
} choice;

void display_menu()
{
    printf("=== MENU ===\n");
    printf("1. Create plan\n");
    printf("2. Show room\n");
    printf("3. Show seats\n");
    printf("4. Add student\n");
    printf("5. Edit student\n");
    printf("6. Remove student\n");
    printf("7. Load CSV file\n");
    printf("8. Contact tracing\n");
    printf("9. Quit\n");
    printf("============\n");
    return;
}

int menu_choice(FILE *fp)
{
    int choice = 0;
    char choice_string[MAX_STRING];
    char *ptr;
    room *m_room = NULL; // hier mit fp: wenn kein File da, dann room/student neu, sonst aus File laden
    student *m_student = NULL;

    while (choice != quit)
    {
        display_menu();
        printf("Enter your choice: ");
        scanf("%s", choice_string);
        choice = strtol(choice_string, &ptr, 10);

        switch (choice)
        {
        case create_plan:
        {
            int return_value = menu_create_plan(m_room, m_student);
        }
        break;
        case show_rm:
            if (m_room == NULL)
            {
                printf("No room to show\n");
                break;
            }

            show_room(m_room, m_student);
            break;
        case show_seats:
            // insert function here
            break;
        case add_student:
            if (m_room == NULL)
            {
                printf("Please create a room plan first.\n");
                break;
            }

            if (m_student != NULL)
            {
                int seats = available_seats(m_room->row, m_room->col, m_room->occupancy);
                int num_students = number_students(m_student);
                if (num_students >= seats)
                {
                    printf("All seats are taken.\n");
                    break;
                }
                else
                {
                    m_student = create_student(m_student, m_room); // room mitgeben!
                    int seat_ass = seat_assignment(m_student, m_room);
                    if (seat_ass == 0)
                    {
                        printf("Seat assignment successful\n");
                    }
                    else if (seat_ass == 1)
                    {
                        printf("Seat assignment not succesful\n");
                    }
                    else
                    {
                        printf("Seat ass...?\n");
                    }
                }
                break;
            }

            m_student = create_student(m_student, m_room); // room mitgeben!
            int seat_ass;
            seat_ass = seat_assignment(m_student, m_room);
            if (seat_ass == 0)
            {
                printf("Seat assignment successful\n");
            }
            else if (seat_ass == 1)
            {
                printf("Seat assignment not succesful\n");
            }
            else
            {
                printf("Seat ass...?\n");
            }
            break;
        case edit_student:
            // insert function here
            break;
        case remove_student:
            // insert function here
            break;
        case load_csv_file:
            // insert function here
            break;
        case contact_tracing:
            // insert function here
            break;
        case quit:
            printf("Goodbye!\n");
            int error;
            if (m_student != NULL)
            {
                error = free_student(m_student);
                if (error != 0)
                {
                    fprintf(stderr, "free_student failed");
                }
            }

            if (m_room != NULL)
            {
                error = free_room(m_room);
                if (error != 0)
                {
                    fprintf(stderr, "free_room failed\n");
                }
            }
            break;
        default:
            printf("Invalid choice, please try again.\n");
            break;
        }
    }
    return choice;
}
