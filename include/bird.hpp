#pragma once

#include "config.hpp"

#include <SDL2/SDL.h>

class Bird
{
public:

  static const int8_t DOT_VELOCITY = 5;
  Bird();
  void handle_event(SDL_Event &event);
  SDL_Rect* move();

private:
  int16_t m_xpos{}, m_ypos{};
  int16_t m_xvel{}, m_yvel{};
};