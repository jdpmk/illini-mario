#include <core/platform.h>

namespace game {

namespace core {

Platform::Platform(glm::dvec2 position, glm::dvec2 velocity, size_t width, size_t height)
        : physics::Entity(position, velocity, width, height) {
  width_ = width;
  height_ = height;
}

}

}