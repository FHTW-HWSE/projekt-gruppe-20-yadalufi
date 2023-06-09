#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../file.h"
#include "../student.h"

void menu_add_student(room *m_room, student *m_student)
{
    if (m_room == NULL)
    {
        printf("Please create a room plan first.\n");
        return;
    }

    if (m_student != NULL)
    {
        int seats = available_seats(m_room->row, m_room->col, m_room->occupancy);
        int num_students = number_students(m_student);
        if (num_students >= seats)
        {
            printf("All seats are taken.\n");
            return;
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
        return;
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
}
