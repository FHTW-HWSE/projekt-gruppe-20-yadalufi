#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "contact_tracing.h"
#include "file.h"
#include "menu.h"
#include "student.h"

#define MAX_STRING 250

/*
 * Function: trace_contacts
 * ------------------------
 *  This function is called when the user selects the contact tracing option from the menu.
 *  It prompts the user to select a student from the list of students in the room.
 *  It then prints the student's information and the information of the students sitting
 *  around the selected student. Direct neighbours are students sitting one seat away from
 *  the selected student. Indirect neighbours are students sitting two seats away from the
 *  selected student.
 *
 *  selection: the student selected by the user
 *  rm: the room selected by the user
 *  head: the head of the list of students in the room
 *
 *  returns: 0 if successful
 */
int reset_counter_vars(int *i, int *j){
    *i = 0;
    *j = 0;
    return 0;
}

// Print the student's information
void print_student_info(student *temp){
    printf("\tName: %s, %s\tStudent ID: %s\n", temp->first_name, temp->last_name, temp->student_id);
}

// Count the number of students in the list
int count_students_in_list(student *head){
    student *temp = head;
    int counter = 0;
    while (temp != NULL) {
        counter++;
        temp = temp->next;
    }
    return counter;
}

// Find the selected student in the list
student *find_student(student *head, int selection) {
    student *temp = head;
    int counter = 0;

    counter = count_students_in_list(head);

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

// Search for the selected student's direct and indirect neighbours and print their information
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
    reset_counter_vars(&i, &j);
    printf("\nDirect neighbours of Student %s, %s\tStudent ID: %s\n", temp->first_name, temp->last_name, temp->student_id);
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
                    direct_neighbours++;
                }
            }
            // row of selected student
            if(temp->row == row_seat){
                if(temp->col == col_seat -1 || temp->col == col_seat +1){
                    print_student_info(temp);
                    direct_neighbours++;
                }
            }
            temp = temp->next;
        }
    }
    // if no direct neighbours print message
    if(direct_neighbours == 0){
        printf("\tNo direct neighbours\n");
    }
    reset_counter_vars(&i, &j);

    temp = head;
    temp = find_student(head, selection);
    printf("\nIndirect neighbours of Student %s, %s\tStudent ID: %s\n", temp->first_name, temp->last_name, temp->student_id);

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
                    indirect_neighbours++;
                }
            }
            // row in front of selected student + row of selected student + row behind selected student
            if(temp->row == row_seat -1 || temp->row == row_seat || temp->row == row_seat +1){
                if(temp->col == col_seat -2 || temp->col == col_seat +2){
                    print_student_info(temp);
                    indirect_neighbours++;
                }
            }
            temp = temp->next;
        }
    }
    // if no indirect neighbours print message
    if(indirect_neighbours == 0){
        printf("\tNo indirect neighbours\n");
    }
    printf("\n");
    return 0;
}

// Prompt the user to select a student from the list
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

    counter = count_students_in_list(head);
    temp = head;

    // print all students in list
    for (int i = 1; i <= counter; i++){
        printf("%d. %s %s, %s\n", i, temp->first_name, temp->last_name, temp->student_id);
        students_in_room++;
        temp = temp->next;
    }
    temp = head;
    if (students_in_room == 0){
        printf("No students in room.\n");
        return 0;
    }

    printf("\nSelect student: \n");
    scanf("%s", selected_student_string);
    selection = strtol(selected_student_string, &ptr_student, 10);

    while (selection < 1 || selection > counter){
        printf("Invalid selection. Please try again: \n");
        selection = 0;
        scanf("%s", selected_student_string);
        selection = strtol(selected_student_string, &ptr_student, 10);
    }

    printf("Selection: %d.\n", selection);
    temp = find_student(head, selection);
    printf("Selected student: %s %s, %s\n", temp->first_name, temp->last_name, temp->student_id);
    return selection;
}
