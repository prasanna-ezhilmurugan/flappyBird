#include "../include/texture_manager.hpp"
#include <SDL2/SDL_image.h>
#include <iostream>

texture_manager::texture_manager(SDL_Renderer *renderer)
    : m_renderer{renderer}
{
}

void texture_manager::load_texture(std::string_view path)
{
  // clear pre_existing texture
  free();

  SDL_Texture *newTexture{nullptr};

  SDL_Surface *loadedSurface = IMG_Load(path.data());
  if (!loadedSurface)
  {
    std::cout << "Unable to load image";
  }
  else
  {
    newTexture = SDL_CreateTextureFromSurface(m_renderer, loadedSurface);

    if (!newTexture)
    {
      std::cout << "Unable to create texture form the surface";
    }
    else
    {
      // getimage dimentions
      m_width = loadedSurface->w;
      m_height = loadedSurface->h;
    }

    SDL_FreeSurface(loadedSurface);
  }
  m_texture = newTexture;
}

void texture_manager::render(int x, int y, SDL_RendererFlip renderFlip)
{
  SDL_Rect renderQuad = {x, y, m_width, m_height};

  SDL_RenderCopyEx(m_renderer, m_texture, NULL, &renderQuad, 0.0, NULL, renderFlip);
}

void texture_manager::free()
{
  if (m_texture)
  {
    SDL_DestroyTexture(m_texture);
    m_texture = nullptr;
    m_height = 0;
    m_width = 0;
  }
}