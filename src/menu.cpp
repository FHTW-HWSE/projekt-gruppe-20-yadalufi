#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "menu/create_plan.h"
#include "menu/add_student.h"
#include "menu/quit.h"
#include "menu.h"
#include "file.h"
#include "student.h"
#include "contact_tracing.h"
#include "csv_read.h"
#include "menu/load_csv.h"


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

/**
 * @brief       Displays the menu
 *
 * @return      void
 */
void display_menu()
{
    printf("\n\n=== MENU ===\n");
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

/**
 * @brief       Displays the menu and asks for user input
 *
 * @param       fp    Pointer to the file
 *
 * @return      int
 */
int menu_choice(char *filename)
{
    int choice = 0;
    char choice_string[MAX_STRING];
    char *ptr;
    room *m_room = NULL; 
    student *m_student = NULL;
    int selection = 0;
    if ((strcmp(filename, "") != 0)) {
        m_student = read_csv(filename, &m_room, m_student);
    }

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
            int return_value = menu_create_plan(&m_room, &m_student);
        }
        break;
        case show_rm:
            if (m_room == NULL)
            {
                printf("\nNo room to show\n\n");
                break;
            }
            if (m_room->row > 8 || m_room->col > 6) {
                printf("\n\n%s - %s (%d/%d/%d)\n", m_room->room_name, m_room->exam_name, m_room->exam_date.day, m_room->exam_date.month, m_room->exam_date.year);
                printf("\nRoom too big to show\n\n");
                break;
            }
            show_room(m_room, m_student);
            break;
        case show_seats:
            // insert function here
            break;
        case add_student:
            menu_add_student(&m_room, &m_student);
            break;
        case remove_student:
            // insert function here
            break;
        case load_csv_file:
            m_student = menu_load_csv(&m_room, m_student);
            break;
        case contact_tracing:
            if (m_room != NULL && m_student != NULL) {
            selection = select_student(m_room, m_student);
            trace_contacts(selection, m_room, m_student);
            } else {
                printf("\nContact tracing not possible (no room/students)\n\n");
            }
            break;
        case quit:
            menu_quit(&m_room, &m_student);
            break;
        default:
            printf("\nInvalid choice, please try again.\n\n");
            break;
        }
    }
    return choice;
}
