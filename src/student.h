#ifndef STUDENT_H
#define STUDENT_H
/*
typedef struct {
    int year;
    int month;
    int day;
} date;

typedef struct {
    char* room_name;
    char* exam_name;
    date exam_date;
    int row;
    int col;        
    int occupancy;
} room;

typedef struct student {
    char *first_name;
    char *last_name;
    char *student_id;
    int col;
    int row;
    struct student *next;
    struct student **students; // struct student *students[]
} student;
*/
#include "file.h"

char * allocate_new_student_first_name(student * new_student);
char * allocate_new_student_last_name(student * new_student);
char * allocate_new_student_id(student * new_student);
student * allocate_new_student();
student* create_student(student *st_head, room *st_room);
int free_student(student *new_student);
int seat_assignment (student * head, room * sa_room);
int number_students(student * head);

#endif //STUDENT_H
