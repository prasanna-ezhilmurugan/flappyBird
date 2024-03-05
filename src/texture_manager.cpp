#include "../include/texture_manager.hpp"

  SDL_Texture* texture_manager::create_texture_or_throw(SDL_Renderer *renderer, std::string_view path){
    SDL_Texture *texture{nullptr};

    SDL_Surface *surface = IMG_Load(path.data());
    if (!surface)
    {
      std::cout << ("Failed") << "to load the img";
      return nullptr;
    }
    else
    {
      texture = SDL_CreateTextureFromSurface(renderer, surface);
      if (!texture)
      {
        throw std::runtime_error("Failed");
        return nullptr;
      }

      return texture;
    }
  }