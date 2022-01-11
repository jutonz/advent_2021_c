#ifndef DAY5_1
#define DAY5_1

#include <vector>

namespace day5 {
  class Point {
    public:
      int x;
      int y;
      Point(int x, int y);
      Point();
      bool operator==(const Point &other) const;
  };

  class Line {
    public:
      Point start;
      Point end;
      Line(Point start, Point end);
      std::vector<Point> contained_points();
  };

  class Grid {
    public:
      std::vector<std::vector<Point>> grid;
  };
}

void run5_1(const char *filename);
day5::Line read_line(std::string line);

#endif
