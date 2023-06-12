#include <stdio.h>
#include <string.h>
#include "create_plan.h"
#include "../file.h"
#include "../student.h"

/**
 * @brief           Creates a seating plan and performs seat assignments.
 *
 * This function is called when the user chooses to create a seating plan. It allows the user to
 * create a new room and perform seat assignments for the students. If an existing plan exists,
 * the user has the option to overwrite it or cancel the operation. The function returns 0 upon
 * successful completion.
 *
 * @param           m_room    Pointer to the pointer of the room structure.
 * @param           m_student Pointer to the pointer of the student structure.
 *
 * @return          int
 */
int menu_create_plan(room **m_room, student **m_student)
{
    char input[MAX_STRING];

    if (*m_room == NULL)
    {
        *m_room = create_room(*m_room, *m_student); // student head mitgeben
        if (*m_student != NULL && *m_room != NULL)
        {
            int seat_ass = seat_assignment(*m_student, *m_room);
            if (seat_ass == 0)
            {
                printf("\nSeat assignment successful\n\n");
            }
            else if (seat_ass == 1)
            {
                printf("\nSeat assignment not successful\n\n");
            }
            else
            {
                printf("\nSeat assignment error\n\n");
            }
        }
        return 0;
    }

    printf("\nDo you want to overwrite the existing plan?\n(y) or (n)\n");
    scanf(" %s", input);
    while (strcmp(input, "y") != 0 && strcmp(input, "n") != 0)
    {
        printf("Input invalid, please enter (y) or (n)\n");
        scanf(" %s", input);
    }
    if (strcmp(input, "y") == 0)
    {
        *m_room = create_room(*m_room, *m_student);
        if (*m_student != NULL && *m_room != NULL)
        {
            int seat_ass = seat_assignment(*m_student, *m_room);
            if (seat_ass == 0)
            {
                printf("\nSeat assignment successful\n\n");
            }
            else if (seat_ass == 1)
            {
                printf("\nSeat assignment not successful\n\n");
            }
            else
            {
                printf("\nSeat assignment error\n\n");
            }
        }
    }

    return 0;
}
