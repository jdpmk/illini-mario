#pragma once

#include "physics/accelerated_entity.h"

namespace game {

namespace core {

class Player : public physics::AcceleratedEntity {
 public:
  Player() = default;
  Player(std::string name, glm::dvec2 position, glm::dvec2 velocity, glm::dvec2 acceleration, size_t width, size_t height);
  size_t GetScore();
  size_t GetWidth();
  size_t GetHeight();
  glm::dvec2 GetTopLeftCorner();
  glm::dvec2 GetTopRightCorner();
  glm::dvec2 GetBottomLeftCorner();
  glm::dvec2 GetBottomRightCorner();
 private:
  size_t score_;
  size_t width_;
  size_t height_;
};

}

}