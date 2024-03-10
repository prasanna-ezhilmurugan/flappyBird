#pragma once
#include "bird.hpp"
#include "texture_manager.hpp"
#include "pipe.hpp"
#include <SDL2/SDL.h>
#include <vector>
class Game
{
public:
  Game();
  ~Game();
  void handle_event();
  void update();
  void render();

  bool isRunning() { return m_running; };

private:
  SDL_Window *m_window{nullptr};
  SDL_Renderer *m_renderer{nullptr};
  SDL_Event m_event;
  texture_manager m_background_texture{m_renderer};
  texture_manager m_base_texture{m_renderer};
  SDL_Rect bird_rect, pipe_upper_rect, pipe_lower_rect, collision_rect;
  Bird bird{m_renderer};
  std::vector<Pipe> pipes;
  int pipe_gap{};
  bool m_running{false};
  int scrolling_off_set{};
  float m_lastTick{};
  void render_background();
};