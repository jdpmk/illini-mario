#include <physics/entity.h>

namespace physics {

Entity::Entity(std::string name, glm::dvec2 position, glm::dvec2 velocity) {
  name_ = name;
  position_ = position;
  old_position_ = position;
  velocity_ = velocity;
}

std::string Entity::GetName() const {
  return name_;
}

glm::dvec2 Entity::GetPosition() const {
  return position_;
}

glm::dvec2 Entity::GetOldPosition() const {
  return old_position_;
}

glm::dvec2 Entity::GetVelocity() const {
  return velocity_;
}

void Entity::SetPosition(const glm::dvec2& position) {
  position_ = position;
}

void Entity::SetOldPosition(const glm::dvec2& old_position) {
  old_position_ = old_position;
}

void Entity::SetVelocity(const glm::dvec2& velocity) {
  velocity_ = velocity;
}

void Entity::UpdateState(double dt) {
  old_position_ = position_;
  position_ += velocity_ * dt;
}

}
