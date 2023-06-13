#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "file.h"
#include "menu.h"
#include "contact_tracing.h"
#include "csv_read.h"

/**
 * @brief       Main function - entry point
 *
 * @param       argc
 * @param       argv
 * @return      int
 */
int main(int argc, char **argv)
{
  char *file_name = NULL;
  size_t file_name_size = 0;

  if (argc < 2)
  {
    printf("Please enter a file name:\n");
    //getline(&file_name, &file_name_size, stdin);
    char temp[MAX_STRING];
    file_name = (char *)malloc(sizeof(char)*MAX_STRING);
    scanf("%[^\n]", &temp);
    strcpy(file_name, temp);
  }
  else
  {
    file_name = (char *)malloc(sizeof(argv[1]) * sizeof(char));
    strcpy(file_name, argv[1]);
  }

/*
  FILE *fp;
  fp = fopen(file_name, "r");

  // if 'fp' is NULL create room
  if (fp == NULL)
  {
    fp = fopen(file_name, "w"); // Try to create a file

    if (fp == NULL)
      fprintf(stderr, "The file could not be created.\n");
  }
*/
  menu_choice(file_name);

if (file_name != NULL) {
  free(file_name);
}
 // fclose(fp);

  return 0;
}
