#pragma once

#include <string>
#include "cinder/gl/gl.h"

namespace physics {

class Entity {
 public:
  Entity() = default;
  Entity(std::string name, glm::dvec2 position, glm::dvec2 velocity);
  std::string GetName() const;
  glm::dvec2 GetPosition() const;
  glm::dvec2 GetOldPosition() const;
  glm::dvec2 GetVelocity() const;
  void SetPosition(const glm::dvec2& position);
  void SetOldPosition(const glm::dvec2& position);
  void SetVelocity(const glm::dvec2& velocity);
  virtual void UpdateState(double dt);
 protected:
  std::string name_;
  glm::dvec2 position_;
  glm::dvec2 old_position_;
  glm::dvec2 velocity_;
};

}
