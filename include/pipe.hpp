#pragma once

#include "texture_manager.hpp"
#include <SDL2/SDL.h>

class Pipe{
  public:
  Pipe(SDL_Renderer* renderer, float ypos);
  void update(float delta_time);
  void render();
  SDL_Rect getUpperRect();
  SDL_Rect getLowerRect();

  private:
  SDL_Renderer* m_renderer{nullptr};
  texture_manager m_texture{m_renderer};

  float m_xpos{}, m_ypos{};
  float m_lastTicks{};
  int MOVING_VELOCITY{180};
};