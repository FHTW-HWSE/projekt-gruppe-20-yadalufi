
#ifndef YADALUFI_CONTACT_TRACING_H
#define YADALUFI_CONTACT_TRACING_H

#include "file.h"
#include "student.h"
#include "menu.h"

int trace_contacts(int selection, room *rm, student *head);
int select_student (room *rm, student *head);
int reset_counter_vars(int *i, int *j);
void print_student_info(student *temp);
student *find_student(student *head, int selection);
//int count_students_in_list(student *head);

#endif //YADALUFI_CONTACT_TRACING_H
