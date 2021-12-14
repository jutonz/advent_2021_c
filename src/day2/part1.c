#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../file.h"

int main(int argc, char *argv[]) {
  if (argc != 2) {
    char error[256];
    snprintf(error, 256, "Usage: %s /path/to/input.txt", argv[0]);
    printf("%s\n", error);
    exit(1);
  }

  FILE *fp = open_file(argv[1]);
  static const short BUFFER_LENGTH = 255;
  char buffer[BUFFER_LENGTH];

  char direction[255];
  int amount;
  int x = 0;
  int y = 0;
  while(fgets(buffer, BUFFER_LENGTH, fp)) {
    sscanf(buffer, "%s %d\n", direction, &amount);

    if (strcmp(direction, "forward") == 0) {
      y += amount;
    } else if (strcmp(direction, "up") == 0) {
      x += amount;
    } else if (strcmp(direction, "down") == 0) {
      x -= amount;
    }

    printf("Direction: %s; Amount: %d; x %d; y %d\n", direction, amount, x, y);
  }

  printf("Position is %d x %d\n", x, y);
  printf("Multiplied, that's %d\n", x * y);

  return 0;
}
