#include <stdio.h>
#include <string.h>
#include "create_plan.h"
#include "../file.h"
#include "../student.h"

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
    }

    return 0;
}
