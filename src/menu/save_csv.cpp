#include <stdio.h>
#include <string.h>
#include "save_csv.h"
#include "../file.h"
#include "../student.h"
#include "../csv_write.h"
#include <stdlib.h>

#define MAX_STRING 250

/**
 * @brief               Saves the user input in a csv File
 * 
 * This function saves the user input when the user chooses save csv from the menu
 * It alerts the user if there is no data to be saved or if the saving has failed 
 * for other reasons
 * 
 * @param          m_room    Pointer to the room structure.
 * @param           m_student Pointer to the student structure.
 * 
 * 
 * @return              int 
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