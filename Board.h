#ifndef BOARD_H
#define BOARD_H

#include "Direction.h"
#include "Point.h"
#include "Tile.h"
#include <array>
#include <ostream>

constexpr inline int g_consoleLines{25};

class Board {
public:
  Board() = default;
  friend std::ostream &operator<<(std::ostream &out, const Board &board);
  // returns true if the tile was successfully moved, false otherwise
  bool moveTile(Direction direction);
  const Tile &tileAt(const Point &point) const;

private:
  static constexpr int squareSize{4};
  std::array<std::array<Tile, squareSize>, squareSize> m_board{
      {{Tile{1}, Tile{2}, Tile{3}, Tile{4}},

       {Tile{5}, Tile{6}, Tile{7}, Tile{8}},

       {Tile{9}, Tile{10}, Tile{11}, Tile{12}},

       {Tile{13}, Tile{14}, Tile{15}, Tile{0}}

      }};
  Point m_emptyTile{3, 3};
  Tile &tileAtMutable(const Point &point);
};

#endif // !BOARD_H
