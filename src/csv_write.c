#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct seat {
    int row;
    int column;
};

struct student {
    int id;
    char name[50];
    int phone_number;
    struct seat assigned_seat;
};
void write_csv(struct student *student, int num_students, const char *filename) {
    FILE *fp = fopen("test.csv", "w+");
    if (fp == NULL) {
        printf("Error: Could not open file %s for writing\n", filename);
        return;
    }

    // Write header row
    fprintf(fp, "ID;Name;Seat\n");

    // Write data rows
    for (int i = 0; i < num_students; i++) {
        fprintf(fp, "%d,%s,%d,%d,\n", student[i].id, student[i].name, student[i].assigned_seat);
    }

    fclose(fp);
}