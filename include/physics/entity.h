#pragma once

#include <string>
#include "cinder/gl/gl.h"

namespace physics {

class Entity {
 public:
  Entity() = default;
  Entity(glm::dvec2 position, glm::dvec2 velocity, size_t width, size_t height);
  glm::dvec2 GetPosition() const;
  glm::dvec2 GetVelocity() const;
  size_t GetWidth() const;
  size_t GetHeight() const;
  glm::dvec2 GetTopLeftCorner() const;
  glm::dvec2 GetBottomLeftCorner() const;
  glm::dvec2 GetTopRightCorner() const;
  glm::dvec2 GetBottomRightCorner() const;
  void SetPosition(const glm::dvec2& position);
  void SetVelocity(const glm::dvec2& velocity);
  virtual void UpdateState(double dt);
 protected:
  glm::dvec2 position_;
  glm::dvec2 velocity_;
  size_t width_;
  size_t height_;
};

}
