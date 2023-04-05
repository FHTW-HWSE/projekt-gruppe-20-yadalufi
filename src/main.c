#include <stdlib.h>
#include "file.h"

int main()
{
  struct File *file = malloc(sizeof(struct File));
  file->name = "test.csv";
  file->content = "Example content";

  saveCSV(file->name, file->content);
  readCSV(file->name);

  return 0;
}
