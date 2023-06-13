#include <stdio.h>
#include <string.h>
#include "remove_student.h"
#include "../file.h"
#include "../student.h"
#include <stdlib.h>

#define MAX_STRING 250

student * menu_remove_student(room * m_room, student * m_student) {
        if(m_room == NULL && m_student == NULL) {
            printf("\nNo room or student list\n\n");
            return m_student;
        } else {
            m_student = remove_student(m_student, m_room);
            seat_assignment(m_student, m_room);
            return m_student;
        }
}