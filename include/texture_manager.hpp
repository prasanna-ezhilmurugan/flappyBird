#pragma once

#include <SDL2/SDL.h>
#include <string_view>

class texture_manager
{
public:
  texture_manager(SDL_Renderer *renderer);
  void load_texture(std::string_view path);

  void free();
  void render(int x = 0, int y = 0, SDL_RendererFlip renderFlip = SDL_FLIP_NONE);

  int16_t getHeight() { return m_height; };
  int16_t getWidth() { return m_width; };

private:
  SDL_Renderer *m_renderer{nullptr};
  SDL_Texture *m_texture{nullptr};

  int16_t m_height{}, m_width{};
};