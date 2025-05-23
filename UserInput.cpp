#include "UserInput.h"
#include <ios>
#include <iostream>
#include <limits>

char UserInput::readCommandFromUser() {
  char command{};

  while (true) {
    std::cin >> command;
    if (!std::cin) {
      std::cin.clear();
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    switch (command) {
    case 'w':
    case 'a':
    case 's':
    case 'd':
    case 'q':
      return command;
    }
  }
}