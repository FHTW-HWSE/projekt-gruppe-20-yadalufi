#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"

void read_csv(const char* filename, room* examRoom, student** students) {
    FILE* inputFile = fopen(filename, "r");
    if (inputFile == NULL) {
        printf("Error: Could not open file %s for reading\n", filename);
        return;
    }

    // Skip the first line
    char line[100];
    fgets(line, sizeof(line), inputFile); // Read and discard the first line

    // Read room information from the second line
    char room_name[100];
    char exam_name[100];
    int year, month, day, row, col, occupancy;
    fscanf(inputFile, "%[^,],%[^,],%d,%d,%d,%d,%d,%d\n", room_name, exam_name, &month, &day, &year, &row, &col, &occupancy);

    examRoom->room_name = strdup(room_name);
    examRoom->exam_name = strdup(exam_name);
    examRoom->exam_date.month = month;
    examRoom->exam_date.day = day;
    examRoom->exam_date.year = year;
    examRoom->row = row;
    examRoom->col = col;
    examRoom->occupancy = occupancy;

    // Skip the third line
    fgets(line, sizeof(line), inputFile); // Read and discard the third line

    // Read student information
    while (fgets(line, sizeof(line), inputFile)) {
        char first_name[100];
        char last_name[100];
        char student_id[100];
        int col, row;

        sscanf(line, "%[^,],%[^,],%[^,\n],%d,%d\n", student_id, first_name, last_name, &col, &row);

        student* newStudent = (student*)malloc(sizeof(student));

        newStudent->first_name = strdup(first_name);
        newStudent->last_name = strdup(last_name);
        newStudent->student_id = strdup(student_id);
        newStudent->col = col;
        newStudent->row = row;
        newStudent->next = NULL;

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
