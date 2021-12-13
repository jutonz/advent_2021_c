#include <stdio.h>
#include <stdlib.h>
#include "helpers.h"

FILE* open_file(const char *filename) {
  FILE *fp = fopen(filename, "r");

  if (fp == NULL) {
    perror("Could not open file\n");
    exit(1);
  }

  return fp;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    char error[256];
    snprintf(error, 256, "Usage: %s /path/to/input.txt", argv[0]);
    printf("%s\n", error);
    exit(1);
  }

  static const int WINDOW_SIZE = 3;
  int window[WINDOW_SIZE];
  initialize_window(window, WINDOW_SIZE);

  return 0;
}
