#pragma once

#include <string_view>

namespace config
{
  constexpr int window_width{288 * 3};
  constexpr int window_height{512};
  constexpr int bird_width{34};
  constexpr int bird_height{24};
  constexpr int num_width{24};

  constexpr std::string_view projectName{"flappyBird"};
  constexpr std::string_view background_sprite{"../assets/sprites/background-day.png"};
  constexpr std::string_view base_sprite{"../assets/sprites/base.png"};
  constexpr std::string_view bird_downflap{"../assets/sprites/bluebird-downflap.png"};
  constexpr std::string_view bird_midflap{"../assets/sprites/bluebird-midflap.png"};
  constexpr std::string_view bird_upflap{"../assets/sprites/bluebird-upflap.png"};

  constexpr std::string_view pipe{"../assets/sprites/pipe-green.png"};

  constexpr std::string_view sprite_0{"../assets/sprites/0.png"};
  constexpr std::string_view sprite_1{"../assets/sprites/1.png"};
  constexpr std::string_view sprite_2{"../assets/sprites/2.png"};
  constexpr std::string_view sprite_3{"../assets/sprites/3.png"};
  constexpr std::string_view sprite_4{"../assets/sprites/4.png"};
  constexpr std::string_view sprite_5{"../assets/sprites/5.png"};
  constexpr std::string_view sprite_6{"../assets/sprites/6.png"};
  constexpr std::string_view sprite_7{"../assets/sprites/7.png"};
  constexpr std::string_view sprite_8{"../assets/sprites/8.png"};
  constexpr std::string_view sprite_9{"../assets/sprites/9.png"};
}