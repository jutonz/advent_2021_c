#include <stdio.h>
#include <stdlib.h>

FILE* open_file(const char *filename) {
  FILE *fp = fopen(filename, "r");

  if (fp == NULL) {
    perror("Could not open file\n");
    exit(1);
  }

  return fp;
}
