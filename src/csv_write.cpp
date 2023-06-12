#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"

/**
 * @brief      Reads the student's information in the room and student structures and writes it to a csv file
 *
 * @param      filename  The filename
 * @param      examRoom  Pointer to the room structure
 * @param      students  Pointer to the student list
 * @param      num_students  The number of students
 *
 * @return     void
 */
void write_csv(const char* filename, room* examRoom, student* students, int num_students) {
    FILE *fp = fopen(filename, "w+");
    if (fp == NULL) {
        printf("Error: Could not open file %s for writing\n", filename);
        return;
    }
    // Write room header row
    fprintf(fp, "Room name,Exam name,Month,Day,Year,row,col,occupancy\n");
    fprintf(fp, "%s,%s,%d,%d,%d,%d,%d,%d\n", examRoom->room_name, examRoom->exam_name,
            examRoom->exam_date.month, examRoom->exam_date.day,examRoom->exam_date.year, examRoom->row,
            examRoom->col, examRoom->occupancy);
    fprintf(fp,"\n");

    // Write student header row
    fprintf(fp, "ID,First Name,Last Name,Seat\n");

    // Write data rows
    for (int i = 0; i < num_students; i++) {
        fprintf(fp, "%s,%s,%s,%d,%d\n", students[i].student_id, students[i].first_name,
                students[i].last_name, students[i].row, students[i].col);
    }

    fclose(fp);
}
