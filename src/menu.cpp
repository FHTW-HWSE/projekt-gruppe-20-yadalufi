#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "menu/create_plan.h"
#include "menu/add_student.h"
#include "menu/quit.h"
#include "menu.h"
#include "file.h"
#include "student.h"

/// @brief Display menu
enum menu_elements
{
    create_plan = 1,
    show_rm,
    show_seats,
    add_student,
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
    printf("5. Remove student\n");
    printf("6. Load CSV file\n");
    printf("7. Contact tracing\n");
    printf("8. Quit\n");
    printf("============\n\n");
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
            menu_add_student(m_room, m_student);
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
            menu_quit(m_room, m_student);
            break;
        default:
            printf("Invalid choice, please try again.\n");
            break;
        }
    }
    return choice;
}
