#include "Point.h"
#include "Direction.h"

bool operator==(const Point &p1, const Point &p2) {
  return p1.x() == p2.x() && p1.y() == p2.y();
}

bool operator!=(const Point &p1, const Point &p2) { return !(p1 == p2); }

Point::Point(int x, int y) : m_x{x}, m_y{y} {}

Point Point::getAdjacentPoint(Direction direction) const {
  switch (direction) {
  case Direction::Down:
    return {m_x, m_y + 1};
  case Direction::Up:
    return {m_x, m_y - 1};
  case Direction::Left:
    return {m_x - 1, m_y};
  case Direction::Right:
    return {m_x + 1, m_y};
  default:
    // unknown case, shouldn't happen
    return {0, 0};
  }
}