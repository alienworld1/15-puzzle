#include "Board.h"
#include "Direction.h"
#include "UserInput.h"
#include <iostream>

int main() {
  Board board{};
  std::cout << board;

  for (int i{0}; i < 4; ++i) {
    std::cout << "generating random direction... " << generateRandomDirection()
              << '\n';
  }

  while (true) {
    char command{UserInput::readCommandFromUser()};
    if (command == 'q')
      break;
    std::cout << "You entered direction: " << convertCharToDirection(command)
              << '\n';
  }

  std::cout << "\n\nBye!\n\n";
  return 0;
}
