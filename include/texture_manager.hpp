#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string_view>
#include <iostream>

namespace texture_manager
{
  SDL_Texture *create_texture_or_throw(SDL_Renderer *renderer, std::string_view path);
}