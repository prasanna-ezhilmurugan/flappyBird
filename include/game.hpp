#pragma once
#include "bird.hpp"
#include <SDL2/SDL.h>

class Game
{
public:
  Game();
  ~Game();
  void handle_event();
  void render();

  bool isRunning() { return m_running; };

private:
  Bird bird{};
  SDL_Window *m_window{nullptr};
  SDL_Renderer *m_renderer{nullptr};
  SDL_Event m_event;
  bool m_running{false};
};