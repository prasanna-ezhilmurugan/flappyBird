#pragma once

#include "config.hpp"
#include <SDL2/SDL.h>

class Bird
{
public:

  static const int8_t BIRD_VELOCITY = 5;
  static const int8_t falling_constant = 2;
  Bird();
  void handle_event(SDL_Event &event);
  void jump();
  SDL_Rect *update_pos();

private:
  int m_xpos{}, m_ypos{};
  int m_xvel{}, m_yvel{};
  int vertical_speed{};
};