#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"

void write_csv(const char* filename, room* examRoom, student* student, int num_students) {
    FILE *fp = fopen("test.csv", "w+");
    if (fp == NULL) {
        printf("Error: Could not open file %s for writing\n", filename);
        return;
    }
    // Write room header row
    fprintf(fp, "Room name;Exame name; Exam date;row;col;occupancy\n");
    fprintf(fp,"%s, %s, %s, %d, %d, %d\n",examRoom->room_name, examRoom->exam_name, examRoom->exam_date, examRoom->row, examRoom->col, examRoom->occupancy);

    // Write student header row
    fprintf(fp, "ID;First Name;Last Name;Seat\n");

    // Write data rows
    for (int i = 0; i < num_students; i++) {
        fprintf(fp, "%s,%s,%s,%d,%d,\n", student[i].student_id, student[i].first_name, student[i].last_name, student[i].row, student[i].col);
    }

    fclose(fp);
}