#include <core/player.h>

namespace game {

namespace core {

Player::Player(std::string name, glm::dvec2 position, glm::dvec2 velocity, glm::dvec2 acceleration, size_t width, size_t height) {
  name_ = name;
  position_ = position;
  velocity_ = velocity;
  acceleration_ = acceleration;
  score_ = 0;
  width_ = width;
  height_ = height;
}

size_t Player::GetScore() {
  return score_;
}

size_t Player::GetWidth() {
  return width_;
}

size_t Player::GetHeight() {
  return height_;
}

glm::dvec2 Player::GetTopLeftCorner() {
  return glm::dvec2(position_.x - width_ / 2, position_.y + height_ / 2);
}

glm::dvec2 Player::GetTopRightCorner() {
  return glm::dvec2(position_.x + width_ / 2, position_.y + height_ / 2);
}

glm::dvec2 Player::GetBottomLeftCorner() {
  return glm::dvec2(position_.x - width_ / 2, position_.y - height_ / 2);
}

glm::dvec2 Player::GetBottomRightCorner() {
  return glm::dvec2(position_.x + width_ / 2, position_.y - height_ / 2);
}

}

}