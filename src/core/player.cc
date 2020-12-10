#include "core/player.h"

namespace game {

namespace core {

Player::Player(const glm::dvec2& position, const glm::dvec2& velocity,
               const glm::dvec2& acceleration, size_t width, size_t height)
    : physics::Entity(position, velocity, acceleration,
                                 width, height) {
  score_ = 0;
  is_jumping_ = false;
  on_ground_ = false;
}

size_t Player::GetScore() const {
  return score_;
}

bool Player::IsJumping() const {
  return is_jumping_;
}

bool Player::IsOnGround() const {
  return on_ground_;
}

bool Player::IsFacingRight() const {
  return velocity_.x >= 0;
}

void Player::IncrementScore() {
  ++score_;
}

void Player::SetOnGround(bool on_ground) {
  on_ground_ = on_ground;
}

void Player::SetJumping(bool is_jumping) {
  is_jumping_ = is_jumping;
}

void Player::UpdateState(double dt) {
  if (!on_ground_) velocity_.y += acceleration_.y;
  velocity_.x *= acceleration_.x;
  position_ += velocity_ * dt;
}

}

}