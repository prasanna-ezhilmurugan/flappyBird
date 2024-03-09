#pragma once

#include <string_view>

namespace config
{
  constexpr int window_width{288};
  constexpr int window_height{512};
  constexpr int bird_width{34};
  constexpr int bird_height{24};

  constexpr std::string_view projectName{"flappyBird"};
  constexpr std::string_view background_sprite{"../assets/sprites/background-day.png"};
  constexpr std::string_view base_sprite{"../assets/sprites/base.png"};
  constexpr std::string_view bird_downflap{"../assets/sprites/bluebird-downflap.png"};
  constexpr std::string_view bird_midflap{"../assets/sprites/bluebird-midflap.png"};
  constexpr std::string_view bird_upflap{"../assets/sprites/bluebird-upflap.png"};

}