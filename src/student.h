/**
 * @file        student.h
 * @brief       Header file for student.cpp
 */

#ifndef STUDENT_H
#define STUDENT_H

#include "file.h"

char *allocate_new_student_first_name(student *new_student);
char *allocate_new_student_last_name(student *new_student);
char *allocate_new_student_id(student *new_student);
student *allocate_new_student();
student *create_student(student *st_head, room *st_room);
int free_student(student *new_student);
int seat_assignment(student *head, room *sa_room);
int number_students(student *head);
student *remove_student(student *head, room *rs_room);
student *remove_list_item(student *head, student *temp);

#endif // STUDENT_H
