#include "../include/game.hpp"
#include "../include/texture_manager.hpp"
#include "../include/config.hpp"
#include <iostream>

#include <SDL2/SDL_image.h>
#include <stdexcept>

namespace loader
{
  SDL_Window *create_window_or_throw()
  {
    SDL_Window *window =
        SDL_CreateWindow(config::projectName.data(), SDL_WINDOWPOS_CENTERED,
                         SDL_WINDOWPOS_CENTERED, config::window_width,
                         config::window_height, SDL_WINDOW_SHOWN);

    if (!window)
    {
      throw std::runtime_error("Failed");
      return nullptr;
    }

    return window;
  }

  SDL_Renderer *create_renderer_or_throw(SDL_Window *window)
  {
    SDL_Renderer *renderer = SDL_CreateRenderer(
        window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (!renderer)
    {
      throw std::runtime_error("Failed");
      return nullptr;
    }

    return renderer;
  }

} // namespace loader

Game::Game()
    : m_window{loader::create_window_or_throw()},
      m_renderer{loader::create_renderer_or_throw(m_window)}
{
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    throw std::runtime_error("Failed to initialize SDL");
  }
  if (!(IMG_Init(IMG_INIT_PNG) &
        IMG_INIT_PNG))
  { // Correct the function name from IMG_INTI_PNG to
    // IMG_INIT_PNG
    throw std::runtime_error("Failed to initialize IMG");
  }

  m_running = true;
}

void Game::handle_event()
{
  while (SDL_PollEvent(&m_event))
  {
    if (m_event.type == SDL_QUIT)
    {
      m_running = false;
    }
    else
    {
      bird.handle_event(m_event);
    }
  }
}

void Game::render()
{
  SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
  SDL_RenderClear(m_renderer);

  --scrolling_off_set;
  if (scrolling_off_set < -m_background_texture.getWidth())
  {
    scrolling_off_set = 0;
  }

  m_background_texture.load_texture(config::background_sprite);
  m_bird_texture.load_texture(config::bird_sprite);
  m_background_texture.render(scrolling_off_set, 0);
  m_background_texture.render(scrolling_off_set + m_background_texture.getWidth(), 0);
  m_bird_texture.render(bird.move()->x, bird.move()->y);
  SDL_RenderPresent(m_renderer);
}

Game::~Game()
{
  IMG_Quit();
  SDL_Quit();
}