#ifndef MENU_H
#define MENU_H

#include "menu/create_plan.h"
#include "menu/add_student.h"
#include "file.h"

#define MAX_STRING 250

void display_menu();
int menu_choice(FILE *fp);

#endif // MENU_H
