#include <core/player.h>

namespace game {

namespace core {

Player::Player(const std::string& name, const glm::dvec2& position, const glm::dvec2& velocity, const glm::dvec2& acceleration, size_t width, size_t height)
        : physics::AcceleratedEntity(position, velocity, acceleration, width, height) {
  name_ = name;
  score_ = 0;
}

size_t Player::GetScore() const {
  return score_;
}

}

}