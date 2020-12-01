#pragma once

#include <physics/entity.h>

namespace game {

namespace core {

/**
 * A class that represents a platform in the game.
 */
class Platform : public physics::Entity {
 public:
  Platform() = default;
  Platform(glm::dvec2 position, glm::dvec2 velocity,
           size_t width, size_t height)
      : physics::Entity(position, velocity, width, height) {}
};

}

}