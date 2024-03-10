#pragma once

#include <SDL2/SDL.h>
#include <vector>
#include "texture_manager.hpp"

class Scoreboard
{
public:
  Scoreboard(SDL_Renderer* renderer);
  void update();
  void render();
private:
  SDL_Renderer* m_renderer{nullptr};
  texture_manager num[10] = {
    texture_manager(m_renderer),
    texture_manager(m_renderer),
    texture_manager(m_renderer),
    texture_manager(m_renderer),
    texture_manager(m_renderer),
    texture_manager(m_renderer),
    texture_manager(m_renderer),
    texture_manager(m_renderer),
    texture_manager(m_renderer),
    texture_manager(m_renderer),
  };

  int m_score{};
  std::vector<int> m_score_digit{};
};