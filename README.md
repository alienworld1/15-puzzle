To compile this, use the command:
```powershell
g++ main.cpp Tile.cpp Board.cpp UserInput.cpp Direction.cpp Point.cpp -O2 -DNDEBUG -pedantic-errors -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -Werror -std=c++23 -o main
```
and to run:
```powershell
.\main
```
If c++23 is not supported by your compiler, anything above c++17 is fine, I think.
