#ifndef MENU_H
#define MENU_H

#include "menu/create_plan.h"
#include "menu/add_student.h"
#include "menu/quit.h"
#include "file.h"
#include "csv_read.h"


#define MAX_STRING 250

void display_menu();
int menu_choice(char *filename);

#endif // MENU_H
