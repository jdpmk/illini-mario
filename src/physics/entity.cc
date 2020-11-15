#include <physics/entity.h>

namespace physics {

Entity::Entity(glm::dvec2 position, glm::dvec2 velocity, size_t width, size_t height) {
  position_ = position;
  velocity_ = velocity;
  width_ = width;
  height_ = height;
}

glm::dvec2 Entity::GetPosition() const {
  return position_;
}

glm::dvec2 Entity::GetVelocity() const {
  return velocity_;
}

size_t Entity::GetWidth() const {
  return width_;
}

size_t Entity::GetHeight() const {
  return height_;
}

glm::dvec2 Entity::GetTopLeftCorner() const {
  return glm::dvec2(position_.x - width_ / 2, position_.y + height_ / 2);
}

glm::dvec2 Entity::GetBottomLeftCorner() const {
  return glm::dvec2(position_.x - width_ / 2, position_.y - height_ / 2);
}

glm::dvec2 Entity::GetTopRightCorner() const {
  return glm::dvec2(position_.x + width_ / 2, position_.y + height_ / 2);
}

glm::dvec2 Entity::GetBottomRightCorner() const {
  return glm::dvec2(position_.x + width_ / 2, position_.y - height_ / 2);
}

void Entity::SetPosition(const glm::dvec2& position) {
  position_ = position;
}

void Entity::SetVelocity(const glm::dvec2& velocity) {
  velocity_ = velocity;
}

void Entity::UpdateState(double dt) {
  position_ += velocity_ * dt;
}

}
