#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../file.h"
#include "../student.h"

void menu_quit(room **m_room, student **m_student)
{
    printf("Goodbye!\n");
    int error;
    if (*m_student != NULL)
    {
        error = free_student(*m_student);
        if (error != 0)
        {
            fprintf(stderr, "free_student failed");
        }
    }

    if (*m_room != NULL)
    {
        error = free_room(*m_room);
        if (error != 0)
        {
            fprintf(stderr, "free_room failed\n");
        }
    }
}
