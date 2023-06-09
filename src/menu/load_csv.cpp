#include <stdio.h>
#include <string.h>
#include "load_csv.h"
#include "../file.h"
#include "../student.h"
#include "../csv_read.h"

#define MAX_STRING 250

/**
 * @brief           Loads the room and student information 
 * 
 * This function is called when the user chooses to load the room and student information from the menu
 * If an existing plan exists,the user has the option to overwrite it or cancel the operation.
 * The function returns 0 upon uccessful completion.
 * 
 * @param           m_room    Pointer to the pointer of the room structure.
 * @param           m_student Pointer to the student structure.
 * 
 * @return          void
 */

student * menu_load_csv(room **m_room, student *m_student) {
        char input[MAX_STRING];
        char filename[MAX_STRING];

        if (*m_room == NULL && m_student == NULL) {
            printf("\nPlease enter file name:\n\n");
            scanf(" %s", filename);
            m_student = read_csv(filename, m_room, m_student);
        } else {
            printf("\nDo you want to overwrite the current data?\n(y) or (n)\n");
            scanf(" %s", input);
                while (strcmp(input, "y") != 0 && strcmp(input, "n") != 0)
                {
                    printf("Input invalid, please enter (y) or (n)\n");
                    scanf(" %s", input);
                }
                if (strcmp(input, "n") == 0) {
                    return m_student;
                } else if (strcmp(input, "y") == 0) {
                    int err = free_room(*m_room);
                    if (err != 0) {
                        fprintf(stderr, "free_room failed\n");
                    }
                    err = free_student(m_student);
                    if (err != 0) {
                        fprintf(stderr, "free_student failed\n");
                    }
                    *m_room = NULL;
                    m_student = NULL;
                    printf("\nPlease enter file name:\n\n");
                    scanf(" %s", filename);
                    m_student = read_csv(filename, m_room, m_student);
                }
        }
    return m_student;
}
