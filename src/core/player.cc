#include <core/player.h>

namespace game {

namespace core {

Player::Player(const std::string& name, const glm::dvec2& position, const glm::dvec2& velocity, const glm::dvec2& acceleration, size_t width, size_t height)
        : physics::AcceleratedEntity(position, velocity, acceleration, width, height) {
  name_ = name;
  score_ = 0;
  jumping_ = false;
  on_ground_ = false;
}

size_t Player::GetScore() const {
  return score_;
}

bool Player::IsOnGround() const {
  return on_ground_;
}

void Player::SetOnGround(bool on_ground) {
  on_ground_ = on_ground;
}

bool Player::IsJumping() const {
  return jumping_;
}

void Player::SetJumping(bool jumping) {
  jumping_ = jumping;
}

void Player::UpdateState(double dt) {
  if (!on_ground_) velocity_.y += acceleration_.y;
  velocity_.x *= acceleration_.x;
  position_ += velocity_ * dt;
}


}

}