#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "file.h"
#include "structs/file.h"
#include "menu.h"

/// @brief Main function
///
/// @param argc
/// @param argv
///@return int
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
  fclose(fp);                                         // hier nicht schließen, sondern fp ins Menü (menu_choice) mitgeben

  // create matrix

  // saveCSV(file->name, file->content);
  // readCSV(file->name);

  menu_choice();

  return 0;
}
