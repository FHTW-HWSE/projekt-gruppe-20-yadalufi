#include <stdio.h>
#include <string.h>
#include "save_csv.h"
#include "../file.h"
#include "../student.h"
#include "../csv_write.h"
#include <stdlib.h>

#define MAX_STRING 250

/**
 * @brief 
 * 
 * @param m_room 
 * @param m_student 
 * @return int 
 */

int menu_write_csv(room *m_room, student *m_student) {
    char filename[MAX_STRING];

    if(m_room == NULL && m_student == NULL) {
        printf("\nNo data to save\n\n");
        return EXIT_FAILURE;
    } else {
        printf("\nPlease enter file name\nwithout file extension (.csv)\n\n");
        scanf(" %s", filename);
        strcat(filename, ".csv");
        int num_students = number_students(m_student);
        int err = write_csv(filename, m_room, m_student, num_students);
        if (err == EXIT_SUCCESS) {
            printf("\nData successfully saved\n\n");
        } else {
            printf("\nData could not be saved\n\n");
        }
    }

    return EXIT_SUCCESS;
}