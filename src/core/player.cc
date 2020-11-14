#include <core/player.h>

namespace game {

namespace core {

Player::Player(std::string name) {
  name_ = name;
  score_ = 0;
}

size_t Player::GetScore() {
  return score_;
}
std::string Player::GetName() {
  return name_;
}

}

}