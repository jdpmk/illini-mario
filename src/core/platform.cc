#include <core/platform.h>

namespace game {

namespace core {

Platform::Platform(std::string name, glm::dvec2 position, glm::dvec2 velocity, glm::dvec2 top_left_corner, glm::dvec2 bottom_right_corner) {
  name_ = name;
  position_ = position;
  velocity_ = velocity;
  top_left_corner_ = top_left_corner;
  bottom_right_corner_ = bottom_right_corner;
}

glm::dvec2 Platform::GetTopLeftCorner() {
  return top_left_corner_;
}

glm::dvec2 Platform::GetBottomRightCorner() {
  return bottom_right_corner_;
}

}

}