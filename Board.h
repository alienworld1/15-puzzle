#ifndef BOARD_H
#define BOARD_H

#include "Tile.h"
#include <array>
#include <ostream>

constexpr inline int g_consoleLines{25};

class Board {
public:
  Board() = default;
  friend std::ostream &operator<<(std::ostream &out, const Board &board);

private:
  static constexpr int squareSize{4};
  std::array<std::array<Tile, squareSize>, squareSize> m_board{
      {{Tile{1}, Tile{2}, Tile{3}, Tile{4}},

       {Tile{5}, Tile{6}, Tile{7}, Tile{8}},

       {Tile{9}, Tile{10}, Tile{11}, Tile{12}},

       {Tile{13}, Tile{14}, Tile{15}, Tile{0}}

      }};
};

#endif // !BOARD_H
