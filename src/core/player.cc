#include <core/player.h>

namespace game {

namespace core {

Player::Player(std::string name, glm::dvec2 position, glm::dvec2 velocity, glm::dvec2 acceleration) {
  name_ = name;
  position_ = position;
  velocity_ = velocity;
  acceleration_ = acceleration;
  score_ = 0;
}

size_t Player::GetScore() {
  return score_;
}

}

}