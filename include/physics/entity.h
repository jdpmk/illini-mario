#pragma once

#include <string>
#include "cinder/gl/gl.h"

namespace physics {

class Entity {
 public:
  Entity(std::string name, glm::dvec2 position, glm::dvec2 velocity);
  std::string GetName();
  glm::dvec2 GetPosition();
  glm::dvec2 GetVelocity();
  virtual void UpdateState();
 protected:
  std::string name_;
  glm::dvec2 position_;
  glm::dvec2 velocity_;
};

}
