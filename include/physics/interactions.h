#pragma once

#include <core/player.h>
#include <core/platform.h>

namespace physics {

namespace interactions {

enum CollisionType {
  PlayerOnPlatform,
  PlayerUnderPlatform,
  NoCollision
};

CollisionType DetermineCollision(const game::core::Player& player, const game::core::Platform& platform);

}

}