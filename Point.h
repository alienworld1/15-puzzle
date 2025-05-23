#ifndef POINT_H
#define POINT_H

#include "Direction.h"

class Point {
public:
  int x() const { return m_x; }
  int y() const { return m_y; }
  Point getAdjacentPoint(Direction direction) const;
  Point(int x = 0, int y = 0);

private:
  int m_x{};
  int m_y{};
};

bool operator==(const Point &p1, const Point &p2);
bool operator!=(const Point &p1, const Point &p2);

#endif // !POINT_H
