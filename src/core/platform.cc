#include "core/platform.h"

namespace game {

namespace core {

Platform::Platform(glm::dvec2 position,
                   glm::dvec2 velocity,
                   glm::dvec2 acceleration,
                   size_t width,
                   size_t height)
: physics::Entity(position, velocity, acceleration, width, height) {
  visited_ = false;
}

bool Platform::GetVisited() const {
  return visited_;
}

void Platform::SetVisited(bool visited) {
  visited_ = visited;
}

}

}
