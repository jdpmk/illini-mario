#include <core/player.h>
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

namespace game {

namespace core {

Player::Player(const std::string& name, const glm::dvec2& position, const glm::dvec2& velocity, const glm::dvec2& acceleration, size_t width, size_t height)
        : physics::AcceleratedEntity(name, position, velocity, acceleration) {
  score_ = 0;
  width_ = width;
  height_ = height;
}

size_t Player::GetScore() const {
  return score_;
}

size_t Player::GetWidth() const {
  return width_;
}

size_t Player::GetHeight() const {
  return height_;
}

glm::dvec2 Player::GetTopLeftCorner() const {
  return glm::dvec2(position_.x - width_ / 2, position_.y + height_ / 2);
}

glm::dvec2 Player::GetBottomRightCorner() const {
  return glm::dvec2(position_.x + width_ / 2, position_.y - height_ / 2);
}

}

}