#include "../include/bird.hpp"
#include "bird.hpp"

Bird::Bird()
{
  // Initialize the position
  m_xpos = (config::window_width / 2) - (config::bird_width / 2);
  m_ypos = (config::window_height / 2) - (config::bird_height / 2);

  // Initilize the velocity
  m_xvel = 0;
  m_yvel = 0;
}

void Bird::handle_event(SDL_Event &event)
{
  if (event.type == SDL_KEYDOWN && event.key.repeat == 0)
  {
    switch (event.key.keysym.sym)
    {
    case SDLK_SPACE:
      vertical_speed = BIRD_VELOCITY;
      jump();
      break;

    default:
      break;
    }
  }
}

void Bird::jump()
{

}

SDL_Rect *Bird::update_pos()
{
  SDL_Rect *pos{new SDL_Rect};

  pos->x = m_xpos;
  pos->y = m_ypos;
  pos->w = config::bird_width;
  pos->h = config::bird_height;
  return pos;
}