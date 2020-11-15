#include <physics/accelerated_entity.h>

namespace physics {

AcceleratedEntity::AcceleratedEntity(glm::dvec2 position, glm::dvec2 velocity, glm::dvec2 acceleration, size_t width, size_t height)
        : Entity(position, velocity, width, height) {
  acceleration_ = acceleration;
}

glm::dvec2 AcceleratedEntity::GetAcceleration() {
  return acceleration_;
}

void AcceleratedEntity::SetAcceleration(const glm::dvec2& acceleration) {
  acceleration_ = acceleration;
}

void AcceleratedEntity::UpdateState(double dt) {
  velocity_ += acceleration_ * dt;
  position_ += velocity_ * dt;
}


}