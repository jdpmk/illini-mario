#include <physics/accelerated_entity.h>

namespace physics {

AcceleratedEntity::AcceleratedEntity(const glm::dvec2& position,
                                     const glm::dvec2& velocity,
                                     const glm::dvec2& acceleration,
                                     size_t width,
                                     size_t height)
  : Entity(position, velocity, width, height),
          acceleration_(acceleration) {}

glm::dvec2 AcceleratedEntity::GetAcceleration() const {
  return acceleration_;
}

void AcceleratedEntity::UpdateState(double dt) {
  velocity_ += acceleration_ * dt;
  position_ += velocity_ * dt;
}

}