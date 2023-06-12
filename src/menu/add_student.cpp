#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../file.h"
#include "../student.h"

/**
 * @brief       Adds a student to the seating plan and performs seat assignment.
 *
 * This function is called when the user chooses to add a student to the seating plan. It checks
 * if a room plan has been created first. If a room plan exists, the function allows the user to
 * create a new student and assigns a seat to the student. If all seats are taken or if an error
 * occurs during seat assignment, appropriate messages are displayed.
 *
 * @param       m_room    Pointer to the pointer of the room structure.
 * @param       m_student Pointer to the pointer of the student structure.
 *
 * @return      void
 */
void menu_add_student(room **m_room, student **m_student)
{
    if (*m_room == NULL)
    {
        printf("\nPlease create a room plan first.\n\n");
        return;
    }

    if (*m_student != NULL)
    {
        int seats = available_seats((*m_room)->row, (*m_room)->col, (*m_room)->occupancy);
        int num_students = number_students(*m_student);
        if (num_students >= seats)
        {
            printf("\nAll seats are taken.\n\n");
            return;
        }
        else
        {
            *m_student = create_student(*m_student, *m_room); // room mitgeben!
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
        return;
    }

    *m_student = create_student(*m_student, *m_room); // room mitgeben!
    int seat_ass;
    seat_ass = seat_assignment(*m_student, *m_room);
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
