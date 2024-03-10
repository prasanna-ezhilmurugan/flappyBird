#include "../include/pipe.hpp"
#include "../include/config.hpp"

Pipe::Pipe(SDL_Renderer* renderer)
:m_renderer{renderer}
{
  m_texture.load_texture(config::pipe);

  m_xpos = config::window_width - m_texture.getWidth();
  m_ypos = (config::window_height - m_texture.getHeight());
}

void Pipe::update(float delta_time){
  m_xpos -= MOVING_VELOCITY * delta_time;
}

void Pipe::render(){
  m_texture.render(m_xpos, m_ypos - 450, SDL_FLIP_VERTICAL);
  m_texture.render(m_xpos, m_ypos);
}