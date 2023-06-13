#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "contact_tracing.h"
#include "file.h"
#include "menu.h"
#include "student.h"

#define MAX_STRING 250

/**
 * @brief      Resets the counter variables
 *
 * @param      i  Pointer to the index
 * @param      j  Pointer to the index
 *
 * @return     int
 */

int reset_counter_vars(int *i, int *j){
    *i = 0;
    *j = 0;
    return 0;
}

/**
 * @brief      Prints the student's information to console
 *
 * @param      temp  Pointer to the student structure
 *
 * @return     void
 */
void print_student_info(student *temp){
    printf("\tName: %s, %s\tStudent ID: %s\n", temp->last_name, temp->first_name, temp->student_id);
}

/**
 * @brief      Finds selected student in list
 *
 * @param      head       Pointer to the head of the student list
 * @param      selection  The selection index
 *
 * @return     student*
 */
student *find_student(student *head, int selection) {
    student *temp = head;
    int counter = 0;

    counter = number_students(head);

    // Check if selection is valid
    if (selection < 1 || selection > counter) {
        printf("Invalid selection!\n");
        return NULL;
    }

    // Reset temp to the head of the list
    temp = head;

    // Traverse the list to find the selected student
    for (int i = 0; i < counter; i++) {
        if (i == selection -1) {
            break;
        }
        temp = temp->next;
    }

    return temp;
}

/**
* @brief      Print direct and indirect neighbours of a selected student within a room to console
*
* @param      selection  The selection index of the student
* @param      rm         Pointer to the room structure
* @param      head       Pointer to the head of the student list
*
* @return     int
*/
int trace_contacts(int selection, room *rm, student *head){

    student *temp = head;
    room *m_room = rm;
    int i = 0;
    int j = 0;
    int row_max = 0;
    //find the max row number
    for (int i = 0; i <= rm->row; i++){
        row_max = i;
    }
    int col_max = 0;
    //find the max col number
    for (int j = 0; j <= rm->col; j++){
        col_max = j;
    }
    reset_counter_vars(&i, &j);

    int row_seat = 0;
    int col_seat = 0;

    temp = find_student(head, selection);
    char filename[MAX_STRING];
    get_ct_filename(m_room, temp, filename);

    FILE *fp = fopen(filename, "w+");
    if (fp == NULL) {
        printf("Error: Could not open file %s for writing\n", filename);
        return 1;
    }

    reset_counter_vars(&i, &j);
    printf("\nDirect neighbours of student %s, %s\tStudent ID: %s\n", temp->last_name, temp->first_name, temp->student_id);
    fprintf(fp, "%s, %s, %d/%d/%d\n", m_room->exam_name, m_room->room_name, m_room->exam_date.year, m_room->exam_date.month, m_room->exam_date.day);
    fprintf(fp, "Contact tracing for\n%s, %s, %s\n\nDirect neighbours:\n", temp->last_name, temp->first_name, temp->student_id);
    // Seat of selected student as in list (starts at 0)
    // used in if statements to find neighbours by comparing to row and col
    row_seat = temp->row;
    col_seat = temp->col;

    reset_counter_vars(&i, &j);
    temp = head;
    int direct_neighbours = 0;
    // find direct neighbors and print to console
    // iterate through room (rows and columns) and check if student is in range
    for(i = 0 ; temp != NULL && i <= rm->row -1; i++){
        for(j = 0 ; temp != NULL && j <= rm->col -1; j++){
            // row in front of selected student + row behind selected student
            if(temp->row == row_seat -1 || temp->row == row_seat +1){
                if(temp->col == col_seat -1 || temp->col == col_seat || temp->col == col_seat +1){
                    print_student_info(temp);
                    print_student_info_file(temp, fp);
                    direct_neighbours++;
                }
            }
            // row of selected student
            if(temp->row == row_seat){
                if(temp->col == col_seat -1 || temp->col == col_seat +1){
                    print_student_info(temp);
                    print_student_info_file(temp, fp);
                    direct_neighbours++;
                }
            }
            temp = temp->next;
        }
    }
    // if no direct neighbours print message
    if(direct_neighbours == 0){
        printf("\tNo direct neighbours\n");
        fprintf(fp, "No direct neighbours\n");
    }
    reset_counter_vars(&i, &j);

    temp = head;
    temp = find_student(head, selection);
    printf("\nIndirect neighbours of student %s, %s\tStudent ID: %s\n", temp->last_name, temp->first_name, temp->student_id);
    fprintf(fp, "\nIndirect neighbours:\n");


    reset_counter_vars(&i, &j);
    temp = head;
    int indirect_neighbours = 0;
    // find indirect neighbours and print to console
    // iterate through room (rows and columns) and check if student is in range
    for(i = 0 ; temp != NULL && i <= rm->row -1; i++){
        for(j = 0 ; temp != NULL && j <= rm->col -1; j++){
            // row two in front of selected student + row two behind selected student
            if(temp->row == row_seat -2 || temp->row == row_seat +2){
                if(temp->col == col_seat -2 || temp->col == col_seat -1 || temp->col == col_seat || temp->col == col_seat +1|| temp->col == col_seat +2){
                    print_student_info(temp);
                    print_student_info_file(temp, fp);
                    indirect_neighbours++;
                }
            }
            // row in front of selected student + row of selected student + row behind selected student
            if(temp->row == row_seat -1 || temp->row == row_seat || temp->row == row_seat +1){
                if(temp->col == col_seat -2 || temp->col == col_seat +2){
                    print_student_info(temp);
                    print_student_info_file(temp, fp);
                    indirect_neighbours++;
                }
            }
            temp = temp->next;
        }
    }
    // if no indirect neighbours print message
    if(indirect_neighbours == 0){
        printf("\tNo indirect neighbours\n");
        fprintf(fp, "No indirect neighbours\n");
    }
    printf("\n");
    fclose(fp);
    return 0;
}

/**
 * @brief       Selects a student from the list according to the user input
 *
 * @param       rm   The room
 * @param       head The head of the student list
 *
 * @return      int
 */
int select_student (room *rm, student *head){

    if (head == NULL){
        printf("No students in list.\n");
        return 0;
    }
    if (rm == NULL){
        printf("No rooms in list.\n");
        return 0;
    }

    student *temp = head;
    char selected_student_string[MAX_STRING];
    char *ptr_student = NULL;
    int selection = 0;
    int counter = 0;
    int students_in_room = 0;

    printf("\n%s - %s (%d/%d/%d)\n\n", rm->room_name, rm->exam_name, rm->exam_date.day, rm->exam_date.month, rm->exam_date.year);
    printf("Students in room:\n");

    counter = number_students(head);
    temp = head;

    // print all students in list
    for (int i = 1; i <= counter; i++){
        printf("%d. %s %s, %s\n", i, temp->last_name, temp->first_name, temp->student_id);
        students_in_room++;
        temp = temp->next;
    }
    temp = head;
    if (students_in_room == 0){
        printf("No students in room.\n");
        return 0;
    }

    printf("\nSelect student \nor enter (q) to quit\n");
    scanf("%s", selected_student_string);
    if (strcmp(selected_student_string, "q") == 0) {
        return -1;
    }
    selection = strtol(selected_student_string, &ptr_student, 10);

    while (selection < 1 || selection > counter){
        printf("Invalid selection. Please try again: \n");
        selection = 0;
        scanf("%s", selected_student_string);
        selection = strtol(selected_student_string, &ptr_student, 10);
    }

    printf("Selection: %d.\n", selection);
    temp = find_student(head, selection);
    printf("Selected student: %s %s, %s\n", temp->last_name, temp->first_name, temp->student_id);
    return selection;
}

/**
 * @brief           Gets the filename for the contact tracing file
 *
 * @param           rm  The room
 * @param           temp The student
 * @param           fp The file pointer
 *
 * @return          int
 */
int get_ct_filename(room *rm, student *temp, char* filename) {
    char datestr[8];
    sprintf(datestr, "%d%d%d", rm->exam_date.year, rm->exam_date.month, rm->exam_date.day);

    strcpy(filename, "contact_tracing_");
    strcat(filename, rm->exam_name);
    strcat(filename, "_");
    strcat(filename, datestr);
    strcat(filename, "_");
    strcat(filename, temp->last_name);
    strcat(filename, "_");
    strcat(filename, temp->first_name);
    strcat(filename, ".csv");
    return 0;
}

/**
 * @brief           Prints the student information to file
 *
 * @param           temp The student
 * @param           fp The file pointer
 *
 * @return          void
 */
void print_student_info_file(student *temp, FILE *fp) {
    fprintf(fp, "%s, %s, %s\n", temp->last_name, temp->first_name, temp->student_id);
}
