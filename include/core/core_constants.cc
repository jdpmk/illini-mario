#include <stdlib.h>

#include "cinder/gl/gl.h"

namespace game {

namespace core {

namespace constants {

/**
 * Control Constants
 */
const size_t kPointerToVelocityScale = 25;

/**
 * Player Constants
 */
const std::string kPlayerName = "Player";
const size_t kMaxPlayerXVelocity = 50;
const double kJumpBoostVelocity = 0.375;
const glm::dvec2 kPlayerAcceleration = glm::dvec2(1, -0.5);
const size_t kPlayerWidth = 40;
const size_t kPlayerHeight = 40;

/**
 * Platform Constants
 */
const size_t kMinPlatformDeltaHeight = 80;
const size_t kMaxPlatformDeltaHeight = 100;
const size_t kMinPlatformDeltaWidth = 100;
const size_t kMaxPlatformDeltaWidth = 200;
const glm::dvec2 kPlayerStartPosition = glm::dvec2(400, 100);
const glm::dvec2 kPlayerStartVelocity = glm::dvec2(0, 0);
const glm::dvec2 kInitialPlatformPosition = glm::dvec2(400, 20);
const glm::dvec2 kInitialPlatformVelocity = glm::dvec2(0, -0.25);
const glm::dvec2 kPlatformAcceleration = glm::dvec2(0, -0.001);
const size_t kPlatformWidth = 100;
const size_t kPlatformHeight = 10;

}

}

}