#include "../include/game.hpp"

int main()
{
  Game game{};
  while (game.isRunning())
  {
    game.handle_event();
    game.render();
  }
  return 0;
}
