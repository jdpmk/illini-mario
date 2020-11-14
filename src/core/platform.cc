#include <core/platform.h>

namespace game {

namespace core {

Platform::Platform(glm::dvec2 top_left_corner, glm::dvec2 bottom_right_corner) {
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