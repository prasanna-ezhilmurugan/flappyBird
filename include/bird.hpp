#pragma once

#include "config.hpp"
#include "texture_manager.hpp"
#include <SDL2/SDL.h>

class Bird
{
public:
  Bird(SDL_Renderer *renderer);
  void handle_event(SDL_Event &event);
  void update();
  void render();

private:
  SDL_Renderer *m_renderer{nullptr};
  // Test obj[] = { Test(1, 1), Test(2, 2), Test(3, 3) };
  texture_manager m_texture[3] = {texture_manager(m_renderer), texture_manager(m_renderer), texture_manager(m_renderer)};
  float m_xpos{}, m_ypos{};
  int m_xvel{}, m_yvel{};
  float m_lastTick{};

  const int JUMP_AMPLITUDE = 120;
  // falls as a rate fo 100 pixels per second
  const int FALLING_VELOCITY = 100;
};