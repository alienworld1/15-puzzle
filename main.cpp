#include "Board.h"
#include "Direction.h"
#include "UserInput.h"
#include <iostream>

constexpr int g_numberOfRandomSlides{200};

int main() {
  Board board{};

  // randomize the board
  for (int i{0}; i < g_numberOfRandomSlides; ++i) {
    board.moveTile(generateRandomDirection());
  }

  std::cout << board;

  while (true) {
    char command{UserInput::readCommandFromUser()};
    if (command == 'q')
      break;
    // std::cout << "You entered direction: " << convertCharToDirection(command)
    //           << '\n';
    if (board.moveTile(convertCharToDirection(command))) {
      std::cout << board;
    } else {
      std::cout << "That move is invalid.\n";
    }
  }

  std::cout << "\n\nBye!\n\n";
  return 0;
}
