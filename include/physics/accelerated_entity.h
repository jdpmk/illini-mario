#pragma once

#include <physics/entity.h>

namespace physics {

/**
 * A class that represents an entity that has position, velocity, and
 * acceleration vectors.
 */
class AcceleratedEntity : public Entity {
 public:
  AcceleratedEntity() = default;
  AcceleratedEntity(const glm::dvec2& position, const glm::dvec2& velocity,
                    const glm::dvec2& acceleration, size_t width,
                    size_t height);
  glm::dvec2 GetAcceleration() const;
  void UpdateState(double dt) override;

 protected:
  glm::dvec2 acceleration_;
};

}