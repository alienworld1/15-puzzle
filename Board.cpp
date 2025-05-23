#include "Board.h"
#include "Direction.h"
#include "Point.h"
#include "Tile.h"
#include <cassert>
#include <ostream>
#include <utility>

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

Tile &Board::tileAtMutable(const Point &point) {
  assert(point.x() >= 0 && point.x() < 4 && "out of bounds");
  assert(point.y() >= 0 && point.y() < 4 && "out of bounds");

  return m_board[static_cast<std::size_t>(point.y())]
                [static_cast<std::size_t>(point.x())];
}

bool Board::moveTile(Direction direction) {
  switch (direction) {
  case Direction::Up:
    if (m_emptyTile.y() == 0)
      return false;
    break;
  case Direction::Down:
    if (m_emptyTile.y() == Board::squareSize - 1)
      return false;
    break;
  case Direction::Left:
    if (m_emptyTile.x() == 0)
      return false;
    break;
  case Direction::Right:
    if (m_emptyTile.x() == Board::squareSize - 1)
      return false;
    break;
  default:
    return false;
  }
  std::swap(tileAtMutable(m_emptyTile),
            tileAtMutable(m_emptyTile.getAdjacentPoint(direction)));
  m_emptyTile = m_emptyTile.getAdjacentPoint(direction);
  return true;
}

bool Board::areTilesInOrder() const {
  int tileCounter{1};
  constexpr int numberOfTiles{Board::squareSize * Board::squareSize};

  for (const auto &row : m_board) {
    for (const auto &tile : row) {
      if (tile.number() != tileCounter)
        return false;
      tileCounter = (tileCounter + 1) % numberOfTiles;
    }
  }
  return true;
}