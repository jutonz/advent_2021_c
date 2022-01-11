#include <iostream>
#include <fstream>
#include "./part1.h"

using namespace day5;
using std::fstream;
using std::string;
using std::vector;

Point::Point(int x_value, int y_value) {
  x = x_value;
  y = y_value;
}

Point::Point() {
  x = 0;
  y = 0;
}

bool Point::operator==(const Point &other) const {
  return this->x == other.x && this->y == other.y;
}

Line::Line(Point start_p, Point end_p) {
  start = start_p;
  end = end_p;
}

Line read_line(string line) {
  int p1x, p1y, p2x, p2y;
  sscanf(line.c_str(), "%d,%d -> %d,%d", &p1x, &p1y, &p2x, &p2y);

  Point start(p1x, p1y);
  Point end(p2x, p2y);

  return Line(start, end);
}

vector<Point> Line::contained_points() {
  vector<Point> points;
  //points.push_back(start);



  return points;
}

void run5_1(const char *filename) {
  fstream file;
  file.open(filename, std::ios::in);
}
