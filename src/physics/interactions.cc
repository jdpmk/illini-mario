#include <physics/interactions.h>

namespace physics {

namespace interactions {

CollisionType DetermineCollision(const game::core::Player& player, const game::core::Platform& platform) {
  size_t player_bottom = player.GetPosition().y - player.GetHeight() / 2;
  size_t player_top = player.GetPosition().y + player.GetHeight() / 2;
  size_t player_left = player.GetPosition().x - player.GetWidth() / 2;
  size_t player_right = player.GetPosition().x + player.GetWidth() / 2;

  size_t player_old_bottom = player.GetOldPosition().y - player.GetHeight() / 2;
  size_t player_old_top = player.GetOldPosition().y + player.GetHeight() / 2;
  size_t player_old_left = player.GetOldPosition().x - player.GetWidth() / 2;
  size_t player_old_right = player.GetOldPosition().x + player.GetWidth() / 2;

  size_t platform_bottom = platform.GetPosition().y - platform.GetHeight() / 2;
  size_t platform_top = platform.GetPosition().y + platform.GetHeight() / 2;
  size_t platform_left = platform.GetPosition().x - platform.GetWidth() / 2;
  size_t platform_right = platform.GetPosition().x + platform.GetWidth() / 2;

  size_t platform_old_bottom = platform.GetOldPosition().y - platform.GetHeight() / 2;
  size_t platform_old_top = platform.GetOldPosition().y + platform.GetHeight() / 2;
  size_t platform_old_left = platform.GetOldPosition().x - platform.GetWidth() / 2;
  size_t platform_old_right = platform.GetOldPosition().x + platform.GetWidth() / 2;

  bool falling_on_top = player_bottom <= platform_top &&
                        player_old_bottom >= platform_old_top;
  bool hitting_from_under = player_top >= platform_bottom &&
                            player_old_top < platform_old_bottom;
  bool hitting_from_left = player_right >= platform_left &&
                           player_old_right <= platform_old_left;
  bool hitting_from_right = player_left <= platform_right &&
                           player_old_left >= platform_old_right;

  if (falling_on_top) {
    std::cout << "On Platform" << std::endl;
    return PlayerOnPlatform;
  }
  if (hitting_from_under) {
    std::cout << "Under Platform" << std::endl;
    return PlayerUnderPlatform;
  }
  if (hitting_from_left) {
    std::cout << "Left of Platform" << std::endl;
    return PlayerOnLeftOfPlatform;
  }
  if (hitting_from_right) {
    std::cout << "Right of Platform" << std::endl;
    return PlayerOnRightOfPlatform;
  }
  std::cout << "No Collision" << std::endl;
  return NoCollision;
}

}

}