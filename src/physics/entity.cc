#include <physics/entity.h>

namespace physics {

Entity::Entity(std::string name, glm::dvec2 position, glm::dvec2 velocity) {
  name_ = name;
  position_ = position;
  velocity_ = velocity;
}

std::string Entity::GetName() {
  return name_;
}

glm::dvec2 Entity::GetPosition() {
  return position_;
}

glm::dvec2 Entity::GetVelocity() {
  return velocity_;
}

void Entity::UpdateState(double dt) {
  position_ += velocity_ * dt;
}

}
