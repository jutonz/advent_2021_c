#include <stdio.h>
#include <stdlib.h>
#include "helpers.h"

char* calculate_gamma(struct Column *cols, int length) {
  char *gamma = (char*)malloc(sizeof(char) * (length + 1));
  gamma[length + 1] = '\0';

  for (int i = 0; i < length; i++) {
    struct Column col = cols[i];
    gamma[i] = col.zeroes > col.ones ? '0' : '1';
  }

  return gamma;
}

char* calculate_epsilon(struct Column *cols, int length) {
  char *epsilon = (char*)malloc(sizeof(char) * (length + 1));
  epsilon[length + 1] = '\0';

  for (int i = 0; i < length; i++) {
    struct Column col = cols[i];
    epsilon[i] = col.zeroes < col.ones ? '0' : '1';
  }

  return epsilon;
}
