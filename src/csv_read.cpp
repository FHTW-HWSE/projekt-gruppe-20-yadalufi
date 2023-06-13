#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"
#include "student.h"
#include "csv_read.h"

#define MAX_STRING 250
/**
 * @brief      Reads the csv file and stores the information in the room and student structures
 *
 * @param      filename  The filename
 * @param      examRoom  Pointer to the room structure
 * @param      students  Pointer to the student list
 *
 * @return     void
 */
student * read_csv(char* filename, room** exam_room, student* head) {
    student* current = NULL;

    FILE* inputFile = fopen(filename, "r");
    if (inputFile == NULL) {
        printf("Error: Could not open file %s for reading\n", filename);
        return NULL;
    }

    // Skip the first line
    char line[MAX_STRING];
    fgets(line, sizeof(line), inputFile); // Read and discard the first line

    // Read room information from the second line
    char room_name[MAX_STRING];
    char exam_name[MAX_STRING];
    int year, month, day, row, col, occupancy;
    fscanf(inputFile, "%[^,],%[^,],%d,%d,%d,%d,%d,%d\n", room_name, exam_name, &month, &day, &year, &row, &col, &occupancy);

    *exam_room = (room*)malloc(sizeof(room));

    (*exam_room)->room_name = (char *)malloc(sizeof(char) * MAX_STRING);
    strcpy((*exam_room)->room_name, room_name);
    (*exam_room)->exam_name = (char *)malloc(sizeof(char) * MAX_STRING);
    strcpy((*exam_room)->exam_name, exam_name);
    (*exam_room)->exam_date.month = month;
    (*exam_room)->exam_date.day = day;
    (*exam_room)->exam_date.year = year;
    (*exam_room)->row = row;
    (*exam_room)->col = col;
    (*exam_room)->occupancy = occupancy;

    // Skip the third line
    fgets(line, sizeof(line), inputFile); // Read and discard the third line
 //   fgets(line, sizeof(line), inputFile);

    // Read student information
    while (fgets(line, sizeof(line), inputFile)) {
        char first_name[MAX_STRING];
        char last_name[MAX_STRING];
        char student_id[MAX_STRING];
        int col, row;

        sscanf(line, "%[^,],%[^,],%[^,\n],%d,%d\n", student_id, first_name, last_name, &row, &col);

        student* new_student = (student*)malloc(sizeof(student));
        new_student->first_name = (char *)malloc(sizeof(char) * MAX_STRING);
        strcpy(new_student->first_name, first_name);

        new_student->last_name = (char *)malloc(sizeof(char)*MAX_STRING);
        strcpy(new_student->last_name, last_name);
        
        new_student->student_id = (char*)malloc(sizeof(char)*MAX_STRING);
        strcpy(new_student->student_id, student_id);
        new_student->col = col-1;
        new_student->row = row-1;
        new_student->next = NULL;

        if (head == NULL) {
            head = new_student;
            current = new_student;
        } else {
            current->next = new_student;
            current = new_student;
        }
    }

    fclose(inputFile);
    return head;
}
