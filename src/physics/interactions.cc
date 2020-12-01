#include "physics/interactions.h"

namespace physics {

namespace interactions {

CollisionType DetermineCollision(const game::core::Player& player,
                                 const game::core::Platform& platform,
                                 double dt) {
  glm::dvec2 player_top_left =
          player.GetTopLeftCorner() + player.GetVelocity() * dt;
  glm::dvec2 player_top_right =
          player.GetTopRightCorner() + player.GetVelocity() * dt;
  glm::dvec2 player_bottom_right =
          player.GetBottomRightCorner() + player.GetVelocity() * dt;
  glm::dvec2 player_bottom_left =
          player.GetBottomLeftCorner() + player.GetVelocity() * dt;

  glm::dvec2 platform_top_left =
          platform.GetTopLeftCorner() + platform.GetVelocity() * dt;
  glm::dvec2 platform_top_right =
          platform.GetTopRightCorner() + platform.GetVelocity() * dt;
  glm::dvec2 platform_bottom_right =
          platform.GetBottomRightCorner() + platform.GetVelocity() * dt;
  glm::dvec2 platform_bottom_left =
          platform.GetBottomLeftCorner() + platform.GetVelocity() * dt;

  double player_bottom = player_bottom_left.y;
  double player_top = player_top_left.y;
  double player_left = player_bottom_left.x;
  double player_right = player_top_right.x;

  double platform_bottom = platform_bottom_left.y;
  double platform_top = platform_top_left.y;
  double platform_left = platform_bottom_left.x;
  double platform_right = platform_top_right.x;

  // Determine if there is any possibility for collisions
  bool overlap = !(player_right < platform_left ||
                   player_left > platform_right ||
                   player_top < platform_bottom ||
                   player_bottom > platform_top);

  if (!overlap) return NoCollision;

  // Determine the relative positioning of the player to narrow down which
  // collisions are possible
  bool on_top = player.GetVelocity().y < 0 && player_bottom <= platform_top &&
                (player_left < platform_right && player_right > platform_left);
  bool on_bottom = player.GetVelocity().y > 0 && player_top > platform_bottom &&
                   (player_left < platform_right ||
                    player_right > platform_left);
  bool on_left = player.GetVelocity().x > 0 && player_right > platform_left &&
                 (player_bottom < platform_top || player_top > platform_bottom);
  bool on_right = player.GetVelocity().x < 0 && player_left < platform_right &&
                  (player_bottom < platform_top ||
                   player_top > platform_bottom);

  // Handle special cases where more than one collision is possible
  // Assume that the collision that results in greater overlap occurred first
  // and therefore is the collision result
  if (on_top && on_left) {
    if (abs(player_right - platform_left) >=
        abs(player_bottom - platform_top)) {
      return PlayerOnPlatform;
    } else {
      return PlayerOnLeftOfPlatform;
    }
  }

  if (on_top && on_right) {
    if (abs(player_left - platform_right) >=
        abs(player_bottom - platform_top)) {
      return PlayerOnPlatform;
    } else {
      return PlayerOnRightOfPlatform;
    }
  }

  if (on_bottom && on_left) {
    if (abs(player_right - platform_left) >=
        abs(player_top - platform_bottom)) {
      return PlayerUnderPlatform;
    } else {
      return PlayerOnLeftOfPlatform;
    }
  }

  if (on_bottom && on_right) {
    if (abs(player_left - platform_right) >=
        abs(player_top - platform_bottom)) {
      return PlayerUnderPlatform;
    } else {
      return PlayerOnRightOfPlatform;
    }
  }

  // If only one collision occurred, return the respective collision
  if (on_top) return PlayerOnPlatform;
  if (on_bottom) return PlayerUnderPlatform;
  if (on_left) return PlayerOnLeftOfPlatform;
  if (on_right) return PlayerOnRightOfPlatform;

  // Default return value, if for some reason all other conditions were not met
  return NoCollision;
}

}

}