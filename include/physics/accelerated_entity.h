#pragma once

#include <physics/entity.h>

namespace physics {

class AcceleratedEntity : public Entity {
 public:
  AcceleratedEntity(std::string name, glm::dvec2 position, glm::dvec2 velocity, glm::dvec2 acceleration);
  glm::dvec2 GetAcceleration();
  void UpdateState() override;
 protected:
  glm::dvec2 acceleration_;
};

}
