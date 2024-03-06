#pragma once
#include "bird.hpp"
#include <SDL2/SDL.h>
#include "texture_manager.hpp"

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
  texture_manager m_background_texture{m_renderer};
  texture_manager m_bird_texture{m_renderer};
  SDL_Event m_event;
  bool m_running{false};
  int scrolling_off_set{};
};