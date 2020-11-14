#include <physics/accelerated_entity.h>

namespace physics {

AcceleratedEntity::AcceleratedEntity(std::string name, glm::dvec2 position, glm::dvec2 velocity, glm::dvec2 acceleration)
        : Entity(name, position, velocity) {
  acceleration_ = acceleration;
}

glm::dvec2 AcceleratedEntity::GetAcceleration() {
  return acceleration_;
}

void AcceleratedEntity::SetAcceleration(const glm::dvec2& acceleration) {
  acceleration_ = acceleration;
}

void AcceleratedEntity::UpdateState(double dt) {
  old_position_ = position_;
  velocity_ += acceleration_ * dt;
  position_ += velocity_ * dt;
}


}
