#include "Board.h"
#include <ostream>

std::ostream &operator<<(std::ostream &out, const Board &board) {
  for (int i{0}; i < g_consoleLines; ++i) {
    out << '\n';
  }

  for (const auto &row : board.m_board) {
    for (const auto &tile : row) {
      out << tile;
    }
    out << '\n';
  }
  return out;
}