#pragma once

#include "config.hpp"
#include "texture_manager.hpp"
#include <SDL2/SDL.h>

class Bird
{
public:
  Bird(SDL_Renderer *renderer);
  void handle_event(SDL_Event &event);
  void update(float delta_time);
  void render();

private:
  SDL_Renderer *m_renderer{nullptr};
  texture_manager m_texture[3] = {texture_manager(m_renderer), texture_manager(m_renderer), texture_manager(m_renderer)};
  float m_xpos{}, m_ypos{};
  int m_xvel{}, m_yvel{};
  int frame_count{};

  const int JUMP_AMPLITUDE = 120;
  // falls as a rate fo 100 pixels per second
  const int FALLING_VELOCITY = 100;
};