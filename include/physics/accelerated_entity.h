#pragma once

#include <physics/entity.h>

namespace physics {

class AcceleratedEntity : public Entity {
 public:
  AcceleratedEntity() = default;
  AcceleratedEntity(glm::dvec2 position, glm::dvec2 velocity, glm::dvec2 acceleration, size_t width, size_t height);
  glm::dvec2 GetAcceleration();
  void SetAcceleration(const glm::dvec2& acceleration);
  void UpdateState(double dt) override;
 protected:
  glm::dvec2 acceleration_;
};

}