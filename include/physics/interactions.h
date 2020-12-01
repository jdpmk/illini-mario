#pragma once

#include <core/player.h>
#include <core/platform.h>

namespace physics {

namespace interactions {

/**
 * An enum that represents the various types of collisions that may occur
 * between a player and platform.
 */
enum CollisionType {
  PlayerOnPlatform,
  PlayerUnderPlatform,
  PlayerOnLeftOfPlatform,
  PlayerOnRightOfPlatform,
  NoCollision
};

/**
 * Determines what type of collision occurred between a player and platform,
 * given a timestep.
 *
 * @param player The player
 * @param platform The platform
 * @param dt The timestep
 * @return An enum value representing what type of collision occurred
 */
CollisionType DetermineCollision(const game::core::Player& player,
                                 const game::core::Platform& platform,
                                 double dt);

}

}