#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

FILE* open_file() {
  FILE *fp = fopen("input.txt", "r");

  if (fp == NULL) {
    perror("Could not open file\n");
    exit(1);
  }

  return fp;
}

int main() {
  FILE *fp = open_file();
  int bufferLength = 255;
  char buffer[bufferLength];

  bool initial = true;
  int previous, current;
  int increases = 0;
  while(fgets(buffer, bufferLength, fp)) {
    sscanf(buffer, "%d", &current);

    if (initial) {
      printf("%d (initial)\n", current);
    } else if (current > previous) {
      increases++;
      printf("%d (increase)\n", current);
    } else if (current < previous) {
      printf("%d (decrease)\n", current);
    } else {
      printf("%d (no change)\n", current);
    }

    initial = false;
    previous = current;
  }

  printf("There were %d increases\n", increases);
  fclose(fp);

  return 0;
}
