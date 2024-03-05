#include "../include/bird.hpp"

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
    case SDLK_UP:
      m_yvel -= DOT_VELOCITY;
      break;
    case SDLK_DOWN:
      m_yvel += DOT_VELOCITY;
      break;
    case SDLK_LEFT:
      m_xvel -= DOT_VELOCITY;
      break;
    case SDLK_RIGHT:
      m_xvel += DOT_VELOCITY;
      break;

    default:
      break;
    }
  }
}

SDL_Rect *Bird::move()
{
  SDL_Rect *bird_pos{new SDL_Rect};
  // move the bird in x - axis
  m_xpos += m_xvel;

  if ((m_xpos < 0) || (m_xpos) > config::window_width- config::bird_width)
  {
    m_xpos -= m_xvel;
  }

  // move the bird in y - axis
  m_ypos += m_yvel;

  if ((m_ypos < 0) || (m_ypos) > config::window_height - config::bird_height)
  {
    m_ypos -= m_yvel;
  }

  bird_pos->x = m_xpos;
  bird_pos->y = m_ypos;
  bird_pos->w = config::bird_width;
  bird_pos->h = config::bird_height;

  return bird_pos;
}
