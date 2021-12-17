#include <gtest/gtest.h>

extern "C" {
  #include "./helpers.h"
}

TEST(calculate_gamma, all_zero) {
  struct Column col1;
  col1.position = 0;
  col1.zeroes = 1;
  col1.ones = 0;
  struct Column col2;
  col2.position = 1;
  col2.zeroes = 1;
  col2.ones = 0;
  struct Column cols[] = {col1, col2};

  char *gamma = calculate_gamma(cols, 2);

  EXPECT_STREQ(gamma, "00");
}

TEST(calculate_gamma, all_one) {
  struct Column col1;
  col1.position = 0;
  col1.zeroes = 0;
  col1.ones = 1;
  struct Column col2;
  col2.position = 1;
  col2.zeroes = 0;
  col2.ones = 1;
  struct Column cols[] = {col1, col2};

  char *gamma = calculate_gamma(cols, 2);

  EXPECT_STREQ(gamma, "11");
}

TEST(calculate_epsilon, all_zero) {
  struct Column col1;
  col1.position = 0;
  col1.zeroes = 1;
  col1.ones = 0;
  struct Column col2;
  col2.position = 1;
  col2.zeroes = 1;
  col2.ones = 0;
  struct Column cols[] = {col1, col2};

  char *epsilon = calculate_epsilon(cols, 2);

  EXPECT_STREQ(epsilon, "11");
}

TEST(calculate_epsilon, all_one) {
  struct Column col1;
  col1.position = 0;
  col1.zeroes = 0;
  col1.ones = 1;
  struct Column col2;
  col2.position = 1;
  col2.zeroes = 0;
  col2.ones = 1;
  struct Column cols[] = {col1, col2};

  char *epsilon = calculate_epsilon(cols, 2);

  EXPECT_STREQ(epsilon, "00");
}
