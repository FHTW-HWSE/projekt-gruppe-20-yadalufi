#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "file.h"
#include "structs/file.h"
#include "menu.h"

int main(int argc, char **argv)
{
  char *file_name = NULL;
  size_t file_name_size = 0;

  if (argc < 2)
  {
    printf("Please enter a file name:\n");
    getline(&file_name, &file_name_size, stdin);
  }
  else
  {
    file_name = (char *)malloc(sizeof(argv[1]) * sizeof(char));
    strcpy(file_name, argv[1]);
  }

  FILE *fp;
  fp = fopen(file_name, "r");

  // create room if 'fp' is NULL -> file not probably not found
  if (fp == NULL)
  {
    fp = fopen(file_name, "w"); // Try to create a file

    if (fp == NULL)
      fprintf(stderr, "The file could not be created.\n");
  }
  fclose(fp);

  // create matrix

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

  int error = free_student(Student);
  if (error != 0)
  {
    fprintf(stderr, "free_student failed");
  }

  error = free_room(Room);
  if (error != 0)
  {
    fprintf(stderr, "free_room failed\n");
  }

  return 0;
}