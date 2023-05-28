#include <stdio.h>
#include <stdlib.h>
#include "file.h"

int *create_array_classroom ();

int *create_array_classroom(int rows, int cols) {

    room *classroom = (room *)malloc(sizeof(room));
    if(room == NULL){
        perror("Error allocating memory for array_classroom");
    }

    classroom->col = cols;
    classroom->row = rows;
    int used_seats = 0;

    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            used_seats++;
        }
    }
    return classroom;
}
