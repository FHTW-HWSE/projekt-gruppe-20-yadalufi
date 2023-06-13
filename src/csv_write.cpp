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
int write_csv(const char* filename, room* exam_room, student* head, int num_students) {
    student * temp = head;
    FILE *fp = fopen(filename, "w+");
    if (fp == NULL) {
        printf("Error: Could not open file %s for writing\n", filename);
        return EXIT_FAILURE;
    }
    // Write room header row
    fprintf(fp, "Room name,Exam name,Month,Day,Year,row,col,occupancy\n");
    fprintf(fp, "%s,%s,%d,%d,%d,%d,%d,%d\n", exam_room->room_name, exam_room->exam_name,
            exam_room->exam_date.month, exam_room->exam_date.day,exam_room->exam_date.year, exam_room->row,
            exam_room->col, exam_room->occupancy);
    fprintf(fp,"\n");

    // Write student header row
    fprintf(fp, "ID,First Name,Last Name,Seat\n");

    // Write data rows
    for (int i = 0; i < num_students; i++) {
        fprintf(fp, "%s,%s,%s,%d,%d\n", temp->student_id, temp->first_name,
                temp->last_name, temp->row+1, temp->col+1);
                temp = temp->next;
    }

    fclose(fp);
    return EXIT_SUCCESS;
}
