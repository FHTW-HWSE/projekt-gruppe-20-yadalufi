#include <stdlib.h>
#include <stdio.h>
#include "file.h"
#include "structs/file.h"
#include "structs/student.h"

int main(int argc, char **argv)
{
  struct File *file = malloc(sizeof(struct File));
  file->name = "test.csv";
  file->content = "Example content";

  // saveCSV(file->name, file->content);
  // readCSV(file->name);

  for (int i = 0; i < argc; i++) {
    // menu (switch case)
  }

  room *Room = create_room();

  struct Student *student = malloc(sizeof(struct Student));
  if (student == NULL){
      fprintf(stderr, "Out of memory\n");
      exit(1);
  }

  free(student);
  free_room(Room);

  return 0;
}
