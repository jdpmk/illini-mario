#pragma once

#include "cinder/gl/gl.h"

namespace game {

namespace core {

namespace constants {

/**
 * Generic Constants
 */
const size_t kDefaultWindowSize = 875;

/**
 * Control Constants
 */
const size_t kPointerToVelocityScale = 25;
const double kBeginScrollThreshold = 0.9;
const double kStopScrollThreshold = 0.67;

/**
 * Player Constants
 */
const std::string kPlayerName = "Player";
const size_t kMaxPlayerXVelocity = 50;
const double kJumpBoostVelocity = 0.5;
const glm::dvec2 kPlayerAcceleration = glm::dvec2(1, -0.5);
const size_t kPlayerWidth = 40;
const size_t kPlayerHeight = 40;

/**
 * Platform Constants
 */
const size_t kMinPlatformDeltaHeight = 110;
const size_t kMaxPlatformDeltaHeight = 130;
const size_t kMinPlatformDeltaWidth = 120;
const size_t kMaxPlatformDeltaWidth = 240;
const glm::dvec2 kPlayerStartPosition = glm::dvec2(400, 100);
const glm::dvec2 kPlayerStartVelocity = glm::dvec2(0, 0);
const glm::dvec2 kInitialPlatformPosition = glm::dvec2(400, 40);
const glm::dvec2 kInitialPlatformVelocity = glm::dvec2(0, -0.25);
const glm::dvec2 kPlatformAcceleration = glm::dvec2(0, -0.002);
const glm::dvec2 kPlatformScrollingVelocity = glm::dvec2(0, -6.67);
const size_t kPlatformWidth = 96;
const size_t kPlatformHeight = 32;

}

}

}