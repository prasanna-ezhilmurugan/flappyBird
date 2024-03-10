#include "../include/bird.hpp"

Bird::Bird(SDL_Renderer *renderer)
    : m_renderer{renderer}
{
  m_texture[0].load_texture(config::bird_downflap);
  m_texture[1].load_texture(config::bird_midflap);
  m_texture[2].load_texture(config::bird_upflap);
  // Initialize the position
  m_xpos = (config::window_width - config::bird_width)/3;
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
      m_ypos -= JUMP_AMPLITUDE;
      break;

    default:
      break;
    }
  }
}

void Bird::update(float delta_time)
{
  m_ypos += FALLING_VELOCITY* delta_time ;
}

void Bird::render()
{
  m_texture[frame_count].render(m_xpos, m_ypos);
  ++frame_count;
  frame_count = frame_count%3;
}

SDL_Rect Bird::getRect(){
  SDL_Rect rect{};
  rect.x = m_xpos;
  rect.y = m_ypos;
  rect.w = config::bird_width;
  rect.h = config::bird_height;

  return rect;
}