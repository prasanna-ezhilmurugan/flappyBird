#include "../include/pipe.hpp"
#include "../include/config.hpp"

Pipe::Pipe(SDL_Renderer *renderer, float ypos)
    : m_renderer{renderer},
      m_ypos{ypos}
{
  m_texture.load_texture(config::pipe);

  m_xpos = config::window_width - m_texture.getWidth();
}

void Pipe::update(float delta_time)
{
  m_xpos -= MOVING_VELOCITY * delta_time;
}

void Pipe::render()
{
  m_texture.render(m_xpos, m_ypos, SDL_FLIP_VERTICAL);
  m_texture.render(m_xpos, m_ypos + 450);
}
SDL_Rect Pipe::getUpperRect()
{
  SDL_Rect rect{};
  rect.x = m_xpos;
  rect.y = m_ypos;
  rect.w = m_texture.getWidth();
  rect.h = m_texture.getHeight();

  return rect;
}
SDL_Rect Pipe::getLowerRect()
{
  SDL_Rect rect{};
  rect.x = m_xpos;
  rect.y = m_ypos;
  rect.w = m_texture.getWidth();
  rect.h = m_texture.getHeight();

  return rect;
}