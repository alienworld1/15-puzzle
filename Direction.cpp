#include "Direction.h"
#include "Random.h"
#include <ostream>
#include <string_view>

std::string_view convertDirectionToString(Direction direction) {
  switch (direction) {
  case Direction::Down:
    return "down";
  case Direction::Left:
    return "left";
  case Direction::Right:
    return "right";
  case Direction::Up:
    return "up";
  }

  // same purpose as in the convertCharToDirection function
  // just to shut the compiler up
  return "???";
}

std::ostream &operator<<(std::ostream &out, Direction direction) {
  out << convertDirectionToString(direction);
  return out;
}

Direction operator-(Direction direction) {
  using enum Direction;
  switch (direction) {
  case Up:
    return Down;
  case Down:
    return Up;
  case Left:
    return Right;
  case Right:
    return Left;
  }

  // same purpose as in the convertCharToDirection function
  // just to shut the compiler up
  return Right;
}

Direction generateRandomDirection() {
  int direction{Random::get(0, 3)};
  return static_cast<Direction>(direction);
}

Direction convertCharToDirection(char ch) {
  switch (ch) {
  case 'w':
    return Direction::Up;
  case 'a':
    return Direction::Left;
  case 's':
    return Direction::Down;
  case 'd':
    return Direction::Right;
  }

  // this should never happen if the function is used correctly
  // so ill leave it like this
  return Direction::Right;
}