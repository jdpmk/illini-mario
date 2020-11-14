#pragma once

#include <physics/entity.h>

namespace physics {

class AcceleratedEntity : public Entity {
 public:
  AcceleratedEntity() = default;
  AcceleratedEntity(std::string name, glm::dvec2 position, glm::dvec2 velocity, glm::dvec2 acceleration);
  glm::dvec2 GetAcceleration();
  void SetAcceleration(const glm::dvec2& acceleration);
  void UpdateState(double dt) override;
 protected:
  glm::dvec2 acceleration_;
};

}
