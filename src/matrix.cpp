#include <stdio.h>
#include <stdlib.h>
#include "file.h"

int number_seats (int row, int col);

    int number_seats(int row, int col) {
    int seats = 0;

    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            seats++;
        }
    }

    if (row < 1 || col < 1) {
        seats = -1;
    }
    return seats;
}
