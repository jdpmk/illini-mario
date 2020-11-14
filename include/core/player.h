#pragma once

#include "physics/accelerated_entity.h"

namespace game {

namespace core {

class Player : public physics::AcceleratedEntity {
 public:
  Player() = default;
  Player(const std::string& name, const glm::dvec2& position, const glm::dvec2& velocity, const glm::dvec2& acceleration, size_t width, size_t height);
  size_t GetScore() const;
  size_t GetWidth() const;
  size_t GetHeight() const;
  glm::dvec2 GetTopLeftCorner() const;
  glm::dvec2 GetBottomRightCorner() const;
 private:
  size_t score_;
  size_t width_;
  size_t height_;
};

}

}