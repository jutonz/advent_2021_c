#include <gtest/gtest.h>
#include "./../part1.h"

using namespace day5;

TEST(Point_operator_eql, is_eql) {
  EXPECT_FALSE(Point(1,1) == Point(1,2));
  EXPECT_FALSE(Point(1,1) == Point(2,1));
  EXPECT_FALSE(Point(1,1) == Point(2,2));
  EXPECT_TRUE(Point(1,1) == Point(1,1));
}


TEST(Line_contained_points, returns_points_on_the_line) {
  Point start(1, -1);
  Point end(-1, 1);
  Line line(start, end);

  auto points = line.contained_points();

  EXPECT_EQ(points.size(), 3);
  EXPECT_EQ(points.at(0), Point(1, -1));
  EXPECT_EQ(points.at(1), Point(0, 0));
  EXPECT_EQ(points.at(2), Point(-1, 1));
}

TEST(read_line, creates_a_line) {
  Line line = read_line("1,1 -> 3,3");

  EXPECT_EQ(line.start, Point(1,1));
  EXPECT_EQ(line.end, Point(3,3));
}
