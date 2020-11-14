#pragma once

#include <physics/entity.h>

namespace game {

namespace core {

class Platform : public physics::Entity {
 public:
  Platform() = default;
  Platform(glm::dvec2 top_left_corner, glm::dvec2 bottom_right_corner);
  glm::dvec2 GetTopLeftCorner();
  glm::dvec2 GetBottomRightCorner();
 private:
  glm::dvec2 top_left_corner_;
  glm::dvec2 bottom_right_corner_;
};

}

}