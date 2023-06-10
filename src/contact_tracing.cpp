#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "contact_tracing.h"
#include "file.h"
#include "menu.h"
#include "student.h"

#define MAX_STRING 250

int reset_counter_vars(int *i, int *j){
    *i = 0;
    *j = 0;
    return 0;
}

void print_student_info(student *temp){
    printf("Name: %s, %s\tStudent ID: %s\n", temp->first_name, temp->last_name, temp->student_id);
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

student *find_student(student *head, int selection) {
    student *temp = head;
    int counter = 0;

    counter = count_students_in_list(head);

    // Check if selection is valid
    if (selection < 1 || selection > counter) {
        // Invalid selection value
        // You can choose to handle the error here, such as printing an error message
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

int trace_contacts(int selection, room *rm, student *head){

    student *temp = head;
    int i = 0;
    int j = 0;
    int row_min = 1;
    int row_max = 0;
    //find the max row number
    for (int i = 0; i <= rm->row; i++){
        row_max = i;
    }

    printf("Selection: %d\n", selection);
    temp = find_student(head, selection);
    printf("Direct neighbours of Student %s, %s\tStudent ID: %s\n", temp->first_name, temp->last_name, temp->student_id);

    // find direct neighbors and print to console
    if(rm->row -1 < row_min){
        rm->row = row_min;
    }
    if(rm->row +1 > row_max){
        rm->row = row_max;
    }

    reset_counter_vars(&i, &j);
    temp = head;
    for(i = rm->row -1; i <= rm->row + 1; i++){
        for(j = rm->col -1; j <= rm->col + 1; j++){
            if(temp->student_id == find_student(head, selection)->student_id){
                continue;
            }
            print_student_info(temp);
        }
    }
    reset_counter_vars(&i, &j);

    find_student(head, selection);
    printf("Indirect neighbours of Student %s, %s\tStudent ID: %s\n", temp->first_name, temp->last_name, temp->student_id);

    reset_counter_vars(&i, &j);

    // find indirect neighbours and print to console
    // indirect neighbors in front
    for(i = rm->row -2; ; ){
        for(j = rm->col -2; j <= rm->col + 2; j++){
            print_student_info(temp);
        }
    }
    reset_counter_vars(&i, &j);

    // indirect neighbors behind
    for(i = rm->row +2; ; ){
        for(j = rm->col -2; j <= rm->col + 2; j++){
            print_student_info(temp);
        }
    }
    reset_counter_vars(&i, &j);

    // indirect neighbors to the left
    for(i = rm->col -2; ; ){
        for(j = rm->row -1; j <= rm->row + 1; j++){
            print_student_info(temp);
        }
    }
    reset_counter_vars(&i, &j);

    // indirect neighbors to the right
    for(i = rm->col +2; ; ){
        for(j = rm->row -1; j <= rm->row + 1; j++){
            print_student_info(temp);
        }
    }

    return 0;
}

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

    printf("%s - %s (%d/%d/%d)\n\n", rm->room_name, rm->exam_name, rm->exam_date.day, rm->exam_date.month, rm->exam_date.year);
    printf("Students in room:\n");

    counter = count_students_in_list(head);
    temp = head;

    for (int i = 1; i <= counter; i++){
        printf("%d. %s %s, %s\n", i, temp->first_name, temp->last_name, temp->student_id);
        temp = temp->next;
    }
    temp = head;

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
