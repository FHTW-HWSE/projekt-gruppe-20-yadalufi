#include <stdlib.h>
#include <stdio.h>
#include "file.h"
#include "structs/file.h"
#include "structs/student.h"
#include "menu.h"

int main(int argc, char **argv)
{
  struct File *file = malloc(sizeof(struct File));
  file->name = "test.csv";
  file->content = "Example content";

  // saveCSV(file->name, file->content);
  // readCSV(file->name);

  menu_choice();

  room *Room = create_room();
  student *Student = create_student();



/*
  struct student *student = malloc(sizeof(struct student));
  if (student == NULL){
      fprintf(stderr, "Out of memory\n");
      exit(1);
  }
*/

  int error =  free_student(Student);
  if (error != 0) {
    fprintf(stderr, "free_student failed");
  }

  error = free_room(Room);
  if (error != 0) {
    fprintf(stderr, "free_room failed\n");
  }
  free(file);

  return 0;
}
