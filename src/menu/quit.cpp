#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../file.h"
#include "../student.h"

/**
 * @brief       Quits the program and frees allocated memory.
 *
 * This function is called when the user chooses to quit the program. It displays a goodbye message,
 * frees the memory allocated for the student and room structures, and performs necessary error handling.
 *
 * @param       m_room    Pointer to the pointer of the room structure.
 * @param       m_student Pointer to the pointer of the student structure.
 *
 * @return      void
 */

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
