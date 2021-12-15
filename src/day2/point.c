#include <string.h>
#include "point.h"

void navigate(struct Point *p, char *direction, int amount) {
  if (strcmp(direction, "forward") == 0) {
    p->y += amount;
  } else if (strcmp(direction, "up") == 0) {
    p->x += amount;
  } else if (strcmp(direction, "down") == 0) {
    p->x -= amount;
  }
}
