#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"

/**
 * @brief      Reads the csv file and stores the information in the room and student structures
 *
 * @param      filename  The filename
 * @param      examRoom  Pointer to the room structure
 * @param      students  Pointer to the student list
 *
 * @return     void
 */
void read_csv(const char* filename, room* examRoom, student** students){
    FILE* inputFile = fopen(filename, "r");
    if (inputFile == NULL) {
                printf("Error: Could not open file %s for reading\n", filename);
        return;
    }

    // Read room information from the first line for the room
    char room_name[100];
    char exam_name[100];
    int year, month, day, row, col, occupancy;

    // reads until the comma then stops
    fscanf(inputFile, "%[^,],%[^,],%d/%d/%d,%d,%d,%d\n", room_name, exam_name, &year, &month, &day, &row, &col, &occupancy);

    // Allocating memory for the strings using strdup (duplicats the string and returns pointer to newly allocated memory)
    examRoom->room_name = strdup(room_name);
    examRoom->exam_name = strdup(exam_name);
    examRoom->exam_date.year = year;
    examRoom->exam_date.month = month;
    examRoom->exam_date.day = day;
    examRoom->row = row;
    examRoom->col = col;
    examRoom->occupancy = occupancy;

    // Read student information from file
    char line[100];
    while (fgets(line, sizeof(line), inputFile)) {
        char first_name[100];
        char last_name[100];
        char student_id[100];
        int col, row;

         // reads until the comma then stops
        sscanf(line, "%[^,],%[^,],%[^,],%d,%d\n", first_name, last_name, student_id, &col, &row);

        // Allocating memory again but for student
        student* newStudent = (student*)malloc(sizeof(student));
        newStudent->first_name = strdup(first_name);
        newStudent->last_name = strdup(last_name);
        newStudent->student_id = strdup(student_id);
        newStudent->col = col;
        newStudent->row = row;
        newStudent->next = NULL;

        // Appending the Student to the list
        if (*students == NULL) {
            *students = newStudent;
        } else {
            student* curr = *students;
            while (curr->next != NULL) {
                curr = curr->next;
            }
            curr->next = newStudent;
        }
    }

    fclose(inputFile);
}
