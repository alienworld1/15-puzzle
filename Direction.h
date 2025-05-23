#ifndef DIRECTION_H
#define DIRECTION_H

#include <ostream>
#include <string_view>

enum class Direction { Up, Down, Left, Right };

std::string_view convertDirectionToString(Direction direction);
Direction operator-(Direction direction);
std::ostream &operator<<(std::ostream &out, Direction direction);
Direction generateRandomDirection();
Direction convertCharToDirection(char ch);

#endif // !DIRECTION_H
