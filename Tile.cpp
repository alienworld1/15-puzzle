#include "Tile.h"
#include <cassert>
#include <ostream>

Tile::Tile(int number) : m_number{number} {
  assert(number >= 0 && number <= 15 &&
         "Tiles should have a number from 0 to 15.");
}

bool Tile::isEmpty() const { return m_number == 0; }

std::ostream &operator<<(std::ostream &out, const Tile &tile) {
  out << ' ';
  if (tile.number() < 10)
    out << ' ';

  if (tile.number() == 0)
    out << "  ";
  else
    out << tile.number() << ' ';

  return out;
}