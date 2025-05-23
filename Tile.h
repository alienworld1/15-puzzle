#ifndef TILE_H
#define TILE_H

#include <ostream>

class Tile {
public:
  explicit Tile(int number);
  bool isEmpty() const;
  int number() const { return m_number; }

private:
  int m_number{};
};

std::ostream &operator<<(std::ostream &out, const Tile &tile);

#endif // !TILE_H
