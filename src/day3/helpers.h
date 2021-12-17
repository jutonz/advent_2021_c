#ifndef DAY3_1
#define DAY3_1

struct Column {
  int position;
  int zeroes;
  int ones;
};

char* calculate_gamma(struct Column *cols, int length);
char* calculate_epsilon(struct Column *cols, int length);

#endif
