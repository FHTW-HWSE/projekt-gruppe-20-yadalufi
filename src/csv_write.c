#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs/student.h"

void write_csv(struct student *student, int num_students, const char *filename) {
    FILE *fp = fopen("test.csv", "w+");
    if (fp == NULL) {
        printf("Error: Could not open file %s for writing\n", filename);
        return;
    }

    // Write header row
    fprintf(fp, "ID;First Name;Last Name;Seat\n");

    // Write data rows
    for (int i = 0; i < num_students; i++) {
        fprintf(fp, "%s,%s,%s,%d,%d,\n", student[i].student_id, student[i].first_name, student[i].last_name, student[i].row, student[i].col);
    }

    fclose(fp);
}