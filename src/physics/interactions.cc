#include <physics/interactions.h>

namespace physics {

namespace interactions {

CollisionType DetermineCollision(const game::core::Player& player, const game::core::Platform& platform, double dt) {
  glm::dvec2 player_future_top_left = player.GetTopLeftCorner() + player.GetVelocity() * dt;
  glm::dvec2 player_future_top_right = player.GetTopRightCorner() + player.GetVelocity() * dt;
  glm::dvec2 player_future_bottom_right = player.GetBottomRightCorner() + player.GetVelocity() * dt;
  glm::dvec2 player_future_bottom_left = player.GetBottomLeftCorner() + player.GetVelocity() * dt;

  glm::dvec2 platform_future_top_left = platform.GetTopLeftCorner() + platform.GetVelocity() * dt;
  glm::dvec2 platform_future_top_right = platform.GetTopRightCorner() + platform.GetVelocity() * dt;
  glm::dvec2 platform_future_bottom_right = platform.GetBottomRightCorner() + platform.GetVelocity() * dt;
  glm::dvec2 platform_future_bottom_left = platform.GetBottomLeftCorner() + platform.GetVelocity() * dt;

  double player_future_bottom = player_future_bottom_left.y;
  double player_future_top = player_future_top_left.y;
  double player_future_left = player_future_bottom_left.x;
  double player_future_right= player_future_top_right.x;

  double platform_future_bottom = platform_future_bottom_left.y;
  double platform_future_top = platform_future_top_left.y;
  double platform_future_left = platform_future_bottom_left.x;
  double platform_future_right= platform_future_top_right.x;

  bool overlap = !(player_future_right < platform_future_left || player_future_left > platform_future_right  ||
                   player_future_top < platform_future_bottom || player_future_bottom > platform_future_top);

  if (!overlap) {
    return NoCollision;
  }

  bool on_top = player.GetVelocity().y < 0 && player_future_bottom <= platform_future_top &&
                (player_future_left < platform_future_right && player_future_right > platform_future_left);

  bool on_bottom = player.GetVelocity().y > 0 && player_future_top > platform_future_bottom &&
                   (player_future_left < platform_future_right || player_future_right > platform_future_left);

  bool on_left = player.GetVelocity().x > 0 && player_future_right > platform_future_left &&
                 (player_future_bottom < platform_future_top || player_future_top > platform_future_bottom);

  bool on_right = player.GetVelocity().x < 0 && player_future_left < platform_future_right &&
                  (player_future_bottom < platform_future_top || player_future_top > platform_future_bottom);

  if (on_top && on_left) {
    if (abs(player_future_right - platform_future_left) >= abs(player_future_bottom - platform_future_top)) {
      return PlayerOnPlatform;
    } else {
      return PlayerOnLeftOfPlatform;
    }
  }

  if (on_top && on_right) {
    if (abs(player_future_left - platform_future_right) >= abs(player_future_bottom - platform_future_top)) {
      return PlayerOnPlatform;
    } else {
      return PlayerOnRightOfPlatform;
    }
  }

  if (on_bottom && on_left) {
    if (abs(player_future_right - platform_future_left) >= abs(player_future_top - platform_future_bottom)) {
      return PlayerUnderPlatform;
    } else {
      return PlayerOnLeftOfPlatform;
    }
  }

  if (on_bottom && on_right) {
    if (abs(player_future_left - platform_future_right) >= abs(player_future_top - platform_future_bottom)) {
      return PlayerUnderPlatform;
    } else {
      return PlayerOnRightOfPlatform;
    }
  }

  if (on_top) return PlayerOnPlatform;
  if (on_bottom) return PlayerUnderPlatform;
  if (on_left) return PlayerOnLeftOfPlatform;
  if (on_right) return PlayerOnRightOfPlatform;
  return NoCollision;
}

}

}