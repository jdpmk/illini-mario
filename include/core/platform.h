#pragma once

#include <physics/entity.h>

namespace game {

namespace core {

class Platform : public physics::Entity {
 public:
  Platform() = default;
  Platform(glm::dvec2 position, glm::dvec2 velocity, size_t width, size_t height);
};

}

}