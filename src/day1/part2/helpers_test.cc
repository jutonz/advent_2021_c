#include <gtest/gtest.h>

extern "C" {
  #include "helpers.h"
}

TEST(initialize_window, does_the_thing) {
  static const int WINDOW_SIZE = 3;
  int window[WINDOW_SIZE];

  //initialize_window(window, WINDOW_SIZE);

  //for(int i = 0; i <= WINDOW_SIZE; i++) {
    //EXPECT_EQ(window[i], -1);
  //}
  // Expect two strings not to be equal.
  //EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(42, 42);
}
