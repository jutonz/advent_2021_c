#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../file.h"
#include "./helpers.h"

static const short BUFFER_LENGTH = 255;
int main(int argc, char *argv[]) {
  char *filename = check_args(argc, argv);
  char buffer[BUFFER_LENGTH];
  FILE *fp = open_file(filename);

  bool first_line = true;
  struct Column *columns;
  int length;

  while(fgets(buffer, BUFFER_LENGTH, fp)) {
    if (first_line) {
      length = strlen(buffer) - 1;
      printf("length is %d\n", length);
      columns = (struct Column*)malloc(sizeof(struct Column) * length);
      for(int i = 0; i < length; i++) {
        struct Column column = {i, 0, 0};
        columns[i] = column;
      }
      first_line = false;
    }

    for (int i = 0; i < length; i++) {
      char ch = buffer[i];
      if (ch == '0') {
        columns[i].zeroes++;
      } else {
        columns[i].ones++;
      }
    }
  }

  char *gamma = calculate_gamma(columns, length);
  char *epsilon = calculate_epsilon(columns, length);

  int gamma_i = strtol(gamma, NULL, 2);
  int epsilon_i = strtol(epsilon, NULL, 2);

  printf("gamma: %d; epsilon: %d\n", gamma_i, epsilon_i);
  printf("Power consumption: %d\n", gamma_i * epsilon_i);

  return 0;
}
