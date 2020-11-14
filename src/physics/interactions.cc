#include <physics/interactions.h>

namespace physics {

namespace interactions {

CollisionType DetermineCollision(const game::core::Player& player, const game::core::Platform& platform) {
  return physics::interactions::CollisionType::NoCollision;
}

}

}