#include "../include/scoreboard.hpp"
#include "../include/config.hpp"

Scoreboard::Scoreboard(SDL_Renderer *renderer)
    : m_renderer(renderer)
{

  num[0].load_texture(config::sprite_0);
  num[1].load_texture(config::sprite_1);
  num[2].load_texture(config::sprite_2);
  num[3].load_texture(config::sprite_3);
  num[4].load_texture(config::sprite_4);
  num[5].load_texture(config::sprite_5);
  num[6].load_texture(config::sprite_6);
  num[7].load_texture(config::sprite_7);
  num[8].load_texture(config::sprite_8);
  num[9].load_texture(config::sprite_9);
}
void Scoreboard::update()
{
  m_score++;
}
void Scoreboard::render()
{
  // do
  // {
  //   m_score_digit.push_back(m_score % 10);
  //   m_score = std::floor(m_score / 10);
  // } while (m_score);

  // for (int i = m_score_digit.size() - 1; i >= 0; i--)
  // {
  //   num[m_score_digit[i]].render(i*config::num_width, 0);
  // }
  // }(m_score_digit.size() - i)*num[i].getWidth()
  num[0].render();
}